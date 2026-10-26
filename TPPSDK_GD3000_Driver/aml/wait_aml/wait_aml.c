/* ====================================================================================
 * Copyright 2013 - 2021, NXP Semiconductors.
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
 * ================================================================================*/

/*
 * File: wait_aml.c
 *
 * This driver creates abstraction for WAIT functions for S32K1 SDK/RTD,
 * Kinetis SDK 2.0 or S32K3 RTD.
 */

/*******************************************************************************
* Includes
 ******************************************************************************/
#include "wait_aml.h"

/*******************************************************************************
 * Code
 ******************************************************************************/

/*FUNCTION**********************************************************************
 *
 * Function Name : WAIT_AML_GetSysFreq
 * Description   : Get system core frequency in ticks
 *
 *END**************************************************************************/
inline uint32_t WAIT_AML_GetSysFreq( void )
{
    uint32_t freq;
#if (SDK_VERSION == S32K1_SDK_3_0_0)
    CLOCK_SYS_GetFreq(CORE_CLK, &freq);
#elif (SDK_VERSION == S32K3_RTD_LLD)
    freq = Clock_Ip_GetClockFrequency(CORE_CLK);
#elif (SDK_VERSION == S32K3_RTD_MCAL)
    freq = Mcu_GetClockFrequency(CORE_CLK);
#endif
    return freq;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : WAIT_AML_WaitCycles
 * Description   : Waits for specified amount of cycles which is given by 32bit 
 *                 value range. Assumption for this function is that target 
 *                 architecture is using 32bit general purpose registers.
 *
 *END**************************************************************************/
void WAIT_AML_WaitCycles(uint32_t cycles)
{
    /* Advance to next multiple of 4. Value 0x04U ensures that the number
     * is not zero. */
    cycles = (cycles & 0xFFFFFFFCU) | 0x04U;
    WAIT_AML_WAIT_FOR_MUL4_CYCLES(cycles);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : WAIT_AML_WaitSec
 * Description   : Waits for specified amount of seconds.
 *
 *END**************************************************************************/
void WAIT_AML_WaitSec(uint16_t delay)
{
    for (; delay > 0U; delay--) {
        WAIT_AML_WaitMs(1000U);
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : WAIT_AML_WaitMs
 * Description   : Waits for specified amount of milliseconds.
 *
 *END**************************************************************************/
void WAIT_AML_WaitMs(uint16_t delay)
{
    uint32_t cycles = (uint32_t) WAIT_AML_GET_CYCLES_FOR_MS(delay, WAIT_AML_SYSTEM_CLOCK_FREQ );

    /* Advance to multiple of 4. */
    cycles = (cycles & 0xFFFFFFFCU) | 0x04U;;
    WAIT_AML_WAIT_FOR_MUL4_CYCLES(cycles);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : WAIT_AML_WaitUs
 * Description   : Waits for specified amount of microseconds.
 *
 *END**************************************************************************/
void WAIT_AML_WaitUs(uint16_t delay)
{
    uint32_t cycles = (uint32_t) WAIT_AML_GET_CYCLES_FOR_US(delay, WAIT_AML_SYSTEM_CLOCK_FREQ );

    /* Advance to next multiple of 4. Value 0x04U ensures that the number
     * is not zero. */
    cycles = (cycles & 0xFFFFFFFCU) | 0x04U;
    WAIT_AML_WAIT_FOR_MUL4_CYCLES(cycles);
}



/*******************************************************************************
 * EOF
 ******************************************************************************/
