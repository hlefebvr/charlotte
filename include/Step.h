#ifndef STEP_H
#define STEP_H

#include "types.h"
#include "LED.h"

#include <vector>
#include <string>
#include <optional>

class Application;

class Step {
private:
    Application& m_application;
    std::optional<Mode> m_mode;

    bool m_done = false;
    unsigned int m_current_screen = 0;
protected:
    std::vector<std::string> m_screens;

    void display(const std::string& t_msg, unsigned int t_min_delay_in_seconds = 0);
    void wait(unsigned int t_time_in_seconds);
    void set_led_color(LED::Color t_color);
    void make_bip(unsigned int t_time_in_milliseconds);

    virtual void screen_callback(unsigned int t_index) {}

    void success();
    void fail();
public:
    explicit Step(Application& t_application);

    virtual ~Step() = default;

    void set_mode(Mode t_mode);
    void next_screen();
    void previous_screen();
    void home_screen();
    void reset_status() { m_done = false; }

    virtual void potentiometer_has_new_value(int t_value) = 0;
    virtual void white_button_was_pressed() = 0;
    virtual void blue_button_was_pressed() = 0;
    virtual void red_button_was_pressed() = 0;
    virtual void rotary_has_new_value(int t_value) = 0;
    virtual void rotary_was_pressed() = 0;

    bool done() const { return m_done; }
};

#endif // STEP_H
