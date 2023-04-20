#ifndef SPP_
#define SPP_

#include "Step.h"

namespace Steps {
    class SPP;
}

class Steps::SPP: public Step {
    std::optional<char> m_current_value;

    std::string m_answer;

    void put(char t_char);
public:
    explicit SPP(Application& t_application);

    void potentiometer_has_new_value(int t_value);
    void white_button_was_pressed();
    void blue_button_was_pressed();
    void red_button_was_pressed();
    void rotary_has_new_value(int t_value);
    void rotary_was_pressed();
};

#endif // SPP_
