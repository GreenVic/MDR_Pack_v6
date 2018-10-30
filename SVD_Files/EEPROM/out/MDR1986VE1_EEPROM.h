/*
 * Copyright (c) 2009-2018 ARM Limited. All rights reserved.
 * 
 * SPDX-License-Identifier: Apache-2.0
 * 
 * Licensed under the Apache License, Version 2.0 (the License); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 * http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * @file     MDR1986VE1_EEPROM.h
 * @brief    CMSIS HeaderFile
 * @version  1.6
 * @date     11. October 2018
 * @note     Generated by SVDConv V3.3.18 on Thursday, 11.10.2018 17:11:27
 *           from File 'MDR1986VE1_EEPROM.svd',
 *           last modified on Thursday, 11.10.2018 14:09:44
 */



/** @addtogroup Milandr.
  * @{
  */


/** @addtogroup MDR1986VE1_EEPROM
  * @{
  */


#ifndef MDR1986VE1_EEPROM_H
#define MDR1986VE1_EEPROM_H

#ifdef __cplusplus
extern "C" {
#endif


/** @addtogroup Configuration_of_CMSIS
  * @{
  */



/* =========================================================================================================================== */
/* ================                                Interrupt Number Definition                                ================ */
/* =========================================================================================================================== */

typedef enum {
/* =======================================  ARM Cortex-M1 Specific Interrupt Numbers  ======================================== */
  Reset_IRQn                = -15,              /*!< -15  Reset Vector, invoked on Power up and warm reset                     */
  NonMaskableInt_IRQn       = -14,              /*!< -14  Non maskable Interrupt, cannot be stopped or preempted               */
  HardFault_IRQn            = -13,              /*!< -13  Hard Fault, all classes of Fault                                     */
  SVCall_IRQn               =  -5,              /*!< -5 System Service Call via SVC instruction                                */
  PendSV_IRQn               =  -2,              /*!< -2 Pendable request for system service                                    */
  SysTick_IRQn              =  -1,              /*!< -1 System Tick Timer                                                      */
/* =====================================  MDR1986VE1_EEPROM Specific Interrupt Numbers  ====================================== */
} IRQn_Type;



/* =========================================================================================================================== */
/* ================                           Processor and Core Peripheral Section                           ================ */
/* =========================================================================================================================== */

/* ===========================  Configuration of the ARM Cortex-M1 Processor and Core Peripherals  =========================== */
#define __CM1_REV                 0x0100U       /*!< CM1 Core Revision                                                         */
#define __NVIC_PRIO_BITS               2        /*!< Number of Bits used for Priority Levels                                   */
#define __Vendor_SysTickConfig         0        /*!< Set to 1 if different SysTick Config is used                              */


/** @} */ /* End of group Configuration_of_CMSIS */

#include "core_cm1.h"                           /*!< ARM Cortex-M1 processor and core peripherals                              */
#include "system_MDR1986VE1_EEPROM.h"           /*!< MDR1986VE1_EEPROM System                                                  */

#ifndef __IM                                    /*!< Fallback for older CMSIS versions                                         */
  #define __IM   __I
#endif
#ifndef __OM                                    /*!< Fallback for older CMSIS versions                                         */
  #define __OM   __O
#endif
#ifndef __IOM                                   /*!< Fallback for older CMSIS versions                                         */
  #define __IOM  __IO
#endif


/* ========================================  Start of section using anonymous unions  ======================================== */
#if defined (__CC_ARM)
  #pragma push
  #pragma anon_unions
#elif defined (__ICCARM__)
  #pragma language=extended
#elif defined(__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050)
  #pragma clang diagnostic push
  #pragma clang diagnostic ignored "-Wc11-extensions"
  #pragma clang diagnostic ignored "-Wreserved-id-macro"
  #pragma clang diagnostic ignored "-Wgnu-anonymous-struct"
  #pragma clang diagnostic ignored "-Wnested-anon-types"
#elif defined (__GNUC__)
  /* anonymous unions are enabled by default */
#elif defined (__TMS470__)
  /* anonymous unions are enabled by default */
#elif defined (__TASKING__)
  #pragma warning 586
#elif defined (__CSMC__)
  /* anonymous unions are enabled by default */
#else
  #warning Not supported compiler type
#endif


/* =========================================================================================================================== */
/* ================                            Device Specific Peripheral Section                             ================ */
/* =========================================================================================================================== */


/** @addtogroup Device_Peripheral_peripherals
  * @{
  */



/* =========================================================================================================================== */
/* ================                                        MDR_EEPROM                                         ================ */
/* =========================================================================================================================== */


/**
  * @brief EEPROM Control (MDR_EEPROM)
  */

typedef struct {                                /*!< (@ 0x40018000) MDR_EEPROM Structure                                       */
  
  union {
    __IOM uint32_t CMD;                         /*!< (@ 0x00000000) EEPROM Control register                                    */
    
    struct {
      __IOM uint32_t CON        : 1;            /*!< [0..0] Enable memory access through EEPROM controller                     */
      __IOM uint32_t WR         : 1;            /*!< [1..1] Write operation                                                    */
      __IOM uint32_t RD         : 1;            /*!< [2..2] Read operation                                                     */
      __IOM uint32_t DELAY      : 3;            /*!< [5..3] Memory access CPU delay tacts                                      */
      __IOM uint32_t XE         : 1;            /*!< [6..6] Enable ADDR[16..9]                                                 */
      __IOM uint32_t YE         : 1;            /*!< [7..7] Enable ADDR[8..2]                                                  */
      __IOM uint32_t SE         : 1;            /*!< [8..8] RD Amplifier enable                                                */
      __IOM uint32_t IFREN      : 1;            /*!< [9..9] Select main or info memory                                         */
      __IOM uint32_t ERASE      : 1;            /*!< [10..10] Erase string at ADDR[16:0]                                       */
      __IOM uint32_t MAS1       : 1;            /*!< [11..11] Erase whole block with ERASE                                     */
      __IOM uint32_t PROG       : 1;            /*!< [12..12] Programm EEPROM_DI to ADDR[16:0]                                 */
      __IOM uint32_t NVSTR      : 1;            /*!< [13..13] Memory access mode                                               */
    } CMD_b;
  } ;
  __IOM uint32_t  ADDR;                         /*!< (@ 0x00000004) Address register                                           */
  __IOM uint32_t  DI;                           /*!< (@ 0x00000008) Write data register                                        */
  __IOM uint32_t  DO;                           /*!< (@ 0x0000000C) Read data register                                         */
  __IOM uint32_t  KEY;                          /*!< (@ 0x00000010) Unlock block register                                      */
} MDR_EEPROM_Type;                              /*!< Size = 20 (0x14)                                                          */


/** @} */ /* End of group Device_Peripheral_peripherals */


/* =========================================================================================================================== */
/* ================                          Device Specific Peripheral Address Map                           ================ */
/* =========================================================================================================================== */


/** @addtogroup Device_Peripheral_peripheralAddr
  * @{
  */

#define MDR_EEPROM_BASE             0x40018000UL

/** @} */ /* End of group Device_Peripheral_peripheralAddr */


/* =========================================================================================================================== */
/* ================                                  Peripheral declaration                                   ================ */
/* =========================================================================================================================== */


/** @addtogroup Device_Peripheral_declaration
  * @{
  */

#define MDR_EEPROM                  ((MDR_EEPROM_Type*)        MDR_EEPROM_BASE)

/** @} */ /* End of group Device_Peripheral_declaration */


/* =========================================  End of section using anonymous unions  ========================================= */
#if defined (__CC_ARM)
  #pragma pop
#elif defined (__ICCARM__)
  /* leave anonymous unions enabled */
#elif (__ARMCC_VERSION >= 6010050)
  #pragma clang diagnostic pop
#elif defined (__GNUC__)
  /* anonymous unions are enabled by default */
#elif defined (__TMS470__)
  /* anonymous unions are enabled by default */
#elif defined (__TASKING__)
  #pragma warning restore
#elif defined (__CSMC__)
  /* anonymous unions are enabled by default */
#endif


/* =========================================================================================================================== */
/* ================                                Pos/Mask Peripheral Section                                ================ */
/* =========================================================================================================================== */


/** @addtogroup PosMask_peripherals
  * @{
  */



/* =========================================================================================================================== */
/* ================                                        MDR_EEPROM                                         ================ */
/* =========================================================================================================================== */

/* ==========================================================  CMD  ========================================================== */
#define MDR_EEPROM_CMD_CON_Pos            (0UL)                     /*!< MDR_EEPROM CMD: CON (Bit 0)                           */
#define MDR_EEPROM_CMD_CON_Msk            (0x1UL)                   /*!< MDR_EEPROM CMD: CON (Bitfield-Mask: 0x01)             */
#define MDR_EEPROM_CMD_WR_Pos             (1UL)                     /*!< MDR_EEPROM CMD: WR (Bit 1)                            */
#define MDR_EEPROM_CMD_WR_Msk             (0x2UL)                   /*!< MDR_EEPROM CMD: WR (Bitfield-Mask: 0x01)              */
#define MDR_EEPROM_CMD_RD_Pos             (2UL)                     /*!< MDR_EEPROM CMD: RD (Bit 2)                            */
#define MDR_EEPROM_CMD_RD_Msk             (0x4UL)                   /*!< MDR_EEPROM CMD: RD (Bitfield-Mask: 0x01)              */
#define MDR_EEPROM_CMD_DELAY_Pos          (3UL)                     /*!< MDR_EEPROM CMD: DELAY (Bit 3)                         */
#define MDR_EEPROM_CMD_DELAY_Msk          (0x38UL)                  /*!< MDR_EEPROM CMD: DELAY (Bitfield-Mask: 0x07)           */
#define MDR_EEPROM_CMD_XE_Pos             (6UL)                     /*!< MDR_EEPROM CMD: XE (Bit 6)                            */
#define MDR_EEPROM_CMD_XE_Msk             (0x40UL)                  /*!< MDR_EEPROM CMD: XE (Bitfield-Mask: 0x01)              */
#define MDR_EEPROM_CMD_YE_Pos             (7UL)                     /*!< MDR_EEPROM CMD: YE (Bit 7)                            */
#define MDR_EEPROM_CMD_YE_Msk             (0x80UL)                  /*!< MDR_EEPROM CMD: YE (Bitfield-Mask: 0x01)              */
#define MDR_EEPROM_CMD_SE_Pos             (8UL)                     /*!< MDR_EEPROM CMD: SE (Bit 8)                            */
#define MDR_EEPROM_CMD_SE_Msk             (0x100UL)                 /*!< MDR_EEPROM CMD: SE (Bitfield-Mask: 0x01)              */
#define MDR_EEPROM_CMD_IFREN_Pos          (9UL)                     /*!< MDR_EEPROM CMD: IFREN (Bit 9)                         */
#define MDR_EEPROM_CMD_IFREN_Msk          (0x200UL)                 /*!< MDR_EEPROM CMD: IFREN (Bitfield-Mask: 0x01)           */
#define MDR_EEPROM_CMD_ERASE_Pos          (10UL)                    /*!< MDR_EEPROM CMD: ERASE (Bit 10)                        */
#define MDR_EEPROM_CMD_ERASE_Msk          (0x400UL)                 /*!< MDR_EEPROM CMD: ERASE (Bitfield-Mask: 0x01)           */
#define MDR_EEPROM_CMD_MAS1_Pos           (11UL)                    /*!< MDR_EEPROM CMD: MAS1 (Bit 11)                         */
#define MDR_EEPROM_CMD_MAS1_Msk           (0x800UL)                 /*!< MDR_EEPROM CMD: MAS1 (Bitfield-Mask: 0x01)            */
#define MDR_EEPROM_CMD_PROG_Pos           (12UL)                    /*!< MDR_EEPROM CMD: PROG (Bit 12)                         */
#define MDR_EEPROM_CMD_PROG_Msk           (0x1000UL)                /*!< MDR_EEPROM CMD: PROG (Bitfield-Mask: 0x01)            */
#define MDR_EEPROM_CMD_NVSTR_Pos          (13UL)                    /*!< MDR_EEPROM CMD: NVSTR (Bit 13)                        */
#define MDR_EEPROM_CMD_NVSTR_Msk          (0x2000UL)                /*!< MDR_EEPROM CMD: NVSTR (Bitfield-Mask: 0x01)           */
/* =========================================================  ADDR  ========================================================== */
/* ==========================================================  DI  =========================================================== */
/* ==========================================================  DO  =========================================================== */
/* ==========================================================  KEY  ========================================================== */

/** @} */ /* End of group PosMask_peripherals */


/* =========================================================================================================================== */
/* ================                           Enumerated Values Peripheral Section                            ================ */
/* =========================================================================================================================== */


/** @addtogroup EnumValue_peripherals
  * @{
  */



/* =========================================================================================================================== */
/* ================                                        MDR_EEPROM                                         ================ */
/* =========================================================================================================================== */

/* ==========================================================  CMD  ========================================================== */
/* ===============================================  MDR_EEPROM CMD CON [0..0]  =============================================== */
typedef enum {                                  /*!< MDR_EEPROM_CMD_CON                                                        */
  MDR_EEPROM_CMD__CON__Normal Access   = 0,     /*!< Normal Access : Normal access to memory                                   */
  MDR_EEPROM_CMD__CON__Controller Access = 1,   /*!< Controller Access : Access to memory though registers                     */
} MDR_EEPROM_CMD__CON__Enum;

/* ===============================================  MDR_EEPROM CMD WR [1..1]  ================================================ */
typedef enum {                                  /*!< MDR_EEPROM_CMD_WR                                                         */
  MDR_EEPROM_CMD__WR__Inactive         = 0,     /*!< Inactive : No write operation                                             */
  MDR_EEPROM_CMD__WR__Active           = 1,     /*!< Active : Write operation                                                  */
} MDR_EEPROM_CMD__WR__Enum;

/* ===============================================  MDR_EEPROM CMD RD [2..2]  ================================================ */
typedef enum {                                  /*!< MDR_EEPROM_CMD_RD                                                         */
  MDR_EEPROM_CMD__RD__Inactive         = 0,     /*!< Inactive : No read operation                                              */
  MDR_EEPROM_CMD__RD__Active           = 1,     /*!< Active : Read operation                                                   */
} MDR_EEPROM_CMD__RD__Enum;

/* ==============================================  MDR_EEPROM CMD DELAY [3..5]  ============================================== */
typedef enum {                                  /*!< MDR_EEPROM_CMD_DELAY                                                      */
  MDR_EEPROM_CMD__DELAY__le25MHz       = 0,     /*!< le25MHz : CPU freq is up to 25MHz                                         */
  MDR_EEPROM_CMD__DELAY__le50MHz       = 1,     /*!< le50MHz : CPU freq is up to 50MHz                                         */
  MDR_EEPROM_CMD__DELAY__le75MHz       = 2,     /*!< le75MHz : CPU freq is up to 75MHz                                         */
  MDR_EEPROM_CMD__DELAY__le100MHz      = 3,     /*!< le100MHz : CPU freq is up to 100MHz                                       */
  MDR_EEPROM_CMD__DELAY__le125MHz      = 4,     /*!< le125MHz : CPU freq is up to 125MHz                                       */
  MDR_EEPROM_CMD__DELAY__le150MHz      = 5,     /*!< le150MHz : CPU freq is up to 150MHz                                       */
  MDR_EEPROM_CMD__DELAY__le175MHz      = 6,     /*!< le175MHz : CPU freq is up to 175MHz                                       */
  MDR_EEPROM_CMD__DELAY__le200MHz      = 7,     /*!< le200MHz : CPU freq is up to 200MHz                                       */
} MDR_EEPROM_CMD__DELAY__Enum;

/* ===============================================  MDR_EEPROM CMD XE [6..6]  ================================================ */
typedef enum {                                  /*!< MDR_EEPROM_CMD_XE                                                         */
  MDR_EEPROM_CMD__XE__Off              = 0,     /*!< Off : Disable                                                             */
  MDR_EEPROM_CMD__XE__On               = 1,     /*!< On : Enable                                                               */
} MDR_EEPROM_CMD__XE__Enum;

/* ===============================================  MDR_EEPROM CMD YE [7..7]  ================================================ */
typedef enum {                                  /*!< MDR_EEPROM_CMD_YE                                                         */
  MDR_EEPROM_CMD_YE_Off                = 0,     /*!< Off : Disable                                                             */
  MDR_EEPROM_CMD_YE_On                 = 1,     /*!< On : Enable                                                               */
} MDR_EEPROM_CMD_YE_Enum;

/* ===============================================  MDR_EEPROM CMD SE [8..8]  ================================================ */
typedef enum {                                  /*!< MDR_EEPROM_CMD_SE                                                         */
  MDR_EEPROM_CMD_SE_Off                = 0,     /*!< Off : Disable                                                             */
  MDR_EEPROM_CMD_SE_On                 = 1,     /*!< On : Enable                                                               */
} MDR_EEPROM_CMD_SE_Enum;

/* ==============================================  MDR_EEPROM CMD IFREN [9..9]  ============================================== */
typedef enum {                                  /*!< MDR_EEPROM_CMD_IFREN                                                      */
  MDR_EEPROM_CMD__IFREN__Main          = 0,     /*!< Main : Main memory                                                        */
  MDR_EEPROM_CMD__IFREN__Info          = 1,     /*!< Info : Info memory                                                        */
} MDR_EEPROM_CMD__IFREN__Enum;

/* =============================================  MDR_EEPROM CMD ERASE [10..10]  ============================================= */
typedef enum {                                  /*!< MDR_EEPROM_CMD_ERASE                                                      */
  MDR_EEPROM_CMD__ERASE__Inactive      = 0,     /*!< Inactive : No erase operation                                             */
  MDR_EEPROM_CMD__ERASE__Active        = 1,     /*!< Active : Erase operation                                                  */
} MDR_EEPROM_CMD__ERASE__Enum;

/* =============================================  MDR_EEPROM CMD MAS1 [11..11]  ============================================== */
typedef enum {                                  /*!< MDR_EEPROM_CMD_MAS1                                                       */
  MDR_EEPROM_CMD_MAS1_Off              = 0,     /*!< Off : Disable                                                             */
  MDR_EEPROM_CMD_MAS1_On               = 1,     /*!< On : Enable                                                               */
} MDR_EEPROM_CMD_MAS1_Enum;

/* =============================================  MDR_EEPROM CMD PROG [12..12]  ============================================== */
typedef enum {                                  /*!< MDR_EEPROM_CMD_PROG                                                       */
  MDR_EEPROM_CMD__PROG__Inactive       = 0,     /*!< Inactive : No programm operation                                          */
  MDR_EEPROM_CMD__PROG__Active         = 1,     /*!< Active : Programm operation                                               */
} MDR_EEPROM_CMD__PROG__Enum;

/* =============================================  MDR_EEPROM CMD NVSTR [13..13]  ============================================= */
typedef enum {                                  /*!< MDR_EEPROM_CMD_NVSTR                                                      */
  MDR_EEPROM_CMD__NVSTR__Read          = 0,     /*!< Read : Read mode                                                          */
  MDR_EEPROM_CMD__NVSTR__Write         = 1,     /*!< Write : Programming or erase mode                                         */
} MDR_EEPROM_CMD__NVSTR__Enum;

/* =========================================================  ADDR  ========================================================== */
/* ==========================================================  DI  =========================================================== */
/* ==========================================================  DO  =========================================================== */
/* ==========================================================  KEY  ========================================================== */

/** @} */ /* End of group EnumValue_peripherals */


#ifdef __cplusplus
}
#endif

#endif /* MDR1986VE1_EEPROM_H */


/** @} */ /* End of group MDR1986VE1_EEPROM */

/** @} */ /* End of group Milandr. */
