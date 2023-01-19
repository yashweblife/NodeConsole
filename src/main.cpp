
#include <OledHelper.h>
#include <Controller.h>
#include <Ball.h>
#include <Box.h>
OledHelper oled;
Controller lhs(14);
Controller rhs(12);
Ball b(0, 0);
Box bx(64, 0);
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
  b.setSize(15);
  bx.setSize(10, 100);
}

void loop()
{
  int selection = map(rhs.getValue(), 137, 238, 0, 128);
  oled.clear();
  b.setPos(selection, 32);
  b.draw(oled, bx.checkCollisionWithBall(b));
  bx.draw(oled);
  oled.show();
}