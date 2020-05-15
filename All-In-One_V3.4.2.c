
#include "lib/Main.h"
#include "lib/OLED.h"
#include "lib/Program.h"

char STOP = 1;                  //启停状态
char PlusButton = 0;            //加号键
char MinusButton = 0;           //减号键
char State = 1;                 //切换状态
char ScriptNum = 1;             //脚本编号
signed char CycleNum = 6;       //周期数
char CycleStr[3] = {48, 54, 0}; //周期数字符串形式
int BoxNum = 1;                 //箱数
char BoxStr[3] = {48, 49, 0};   //箱数字符串形式
signed char SkipWaitNum = 5;
char SkipWaitStr[3] = {48, 53, 0};
signed char LastFrameNum = 3;
char LastFrameStr[2] = {51, 0};
int DriveWaitNum = 30;
char DriveWaitStr[4] = {48, 51, 48, 0};
int PasswordNum = 0;
char PasswordStr[5] = {48, 48, 48, 48, 0};
signed char AddNum = 0;
char AddStr[2] = {48, 0};
long FrameNum = 0;                          //帧数
char FrameStr[6] = {48, 48, 48, 48, 48, 0}; //帧数字符串形式
signed char AutoRelease = 0;
long CopyNum = 1;
char CopyStr[4] = {48, 48, 48, 0};
char OthersNum = 1;
char AnimalCrossingNum = 1;
char ProgressNum = 0;
char ProgressStr[3] = {48, 48, 0};
char SkipMode = 0; //跳帧模式
char SpeedUp = 0;
char LockMode = 1;
char initialized = 0; //初始化状态
char Stopping = 0;    //停止信号 用于逐层返回主循环并重新选择脚本
char buttonPIN = 0;
char SlowSwitch = 0;
char PressSwitch = 0;

long SizeofSync = 0;
long SizeofCollect = 0;
long SizeofHatch = 0;
//long SizeofHatch6 = 0;
//long SizeofHatch11 = 0;
//long SizeofHatch16 = 0;
//long SizeofHatch21 = 0;
//long SizeofHatch26 = 0;
//long SizeofHatch31 = 0;
//long SizeofHatch36 = 0;
//long SizeofHatch41 = 0;
long SizeofRelease = 0;
//long SizeofSkip = 0;
//long SizeofSkipFast = 0;
long SizeofCopy = 0;
long SizeofPgm = 0;
long SizeofPgmNow = 0;

int main(void)
{

  SetupHardware();

  PgmInit();

  for (;;)
  {
    PgmStart();
  }
}

//程序初始化
void PgmInit()
{
  OLED_P8x16Str(36, 1, "Loading");
  OLED_P6x8Str(92, 7, "V3.4.2");
  OLED_Set_Pos(8, 4);
  OLED_WrDat(0b11111111);
  for (char i = 0; i < 110; i++)
    OLED_WrDat(0b10000001);
  OLED_WrDat(0b11111111);
  delay(200);
  OLED_Set_Pos(11, 4);
  for (char i = 0; i < 40; i++)
  {
    OLED_WrDat(0b10011001);
    delay(5);
  }

  SizeofSync = GetDuration(Sync) * 5;
  SizeofCollect = GetDuration(CollectMove) * 3 + GetDuration(CollectLastMove) + GetDuration(GetEgg);
  SizeofHatch = GetDuration(BoxOperation1) + GetDuration(BoxOperation2) + GetDuration(BoxOperation3) + GetDuration(BoxOperation4) + GetDuration(BoxOperation5) + GetDuration(BoxOperation6) + GetDuration(BoxOperation7) + GetDuration(Hatched) * 30 + GetDuration(HatchReset) * 6 + GetDuration(OpenBox) * 7 + GetDuration(CloseBox) * 7;
  //SizeofHatch6 = GetDuration(BoxOperation1) + GetDuration(BoxOperation2) + GetDuration(BoxOperation3) + GetDuration(BoxOperation4) + GetDuration(BoxOperation5) + GetDuration(BoxOperation6) + GetDuration(BoxOperation7) + GetDuration(LastMove6) * 6 + GetDuration(Hatched) * 30 + GetDuration(HatchReset) * 6;
  //SizeofHatch11 = GetDuration(BoxOperation1) + GetDuration(BoxOperation2) + GetDuration(BoxOperation3) + GetDuration(BoxOperation4) + GetDuration(BoxOperation5) + GetDuration(BoxOperation6) + GetDuration(BoxOperation7) + GetDuration(HatchMove) * 6 + GetDuration(LastMove11) * 6 + GetDuration(Hatched) * 30 + GetDuration(HatchReset) * 6;
  //SizeofHatch16 = GetDuration(BoxOperation1) + GetDuration(BoxOperation2) + GetDuration(BoxOperation3) + GetDuration(BoxOperation4) + GetDuration(BoxOperation5) + GetDuration(BoxOperation6) + GetDuration(BoxOperation7) + GetDuration(HatchMove) * 12 + GetDuration(LastMove16) * 6 + GetDuration(Hatched) * 30 + GetDuration(HatchReset) * 6;
  //SizeofHatch21 = GetDuration(BoxOperation1) + GetDuration(BoxOperation2) + GetDuration(BoxOperation3) + GetDuration(BoxOperation4) + GetDuration(BoxOperation5) + GetDuration(BoxOperation6) + GetDuration(BoxOperation7) + GetDuration(HatchMove) * 12 + GetDuration(LastMove21) * 6 + GetDuration(Hatched) * 30 + GetDuration(HatchReset) * 6;
  //SizeofHatch26 = GetDuration(BoxOperation1) + GetDuration(BoxOperation2) + GetDuration(BoxOperation3) + GetDuration(BoxOperation4) + GetDuration(BoxOperation5) + GetDuration(BoxOperation6) + GetDuration(BoxOperation7) + GetDuration(HatchMove) * 18 + GetDuration(LastMove26) * 6 + GetDuration(Hatched) * 30 + GetDuration(HatchReset) * 6;
  //SizeofHatch31 = GetDuration(BoxOperation1) + GetDuration(BoxOperation2) + GetDuration(BoxOperation3) + GetDuration(BoxOperation4) + GetDuration(BoxOperation5) + GetDuration(BoxOperation6) + GetDuration(BoxOperation7) + GetDuration(HatchMove) * 24 + GetDuration(LastMove31) * 6 + GetDuration(Hatched) * 30 + GetDuration(HatchReset) * 6;
  //SizeofHatch36 = GetDuration(BoxOperation1) + GetDuration(BoxOperation2) + GetDuration(BoxOperation3) + GetDuration(BoxOperation4) + GetDuration(BoxOperation5) + GetDuration(BoxOperation6) + GetDuration(BoxOperation7) + GetDuration(HatchMove) * 24 + GetDuration(LastMove36) * 6 + GetDuration(Hatched) * 30 + GetDuration(HatchReset) * 6;
  //SizeofHatch41 = GetDuration(BoxOperation1) + GetDuration(BoxOperation2) + GetDuration(BoxOperation3) + GetDuration(BoxOperation4) + GetDuration(BoxOperation5) + GetDuration(BoxOperation6) + GetDuration(BoxOperation7) + GetDuration(HatchMove) * 30 + GetDuration(LastMove41) * 6 + GetDuration(Hatched) * 30 + GetDuration(HatchReset) * 6;
  SizeofRelease = GetDuration(Release) * 30 + GetDuration(RIGHT5) * 6 + GetDuration(UP5) * 12 + GetDuration(DOWN5) * 12;
  //SizeofSkip = GetDuration(Skip) * 31;
  //SizeofSkipFast = GetDuration(SkipFast) * 31;
  SizeofCopy = GetDuration(CollectMove) * 3 + GetDuration(CollectLastMove) + GetDuration(CopyGetEgg);
  SizeofPgm = GetDuration(Sync) * 5;

  STOP = 0;
  RunScript(Sync, 5);
  STOP = 1;

  OLED_Set_Pos(51, 4);
  for (char i = 0; i < 46; i++)
  {
    OLED_WrDat(0b10011001);
    delay(5);
  }

  ReadEepData();

  OLED_Set_Pos(97, 4);
  for (char i = 0; i < 20; i++)
  {
    OLED_WrDat(0b10011001);
    delay(5);
  }
  delay(200);
  OLED_P6x8Str(0, 6, "          ");
  OLED_P6x8Str(0, 7, "  ");
  OLED_P6x8Str(110, 7, "   ");
  //OLED_P6x8Str(48, 0, "  ");
  //OLED_P6x8Str(48, 1, "       ");
  OLED_P8x16Str(36, 1, "       ");
  OLED_P8x16Str(8, 4, "               ");
  OLED_P8x16Str(0, 0, "<");
  OLED_Set_Pos(116, 7);
  OLED_WrDat(0b00111100);
  OLED_WrDat(0b00111100);
  OLED_WrDat(0b00111100);
  OLED_WrDat(0b00111100);
  //OLED_P8x16Str(117,7,"N");
  OLED_P16x16Ch(96, 1, 14);
  OLED_Set_Pos(8, 7);
  OLED_WrDat(0b11111111);
  for (int i = 0; i < 104; i++)
    OLED_WrDat(0b10000001);
  OLED_WrDat(0b11111111);
  OLED_P8x16Str(88, 5, " --%");
  SwitchScript();
  initialized = 1;
}

