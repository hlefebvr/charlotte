#ifndef LCD_H
#define LCD_H

#include <string>

class Application;

class LCD {
    Application& m_application;
    int m_handle = -1;
public:
    LCD(Application& t_application);

    void initialize();

    void display(const std::string& t_msg);

    bool is_working() const { return m_handle >= 0; }
};

#endif // LCD_H
