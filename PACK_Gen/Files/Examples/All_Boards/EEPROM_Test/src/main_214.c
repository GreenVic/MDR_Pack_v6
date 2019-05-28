#include <MDR_GPIO.h>
#include <MDR_RST_Clock.h>
#include <MDR_Funcs.h>
#include <MDRB_Buttons.h>
#include <MDRB_LCD.h>
#include <MDR_EEPROM.h>

#include <EEPROM_PageFuncs.h>

//----------  �������� ������������ ������  -------------
// �� 8��� ����� ������� ������ �� ������� MDR_ToPseudoRand(),
// ������ ������ �������� ���������� ����������� �������.
#define USE_PSEUDO_RAND_VALUES  1

#if USE_PSEUDO_RAND_VALUES
  #define GetTestValue  MDR_ToPseudoRand
#else
  uint32_t ReturnInput(uint32_t value) { return value; }

  #define GetTestValue  ReturnInput
#endif
 
//--------------  ��������� ������������  -----------------
// ���� ����������� �� ���� �������� - �� HSI � �� HSE � ������������ ���������� � PLL
#define PLL_MUL   HSE_PLL_MUL_MAX
static MDR_BKP_LOW_RI    BKP_LowRI;
static MDR_EEPROM_DELAY  EEPROM_Delay;

//-------  �������� �� �������� ��������� � �������  ------
#define DEBOUNCE_MS         5


//------------  ������� ������ � ������� EEPROM  ---------
bool CheckClearAllPages(MDR_EEPROM_MEM bank);
bool ReadAllPagesAndCheckData(MDR_EEPROM_MEM bank);
bool EraseAllPagesAndCheck(MDR_EEPROM_MEM bank);
bool WriteAllPagesAndCheck(MDR_EEPROM_MEM bank);

//------------  ������ ��������� �����  -----------
typedef enum {
  tst_OK,
  tst_Err_EraseFull_Info,
  tst_Err_EraseFull_Main,
  tst_Err_CheckData,
  tst_Err_HoldData,
  tst_Err_ErasePages,
  tst_Started,
} TestResult;

#ifndef LCD_IS_7SEG_DISPLAY 
  #define STATUS_COUNT    7
  static char* resultNames[STATUS_COUNT] = {"Success", "E_EraseF_Info", "E_EraseF_Main", "E_CheckData", "E_HoldData", "E_ErasePages", "Started..."};
#endif

//------------- �������� ������ � �� ���������--------------
typedef enum {
  test_Main_HoldInfo,
  test_Info_HoldMain,
  test_EraseFull
} TestActive;

static TestActive activeTest;
#ifndef LCD_IS_7SEG_DISPLAY 
  static char* testNames[] = {"MainWR", "InfoWR", "Erase"};
#endif

//  !!! ��� 1986��4� (�������� � ��� 1986��214,1986��234)!!!
//  ������ �� ���������� �������������� ������ �������� ������ � ������ �����. 
//  �� ���������� � ��������� ������ �������� ����������������� ���� �� �������!
  
//  ������� ����� ������
#ifdef MDR_EEPROM_18MHz
  TestResult Test_EraseCM0_T1(void);
  TestResult Test_EraseCM0_T2(void); 
#else  
  TestResult Test_BankWriteErase(MDR_EEPROM_MEM testBank, MDR_EEPROM_MEM holdDataBank);
  TestResult Test_EraseModes(void);
#endif

//--------------  ��������� LCD ������  -----------------
#ifdef LCD_PIN_CONFLICT  
  #define LCD_PIN_CAPTURE   MDRB_LCD_CapturePins()
  #define LCD_PIN_RELEASE   MDRB_LCD_ReleasePins()
  
#else
  #define LCD_PIN_CAPTURE
  #define LCD_PIN_RELEASE
#endif

#define LCD_LINE_INFO       3
#define LCD_LINE_RESULT     5

void LCD_ShowActiveTest(TestActive testItem);
void LCD_ShowTestResult(TestResult result);

#define USE_HSI			1

