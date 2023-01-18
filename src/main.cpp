
#include <OledHelper.h>
OledHelper oled;
void setup() {
  Serial.begin(9600);
  if(!oled.setup_oled()){
    for(;;){}
  }
  Serial.println("Oled Initialized");
  oled.clear();
  for(int i=0;i<10;i++){
    oled.circle(i*10,10,5,false);
  }
  oled.show();
  
}

void loop() {
  // put your main code here, to run repeatedly:
}