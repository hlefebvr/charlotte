#include "Step.h"

#include "Application.h"

Step::Step(Application& t_application) : m_application(t_application) {

}


void Step::set_mode(Mode t_mode) {
    if (m_mode.has_value() && t_mode == m_mode) { return; }
    m_mode = t_mode;

    if (m_mode == Question) {
        m_current_screen = 0;
        m_application.display(m_screens.empty() ? "" : m_screens.front());
        return;
    }

    if (m_done) {
        m_application.display("Enigme deja      resolue.");
    } else {
        m_application.display(" .Mode reponse. ");
    }

}

void Step::next_screen() {
    m_current_screen += 1;
    m_current_screen %= m_screens.size();
    m_application.display(m_screens.at(m_current_screen));
    screen_callback(m_current_screen);
}

void Step::previous_screen() {

    m_current_screen = m_current_screen == 0 ? m_screens.size() - 1 : m_current_screen - 1;
    m_application.display(m_screens.at(m_current_screen));
    screen_callback(m_current_screen);

}

void Step::display(const std::string& t_msg, unsigned int t_min_delay_in_seconds) {
    m_application.display(t_msg, t_min_delay_in_seconds);
}

void Step::wait(unsigned int t_time_in_seconds) {
    m_application.wait(t_time_in_seconds);
}

void Step::set_led_color(LED::Color t_color) {
    m_application.set_led_color(t_color);
}

void Step::make_bip(unsigned int t_time_in_milliseconds) {
    m_application.make_bip(t_time_in_milliseconds);
}

void Step::success() {
    for (int k = 0 ; k < 5 ; ++k) {
        m_application.wait(100);
        m_application.set_led_color(LED::Green);
        make_bip(30);
        m_application.wait(70);
        m_application.set_led_color(LED::Off);
    }
    m_application.display("Bravo !         Enigme resolue !");
    m_done = true;
}

void Step::fail() {
    m_application.set_led_color(LED::Red);
    make_bip(200);
    m_application.wait(500);
    m_application.set_led_color(LED::Off);
}
