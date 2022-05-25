// Screen dimensions
#define SCREEN_WIDTH  128
#define SCREEN_HEIGHT 128 // Change this to 96 for 1.27" OLED.

// You can use any (4 or) 5 pins 
#define SCLK_PIN 36
#define MOSI_PIN 35
#define DC_PIN   5
#define RST_PIN  -1

#define CS_PIN1  6
#define CS_PIN2  12
#define CS_PIN3  14
#define CS_PIN4  18
#define CS_PIN5  17
#define CS_PIN6  11

// Color definitions
#define	BLACK           0x0000
#define	BLUE            0x001F
#define	RED             0xF800
#define	GREEN           0x07E0
#define CYAN            0x07FF
#define MAGENTA         0xF81F
#define YELLOW          0xFFE0  
#define WHITE           0xFFFF

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1351.h>
#include <SPI.h>

// Option 1: use any pins but a little slower
Adafruit_SSD1351 OLED1 = Adafruit_SSD1351(SCREEN_WIDTH, SCREEN_HEIGHT, CS_PIN1, DC_PIN, MOSI_PIN, SCLK_PIN, RST_PIN);  
Adafruit_SSD1351 OLED2 = Adafruit_SSD1351(SCREEN_WIDTH, SCREEN_HEIGHT, CS_PIN2, DC_PIN, MOSI_PIN, SCLK_PIN, RST_PIN);  
Adafruit_SSD1351 OLED3 = Adafruit_SSD1351(SCREEN_WIDTH, SCREEN_HEIGHT, CS_PIN3, DC_PIN, MOSI_PIN, SCLK_PIN, RST_PIN);  
Adafruit_SSD1351 OLED4 = Adafruit_SSD1351(SCREEN_WIDTH, SCREEN_HEIGHT, CS_PIN4, DC_PIN, MOSI_PIN, SCLK_PIN, RST_PIN);  
Adafruit_SSD1351 OLED5 = Adafruit_SSD1351(SCREEN_WIDTH, SCREEN_HEIGHT, CS_PIN5, DC_PIN, MOSI_PIN, SCLK_PIN, RST_PIN);  
Adafruit_SSD1351 OLED6 = Adafruit_SSD1351(SCREEN_WIDTH, SCREEN_HEIGHT, CS_PIN6, DC_PIN, MOSI_PIN, SCLK_PIN, RST_PIN); 

// Option 2: must use the hardware SPI pins 
//Adafruit_SSD1351 OLED1 = Adafruit_SSD1351(SCREEN_WIDTH, SCREEN_HEIGHT, &SPI, CS_PIN1, DC_PIN, RST_PIN);
//Adafruit_SSD1351 OLED2 = Adafruit_SSD1351(SCREEN_WIDTH, SCREEN_HEIGHT, &SPI, CS_PIN2, DC_PIN, RST_PIN);
//Adafruit_SSD1351 OLED3 = Adafruit_SSD1351(SCREEN_WIDTH, SCREEN_HEIGHT, &SPI, CS_PIN3, DC_PIN, RST_PIN);
//Adafruit_SSD1351 OLED4 = Adafruit_SSD1351(SCREEN_WIDTH, SCREEN_HEIGHT, &SPI, CS_PIN4, DC_PIN, RST_PIN);
//Adafruit_SSD1351 OLED5 = Adafruit_SSD1351(SCREEN_WIDTH, SCREEN_HEIGHT, &SPI, CS_PIN5, DC_PIN, RST_PIN);
//Adafruit_SSD1351 OLED6 = Adafruit_SSD1351(SCREEN_WIDTH, SCREEN_HEIGHT, &SPI, CS_PIN6, DC_PIN, RST_PIN);


float p = 3.1415926;

