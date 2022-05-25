//#include "I2Cdev.h"
#include "MPU6050_6Axis_MotionApps20.h"
#include "Wire.h"

//Gyro         SDA  SCL INT (DONT FORGET VCC & GND)
//Arduino Uno  A4   A5  2

MPU6050 MPU;

bool dmpReady = false;
uint8_t MPUIntStatus;
uint8_t devStatus;
uint16_t packetSize;
uint16_t fifoCount;
uint8_t fifoBuffer[64];

Quaternion q;
VectorInt16 aa;
VectorInt16 aaReal;
VectorInt16 aaWorld;
VectorFloat gravity;
float euler[3];
float ypr[3];

volatile bool MPUInterrupt = false;

void dmpDataReady() 
{
    MPUInterrupt = true;
}

void setup() 
{
    Wire.begin();
    TWBR = 12;
    Serial.begin(115200);
    while (!Serial);

    Serial.println(F("Initializing I2C devices..."));
    MPU.initialize();

    Serial.println(F("Testing device connections..."));
    Serial.println(MPU.testConnection() ? F("MPU6050 connection successful") : F("MPU6050 connection failed"));

    Serial.println(F("\nSend any character to begin DMP programming and demo: "));
    while (Serial.available() && Serial.read()); // empty buffer
    while (!Serial.available());                 // wait for data
    while (Serial.available() && Serial.read()); // empty buffer again

    Serial.println(F("Initializing DMP..."));
    devStatus = MPU.dmpInitialize();

    MPU.setXGyroOffset(220);
    MPU.setYGyroOffset(76);
    MPU.setZGyroOffset(-85);
    MPU.setZAccelOffset(1788);

    if (devStatus == 0) 
    {
        Serial.println(F("Enabling DMP..."));
        MPU.setDMPEnabled(true);

        Serial.println(F("Enabling interrupt detection (Arduino external interrupt 0)..."));
        attachInterrupt(0, dmpDataReady, RISING);
        MPUIntStatus = MPU.getIntStatus();

        Serial.println(F("DMP ready! Waiting for first interrupt..."));
        dmpReady = true;
        packetSize = MPU.dmpGetFIFOPacketSize();
    } 
    else 
    {
        Serial.print(F("DMP Initialization failed (code "));
        Serial.print(devStatus);
        Serial.println(F(")"));
    }
}

void loop() 
{
    if (!dmpReady) return;

    while (!MPUInterrupt && fifoCount < packetSize) 
    {
        // other program behavior stuff here
    }

    MPUInterrupt = false;
    MPUIntStatus = MPU.getIntStatus();

    fifoCount = MPU.getFIFOCount();

    if ((MPUIntStatus & 0x10) || fifoCount == 1024) 
    {
        MPU.resetFIFO();
        Serial.println(F("FIFO overflow!"));
    } 
    else if (MPUIntStatus & 0x02) 
    {
        while (fifoCount < packetSize) fifoCount = MPU.getFIFOCount();

        MPU.getFIFOBytes(fifoBuffer, packetSize);
        fifoCount -= packetSize;
        
        MPU.dmpGetQuaternion(&q, fifoBuffer);
        MPU.dmpGetGravity(&gravity, &q);
        MPU.dmpGetYawPitchRoll(ypr, &q, &gravity);
        Serial.print("Z Angle: ");
        Serial.print(ypr[0] * 180/M_PI);
        Serial.print("\tY Angle: ");
        Serial.print(ypr[1] * 180/M_PI);
        Serial.print("\tX Angle: ");
        Serial.println(ypr[2] * 180/M_PI);
        Serial.print("\n");
    }
    delay(100);
}
