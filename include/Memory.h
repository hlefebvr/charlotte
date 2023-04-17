#ifndef MEMORY_H
#define MEMORY_H

#include "Step.h"

namespace Steps {
    class Memory;
}

class Steps::Memory : public Step {
    const std::vector<LED::Color> m_colors = {
        LED::Red,
        LED::Red,
        LED::Blue,
        LED::White,
        LED::Blue,
        LED::Red,
        LED::Blue,
        LED::Blue,
        LED::Red,
        LED::White,
        LED::Red,
        LED::Red,
    };

    unsigned int m_current_index = 0;

    void screen_callback(unsigned int t_index) override;
    void check(LED::Color t_color);
public:
    explicit Memory(Application& t_application);

    void potentiometer_has_new_value(int t_value);
    void white_button_was_pressed();
    void blue_button_was_pressed();
    void red_button_was_pressed();
    void rotary_has_new_value(int t_value);
    void rotary_was_pressed();
};

#endif // MEMORY_H
