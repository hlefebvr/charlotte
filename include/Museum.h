#ifndef MUSEUM_
#define MUSEUM_

#include "Step.h"

namespace Steps {
    class Museum;
}

class Steps::Museum: public Step {
    std::optional<int> m_current_index;
    const std::vector<std::string> m_names = { "Charlotte", "Henri", "Greg", "Marie" };
public:
    explicit Museum(Application& t_application);

    void potentiometer_has_new_value(int t_value);
    void white_button_was_pressed();
    void blue_button_was_pressed();
    void red_button_was_pressed();
    void rotary_has_new_value(int t_value);
    void rotary_was_pressed();
};

#endif // MUSEUM_
