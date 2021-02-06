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
using std::default_random_engine;
using std::vector;
using std::cout;
using std::endl;
using std::ofstream;
using std::chrono::system_clock;
using std::shuffle;
using std::binary_search;
using std::sort;
using std::rotate;

int randNumGen(int min, int max);
void sortAlg(long numEle);
void shufAlg(long size);
void biSearch(long size);
void rotateAlg(long size);

vector<int> intVec;
bool isSorted = false;

int main() {

	long vecSize = 100000000;
	//create a vector & fill it w/ 100 million random numbers
	cout << "Generating vector of "<< vecSize <<" random numbers" << endl;
	for (long i = 0; i < vecSize;i++) {
		intVec.push_back(randNumGen(0, 100));
	}

	//iterates through the vector by a factor of 10 & uses sort to sort each iteration
	for(long i = 10; i <= vecSize;i= i * 10)
	{
		sortAlg(i);
	}

	//iterates through the vector by a factor of 10 & uses binary search to search each size for a random int
	for(long i = 10; i <= vecSize;i= i * 10)
	{
		biSearch(i);
	}

	//rotates the vectors of different sizes so that a random point between the beginning & the chosen size is the new beginning
	for(long i = 10; i <= vecSize;i= i * 10)
	{
		rotateAlg(i);
	}

}

//run & time sort algorithm on x elements in the vector 5 times & print results of each time
void sortAlg(long numEle)
{
	StopWatch counter;
	ofstream file("timeItValSort.txt",std::ios::app);
	file << "Sorting 5 vectors of " << numEle << " different elements using sort\n";
	cout << "Sorting 5 vectors of " << numEle << " different elements using sort\n";

	for(int i = 0; i < 5; i++)
	{
		counter.start();
		sort(intVec.begin(), intVec.begin()+ numEle);
		counter.stop();
		file << "Time to complete (milliseconds): "<< counter.getTimeMilli() << endl;
		//shuffle the vector so it can be sorted from scratch
		shufAlg(numEle);
	}
	file << endl;
}

//random number generator returns a random int between a min value & max value
int randNumGen(int min, int max){
	random_device randDev;
	mt19937 gen(randDev());
	uniform_int_distribution<>dis(min,max);
	return dis(gen);
}

//use shuffle to re-scramble the vector
void shufAlg(long size) {
	StopWatch watch;
	ofstream file("timeItShuffle.txt",std::ios::app);
	cout << "Re-shuffling the vector size " << size << endl;
	file << "Re-shuffling the vector size " << size << endl;
	watch.start();
	unsigned seed = system_clock::now().time_since_epoch().count();
	shuffle (intVec.begin(), intVec.begin() + size, default_random_engine(seed));
	watch.stop();
	file << "Time to complete (seconds): "<< watch.getTimeSec() << endl << endl;
}

//use a binary search to look for a random int in a vector of x size ** if the vector isn't sorted this function sorts the entire vector before initiating the search**
void biSearch(long size) {
	if(!isSorted)
	{
		cout << "Sorting vector before initiating binary search." << endl;
		sort(intVec.begin(), intVec.end());	//must sort the entire vector before using binary search
		isSorted = true;
	}

	bool isFound;
	cout << "Searching for a random num in a vector of " << size << " different elements using binary_search 5 times."<< endl;
	StopWatch timer;

	ofstream file("timeItBiSearch.txt",std::ios::app);
	file << "Searching for a random num in a vector of " << size << " different elements using binary_search 5 times.\n";

	for(int i = 0; i < 5; i++){
		timer.start();
		isFound = binary_search(intVec.begin(),intVec.begin()+size, randNumGen(0,100));
		timer.stop();
		file << "Time to complete (milliseconds): "<< timer.getTimeMilli()<< endl;

		if(isFound)
			cout<< "The number was found in "<< timer.getTimeMilli() << " milliseconds." << endl;
		else
			cout<< "The number was not found. It took "<< timer.getTimeMilli()<< " milliseconds to run" << endl;
	}
	file << endl;

}

//run & time the rotate algorithm
void rotateAlg(long size) {
	StopWatch timer;
	long midNum = randNumGen(1, size - 1);
	ofstream file("timeItRotate.txt", std::ios::app);
	cout << "Rotating a vector with a size of "<< size << endl;
	file << "Rotating the vector with a size of "<< size << endl;
	for(int i = 0; i < 5; i++)
	{
		timer.start();
		rotate(intVec.begin(),intVec.begin() + midNum, intVec.begin() + size);
		timer.stop();
		file << "Time to complete (milliseconds): " << timer.getTimeMilli()<< endl;
	}
	file << endl;
}
