#include "Poetry.h"

Steps::Poetry::Poetry(Application& t_application) : Step(t_application) {

    m_screens = {
        //"----------------"
          "M'habituer      "
          "M'habituer      ",

          "Si je ne le puis"
          "qu'on m'en blame",

          "Peut-on s'habitu"
          "er aux flammes ?",

          "Elles vous ont  "
          "avant tuer      ",

          "Ah! Crevez les  "
          "yeux de l'ame   ",

          "S'ils s'habituai"
          "ent aux nuees...",

          "Oups! Pardon, je"
          "ne t'avais pas  ",

          "vu! Tu as deja  "
          "fini ? Quel     ",

          "rapidite! Je m'e"
          "tais mis a la   ",

          "lecture en t'   "
          "attendant...    ",

          "Meme si je sais "
          "bien que la     ",

          "poesie n'est plu"
          "s vraiment a la ",

          "page..."
    };

}

void Steps::Poetry::potentiometer_has_new_value(int t_value) {

}

void Steps::Poetry::white_button_was_pressed() {

}

void Steps::Poetry::blue_button_was_pressed() {

}

void Steps::Poetry::red_button_was_pressed() {

}

void Steps::Poetry::rotary_has_new_value(int t_value) {

    if (done()) { return; }

    m_current_value = t_value;

    display("Value: " + std::to_string(m_current_value.value()));

}

void Steps::Poetry::rotary_was_pressed() {

    if (done()) { return; }

    if (!m_current_value.has_value() || m_current_value != 172) {
        fail();
        return;
    }

    success();

}
