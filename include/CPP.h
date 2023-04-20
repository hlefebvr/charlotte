#ifndef CPP_
#define CPP_

#include "Step.h"

namespace Steps {
    class CPP;
}

class Steps::CPP : public Step {
    std::optional<int> m_current_value;
public:
    explicit CPP(Application& t_application);

    void potentiometer_has_new_value(int t_value);
    void white_button_was_pressed();
    void blue_button_was_pressed();
    void red_button_was_pressed();
    void rotary_has_new_value(int t_value);
    void rotary_was_pressed();
};

#endif // CPP_
