#ifndef POTENTIOMETER_H
#define POTENTIOMETER_H

class Application;

class Potentiometer {
    Application& m_application;
    unsigned char m_last_value;

    unsigned char current_value() const;
public:
    explicit Potentiometer(Application& t_application);

    void initialize();

    void ping();
};

#endif // POTENTIOMETER_H
