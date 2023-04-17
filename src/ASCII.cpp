#include "ASCII.h"


Steps::ASCII::ASCII(Application& t_application) : Step(t_application) {

    m_screens = {
        //"----------------"
          "Okay ! Alors    "
          "C'est parti !   ",

          "Enfile ta plus  "
          "  belle         ",

          "combinaison et  "
          "plonge dans     ",

          "cette enigme!   "
          "             ...",

          "01010111        "  // W
          "01000010        ", // B

          "01000010        "  // B
          "01010111        ", // W

          "01010010        "  // R
          "01000010        ", // B

          "01010111        ", // W
    };

}

void Steps::ASCII::potentiometer_has_new_value(int t_value) {

}

void Steps::ASCII::put(char t_char) {

    if (done()) { return; }

    if (m_current_index == m_answer.size()) { return; }

    m_answer.at(m_current_index) = t_char;

    ++m_current_index;

    std::string to_print;
    for (const char c : m_answer) {
        if (c != '_') {
            to_print += '*';
        } else {
            to_print += '_';
        }
    }

    display(to_print);

}

void Steps::ASCII::white_button_was_pressed() {
    put('W');
}

void Steps::ASCII::blue_button_was_pressed() {
    put('B');
}

void Steps::ASCII::red_button_was_pressed() {
    put('R');
}

void Steps::ASCII::rotary_has_new_value(int t_value) {

}

void Steps::ASCII::rotary_was_pressed() {

    if (done()) { return; }

    if (m_answer != "WBBWRBW") {
        fail();
        m_answer = "_______";
        m_current_index = 0;
        display(m_answer);
        return;
    }

    success();

}