//  ------------------- ��������� -------------------
int main(void)
{
  TestResult result;
  uint32_t CPU_FreqHz;
  
 // MDR_DebugerProtectDelay();
   
	// ����� ������� HSI ��� HSE_Max
#if USE_HSI
		MDR_CPU_SetClock_HSI_def();
#else
		MDR_CPU_SetClock_HSE_PLL_def(MDR_Off, PLL_MUL, BKP_LowRI, EEPROM_Delay);
#endif
	
	CPU_FreqHz = MDR_CPU_GetFreqHz(true);
	
  // ������������� ������, EEPROM,LCD
  MDRB_Buttons_Init(DEBOUNCE_MS, HSI_FREQ_HZ);	
	MDR_EEPROM_Init(CPU_FreqHz);
	MDRB_LCD_Init(CPU_FreqHz);	
	
	activeTest = test_Main_HoldInfo;  
	LCD_ShowActiveTest(activeTest);
	
	
  while (1)
  {
    //  ����� ������� HSI ��� HSE_Max
    if (MDRB_BntClicked_Up(true))
    {
      if (activeTest != test_EraseFull)
        ++activeTest;
      else
        activeTest = test_Main_HoldInfo;
      
      LCD_ShowActiveTest(activeTest);
    }
    //  ������ �����
    if (MDRB_BntClicked_Right(true))
    {
      LCD_ShowTestResult(tst_Started);
      
#ifndef MDR_EEPROM_18MHz      
      switch (activeTest) 
      {
        case test_Main_HoldInfo:
          result = Test_BankWriteErase(MDR_EEPROM_Main, MDR_EEPROM_Info);
          break;
        case test_Info_HoldMain:
          result = Test_BankWriteErase(MDR_EEPROM_Info, MDR_EEPROM_Main);
          break;
        case test_EraseFull:
          result = Test_EraseModes();
      }
      LCD_ShowTestResult(result);
      
#else
      result = Test_EraseCM0_T1();
      LCD_ShowTestResult(result);
      
      result = Test_EraseCM0_T2();
      LCD_ShowTestResult(result);
      
#endif
    }
  }
}

#ifdef MDR_EEPROM_18MHz
  TestResult Test_EraseCM0_T2(void)
  {
    uint32_t addr, valRD;
    MDR_EEPROM_PAGE page;
    MDR_EEPROM_BLOCK block;  
    MDR_EEPROM_MEM bank = MDR_EEPROM_Info;
    
    uint32_t errCnt, clrCnt;
    
    MDR_EEPROM_EraseFull(EEPROM_EraseFull_MainAndInfo);  
    
    
    errCnt = clrCnt = 0;
    for (block = EEPROM_Block1; block <= EEPROM_Block4; ++block)
      for (page = EEPROM_Page1; page <= EEPROM_Page4; ++page)
      {
        addr = MDR_EEPROM_PageToAddr(block, page, bank);
        MDR_EEPROM_Write(addr, addr, bank);
        valRD = MDR_EEPROM_Read(addr, bank);
        if (valRD != addr)
          ++errCnt;
        if (valRD == MDR_EEPROM_CLEAR_VALUE)
          ++clrCnt;
      }
      
    if ((clrCnt + errCnt) == 0)
      return tst_OK;
    else
      return tst_Err_HoldData;
  }


  TestResult Test_EraseCM0_T1(void)
  {
    //WriteAllPages(MDR_EEPROM_Main);
    //WriteAllPages(MDR_EEPROM_Info);
    //  �������� �������� � �������������� ������
    MDR_EEPROM_EraseFull(EEPROM_EraseFull_MainAndInfo);

    //  �������� main ��������
    if (!CheckClearAllPages(MDR_EEPROM_Main))
      return tst_Err_EraseFull_Main;   
    
    //  �������� Info ��������
    if (!CheckClearAllPages(MDR_EEPROM_Info))
      return tst_Err_EraseFull_Info;

    //=========== 
    //WriteAllPages(MDR_EEPROM_Main);
    WriteAllPages(MDR_EEPROM_Info);

  //  if (!ReadAllPagesAndCheckData(MDR_EEPROM_Main))
  //    return tst_Err_HoldData;
    
    ReadAllPagesAndCheckData(MDR_EEPROM_Info);
    
    //if (!ReadAllPagesAndCheckData(MDR_EEPROM_Info))
  //    return tst_Err_HoldData;
    
    MDR_EEPROM_EraseFull(EEPROM_EraseFull_Main);
     
    //  �������� main ��������
    if (!CheckClearAllPages(MDR_EEPROM_Main))
      return tst_Err_EraseFull_Main;   
    
    //  �������� Info �����������
    if (!ReadAllPagesAndCheckData(MDR_EEPROM_Info))
      return tst_Err_HoldData;
    
    return tst_OK;
  }

