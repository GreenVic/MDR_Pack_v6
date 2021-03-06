;/*****************************************************************************
; * @file:    startup_MDR1986BE3.s
; * @purpose: CMSIS Cortex-M1 Core Device Startup File 
; *           for the ARM 'Microcontroller Prototyping System' 
; *------- <<< Use Configuration Wizard in Context Menu >>> ------------------
; *
; * Copyright (C) 2008-2009 ARM Limited. All rights reserved.
; * ARM Limited (ARM) is supplying this software for use with Cortex-M0 
; * processor based microcontrollers.  This file can be freely distributed 
; * within development tools that are supporting such ARM based processors. 
; *
; * THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
; * OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
; * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
; * ARM SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL, OR
; * CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
; *
; *****************************************************************************/


; <h> Stack Configuration
;   <o> Stack Size (in Bytes) <0x0-0xFFFFFFFF:8>
; </h>

Stack_Size      EQU     0x00000400

                AREA    STACK, NOINIT, READWRITE, ALIGN=3
Stack_Mem       SPACE   Stack_Size
__initial_sp


; <h> Heap Configuration
;   <o>  Heap Size (in Bytes) <0x0-0xFFFFFFFF:8>
; </h>

Heap_Size       EQU     0x00007000

                AREA    HEAP, NOINIT, READWRITE, ALIGN=3
__heap_base
Heap_Mem        SPACE   Heap_Size
__heap_limit


                PRESERVE8
                THUMB


; Vector Table Mapped to Address 0 at Reset

                AREA    RESET, DATA, READONLY
                EXPORT  __Vectors

__Vectors       DCD     __initial_sp              ; Top of Stack
                DCD     Reset_Handler             ; Reset Handler
                DCD     NMI_Handler               ; NMI Handler
                DCD     HardFault_Handler         ; Hard Fault Handler
                DCD     0                         ; Reserved
                DCD     0                         ; Reserved
                DCD     0                         ; Reserved
                DCD     0                         ; Reserved
                DCD     0                         ; Reserved
                DCD     0                         ; Reserved
                DCD     0                         ; Reserved
                DCD     SVC_Handler               ; SVCall Handler
                DCD     0                         ; Reserved
                DCD     0                         ; Reserved
                DCD     PendSV_Handler            ; PendSV Handler
                DCD     SysTick_Handler           ; SysTick Handler

                ; External Interrupts - MDR1986BE3 Specific 
				DCD     MIL2_IRQHandler	            ; 0:  MIL_STD_1553B2 Interrupt
				DCD     MIL1_IRQHandler	            ; 1:  MIL_STD_1553B1 Interrupt
				DCD     USB_IRQHandler				; 2:  USB Interrupt
				DCD     CAN1_IRQHandler				; 3:  CAN1 Interrupt
				DCD     CAN2_IRQHandler				; 4:  CAN2 Interrupt
				DCD     DMA_IRQHandler				; 5:  DMA Interrupt
				DCD     UART1_IRQHandler			; 6:  UART1 Interrupt
				DCD     UART2_IRQHandler			; 7:  UART2 Interrupt
				DCD     SSP1_IRQHandler				; 8:  SSP1 Interrupt
				DCD     NAND_IRQHandler				; 9:  NAND Busy Interrupt
				DCD     ARINC_RX_IRQHandler		    ; 10: ARINC429 Receivers R1-R4 Interrupt
				DCD     POWER_IRQHandler			; 11: Power Detector Interrupt
				DCD     WWDG_IRQHandler				; 12: WWDG Interrupt 
				DCD     TIMER4_IRQHandler			; 13: Timer4 Interrupt
				DCD     TIMER1_IRQHandler			; 14: Timer1 Interrupt
				DCD     TIMER2_IRQHandler			; 15: Timer2 Interrupt
				DCD     TIMER3_IRQHandler			; 16: Timer3 Interrupt
				DCD     ADC_IRQHandler				; 17: ADC Interrupt
				DCD     ETH1_IRQHandler		        ; 18: Ethernet1 Interrupt
				DCD     SSP3_IRQHandler				; 19: SSP3 Interrupt
				DCD     SSP2_IRQHandler				; 20: SSP2 Interrupt
				DCD     ARINC_TX_IRQHandler		    ; 21: ARINC429 Transmitters T1-T4 Interrupt
				DCD     KEY_IRQHandler	    		; 20: Keyboard Interrupt
				DCD     LED_IRQHandler				; 20: LED Display Interrupt
				DCD     UART34_IRQHandler			; 20: UART3 and UART4 Interrupt
				DCD     AUC_IRQHandler		        ; 20: AudioCodec Interrupt
				DCD     ETH2_IRQHandler		        ; 20: Ethernet2 Interrupt
				DCD     BKP_IRQHandler				; 27: Backup and RTC Interrupt
				DCD     EXT1_IRQHandler				; 28: EXT_INT1 Interrupt
				DCD     EXT2_IRQHandler			    ; 29: EXT_INT2 Interrupt
				DCD     EXT3_IRQHandler			    ; 30: EXT_INT3 Interrupt
				DCD     EXT4_IRQHandler			    ; 31: EXT_INT4 Interrupt


                AREA    |.text|, CODE, READONLY


