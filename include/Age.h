#ifndef AGE_H
#define AGE_H

#include <Step.h>

namespace Steps {
    class Age;
}

class Steps::Age : public Step {
    std::optional<int> m_current_value;
public:
    explicit Age(Application& t_application);

    void potentiometer_has_new_value(int t_value);
    void white_button_was_pressed();
    void blue_button_was_pressed();
    void red_button_was_pressed();
    void rotary_has_new_value(int t_value);
    void rotary_was_pressed();
};

#endif // AGE_H
