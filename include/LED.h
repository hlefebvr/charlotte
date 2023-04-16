#ifndef LED_H
#define LED_H

class Application;

class LED {
public:
    LED(Application& t_application);

    void initialize();

    enum Color {
        Red = 0xFF0000,     // Red
		Green = 0x00FF00,   // Green
		Blue = 0x0000FF,    // Blue
		Yellow = 0xFFFF00,  // Yellow
		Cyan = 0x00FFFF,    // Cyan
		Magenta = 0xFF00FF, // Magenta
		White = 0xFFFFFF,   // White
		Pink = 0x9400D3,    // Pink
		Off = 0x000000,     // Off
    };

    void set_color(Color t_color);

private:
    Application& m_application;
    Color m_color = Off;
};

#endif // LED_H
