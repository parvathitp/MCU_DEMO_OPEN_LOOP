/*
 * emios_service.c
 *
 * SERVICE LAYER
 * -------------
 * Converts application duty commands into eMIOS compare values.
 *
 * Current stage : Service -> NXP RTD directly.
 * Future stage  : Service -> EAL -> NXP RTD.
 */

#include "emios_service.h"
#include "app.h"
#include "Emios_Mcl_Ip.h"
#include "Emios_Mcl_Ip_Cfg.h"
#include "Emios_Pwm_Ip.h"
#include "Emios_Pwm_Ip_Cfg.h"
#include <stdint.h>

bool ACTUATE_SetDutycycle(PWM_3PhaseDuty_t *fltpwm)
{
    uint16_t pwmPeriodHalf;
    uint16_t pwmShiftA;
    uint16_t pwmShiftB;
    uint16_t pwmShiftC;
    uint16_t pwmPhaseARegA;
    uint16_t pwmPhaseARegB;
    uint16_t pwmPhaseBRegA;
    uint16_t pwmPhaseBRegB;
    uint16_t pwmPhaseCRegA;
    uint16_t pwmPhaseCRegB;

    if (fltpwm == NULL)
    {
        return false;
    }

    if (fltpwm->fltArg1 < DUTY_MIN)       { fltpwm->fltArg1 = DUTY_MIN; }
    else if (fltpwm->fltArg1 > DUTY_MAX) { fltpwm->fltArg1 = DUTY_MAX; }

    if (fltpwm->fltArg2 < DUTY_MIN)       { fltpwm->fltArg2 = DUTY_MIN; }
    else if (fltpwm->fltArg2 > DUTY_MAX) { fltpwm->fltArg2 = DUTY_MAX; }

    if (fltpwm->fltArg3 < DUTY_MIN)       { fltpwm->fltArg3 = DUTY_MIN; }
    else if (fltpwm->fltArg3 > DUTY_MAX) { fltpwm->fltArg3 = DUTY_MAX; }

    pwmPeriodHalf = (uint16_t)(Emios_Mcl_Ip_Sa_0_MasterBusConfig[0].defaultPeriod >> 1U);

    Emios_Mcl_Ip_ComparatorTransferDisable(0U, (uint32_t)0xEU);

    pwmShiftA = (uint16_t)(fltpwm->fltArg1 * (float)pwmPeriodHalf);
    pwmShiftB = (uint16_t)(fltpwm->fltArg2 * (float)pwmPeriodHalf);
    pwmShiftC = (uint16_t)(fltpwm->fltArg3 * (float)pwmPeriodHalf);

    pwmPhaseARegA = pwmPeriodHalf - pwmShiftA;
    pwmPhaseARegB = pwmPeriodHalf + pwmShiftA;
    pwmPhaseBRegA = pwmPeriodHalf - pwmShiftB;
    pwmPhaseBRegB = pwmPeriodHalf + pwmShiftB;
    pwmPhaseCRegA = pwmPeriodHalf - pwmShiftC;
    pwmPhaseCRegB = pwmPeriodHalf + pwmShiftC;

    Emios_Pwm_Ip_UpdateUCRegA(0U, 1U, pwmPhaseARegA);
    Emios_Pwm_Ip_UpdateUCRegB(0U, 1U, pwmPhaseARegB);
    Emios_Pwm_Ip_UpdateUCRegA(0U, 2U, pwmPhaseBRegA);
    Emios_Pwm_Ip_UpdateUCRegB(0U, 2U, pwmPhaseBRegB);
    Emios_Pwm_Ip_UpdateUCRegA(0U, 3U, pwmPhaseCRegA);
    Emios_Pwm_Ip_UpdateUCRegB(0U, 3U, pwmPhaseCRegB);

    Emios_Mcl_Ip_ComparatorTransferEnable(0U, (uint32_t)0xEU);

    return true;
}
