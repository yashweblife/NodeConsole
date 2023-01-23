#include <Arduino.h>
#include <OledHelper.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

OledHelper::OledHelper() {}

bool OledHelper::setup_oled()
{
    d = Adafruit_SSD1306(128, 64, &Wire, -1);
    if (!d.begin(SSD1306_SWITCHCAPVCC, 0x3C))
    {
        return (false);
    }
    return (true);
}
/**
 * @brief Draw pixel on given spot
 * 
 * @param x int
 * @param y int
 */
void OledHelper::pix(int x, int y)
{
    d.drawPixel(x, y, SSD1306_WHITE);
}
/**
 * @brief Draw line from x, y to x1,y1
 * 
 * @param x  int 
 * @param y  int
 * @param x1 int 
 * @param y1 int 
 */
void OledHelper::line(int x, int y, int x1, int y1)
{
    d.drawLine(x, y, x1, y1, SSD1306_WHITE);
}

/**
 * @brief Draw circle at x,y with a given radius and speciy wether to fill it or not
 * 
 * @param x int
 * @param y int
 * @param r int
 * @param fill bool
 */
void OledHelper::circle(int x, int y, int r, bool fill)
{
    if (fill)
    {
        d.fillCircle(x, y, r, SSD1306_WHITE);
    }
    else
    {
        d.drawCircle(x, y, r, SSD1306_WHITE);
    }
}
/**
 * @brief Draw rectangle at x,y with size of w,h and specify fill
 * 
 * @param x int
 * @param y int
 * @param w int
 * @param h int
 * @param fill bool
 */
void OledHelper::rect(int x, int y, int w, int h, bool fill)
{
    if (fill)
    {
        d.fillRect(x, y, w, h, SSD1306_WHITE);
    }
    else
    {
        d.drawRect(x, y, w, h, SSD1306_WHITE);
    }
}
/**
 * @brief Write text at point x,y with a specified size and specified fill
 * Set fill to true to highlight text
 * @param t String - text to write
 * @param x int - x pos on screen
 * @param y int - y pos on screen
 * @param s float - size of text
 * @param fill bool - highlight
 */
void OledHelper::text(String t, int x, int y, float s, bool fill)
{
    d.setTextSize(s); // Draw 2X-scale text
    if (fill == true)
    {
        d.setTextColor(SSD1306_BLACK, SSD1306_WHITE);
    }
    else
    {
        d.setTextColor(SSD1306_WHITE);
    }
    d.setCursor(x, y);
    d.println(t);
}
/**
 * @brief Draw bitmap image onto screen at x,y
 * 
 * @param x int
 * @param y int
 * @param w int
 * @param h int
 * @param image const uint8_t 
 */
void OledHelper::bitmap(int x, int y, int w, int h, const uint8_t *image)
{
    d.drawBitmap(x, y, image, w, h, 1);
}
/**
 * @brief Draw state of display
 * 
 */
void OledHelper::show()
{
    d.display();
}
/**
 * @brief Clear display
 * 
 */
void OledHelper::clear()
{
    d.clearDisplay();
}
/**
 * @brief set dim
 * 
 * @param val bool
 */
void OledHelper::dim(bool val)
{
    d.dim(val);
}
/**
 * @brief Rotate the screen
 * 
 * @param val int
 */
void OledHelper::rotate(int val)
{
    d.setRotation(val);
}