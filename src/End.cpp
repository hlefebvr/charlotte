#include "End.h"

Steps::End::End(Application& t_application) : Step(t_application) {

    m_screens = {
        //"----------------"
          "Bravo !         "
          "Tu as reussi a  ",

          "resoudre toutes "
          "mes enigmes !   ",

          "Comme recompense"
          "voila mon code :",

          "5b598a3454adf51a"
          "0451c334be359c2f",

          "MDR."
    };

}

void Steps::End::potentiometer_has_new_value(int t_value) {

}

void Steps::End::white_button_was_pressed() {

}

void Steps::End::blue_button_was_pressed() {

}

void Steps::End::red_button_was_pressed() {

}

void Steps::End::rotary_has_new_value(int t_value) {

}

void Steps::End::rotary_was_pressed() {

}
