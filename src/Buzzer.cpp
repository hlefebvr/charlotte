#include "Buzzer.h"

// BUZZER
#define BUZZER	28 // GPI20

#include <wiringPi.h>

#include "Application.h"

Buzzer::Buzzer(Application& t_application) : m_application(t_application) {

}

void Buzzer::initialize() {

    pinMode(BUZZER, OUTPUT);   //set GPIO0 output

    bip(500);
}

void Buzzer::bip(unsigned int t_time_in_milliseconds) {

    digitalWrite(BUZZER, HIGH);     //bip on
    delay(t_time_in_milliseconds);
    digitalWrite(BUZZER, LOW);      //bip off

}
