#include "Letter.h"

Steps::Letter::Letter(Application& t_application) : Step(t_application) {

    m_screens = {
        //"----------------"
          "J'espere que ca "
          "t'a plu ce petit",

          "poeme ! Restons "
          "dans les lettres",

          "Celle la debute "
          "la nuit et      ",

          "termine le matin"
          "... Enfin...    ",

          "ASCII parait... "

    };

}

void Steps::Letter::put(char t_char) {

    if (done()) { return; }

    if (m_current_index == m_answer.size()) { return; }

    m_answer.at(m_current_index) = t_char;

    ++m_current_index;

    display(m_answer);

}

void Steps::Letter::potentiometer_has_new_value(int t_value) {

}

void Steps::Letter::white_button_was_pressed() {
    put('0');
}

void Steps::Letter::blue_button_was_pressed() {
    put('1');
}

void Steps::Letter::red_button_was_pressed() {
    m_answer =  "________";
    m_current_index = 0;
    display(m_answer);
}

void Steps::Letter::rotary_has_new_value(int t_value) {

}

void Steps::Letter::rotary_was_pressed() {

    if (done()) { return; }

    if (m_answer != "01001110") {
        fail();
        m_answer =  "________";
        m_current_index = 0;
        display(m_answer);
        return;
    }

    success();

}
