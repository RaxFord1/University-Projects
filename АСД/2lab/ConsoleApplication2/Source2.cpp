#define _CRT_SECURE_NO_WARNINGS//strtok is not safe function. Delete depricate warning
#include "windows.h"
#include <string>
#include <vector>
#include <iostream> 
#include <fstream> 

using namespace std;

int main() {

	ifstream fin("D:/Shakespeare_Hamlet.txt");//open the file

	if (!fin.is_open()) {
		cout << "Couldn't open the file!" << endl;
	}
	else {
		int count = 0;//num of repeats

		const int length = 101;//max lenght of line
		char str[length];//line that we read
		char word[length];//word that we are looking for

		cout << "Enter a word to find:" << endl;
		cin >> word;//reading word

		while (fin.getline(str, length)) {
			char* token = strtok(str, " ");//find first occurence of delimeter

			while (token != NULL) { // if no occurence found -> continue with the next line
				const char* p;
				p = strstr(token, word); // returns pointer on the first occurrence of word in token

				if (p != NULL) {
					count++;
				}
				token = strtok(NULL, " ,.!:;-?");//continue to find occurence of delimeter from where we ended last time
			}
		}
		//print the results
		cout << "Number of repeats of the word '" << word << "' = " << count << endl;
	}
	fin.close();//close the file stream
	system("pause");//pause console
	return 0;
}