//读取EEPROM
void ReadEepData()
{
  long eep1 = 0;
  long eep2 = 0;
  cli();
  for (int i = 0; i < 15; i++)
  {
    int x = i * 10 + 250;
    eep1 = eeprom_read_dword(x);
    delay(5);
    eep2 = eeprom_read_dword(x + 5);
    delay(5);
    if (eep1 == (eep2 - 10))
    {
      switch (i)
      {
      case 0:
        ScriptNum = (char)eeprom_read_dword(x);
        break;
      case 1:
        CycleNum = (signed char)eeprom_read_dword(x);
        break;
      case 2:
        BoxNum = (int)eeprom_read_dword(x);
        break;
      case 3:
        FrameNum = (long)eeprom_read_dword(x);
        break;
      case 4:
        SpeedUp = (char)eeprom_read_dword(x);
        break;
      case 5:
        LastFrameNum = (signed char)eeprom_read_dword(x);
        break;
      case 6:
        SkipWaitNum = (signed char)eeprom_read_dword(x);
        break;
      case 7:
        DriveWaitNum = (int)eeprom_read_dword(x);
        break;
      case 8:
        PasswordNum = (int)eeprom_read_dword(x);
        break;
      case 9:
        AddNum = (signed char)eeprom_read_dword(x);
        break;
      case 10:
        LockMode = (char)eeprom_read_dword(x);
        break;
      case 11:
        OthersNum = (char)eeprom_read_dword(x);
        break;
      case 12:
        AutoRelease = (signed char)eeprom_read_dword(x);
        break;
      case 13:
        CopyNum = (long)eeprom_read_dword(x);
        break;
      case 14:
        AnimalCrossingNum = (char)eeprom_read_dword(x);
        break;
      default:
        break;
      }
      delay(5);
    }
  }
  sei();
  NumToStr(CycleNum, CycleStr);
  NumToStr(BoxNum, BoxStr);
  NumToStr(FrameNum, FrameStr);
  NumToStr(LastFrameNum, LastFrameStr);
  NumToStr(SkipWaitNum, SkipWaitStr);
  NumToStr(DriveWaitNum, DriveWaitStr);
  NumToStr(PasswordNum, PasswordStr);
  NumToStr(AddNum, AddStr);
  NumToStr(CopyNum, CopyStr);
}

//写入EEPROM
void WriteEepData(int address, long num)
{
  cli();
  eeprom_write_dword(address, num);
  delay(10);
  eeprom_write_dword(address + 5, num + 10);
  sei();
}

/*
//寄存器置1
void set_bit(char x, char y)
{
  x |= 1u << y;
}

//寄存器置0
void reset_bit(char x, char y)
{
  x &= ~(1u << y);
}

//读取引脚电平
char read_bit(char x, char y)
{
  char i = x & (1u << y);
  return i;
}
*/

//数字转字符串
void NumToStr(long num, char str[])
{
  char x = 0;
  long i = 1;
  while (str[x] != 0)
    x++;
  while (x != 0)
  {
    x--;
    str[x] = (num / i) % 10 + 0x30;
    i *= 10;
  }
}

//获取脚本时长
long GetDuration(const command script[])
{
  long x = 0;
  for (int i = 0;; i++)
  {
    if (pgm_read_byte(&script[i].button) == SCRIPT_END)
      break;
    x += pgm_read_byte(&script[i].duration);
  }
  return x;
}

