#ifndef GREENLIGHT_H
#define GREENLIGHT_H

#include "Step.h"

namespace Steps {
    class GreenLight;
}

class Steps::GreenLight : public Step {
    LED::Color m_current_color = LED::Off;
public:
    explicit GreenLight(Application& t_application);

    void potentiometer_has_new_value(int t_value);
    void white_button_was_pressed();
    void blue_button_was_pressed();
    void red_button_was_pressed();
    void rotary_has_new_value(int t_value);
    void rotary_was_pressed();
};

#endif // GREENLIGHT_H
