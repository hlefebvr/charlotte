#include "Potentiometer.h"
#include "Application.h"

// ADC
#define ADC_DATA	1 // GPI18
#define ADC_CLK		5 // GPI24
#define ADC_CS		4 // GPI23

#include <wiringPi.h>

Potentiometer::Potentiometer(Application& t_application) : m_application(t_application) {

}

void Potentiometer::initialize() {

	pinMode(ADC_CS,  OUTPUT);
	pinMode(ADC_CLK, OUTPUT);

    m_application.display("Potentio OK.");

}

unsigned char Potentiometer::current_value() const {

    //10:CH0
	//11:CH1
	unsigned char i;
	unsigned char dat1 = 0, dat2 = 0;

	pinMode(ADC_DATA, OUTPUT);

	digitalWrite(ADC_CS, 0);

	digitalWrite(ADC_CLK,0);
	digitalWrite(ADC_DATA,1);	delayMicroseconds(2);
	digitalWrite(ADC_CLK,1);	delayMicroseconds(2);
	digitalWrite(ADC_CLK,0);

	digitalWrite(ADC_DATA,1);    delayMicroseconds(2); //CH0 10
	digitalWrite(ADC_CLK,1);	delayMicroseconds(2);
	digitalWrite(ADC_CLK,0);

	digitalWrite(ADC_DATA,0);	delayMicroseconds(2); //CH0 0

	digitalWrite(ADC_CLK,1);
	digitalWrite(ADC_DATA,1);    delayMicroseconds(2);
	digitalWrite(ADC_CLK,0);
	digitalWrite(ADC_DATA,1);    delayMicroseconds(2);

	for(i=0;i<8;i++)
	{
		digitalWrite(ADC_CLK,1);	delayMicroseconds(2);
		digitalWrite(ADC_CLK,0);    delayMicroseconds(2);

		pinMode(ADC_DATA, INPUT);
		dat1=dat1<<1 | digitalRead(ADC_DATA);
	}

	for(i=0;i<8;i++)
	{
		dat2 = dat2 | ((unsigned char)(digitalRead(ADC_DATA))<<i);
		digitalWrite(ADC_CLK,1); 	delayMicroseconds(2);
		digitalWrite(ADC_CLK,0);    delayMicroseconds(2);
	}

	digitalWrite(ADC_CS,1);

	pinMode(ADC_DATA, OUTPUT);

	return(dat1==dat2) ? dat1 : 128;

}

void Potentiometer::ping() {

    const unsigned char value = current_value();

    if (value != 128 && !(m_last_value <= value + 2 && value <= m_last_value + 2)) {
        m_last_value = value;
        m_application.potentiometer_has_new_value(m_last_value);
    }

}
