#ifndef MORSE_H
#define MORSE_H

#include "Step.h"

namespace Steps {
    class Morse;
}

class Steps::Morse: public Step {
    const std::string m_pattern = "-.-. -.-- .- -.";
    LED::Color m_current_color = LED::Off;
protected:

    void screen_callback(unsigned int t_index);
public:
    explicit Morse(Application& t_application);

    void potentiometer_has_new_value(int t_value);
    void white_button_was_pressed();
    void blue_button_was_pressed();
    void red_button_was_pressed();
    void rotary_has_new_value(int t_value);
    void rotary_was_pressed();
};

#endif // MORSE_H
