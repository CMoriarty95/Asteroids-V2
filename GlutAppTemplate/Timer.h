#pragma once
#include <time.h>
#include <ctime>

//
class Timer {

	int time = 0;
	int tempTime = 0;

public: 
	Timer(){
		clock_t start = clock();
		time = (start) / 1000;
	}

	int getTime() {
		return time;
	}
	void setTimer() {
		tempTime = time;
	}
	int compareTime() {
		return (time - tempTime);
	}

};