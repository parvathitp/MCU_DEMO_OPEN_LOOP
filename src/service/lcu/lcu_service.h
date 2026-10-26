/*
 * lcu_service.h
 *
 * SERVICE LAYER - motor actuation/output service.
 */

#ifndef SERVICE_LCU_LCU_SERVICE_H_
#define SERVICE_LCU_LCU_SERVICE_H_

#include <stdbool.h>
#include <stdint.h>

bool ACTUATE_EnableOutput(void);
bool ACTUATE_DisableOutput(void);
bool ACTUATE_GateDriverFaultDetected(uint8_t *status);
void ACTUATE_WaitMs(uint32_t delayMs);

#endif /* SERVICE_LCU_LCU_SERVICE_H_ */
