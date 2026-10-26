/*
 * lcu_service.c
 *
 * SERVICE LAYER
 * -------------
 * Owns runtime motor-output hardware operations.
 *
 * Current stage : Service -> NXP/TPP APIs directly.
 * Future stage  : Service -> EAL -> NXP/TPP APIs.
 */

#include "lcu_service.h"
#include "emios_service.h"
#include "Lcu_Ip.h"
#include "Lcu_Ip_Cfg.h"
#include "gd3000_init.h"
#include "tpp.h"
#include "wait_aml.h"

bool ACTUATE_EnableOutput(void)
{
    PWM_3PhaseDuty_t pwm;
    Lcu_Ip_SyncOutputValueType lcuEnable[6U];

    pwm.fltArg1 = 0.50F;
    pwm.fltArg2 = 0.50F;
    pwm.fltArg3 = 0.50F;

    (void)ACTUATE_SetDutycycle(&pwm);

    lcuEnable[0].LogicOutputId = LCU_LOGIC_OUTPUT_0; /* A LS */
    lcuEnable[0].Value = 1U;
    lcuEnable[1].LogicOutputId = LCU_LOGIC_OUTPUT_1; /* A HS */
    lcuEnable[1].Value = 1U;
    lcuEnable[2].LogicOutputId = LCU_LOGIC_OUTPUT_2; /* B LS */
    lcuEnable[2].Value = 1U;
    lcuEnable[3].LogicOutputId = LCU_LOGIC_OUTPUT_3; /* B HS */
    lcuEnable[3].Value = 1U;
    lcuEnable[4].LogicOutputId = LCU_LOGIC_OUTPUT_4; /* C LS */
    lcuEnable[4].Value = 1U;
    lcuEnable[5].LogicOutputId = LCU_LOGIC_OUTPUT_5; /* C HS */
    lcuEnable[5].Value = 1U;

    Lcu_Ip_SetSyncOutputEnable(lcuEnable, 6U);

    return true;
}

bool ACTUATE_DisableOutput(void)
{
    PWM_3PhaseDuty_t pwm;
    Lcu_Ip_SyncOutputValueType lcuDisable[6U];
    uint8_t index;

    for (index = 0U; index < 6U; index++)
    {
        lcuDisable[index].LogicOutputId = index;
        lcuDisable[index].Value = 0U;
    }

    Lcu_Ip_SetSyncOutputEnable(lcuDisable, 6U);

    pwm.fltArg1 = 0.50F;
    pwm.fltArg2 = 0.50F;
    pwm.fltArg3 = 0.50F;

    (void)ACTUATE_SetDutycycle(&pwm);

    return true;
}

bool ACTUATE_GateDriverFaultDetected(uint8_t *status)
{
    uint8_t sr0 = 0U;

    if (TPP_GetStatusRegister(&tppDrvConfig, tppSR0_deviceEvents, &sr0) == kStatus_Success)
    {
        if (status != NULL)
        {
            *status = sr0;
        }

        return (sr0 != 0U);
    }

    return false;
}

void ACTUATE_WaitMs(uint32_t delayMs)
{
    WAIT_AML_WaitMs(delayMs);
}
