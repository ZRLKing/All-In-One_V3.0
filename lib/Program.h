//extern char AutoPause;
extern char ScriptNum;
extern signed char CycleNum;
extern int BoxNum;
extern char InfUsedNum;
extern long FrameNum;
extern signed char SkipWaitNum;
extern signed char LastFrameNum;
extern int DriveWaitNum;
extern int PasswordNum;
extern long SizeofCollect;
extern long SizeofHatch6;
extern long SizeofHatch11;
extern long SizeofHatch16;
extern long SizeofHatch21;
extern long SizeofHatch26;
extern long SizeofHatch31;
extern long SizeofHatch36;
extern long SizeofHatch41;
extern long SizeofRelease;
extern long SizeofSkip;
extern long SizeofPgm;
extern long SizeofPgmNow;

void PgmStart(void);
void CollectAndHatch(void);
void Collecting(void);
void Hatching(void);
void HatchOpration(void);
void Releasing(void);
void Skipping(void);
void SkipLastFrame(void);
void Driving(void);
void SkipAndDrive(void);
void InfUsed(void);
void PressA(void);
void LuckDraw(void);
void CollectWatt(void);
void CollectBerry(void);
void HeadwearBattle(void);
void PokeJob(void);

/////////////////////////ģ����/////////////////////////

//����ʱ��40Լ����1��

//ȡ���ƶ�
static const command CollectMove[] PROGMEM = {
    {UPRIGHT, 2},
    {UPLEFT, 2},
    {LEFT, 60},
    {PAUSE, 5},
    {UPLEFT, 2},
    {UPRIGHT, 2},
    {RIGHT, 60},
    {PAUSE, 5},
    {SCRIPT_END, 0},
};

//ȡ���Ի�
static const command GetEgg[] PROGMEM = {
    {UPRIGHT, 5},
    {PAUSE, 5},
    {A, 2},
    {PAUSE, 50},
    {A, 2},
    {PAUSE, 150},
    {B, 2},
    {PAUSE, 80},
    {B, 2},
    {PAUSE, 80},
    {B, 2},
    {PAUSE, 30},
    {SCRIPT_END, 0},
};

//ȡ����������
static const command CollectToHatch[] PROGMEM = {
    {DOWN, 10},
    {PAUSE, 5},
    {RIGHT, 200},
    {PAUSE, 5},
    {DOWNLEFT, 100},
    {PAUSE, 5},
    {X, 2},
    {PAUSE, 50},
    {A, 2},
    {PAUSE, 80},
    {R, 2},
    {PAUSE, 100},
    {LEFT, 2},
    {PAUSE, 5},
    {DOWN, 2},
    {PAUSE, 5},
    {A, 2},
    {PAUSE, 30},
    {UP, 2},
    {PAUSE, 5},
    {UP, 2},
    {PAUSE, 5},
    {A, 2},
    {PAUSE, 30},
    {UP, 2},
    {PAUSE, 5},
    {A, 2},
    {PAUSE, 60},
    {A, 2},
    {PAUSE, 50},
    {A, 2},
    {PAUSE, 30},
    {UP, 2},
    {PAUSE, 5},
    {UP, 2},
    {PAUSE, 5},
    {A, 2},
    {PAUSE, 30},
    {UP, 2},
    {PAUSE, 5},
    {A, 2},
    {PAUSE, 60},
    {A, 2},
    {PAUSE, 50},
    {A, 2},
    {PAUSE, 30},
    {UP, 2},
    {PAUSE, 5},
    {UP, 2},
    {PAUSE, 5},
    {A, 2},
    {PAUSE, 30},
    {UP, 2},
    {PAUSE, 5},
    {A, 2},
    {PAUSE, 60},
    {A, 2},
    {PAUSE, 50},
    {A, 2},
    {PAUSE, 30},
    {UP, 2},
    {PAUSE, 5},
    {UP, 2},
    {PAUSE, 5},
    {A, 2},
    {PAUSE, 30},
    {UP, 2},
    {PAUSE, 5},
    {A, 2},
    {PAUSE, 60},
    {A, 2},
    {PAUSE, 50},
    {A, 2},
    {PAUSE, 30},
    {UP, 2},
    {PAUSE, 5},
    {UP, 2},
    {PAUSE, 5},
    {A, 2},
    {PAUSE, 30},
    {UP, 2},
    {PAUSE, 5},
    {A, 2},
    {PAUSE, 60},
    {A, 2},
    {PAUSE, 50},
    {B, 2},
    {PAUSE, 80},
    {B, 2},
    {PAUSE, 80},
    {B, 2},
    {PAUSE, 80},
    {SCRIPT_END, 0},
};

//������λ
static const command HatchReset[] PROGMEM = {
    {DOWNLEFT, 10},
    {PAUSE, 5},
    {LEFT, 200},
    {LEFT, 200},
    {LEFT, 150},
    {PAUSE, 5},
    {SCRIPT_END, 0},
};

//�����ƶ�
static const command HatchMove[] PROGMEM = {
    {DOWNLEFT, 2},
    {DOWNRIGHT, 2},
    {RIGHT, 200},
    {RIGHT, 200},
    {RIGHT, 100},
    {PAUSE, 5},
    {DOWNRIGHT, 2},
    {DOWNLEFT, 2},
    {LEFT, 200},
    {LEFT, 200},
    {LEFT, 100},
    {PAUSE, 5},
    {SCRIPT_END, 0},
};

//����6�������һ���ƶ�
static const command LastMove6[] PROGMEM = {
    {DOWNLEFT, 2},
    {DOWNRIGHT, 2},
    {RIGHT, 200},
    {RIGHT, 200},
    {RIGHT, 100},
    {PAUSE, 5},
    {DOWNRIGHT, 2},
    {DOWNLEFT, 2},
    {LEFT, 200},
    {LEFT, 200},
    {LEFT, 50},
    {PAUSE, 5},
    {SCRIPT_END, 0},
};

//����11�������һ���ƶ�
static const command LastMove11[] PROGMEM = {
    {DOWNLEFT, 2},
    {DOWNRIGHT, 2},
    {RIGHT, 200},
    {RIGHT, 200},
    {RIGHT, 50},
    {PAUSE, 5},
    {SCRIPT_END, 0},
};

//����16�������һ���ƶ�
static const command LastMove16[] PROGMEM = {
    {DOWNLEFT, 2},
    {DOWNRIGHT, 2},
    {RIGHT, 100},
    {PAUSE, 5},
    {SCRIPT_END, 0},
};

