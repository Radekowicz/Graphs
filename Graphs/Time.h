#pragma once

#include <iostream>
#include <ctime>
#include <chrono>

using namespace std::chrono;

class Time
{
	high_resolution_clock::time_point startTime;
	high_resolution_clock::time_point endTime;

public:
	void start();

	void stopAndPrint();

	double stopAndPrint2();

};

