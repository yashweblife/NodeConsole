#ifndef OledHelper_h
#define OledHelper_h

#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_SSD1306.h>
/**
 * @brief Oled Helper takes care of the display by abstrascting away the extra lines
 *
 */
class OledHelper
{
public:
    /**
     * @brief Construct a new Oled Helper object
     *
     */
    OledHelper();
    bool setup_oled();
    /**
     * @brief Draw pixel on position x,y
     *
     * @param x
     * @param y
     */
    void pix(int x = 0, int y = 0);
    /**
     * @brief Draw line from x,y to x1,y1
     *
     * @param x
     * @param y
     * @param x1
     * @param y1
     */
    void line(int x = 0, int y = 0, int x1 = 10, int y1 = 10);
    /**
     * @brief Draw circle at x,y with radius r, specify if the circle is solid or not
     *
     * @param x
     * @param y
     * @param r
     * @param fill
     */
    void circle(int x = 0, int y = 0, int r = 10, bool fill = false);
    /**
     * @brief Draw rectangle at x,y of size w,h, specify if the circle is solid or not
     *
     * @param x
     * @param y
     * @param w
     * @param h
     * @param fill
     */
    void rect(int x = 0, int y = 0, int w = 10, int h = 10, bool fill = false);
    /**
     * @brief Draw text t at position x,y with the size s and specify highlight
     * @param t
     * @param x
     * @param y
     * @param s
     * @param fill
     */
    void text(String t = "", int x = 0, int y = 0, float s = 1, bool fill = false);
    /**
     * @brief draw bitmap at pos x,y and specify w,h
     *
     * @param x
     * @param y
     * @param w
     * @param h
     * @param image
     */
    void bitmap(int x, int y, int w, int h, const uint8_t *image);
    /**
     * @brief Activate the display with drawings
     *
     */
    void show(void);
    /**
     * @brief Clear the display
     *
     */
    void clear(void);
    /**
     * @brief Dim the display
     *
     * @param val
     */
    void dim(bool val = true);
    /**
     * @brief Rotate the display
     *
     * @param val
     */
    void rotate(int val = 2);

private:
    Adafruit_SSD1306 d;
};

#endif