//����21�������һ���ƶ�
static const command LastMove21[] PROGMEM = {
    {DOWNLEFT, 2},
    {DOWNRIGHT, 2},
    {RIGHT, 200},
    {RIGHT, 200},
    {RIGHT, 100},
    {PAUSE, 5},
    {DOWNRIGHT, 2},
    {DOWNLEFT, 2},
    {LEFT, 200},
    {LEFT, 100},
    {PAUSE, 5},
    {SCRIPT_END, 0},
};

//����26�������һ���ƶ�
static const command LastMove26[] PROGMEM = {
    {DOWNLEFT, 2},
    {DOWNRIGHT, 2},
    {RIGHT, 200},
    {RIGHT, 200},
    {RIGHT, 50},
    {PAUSE, 5},
    {SCRIPT_END, 0},
};

//����31�������һ���ƶ�
static const command LastMove31[] PROGMEM = {
    {DOWNLEFT, 2},
    {DOWNRIGHT, 2},
    {RIGHT, 150},
    {PAUSE, 5},
    {SCRIPT_END, 0},
};

//����36�������һ���ƶ�
static const command LastMove36[] PROGMEM = {
    {DOWNLEFT, 2},
    {DOWNRIGHT, 2},
    {RIGHT, 200},
    {RIGHT, 200},
    {RIGHT, 100},
    {PAUSE, 5},
    {DOWNRIGHT, 2},
    {DOWNLEFT, 2},
    {LEFT, 200},
    {LEFT, 100},
    {PAUSE, 5},
    {SCRIPT_END, 0},
};

//����41�������һ���ƶ�
static const command LastMove41[] PROGMEM = {
    {DOWNLEFT, 2},
    {DOWNRIGHT, 2},
    {RIGHT, 200},
    {RIGHT, 200},
    {RIGHT, 150},
    {PAUSE, 5},
    {SCRIPT_END, 0},
};

//��������
static const command Hatched[] PROGMEM = {
    {DOWNRIGHT, 50},
    {PAUSE, 5},
    {B, 2},
    {PAUSE, 200},
    {PAUSE, 200},
    {PAUSE, 200},
    {PAUSE, 130},
    {B, 2},
    {PAUSE, 150},
    {SCRIPT_END, 0},
};

//���Ӳ���1
static const command BoxOperation1[] PROGMEM = {
    {X, 2},
    {PAUSE, 50},
    {A, 2},
    {PAUSE, 80},
    {R, 2},
    {PAUSE, 100},
    {Y, 2},
    {PAUSE, 5},
    {Y, 2},
    {PAUSE, 5},
    {A, 2},
    {PAUSE, 5},
    {UP, 2},
    {PAUSE, 5},
    {A, 2},
    {PAUSE, 10},
    {LEFT, 2},
    {PAUSE, 5},
    {DOWN, 2},
    {PAUSE, 5},
    {A, 2},
    {PAUSE, 10},
    {B, 2},
    {PAUSE, 80},
    {B, 2},
    {PAUSE, 80},
    {B, 2},
    {PAUSE, 80},
    {SCRIPT_END, 0},
};

//���Ӳ���2
static const command BoxOperation2[] PROGMEM = {
    {X, 2},
    {PAUSE, 50},
    {A, 2},
    {PAUSE, 80},
    {R, 2},
    {PAUSE, 100},
    {LEFT, 2},
    {PAUSE, 5},
    {DOWN, 2},
    {PAUSE, 5},
    {Y, 2},
    {PAUSE, 5},
    {Y, 2},
    {PAUSE, 5},
    {A, 2},
    {PAUSE, 5},
    {UP, 2},
    {PAUSE, 5},
    {UP, 2},
    {PAUSE, 5},
    {A, 2},
    {PAUSE, 10},
    {RIGHT, 2},
    {PAUSE, 5},
    {UP, 2},
    {PAUSE, 5},
    {A, 2},
    {PAUSE, 10},
    {RIGHT, 2},
    {PAUSE, 5},
    {A, 2},
    {PAUSE, 5},
    {UP, 2},
    {PAUSE, 5},
    {A, 2},
    {PAUSE, 10},
    {LEFT, 2},
    {PAUSE, 5},
    {LEFT, 2},
    {PAUSE, 5},
    {DOWN, 2},
    {PAUSE, 5},
    {A, 2},
    {PAUSE, 10},
    {B, 2},
    {PAUSE, 80},
    {B, 2},
    {PAUSE, 80},
    {B, 2},
    {PAUSE, 80},
    {SCRIPT_END, 0},
};

//���Ӳ���3
static const command BoxOperation3[] PROGMEM = {
    {X, 2},
    {PAUSE, 50},
    {A, 2},
    {PAUSE, 80},
    {R, 2},
    {PAUSE, 100},
    {LEFT, 2},
    {PAUSE, 5},
    {DOWN, 2},
    {PAUSE, 5},
    {Y, 2},
    {PAUSE, 5},
    {Y, 2},
    {PAUSE, 5},
    {A, 2},
    {PAUSE, 5},
    {UP, 2},
    {PAUSE, 5},
    {UP, 2},
    {PAUSE, 5},
    {A, 2},
    {PAUSE, 10},
    {RIGHT, 2},
    {PAUSE, 5},
    {RIGHT, 2},
    {PAUSE, 5},
    {UP, 2},
    {PAUSE, 5},
    {A, 2},
    {PAUSE, 10},
    {RIGHT, 2},
    {PAUSE, 5},
    {A, 2},
    {PAUSE, 5},
    {UP, 2},
    {PAUSE, 5},
    {A, 2},
    {PAUSE, 10},
    {LEFT, 2},
    {PAUSE, 5},
    {LEFT, 2},
    {PAUSE, 5},
    {LEFT, 2},
    {PAUSE, 5},
    {DOWN, 2},
    {PAUSE, 5},
    {A, 2},
    {PAUSE, 10},
    {B, 2},
    {PAUSE, 80},
    {B, 2},
    {PAUSE, 80},
    {B, 2},
    {PAUSE, 80},
    {SCRIPT_END, 0},
};

