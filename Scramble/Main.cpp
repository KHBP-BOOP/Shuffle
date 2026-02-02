#include "HeaderFiles.h"
#include "Cubies.h"
//
// RUFLDB
// R`
// R2
// 
// 
// Rw
// Rw`
// Rw2
//


int main() {
	ThreeTimesThree testThreeTimesThreeCubie;

	testThreeTimesThreeCubie.PrintScramble3times3();

	std::cout << "press ENTER to use stop clock." << std::endl;
	while (true) {
		char ifUseStopClock = 0;
		if (_kbhit()) {
			ifUseStopClock = _getch();
		}
		else {
			std::this_thread::sleep_for(std::chrono::milliseconds(10));
			continue;
		}
		while (_kbhit()) { _getch(); }


		if (ifUseStopClock == 13) {
			testThreeTimesThreeCubie.start();
			break;
		}
		else if (ifUseStopClock == 27) {
			break;
		}
	}

}