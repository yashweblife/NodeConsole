# Node Console

This is a ESP8266 project.

### Stuff used

- NodeMCU
- 2X 1K POT
- 0.96` I2C OLED display

## Some Info

This project has `many custom libraries` that can be used for other projects.
The premis behind this project is to create an `interface for the NodeMCU`.

A problem with NodeMCU is that it has `only 1 analog pin`, in order to read >1
analog values, we need to be smart.
The way we do it is by rapidly switching power between the knobs.

#### Breakdown

POT has 3 pins,

1. VCC
2. POT
3. GND

- Connect VCC to a digital pin preferably using a transistor
- Connect POT pin to analog input with a diode in between
- Connect GND to GND

If you turn on the digital pin, the analog pin will recieve data from the POT.
Use another POT with another digital pin.

#### The display driver library

The core library being used is `Adafruit1306` but Ive added an abstraction layer for ease of use. It doesnt matter in the long run since it gets reduced and optimized upon compilation. Any code should be written with efficiency in mind but never forget ease of use. If you have to repeat 4 lines of code all the time to get something done, put it in a funciton.

#### Vectors

Probably the most important functional library in this project.
This handles stuff like position, velocity and acceleration data
It can also be used for other things like holding size data.

```C++
#include<Vector.h>
void test(){
    Vector vec1(0,0,0); //Vector takes 3 arguments: x,y,z
    Vector vec2(0,0,0);
    //Add and subtract 2 Vectors
    vec1.add(vec2);
    vec1.sub(vec2);
    //Get Magnitude of vector
    float mag = vec1.getMag();
    //Set the vector to its unit form
    vec1.normalize();
    //Multiply a scalar to the vector
    vec1.scalar(mag);   //Multiplying a unit vector with its provious magnitude will simply give the original vector
    float dist = vec1.distance(vec2);    //Get the distance between 2 vectors
}
```

#### Ball

The simplest thing you should be able to do in this project is create a ball.

The primary things you can with a ball are: - Set Position/Velocity/Acceleration
Create a ball like this:

```C++
#include <Ball.h>
#include<OledHelper.h>

OledHelper oled;

Ball b(10,10);
//Set Size
void setup(){
    if (!oled.setup_oled())
    {
        for (;;)
        {
        }
    }
    //Set the balls size
    b.setSize(10);
    //Set the acceleration to some y value to emulate gravity
    b.setAcc(0, 0.02);
}
void loop(){
    //Update the ball's physics
    b.update();
    //Bound the ball to the screen, the ball will bounce
    b.bound(0,0,128,64);
    //draw the ball
    b.draw(oled);
}

```

 
