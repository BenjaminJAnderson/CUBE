#include <Adafruit_GFX.h>
#include <Adafruit_SSD1351.h>
#include <SPI.h>
#include "MPU9250.h"

// You can use any (4 or) 5 pins 
#define SCLK_PIN 14   //18 White noise with this setup on larger oled 14
#define MOSI_PIN 13   //23                                            13
#define DC_PIN   15   //17                                            17
#define RST_PIN  4

// Color definitions
#define BLACK           0x0000
#define BLUE            0x001F
#define RED             0xF800
#define GREEN           0x07E0
#define CYAN            0x07FF
#define MAGENTA         0xF81F
#define YELLOW          0xFFE0  
#define WHITE           0xFFFF

Adafruit_SSD1351 OLED = Adafruit_SSD1351(128, 128, &SPI, 5, DC_PIN, RST_PIN);
Adafruit_SSD1351 OLED2 = Adafruit_SSD1351(128, 128, &SPI, 17, DC_PIN, RST_PIN);
Adafruit_SSD1351 OLED3 = Adafruit_SSD1351(128, 128, &SPI, 18, DC_PIN, RST_PIN);
Adafruit_SSD1351 OLED4 = Adafruit_SSD1351(128, 128, &SPI, 19, DC_PIN, RST_PIN);
Adafruit_SSD1351 OLED5 = Adafruit_SSD1351(128, 128, &SPI, 21, DC_PIN, RST_PIN);
Adafruit_SSD1351 OLED6 = Adafruit_SSD1351(128, 128, &SPI, 34, DC_PIN, RST_PIN);
MPU9250 IMU(SPI,19);
int status;

void setup() {
  // serial to display data
  Serial.begin(115200);
  OLED.begin();
  OLED2.begin();
  OLED3.begin();
  OLED4.begin();
  OLED5.begin();
  OLED6.begin();
  while(!Serial) {}

  // start communication with IMU 
  status = IMU.begin();
  if (status < 0) {
    Serial.println("IMU initialization unsuccessful");
    Serial.println("Check IMU wiring or try cycling power");
    Serial.print("Status: ");
    Serial.println(status);
    while(1) {}
  }
}

void loop() {
  IMU.readSensor();
  OLED.fillScreen(GREEN);
  OLED2.fillScreen(RED);
  OLED3.fillScreen(BLUE);
  OLED4.fillScreen(MAGENTA);
  OLED5.fillScreen(WHITE);
  OLED6.fillScreen(YELLOW);
  Serial.print(IMU.getAccelX_mss(),6);
  Serial.print("\t");
  Serial.print(IMU.getAccelY_mss(),6);
  Serial.print("\t");
  Serial.print(IMU.getAccelZ_mss(),6);
  Serial.print("\t");
  Serial.print(IMU.getGyroX_rads(),6);
  Serial.print("\t");
  Serial.print(IMU.getGyroY_rads(),6);
  Serial.print("\t");
  Serial.print(IMU.getGyroZ_rads(),6);
  Serial.print("\t");
  Serial.print(IMU.getMagX_uT(),6);
  Serial.print("\t");
  Serial.print(IMU.getMagY_uT(),6);
  Serial.print("\t");
  Serial.print(IMU.getMagZ_uT(),6);
  Serial.print("\t");
  Serial.println(IMU.getTemperature_C(),6);
}
