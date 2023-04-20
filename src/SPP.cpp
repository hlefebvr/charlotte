#include "SPP.h"

Steps::SPP::SPP(Application& t_application) : Step(t_application) {

    m_screens = {
        //"----------------"
          "Okaay ! Je vois "
          "que tu as une   ",

          "bonne memoire ! "
          "D'ailleurs, tu  ",

          "te souviens de  "
          "ce type avec qui",

          "tu niquais ? Ca "
          "fait longtemps  ",

          "que tu l'as pas "
          "vu, non ? Il m'a",

          "dit de te dire  "
          "que tu lui      ",

          "manquais.       "
          "Le truc c'est   ",

          "que c'est pas   "
          "facile le voyage",

          "Et c'est pas fac"
          "il de trouver le",

          "plus court chemi"
          "n...            ",

          "hlefebvr.github."
          "io/assets/images",

          "/spp.png        "
          "[de A a J] "
    };

}

void Steps::SPP::put(char t_value) {
    m_answer += t_value;
    display(m_answer);
}

void Steps::SPP::potentiometer_has_new_value(int t_value) {

}

void Steps::SPP::white_button_was_pressed() {

    if (done()) { return; }

    if (!m_current_value.has_value()) {
        return;
    }

    put(m_current_value.value());

}

void Steps::SPP::blue_button_was_pressed() {

}

void Steps::SPP::red_button_was_pressed() {

    if (done()) { return; }

    m_answer = "";
    m_current_value.reset();

    display(m_answer);

}

void Steps::SPP::rotary_has_new_value(int t_value) {

    if (done()) { return; }

    const char letter = 'A' + (t_value % 26);

    m_current_value = letter;

    display(m_answer + m_current_value.value());

}

void Steps::SPP::rotary_was_pressed() {

    if (done()) { return; }

    if (m_answer != "ADFHJ") {
        fail();
        m_answer = "";
        m_current_value.reset();
        display(m_answer);
        return;
    }

    success();
}