//���Ӳ���4
static const command BoxOperation4[] PROGMEM = {
    {X, 2},
    {PAUSE, 50},
    {A, 2},
    {PAUSE, 80},
    {R, 2},
    {PAUSE, 100},
    {LEFT, 2},
    {PAUSE, 5},
    {DOWN, 2},
    {PAUSE, 5},
    {Y, 2},
    {PAUSE, 5},
    {Y, 2},
    {PAUSE, 5},
    {A, 2},
    {PAUSE, 5},
    {UP, 2},
    {PAUSE, 5},
    {UP, 2},
    {PAUSE, 5},
    {A, 2},
    {PAUSE, 10},
    {RIGHT, 2},
    {PAUSE, 5},
    {RIGHT, 2},
    {PAUSE, 5},
    {RIGHT, 2},
    {PAUSE, 5},
    {UP, 2},
    {PAUSE, 5},
    {A, 2},
    {PAUSE, 10},
    {RIGHT, 2},
    {PAUSE, 5},
    {A, 2},
    {PAUSE, 5},
    {UP, 2},
    {PAUSE, 5},
    {A, 2},
    {PAUSE, 10},
    {RIGHT, 2},
    {PAUSE, 5},
    {RIGHT, 2},
    {PAUSE, 5},
    {RIGHT, 2},
    {PAUSE, 5},
    {DOWN, 2},
    {PAUSE, 5},
    {A, 2},
    {PAUSE, 10},
    {B, 2},
    {PAUSE, 80},
    {B, 2},
    {PAUSE, 80},
    {B, 2},
    {PAUSE, 80},
    {SCRIPT_END, 0},
};

//���Ӳ���5
static const command BoxOperation5[] PROGMEM = {
    {X, 2},
    {PAUSE, 50},
    {A, 2},
    {PAUSE, 80},
    {R, 2},
    {PAUSE, 100},
    {LEFT, 2},
    {PAUSE, 5},
    {DOWN, 2},
    {PAUSE, 5},
    {Y, 2},
    {PAUSE, 5},
    {Y, 2},
    {PAUSE, 5},
    {A, 2},
    {PAUSE, 5},
    {UP, 2},
    {PAUSE, 5},
    {UP, 2},
    {PAUSE, 5},
    {A, 2},
    {PAUSE, 10},
    {LEFT, 2},
    {PAUSE, 5},
    {LEFT, 2},
    {PAUSE, 5},
    {LEFT, 2},
    {PAUSE, 5},
    {UP, 2},
    {PAUSE, 5},
    {A, 2},
    {PAUSE, 10},
    {RIGHT, 2},
    {PAUSE, 5},
    {A, 2},
    {PAUSE, 5},
    {UP, 2},
    {PAUSE, 5},
    {A, 2},
    {PAUSE, 10},
    {RIGHT, 2},
    {PAUSE, 5},
    {RIGHT, 2},
    {PAUSE, 5},
    {DOWN, 2},
    {PAUSE, 5},
    {A, 2},
    {PAUSE, 10},
    {B, 2},
    {PAUSE, 80},
    {B, 2},
    {PAUSE, 80},
    {B, 2},
    {PAUSE, 80},
    {SCRIPT_END, 0},
};

//���Ӳ���6
static const command BoxOperation6[] PROGMEM = {
    {X, 2},
    {PAUSE, 50},
    {A, 2},
    {PAUSE, 80},
    {R, 2},
    {PAUSE, 100},
    {LEFT, 2},
    {PAUSE, 5},
    {DOWN, 2},
    {PAUSE, 5},
    {Y, 2},
    {PAUSE, 5},
    {Y, 2},
    {PAUSE, 5},
    {A, 2},
    {PAUSE, 5},
    {UP, 2},
    {PAUSE, 5},
    {UP, 2},
    {PAUSE, 5},
    {A, 2},
    {PAUSE, 10},
    {LEFT, 2},
    {PAUSE, 5},
    {LEFT, 2},
    {PAUSE, 5},
    {UP, 2},
    {PAUSE, 5},
    {A, 2},
    {PAUSE, 10},
    {RIGHT, 2},
    {PAUSE, 5},
    {A, 2},
    {PAUSE, 5},
    {UP, 2},
    {PAUSE, 5},
    {A, 2},
    {PAUSE, 10},
    {RIGHT, 2},
    {PAUSE, 5},
    {DOWN, 2},
    {PAUSE, 5},
    {A, 2},
    {PAUSE, 10},
    {B, 2},
    {PAUSE, 80},
    {B, 2},
    {PAUSE, 80},
    {B, 2},
    {PAUSE, 80},
    {SCRIPT_END, 0},
};

//���Ӳ���7
static const command BoxOperation7[] PROGMEM = {
    {X, 2},
    {PAUSE, 50},
    {A, 2},
    {PAUSE, 80},
    {R, 2},
    {PAUSE, 100},
    {LEFT, 2},
    {PAUSE, 5},
    {DOWN, 2},
    {PAUSE, 5},
    {Y, 2},
    {PAUSE, 5},
    {Y, 2},
    {PAUSE, 5},
    {A, 2},
    {PAUSE, 5},
    {UP, 2},
    {PAUSE, 5},
    {UP, 2},
    {PAUSE, 5},
    {A, 2},
    {PAUSE, 10},
    {LEFT, 2},
    {PAUSE, 5},
    {UP, 2},
    {PAUSE, 5},
    {A, 2},
    {PAUSE, 10},
    {R, 2},
    {PAUSE, 30},
    {B, 2},
    {PAUSE, 80},
    {B, 2},
    {PAUSE, 80},
    {B, 2},
    {PAUSE, 80},
    {SCRIPT_END, 0},
};

//�����������ƶ�
static const command ReleaseDown[] PROGMEM = {
    {A, 2},
    {PAUSE, 30},
    {UP, 2},
    {PAUSE, 5},
    {UP, 2},
    {PAUSE, 5},
    {A, 2},
    {PAUSE, 30},
    {UP, 2},
    {PAUSE, 5},
    {A, 2},
    {PAUSE, 60},
    {A, 2},
    {PAUSE, 20},
    {DOWN, 2},
    {PAUSE, 5},
    {SCRIPT_END, 0},
};

//�����������ƶ�
static const command ReleaseUP[] PROGMEM = {
    {A, 2},
    {PAUSE, 30},
    {UP, 2},
    {PAUSE, 5},
    {UP, 2},
    {PAUSE, 5},
    {A, 2},
    {PAUSE, 30},
    {UP, 2},
    {PAUSE, 5},
    {A, 2},
    {PAUSE, 60},
    {A, 2},
    {PAUSE, 20},
    {UP, 2},
    {PAUSE, 5},
    {SCRIPT_END, 0},
};

//�����������ƶ�
static const command ReleaseRight[] PROGMEM = {
   {A, 2},
    {PAUSE, 30},
    {UP, 2},
    {PAUSE, 5},
    {UP, 2},
    {PAUSE, 5},
    {A, 2},
    {PAUSE, 30},
    {UP, 2},
    {PAUSE, 5},
    {A, 2},
    {PAUSE, 60},
    {A, 2},
    {PAUSE, 20},
    {RIGHT, 2},
    {PAUSE, 5},
    {SCRIPT_END, 0},
};

