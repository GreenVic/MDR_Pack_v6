#include <MDR_Timer.h>
#include <MDRB_LEDs.h>
#include <MDRB_LCD.h>

#include <MDRB_Timer_PinSelect.h>
#include "test_Defs.h"


//  ОПИСАНИЕ:
//    Пример подсчета передних фронтов на входе канала таймера.
//    Таймер1 генерирует импульсы c выхода CH1, которые подаются на вход CH1 Таймера2.
//    В прерываниях таймеров по периоду: 
//      - Таймер1 переключается светодиод1, 
//      - Таймер2 переключается светодиод2.
//  В коде можно поменять настройки фильтров, частоты сэмплирования и прочего 
//  для изучения их влияния на периоды мигания светодиодов.
//
//  В 1986ВК214 без подключения налюдается беспорядочное мигание светодиода (из-за наводок или утечек).
//  При подключении TIM1_CH1 к TIM2_CH1 мигания ожидаемо упорядочиваются.


//  Test Interface functions
static void  Test_Init(void);
static void  Test_Finit(void);
static void  Test_Empty(void);
static void  Test_HandleTim1IRQ(void);
static void  Test_HandleTim2IRQ(void);
static void  Test_HandleTim3IRQ(void);
static void  Test_HandleTim4IRQ(void);


TestInterface TI_PWM_CountCAP = {
  .funcInit       = Test_Init,
  .funcFinit      = Test_Finit,
  .funcChange     = Test_Empty,
  .funcExec       = Test_Empty,
  .funcMainLoop   = Test_Empty,
  .funcHandlerTim1 = Test_HandleTim1IRQ,
  .funcHandlerTim2 = Test_HandleTim2IRQ,
  .funcHandlerTim3 = Test_HandleTim3IRQ,
  .funcHandlerTim4 = Test_HandleTim4IRQ,
};

#define LED2_PERIOD   4

static const MDR_Timer_CfgCountCH cfgCntCH = {
  .cfgPeriod.clockBRG = TIM_BRG_LED,
  .cfgPeriod.period = LED2_PERIOD,
  .cfgPeriod.startValue = 0,
  .cfgPeriod.periodUpdateImmediately = MDR_Off,
  
  .cfgIRQ.SelectIRQ   = TIM_FL_CNT_ARR,
  .cfgIRQ.priorityIRQ = 0,
  .cfgIRQ.activateNVIC_IRQ = true,
   
  .selEventCH  = CAP_EVENT_CH,  
  .countDir    = TIM_Event_CountUp,  
  .clockDTS    = TIM_FDTS_TimClk_div1
};

static const MDR_TimerCh_CfgCAP cfgCAP = {
  .Filter   = MDR_TIM_FLTR_TIM_CLK, 
  .EventPSC = MDR_PSC_div1,
  .EventCAP = MDR_TIM_CAP_RiseOnPin,
  .enableCAP1 = false,
  .EventCAP1  = MDR_TIM_CAP1_FallOnPin
};

static void Test_Init(void)
{  
  //  To LCD
#ifndef LCD_IS_7SEG_DISPLAY
  MDRB_LCD_Print("Count CAP", 3);
  
#elif defined (LCD_CONFLICT)
  //  LCD conflicts with Timers channel
  //  Show Test index and LCD Off
  MDRB_LCD_Print("11");  
  MDR_LCD_BlinkyStart(MDR_LCD_Blink_2Hz, MDR_Off);
  MDR_Delay_ms(LCD_HIDE_DELAY, MDR_CPU_GetFreqHz(false));
  
  MDR_LCD_DeInit();
#else
  MDRB_LCD_Print("11");
#endif
  
  MDRB_LED_Init(LED_SEL);
  MDRB_LED_Set (LED_SEL, 0);  
      
  //  PWM1 - Output pulses for ETR, show period with LED1
  MDR_Timer_InitPeriod(PWM1_TIMex, TIM_BRG_LED, TIM_PSG_LED, TIM_PERIOD_LED, true);
  MDR_TimerPulse_InitPulse(PWM1_TIM_CH, TIM_PERIOD_LED, 50);
  MDR_TimerCh_InitPinGPIO(&PWM1_PIN_CH,  MDR_PIN_FAST);
     
  //  CAP - Counts CAP Events and show period with LED2
  MDR_Timer_InitCountChannelEvent(CAP_TIMex, &cfgCntCH);
  MDR_TimerCh_InitCAP(CAP_TIM_CH, &cfgCAP);
  MDR_TimerCh_InitPinGPIO(&CAP_PIN_CH, MDR_PIN_FAST);
      
  // Start
#ifndef SYNC_START_UNAVALABLE  
  MDR_Timer_StartSync(PWM1_START_SEL_MSK | CAP_START_SEL_MSK);
#else
  MDR_Timer_Start(CAP_TIMex);
  MDR_Timer_Start(PWM1_TIMex);
#endif  
}  

static void Test_Finit(void)
{
  //  Stop
#ifndef SYNC_START_UNAVALABLE  
  MDR_Timer_StopSync(PWM1_START_SEL_MSK | CAP_START_SEL_MSK);
#else
  MDR_Timer_Stop(PWM1_TIMex);
  MDR_Timer_Stop(CAP_TIMex);  
#endif    
  
  //  Pins to third state
  MDR_TimerCh_DeInitPinGPIO(&PWM1_PIN_CH);
  MDR_TimerCh_DeInitPinGPIO(&CAP_PIN_CH);

  //  Finit Timers
  MDR_Timer_DeInit(PWM1_TIMex);
  MDR_Timer_DeInit(CAP_TIMex);

#ifdef LCD_CONFLICT 
  // Restore LCD  
  MDRB_LCD_Init(MDR_CPU_GetFreqHz(false));    
#endif
  
  LED_Uninitialize();  
}

static void Test_HandleTim1IRQ(void)
{
  MDR_Timer_ClearEvent(MDR_TIMER1, TIM_FL_CNT_ARR);
  MDRB_LED_Switch(MDRB_LED_1);  
}

static void Test_HandleTim2IRQ(void)
{
  MDR_Timer_ClearEvent(MDR_TIMER2, TIM_FL_CNT_ARR);
  MDRB_LED_Switch(MDRB_LED_2);
}

static void Test_HandleTim3IRQ(void)
{
#ifdef  TIMER3_EXIST  
  MDR_Timer_ClearEvent(MDR_TIMER3, TIM_FL_CNT_ARR);  
  MDRB_LED_Switch(MDRB_LED_3);
#endif
}

static void Test_HandleTim4IRQ(void)
{
#ifdef  TIMER4_EXIST  
  MDR_Timer_ClearEvent(MDR_TIMER4, TIM_FL_CNT_ARR);  
  MDRB_LED_Switch(MDRB_LED_4);
#endif
}

static void  Test_Empty(void)
{
}

