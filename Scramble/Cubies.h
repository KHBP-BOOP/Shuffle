#pragma once
#include "StopClock.h"
class ThreeTimesThree : public StopClock{


public:
	void PrintScramble3times3();

private:
	static char face3times3[6];
	static char rotationMethod[3];

};