//切换脚本
void SwitchScript()
{
  if (State == 1)
  {
    if (PlusButton)
    {
      ScriptNum++;
      if (ScriptNum > 11)
        ScriptNum = 1;
    }
    if (MinusButton)
    {
      ScriptNum--;
      if (ScriptNum < 1)
        ScriptNum = 11;
    }
  }

  switch (ScriptNum)
  {
  case 1: //取孵一体
    OLED_P16x16Ch(8, 0, 0);
    OLED_P16x16Ch(24, 0, 2);
    OLED_P16x16Ch(40, 0, 3);
    OLED_P16x16Ch(56, 0, 4);
    OLED_P8x16Str(72, 0, ">");
    //OLED_P8x16Str(80, 0, "  ");

    OLED_P8x16Str(8, 2, CycleStr);
    OLED_P16x16Ch(24, 2, 7);
    OLED_P16x16Ch(40, 2, 8);
    OLED_P8x16Str(56, 2, "    ");

    OLED_P8x16Str(8, 4, BoxStr);
    OLED_P16x16Ch(24, 4, 9);
    OLED_P8x16Str(40, 4, "   ");
    break;
  case 2: //取蛋
    //OLED_P8x16Str(0,0,"<");
    OLED_P16x16Ch(8, 0, 0);
    OLED_P16x16Ch(24, 0, 1);
    OLED_P8x16Str(40, 0, ">");
    OLED_P8x16Str(48, 0, "    ");

    OLED_P8x16Str(8, 2, "      ");

    OLED_P8x16Str(8, 4, BoxStr);
    OLED_P16x16Ch(24, 4, 9);
    break;
  case 3: //孵蛋
          //OLED_P8x16Str(0,0,"<");
    OLED_P16x16Ch(8, 0, 2);
    OLED_P16x16Ch(24, 0, 1);
    OLED_P8x16Str(40, 0, ">");

    OLED_P8x16Str(8, 2, CycleStr);
    OLED_P16x16Ch(24, 2, 7);
    OLED_P16x16Ch(40, 2, 8);

    OLED_P8x16Str(8, 4, BoxStr);
    OLED_P16x16Ch(24, 4, 9);
    break;
  case 4: //放生
    //OLED_P8x16Str(0,0,"<");
    OLED_P16x16Ch(8, 0, 5);
    OLED_P16x16Ch(24, 0, 6);
    OLED_P8x16Str(40, 0, ">");

    OLED_P8x16Str(8, 2, "      ");

    OLED_P8x16Str(8, 4, BoxStr);
    OLED_P16x16Ch(24, 4, 9);
    OLED_P8x16Str(40, 4, "   ");
    break;
  case 5: //过帧
    //OLED_P8x16Str(0,0,"<");
    OLED_P16x16Ch(8, 0, 55);
    OLED_P16x16Ch(24, 0, 10);
    OLED_P8x16Str(40, 0, ">");
    OLED_P8x16Str(48, 0, "      ");

    if (SpeedUp)
    {
      OLED_P16x16Ch(8, 2, 63);
      OLED_P16x16Ch(24, 2, 64);
    }
    else
    {
      OLED_P16x16Ch(8, 2, 61);
      OLED_P16x16Ch(24, 2, 62);
    }
    OLED_P8x16Str(40, 2, "    ");

    OLED_P8x16Str(8, 4, FrameStr);
    OLED_P16x16Ch(48, 4, 10);
    //OLED_P8x16Str(64, 4, " ");
    break;
  case 6: //最后N帧
    //OLED_P8x16Str(0,0,"<");
    OLED_P16x16Ch(8, 0, 48);
    OLED_P16x16Ch(24, 0, 49);
    OLED_P8x16Str(40, 0, "N");
    OLED_P16x16Ch(48, 0, 10);
    OLED_P8x16Str(64, 0, ">");
    OLED_P8x16Str(72, 0, " ");

    OLED_P16x16Ch(8, 2, 52);
    OLED_P16x16Ch(24, 2, 53);
    OLED_P8x16Str(40, 2, SkipWaitStr);
    OLED_P16x16Ch(56, 2, 54);
    OLED_P8x16Str(72, 2, " ");

    OLED_P16x16Ch(8, 4, 55);
    OLED_P8x16Str(24, 4, LastFrameStr);
    OLED_P16x16Ch(32, 4, 10);
    OLED_P8x16Str(48, 4, "    ");
    break;
  case 7: //自动驾驶
    OLED_P8x16Str(0, 0, "<");
    OLED_P16x16Ch(8, 0, 21);
    OLED_P16x16Ch(24, 0, 22);
    OLED_P16x16Ch(40, 0, 42);
    OLED_P16x16Ch(56, 0, 43);
    OLED_P8x16Str(72, 0, ">");

    OLED_P16x16Ch(8, 2, 46);
    OLED_P16x16Ch(24, 2, 47);
    if (PasswordNum >= 10000 && PasswordNum <= 10009)
      OLED_P8x16Str(40, 2, "????");
    else if (PasswordNum >= 10010 && PasswordNum <= 10019)
      OLED_P8x16Str(40, 2, "----");
    else
      OLED_P8x16Str(40, 2, PasswordStr);

    OLED_P16x16Ch(8, 4, 52);
    OLED_P16x16Ch(24, 4, 53);
    OLED_P8x16Str(40, 4, DriveWaitStr);
    OLED_P16x16Ch(64, 4, 54);
    break;
  case 8: //道具复制
    OLED_P16x16Ch(8, 0, 65);
    OLED_P16x16Ch(24, 0, 66);
    OLED_P16x16Ch(40, 0, 67);
    OLED_P16x16Ch(56, 0, 68);
    OLED_P8x16Str(72, 0, ">");

    OLED_P8x16Str(8, 2, CopyStr);
    OLED_P16x16Ch(32, 2, 69);
    OLED_P8x16Str(48, 2, "     ");

    switch (AutoRelease)
    {
    case 0:
      OLED_P16x16Ch(8, 4, 71);
      OLED_P16x16Ch(24, 4, 72);
      OLED_P16x16Ch(40, 4, 5);
      OLED_P16x16Ch(56, 4, 6);
      break;
    case 1:
      OLED_P16x16Ch(8, 4, 73);
      OLED_P16x16Ch(24, 4, 69);
      OLED_P16x16Ch(40, 4, 5);
      OLED_P16x16Ch(56, 4, 6);
      break;
    case 2:
      OLED_P16x16Ch(8, 4, 73);
      OLED_P16x16Ch(24, 4, 9);
      OLED_P16x16Ch(40, 4, 5);
      OLED_P16x16Ch(56, 4, 6);
      break;
    case 3:
      OLED_P16x16Ch(8, 4, 45);
      OLED_P16x16Ch(24, 4, 1);
      OLED_P16x16Ch(40, 4, 74);
      OLED_P16x16Ch(56, 4, 38);
      break;
    default:
      break;
    }
    OLED_P8x16Str(72, 4, " ");
    break;
  case 9: //连接交换
    OLED_P16x16Ch(8, 0, 34);
    OLED_P16x16Ch(24, 0, 35);
    OLED_P16x16Ch(40, 0, 36);
    OLED_P16x16Ch(56, 0, 37);
    OLED_P8x16Str(72, 0, ">");

    OLED_P8x16Str(8, 2, "      ");

    OLED_P8x16Str(8, 4, BoxStr);
    OLED_P16x16Ch(24, 4, 9);
    OLED_P8x16Str(40, 4, "    ");
    break;
  case 10: //其他功能
    if (State == 1)
    {
      OLED_P16x16Ch(8, 0, 16);
      OLED_P16x16Ch(24, 0, 17);
      OLED_P16x16Ch(40, 0, 19);
      OLED_P16x16Ch(56, 0, 20);
      OLED_P8x16Str(72, 0, ">");
      OLED_P8x16Str(32, 2, "   ");
      OLED_P8x16Str(8, 4, "    ");
    }
    switch (OthersNum)
    {
    case 1: //连A
      OLED_P16x16Ch(8, 2, 34);
      OLED_P8x16Str(24, 2, "A");
      break;
    case 2: //刷瓦特
      OLED_P16x16Ch(8, 2, 27);
      OLED_P16x16Ch(24, 2, 32);
      OLED_P16x16Ch(40, 2, 33);
      break;
    case 3: //刷树果
      OLED_P16x16Ch(8, 2, 27);
      OLED_P16x16Ch(24, 2, 25);
      OLED_P16x16Ch(40, 2, 26);
      break;
    case 4: //刷头饰
      OLED_P16x16Ch(8, 2, 27);
      OLED_P16x16Ch(24, 2, 28);
      OLED_P16x16Ch(40, 2, 29);
      break;
    case 5: //刷经验
      OLED_P16x16Ch(8, 2, 27);
      OLED_P16x16Ch(24, 2, 40);
      OLED_P16x16Ch(40, 2, 41);
      break;
    case 6: //售货郎
      OLED_P16x16Ch(8, 2, 56);
      OLED_P16x16Ch(24, 2, 57);
      OLED_P16x16Ch(40, 2, 58);
      break;
    case 7: //ID抽奖
      OLED_P8x16Str(8, 2, "ID");
      OLED_P16x16Ch(24, 2, 23);
      OLED_P16x16Ch(40, 2, 24);
      break;
    default:
      break;
    }

    break;
  case 11: //动森功能
    if (State == 1)
    {
      OLED_P16x16Ch(8, 0, 22);
      OLED_P16x16Ch(24, 0, 39);
      OLED_P16x16Ch(40, 0, 19);
      OLED_P16x16Ch(56, 0, 20);
      OLED_P8x16Str(72, 0, ">");
      OLED_P8x16Str(32, 2, "   ");
      OLED_P8x16Str(8, 4, "    ");
    }
    switch (AnimalCrossingNum)
    {
    case 1: //连A
      OLED_P16x16Ch(8, 2, 34);
      OLED_P8x16Str(24, 2, "A");
      break;
    case 2: //连Y
      OLED_P16x16Ch(8, 2, 34);
      OLED_P8x16Str(24, 2, "Y");
      break;
    case 3: //刷动物
      OLED_P16x16Ch(8, 2, 27);
      OLED_P16x16Ch(24, 2, 22);
      OLED_P16x16Ch(40, 2, 15);
      break;
    default:
      break;
    }

    break;

  default:
    break;
  }
}

