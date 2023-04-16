#ifndef BUZZER_H
#define BUZZER_H

class Application;

class Buzzer {
    Application& m_application;
public:
    Buzzer(Application& t_application);

    void initialize();

    void bip(unsigned int t_time_in_milliseconds);
};

#endif // BUZZER_H
