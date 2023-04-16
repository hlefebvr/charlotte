#ifndef BUTTON_H
#define BUTTON_H

class Application;

class Button {
public:
    enum Color { White, Blue, Red };

    Button(Application& t_application, Color t_color);

    void initialize();

    void ping();
private:
    Application& m_application;
    const unsigned int m_pin;
    Color m_color;
};

#endif // BUTTON_H
