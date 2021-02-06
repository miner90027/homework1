/* Aleks McCormick
 * UAF CS 202
 * Homework 1
 * 01/28/2021
 */
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

char* strdup(const char*);
char* findx(const char* s, const char* x);

int main(){
	string data = "How many chars are on the screen";
	const char *cstr = data.c_str();
	cout<< strdup(cstr) << endl;

}

char* strdup(const char* orig){
	int size = strlen(orig) + 1;

	char *copy;
	copy = new char[size];

	for(int i = 0; i <= size;i++)
		copy[i] = orig[i];

	return copy;
}

char* findx(const char* s, const char* x){
	char* z;
	return z;
}