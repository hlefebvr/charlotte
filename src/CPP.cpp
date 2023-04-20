#include "CPP.h"

Steps::CPP::CPP(Application& t_application) : Step(t_application) {

    m_screens = {
        //"----------------"
          "Arf, tu as      "
          "bientot resolu  ",

          "toutes mes enigm"
          "es... c'est     ",

          "vraiment frustra"
          "nt... Si c'est  ",

          "comme ca, je me "
          "met en greve de ",

          "toute facon ! Tu"
          "n'as qu'a te    ",

          "debrouiller tout"
          "e seule !       ",

          "GitHub: hlefebvr"
          "/charlotte"
    };

}

void Steps::CPP::potentiometer_has_new_value(int t_value) {

}

void Steps::CPP::white_button_was_pressed() {

}

void Steps::CPP::blue_button_was_pressed() {

}

void Steps::CPP::red_button_was_pressed() {

}

void Steps::CPP::rotary_has_new_value(int t_value) {

    if (done()) { return; }

    m_current_value = t_value;

    display("Value: " + std::to_string(m_current_value.value()));
}

void Steps::CPP::rotary_was_pressed() {

    if (done()) { return; }

    int result = 0;

    const int n = 5;
    const int m = 6;

    for (int i = 1 ; i <= n ; ++i) {
        for (int j = 1 ; j <= m ; ++j) {
            if ( (i+j) % 2 == 0 ) {
                result += i*j;
            } else {
                result -= i*j;
            }
        }
    }

    if (!m_current_value.has_value() || m_current_value != result) {
        fail();
        return;
    }

    success();
}
