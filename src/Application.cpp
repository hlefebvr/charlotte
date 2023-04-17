#include "Application.h"
#include <iostream>
#include <filesystem>
#include <fstream>
#include <exception>
#include <wiringPi.h>

std::string impl::Application::s_memory_filename = "memory.txt";

impl::Application::Application(LCD* t_lcd,
                               Potentiometer* t_potentiometer,
                               Button* t_white_button,
                               Button* t_blue_button,
                               Button* t_red_button,
                               LED* t_led,
                               Buzzer* t_buzzer,
                               Rotary* t_rotary
                               )
    : m_lcd(t_lcd),
      m_potentiometer(t_potentiometer),
      m_white_button(t_white_button),
      m_blue_button(t_blue_button),
      m_red_button(t_red_button),
      m_led(t_led),
      m_buzzer(t_buzzer),
      m_rotary(t_rotary) {

    // Output
    m_lcd->initialize();
    m_led->initialize();
    m_buzzer->initialize();

    // Input
    m_potentiometer->initialize();
    m_white_button->initialize();
    m_blue_button->initialize();
    m_red_button->initialize();
    m_rotary->initialize();

    read_current_step_from_disk();

}

void impl::Application::read_current_step_from_disk() {

    if (!std::filesystem::exists(s_memory_filename)) {
        m_current_step = 0;
        return;
    }

    std::ifstream file(s_memory_filename);

    if (!file.is_open())  {
        error("Could not read memory file.");
        return;
    }

    file >> m_current_step;

    file.close();

}

void impl::Application::write_current_step_from_disk() {

    std::ofstream file(s_memory_filename);

    if (!file.is_open())  {
        error("Could not write memory file.");
        return;
    }

    file << m_current_step;

    file.close();

}

void impl::Application::error(const std::string& t_msg) {

    m_is_in_error = true;

    m_led->set_color(LED::Red);

    if (!m_lcd->is_working()) {
        std::cout << t_msg << std::endl;
        return;
    }

    display(t_msg);

}

void impl::Application::display(const std::string& t_msg, unsigned int t_min_delay_in_seconds) {
    m_lcd->display(t_msg);
    wait(t_min_delay_in_seconds);
}

void impl::Application::wait(unsigned int t_time_in_seconds) {
    delay(t_time_in_seconds);
}

void impl::Application::run() {

    display("Application         is starting.");
    display("Current step: " + std::to_string(m_current_step));
    display("");

    while (true) {

        m_potentiometer->ping();
        m_white_button->ping();
        m_blue_button->ping();
        m_red_button->ping();
        m_rotary->ping();

    }

}

void impl::Application::potentiometer_has_new_value(int t_value) {
    display("Value: " + std::to_string(t_value), 500);
}

void impl::Application::white_button_was_pressed() {
    m_led->set_color(LED::White);
}

void impl::Application::blue_button_was_pressed() {
    m_led->set_color(LED::Blue);
}

void impl::Application::red_button_was_pressed() {
    m_led->set_color(LED::Red);
}

void impl::Application::rotary_has_new_value(int t_value) {
    display("Rotary: " + std::to_string(t_value));
}

void impl::Application::rotary_was_pressed() {
    m_led->set_color(LED::Cyan);
    wait(1000);
    m_led->set_color(LED::Off);
}

Application::Application() : impl::Application(new LCD(*this),
                                               new Potentiometer(*this),
                                               new Button(*this, Button::White),
                                               new Button(*this, Button::Blue),
                                               new Button(*this, Button::Red),
                                               new LED(*this),
                                               new Buzzer(*this),
                                               new Rotary(*this)
                                            ) {}