//切换指针
void SwitchPointer(char x1, char x2, char y1, char y2)
{
  OLED_P8x16Str(0, y1, " ");
  OLED_P8x16Str(x1, y1, " ");
  OLED_P8x16Str(0, y2, "<");
  OLED_P8x16Str(x2, y2, ">");
}

//操作状态
//State:
//1.功能
//2.周期
//3.箱
//4.帧
//5.跳帧秒
//6.开车秒
//7.密码
//8.其他功能
//9.最后帧
//10.锁定模式
//11.加好友
//12.过帧模式
//13.复制数量
//14.自动放生
//15.动森功能
void SwitchState()
{
  switch (ScriptNum)
  {
  case 1:
    if (State == 1)
    {
      State = 2;
      SwitchPointer(72, 56, 0, 2);
    }
    else if (State == 2)
    {
      State = 3;
      SwitchPointer(56, 40, 2, 4);
    }
    else
    {
      State = 1;
      SwitchPointer(40, 72, 4, 0);
    }
    break;

  case 3:
    if (State == 1)
    {
      State = 2;
      SwitchPointer(40, 56, 0, 2);
    }
    else if (State == 2)
    {
      State = 3;
      SwitchPointer(56, 40, 2, 4);
    }
    else
    {
      State = 1;
      SwitchPointer(40, 40, 4, 0);
    }
    break;

  case 2:
  case 4:
    if (State == 1)
    {
      State = 3;
      SwitchPointer(40, 40, 0, 4);
    }
    else
    {
      State = 1;
      SwitchPointer(40, 40, 4, 0);
    }
    break;

  case 5:
    if (State == 1)
    {
      State = 12;
      SwitchPointer(40, 40, 0, 2);
    }
    else if (State == 12)
    {
      State = 4;
      SwitchPointer(40, 64, 2, 4);
    }
    else
    {
      State = 1;
      SwitchPointer(64, 40, 4, 0);
    }
    break;

  case 6:
    if (State == 1)
    {
      State = 5;
      SwitchPointer(64, 72, 0, 2);
    }
    else if (State == 5)
    {
      State = 9;
      SwitchPointer(72, 48, 2, 4);
    }
    else
    {
      State = 1;
      SwitchPointer(48, 64, 4, 0);
    }
    break;

  case 7:
    switch (State)
    {
    case 1:
      State = 7;
      SwitchPointer(72, 72, 0, 2);
      break;
    case 7:
      State = 6;
      SwitchPointer(72, 80, 2, 4);
      break;
    case 6:
      State = 11;
      OLED_P8x16Str(8, 0, AddStr);
      OLED_P16x16Ch(16, 0, 31);
      OLED_P16x16Ch(32, 0, 30);
      OLED_P16x16Ch(48, 0, 50);
      OLED_P16x16Ch(64, 0, 51);

      OLED_P16x16Ch(8, 2, 55);
      OLED_P8x16Str(24, 2, LastFrameStr);
      OLED_P16x16Ch(32, 2, 10);
      OLED_P8x16Str(48, 2, "   ");

      if (LockMode)
        OLED_P16x16Ch(8, 4, 60);
      else
        OLED_P16x16Ch(8, 4, 59);
      OLED_P16x16Ch(24, 4, 18);
      OLED_P8x16Str(40, 4, "     ");

      SwitchPointer(80, 80, 4, 0);
      break;
    case 11:
      State = 9;
      SwitchPointer(80, 48, 0, 2);
      break;
    case 9:
      State = 10;
      SwitchPointer(48, 40, 2, 4);
      break;
    case 10:
      State = 1;
      SwitchScript();
      OLED_P8x16Str(0, 4, " ");
      OLED_P8x16Str(80, 0, " ");
      break;

    default:
      break;
    }
    break;

  case 8:
    if (State == 1)
    {
      State = 13;
      SwitchPointer(72, 48, 0, 2);
    }
    else if (State == 13)
    {
      State = 14;
      SwitchPointer(48, 72, 2, 4);
    }
    else
    {
      State = 1;
      SwitchPointer(72, 72, 4, 0);
    }
    break;

  case 9:
    if (State == 1)
    {
      State = 3;
      SwitchPointer(72, 40, 0, 4);
    }
    else
    {
      State = 1;
      SwitchPointer(40, 72, 4, 0);
    }
    break;

  case 10:
    if (State == 1)
    {
      State = 8;
      if (OthersNum == 1)
        SwitchPointer(72, 32, 0, 2);
      else
        SwitchPointer(72, 56, 0, 2);
    }
    else
    {
      State = 1;
      if (OthersNum == 1)
        SwitchPointer(32, 72, 2, 0);
      else
        SwitchPointer(56, 72, 2, 0);
    }
    break;
  case 11:
    if (State == 1)
    {
      State = 15;
      if (AnimalCrossingNum < 3)
        SwitchPointer(72, 32, 0, 2);
      else
        SwitchPointer(72, 56, 0, 2);
    }
    else
    {
      State = 1;
      if (AnimalCrossingNum < 3)
        SwitchPointer(32, 72, 2, 0);
      else
        SwitchPointer(56, 72, 2, 0);
    }
    break;
  default:
    break;
  }
}