#else


  TestResult Test_BankWriteErase(MDR_EEPROM_MEM testBank, MDR_EEPROM_MEM holdDataBank)
  {
    //  �������� �������� � �������������� ������
    MDR_EEPROM_EraseFull(EEPROM_EraseFull_MainAndInfo);
    //  �������� Info ��������
    if (!CheckClearAllPages(MDR_EEPROM_Info))
      return tst_Err_EraseFull_Info; 
    //  �������� main ��������
    if (!CheckClearAllPages(MDR_EEPROM_Main))
      return tst_Err_EraseFull_Main;   

    //  ������ ������ ��� �������� 
    if (!WriteAllPagesAndCheck(holdDataBank))
      return tst_Err_CheckData;
    
    // ������ � �������� ������������ ����� ������
    if (!WriteAllPagesAndCheck(testBank))
      return tst_Err_CheckData;  
    if (!EraseAllPagesAndCheck(testBank))
      return tst_Err_ErasePages;
    
    // �������� ����������� ������
    if (!ReadAllPagesAndCheckData(holdDataBank))
      return tst_Err_HoldData;
    
    return tst_OK;
  }

  TestResult Test_EraseModes(void)
  {
    // ������ ������ � Main ������
    if (!WriteAllPagesAndCheck(MDR_EEPROM_Main))
      return tst_Err_CheckData;
    // ������ ������ � Info ������
    if (!WriteAllPagesAndCheck(MDR_EEPROM_Info))
      return tst_Err_CheckData;

    // ==== 1 - �������� ������ �������� =======
    MDR_EEPROM_EraseFull(EEPROM_EraseFull_Main);
    if (!CheckClearAllPages(MDR_EEPROM_Main))
      return tst_Err_EraseFull_Main;   
    
    // �������� ����������� ������ � Info
    if (!ReadAllPagesAndCheckData(MDR_EEPROM_Info))
      return tst_Err_HoldData;  
    
    // ==== 2 - �������� Main � Info =======
    // ������ ������ � Main ������
    if (!WriteAllPagesAndCheck(MDR_EEPROM_Main))
      return tst_Err_CheckData;  
    
    //  ��������
    MDR_EEPROM_EraseFull(EEPROM_EraseFull_MainAndInfo);
    
    //  �������� Info ��������
    if (!CheckClearAllPages(MDR_EEPROM_Info))
      return tst_Err_EraseFull_Info; 
    //  �������� main ��������
    if (!CheckClearAllPages(MDR_EEPROM_Main))
      return tst_Err_EraseFull_Main;

    return tst_OK;  
  }
#endif

void LCD_ShowActiveTest(TestActive testItem)
{
  static char mess[64];
  uint32_t cpuFreqHz = (uint32_t)MDR_CPU_GetFreqHz(false) / 1000000;
  
  LCD_PIN_CAPTURE;
  
#ifndef LCD_IS_7SEG_DISPLAY
  sprintf(mess, "%s, %dMHz", testNames[testItem], cpuFreqHz);
  MDRB_LCD_Print(mess, LCD_LINE_INFO);
  
#else
  sprintf(mess, "%d %d", (uint8_t)testItem, cpuFreqHz);
  MDRB_LCD_Print(mess);
  
#endif 
  
  LCD_PIN_RELEASE; 
}

void LCD_ShowTestResult(TestResult result)
{
  LCD_PIN_CAPTURE;
  
#ifndef LCD_IS_7SEG_DISPLAY   
  MDRB_LCD_Print(resultNames[result], LCD_LINE_RESULT);
  
#else
  static char mess[10];
  sprintf(mess, "%d", (uint8_t)result);
  MDRB_LCD_Print(mess);
  
#endif 
  
  LCD_PIN_RELEASE;
}




