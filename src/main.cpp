
#include <OledHelper.h>
#include <Controller.h>

OledHelper oled;
Controller lhs(14);
Controller rhs(12);

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
  int selection = map(rhs.getValue(), 137, 238, 1, 3);
  oled.clear();
  oled.text("Hello", 10, 10, 1, selection == 1);
  oled.text("World", 10, 20, 1, selection == 2);
  oled.text("This", 10, 30, 1, selection == 3);
  oled.show();
}