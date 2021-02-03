/* Aleks McCormick
 * UAF CS 202
 * Homework 1
 * 01/28/2021
 */
#include <iostream>
#include <random>
#include <algorithm>
#include <vector>
using std::random_device;
using std::mt19937;
using std::uniform_int_distribution;
using std::vector;
using std::cout;
using std::endl;

int randNumGen();

int main() {
	//create a vector & fill it w/ 1 million random numbers
	vector<int> intVec;
	long million = 1000000;
	for (long i = 0; i < million;i++) {
		intVec.push_back(randNumGen());
	}

	//print out vector for debugging purposes
	/*
	for(auto i: intVec)
	{
		cout << i << endl;
	}
*/
}

//random number generator returns a random int between 0 & 100
int randNumGen(){
	random_device randDev;
	mt19937 gen(randDev());
	uniform_int_distribution<>dis(0,100);
	return dis(gen);
}