/////////////////////////////////////////////////////////////

//切换周期数
void SwitchCycle()
{
  if (PlusButton)
  {
    CycleNum += 5;
    if (CycleNum > 41)
      CycleNum = 6;
  }
  if (MinusButton)
  {
    CycleNum -= 5;
    if (CycleNum < 6)
      CycleNum = 41;
  }
  NumToStr(CycleNum, CycleStr);
  OLED_P8x16Str(8, 2, CycleStr);
  //CycleStr[0] = CycleNum / 10 + 0x30;
  //CycleStr[1] = CycleNum % 10 + 0x30;
}

//切换箱数
void SwitchBox()
{
  if (PlusButton)
  {
    BoxNum++;
    if (BoxNum > 32)
      BoxNum = 1;
  }
  if (MinusButton)
  {
    BoxNum--;
    if (BoxNum < 1)
      BoxNum = 32;
  }
  NumToStr(BoxNum, BoxStr);
  OLED_P8x16Str(8, 4, BoxStr);
  //BoxStr[0] = BoxNum / 10 + 0x30;
  //BoxStr[1] = BoxNum % 10 + 0x30;
}

//切换帧数
void SwitchFrame()
{
  char x = 100;
  if (SlowSwitch)
    x = 1;
  if (PlusButton)
  {
    FrameNum += x;
    if (FrameNum > 90000)
      FrameNum = 0;
  }
  if (MinusButton)
  {
    FrameNum -= x;
    if (FrameNum < 0)
      FrameNum = 90000;
  }
  NumToStr(FrameNum, FrameStr);
  OLED_P8x16Str(8, 4, FrameStr);
  //FrameStr[0] = (FrameNum / 10000) % 10 + 0x30;
  //FrameStr[1] = (FrameNum / 1000) % 10 + 0x30;
  //FrameStr[2] = (FrameNum / 100) % 10 + 0x30;
  //FrameStr[3] = (FrameNum / 10) % 10 + 0x30;
  //FrameStr[4] = FrameNum % 10 + 0x30;
}

//切换过帧模式
void SwitchSpeed()
{
  if (PlusButton || MinusButton)
    SpeedUp = !SpeedUp;
  if (SpeedUp)
  {
    OLED_P16x16Ch(8, 2, 63);
    OLED_P16x16Ch(24, 2, 64);
  }
  else
  {
    OLED_P16x16Ch(8, 2, 61);
    OLED_P16x16Ch(24, 2, 62);
  }
}

//切换最后N帧
void SwitchLastFrame()
{
  if (PlusButton)
  {
    LastFrameNum++;
    if (LastFrameNum > 5)
      LastFrameNum = 0;
  }
  if (MinusButton)
  {
    LastFrameNum--;
    if (LastFrameNum < 0)
      LastFrameNum = 5;
  }
  NumToStr(LastFrameNum, LastFrameStr);
  if (ScriptNum == 6)
    OLED_P8x16Str(24, 4, LastFrameStr);
  else
    OLED_P8x16Str(24, 2, LastFrameStr);
  //LastFrameStr[0] = LastFrameNum % 10 + 0x30;
}

//切换N帧等待时间
void SwitchSkipWait()
{
  if (PlusButton)
  {
    SkipWaitNum += 5;
    if (SkipWaitNum > 90)
      SkipWaitNum = 0;
  }
  if (MinusButton)
  {
    SkipWaitNum -= 5;
    if (SkipWaitNum < 0)
      SkipWaitNum = 90;
  }
  NumToStr(SkipWaitNum, SkipWaitStr);
  OLED_P8x16Str(40, 2, SkipWaitStr);
  //SkipWaitStr[0] = (SkipWaitNum / 10) % 10 + 0x30;
  //SkipWaitStr[1] = SkipWaitNum % 10 + 0x30;
}

//切换开车等待时间
void SwitchDriveWait()
{
  if (PlusButton)
  {
    DriveWaitNum += 30;
    if (DriveWaitNum > 180)
      DriveWaitNum = 0;
  }
  if (MinusButton)
  {
    DriveWaitNum -= 30;
    if (DriveWaitNum < 0)
      DriveWaitNum = 180;
  }
  NumToStr(DriveWaitNum, DriveWaitStr);
  OLED_P8x16Str(40, 4, DriveWaitStr);
  //DriveWaitStr[0] = (DriveWaitNum / 100) % 10 + 0x30;
  //DriveWaitStr[1] = (DriveWaitNum / 10) % 10 + 0x30;
  //DriveWaitStr[2] = DriveWaitNum % 10 + 0x30;
}

//切换密码
void SwitchPassword()
{
  char x = 10;
  if (SlowSwitch)
    x = 1;
  if (PlusButton)
  {
    PasswordNum += x;
    if (PasswordNum > 10019)
      PasswordNum = 0;
  }
  if (MinusButton)
  {
    PasswordNum -= x;
    if (PasswordNum < 0)
      PasswordNum = 10019;
  }
  NumToStr(PasswordNum, PasswordStr);
  if (PasswordNum >= 10000 && PasswordNum <= 10009)
    OLED_P8x16Str(40, 2, "????");
  else if (PasswordNum >= 10010 && PasswordNum <= 10019)
    OLED_P8x16Str(40, 2, "----");
  else
    OLED_P8x16Str(40, 2, PasswordStr);
  //PasswordStr[0] = (PasswordNum / 1000) % 10 + 0x30;
  //PasswordStr[1] = (PasswordNum / 100) % 10 + 0x30;
  //PasswordStr[2] = (PasswordNum / 10) % 10 + 0x30;
  //PasswordStr[3] = PasswordNum % 10 + 0x30;
}

