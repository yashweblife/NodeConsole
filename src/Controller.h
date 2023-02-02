#ifndef Controller_h
#define Controller_h
#include <Arduino.h>
class Controller
{
public:
    /**
     * @brief Construct a new Controller object
     *
     */
    Controller();
    /**
     * @brief Construct a new Controller object
     *
     * @param val
     */
    Controller(int val);
    /**
     * @brief Construct a new Controller object
     *
     * @param val
     * @param _min
     * @param _max
     */
    Controller(int val, int _min, int _max);
    int pin = 14;
    float minVal = 0;
    float maxVal = 1024;
    /**
     * @brief Set the min value of the object
     *
     * @param val
     */
    void setMin(float val);
    /**
     * @brief Set the max value of the object
     *
     * @param val
     */
    void setMax(float val);
    /**
     * @brief Get the Value of the object
     *
     * @return float
     */
    float getValue();
    /**
     * @brief Caliberate the minimum value of the object
     *
     */
    void caliberateMin();
    /**
     * @brief Caliberate the maximum value of the objct
     *
     */
    void caliberateMax();
    /**
     * @brief Map value between 2 points
     *
     * @param _min
     * @param _max
     * @return float
     */
    float mapValue(float _min, float _max);
};
#endif