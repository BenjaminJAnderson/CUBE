#ifndef _Adafruit_SSD1351_H_
#define _Adafruit_SSD1351_H_

#include <Adafruit_SPITFT.h>

// These #defines are DEPRECATED but present for older code compatibility:
#define SSD1351WIDTH 128  ///< DEPRECATED screen width
#define SSD1351HEIGHT 128 ///< DEPRECATED screen height, set to 96 for 1.27"

#define SSD1351_CMD_SETCOLUMN 0x15      ///< See datasheet
#define SSD1351_CMD_SETROW 0x75         ///< See datasheet
#define SSD1351_CMD_WRITERAM 0x5C       ///< See datasheet
#define SSD1351_CMD_READRAM 0x5D        ///< Not currently used
#define SSD1351_CMD_SETREMAP 0xA0       ///< See datasheet
#define SSD1351_CMD_STARTLINE 0xA1      ///< See datasheet
#define SSD1351_CMD_DISPLAYOFFSET 0xA2  ///< See datasheet
#define SSD1351_CMD_DISPLAYALLOFF 0xA4  ///< Not currently used
#define SSD1351_CMD_DISPLAYALLON 0xA5   ///< Not currently used
#define SSD1351_CMD_NORMALDISPLAY 0xA6  ///< See datasheet
#define SSD1351_CMD_INVERTDISPLAY 0xA7  ///< See datasheet
#define SSD1351_CMD_FUNCTIONSELECT 0xAB ///< See datasheet
#define SSD1351_CMD_DISPLAYOFF 0xAE     ///< See datasheet
#define SSD1351_CMD_DISPLAYON 0xAF      ///< See datasheet
#define SSD1351_CMD_PRECHARGE 0xB1      ///< See datasheet
#define SSD1351_CMD_DISPLAYENHANCE 0xB2 ///< Not currently used
#define SSD1351_CMD_CLOCKDIV 0xB3       ///< See datasheet
#define SSD1351_CMD_SETVSL 0xB4         ///< See datasheet
#define SSD1351_CMD_SETGPIO 0xB5        ///< See datasheet
#define SSD1351_CMD_PRECHARGE2 0xB6     ///< See datasheet
#define SSD1351_CMD_SETGRAY 0xB8        ///< Not currently used
#define SSD1351_CMD_USELUT 0xB9         ///< Not currently used
#define SSD1351_CMD_PRECHARGELEVEL 0xBB ///< Not currently used
#define SSD1351_CMD_VCOMH 0xBE          ///< See datasheet
#define SSD1351_CMD_CONTRASTABC 0xC1    ///< See datasheet
#define SSD1351_CMD_CONTRASTMASTER 0xC7 ///< See datasheet
#define SSD1351_CMD_MUXRATIO 0xCA       ///< See datasheet
#define SSD1351_CMD_COMMANDLOCK 0xFD    ///< See datasheet
#define SSD1351_CMD_HORIZSCROLL 0x96    ///< Not currently used
#define SSD1351_CMD_STOPSCROLL 0x9E     ///< Not currently used
#define SSD1351_CMD_STARTSCROLL 0x9F    ///< Not currently used


class Adafruit_SSD1351 : public Adafruit_SPITFT {
public:
  // NEW CONSTRUCTORS -- recommended for new projects
  // 6-7 args using soft SPI (reset optional)
  Adafruit_SSD1351(uint16_t SSD1351WIDTH, uint16_t SSD1351HEIGHT, int8_t cs_pin,
                   int8_t dc_pin, int8_t mosi_pin, int8_t sclk_pin,
                   int8_t rst_pin = -1);
  // 5-6 args using hardware SPI (must specify peripheral) (reset optional)
  Adafruit_SSD1351(uint16_t width, uint16_t height, SPIClass *spi,
                   int8_t cs_pin, int8_t dc_pin, int8_t rst_pin = -1);

  // DEPRECATED CONSTRUCTORS for back compatibility, avoid in new projects
  // 4-5 args using soft SPI (reset optional)
  Adafruit_SSD1351(int8_t cs_pin, int8_t dc_pin, int8_t mosi_pin,
                   int8_t sclk_pin, int8_t rst_pin = -1);
  // 2-3 args using default hardware SPI peripheral (reset optional)
  Adafruit_SSD1351(int8_t cs_pin, int8_t dc_pin, int8_t rst_pin = -1);

  ~Adafruit_SSD1351(void);

  void begin(uint32_t freq = 0), setRotation(uint8_t r),
      invertDisplay(boolean i), // Preferred syntax (same as other screens)
      invert(boolean i),        // For compatibility with old code
      enableDisplay(boolean enable),
      setAddrWindow(uint16_t x, uint16_t y, uint16_t w, uint16_t h);
};

#endif // _Adafruit_SSD1351_H_
