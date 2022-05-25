#include <Adafruit_GFX.h>
#include <Adafruit_SSD1351.h>
#include <time.h>
#include <SPI.h>

#define SCLK_PIN 18
#define MOSI_PIN 23
#define DC_PIN   17
#define CS_PIN   5
#define RST_PIN  4

// Color definitions
#define  BLACK           0x0000
#define BLUE            0x001F
#define RED             0xF800
#define GREEN           0x07E0
#define CYAN            0x07FF
#define MAGENTA         0xF81F
#define YELLOW          0xFFE0  
#define WHITE           0xFFFF



Adafruit_SSD1351 OLED = Adafruit_SSD1351(128, 128, &SPI, CS_PIN, DC_PIN, RST_PIN);

typedef struct 
{
  int PosX, PosY;
  int VelX, VelY;
  int OldX, OldY;
  int AccX, AccY;
  int Radius;
}Balls;

typedef struct
{
  int StartPosX, StartPosY;
  int EndPosX, EndPosY;
}Walls;

Balls Ball[10];
Walls Wall[4];

bool DoCirclesOverlap(int R1, int X1, int Y1, int R2, int X2, int Y2)
{
  return fabs((X1-X2)*(X1-X2) + (Y1-Y2)*(Y1-Y2)) <= (R1+R2)*(R1+R2);
}

int Collision()
{
  for(int i = 0; i < 10; i++)
  {
    if(Ball[i].PosX < 10 + Ball[i].Radius)
    {
      Ball[i].VelX = -(Ball[i].VelX);
    }
    else if(Ball[i].PosY < 10 + Ball[i].Radius)
    {
      Ball[i].VelY = -(Ball[i].VelY);
    }
    else if(Ball[i].PosX > 120 - Ball[i].Radius)
    {
      Ball[i].VelX = -(Ball[i].VelX);
    }
    else if(Ball[i].PosY > 120 - Ball[i].Radius)
    {
      Ball[i].VelY = -(Ball[i].VelY);
    }
  }

  for(int i = 0; i < 10; i++)
  {
    for(int j = 0; j < 10; j++)
    {
      if(i != j)
      {
        if(DoCirclesOverlap(Ball[i].Radius, Ball[i].PosX, Ball[i].PosY, Ball[j].Radius, Ball[j].PosX, Ball[j].PosY))
        {
          int Distance = sqrt((Ball[i].PosX - Ball[j].PosX)*(Ball[i].PosX - Ball[j].PosX) + (Ball[i].PosY - Ball[j].PosY)*(Ball[i].PosY - Ball[j].PosY));
          int Overlap = (Distance - Ball[i].Radius - Ball[j].Radius)/2;

          // HAVE CODE TO DETECT COLLISIONS WITH CLASS (OBJECTS), THIS WILL THEN SEND IT TO THE RIGHT COLLISION FUNCTION BASED ON THE CLASS IT IS TOUCHING 
          /*int NormX = (Ball[i].PosX - Ball[j].PosX) / Distance;
          int NormY = (Ball[i].PosY - Ball[j].PosY) / Distance;

          int TangX = -NormY;
          int TangY = NormX;

          DPTan1 = Ball[i].VelX * TangX + Ball[i].VelY * TangY;
          DPTan2 = Ball[j].VelX * TangX + Ball[j].VelY * TangY;

          Ball[i].VelX = TangX * DPTan1;
          Ball[i].VelY = TangY * DPTan1;
          Ball[j].VelX = TangX * DPTan2;
          Ball[j].VelY = TangY * DPTan2;
          
          Ball[i].PosX -= Overlap * (Ball[i].PosX - Ball[j].PosX) / Distance;
          Ball[i].PosY -= Overlap * (Ball[i].PosY - Ball[j].PosY) / Distance;
          
          Ball[j].PosX += Overlap * (Ball[i].PosX - Ball[j].PosX) / Distance;
          Ball[j].PosY += Overlap * (Ball[i].PosY - Ball[j].PosY) / Distance; 
          */         
        }
      }
    }
  }
}

int Motion()
{
  for(int i = 0; i < 10; i++)
  {
    Ball[i].OldX = Ball[i].PosX;
    Ball[i].OldY = Ball[i].PosY;
    Ball[i].PosX += Ball[i].VelX;
    Ball[i].PosY += Ball[i].VelY;
  }
  Collision();
}

int Initialise(int X)
{
  for(int i = 0; i < X; i++)
  {
    Ball[i].Radius = rand() %10 + 1;
    Ball[i].PosX = rand() %(128 - Ball[i].Radius) + Ball[i].Radius;
    Ball[i].PosY = rand() %(128 - Ball[i].Radius) + Ball[i].Radius;
    Ball[i].VelX = rand() % 3 + 1;
    Ball[i].VelY = rand() % 3 + 1;
  }
  Wall[0].StartPosX = 0, Wall[0].StartPosY = 0, Wall[0].EndPosX = 0, Wall[0].EndPosY = 127;
  Wall[1].StartPosX = 0, Wall[1].StartPosY = 0, Wall[1].EndPosX = 127, Wall[1].EndPosY = 0;
  Wall[2].StartPosX = 127, Wall[2].StartPosY = 127, Wall[2].EndPosX = 127, Wall[2].EndPosY = 0;
  Wall[3].StartPosX = 127, Wall[3].StartPosY = 127, Wall[3].EndPosX = 0, Wall[3].EndPosY = 127;
}

void setup(void)
{
  srand(time(0));
  Serial.begin(9600);
  OLED.begin();
  OLED.fillRect(0, 0, 128, 128, BLACK);
  Initialise(10);
  TestPattern();
  delay(5000);
  OLED.fillScreen(BLACK);
  OLED.drawLine(Wall[0].StartPosX, Wall[0].StartPosY, Wall[0].EndPosX, Wall[0].EndPosY, WHITE);
  OLED.drawLine(Wall[1].StartPosX, Wall[1].StartPosY, Wall[1].EndPosX, Wall[1].EndPosY, WHITE);
  OLED.drawLine(Wall[2].StartPosX, Wall[2].StartPosY, Wall[2].EndPosX, Wall[2].EndPosY, WHITE);
  OLED.drawLine(Wall[3].StartPosX, Wall[3].StartPosY, Wall[3].EndPosX, Wall[3].EndPosY, WHITE);
}

void loop()
{
  Motion();
  for(int i = 0; i < 10; i++)
  {
    OLED.fillCircle(Ball[i].OldX, Ball[i].OldY, Ball[i].Radius, BLACK);
    OLED.fillCircle(Ball[i].PosX, Ball[i].PosY, Ball[i].Radius, RED);
  }
  delay(20);
}



void testdrawcircles(uint8_t radius, uint16_t color) {
  for (uint8_t x=0; x < OLED.width()-1+radius; x+=radius*2) {
    for (uint8_t y=0; y < OLED.height()-1+radius; y+=radius*2) {
      OLED.drawCircle(x, y, radius, color);
    }
  }  
}

void TestPattern(void)
{
  static const uint16_t PROGMEM colors[] =
    { RED, YELLOW, GREEN, CYAN, BLUE, MAGENTA, BLACK, WHITE };

  for(uint8_t c=0; c<8; c++) {
    OLED.fillRect(0, OLED.height() * c / 8, OLED.width(), OLED.height() / 8,
      pgm_read_word(&colors[c]));
  }
}
