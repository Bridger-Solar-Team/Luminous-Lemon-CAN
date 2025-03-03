//The last number in the CAN ID is 12 for the dash baord,
  //25 for the battery box board, 11 for the data logging board,
  //and 30 for the BMS
#define DASH_CANID 12
#define BATTERYBOX_CANID 25
#define LOGGER_CANID 14
#define BMS_CANID 30
#define REAR_CANID 18

#define PIN1 5
#define PIN2 18
#define PIN3 19
#define PIN4 23
#define PIN5 13
#define PIN6 33
#define PIN7 14
#define PIN8 32
#define PIN9 34
#define PIN10 35
#define PIN11 36
#define PIN12 39

#define SCL 22
#define SDA 21

#define CTX 16
#define CRX 17

#define PWR1 26
#define PWR2 4
#define PWR3 25
#define PWR4 27
#define PWR5 15

#define DCL_WARNING_SETPOINT 20
#define CCL_WARNING_SETPOINT 30

bool powerOn;
bool leftTurn;
bool rightTurn;
bool horn;
bool fwdRev;
bool dispToggle;
bool hazzards;
bool cruiseControl;
bool brakePressed;
float throttle;

float batteryVoltageLV;
float workingVoltageLV;

bool sdFailure;

float soc;
int dcl;
int ccl;
int currentDraw;
bool overCurrent;
bool overCharge;
bool overDischarge;
bool bmsFailure;
bool overTemp;

String old_line0;
String old_line1;
String line0;
String line1;
bool cruiseActive;
float cruiseSpeed;
bool blink = false;
unsigned long blinkTimer = 0; //Used for flashing lights
int blinkFrequency = 2;
int pinsCanSpacing = 100; //Time between CAN frames in milliseconds
unsigned long pinsCanTime = 0; //Used for timing CAN messages
int canArray = 0;
float tLow = 0.35;
float tHigh = 0.10;
int speed;