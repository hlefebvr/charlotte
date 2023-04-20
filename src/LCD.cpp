#include "LCD.h"

// Used for LCD
#include <wiringPi.h>
#include <pcf8574.h>
#include <lcd.h>

// LCD Settings

#define        AF_BASE    64
#define        AF_RS                (AF_BASE + 0)
#define        AF_RW                (AF_BASE + 1)
#define        AF_E                 (AF_BASE + 2)
#define        AF_LED               (AF_BASE + 3)

#define        AF_DB4               (AF_BASE + 4)
#define        AF_DB5               (AF_BASE + 5)
#define        AF_DB6               (AF_BASE + 6)
#define        AF_DB7               (AF_BASE + 7)

#include "Application.h"

#include <cmath>

LCD::LCD(Application& t_application)
    : m_application(t_application) {

}

void LCD::initialize() {


    if (pcf8574Setup(AF_BASE,0x27) < 0) { //pcf8574 I2C address
		m_application.error("LCD::PCF8574 failed.");
	}

    m_handle = lcdInit (2, 16, 4, AF_RS, AF_E, AF_DB4,AF_DB5,AF_DB6,AF_DB7, 0,0,0,0) ;

    if (m_handle < 0) {
        m_application.error("LCD  initialization faild.");
    }

    for(int i = 0 ; i < 8 ; i++) {
		pinMode(AF_BASE+i,OUTPUT);
	}

    digitalWrite(AF_LED,1);
    digitalWrite(AF_RW,0);

    lcdHome(m_handle);
    lcdClear(m_handle);
    lcdCursorBlink(m_handle, false);
    lcdCursor(m_handle, false);
}

void LCD::display(const std::string& t_msg) {

    const unsigned int size = t_msg.size();

    const std::string line1 = t_msg.substr(0, 16);
    const std::string line2 = t_msg.substr(std::min<unsigned int>(size, 16), 16);

    lcdClear(m_handle);
    lcdPosition(m_handle, 0, 0) ;
    lcdPuts(m_handle, line1.c_str()) ;
    lcdPosition(m_handle, 0, 1) ;
    lcdPuts(m_handle, line2.c_str()) ;

}

