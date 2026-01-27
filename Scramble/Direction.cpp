#include "Direction.h"
#include "HeaderFiles.h"


void Direction::PrintScramble() {

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> randDirection(0, 5);
	std::uniform_int_distribution<int> randTurningWay(0, 2);

	int lastDirection = -1;
	int lastTurningWay = -1;

	int currentDirection = -1;
	int currentTurningWay = -1;

	std::uniform_int_distribution<int> randStepsNumber(20, 25);
	int stepsNumber = randStepsNumber(gen);


	for (int i = 0; i < stepsNumber; ++i) {

		while (currentDirection == lastDirection || currentTurningWay == lastTurningWay) {
			currentDirection = randDirection(gen);
			currentTurningWay = randTurningWay(gen);
		}

		std::cout << direction[currentDirection] << turningWay[currentTurningWay] << ' ';

		lastDirection = currentDirection;
		lastTurningWay = currentTurningWay;
	}

	std::cout << "The number of steps for this scramble is " << stepsNumber;
}

	
char Direction::direction[6] = { 'R', 'U', 'F', 'L', 'D', 'B' };
char Direction::turningWay[3] = { '\0', //cw
								'\'', //ccw
								'2'  //180
};
	


