#ifndef ASCII_H
#define ASCII_H

#include "Step.h"

namespace Steps {
    class ASCII;
}

class Steps::ASCII : public Step {
    std::string m_answer = "_______";
    unsigned int m_current_index = 0;

    void put(char t_char);
public:
    explicit ASCII(Application& t_application);

    void potentiometer_has_new_value(int t_value);
    void white_button_was_pressed();
    void blue_button_was_pressed();
    void red_button_was_pressed();
    void rotary_has_new_value(int t_value);
    void rotary_was_pressed();
};

#endif // ASCII_H
