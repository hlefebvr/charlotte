#include "Button.h"

// BUTTONS
#define BUTTON_WHITE	24 // GPI19
#define BUTTON_BLUE		25 // GPI26
#define BUTTON_RED		29 // GPI21

#include <wiringPi.h>
#include "Application.h"

Button::Button(Application& t_application, Color t_color)
    : m_application(t_application),
      m_pin([&](){
        if (t_color == White) return BUTTON_WHITE;
        if (t_color == Blue) return BUTTON_BLUE;
        if (t_color == Red) return BUTTON_RED;
        t_application.error("Unexpected button color.");
        return -1;
    }()),
     m_color(t_color)  {

}

void Button::initialize() {
    pinMode(m_pin, INPUT);
    pullUpDnControl(m_pin, PUD_UP);
    m_application.display("Button " + std::to_string(m_color) + " OK.");
}

void Button::ping() {

    if (digitalRead(m_pin) == 0) {
        delay(100);
        while(digitalRead(m_pin) == 0);
        delay(100);
        switch (m_color) {
            case White: m_application.white_button_was_pressed(); break;
            case Blue: m_application.blue_button_was_pressed(); break;
            case Red: m_application.red_button_was_pressed(); break;
            default: m_application.error("Unexpected button color.");
        }
    }

}
