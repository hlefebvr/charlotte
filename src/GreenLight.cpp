#include "GreenLight.h"


Steps::GreenLight::GreenLight(Application& t_application) : Step(t_application) {

    m_screens = {
        //"----------------"
          "Bravo! Je vois  "
          "que tu as reussi",

          "ma premiere     "
          "  enigme !      ",

          "Prete pour la   "
          "suite ? Si oui, ",

          "J'attends ton   "
          "Feu vert !      "
    };

}

void Steps::GreenLight::potentiometer_has_new_value(int t_value) {

}

void Steps::GreenLight::white_button_was_pressed() {

}

void Steps::GreenLight::blue_button_was_pressed() {

}

void Steps::GreenLight::red_button_was_pressed() {

}

void Steps::GreenLight::rotary_has_new_value(int t_value) {

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

void Steps::GreenLight::rotary_was_pressed() {

    if (done()) { return; }

    if (m_current_color != LED::Green) {
        fail();
        set_led_color(m_current_color);
        return;
    }

    success();
}
