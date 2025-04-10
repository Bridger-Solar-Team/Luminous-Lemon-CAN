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

#define MISO 19
#define MOSI 23
#define SCK 18
#define CS 5

#define SCL 22
#define SDA 21

#define CTX 16
#define CRX 17

#define PWR1 26
#define PWR2 4
#define PWR3 25
#define PWR4 27
#define PWR5 15

bool powerOn = false;
bool leftTurn = false;
bool rightTurn = false;
bool horn = false;
bool fwdRev = false;
bool dispToggle = false;
bool hazzards = false;
bool cruiseControl = false;
bool brakePressed = false;
float throttle = 0;

float batteryVoltageLV = 0;
float workingVoltageLV = 0;

bool sdFailure = false;

float soc = 0.5;
int dcl = 50;
int ccl = 40;
float currentDraw = 0;
bool overCurrent = false;
bool overCharge = false;
bool overDischarge = false;
bool bmsFailure = false;
bool overTemp = false;

int canArray = 0;