#include "Application.h"
#include <iostream>
#include <filesystem>
#include <fstream>
#include <exception>
#include <wiringPi.h>

std::string impl::Application::s_memory_filename = "memory.txt";

impl::Application::Application(LCD* t_lcd,
                               Potentiometer* t_potentiometer)
    : m_lcd(t_lcd),
      m_potentiometer(t_potentiometer) {


    m_lcd->initialize();
    m_potentiometer->initialize();

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
    }

}

void impl::Application::potentiometer_has_new_value(int t_value) {
    std::cout << t_value << std::endl;
    display("Value: " + std::to_string(t_value));
}

Application::Application() : impl::Application(new LCD(*this),
                                               new Potentiometer(*this)
                                            ) {}

