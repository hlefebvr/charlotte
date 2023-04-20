#include "Age.h"

#include "Application.h"

Steps::Age::Age(Application& t_application) : Step(t_application) {

    m_screens = {
      //"----------------"
        "Joyeux          "
        "  anniversaire !",

        "Bienvenue a toi,"
        "Charlotte Mangin",

        "Ce jeu se nomme "
        "      ...       ",

        "*** L'ennigmator"
        "        chat ***",

        "C'est une boite "
        "mega top secrete",

        "qu'il t'appartie"
        "nt d'ouvrir !   ",

        "Pour cela, il te"
        "faudra repondre ",

        "a quelques enigm"
        "es ! J'espere   ",

        "que tu es prete!"
        "  ************  ",

        "Tout d'abord, tu"
        "es actuellement ",

        "en mode question"
        "ou tu peux lire ",

        "l'enigme que tu "
        "dois resoudre.  ",

        "Tu peux changer "
        "le mode courant ",

        "en bougeant mon "
        "curseur dessous ",

        "de gauche (Q)   "
        "    a droite (R)",

        "Attention !!    "
        "En mode reponse ",

        "Mes boutons ne  "
        "repondent plus  ",

        "de rien ! Leur  "
        "role change a   ",

        "chaque enigme.  "
        "Tous ? Presque !",

        "Le bouton qui   "
        "brille, juste la",

        "a droite. Il te "
        "sert a valider  ",

        "ta reponse.     "
        "D'ailleurs !    ",

        "En guise de 1ere"
        "enigme, tu dois ",

        "entrer ton age !"
        "Bonne chance !"
    };

}


void Steps::Age::potentiometer_has_new_value(int t_value) {

}

void Steps::Age::white_button_was_pressed() {

}

void Steps::Age::blue_button_was_pressed() {

}

void Steps::Age::red_button_was_pressed() {

}

void Steps::Age::rotary_has_new_value(int t_value) {

    if (done()) { return; }

    m_current_value = t_value;

    display("Value: " + std::to_string(m_current_value.value()));

}

void Steps::Age::rotary_was_pressed() {

    if (done()) { return; }

    if (!m_current_value.has_value() || m_current_value != 29) {
        fail();
        return;
    }

    success();

}
