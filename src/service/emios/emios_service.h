/*
 * emios_service.h
 *
 * SERVICE LAYER - PWM service interface.
 */

#ifndef SERVICE_EMIOS_EMIOS_SERVICE_H_
#define SERVICE_EMIOS_EMIOS_SERVICE_H_

#include <stdbool.h>

typedef struct
{
    float fltArg1;     /* Phase A */
    float fltArg2;     /* Phase B */
    float fltArg3;     /* Phase C */
} PWM_3PhaseDuty_t;

bool ACTUATE_SetDutycycle(PWM_3PhaseDuty_t *fltpwm);

#endif /* SERVICE_EMIOS_EMIOS_SERVICE_H_ */