; Reset Handler

Reset_Handler   PROC
                EXPORT  Reset_Handler             [WEAK]
                IMPORT  __main
                LDR     R0, =__main
                BX      R0
                ENDP


; Dummy Exception Handlers (infinite loops which can be modified)

NMI_Handler     PROC
                EXPORT  NMI_Handler               [WEAK]
                B       .
                ENDP
HardFault_Handler \
                PROC
                EXPORT  HardFault_Handler         [WEAK]
                B       .
                ENDP
SVC_Handler     PROC
                EXPORT  SVC_Handler               [WEAK]
                B       .
                ENDP
PendSV_Handler  PROC
                EXPORT  PendSV_Handler            [WEAK]
                B       .
                ENDP
SysTick_Handler PROC
                EXPORT  SysTick_Handler           [WEAK]
                B       .
                ENDP

Default_Handler PROC

                EXPORT  MIL2_IRQHandler	             [WEAK]
                EXPORT  MIL1_IRQHandler	             [WEAK]
                EXPORT  USB_IRQHandler			     [WEAK]
                EXPORT  CAN1_IRQHandler			     [WEAK]
                EXPORT  CAN2_IRQHandler			     [WEAK]
                EXPORT  DMA_IRQHandler			     [WEAK]
                EXPORT  UART1_IRQHandler		     [WEAK]
                EXPORT  UART2_IRQHandler		     [WEAK]
                EXPORT  SSP1_IRQHandler			     [WEAK]
                EXPORT  NAND_IRQHandler			     [WEAK]
                EXPORT  ARINC_RX_IRQHandler	         [WEAK]
                EXPORT  POWER_IRQHandler		     [WEAK]
                EXPORT  WWDG_IRQHandler			     [WEAK]
                EXPORT  TIMER4_IRQHandler		     [WEAK]
                EXPORT  TIMER1_IRQHandler		     [WEAK]
                EXPORT  TIMER2_IRQHandler		     [WEAK]
                EXPORT  TIMER3_IRQHandler		     [WEAK]
                EXPORT  ADC_IRQHandler			     [WEAK]
                EXPORT  ETH1_IRQHandler              [WEAK]
                EXPORT  SSP3_IRQHandler			     [WEAK]
                EXPORT  SSP2_IRQHandler			     [WEAK]
				EXPORT  ARINC_TX_IRQHandler	         [WEAK]
                EXPORT  KEY_IRQHandler	    	     [WEAK]
                EXPORT  LED_IRQHandler			     [WEAK]
                EXPORT  UART34_IRQHandler		     [WEAK]
                EXPORT  AUC_IRQHandler		         [WEAK]
                EXPORT  ETH2_IRQHandler	             [WEAK]
                EXPORT  BKP_IRQHandler			     [WEAK]
                EXPORT  EXT1_IRQHandler			     [WEAK]
                EXPORT  EXT2_IRQHandler			     [WEAK]
				EXPORT  EXT3_IRQHandler			     [WEAK]
				EXPORT  EXT4_IRQHandler			     [WEAK]
					
					
MIL2_IRQHandler
MIL1_IRQHandler
USB_IRQHandler
CAN1_IRQHandler
CAN2_IRQHandler
DMA_IRQHandler
UART1_IRQHandler
UART2_IRQHandler
SSP1_IRQHandler
NAND_IRQHandler
ARINC_RX_IRQHandler
POWER_IRQHandler
WWDG_IRQHandler
TIMER4_IRQHandler
TIMER1_IRQHandler
TIMER2_IRQHandler
TIMER3_IRQHandler
ADC_IRQHandler
ETH1_IRQHandler
SSP3_IRQHandler
SSP2_IRQHandler
ARINC_TX_IRQHandler
KEY_IRQHandler
LED_IRQHandler
UART34_IRQHandler
AUC_IRQHandler
ETH2_IRQHandler
BKP_IRQHandler
EXT1_IRQHandler
EXT2_IRQHandler
EXT3_IRQHandler
EXT4_IRQHandler
                B       .

                ENDP


                ALIGN


; User Initial Stack & Heap

                IF      :DEF:__MICROLIB
                
                EXPORT  __initial_sp
                EXPORT  __heap_base
                EXPORT  __heap_limit
                
                ELSE
                
                IMPORT  __use_two_region_memory
                EXPORT  __user_initial_stackheap
__user_initial_stackheap

                LDR     R0, =  Heap_Mem
                LDR     R1, =(Stack_Mem + Stack_Size)
                LDR     R2, = (Heap_Mem +  Heap_Size)
                LDR     R3, = Stack_Mem
                BX      LR

                ALIGN

                ENDIF


                END
