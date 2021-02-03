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
using std::chrono::system_clock;
using std::shuffle;
using std::default_random_engine;

int randNumGen();
void sortAlg(long numEle);
void shufAlg();


vector<int> intVec;

int main() {

	//create a vector & fill it w/ 10 million random numbers
	for (long i = 0; i < 10000000;i++) {
		intVec.push_back(randNumGen());
	}


	//iterates through the vector by a factor of 10 & uses sort to sort each itteration
	for(long i = 10; i < 10000000;i= i * 10)
	{
		sortAlg(i);
	}

	//shufAlg();


}
//run & time sort algorithm on x elements in the vector 5 times & print results of each time
void sortAlg(long numEle)
{
	StopWatch counter;
	ofstream file("timeItValSort.txt",std::ios::app);
	file << "Sorting 5 vectors of " << numEle << " diffrent elements using sort\n";
	cout << "Sorting 5 vectors of " << numEle<< " diffrent elements using sort\n";

	for(int i = 0; i < 5; i++)
	{
		counter.start();
		sort(intVec.begin(), intVec.begin()+ numEle);
		counter.stop();
		file << "Time to complete (seconds): "<< counter.getTimeMilli() << endl;
		//shuffle the vector so it can be sorted from scratch
		shufAlg();
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

//use shuffle to re-scramble the vector
void shufAlg() {
	StopWatch watch;
	ofstream file("timeItShuffle.txt",std::ios::app);
	cout<< "Re-shuffling the vector" << endl;
	file << "Re-shuffling the vector\n";
	watch.start();
	unsigned seed = system_clock::now().time_since_epoch().count();
	shuffle (intVec.begin(), intVec.end(), default_random_engine(seed));
	watch.stop();
	file << "Time to complete (seconds): "<< watch.getTimeSec() << endl << endl;
}
