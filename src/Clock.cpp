#include<Arduino.h>
#include<Clock.h>
#include<NTPClient.h>
#include<WiFiUdp.h>

Clock::Clock(){
    ntp=NTPClient(clocker, "pool.ntp.org", -21600);
}