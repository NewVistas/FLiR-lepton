//Last modified on 11th december of 2015

//initialize the libraries used for the communications
#include <Wire.h>
#include <SPI.h>

byte x = 0;
#define ADDRESS  (0x2A)

//define the comands to control the communication i2c (used for confguring the module)
#define AGC (0x01)
#define SYS (0x02)
#define VID (0x03)
#define OEM (0x08)
#define RAD (0x0E)

#define GET (0x00)
#define SET (0x01)
#define RUN (0x02)

//define de size of a VoSPI packet, 2bytes for ID, 2bytes for CRC and 160bytes for the frame
#define VOSPI_FRAME_SIZE (164)
byte lepton_frame_packet[VOSPI_FRAME_SIZE];

//defining variables related with the image
int image_index;
#define image_x (80)
#define image_y (60)
word image[image_x][image_y];

//Initialize the variables used in this sketch
int i,j;
float AUXtemperature;
String matlabAction;
word minval = 99999;
boolean captureImage = false;
bool runonce = 0;
bool donecapturing = 0;

//Initialize the variable used for comparing the user entry
String SETUP = "setupConfi";
String BEGIN = "beginTrans";
String END = "endTransmi";
String CAPTURE = "captureIma";
String TRANSFER = "transferIm";
String OK = "<OK>";


void setup(){
  //initialize i2c communication
  Wire.begin();

  //initialize Serial communication
  Serial.begin(115200);

  //configure spi communication
  pinMode(10, OUTPUT);
  SPI.setDataMode(SPI_MODE3);
  SPI.setClockDivider(5);

  //initialize SPI communication
  SPI.begin();

  //set the time out of the serial input
  Serial.setTimeout(90000UL);

  Serial.println(SETUP);
}

void loop(){  
  if (runonce == 0) {
    Serial.println(BEGIN);
    int i;
    int reading = 0;
    String debugString;

    runonce = 1;
    delay(200);
  }
    
  //assign the user input into a variable
  matlabAction = Serial.readStringUntil('\n');

  //depend on the user input do a ceratin action
  if(matlabAction == CAPTURE){
    lepton_sync();
    delay(50);
    Serial.println(OK);
    while(donecapturing == false){
      read_lepton_frame();
      buffer_image();
    }
    Serial.println(OK);
    find_min();
  }else if(matlabAction == TRANSFER){
    Serial.println(OK);
    for(i=0;i<79;i++){
      for(j=0;j<59;j++){
        Serial.println((int)image[i][j]-minval, DEC);
      }
    }
    Serial.println(OK);
  }else{
    
  }
  Serial.flush();
  donecapturing = false;
}

