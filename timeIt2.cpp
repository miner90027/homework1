/* Aleks McCormick
 * UAF CS 202
 * Homework 1
 * 01/28/2021
 */
#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include <algorithm>
#include <vector>
#include <list>
#include <queue>
#include "StopWatch.hpp"
using std::random_device;
using std::mt19937;
using std::uniform_int_distribution;
using std::default_random_engine;
using std::vector;
using std::list;
using std::queue;
using std::cout;
using std::endl;
using std::string;
using std::getline;
using std::ofstream;
using std::ifstream;
using std::chrono::system_clock;
using std::shuffle;
using std::binary_search;
using std::sort;
using std::rotate;
/*
int randNumGen(int min, int max);
void sortAlg(long numEle);
void shufAlg();
void biSearch(long size);
void rotateAlg(long size);

bool isSorted = false;
*/
void fillVec(ifstream &fileIn, vector<string> &vec, StopWatch &time);

int main() {
	//receive all of the text files
	ifstream sherlock("projectGutenbergBooks/sherlockHolmes.txt");
	ifstream warOWorlds("projectGutenbergBooks/warOfTheWorlds.txt");
	ifstream greatGat("projectGutenbergBooks/theGreatGatsby.txt");
	ifstream wizOz("projectGutenbergBooks/wizardOfOz.txt");
	ifstream alice("projectGutenbergBooks/alice&Wonderland.txt");

	//init the output files for each book
	ofstream sherOut("sherOut.txt",std::ios::app);
	ofstream warOut("warOut.txt",std::ios::app);
	ofstream gatOut("gatOut.txt",std::ios::app);
	ofstream wizOut("wizOut.txt",std::ios::app);
	ofstream aliceOut("aliceOut.txt",std::ios::app);

	//check to make sure that all of the files can be opened
	if(!sherlock || !warOWorlds || !greatGat || !wizOz || !alice) {
		cout << "A file was not found." << endl;
		return -1;
	}

	//init all of the stop watches
	StopWatch aliceTime;
	StopWatch wizTime;
	StopWatch warTime;
	StopWatch gatTime;
	StopWatch sherTime;

	//init all of the containers
	vector<string> aliceVec;
	vector<string> wizVec;
	vector<string> gatVec;
	list<string> warList;
	queue<string> sherQue;

	//fill all of the containers
	//temp sting variable used for filling containers
	string temp;
	//fill list
	warTime.start();
	while(getline(warOWorlds, temp))
	{
		warList.push_back(temp);
	}
	warTime.stop();
	//fill queue
	sherTime.start();
	while(getline(sherlock, temp))
	{
		sherQue.push(temp);
	}
	sherTime.stop();
	//fill vectors
	fillVec(alice, aliceVec, aliceTime);
	fillVec(wizOz, wizVec, wizTime);
	fillVec(greatGat, gatVec, gatTime);

	//write out the storage times to their respective files
	aliceOut << "Stored in a vector in (milliseconds):" << aliceTime.getTimeMilli() << endl;
	wizOut << "Stored in a vector in (milliseconds):" << wizTime.getTimeMilli() << endl;
	gatOut << "Stored in a vector in (milliseconds):" << gatTime.getTimeMilli() << endl;
	warOut << "Stored in a list in (milliseconds):" << warTime.getTimeMilli() << endl;
	sherOut << "Stored in a queue in (milliseconds):" << sherTime.getTimeMilli() << endl;


/*
 	//test print a vector
	for(auto i: aliceVec)
	{
		cout << i << "\n";
	}
*/
}

//fills & times the vectors
void fillVec(ifstream &fileIn, vector<string> &vec, StopWatch &time) {
	//temp sting variable used for filling containers
	string temp;

	//time & fill all containers
	time.start();
	while(getline(fileIn, temp))
	{
		vec.push_back(temp);
	}
	time.stop();
}

/*
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
		shufAlg();
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
void shufAlg() {
	StopWatch watch;
	ofstream file("timeItShuffle.txt",std::ios::app);
	cout << "Re-shuffling the vector" << endl;
	file << "Re-shuffling the vector\n";
	watch.start();
	unsigned seed = system_clock::now().time_since_epoch().count();
	shuffle (intVec.begin(), intVec.end(), default_random_engine(seed));
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
*/