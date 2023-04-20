#include "Mbappe.h"

Steps::Mbappe::Mbappe(Application& t_application) : Step(t_application) {

    m_screens = {
        //"----------------"
          "On dirait que tu"
          "t'en sors tres  ",

          "bien ! Je vais  "
          "devoir trouver  ",

          "plus dur... Pour"
          "ca, il me faut  ",

          "des encouragemen"
          "ts, comme ceux  ",

          "que l'on donnait"
          "a Mbappe.       ",

          "Tu veux bien    "
          "faire ca pour   ",

          "moi ? "
    };

}

void Steps::Mbappe::put(char t_char) {

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

void Steps::Mbappe::potentiometer_has_new_value(int t_value) {

}

void Steps::Mbappe::white_button_was_pressed() {
    put('W');
}

void Steps::Mbappe::blue_button_was_pressed() {
    put('B');
}

void Steps::Mbappe::red_button_was_pressed() {
    put('R');
}

void Steps::Mbappe::rotary_has_new_value(int t_value) {

}

void Steps::Mbappe::rotary_was_pressed() {

    if (done()) { return; }

    if (m_answer != "BWR") {
        fail();
        m_answer = "___";
        m_current_index = 0;
        display(m_answer);
        return;
    }

    success();

}
