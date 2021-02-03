/* Aleks McCormick
 * UAF CS 202
 * Homework 1
 * 01/28/2021
 */
#include <iostream>
#include <fstream>
#include <random>
#include <algorithm>
#include <vector>
#include "StopWatch.hpp"
using std::random_device;
using std::mt19937;
using std::uniform_int_distribution;
using std::vector;
using std::cout;
using std::endl;
using std::sort;
using std::ofstream;

int randNumGen();
void sortAlg(int numEle);

StopWatch counter;
vector<int> intVec;

int main() {

	//create a vector & fill it w/ 10 million random numbers
	for (long i = 0; i < 10000000;i++) {
		intVec.push_back(randNumGen());
	}

	//sortAlg(10);
	sortAlg(100);
	//stop timer & print elapsed time for debuggin
	/*
	counter.stop();
	cout << counter.getTimeSec() << endl;
	cout << counter.getTimeMilli() << endl;
	*/

	//print out vector for debugging purposes
	/*
	for(auto i: intVec)
	{
		cout << i << endl;
	}
*/
}

void sortAlg(int numEle)
{
	ofstream file("timeItValSort.txt",std::ios::app);
	file << "Sorting 5 vectors of " << numEle << " diffrent elements\n";
	cout << "Sorting 5 vectors of " << numEle<< " diffrent elements\n";
	//run & time sort algorithm on 10 elements in the vector 5 times & print results of each time
	for(int i = 0, x = 0; i < 5; i++, x+=10)
	{
		counter.start();
		sort(intVec.begin() + x, intVec.begin() + x + numEle);
		counter.stop();
		file << "Time to complete (milliseconds): "<< counter.getTimeMilli() << endl;

	}
	file << endl;
}

//random number generator returns a random int between 0 & 100
int randNumGen(){
	random_device randDev;
	mt19937 gen(randDev());
	uniform_int_distribution<>dis(0,100);
	return dis(gen);
}