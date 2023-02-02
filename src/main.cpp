#include <OledHelper.h>
#include <Controller.h>
#include <Ball.h>
#include <Box.h>
#include <Pong.h>
OledHelper oled;


Pong pong;

static const unsigned char PROGMEM fighter[] =
    {0b00000010, 0b01000000,
     0b00000110, 0b01100000,
     0b00001110, 0b01110000,
     0b00001100, 0b00110000,
     0b00011001, 0b10011000,
     0b00011001, 0b10011000,
     0b00011100, 0b00111000,
     0b00011110, 0b01111000,
     0b00111111, 0b11111100,
     0b00111111, 0b11111100,
     0b00101101, 0b10110100,
     0b00100101, 0b10100100,
     0b00110001, 0b10001100,
     0b00111111, 0b11111100,
     0b00110111, 0b11101100,
     0b00010000, 0b00001000};


void setup()
{
  Serial.begin(9600);
  if (!oled.setup_oled())
  {
    for (;;)
    {
    }
  }
  oled.rotate();


}



void loop()
{
}
