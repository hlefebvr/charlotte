#ifndef LETTER_H
#define LETTER_H

#include "Step.h"

namespace Steps {
    class Letter;
}

class Steps::Letter : public Step {
    std::string m_answer = "________";
    unsigned int m_current_index = 0;

    void put(char t_char);
public:
    explicit Letter(Application& t_application);

    void potentiometer_has_new_value(int t_value);
    void white_button_was_pressed();
    void blue_button_was_pressed();
    void red_button_was_pressed();
    void rotary_has_new_value(int t_value);
    void rotary_was_pressed();
};
#endif // LETTER_H