//�������л���һ��
static const command ReleaseReset[] PROGMEM = {
    {A, 2},
    {PAUSE, 30},
    {UP, 2},
    {PAUSE, 5},
    {UP, 2},
    {PAUSE, 5},
    {A, 2},
    {PAUSE, 30},
    {UP, 2},
    {PAUSE, 5},
    {A, 2},
    {PAUSE, 60},
    {A, 2},
    {PAUSE, 20},
    {LEFT, 2},
    {PAUSE, 5},
    {LEFT, 2},
    {PAUSE, 5},
    {LEFT, 2},
    {PAUSE, 5},
    {LEFT, 2},
    {PAUSE, 5},
    {LEFT, 2},
    {PAUSE, 5},
    {R, 2},
    {PAUSE, 30},
    {SCRIPT_END, 0},
};

//ת������
static const command GotoSettings[] PROGMEM = {
    {HOME, 2},
    {PAUSE, 50},
    {DOWN, 2},
    {PAUSE, 5},
    {RIGHT, 2},
    {PAUSE, 5},
    {RIGHT, 2},
    {PAUSE, 5},
    {RIGHT, 2},
    {PAUSE, 5},
    {RIGHT, 2},
    {PAUSE, 5},
    {A, 2},
    {PAUSE, 30},
    {DOWN, 60},
    {PAUSE, 5},
    {RIGHT, 2},
    {PAUSE, 5},
    {DOWN, 2},
    {PAUSE, 5},
    {DOWN, 2},
    {PAUSE, 5},
    {DOWN, 2},
    {PAUSE, 5},
    {DOWN, 2},
    {PAUSE, 5},
    {A, 2},
    {PAUSE, 10},
    {DOWN, 2},
    {PAUSE, 5},
    {DOWN, 2},
    {PAUSE, 5},
    {A, 2},
    {PAUSE, 5},
    {RIGHT, 2},
    {PAUSE, 5},
    {RIGHT, 2},
    {PAUSE, 5},
    {RIGHT, 2},
    {PAUSE, 5},
    {RIGHT, 2},
    {PAUSE, 5},
    {RIGHT, 2},
    {PAUSE, 5},
    {A, 2},
    {PAUSE, 10},
    {SCRIPT_END, 0},
};

//����һ֡
static const command SkipBack[] PROGMEM = {
    {A, 2},
    {PAUSE, 5},
    {LEFT, 2},
    {PAUSE, 1},
    {LEFT, 2},
    {PAUSE, 1},
    {LEFT, 2},
    {PAUSE, 1},
    {DOWN, 2},
    {PAUSE, 1},
    {RIGHT, 2},
    {PAUSE, 1},
    {RIGHT, 2},
    {PAUSE, 1},
    {RIGHT, 2},
    {PAUSE, 1},
    {A, 2},
    {PAUSE, 5},
    {SCRIPT_END, 0},
};

//��֡
static const command Skip[] PROGMEM = {
    {A, 2},
    {PAUSE, 5},
    {LEFT, 2},
    {PAUSE, 1},
    {LEFT, 2},
    {PAUSE, 1},
    {LEFT, 2},
    {PAUSE, 1},
    {UP, 2},
    {PAUSE, 1},
    {RIGHT, 2},
    {PAUSE, 1},
    {RIGHT, 2},
    {PAUSE, 1},
    {RIGHT, 2},
    {PAUSE, 1},
    {A, 2},
    {PAUSE, 5},
    {SCRIPT_END, 0},
};

//�ص���Ϸ
static const command GotoGame[] PROGMEM = {
    {HOME, 2},
    {PAUSE, 50},
    {A, 2},
    {PAUSE, 80},
    {SCRIPT_END, 0},
};

//������Ϸ
static const command RestartGame[] PROGMEM = {
    {HOME, 2},
    {PAUSE, 50},
    {X, 2},
    {PAUSE, 30},
    {A, 2},
    {PAUSE, 150},
    {A, 2},
    {PAUSE, 80},
    {A, 2},
    {PAUSE, 200},
    {PAUSE, 200},
    {PAUSE, 200},
    {PAUSE, 100},
    {A, 2},
    {PAUSE, 200},
    {PAUSE, 200},
    {SCRIPT_END, 0},
};

//����ļ����
static const command Recruit[] PROGMEM = {
    {A, 2},
    {PAUSE, 50},
    {A, 2},
    {PAUSE, 120},
    {SCRIPT_END, 0},
};

//�ڶ�����ļ
static const command NextRecruit[] PROGMEM = {
    {B, 2},
    {PAUSE, 30},
    {A, 2},
    {PAUSE, 200},
    {A, 2},
    {PAUSE, 30},
    {B, 2},
    {PAUSE, 30},
    {B, 2},
    {PAUSE, 50},
    {A, 2},
    {PAUSE, 120},
    {SCRIPT_END, 0},
};

//�˳���ļ����
static const command ExitRecruit[] PROGMEM = {
    {B, 2},
    {PAUSE, 30},
    {A, 2},
    {PAUSE, 200},
    {SCRIPT_END, 0},
};

//����
static const command Connect[] PROGMEM = {
    {Y, 2},
    {PAUSE, 50},
    {PLUS, 2},
    {PAUSE, 200},
    {PAUSE, 200},
    {PAUSE, 200},
    {PAUSE, 200},
    {PAUSE, 200},
    {B, 2},
    {PAUSE, 30},
    {B, 2},
    {PAUSE, 50},
    {SCRIPT_END, 0},
};

//����׼��
static const command ReadyToDrive[] PROGMEM = {
    {A, 2},
    {PAUSE, 200},
    {PAUSE, 100},
    {PLUS, 2},
    {PAUSE, 60},
    {RIGHT, 2},
    {PAUSE, 5},
    {DOWN, 2},
    {PAUSE, 5},
    {SCRIPT_END, 0},
};

//����0
static const command Password0[] PROGMEM = {
    {DOWN, 2},
    {PAUSE, 5},
    {DOWN, 2},
    {PAUSE, 5},
    {A, 2},
    {PAUSE, 5},
    {UP, 2},
    {PAUSE, 5},
    {UP, 2},
    {PAUSE, 5},
    {SCRIPT_END, 0},
};

