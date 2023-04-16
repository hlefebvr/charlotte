#include "LED.h"

// LED
#define LED_R	23 // GPI23
#define LED_G	22 // GPI22
#define LED_B	21 // GPI21

#include "Application.h"
#include <wiringPi.h>
#include <softPwm.h>

int map(int x, int in_min, int in_max, int out_min, int out_max) {
	return (x -in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}


LED::LED(Application& t_application) : m_application(t_application) {

}

void LED::initialize() {

    softPwmCreate(LED_R,  0, 100);  //create a soft pwm, original duty cycle is 0Hz, range is 0~100
	softPwmCreate(LED_G,0, 100);
	softPwmCreate(LED_B, 0, 100);

    set_color(Green);
    m_application.wait(500);
    set_color(Off);

    m_application.display("LED OK.");
}

void LED::set_color(Color t_color) {

	int r_val, g_val, b_val;

	r_val = (t_color & 0xFF0000) >> 16;  //get red value
	g_val = (t_color & 0x00FF00) >> 8;   //get green value
	b_val = (t_color & 0x0000FF) >> 0;   //get blue value

	r_val = map(r_val, 0, 255, 0, 100);    //change a num(0~255) to 0~100
	g_val = map(g_val, 0, 255, 0, 100);
	b_val = map(b_val, 0, 255, 0, 100);

	softPwmWrite(LED_R,   100 - r_val);  //change duty cycle
	softPwmWrite(LED_G, 100 - g_val);
	softPwmWrite(LED_B,  100 - b_val);

    m_color = t_color;
}