//切换锁定模式
void SwitchLockMode()
{
  if (PlusButton || MinusButton)
    LockMode = !LockMode;
  if (LockMode)
    OLED_P16x16Ch(8, 4, 60);
  else
    OLED_P16x16Ch(8, 4, 59);
  OLED_P16x16Ch(24, 4, 18);
}

//切换N车加好友
void SwitchAdd()
{
  if (PlusButton)
  {
    AddNum++;
    if (AddNum > 9)
      AddNum = 0;
  }
  if (MinusButton)
  {
    AddNum--;
    if (AddNum < 0)
      AddNum = 9;
  }
  NumToStr(AddNum, AddStr);
  OLED_P8x16Str(8, 0, AddStr);
  //AddStr[0] = AddNum % 10 + 0x30;
}

//切换道具复制数量
void SwitchCopy()
{
  if (PlusButton)
  {
    CopyNum++;
    if (CopyNum > 999)
      CopyNum = 1;
  }
  if (MinusButton)
  {
    CopyNum--;
    if (CopyNum < 1)
      CopyNum = 999;
  }
  NumToStr(CopyNum, CopyStr);
  OLED_P8x16Str(8, 2, CopyStr);
  //CopyStr[0] = (CopyNum / 100) % 10 + 0x30;
  //CopyStr[1] = (CopyNum / 10) % 10 + 0x30;
  //CopyStr[2] = CopyNum % 10 + 0x30;
}

//切换自动放生
void SwitchAutoRelease()
{
  if (PlusButton)
  {
    AutoRelease++;
    if (AutoRelease > 3)
      AutoRelease = 0;
  }
  if (MinusButton)
  {
    AutoRelease--;
    if (AutoRelease < 0)
      AutoRelease = 3;
  }
  switch (AutoRelease)
  {
  case 0:
    OLED_P16x16Ch(8, 4, 71);
    OLED_P16x16Ch(24, 4, 72);
    OLED_P16x16Ch(40, 4, 5);
    OLED_P16x16Ch(56, 4, 6);
    break;
  case 1:
    OLED_P16x16Ch(8, 4, 73);
    OLED_P16x16Ch(24, 4, 69);
    OLED_P16x16Ch(40, 4, 5);
    OLED_P16x16Ch(56, 4, 6);
    break;
  case 2:
    OLED_P16x16Ch(8, 4, 73);
    OLED_P16x16Ch(24, 4, 9);
    OLED_P16x16Ch(40, 4, 5);
    OLED_P16x16Ch(56, 4, 6);
    break;
  case 3:
    OLED_P16x16Ch(8, 4, 45);
    OLED_P16x16Ch(24, 4, 1);
    OLED_P16x16Ch(40, 4, 74);
    OLED_P16x16Ch(56, 4, 38);
    break;
  default:
    break;
  }
}

//切换其他功能
void SwitchOthers()
{
  if (PlusButton)
  {
    OthersNum++;
    if (OthersNum > 7)
      OthersNum = 1;
  }
  if (MinusButton)
  {
    OthersNum--;
    if (OthersNum < 1)
      OthersNum = 7;
  }
  SwitchScript();
  if (OthersNum == 1)
  {
    OLED_P8x16Str(32, 2, ">");
    OLED_P8x16Str(40, 2, "   ");
  }
  else
    OLED_P8x16Str(56, 2, ">");
}

//切换动森功能
void SwitchAnimalCrossing()
{
  if (PlusButton)
  {
    AnimalCrossingNum++;
    if (AnimalCrossingNum > 3)
      AnimalCrossingNum = 1;
  }
  if (MinusButton)
  {
    AnimalCrossingNum--;
    if (AnimalCrossingNum < 1)
      AnimalCrossingNum = 3;
  }
  SwitchScript();
  if (AnimalCrossingNum < 3)
  {
    OLED_P8x16Str(32, 2, ">");
    OLED_P8x16Str(40, 2, "   ");
  }
  else
    OLED_P8x16Str(56, 2, ">");
}

/*
void CycleOLED()
{
  SwitchCycle();
  OLED_P8x16Str(8, 2, CycleStr);
}

void BoxOLED()
{
  SwitchBox();
  OLED_P8x16Str(8, 4, BoxStr);
}

void FrameOLED()
{
  SwitchFrame();
  OLED_P8x16Str(8, 4, FrameStr);
}

void SkipWaitOLED()
{
  SwitchSkipWait();
  OLED_P8x16Str(40, 2, SkipWaitStr);
}

void DriveWaitOLED()
{
  SwitchDriveWait();
  OLED_P8x16Str(40, 4, DriveWaitStr);
}

void PasswordOLED()
{
  SwitchPassword();
  if (PasswordNum >= 10000 && PasswordNum <= 10009)
    OLED_P8x16Str(40, 2, "????");
  else if (PasswordNum >= 10010 && PasswordNum <= 10019)
    OLED_P8x16Str(40, 2, "----");
  else
    OLED_P8x16Str(40, 2, PasswordStr);
}

void LastFrameOLED()
{
  SwitchLastFrame();
  if (ScriptNum == 6)
    OLED_P8x16Str(24, 4, LastFrameStr);
  else
    OLED_P8x16Str(24, 2, LastFrameStr);
}

void AddOLED()
{
  SwitchAdd();
  OLED_P8x16Str(8, 0, AddStr);
}

void CopyOLED()
{
  SwitchCopy();
  OLED_P8x16Str(8, 2, CopyStr);
}
*/

/////////////////////////////////////////////////////////////

//切换变量
void SwitchVariable(void (*Func)(void), int speed)
{
  if (SlowSwitch)
    speed = 50;
  for (int i = 0;; i++)
  {
    if (read_bit(PINF, buttonPIN))
    {
      Func();
      break;
    }
    if (i > (300 / speed - 1))
    {
      Func();
    }
    delay(speed);
  }
}

void delay(int ms)
{
  for (; ms > 0; ms--)
  {
    _delay_ms(1);
  }
}

//设置引脚状态
void SetupButtons()
{
  //地
  set_bit(DDRF, 4);
  reset_bit(PORTF, 4);
  //减
  reset_bit(DDRF, 5);
  set_bit(PORTF, 5);
  //加
  reset_bit(DDRF, 6);
  set_bit(PORTF, 6);
  //切换
  reset_bit(DDRF, 7);
  set_bit(PORTF, 7);
  //启停
  reset_bit(DDRB, 1);
  set_bit(PORTB, 1);
  /*
  //地
  set_bit(DDRB, 1);
  reset_bit(PORTB, 1);
  //减
  reset_bit(DDRF, 5);
  set_bit(PORTF, 5);
  //加
  reset_bit(DDRF, 4);
  set_bit(PORTF, 4);
  //切换
  reset_bit(DDRF, 6);
  set_bit(PORTF, 6);
  //启停
  reset_bit(DDRF, 7);
  set_bit(PORTF, 7);
*/
}

