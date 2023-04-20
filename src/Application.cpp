#include "Application.h"
#include <iostream>
#include <filesystem>
#include <fstream>
#include <exception>
#include <wiringPi.h>

#include "Age.h"
#include "GreenLight.h"
#include "ASCII.h"
#include "Mbappe.h"
#include "Morse.h"
#include "Poetry.h"
#include "Letter.h"
#include "Memory.h"
#include "SPP.h"
#include "Museum.h"
#include "CPP.h"
#include "End.h"

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

void impl::Application::write_current_step_to_disk() {

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

void impl::Application::display(const std::string& t_msg, unsigned int t_min_delay_in_milliseconds) {
    m_lcd->display(t_msg);
    wait(t_min_delay_in_milliseconds);
}

void impl::Application::wait(unsigned int t_time_in_seconds) {
    delay(t_time_in_seconds);
}

void impl::Application::set_led_color(LED::Color t_color) {
    m_led->set_color(t_color);
}

void impl::Application::make_bip(unsigned int t_time_in_milliseconds) {
    m_buzzer->bip(t_time_in_milliseconds);
}

void impl::Application::run() {

    while (true) {

        m_potentiometer->ping();
        m_white_button->ping();
        m_blue_button->ping();
        m_red_button->ping();
        m_rotary->ping();

        if (m_steps.at(m_current_step)->done()) {

            if (m_current_step < m_steps.size()) {
                ++m_current_step;
                write_current_step_to_disk();
            }

        }

    }

}

void impl::Application::red_button_was_pressed_for_a_long_time() {

    if (!m_mode.has_value() || m_mode != Question) {
        return;
    }

    m_led->set_color(LED::Magenta);
    for (auto& step : m_steps) {
        step->reset_status();
    }
    m_current_step = 0;
    write_current_step_to_disk();
    wait(1000);
    m_led->set_color(LED::Off);

}

void impl::Application::add_step(Step* t_step) {
    m_steps.emplace_back(t_step);
}

void impl::Application::potentiometer_has_new_value(int t_value) {

    const auto mode = t_value < 128 ? Question : Answer;

    if (!m_mode.has_value() || mode != m_mode) {
        m_mode = mode;
        m_steps.at(m_current_step)->set_mode(mode);
        m_rotary->reset_value();
    }

}

void impl::Application::white_button_was_pressed() {
    if (m_mode == Answer) {
        m_steps.at(m_current_step)->white_button_was_pressed();
    } else {
        m_steps.at(m_current_step)->previous_screen();
    }
}

void impl::Application::blue_button_was_pressed() {
    if (m_mode == Answer) {
        m_steps.at(m_current_step)->blue_button_was_pressed();
    } else {
        m_steps.at(m_current_step)->next_screen();
    }
}

void impl::Application::red_button_was_pressed() {
    if (m_mode == Answer) {
        m_steps.at(m_current_step)->red_button_was_pressed();
    } else {
        m_steps.at(m_current_step)->home_screen();
    }
}

void impl::Application::rotary_has_new_value(int t_value) {
    if (m_mode == Answer) {
        m_steps.at(m_current_step)->rotary_has_new_value(t_value);
    }
}

void impl::Application::rotary_was_pressed() {
    if (m_mode == Answer) {
        m_steps.at(m_current_step)->rotary_was_pressed();
    }
}

Application::Application() : impl::Application(new LCD(*this),
                                               new Potentiometer(*this),
                                               new Button(*this, Button::White),
                                               new Button(*this, Button::Blue),
                                               new Button(*this, Button::Red),
                                               new LED(*this),
                                               new Buzzer(*this),
                                               new Rotary(*this)
                                            ) {

    add_step(new Steps::Age(*this));
    add_step(new Steps::GreenLight(*this));
    add_step(new Steps::ASCII(*this));
    add_step(new Steps::Mbappe(*this));
    add_step(new Steps::Morse(*this));
    add_step(new Steps::Poetry(*this));
    add_step(new Steps::Letter(*this));
    add_step(new Steps::Memory(*this));
    add_step(new Steps::SPP(*this));
    add_step(new Steps::Museum(*this));
    add_step(new Steps::CPP(*this));
    add_step(new Steps::End(*this));

}

