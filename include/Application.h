#ifndef APPLICATION_H
#define APPLICATION_H

#include "Potentiometer.h"
#include "LCD.h"

#include <string>
#include <vector>
#include <memory>

namespace impl {
    class Application;
}

class impl::Application {

    static std::string s_memory_filename;
    enum Mode { Question, Answer };

    unsigned int m_current_step = 0;
    bool m_is_in_error = false;
    Mode m_mode = Question;

    std::unique_ptr<LCD> m_lcd;
    std::unique_ptr<Potentiometer> m_potentiometer;

    void initialize();
    void read_current_step_from_disk();
    void write_current_step_from_disk();

protected:
    void error(const std::string& t_msg);
    void display(const std::string& t_msg, unsigned int t_min_delay_in_seconds = 1500);
    void wait(unsigned int t_time_in_seconds);

    void potentiometer_has_new_value(int t_value);
public:
    Application(LCD* t_lcd,
                Potentiometer* t_potentiometer
            );

    virtual ~Application() = default;

    void run();
};

class Application : public impl::Application {
    friend class LCD;
    friend class Potentiometer;
public:
    Application();
};

#endif // APPLICATION_H
