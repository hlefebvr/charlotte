#ifndef ROTARY_H
#define ROTARY_H

class Application;

class Rotary {
    Application& m_application;
    int m_counter = 0;
    int m_last_click_count = 0;
public:
    Rotary(Application& t_application);

    void initialize();

    void ping();

    void reset_value();
};

#endif // ROTARY_H
