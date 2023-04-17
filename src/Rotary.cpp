#include "Rotary.h"

// Rotary
#define ROTARY_A	00 // GPI17
#define ROTARY_B	02 // GPI27
#define ROTARY_S	03 // GPI22

#include "Application.h"

#include <wiringPi.h>

Rotary::Rotary(Application& t_application) : m_application(t_application) {

}

static volatile int clicked_count = 0;

void on_click() {
    ++clicked_count;
}

void Rotary::initialize() {

	pinMode(ROTARY_S,  INPUT);
	pinMode(ROTARY_A, INPUT);
	pinMode(ROTARY_B, INPUT);

	pullUpDnControl(ROTARY_S, PUD_UP);

    if(wiringPiISR(ROTARY_S, INT_EDGE_FALLING, &on_click) < 0){
		m_application.error("Unable to init ISR");
		return;
	}

    m_application.display("Rotary OK.");

}

void Rotary::ping() {

    // Checking clicks
    if (m_last_click_count != clicked_count) {
        m_last_click_count = clicked_count;
        m_application.rotary_was_pressed();
    }

    // Checking value

	unsigned char Last_RoB_Status = digitalRead(ROTARY_B);
	unsigned char Current_RoB_Status;
	unsigned char flag = 0;

	while(!digitalRead(ROTARY_A)){
		Current_RoB_Status = digitalRead(ROTARY_B);
		flag = 1;
	}

	if(flag == 1){
		if((Last_RoB_Status == 0)&&(Current_RoB_Status == 1)){
			m_counter++;
		} else if((Last_RoB_Status == 1) && (Current_RoB_Status == 0)){
			m_counter--;
		}
		m_application.rotary_has_new_value(m_counter);
	}

}
