#include "Memory.h"

Steps::Memory::Memory(Application& t_application) : Step(t_application) {

    m_screens = {
        //"----------------"
          "Bien joue ! Mais"
          "Je dois te dire ",

          "que cette enigme"
          "ci risque d'etre",

          "Streisand...    "
          "                ",

          "Ca te derange   "
          "pas que je      ",

          "t'appelle       "
          "  Barbara ?     "
    };

}

void Steps::Memory::screen_callback(unsigned int t_index) {

    if (t_index != 4) { return; }

    for (auto color : m_colors) {
        set_led_color(color);
        wait(400);
        set_led_color(LED::Off);
        wait(400);
    }

}

void Steps::Memory::potentiometer_has_new_value(int t_value) {

}

void Steps::Memory::white_button_was_pressed() {
    check(LED::White);
}

void Steps::Memory::blue_button_was_pressed() {
    check(LED::Blue);
}

void Steps::Memory::red_button_was_pressed() {
    check(LED::Red);
}

void Steps::Memory::rotary_has_new_value(int t_value) {

}

void Steps::Memory::rotary_was_pressed() {

    if (done()) { return; }

    if (m_current_index != m_colors.size()) {
        fail();
        m_current_index = 0;
        return;
    }

    success();

}

void Steps::Memory::check(LED::Color t_color) {

    if (done()) { return; }

    if (m_current_index == m_colors.size() || m_colors[m_current_index] != t_color) {
        fail();
        m_current_index = 0;
        return;
    }

    ++m_current_index;

}