//����1
static const command Password1[] PROGMEM = {
    {LEFT, 2},
    {PAUSE, 5},
    {UP, 2},
    {PAUSE, 5},
    {A, 2},
    {PAUSE, 5},
    {DOWN, 2},
    {PAUSE, 5},
    {RIGHT, 2},
    {PAUSE, 5},
    {SCRIPT_END, 0},
};

//����2
static const command Password2[] PROGMEM = {
    {UP, 2},
    {PAUSE, 5},
    {A, 2},
    {PAUSE, 5},
    {DOWN, 2},
    {PAUSE, 5},
    {SCRIPT_END, 0},
};

//����3
static const command Password3[] PROGMEM = {
    {RIGHT, 2},
    {PAUSE, 5},
    {UP, 2},
    {PAUSE, 5},
    {A, 2},
    {PAUSE, 5},
    {DOWN, 2},
    {PAUSE, 5},
    {LEFT, 2},
    {PAUSE, 5},
    {SCRIPT_END, 0},
};

//����4
static const command Password4[] PROGMEM = {
    {LEFT, 2},
    {PAUSE, 5},
    {A, 2},
    {PAUSE, 5},
    {RIGHT, 2},
    {PAUSE, 5},
    {SCRIPT_END, 0},
};

//����5
static const command Password5[] PROGMEM = {
    {A, 2},
    {PAUSE, 5},
    {SCRIPT_END, 0},
};

//����6
static const command Password6[] PROGMEM = {
    {RIGHT, 2},
    {PAUSE, 5},
    {A, 2},
    {PAUSE, 5},
    {LEFT, 2},
    {PAUSE, 5},
    {SCRIPT_END, 0},
};

//����7
static const command Password7[] PROGMEM = {
    {LEFT, 2},
    {PAUSE, 5},
    {DOWN, 2},
    {PAUSE, 5},
    {A, 2},
    {PAUSE, 5},
    {UP, 2},
    {PAUSE, 5},
    {RIGHT, 2},
    {PAUSE, 5},
    {SCRIPT_END, 0},
};

//����8
static const command Password8[] PROGMEM = {
    {DOWN, 2},
    {PAUSE, 5},
    {A, 2},
    {PAUSE, 5},
    {UP, 2},
    {PAUSE, 5},
    {SCRIPT_END, 0},
};

//����9
static const command Password9[] PROGMEM = {
    {RIGHT, 2},
    {PAUSE, 5},
    {DOWN, 2},
    {PAUSE, 5},
    {A, 2},
    {PAUSE, 5},
    {UP, 2},
    {PAUSE, 5},
    {LEFT, 2},
    {PAUSE, 5},
    {SCRIPT_END, 0},
};

//�ȴ����
static const command DriveWait[] PROGMEM = {
    {PLUS, 2},
    {PAUSE, 60},
    {A, 2},
    {PAUSE, 30},
    {A, 2},
    {PAUSE, 200},
    {SCRIPT_END, 0},
};

//����
static const command StartDrive[] PROGMEM = {
    {UP, 2},
    {PAUSE, 5},
    {A, 2},
    {PAUSE, 200},
    {A, 2},
    {PAUSE, 30},
    {A, 2},
    {PAUSE, 30},
    {A, 2},
    {PAUSE, 30},
    {A, 2},
    {PAUSE, 30},
    {A, 2},
    {PAUSE, 30},
    {A, 2},
    {PAUSE, 30},
    {A, 2},
    {PAUSE, 30},
    {A, 2},
    {PAUSE, 30},
    {A, 2},
    {PAUSE, 30},
    {A, 2},
    {PAUSE, 30},
    {A, 2},
    {PAUSE, 200},
    {PAUSE, 200},
    {SCRIPT_END, 0},
};

//��ȡ����
static const command GetWatt[] PROGMEM = {
    {A, 2},
    {PAUSE, 30},
    {B, 2},
    {PAUSE, 30},
    {B, 2},
    {PAUSE, 50},
    {B, 2},
    {PAUSE, 60},
    {SCRIPT_END, 0},
};

//���ɰ��æˢ��
static const command RefreshJob[] PROGMEM = {
    {A, 2},
    {PAUSE, 30},
    {A, 2},
    {PAUSE, 30},
    {DOWN, 2},
    {PAUSE, 5},
    {DOWN, 2},
    {PAUSE, 5},
    {A, 2},
    {PAUSE, 120},
    {B, 2},
    {PAUSE, 60},
    {B, 2},
    {PAUSE, 30},
    {SCRIPT_END, 0},
};

//��������
static const command StartJob[] PROGMEM = {
    {A, 2},
    {PAUSE, 30},
    {A, 2},
    {PAUSE, 30},
    {DOWN, 2},
    {PAUSE, 5},
    {DOWN, 2},
    {PAUSE, 5},
    {A, 2},
    {PAUSE, 120},
    {A, 2},
    {PAUSE, 50},
    {A, 2},
    {PAUSE, 30},
    {A, 2},
    {PAUSE, 80},
    {X, 2},
    {PAUSE, 30},
    {B, 2},
    {PAUSE, 80},
    {A, 2},
    {PAUSE, 30},
    {A, 2},
    {PAUSE, 200},
    {PAUSE, 200},
    {B, 2},
    {PAUSE, 30},
    {B, 2},
    {PAUSE, 30},
    {B, 2},
    {PAUSE, 50},
    {B, 2},
    {PAUSE, 30},
    {SCRIPT_END, 0},
};

//��������
static const command EndJob[] PROGMEM = {
    {A, 2},
    {PAUSE, 30},
    {A, 2},
    {PAUSE, 30},
    {DOWN, 2},
    {PAUSE, 5},
    {DOWN, 2},
    {PAUSE, 5},
    {A, 2},
    {PAUSE, 120},
    {A, 2},
    {PAUSE, 30},
    {A, 2},
    {PAUSE, 200},
    {PAUSE, 200},
    {PAUSE, 100},
    {B, 2},
    {PAUSE, 30},
    {B, 2},
    {PAUSE, 30},
    {B, 2},
    {PAUSE, 30},
    {B, 2},
    {PAUSE, 30},
    {B, 2},
    {PAUSE, 30},
    {B, 2},
    {PAUSE, 30},
    {B, 2},
    {PAUSE, 30},
    {B, 2},
    {PAUSE, 30},
    {B, 2},
    {PAUSE, 30},
    {B, 2},
    {PAUSE, 30},
    {B, 2},
    {PAUSE, 30},
    {B, 2},
    {PAUSE, 30},
    {B, 2},
    {PAUSE, 30},
    {B, 2},
    {PAUSE, 30},
    {B, 2},
    {PAUSE, 30},
    {SCRIPT_END, 0},
};

