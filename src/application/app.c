/*
 * app.c
 *
 * APPLICATION LAYER
 * -----------------
 * Owns the motor-control algorithm and application state.
 * No direct NXP peripheral API calls are made here.
 */

#include "app.h"
#include "emios_service.h"
#include "lcu_service.h"
#include <stdbool.h>
#include <math.h>

volatile uint8_t g_runRequest = 1U;
volatile float   g_targetHz   = 5.0F;
volatile float   g_amplitude  = 0.15F;
volatile uint8_t g_gdSr0      = 0U;

static float    s_theta;
static float    s_electricalFrequency;
static uint32_t s_gdCheckCnt;
static bool     s_outputsOn;
static bool     s_faultLatched;

static void APP_GenerateSinePWM(float theta, PWM_3PhaseDuty_t *pwm)
{
    const float amp = g_amplitude;

    pwm->fltArg1 = 0.50F + (amp * cosf(theta));
    pwm->fltArg2 = 0.50F + (amp * cosf(theta - PHASE_120_F));
    pwm->fltArg3 = 0.50F + (amp * cosf(theta + PHASE_120_F));
}

static void APP_UpdateFrequencyRamp(void)
{
    if (s_electricalFrequency < (g_targetHz - FREQ_RAMP_STEP_HZ))
    {
        s_electricalFrequency += FREQ_RAMP_STEP_HZ;
    }
    else if (s_electricalFrequency > (g_targetHz + FREQ_RAMP_STEP_HZ))
    {
        s_electricalFrequency -= FREQ_RAMP_STEP_HZ;
    }
    else
    {
        s_electricalFrequency = g_targetHz;
    }
}

static void APP_UpdateElectricalAngle(void)
{
    const float deltaTheta = TWO_PI_F * s_electricalFrequency * CONTROL_PERIOD_S;

    s_theta += deltaTheta;

    if (s_theta >= TWO_PI_F)
    {
        s_theta -= TWO_PI_F;
    }
}

static void APP_StartMotor(void)
{
    PWM_3PhaseDuty_t pwm;

    s_theta = 0.0F;
    s_electricalFrequency = START_FREQ_HZ;

    (void)ACTUATE_EnableOutput();
    ACTUATE_WaitMs(100U);

    APP_GenerateSinePWM(s_theta, &pwm);
    (void)ACTUATE_SetDutycycle(&pwm);

    ACTUATE_WaitMs(ALIGN_TIME_MS);

    s_outputsOn = true;
}

static void APP_StopMotor(void)
{
    if (s_outputsOn)
    {
        (void)ACTUATE_DisableOutput();
        s_outputsOn = false;
    }
}

static void APP_CheckGateDriverFault(void)
{
    uint8_t status = 0U;

    if (++s_gdCheckCnt >= GD_CHECK_EVERY)
    {
        s_gdCheckCnt = 0U;

        if (ACTUATE_GateDriverFaultDetected(&status))
        {
            g_gdSr0 = status;
            (void)ACTUATE_DisableOutput();
            s_outputsOn = false;
            s_faultLatched = true;
        }
    }
}

void APP_Init(void)
{
    s_theta = 0.0F;
    s_electricalFrequency = START_FREQ_HZ;
    s_gdCheckCnt = 0U;
    s_outputsOn = false;
    s_faultLatched = false;
    g_gdSr0 = 0U;
}

void APP_MainFunction(void)
{
    PWM_3PhaseDuty_t pwm;

    if (s_faultLatched)
    {
        /* Same behavior as old code: remain stopped until MCU reset. */
        ACTUATE_WaitMs(CONTROL_PERIOD_MS);
        return;
    }

    if (g_runRequest == 0U)
    {
        APP_StopMotor();
        ACTUATE_WaitMs(CONTROL_PERIOD_MS);
        return;
    }

    if (!s_outputsOn)
    {
        APP_StartMotor();
    }

    APP_GenerateSinePWM(s_theta, &pwm);
    (void)ACTUATE_SetDutycycle(&pwm);

    APP_UpdateFrequencyRamp();
    APP_UpdateElectricalAngle();
    APP_CheckGateDriverFault();

    ACTUATE_WaitMs(CONTROL_PERIOD_MS);
}
