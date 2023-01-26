#ifndef Clock_h
#define Clock_h
#include<Arduino.h>
#include<NTPClient.h>
#include<WiFiUdp.h>
class Clock{
    public:
    Clock() ;
    WiFiUDP clocker;
    NTPClient ntp;
    String getTime();
};


#endif