#include <iostream>
#include "Application.h"

#include <exception>
#include <wiringPi.h>

int main() {

	if (wiringPiSetup() < 0) {
		throw std::runtime_error("Pi initialization failed.");
	}

    Application app;

    app.run();

    return 0;
}
