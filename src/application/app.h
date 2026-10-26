/*
 * app.h
 *
 * Application layer: open-loop motor-control algorithm and state handling.
 */

#ifndef APPLICATION_APP_H_
#define APPLICATION_APP_H_

#include <stdint.h>

/* Open-loop settings */
#define TWO_PI_F               (6.28318530718F)
#define PHASE_120_F            (2.09439510239F)
#define START_FREQ_HZ          (0.20F)
#define CONTROL_PERIOD_S       (0.001F)
#define CONTROL_PERIOD_MS      (1U)
#define FREQ_RAMP_STEP_HZ      (0.0005F)
#define ALIGN_TIME_MS          (1000U)
#define DUTY_MIN               (0.05F)
#define DUTY_MAX               (0.95F)
#define GD_CHECK_EVERY         (10U)

/* Debug/runtime commands */
extern volatile uint8_t g_runRequest;
extern volatile float   g_targetHz;
extern volatile float   g_amplitude;
extern volatile uint8_t g_gdSr0;

void APP_Init(void);
void APP_MainFunction(void);

#endif /* APPLICATION_APP_H_ */