void setup(void) {
  Serial.begin(9600);
  Serial.print("hello!");
  OLED2.begin();

  uint16_t time = millis();
  OLED2.fillRect(0, 0, 128, 128, BLACK);
  time = millis() - time;
  
  Serial.println(time, DEC);
  delay(500);
  
  lcdTestPattern(OLED2);
  delay(500);
  
  OLED2.invert(true);
  delay(100);
  OLED2.invert(false);
  delay(100);

  OLED2.fillScreen(BLACK);
  testdrawtext(OLED2,"Lorem ipsum dolor sit amet, consectetur adipiscing elit. Curabitur adipiscing ante sed nibh tincidunt feugiat. Maecenas enim massa, fringilla sed malesuada et, malesuada sit amet turpis. Sed porttitor neque ut ante pretium vitae malesuada nunc bibendum. Nullam aliquet ultrices massa eu hendrerit. Ut sed nisi lorem. In vestibulum purus a tortor imperdiet posuere. ", WHITE);
  delay(500);

  // tft print function!
  tftPrintTest(OLED2);
  delay(500);
  
  //a single pixel
  OLED2.drawPixel(OLED2.width()/2, OLED2.height()/2, GREEN);
  delay(500);

  // line draw test
  testlines(OLED2,YELLOW);
  delay(500);    
 
  // optimized lines
  testfastlines(OLED2,RED, BLUE);
  delay(500);    


  testdrawrects(OLED2,GREEN);
  delay(1000);

  testfillrects(OLED2,YELLOW, MAGENTA);
  delay(1000);

  OLED2.fillScreen(BLACK);
  testfillcircles(OLED2,10, BLUE);
  testdrawcircles(OLED2,10, WHITE);
  delay(1000);
   
  testroundrects(OLED2);
  delay(500);
  
  testtriangles(OLED2);
  delay(500);
  
  Serial.println("done");
  delay(1000);
}

void loop() {
}

void testlines(Adafruit_SSD1351 Screen, uint16_t color) {
   Screen.fillScreen(BLACK);
   for (uint16_t x=0; x < Screen.width()-1; x+=6) {
     Screen.drawLine(0, 0, x, Screen.height()-1, color);
   }
   for (uint16_t y=0; y < Screen.height()-1; y+=6) {
     Screen.drawLine(0, 0, Screen.width()-1, y, color);
   }
   
   Screen.fillScreen(BLACK);
   for (uint16_t x=0; x < Screen.width()-1; x+=6) {
     Screen.drawLine(Screen.width()-1, 0, x, Screen.height()-1, color);
   }
   for (uint16_t y=0; y < Screen.height()-1; y+=6) {
     Screen.drawLine(Screen.width()-1, 0, 0, y, color);
   }
   
   Screen.fillScreen(BLACK);
   for (uint16_t x=0; x < Screen.width()-1; x+=6) {
     Screen.drawLine(0, Screen.height()-1, x, 0, color);
   }
   for (uint16_t y=0; y < Screen.height()-1; y+=6) {
     Screen.drawLine(0, Screen.height()-1, Screen.width()-1, y, color);
   }

   Screen.fillScreen(BLACK);
   for (uint16_t x=0; x < Screen.width()-1; x+=6) {
     Screen.drawLine(Screen.width()-1, Screen.height()-1, x, 0, color);
   }
   for (uint16_t y=0; y < Screen.height()-1; y+=6) {
     Screen.drawLine(Screen.width()-1, Screen.height()-1, 0, y, color);
   }
   
}

void testdrawtext(Adafruit_SSD1351 Screen, char *text, uint16_t color) {
  Screen.setCursor(0,0);
  Screen.setTextColor(color);
  Screen.print(text);
}

void testfastlines(Adafruit_SSD1351 Screen, uint16_t color1, uint16_t color2) {
   Screen.fillScreen(BLACK);
   for (uint16_t y=0; y < Screen.height()-1; y+=5) {
     Screen.drawFastHLine(0, y, Screen.width()-1, color1);
   }
   for (uint16_t x=0; x < Screen.width()-1; x+=5) {
     Screen.drawFastVLine(x, 0, Screen.height()-1, color2);
   }
}

void testdrawrects(Adafruit_SSD1351 Screen, uint16_t color) {
 Screen.fillScreen(BLACK);
 for (uint16_t x=0; x < Screen.height()-1; x+=6) {
   Screen.drawRect((Screen.width()-1)/2 -x/2, (Screen.height()-1)/2 -x/2 , x, x, color);
 }
}

void testfillrects(Adafruit_SSD1351 Screen, uint16_t color1, uint16_t color2) {
 Screen.fillScreen(BLACK);
 for (uint16_t x=Screen.height()-1; x > 6; x-=6) {
   Screen.fillRect((Screen.width()-1)/2 -x/2, (Screen.height()-1)/2 -x/2 , x, x, color1);
   Screen.drawRect((Screen.width()-1)/2 -x/2, (Screen.height()-1)/2 -x/2 , x, x, color2);
 }
}