//������ս��
static const command Battle[] PROGMEM = {
    {A, 2},
    {PAUSE, 50},
    {B, 2},
    {PAUSE, 50},
    {B, 2},
    {PAUSE, 50},
    {A, 2},
    {PAUSE, 50},
    {DOWN, 2},
    {PAUSE, 30},
    {B, 2},
    {PAUSE, 50},
    {B, 2},
    {PAUSE, 150},
    {B, 2},
    {PAUSE, 200},
    {PAUSE, 200},
    {PAUSE, 200},
    {PAUSE, 200},
    {UP, 50},
    {PAUSE, 30},
    {A, 2},
    {PAUSE, 50},
    {UP, 50},
    {PAUSE, 30},
    {A, 2},
    {PAUSE, 50},
    {UP, 50},
    {PAUSE, 30},
    {A, 2},
    {PAUSE, 50},
    {UP, 50},
    {PAUSE, 30},
    {A, 2},
    {PAUSE, 50},
    {UP, 50},
    {PAUSE, 30},
    {A, 2},
    {PAUSE, 50},
    {UP, 50},
    {PAUSE, 30},
    {A, 2},
    {PAUSE, 200},
    {PAUSE, 200},
    {PAUSE, 100},
    {B, 2},
    {PAUSE, 200},
    {PAUSE, 200},
    {PAUSE, 100},
    {B, 2},
    {PAUSE, 200},
    {B, 2},
    {PAUSE, 50},
    {B, 2},
    {PAUSE, 200},
    {B, 2},
    {PAUSE, 50},
    {B, 2},
    {PAUSE, 200},
    {B, 2},
    {PAUSE, 50},
    {B, 2},
    {PAUSE, 50},
    {B, 2},
    {PAUSE, 50},
    {B, 2},
    {PAUSE, 50},
    {B, 2},
    {PAUSE, 50},
    {B, 2},
    {PAUSE, 50},
    {B, 2},
    {PAUSE, 50},
    {B, 2},
    {PAUSE, 50},
    {SCRIPT_END, 0},
};

//����������
static const command GotoCenter[] PROGMEM = {
    {DOWN, 80},
    {PAUSE, 120},
    {X, 2},
    {PAUSE, 50},
    {A, 2},
    {PAUSE, 120},
    {A, 2},
    {PAUSE, 50},
    {A, 2},
    {PAUSE, 200},
    {UP, 50},
    {PAUSE, 120},
    {UP, 80},
    {PAUSE, 30},
    {A, 2},
    {PAUSE, 30},
    {A, 2},
    {PAUSE, 30},
    {A, 2},
    {PAUSE, 30},
    {A, 2},
    {PAUSE, 200},
    {PAUSE, 200},
    {A, 2},
    {PAUSE, 60},
    {A, 2},
    {PAUSE, 30},
    {DOWN, 80},
    {PAUSE, 120},
    {SCRIPT_END, 0},
};

//�ص�����
static const command GoBack[] PROGMEM = {
    {RIGHT, 30},
    {PAUSE, 30},
    {UP, 135},
    {PAUSE, 30},
    {LEFT, 60},
    {PAUSE, 10},
    {UP, 10},
    {PAUSE, 10},
    {LEFT, 10},
    {PAUSE, 120},
    {UP, 80},
    {PAUSE, 50},
    {SCRIPT_END, 0},
};

//�ȴ�5��
static const command PAUSE5[] PROGMEM = {
    {PAUSE, 200},
    {SCRIPT_END, 0},
};

//ͬ��
static const command Sync[] PROGMEM = {
    {LCLICK, 2},
    {PAUSE, 10},
    {SCRIPT_END, 0},
};

/////////////////////////������/////////////////////////

//RunScript(ģ����,ִ�д���)
//RunStep(��������,����ʱ��) ����ʱ��40Լ����һ��
//LOOP_START(X) LOOP_END ֮��Ĵ���ѭ��X�κ���� X=0Ϊ����ѭ��
//PROGRAM_END ����������Զ�ֹͣ �����д ��������ظ�ִ����ȥ

void PgmStart()
{
    Stopping = 0;
    RunScript(Sync, 3);
    switch (ScriptNum)
    {
    case 1:
        CollectAndHatch();
        break;
    case 2:
        Collecting();
        break;
    case 3:
        Hatching();
        break;
    case 4:
        Releasing();
        break;
    case 5:
        Skipping();
        break;
    case 6:
        SkipLastFrame();
        break;
    case 7:
        Driving();
        break;
    case 8:
        SkipAndDrive();
        break;
    case 9:
        InfUsed();
        break;
    default:
        break;
    }
}

//ȡ��������
void CollectAndHatch()
{
    switch (CycleNum)
    {
    case 6:
        SizeofPgm = SizeofCollect * BoxNum * 43 + SizeofHatch6 * BoxNum + GetDuration(CollectToHatch);
        break;
    case 11:
        SizeofPgm = SizeofCollect * BoxNum * 43 + SizeofHatch11 * BoxNum + GetDuration(CollectToHatch);
        break;
    case 16:
        SizeofPgm = SizeofCollect * BoxNum * 43 + SizeofHatch16 * BoxNum + GetDuration(CollectToHatch);
        break;
    case 21:
        SizeofPgm = SizeofCollect * BoxNum * 43 + SizeofHatch21 * BoxNum + GetDuration(CollectToHatch);
        break;
    case 26:
        SizeofPgm = SizeofCollect * BoxNum * 43 + SizeofHatch26 * BoxNum + GetDuration(CollectToHatch);
        break;
    case 31:
        SizeofPgm = SizeofCollect * BoxNum * 43 + SizeofHatch31 * BoxNum + GetDuration(CollectToHatch);
        break;
    case 36:
        SizeofPgm = SizeofCollect * BoxNum * 43 + SizeofHatch36 * BoxNum + GetDuration(CollectToHatch);
        break;
    case 41:
        SizeofPgm = SizeofCollect * BoxNum * 43 + SizeofHatch41 * BoxNum + GetDuration(CollectToHatch);
        break;
    default:
        break;
    }
    //ȡ�� �ɹ���Լ70%
    LOOP_START((BoxNum * 43))
    RunScript(CollectMove, 3);
    RunScript(GetEgg, 1);
    LOOP_END
    //���ɲ���
    RunScript(CollectToHatch, 1);
    //����
    LOOP_START(BoxNum)
    HatchOperation();
    LOOP_END
    PROGRAM_END
}

