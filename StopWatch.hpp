//
// Created by aleks on 01/28/21.
//

#ifndef HOMEWORK1_STOPWATCH_HPP
#define HOMEWORK1_STOPWATCH_HPP


class StopWatch {
public:
	StopWatch();
	const void Start();
	const void Stop();
	double GetTimeSec();
	double GetTimeMilli();
private:
	double strtTime_;
	double endTime_;
};


#endif //HOMEWORK1_STOPWATCH_HPP
