#include "HeaderFiles.h"
#include "Cubies.h"



void ThreeTimesThree::PrintScramble3times3() {

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> randFace3times3(0, 5);
	std::uniform_int_distribution<int> randRotationMethod3times3(0, 2);

	int lastFace3times3 = -1;
	int lastRotationMethod3times3 = -1;

	int currentFace3times3 = -1;
	int currentRotationMethod3times3 = -1;

	std::uniform_int_distribution<int> randStepsNumber(20, 25);
	int stepsNumber = randStepsNumber(gen);


	for (int i = 0; i < stepsNumber; ++i) {

		while (currentFace3times3 == lastFace3times3 || currentRotationMethod3times3 == lastRotationMethod3times3) {
			currentFace3times3 = randFace3times3(gen);
			currentRotationMethod3times3 = randRotationMethod3times3(gen);
		}

		std::cout << face3times3[currentFace3times3] << rotationMethod[currentRotationMethod3times3] << ' ';

		lastFace3times3 = currentFace3times3;
		lastRotationMethod3times3 = currentRotationMethod3times3;
	}

	//std::cout << "The number of steps for this scramble is " << stepsNumber;
}

	
char ThreeTimesThree::face3times3[6] = { 'R', 'U', 'F', 'L', 'D', 'B' };
char ThreeTimesThree::rotationMethod[3] = { '\0', //cw 90
								'\'', //ccw 90
								'2'  //180
};
