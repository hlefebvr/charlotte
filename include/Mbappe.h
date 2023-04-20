#ifndef MBAPPE_H
#define MBAPPE_H

#include "Step.h"

namespace Steps {
    class Mbappe;
}

class Steps::Mbappe: public Step {
    std::string m_answer = "___";
    unsigned int m_current_index = 0;

    void put(char t_char);
public:
    explicit Mbappe(Application& t_application);

    void potentiometer_has_new_value(int t_value);
    void white_button_was_pressed();
    void blue_button_was_pressed();
    void red_button_was_pressed();
    void rotary_has_new_value(int t_value);
    void rotary_was_pressed();
};

#endif // MBAPPE_H
