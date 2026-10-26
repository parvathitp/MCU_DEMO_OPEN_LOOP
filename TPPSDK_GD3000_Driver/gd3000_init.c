/*******************************************************************************
*
*   Copyright 2006-2021 NXP
*
* This software is owned or controlled by NXP Semiconductors.
* Use of this software is governed by the NXP LA_OPT_NXP_Software_License
* distributed with this Material.
* See the LA_OPT_NXP_Software_License file distributed for more details.
*
* Brief License Summary:
* This software is provided in source form for you to use free of charge,
* but it is not open source software. You are allowed to use this software
* and derivative works of it in source form.
* The software may be used only in connection with a product containing
* a NXP microprocessor, microcontroller, or digital signal processor.
* See license agreement file for full license terms including other
* restrictions.
*
* THIS SOFTWARE IS PROVIDED BY NXP "AS IS" AND ANY EXPRESSED OR
* IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
* OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
* IN NO EVENT SHALL NXP OR ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
* INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
* (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
* SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
* HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
* STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
* IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
* THE POSSIBILITY OF SUCH DAMAGE.
*
****************************************************************************//*!
*
* @file     gd3000_init.c
*
* @date     Jul-9-2021
*
* @brief    MC34GD3000 Initialization
*
*******************************************************************************/
/*******************************************************************************
* Includes
*******************************************************************************/
#include "gd3000_init.h"

/*******************************************************************************
*
* Function:     status_t GD3000_Init(void)
*
* Description:  This function initialize MC34GD3000 MOSFET pre-driver.
*               MC34GD3000 SW driver uses S32K344 LPSPI1 module as a communication
*               interface to configure MC34GD3000 operation mode and to track MC34GD3000
*               Status0/Status1 registers.
*
*******************************************************************************/
status_t GD3000_Init(void)
{
    /* Local Variables */
    status_t GDInitErr = kStatus_Success;

   /* GD3000 pin configuration */
    tppDrvConfig.en1PinIndex    = AML_GD_EN1EN2_PIN;
    tppDrvConfig.en1PinInstance = AML_GD_EN1EN2_PORT;
    tppDrvConfig.en2PinIndex    = AML_GD_EN1EN2_PIN;
    tppDrvConfig.en2PinInstance = AML_GD_EN1EN2_PORT;
    tppDrvConfig.rstPinIndex    = AML_GD_RST_PIN;
    tppDrvConfig.rstPinInstance = AML_GD_RST_PORT;

    /* GD3000 device configuration */
    tppDrvConfig.deviceConfig.deadtime =    INIT_DEADTIME;
    tppDrvConfig.deviceConfig.intMask0 =    INIT_INTERRUPTS0;
    tppDrvConfig.deviceConfig.intMask1 =    INIT_INTERRUPTS1;
    tppDrvConfig.deviceConfig.modeMask =    INIT_MODE;

    /* GD3000 status registers configuration */
    tppDrvConfig.deviceConfig.statusRegister[0U] = 0U;
    tppDrvConfig.deviceConfig.statusRegister[1U] = 0U;
    tppDrvConfig.deviceConfig.statusRegister[2U] = 0U;
    tppDrvConfig.deviceConfig.statusRegister[3U] = 0U;

    /* GD3000 SPI configuration */
    tppDrvConfig.csPinIndex = AML_GD_SPI_PCS_PIN;
    tppDrvConfig.csPinInstance = AML_GD_SPI_PCS_PORT;
#if (SDK_VERSION == KINETIS_SDK_2_0 || SDK_VERSION == S32K1_SDK_3_0_0)
    /* Initialize Peripherals:
     * The code below only applies to Kinetis SDK and S32K1 SDK.
     * When S32K3 RTD is used, the peripherals (GPIO and SPI) are configured
     * through RTD APIs. */
    tppDrvConfig.spiInstance = AML_GD_SPI_INST;
    tppDrvConfig.spiTppConfig.baudRateHz =    LPSPI_FREQ;
    tppDrvConfig.spiTppConfig.sourceClockHz = 4000000U;
    TPP_ConfigureGpio(&tppDrvConfig);
    TPP_ConfigureSpi(&tppDrvConfig, NULL);
#endif

    GDInitErr = TPP_Init(&tppDrvConfig, tppModeEnable);

    return GDInitErr;
}
