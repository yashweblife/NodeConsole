
#include <OledHelper.h>
#include<Controller.h>

OledHelper oled;
Controller lhs(14);
Controller rhs(12);

void setup() {
  Serial.begin(9600);
  if(!oled.setup_oled()){
    for(;;){}
  }
  oled.clear();
}

void loop() {
  oled.clear();
  oled.text("LHS:  "+String(lhs.getValue())+"\nRHS:  "+String(rhs.getValue()));
  oled.show();
}