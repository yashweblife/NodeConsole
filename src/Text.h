#ifndef Text_h
#define Text_h
#include <Arduino.h>
#include <Vector.h>
#include <OledHelper.h>
/**
 * @brief Text is a library to handle string dislplay over the oled
 */
class Text
{
public:
    String value;
    Vector pos;
    Vector size;
    int scale;
    int padding;
    bool border_left;
    bool border_top;
    bool border_right;
    bool border_bottom;
    int padding_left;
    int padding_right;
    int padding_top;
    int padding_bottom;
    bool fill;
    bool underline;
    bool center_cut;
    /**
     * @brief Construct a new Text object
     * 
     * @param data 
     */
    Text(String data);
    /**
     * @brief Get the Width of the text
     * 
     * @return int 
     */
    int getWidth();
    /**
     * @brief Get the Height of the text
     * 
     * @return int 
     */
    int getHeight();
    /**
     * @brief Set the Scale of the text
     * 
     * @param s 
     */
    void setScale(int s);
    /**
     * @brief Set the Pos of the text
     * 
     * @param x 
     * @param y 
     */
    void setPos(int x, int y);
    /**
     * @brief Set the Padding for the text
     * 
     * @param val 
     */
    void setPadding(int val);
    /**
     * @brief Set the Value of the text
     * 
     * @param data 
     */
    void setValue(String data);
    void calculatePadding();
    void calculatePosition();
    /**
     * @brief Draw line going trough the center of the text
     * 
     */
    void centerCut();
    /**
     * @brief Underline the text
     * 
     */
    void underline();
    /**
     * @brief Set the left border visible 
     * 
     * @param val 
     */
    void setBorderLeft(bool val);
    /**
     * @brief Set the right border visible
     * 
     * @param val 
     */
    void setBorderRight(bool val);
    /**
     * @brief Set the top border visible
     * 
     * @param val 
     */
    void setBorderTop(bool val);
    /**
     * @brief Set the bottom border visible
     * 
     * @param val 
     */
    void setBorderBottom(bool val);
    /**
     * @brief Set the Border visible
     * 
     * @param val 
     */
    void setBorder(bool val);
    /**
     * @brief Draw the text
     * 
     * @param oled 
     */
    void draw(OledHelper &oled);
};

#endif
