#include "Museum.h"

Steps::Museum::Museum(Application& t_application) : Step(t_application) {

    m_screens = {
        //"----------------"
          "Parfait ! Voila "
          "qui va rendre   ",

          "vos retrouvaille"
          "s plus aisees...",

          "Si jamais c'est "
          "lui qui vient a ",

          "Grenoble, ca    "
          "serait sympa de ",

          "boire une biere "
          "avec Greg et    ",

          "Marie !         "
          "J'imagine deja  ",

          "la scene: apres "
          "plusieurs pintes",

          "le serveur se   "
          "pointe, \"qui n'",

          "a pas paye ?\".  "
          "Slience...      ",

          "\"C'est pas moi\" "
          "dis tu.         ",

          "\"C'est Henri\"   "
          "dit Greg.       ",

          "\"C'est Marie\"   "
          "dit Henri.      ",

          "\"Greg a tort\"   "
          "dit Marie.      ",

          "Sachant qu'un   "
          "seul ment, qui  ",

          "n'a pas paye ?  "
    };

}

void Steps::Museum::potentiometer_has_new_value(int t_value) {

}

void Steps::Museum::white_button_was_pressed() {

}

void Steps::Museum::blue_button_was_pressed() {

}

void Steps::Museum::red_button_was_pressed() {

}

void Steps::Museum::rotary_has_new_value(int t_value) {

    if (done()) { return; }

    m_current_index = t_value % m_names.size();

    display(m_names.at(m_current_index.value()));

}

void Steps::Museum::rotary_was_pressed() {

    if (done()) { return; }

    if (!m_current_index.has_value()) { return; }

    if (m_current_index.value() != 3) {
        fail();
        return;
    }

    success();

}
