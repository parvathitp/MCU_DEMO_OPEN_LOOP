/*
 * init.h
 *
 *  Created on: 26-Oct-2026
 *      Author: parva
 */

#ifndef INIT_INIT_H_
#define INIT_INIT_H_


#include "Clock_Ip.h"
#include "Clock_Ip_Cfg.h"

#include "OsIf.h"

#include "Siul2_Port_Ip.h"
#include "Siul2_Port_Ip_Cfg.h"



#include "Lpspi_Ip.h"
#include "Lpspi_Ip_Cfg.h"

#include "Emios_Mcl_Ip.h"
#include "Emios_Mcl_Ip_Cfg.h"
#include "Emios_Pwm_Ip.h"
#include "Emios_Pwm_Ip_Cfg.h"
#include "Lcu_Ip.h"
#include "Lcu_Ip_Cfg.h"

#include "Trgmux_Ip.h"

#include "gd3000_init.h"
#include "tpp.h"
#include "wait_aml.h"

#include <stdint.h>
#include <stdbool.h>
#include <math.h>


void software_init(void);

#endif /* INIT_INIT_H_ */