//启停
void StopScript()
{
  STOP = !STOP;
  if (STOP)
  {
    OLED_P8x16Str(88, 5, " --");
    OLED_Set_Pos(11, 7);
    for (int i = 0; i < 100; i++)
      OLED_WrDat(0b10000001);
    OLED_Set_Pos(116, 7);
    OLED_WrDat(0b00111100);
    OLED_WrDat(0b00111100);
    OLED_WrDat(0b00111100);
    OLED_WrDat(0b00111100);
    //OLED_P8x16Str(117,7,"N");
  }
  else
  {
    OLED_P8x16Str(88, 5, " ");
    OLED_P8x16Str(96, 5, ProgressStr);
    OLED_Set_Pos(11, 7);
    for (int i = 0; i < 100; i++)
      OLED_WrDat(0b10000001);
    OLED_Set_Pos(116, 7);
    OLED_WrDat(0b11111110);
    OLED_WrDat(0b01111100);
    OLED_WrDat(0b00111000);
    OLED_WrDat(0b00010000);
    //OLED_P8x16Str(117,7,"Y");
    Stopping = 1;
  }
}

//按键切换
void SwitchButton()
{
  OLED_P8x16Str(88, 5, " --");
  OLED_Set_Pos(11, 7);
  for (int i = 0; i < 100; i++)
    OLED_WrDat(0b10000001);
  switch (State)
  {
  case 1:
    SwitchVariable(SwitchScript, 50);
    WriteEepData(250, ScriptNum);
    break;
  case 2:
    SwitchVariable(SwitchCycle, 50);
    WriteEepData(260, CycleNum);
    break;
  case 3:
    SwitchVariable(SwitchBox, 50);
    WriteEepData(270, BoxNum);
    break;
  case 4:
    if (PressSwitch)
      SlowSwitch = 1;
    SwitchVariable(SwitchFrame, 10);
    WriteEepData(280, FrameNum);
    break;
  case 5:
    SwitchVariable(SwitchSkipWait, 50);
    WriteEepData(310, SkipWaitNum);
    break;
  case 6:
    SwitchVariable(SwitchDriveWait, 50);
    WriteEepData(320, DriveWaitNum);
    break;
  case 7:
    if (PressSwitch)
      SlowSwitch = 1;
    SwitchVariable(SwitchPassword, 10);
    WriteEepData(330, PasswordNum);
    break;
  case 8:
    SwitchVariable(SwitchOthers, 50);
    WriteEepData(360, OthersNum);
    break;
  case 9:
    SwitchVariable(SwitchLastFrame, 50);
    WriteEepData(300, LastFrameNum);
    break;
  case 10:
    SwitchVariable(SwitchLockMode, 50);
    WriteEepData(350, LockMode);
    break;
  case 11:
    SwitchVariable(SwitchAdd, 50);
    WriteEepData(340, AddNum);
    break;
  case 12:
    SwitchVariable(SwitchSpeed, 50);
    WriteEepData(290, SpeedUp);
    break;
  case 13:
    SwitchVariable(SwitchCopy, 10);
    WriteEepData(380, CopyNum);
    break;
  case 14:
    SwitchVariable(SwitchAutoRelease, 50);
    WriteEepData(370, AutoRelease);
    break;
  case 15:
    SwitchVariable(SwitchAnimalCrossing, 50);
    WriteEepData(390, AnimalCrossingNum);
    break;
  default:
    break;
  }
}

//按键检测
void PressButton()
{
  if (initialized)
  {
    //启停键
    if (!read_bit(PINB, 1))
    //if (!read_bit(PINF, 7))
    {
      delay(100);
      for (;;)
      {
        if (read_bit(PINB, 1))
        //if (!read_bit(PINF, 7))
        {
          StopScript();
          break;
        }
        delay(20);
      }
    }

    if (STOP)
    {
      //切换键
      if (!read_bit(PINF, 7))
        PressSwitch = 1;
      if (PressSwitch && read_bit(PINF, 7))
      {
        if (!SlowSwitch)
          SwitchState();
        PressSwitch = 0;
        SlowSwitch = 0;
      }

      //加号键
      if (!read_bit(PINF, 6))
      //if (!read_bit(PINF, 4))
      {
        delay(100);
        PlusButton = 1;
        buttonPIN = 6;
        SwitchButton();
        //SwitchButton(4);
        PlusButton = 0;
      }

      //减号键
      if (!read_bit(PINF, 5))
      {
        delay(100);
        MinusButton = 1;
        buttonPIN = 5;
        SwitchButton();
        MinusButton = 0;
      }
    }
  }
}

//切换LED
void SwitchLED()
{
  if (!STOP)
  {
    set_bit(DDRD, 5);
    reset_bit(PORTD, 5);
  }
  else
    reset_bit(DDRD, 5);
}

//刷新进度条
void RefreshProgress()
{
  ProgressNum = SizeofPgmNow * 100 / SizeofPgm;
  ProgressStr[0] = ProgressNum / 10 + 0x30;
  ProgressStr[1] = ProgressNum % 10 + 0x30;
  OLED_P8x16Str(96, 5, ProgressStr);

  if (ProgressNum)
  {
    OLED_Set_Pos(10 + ProgressNum, 7);
    OLED_WrDat(0b10011001);
  }
  if (ScriptNum < 6 || ScriptNum == 8 || ScriptNum == 9)
    SizeofPgmNow++;
}

//运行指令
void RunStep(Buttons_t button, uint16_t duration)
{
  if (Stopping)
    return;
  for (; duration > 0; duration--)
  {
    cli();
    SwitchLED();
    if (!STOP && initialized)
      RefreshProgress();
    PressButton();
    HID_Task(button);

    if (Stopping)
      break;
    USB_USBTask();
    if (!SkipMode)
      delay(20);
    delay(3);
    sei();
  }
}

//读取模块
void RunScript(const command script[], int times)
{
  if (Stopping)
    return;
  for (; times > 0; times--)
  {
    for (int i = 0;; i++)
    {
      if (pgm_read_byte(&script[i].button) == SCRIPT_END)
        break;
      RunStep(pgm_read_byte(&script[i].button), pgm_read_byte(&script[i].duration));
      if (Stopping)
        break;
    }
    if (Stopping)
      break;
  }
}

//程序结束
void PgmEnd()
{
  if (Stopping)
    return;
  if (!STOP)
  {
    STOP = 1;
    OLED_P8x16Str(88, 5, "100");
    OLED_Set_Pos(110, 7);
    OLED_WrDat(0b10011001);
    OLED_Set_Pos(116, 7);
    OLED_WrDat(0b00111100);
    OLED_WrDat(0b00111100);
    OLED_WrDat(0b00111100);
    OLED_WrDat(0b00111100);
  }
}

