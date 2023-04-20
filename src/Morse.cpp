#include "Morse.h"

Steps::Morse::Morse(Application& t_application) : Step(t_application) {

    m_screens = {
        //"----------------"
          "OK, OK, ca va ! "
          "Merci pour tes  ",

          "encouragements. "
          "                "

          "Pour cette      "
          "enigme, quoi de ",

          "mieux qu'un jeu "
          "de mot ab-sourde",

          "?"
    };

}

void Steps::Morse::screen_callback(unsigned int t_index) {

    if (t_index != 2) {
        return;
    }

    const double measure = 100;

    for (const char symbol : m_pattern) {

        if (symbol == '.') {
            make_bip(measure);
        } else if (symbol == ' ') {
            wait(3 * measure);
        } else if (symbol == '-') {
            make_bip(3 * measure);
        } else {
            display("An error occured.");
        }
        wait(measure);

    }

}

void Steps::Morse::potentiometer_has_new_value(int t_value) {

}

void Steps::Morse::white_button_was_pressed() {

}

void Steps::Morse::blue_button_was_pressed() {

}

void Steps::Morse::red_button_was_pressed() {

}

void Steps::Morse::rotary_has_new_value(int t_value) {

    if (done()) { return; }

    switch (t_value % 9) {
        case 0: m_current_color = LED::Off; break;
        case 1: m_current_color = LED::Red; break;
        case 2: m_current_color = LED::Blue; break;
        case 3: m_current_color = LED::Yellow; break;
        case 4: m_current_color = LED::White; break;
        case 5: m_current_color = LED::Green; break;
        case 6: m_current_color = LED::Pink; break;
        case 7: m_current_color = LED::Magenta; break;
        case 8: m_current_color = LED::Cyan; break;
        default:;
    }

    set_led_color(m_current_color);

}

void Steps::Morse::rotary_was_pressed() {

    if (done()) { return; }

    if (m_current_color != LED::Cyan) {
        fail();
        set_led_color(m_current_color);
        return;
    }

    success();
}
