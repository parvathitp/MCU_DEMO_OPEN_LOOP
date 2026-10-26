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
* @file     gd3000_init.h
*
* @date     Jul-9-2021
*
* @brief    MC34GD3000 Initialization
*
*******************************************************************************/
#ifndef GD3000_GD3000_INIT_H_
#define GD3000_GD3000_INIT_H_
/*******************************************************************************
* Includes
*******************************************************************************/
#include "aml/common_aml.h"
#include "aml/gpio_aml.h"
#include "tpp/tpp.h"

/*******************************************************************************
* Constants and macros
*******************************************************************************/
/* Frequency of SPI communication with device in Hz. */
#define LPSPI_FREQ         2000000
/* Device interrupt masks set by MASK0 and MASK1 commands. */
#define INIT_INTERRUPTS0 (TPP_MASK0_OT_INT_ENABLED | TPP_MASK0_DES_INT_ENABLED | \
                          TPP_MASK0_UV_INT_ENABLED | TPP_MASK0_OC_INT_ENABLED)
#define INIT_INTERRUPTS1 (TPP_MASK1_PHS_INT_ENABLED | TPP_MASK1_FRM_INT_ENABLED | \
                          TPP_MASK1_WRT_INT_ENABLED | TPP_MASK1_RST_INT_ENABLED)
/* Device configuration set by Mode command. */
#define INIT_MODE        (TPP_MODE_DESF_DISABLED | TPP_MODE_FULL_ENABLED | TPP_MODE_LOCK_ENABLED)
/* Dead time of device in nanoseconds. */
#define INIT_DEADTIME    500

extern tpp_drv_config_t tppDrvConfig;

/*******************************************************************************
* Global function prototypes
*******************************************************************************/
status_t GD3000_Init(void);

#endif /* GD3000_GD3000_INIT_H_ */
