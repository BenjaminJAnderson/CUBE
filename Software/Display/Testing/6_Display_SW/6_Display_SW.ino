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
  OLED1.begin();
  OLED2.begin();
  OLED3.begin();
  OLED4.begin();

  uint16_t time = millis();
  OLED1.fillRect(0, 0, 128, 128, BLACK);
  OLED2.fillRect(0, 0, 128, 128, BLACK);
  OLED3.fillRect(0, 0, 128, 128, BLACK);
  OLED4.fillRect(0, 0, 128, 128, BLACK);
  OLED5.fillRect(0, 0, 128, 128, BLACK);
  OLED6.fillRect(0, 0, 128, 128, BLACK);
  time = millis() - time;
  
  Serial.println(time, DEC);
  delay(500);

  lcdTestPattern(OLED1);
  lcdTestPattern(OLED2);
  lcdTestPattern(OLED3);
  lcdTestPattern(OLED4);
  lcdTestPattern(OLED5);
  lcdTestPattern(OLED6);
  delay(500);
  
  OLED1.invert(true);
  OLED2.invert(true);
  OLED3.invert(true);
  OLED4.invert(true);
  OLED5.invert(true);
  OLED6.invert(true);
  delay(100);
  OLED1.invert(false);
  OLED2.invert(false);
  OLED3.invert(false);
  OLED4.invert(false);
  OLED5.invert(false);
  OLED6.invert(false);
  delay(100);

  OLED1.fillScreen(BLACK);
  OLED2.fillScreen(BLACK);
  OLED3.fillScreen(BLACK);
  OLED4.fillScreen(BLACK);
  OLED5.fillScreen(BLACK);
  OLED6.fillScreen(BLACK);
  testdrawtext(OLED1,"Lorem ipsum dolor sit amet, consectetur adipiscing elit. Curabitur adipiscing ante sed nibh tincidunt feugiat. Maecenas enim massa, fringilla sed malesuada et, malesuada sit amet turpis. Sed porttitor neque ut ante pretium vitae malesuada nunc bibendum. Nullam aliquet ultrices massa eu hendrerit. Ut sed nisi lorem. In vestibulum purus a tortor imperdiet posuere. ", WHITE);
  testdrawtext(OLED2,"Lorem ipsum dolor sit amet, consectetur adipiscing elit. Curabitur adipiscing ante sed nibh tincidunt feugiat. Maecenas enim massa, fringilla sed malesuada et, malesuada sit amet turpis. Sed porttitor neque ut ante pretium vitae malesuada nunc bibendum. Nullam aliquet ultrices massa eu hendrerit. Ut sed nisi lorem. In vestibulum purus a tortor imperdiet posuere. ", WHITE);
  testdrawtext(OLED3,"Lorem ipsum dolor sit amet, consectetur adipiscing elit. Curabitur adipiscing ante sed nibh tincidunt feugiat. Maecenas enim massa, fringilla sed malesuada et, malesuada sit amet turpis. Sed porttitor neque ut ante pretium vitae malesuada nunc bibendum. Nullam aliquet ultrices massa eu hendrerit. Ut sed nisi lorem. In vestibulum purus a tortor imperdiet posuere. ", WHITE);
  testdrawtext(OLED4,"Lorem ipsum dolor sit amet, consectetur adipiscing elit. Curabitur adipiscing ante sed nibh tincidunt feugiat. Maecenas enim massa, fringilla sed malesuada et, malesuada sit amet turpis. Sed porttitor neque ut ante pretium vitae malesuada nunc bibendum. Nullam aliquet ultrices massa eu hendrerit. Ut sed nisi lorem. In vestibulum purus a tortor imperdiet posuere. ", WHITE);
  testdrawtext(OLED5,"Lorem ipsum dolor sit amet, consectetur adipiscing elit. Curabitur adipiscing ante sed nibh tincidunt feugiat. Maecenas enim massa, fringilla sed malesuada et, malesuada sit amet turpis. Sed porttitor neque ut ante pretium vitae malesuada nunc bibendum. Nullam aliquet ultrices massa eu hendrerit. Ut sed nisi lorem. In vestibulum purus a tortor imperdiet posuere. ", WHITE);
  testdrawtext(OLED6,"Lorem ipsum dolor sit amet, consectetur adipiscing elit. Curabitur adipiscing ante sed nibh tincidunt feugiat. Maecenas enim massa, fringilla sed malesuada et, malesuada sit amet turpis. Sed porttitor neque ut ante pretium vitae malesuada nunc bibendum. Nullam aliquet ultrices massa eu hendrerit. Ut sed nisi lorem. In vestibulum purus a tortor imperdiet posuere. ", WHITE);
  delay(500);

  // tft print function!
  tftPrintTest(OLED1);
  tftPrintTest(OLED2);
  tftPrintTest(OLED3);
  tftPrintTest(OLED4);
  tftPrintTest(OLED5);
  tftPrintTest(OLED6);
  delay(500);
  
  //a single pixel
  OLED1.drawPixel(OLED1.width()/2, OLED1.height()/2, GREEN);
  OLED2.drawPixel(OLED2.width()/2, OLED2.height()/2, GREEN);
  OLED3.drawPixel(OLED3.width()/2, OLED3.height()/2, GREEN);
  OLED4.drawPixel(OLED4.width()/2, OLED4.height()/2, GREEN);
  OLED5.drawPixel(OLED5.width()/2, OLED5.height()/2, GREEN);
  OLED6.drawPixel(OLED6.width()/2, OLED6.height()/2, GREEN);
  delay(500);

  // line draw test
  testlines(OLED1,YELLOW);
  testlines(OLED2,YELLOW);
  testlines(OLED3,YELLOW);
  testlines(OLED4,YELLOW);
  testlines(OLED5,YELLOW);
  testlines(OLED6,YELLOW);
  delay(500);    
 
  // optimized lines
  testfastlines(OLED1,RED, BLUE);
  testfastlines(OLED2,RED, BLUE);
  testfastlines(OLED3,RED, BLUE);
  testfastlines(OLED4,RED, BLUE);
  testfastlines(OLED5,RED, BLUE);
  testfastlines(OLED6,RED, BLUE);
  delay(500);    

  testdrawrects(OLED1,GREEN);
  testdrawrects(OLED2,GREEN);
  testdrawrects(OLED3,GREEN);
  testdrawrects(OLED4,GREEN);
  testdrawrects(OLED5,GREEN);
  testdrawrects(OLED6,GREEN);
  delay(1000);

  testfillrects(OLED1,YELLOW, MAGENTA);
  testfillrects(OLED2,YELLOW, MAGENTA);
  testfillrects(OLED3,YELLOW, MAGENTA);
  testfillrects(OLED4,YELLOW, MAGENTA);
  testfillrects(OLED5,YELLOW, MAGENTA);
  testfillrects(OLED6,YELLOW, MAGENTA);
  delay(1000);

  OLED1.fillScreen(BLACK);
  OLED2.fillScreen(BLACK);
  OLED3.fillScreen(BLACK);
  OLED4.fillScreen(BLACK);
  OLED5.fillScreen(BLACK);
  OLED6.fillScreen(BLACK);
  testfillcircles(OLED1,10, BLUE);
  testfillcircles(OLED2,10, BLUE);
  testfillcircles(OLED3,10, BLUE);
  testfillcircles(OLED4,10, BLUE);
  testfillcircles(OLED5,10, BLUE);
  testfillcircles(OLED6,10, BLUE);
  testdrawcircles(OLED1,10, WHITE);
  testdrawcircles(OLED2,10, WHITE);
  testdrawcircles(OLED3,10, WHITE);
  testdrawcircles(OLED4,10, WHITE);
  testdrawcircles(OLED5,10, WHITE);
  testdrawcircles(OLED6,10, WHITE);
  delay(1000);

  testroundrects(OLED1);
  testroundrects(OLED2);
  testroundrects(OLED3);
  testroundrects(OLED4);
  testroundrects(OLED5);
  testroundrects(OLED6);
  delay(500);
  
  testtriangles(OLED1);
  testtriangles(OLED2);
  testtriangles(OLED3);
  testtriangles(OLED4);
  testtriangles(OLED5);
  testtriangles(OLED6);
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
