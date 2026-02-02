#include "HeaderFiles.h"
#include "StopClock.h"

void StopClock::start() {
	while (true) {

		char startClockOrEsc = 0;   //?
		if (_kbhit()) {
			startClockOrEsc = _getch();
		}
		else {
			//std::cout << "waiting to use stopclock" << std::endl;
			std::this_thread::sleep_for(std::chrono::milliseconds(10));
			continue;
		}
		while (_kbhit()) {
			_getch();
		}


		if (startClockOrEsc == ' ') {
			std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
			std::cout << "start timing..." << std::endl;

			//²¶×½½áÊøµã
			while (true) {
				if (_kbhit() && _getch() == ' ') {
					std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
					std::chrono::milliseconds ms = std::chrono::duration_cast<std::chrono::milliseconds> (end - start);
					std::cout << "lasting: " << ms.count() / 1000.0 << 's' << std::endl;
					while (_kbhit()) {
						_getch();
					}

					break;
				}
				else {
					//std::cout << "press SPACE to end." << std::endl;
					std::this_thread::sleep_for(std::chrono::milliseconds(10));
				}
			}
		}
		else if (startClockOrEsc == 27) {
			std::cout << "exit the stop clock." << std::endl;
			break;
		}
		else {
			std::cout << "press SPACE to start and end.";
		}


	}

}