/*
//ȡ��������(420������&41����)
void CollectAndHatch41()
{
LOOP_START(600)
  Collecting();
LOOP_END
RunScript(CollectToHatch,1);
RunScript(ReleaseDown,5);
RunStep(B,2);
RunStep(PAUSE,80);
RunStep(B,2);
RunStep(PAUSE,80);
RunStep(B,2);
RunStep(PAUSE,80);
LOOP_START(14)
  Hatching41();
LOOP_END
PROGRAM_END
}
*/

//ȡ��
void Collecting()
{
    SizeofPgm = SizeofCollect * BoxNum * 43;
    LOOP_START((BoxNum * 43))
    RunScript(CollectMove, 3);
    RunScript(GetEgg, 1);
    LOOP_END
    PROGRAM_END
}

//����
void Hatching()
{
    switch (CycleNum)
    {
    case 6:
        SizeofPgm = SizeofHatch6 * BoxNum;
        break;
    case 11:
        SizeofPgm = SizeofHatch11 * BoxNum;
        break;
    case 16:
        SizeofPgm = SizeofHatch16 * BoxNum;
        break;
    case 21:
        SizeofPgm = SizeofHatch21 * BoxNum;
        break;
    case 26:
        SizeofPgm = SizeofHatch26 * BoxNum;
        break;
    case 31:
        SizeofPgm = SizeofHatch31 * BoxNum;
        break;
    case 36:
        SizeofPgm = SizeofHatch36 * BoxNum;
        break;
    case 41:
        SizeofPgm = SizeofHatch41 * BoxNum;
        break;
    default:
        break;
    }
    LOOP_START(BoxNum)
    HatchOperation();
    LOOP_END
    PROGRAM_END
}

//��������
void HatchOperation()
{
    char num = 2;
    RunScript(BoxOperation1, 1);
    LOOP_START(6)
    switch (CycleNum)
    {
    case 6:
        RunScript(LastMove6, 1);
        break;
    case 11:
        RunScript(HatchMove, 1);
        RunScript(LastMove11, 1);
        break;
    case 16:
        RunScript(HatchMove, 2);
        RunScript(LastMove16, 1);
        break;
    case 21:
        RunScript(HatchMove, 2);
        RunScript(LastMove21, 1);
        break;
    case 26:
        RunScript(HatchMove, 3);
        RunScript(LastMove26, 1);
        break;
    case 31:
        RunScript(HatchMove, 4);
        RunScript(LastMove31, 1);
        break;
    case 36:
        RunScript(HatchMove, 4);
        RunScript(LastMove36, 1);
        break;
    case 41:
        RunScript(HatchMove, 5);
        RunScript(LastMove41, 1);
        break;
    default:
        break;
    }
    RunScript(Hatched, 5);
    RunScript(HatchReset, 1);
    switch (num)
    {
    case 2:
        RunScript(BoxOperation2, 1);
        break;
    case 3:
        RunScript(BoxOperation3, 1);
        break;
    case 4:
        RunScript(BoxOperation4, 1);
        break;
    case 5:
        RunScript(BoxOperation5, 1);
        break;
    case 6:
        RunScript(BoxOperation6, 1);
        break;
    case 7:
        RunScript(BoxOperation7, 1);
    default:
        break;
    }
    num++;
    LOOP_END
}

//����
void Releasing()
{
    SizeofPgm = SizeofRelease * BoxNum;
    LOOP_START(BoxNum)
    RunScript(ReleaseDown, 4);
    RunScript(ReleaseRight, 1);
    RunScript(ReleaseUP, 4);
    RunScript(ReleaseRight, 1);
    RunScript(ReleaseDown, 4);
    RunScript(ReleaseRight, 1);
    RunScript(ReleaseUP, 4);
    RunScript(ReleaseRight, 1);
    RunScript(ReleaseDown, 4);
    RunScript(ReleaseRight, 1);
    RunScript(ReleaseUP, 4);
    RunScript(ReleaseReset, 1);
    LOOP_END
    PROGRAM_END
}

//��֡
void Skipping()
{
    SizeofPgm = SizeofSkip * (FrameNum + FrameNum / 30) + GetDuration(GotoSettings) + GetDuration(GotoGame);
    RunScript(GotoSettings, 1);
    LOOP_START((FrameNum + FrameNum / 30))
    RunScript(Skip, 1);
    LOOP_END
    RunScript(GotoGame, 1);
    PROGRAM_END
}

//�����N֡
void SkipLastFrame()
{
    LOOP_START(0)
    LOOP_START((30 / LastFrameNum))
    RunScript(Recruit, 1);
    RunScript(GotoSettings, 1);
    RunScript(Skip, 1);
    RunScript(GotoGame, 1);
    LOOP_START((LastFrameNum - 1))
    RunScript(NextRecruit, 1);
    RunScript(GotoSettings, 1);
    RunScript(Skip, 1);
    RunScript(GotoGame, 1);
    LOOP_END
    RunScript(NextRecruit, 1);
    RunScript(PAUSE5, SkipWaitNum / 5);
    RunScript(RestartGame, 1);
    LOOP_END
    RunScript(GotoSettings, 1);
    RunScript(Skip, 1);
    if (LastFrameNum == 4)
    {
        RunScript(Skip, 2);
    }
    RunScript(GotoGame, 1);
    LOOP_END
}

//�Զ���ʻ
void Driving()
{
    LOOP_START(0)
    int num = 1000;
    RunScript(Connect, 1);
    RunScript(ReadyToDrive, 1);
    LOOP_START(4)
    switch ((PasswordNum / num) % 10)
    {
    case 0:
        RunScript(Password0, 1);
        break;
    case 1:
        RunScript(Password1, 1);
        break;
    case 2:
        RunScript(Password2, 1);
        break;
    case 3:
        RunScript(Password3, 1);
        break;
    case 4:
        RunScript(Password4, 1);
        break;
    case 5:
        RunScript(Password5, 1);
        break;
    case 6:
        RunScript(Password6, 1);
        break;
    case 7:
        RunScript(Password7, 1);
        break;
    case 8:
        RunScript(Password8, 1);
        break;
    case 9:
        RunScript(Password9, 1);
        break;
    default:
        break;
    }
    num /= 10;
    LOOP_END
    RunScript(DriveWait, 1);
    RunScript(PAUSE5, DriveWaitNum / 5);
    RunScript(StartDrive, 1);
    RunScript(RestartGame, 1);
    LOOP_END
}

