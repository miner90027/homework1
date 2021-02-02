//
// Created by aleks on 01/28/21.
//

#include "StopWatch.hpp"
#include <chrono>
#include <ctime>

using std::chrono::steady_clock;
using std::chrono::system_clock;
using std::chrono::duration;



StopWatch::StopWatch():endTime_() {
	Start();
}

const void StopWatch::Start() {
	//strtTime_ = system_clock::now();
}

const void StopWatch::Stop() {
	//endTime_ = system_clock::now();
}

double StopWatch::GetTimeSec() {

	return 0;
}

double StopWatch::GetTimeMilli() {
	return 0;
}
