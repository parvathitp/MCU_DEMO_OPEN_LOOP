/*
 * init.c
 *
 *  Created on: 26-Oct-2026
 *      Author: parva
 */

#include "init.h"

/* GD3000 driver-required application objects/callbacks. */
tpp_drv_config_t tppDrvConfig;

void GD3000_INT_Handler(void)
{
}

void TPP_InitializeOutputs(void)
{
}

void software_init(void){

    status_t gd3000Status;

    uint32_t gd3000Retry = 0U;
	   /* ========================================================
	     * CLOCK
	     * ======================================================== */

	    Clock_Ip_Init(&Clock_Ip_aClockConfig[0]);


	    /* ========================================================
	     * OSIF
	     * ======================================================== */

	    OsIf_Init(NULL_PTR);


	    /* ========================================================
	     * PORTS
	     * ======================================================== */

	    Siul2_Port_Ip_Init(NUM_OF_CONFIGURED_PINS_PortContainer_0_BOARD_InitPeripherals,g_pin_mux_InitConfigArr_PortContainer_0_BOARD_InitPeripherals);


	    /* ========================================================
	     * TRGMUX   (eMIOS CH1/2/3 -> LCU0 inputs)  REQUIRED
	     * ======================================================== */

	    Trgmux_Ip_Init(&Trgmux_Ip_Sa_xTrgmuxInitPB);


	    /* ========================================================
	     * LCU
	     * ======================================================== */

	    Lcu_Ip_Init(&Lcu_Ip_Sa_xLcuInitPB);


	    /* ========================================================
	     * LPSPI  (GD3000 configuration)
	     * ======================================================== */

	    Lpspi_Ip_Init(&Lpspi_Ip_PhyUnitConfig_GD_3000_Instance_1);


	    /* ========================================================
	     * GD3000
	     * ======================================================== */

	    do
	    {
	        gd3000Status =
	            GD3000_Init();

	        gd3000Retry++;

	    } while (
	        (gd3000Status != kStatus_Success) &&
	        (gd3000Retry < 100U)
	    );


	    /* Stop if GD3000 initialization failed */
	    if (gd3000Status != kStatus_Success)
	    {
	        while (1)
	        {
	        }
	    }


	    /* ========================================================
	     * eMIOS
	     * ======================================================== */

	    Emios_Mcl_Ip_Init(0U,&Emios_Mcl_Ip_Sa_0_Config);

	    /* Phase A */
	    Emios_Pwm_Ip_InitChannel(0U,&Emios_Pwm_Ip_Sa_I0_Ch1);

	    /* Phase B */
	    Emios_Pwm_Ip_InitChannel(0U,&Emios_Pwm_Ip_Sa_I0_Ch2);

	    /* Phase C */
	    Emios_Pwm_Ip_InitChannel(0U,&Emios_Pwm_Ip_Sa_I0_Ch3);

	    /* Start eMIOS global timebase */
	    Emios_Mcl_Ip_ConfigureGlobalTimebase(0U,TRUE);

}
