#include <OledHelper.h>
#include <Controller.h>
#include <Ball.h>
#include <Box.h>
#include <Text.h>

OledHelper oled;
Controller lhs(14);
Controller rhs(12);

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

Text basic("Hello World");

void setup()
{
  Serial.begin(9600);
  if (!oled.setup_oled())
  {
    for (;;)
    {
    }
  }
  oled.clear();
  oled.rotate();
}

void pong()
{
  bool game_mode = true;
  bool winner = false;
  Ball ball(64, 32);
  ball.setSize(3);
  ball.setVel(1, 1);
  Box player1(10, 20);
  player1.setPos(0, 32 - 10);

  Box player2(10, 20);
  player2.setPos(128 - 10, 32 - 10);
  for (int i = 0; i < 3; i++)
  {
    oled.clear();
    oled.text("Pong", 10, 10, 2, true);
    oled.text(String(3 - i), 30, 35, 2, true);
    delay(1000);
    oled.show();
  }
  oled.clear();
  oled.text("Go", 10, 10, 2, true);
  oled.show();
  delay(1000);
  while (game_mode == true)
  {
    oled.clear();

    int p1 = map(rhs.getValue(), 137, 238, 0, 64 - player1.size.y);
    int p2 = map(lhs.getValue(), 209, 6, 0, 64 - player2.size.y);

    player1.setPos(player1.pos.x, p1);
    player2.setPos(player2.pos.x, p2);

    int bound_check = ball.bound();
    ball.update();

    if (player1.checkCollisionWithBall(ball.pos.x, ball.pos.y, ball.radius) || player2.checkCollisionWithBall(ball.pos.x, ball.pos.y, ball.radius))
    {
      ball.reverseVel(true);
    }
    if (bound_check == 1)
    {
      game_mode = false;
      winner = true;
    }
    if (bound_check == 3)
    {
      game_mode = false;
      winner = false;
    }

    player1.draw(oled);
    player2.draw(oled);
    ball.draw(oled);
    oled.line(64, 0, 64, 64);
    oled.show();
  }
  delay(500);
  oled.clear();
  if (winner)
  {
    oled.text("Player 2 Wins", 20, 20, 1.5, true);
  }
  else
  {
    oled.text("Player 1 Wins", 20, 20, 1.5, true);
  }
  oled.show();
  delay(2000);
}

void test()
{
  int p1 = map(rhs.getValue(), 137, 238, 0, 128);
  int p2 = map(lhs.getValue(), 209, 6, 0, 64);
  oled.clear();
  oled.bitmap(p1, p2, 16, 16, fighter);
  oled.show();
  basic.padding = 10;
  basic.border_left = true;
  oled.clear();
  basic.draw(oled);
  oled.text(String(basic.value), 20, 0, 1, false);
  oled.show();
}
void loop()
{
}