//����֡����
void SkipAndDrive()
{
    LOOP_START(0)
    int num = 1000;
    RunScript(Recruit, 1);
    RunScript(GotoSettings, 1);
    RunScript(Skip, 1);
    RunScript(GotoGame, 1);
    LOOP_START((LastFrameNum - 1))
    RunScript(NextRecruit, 1);
    RunScript(GotoSettings, 1);
    RunScript(Skip, 1);
    RunScript(GotoGame, 1);
    LOOP_END
    RunScript(ExitRecruit, 1);
    RunScript(GotoSettings, 1);
    RunScript(SkipBack, LastFrameNum);
    RunScript(GotoGame, 1);
    RunScript(GetWatt, 1);
    RunScript(Connect, 1);
    RunScript(ReadyToDrive, 1);
    LOOP_START(4)
    switch ((PasswordNum / num) % 10)
    {
    case 0:
        RunScript(Password0, 1);
        break;
    case 1:
        RunScript(Password1, 1);
        break;
    case 2:
        RunScript(Password2, 1);
        break;
    case 3:
        RunScript(Password3, 1);
        break;
    case 4:
        RunScript(Password4, 1);
        break;
    case 5:
        RunScript(Password5, 1);
        break;
    case 6:
        RunScript(Password6, 1);
        break;
    case 7:
        RunScript(Password7, 1);
        break;
    case 8:
        RunScript(Password8, 1);
        break;
    case 9:
        RunScript(Password9, 1);
        break;
    default:
        break;
    }
    num /= 10;
    LOOP_END
    RunScript(DriveWait, 1);
    RunScript(PAUSE5, DriveWaitNum / 5);
    RunScript(StartDrive, 1);
    RunScript(RestartGame, 1);
    LOOP_END
}

//�����ù���
void InfUsed()
{
    switch (InfUsedNum)
    {
    case 1: //��A
        PressA();
        break;
    case 2: //ˢ����
        CollectWatt();
        break;
    case 3: //ˢ����
        CollectBerry();
        break;
    case 4: //ˢͷ��
        HeadwearBattle();
        break;
    case 5: //���ɰ��æ
        PokeJob();
        break;
    case 6: //����ķ�齱
        LuckDraw();
        break;
    default:
        break;
    }
}

//��A
void PressA()
{
    LOOP_START(0)
    RunStep(A, 2);
    RunStep(PAUSE, 5);
    LOOP_END
}

//ˢ����
void CollectWatt()
{
    LOOP_START(0)
    RunScript(GetWatt, 1);
    RunScript(GotoSettings, 1);
    RunScript(Skip, 1);
    RunScript(GotoGame, 1);
    LOOP_END
}

//ˢ����
void CollectBerry()
{
    LOOP_START(0)
    RunStep(A, 2);
    RunStep(PAUSE, 50);
    RunStep(A, 2);
    RunStep(PAUSE, 50);
    RunStep(A, 2);
    RunStep(PAUSE, 200);
    RunStep(B, 2);
    RunStep(PAUSE, 50);
    RunStep(B, 2);
    RunStep(PAUSE, 50);
    RunStep(B, 2);
    RunStep(PAUSE, 50);
    RunStep(B, 2);
    RunStep(PAUSE, 50);
    RunStep(B, 2);
    RunStep(PAUSE, 50);
    RunStep(B, 2);
    RunStep(PAUSE, 50);
    RunStep(B, 2);
    RunStep(PAUSE, 50);
    RunStep(B, 2);
    RunStep(PAUSE, 50);
    RunStep(B, 2);
    RunStep(PAUSE, 50);
    RunScript(GotoSettings, 1);
    RunScript(Skip, 1);
    RunScript(GotoGame, 1);
    LOOP_END
}

//ˢͷ��()
void HeadwearBattle()
{
    LOOP_START(0)
    LOOP_START(3)
    LOOP_START(10)
    RunScript(Battle, 1);
    RunScript(GotoSettings, 1);
    RunScript(Skip, 1);
    RunScript(GotoGame, 1);
    LOOP_END
    RunScript(GotoCenter, 1);
    RunScript(GoBack, 1);
    LOOP_END
    RunScript(GotoSettings, 1);
    RunScript(Skip, 1);
    RunScript(GotoGame, 1);
    LOOP_END
}

//���ɰ��æ
void PokeJob()
{
    RunScript(RefreshJob, 1);
    LOOP_START(0)
    LOOP_START(15)
    RunScript(StartJob, 1);
    RunScript(GotoSettings, 1);
    RunScript(Skip, 2);
    RunScript(GotoGame, 1);
    RunScript(EndJob, 1);
    LOOP_END
    RunScript(GotoSettings, 1);
    RunScript(Skip, 1);
    RunScript(GotoGame, 1);
    LOOP_END
}

//����ķ�齱
void LuckDraw()
{
    LOOP_START(0)
    RunStep(A, 2);
    RunStep(PAUSE, 30);
    RunStep(A, 2);
    RunStep(PAUSE, 30);
    RunStep(DOWN, 2);
    RunStep(PAUSE, 5);
    RunStep(A, 2);
    RunStep(PAUSE, 30);
    RunStep(A, 2);
    RunStep(PAUSE, 30);
    RunStep(A, 2);
    RunStep(PAUSE, 30);
    RunStep(A, 2);
    RunStep(PAUSE, 30);
    RunStep(A, 2);
    RunStep(PAUSE, 30);
    RunStep(A, 2);
    RunStep(PAUSE, 30);
    RunStep(B, 2);
    RunStep(PAUSE, 30);
    RunStep(B, 2);
    RunStep(PAUSE, 30);
    RunStep(B, 2);
    RunStep(PAUSE, 30);
    RunStep(B, 2);
    RunStep(PAUSE, 30);
    RunStep(B, 2);
    RunStep(PAUSE, 30);
    RunStep(B, 2);
    RunStep(PAUSE, 80);
    RunStep(B, 2);
    RunStep(PAUSE, 30);
    RunStep(B, 2);
    RunStep(PAUSE, 30);
    RunStep(B, 2);
    RunStep(PAUSE, 30);
    RunStep(B, 2);
    RunStep(PAUSE, 30);
    RunStep(B, 2);
    RunStep(PAUSE, 30);
    RunStep(B, 2);
    RunStep(PAUSE, 100);
    RunStep(B, 2);
    RunStep(PAUSE, 30);
    RunStep(B, 2);
    RunStep(PAUSE, 30);
    RunStep(B, 2);
    RunStep(PAUSE, 30);
    RunScript(GotoSettings, 1);
    RunScript(Skip, 1);
    RunScript(GotoGame, 1);
    LOOP_END
}
