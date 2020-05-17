#include "Time.h"

#include <iostream>
#include <ctime>
#include <chrono>

using namespace std;

void Time::start() {
	startTime = high_resolution_clock::now();
}

void Time::stopAndPrint() {
	endTime = high_resolution_clock::now();

	duration<double> time_span = duration_cast<duration<double>>(endTime - startTime);

	cout << "Czas wykonania operacji: " << time_span.count() << "s" << endl;
}

double Time::stopAndPrint2() {
	endTime = high_resolution_clock::now();

	duration<double> time_span = duration_cast<duration<double>>(endTime - startTime);
	return (double)time_span.count();
}