void SetupHardware(void)
{
  // We need to disable watchdog if enabled by bootloader/fuses.
  MCUSR &= ~(1 << WDRF);
  wdt_disable();

  // We need to disable clock division before initializing the USB hardware.
  clock_prescale_set(clock_div_1);
  // We can then initialize our hardware and peripherals, including the USB stack.
  SetupButtons();

  set_bit(PORTD, 1);
  set_bit(DDRD, 1);
  set_bit(DDRD, 0);
  set_bit(DDRD, 4);
  /*
  set_bit(PORTD, 1);
  set_bit(DDRD, 1);
  set_bit(DDRD, 0);
  set_bit(DDRD, 4);
*/

  USB_Init();

  OLED_Init();
}

// Fired to indicate that the device is enumerating.
void EVENT_USB_Device_Connect(void)
{
  // We can indicate that we're enumerating here (via status LEDs, sound, etc.).
}

// Fired to indicate that the device is no longer connected to a host.
void EVENT_USB_Device_Disconnect(void)
{
  // We can indicate that our device is not ready (via status LEDs, sound, etc.).
}

// Fired when the host set the current configuration of the USB device after enumeration.
void EVENT_USB_Device_ConfigurationChanged(void)
{
  bool ConfigSuccess = true;

  // We setup the HID report endpoints.
  ConfigSuccess &= Endpoint_ConfigureEndpoint(JOYSTICK_OUT_EPADDR, EP_TYPE_INTERRUPT, JOYSTICK_EPSIZE, 1);
  ConfigSuccess &= Endpoint_ConfigureEndpoint(JOYSTICK_IN_EPADDR, EP_TYPE_INTERRUPT, JOYSTICK_EPSIZE, 1);

  // We can read ConfigSuccess to indicate a success or failure at this point.
}

// Process control requests sent to the device from the USB host.
void EVENT_USB_Device_ControlRequest(void)
{
  // We can handle two control requests: a GetReport and a SetReport.

  // Not used here, it looks like we don't receive control request from the Switch.
}

// Process and deliver data from IN and OUT endpoints.
void HID_Task(Buttons_t button)
{

  // If the device isn't connected and properly configured, we can't do anything here.
  if (USB_DeviceState != DEVICE_STATE_Configured)
    return;

  // We'll start with the OUT endpoint.
  Endpoint_SelectEndpoint(JOYSTICK_OUT_EPADDR);
  // We'll check to see if we received something on the OUT endpoint.
  if (Endpoint_IsOUTReceived())
  {
    // If we did, and the packet has data, we'll react to it.
    if (Endpoint_IsReadWriteAllowed())
    {
      // We'll create a place to store our data received from the host.
      USB_JoystickReport_Output_t JoystickOutputData;
      // We'll then take in that data, setting it up in our storage.
      while (Endpoint_Read_Stream_LE(&JoystickOutputData, sizeof(JoystickOutputData), NULL) != ENDPOINT_RWSTREAM_NoError)
        ;
      // At this point, we can react to this data.

      // However, since we're not doing anything with this data, we abandon it.
    }
    // Regardless of whether we reacted to the data, we acknowledge an OUT packet on this endpoint.
    Endpoint_ClearOUT();
  }

  // We'll then move on to the IN endpoint.
  Endpoint_SelectEndpoint(JOYSTICK_IN_EPADDR);
  // We first check to see if the host is ready to accept data.
  if (Endpoint_IsINReady())
  {
    // We'll create an empty report.
    USB_JoystickReport_Input_t JoystickInputData;
    // We'll then populate this report with what we want to send to the host.
    GetNextReport(&JoystickInputData, button);
    // Once populated, we can output this data to the host. We do this by first writing the data to the control stream.
    while (Endpoint_Write_Stream_LE(&JoystickInputData, sizeof(JoystickInputData), NULL) != ENDPOINT_RWSTREAM_NoError)
      ;
    // We then send an IN packet on this endpoint.
    Endpoint_ClearIN();
  }
}

USB_JoystickReport_Input_t last_report;

int report_count = 0;
//int hold_LX = STICK_CENTER;
//int hold_LY = STICK_CENTER;
//int hold_RX = STICK_CENTER;

void GetNextReport(USB_JoystickReport_Input_t *const ReportData, Buttons_t button)
{
  //按键释放
  memset(ReportData, 0, sizeof(USB_JoystickReport_Input_t));
  ReportData->LX = STICK_CENTER;
  ReportData->LY = STICK_CENTER;
  ReportData->RX = STICK_CENTER;
  ReportData->RY = STICK_CENTER;
  ReportData->HAT = HAT_CENTER;

  //ReportData->LX = hold_LX;
  //ReportData->LY = hold_LY;
  //ReportData->RX = hold_RX;

  if (!STOP)
  {
    switch (button)
    {
    case UP:
      ReportData->LY = STICK_MIN;
      break;

    case LEFT:
      ReportData->LX = STICK_MIN;
      break;

    case DOWN:
      ReportData->LY = STICK_MAX;
      break;

    case RIGHT:
      ReportData->LX = STICK_MAX;
      break;

    case RLEFT:
      ReportData->RX = STICK_MIN;
      break;

    case RRIGHT:
      ReportData->RX = STICK_MAX;
      break;
      /*
    case HATLEFT:
      ReportData->HAT = HAT_LEFT;
      break;

    case HATRIGHT:
      ReportData->HAT = HAT_RIGHT;
      break;

    case HATCENTER:
      ReportData->HAT = HAT_CENTER;
      break;
*/
    case UPLEFT:
      ReportData->LY = STICK_MIN;
      ReportData->LX = STICK_MIN;
      break;

    case UPRIGHT:
      ReportData->LY = STICK_MIN;
      ReportData->LX = STICK_MAX;
      break;

    case DOWNLEFT:
      ReportData->LY = STICK_MAX;
      ReportData->LX = STICK_MIN;
      break;

    case DOWNRIGHT:
      ReportData->LY = STICK_MAX;
      ReportData->LX = STICK_MAX;
      break;

    case A:
      ReportData->Button |= SWITCH_A;
      break;

    case B:
      ReportData->Button |= SWITCH_B;
      break;

    case X:
      ReportData->Button |= SWITCH_X;
      break;

    case Y:
      ReportData->Button |= SWITCH_Y;
      break;

    case L:
      ReportData->Button |= SWITCH_L;
      break;

    case R:
      ReportData->Button |= SWITCH_R;
      break;

    case PLUS:
      ReportData->Button |= SWITCH_PLUS;
      break;

    case HOME:
      ReportData->Button |= SWITCH_HOME;
      break;

    case RCLICK:
      ReportData->Button |= SWITCH_RCLICK;
      break;

    default:
      break;
    }
  }

  memcpy(&last_report, ReportData, sizeof(USB_JoystickReport_Input_t));
}
