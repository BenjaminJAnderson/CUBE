#include <Adafruit_GFX.h>
#include <Adafruit_SSD1351.h>
#include <SPI.h>

// You can use any (4 or) 5 pins                                               s2
#define SCLK_PIN 36   //18 White noise with this setup on larger oled 14       36    
#define MOSI_PIN 35   //23                                            13        35
#define DC_PIN   5   //17                                            17        5
#define RST_PIN  4

#define CS_PIN1  6
#define CS_PIN2  12
#define CS_PIN3  14
#define CS_PIN4  18
#define CS_PIN5  17
#define CS_PIN6  11

// Color definitions
#define BLACK           0x0000
#define BLUE            0x001F
#define RED             0xF800
#define GREEN           0x07E0
#define CYAN            0x07FF
#define MAGENTA         0xF81F
#define YELLOW          0xFFE0  
#define WHITE           0xFFFF

Adafruit_SSD1351 OLED1 = Adafruit_SSD1351(128, 128, &SPI, CS_PIN1, DC_PIN, -1);
Adafruit_SSD1351 OLED2 = Adafruit_SSD1351(128, 128, &SPI, CS_PIN2, DC_PIN, -1);
Adafruit_SSD1351 OLED3 = Adafruit_SSD1351(128, 128, &SPI, CS_PIN3, DC_PIN, -1);
Adafruit_SSD1351 OLED4 = Adafruit_SSD1351(128, 128, &SPI, CS_PIN4, DC_PIN, -1);
Adafruit_SSD1351 OLED5 = Adafruit_SSD1351(128, 128, &SPI, CS_PIN5, DC_PIN, -1);
Adafruit_SSD1351 OLED6 = Adafruit_SSD1351(128, 128, &SPI, CS_PIN6, DC_PIN, -1);

//PIN HAS TO BE ON THE LAST .BEGIN FUNCTION CALLED, otherwise it doesnt start up
void setup(void)
{
  Serial.begin(9600);
  OLED1.begin();
 // OLED2.begin();
  //OLED3.begin();
  //OLED4.begin();
  //OLED5.begin();
  //OLED6.begin();
  
  OLED1.setCursor(64,64);
  //OLED2.setCursor(64,64);
  //OLED3.setCursor(64,64);
  //OLED4.setCursor(64,64);
  //OLED5.setCursor(64,64);
  //OLED6.setCursor(64,64);
}

void loop()
{
  
  OLED1.fillScreen(WHITE);
  //OLED2.fillScreen(RED);
  //OLED3.fillScreen(BLUE);
  //OLED4.fillScreen(GREEN);
  //OLED5.fillScreen(MAGENTA);
  //OLED6.fillScreen(YELLOW);
  
//  OLED1.print("OLED1");
//  OLED2.print("OLED2");
//  OLED3.print("OLED3");
//  OLED4.print("OLED4");
//  OLED5.print("OLED5");
//  OLED6.print("OLED6");
}
