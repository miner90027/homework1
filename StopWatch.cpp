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
	strtTime_ = system_clock::now();
}

const void StopWatch::Stop() {
	endTime_ = system_clock::now();
}

double StopWatch::GetTimeSec() {
	auto timeDiff = endTime_ - strtTime_;
	return duration<double>(timeDiff).count();
}

double StopWatch::GetTimeMilli() {
	auto timeDiff = endTime_ - strtTime_;
	return duration<double,std::milli>(timeDiff).count();
}
