#ifndef APPLICATION_H
#define APPLICATION_H

#include "types.h"

#include "Potentiometer.h"
#include "LCD.h"
#include "Button.h"
#include "Buzzer.h"
#include "LED.h"
#include "Rotary.h"
#include "Step.h"

#include <string>
#include <vector>
#include <memory>
#include <optional>

namespace impl {
    class Application;
}

class impl::Application {

    static std::string s_memory_filename;

    unsigned int m_current_step = 0;
    bool m_is_in_error = false;
    std::optional<Mode> m_mode;

    std::unique_ptr<LCD> m_lcd;
    std::unique_ptr<Potentiometer> m_potentiometer;
    std::unique_ptr<Button> m_white_button;
    std::unique_ptr<Button> m_blue_button;
    std::unique_ptr<Button> m_red_button;
    std::unique_ptr<LED> m_led;
    std::unique_ptr<Buzzer> m_buzzer;
    std::unique_ptr<Rotary> m_rotary;

    std::vector<std::unique_ptr<Step>> m_steps;

    void initialize();
    void read_current_step_from_disk();
    void write_current_step_to_disk();

protected:
    void error(const std::string& t_msg);
    void display(const std::string& t_msg, unsigned int t_min_delay_in_seconds = 100);
    void wait(unsigned int t_time_in_seconds);
    void set_led_color(LED::Color t_color);
    void make_bip(unsigned int t_time_in_milliseconds);

    void potentiometer_has_new_value(int t_value);
    void white_button_was_pressed();
    void blue_button_was_pressed();
    void red_button_was_pressed();
    void rotary_has_new_value(int t_value);
    void rotary_was_pressed();

    void add_step(Step* t_step);
public:
    Application(LCD* t_lcd,
                Potentiometer* t_potentiometer,
                Button* t_white_button,
                Button* t_blue_button,
                Button* t_red_button,
                LED* t_led,
                Buzzer* t_buzzer,
                Rotary* t_rotary
            );

    virtual ~Application() = default;

    void run();
};

class Application : public impl::Application {
    friend class LCD;
    friend class Potentiometer;
    friend class Button;
    friend class LED;
    friend class Buzzer;
    friend class Rotary;
    friend class Step;
public:
    Application();
};

#endif // APPLICATION_H
