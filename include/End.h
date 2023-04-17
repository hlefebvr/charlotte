#ifndef END_H
#define END_H

#include "Step.h"

namespace Steps {
    class End;
}

class Steps::End : public Step {
public:
    explicit End(Application& t_application);

    void potentiometer_has_new_value(int t_value);
    void white_button_was_pressed();
    void blue_button_was_pressed();
    void red_button_was_pressed();
    void rotary_has_new_value(int t_value);
    void rotary_was_pressed();
};

#endif // END_H
