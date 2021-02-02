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
	vector<int> intVec(10);
	intVec.

}

int randNumGen(){
	random_device randDev;
	mt19937 gen(randDev());
	uniform_int_distribution<>dis(0,100);
	return dis(gen);

}