void testfillcircles(Adafruit_SSD1351 Screen, uint8_t radius, uint16_t color) {
  for (uint8_t x=radius; x < Screen.width()-1; x+=radius*2) {
    for (uint8_t y=radius; y < Screen.height()-1; y+=radius*2) {
      Screen.fillCircle(x, y, radius, color);
    }
  }  
}

void testdrawcircles(Adafruit_SSD1351 Screen, uint8_t radius, uint16_t color) {
  for (uint8_t x=0; x < Screen.width()-1+radius; x+=radius*2) {
    for (uint8_t y=0; y < Screen.height()-1+radius; y+=radius*2) {
      Screen.drawCircle(x, y, radius, color);
    }
  }  
}

void testtriangles(Adafruit_SSD1351 Screen) {
  Screen.fillScreen(BLACK);
  int color = 0xF800;
  int t;
  int w = Screen.width()/2;
  int x = Screen.height();
  int y = 0;
  int z = Screen.width();
  for(t = 0 ; t <= 15; t+=1) {
    Screen.drawTriangle(w, y, y, x, z, x, color);
    x-=4;
    y+=4;
    z-=4;
    color+=100;
  }
}

void testroundrects(Adafruit_SSD1351 Screen) {
  Screen.fillScreen(BLACK);
  int color = 100;
  
  int x = 0;
  int y = 0;
  int w = Screen.width();
  int h = Screen.height();
  for(int i = 0 ; i <= 24; i++) {
    Screen.drawRoundRect(x, y, w, h, 5, color);
    x+=2;
    y+=3;
    w-=4;
    h-=6;
    color+=1100;
    Serial.println(i);
  }
}

void tftPrintTest(Adafruit_SSD1351 Screen) {
  Screen.fillScreen(BLACK);
  Screen.setCursor(0, 5);
  Screen.setTextColor(RED);  
  Screen.setTextSize(1);
  Screen.println("Hello World!");
  Screen.setTextColor(YELLOW);
  Screen.setTextSize(2);
  Screen.println("Hello World!");
  Screen.setTextColor(BLUE);
  Screen.setTextSize(3);
  Screen.print(1234.567);
  delay(1500);
  Screen.setCursor(0, 5);
  Screen.fillScreen(BLACK);
  Screen.setTextColor(WHITE);
  Screen.setTextSize(0);
  Screen.println("Hello World!");
  Screen.setTextSize(1);
  Screen.setTextColor(GREEN);
  Screen.print(p, 6);
  Screen.println(" Want pi?");
  Screen.println(" ");
  Screen.print(8675309, HEX); // print 8,675,309 out in HEX!
  Screen.println(" Print HEX!");
  Screen.println(" ");
  Screen.setTextColor(WHITE);
  Screen.println("Sketch has been");
  Screen.println("running for: ");
  Screen.setTextColor(MAGENTA);
  Screen.print(millis() / 1000);
  Screen.setTextColor(WHITE);
  Screen.print(" seconds.");
}

void mediabuttons(Adafruit_SSD1351 Screen) {
 // play
  Screen.fillScreen(BLACK);
  Screen.fillRoundRect(25, 10, 78, 60, 8, WHITE);
  Screen.fillTriangle(42, 20, 42, 60, 90, 40, RED);
  delay(500);
  // pause
  Screen.fillRoundRect(25, 90, 78, 60, 8, WHITE);
  Screen.fillRoundRect(39, 98, 20, 45, 5, GREEN);
  Screen.fillRoundRect(69, 98, 20, 45, 5, GREEN);
  delay(500);
  // play color
  Screen.fillTriangle(42, 20, 42, 60, 90, 40, BLUE);
  delay(50);
  // pause color
  Screen.fillRoundRect(39, 98, 20, 45, 5, RED);
  Screen.fillRoundRect(69, 98, 20, 45, 5, RED);
  // play color
  Screen.fillTriangle(42, 20, 42, 60, 90, 40, GREEN);
}

/**************************************************************************/
/*! 
    @brief  Renders a simple test pattern on the screen
*/
/**************************************************************************/
void lcdTestPattern(Adafruit_SSD1351 Screen)
{
  static const uint16_t PROGMEM colors[] =
    { RED, YELLOW, GREEN, CYAN, BLUE, MAGENTA, BLACK, WHITE };

  for(uint8_t c=0; c<8; c++) {
    Screen.fillRect(0, Screen.height() * c / 8, Screen.width(), Screen.height() / 8,
      pgm_read_word(&colors[c]));
  }
}
