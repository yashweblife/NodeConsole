#include <OledHelper.h>
#include <Controller.h>
#include <Ball.h>
#include <Box.h>
OledHelper oled;
Controller lhs(14);
Controller rhs(12);

bool game_mode = true;

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
  oled.clear();
  int x_axis = map(rhs.getValue(), 137, 238, 0, 128);
  int y_axis = map(lhs.getValue(), 209, 6, 0, 64);
  oled.circle(x_axis, y_axis, 3);
  oled.circle(x_axis + 10, y_axis, 3);
  oled.rect(x_axis, y_axis + 15, 10, 3);
  oled.show();
}