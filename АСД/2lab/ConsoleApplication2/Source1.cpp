#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <Windows.h> 
#include <string>

using namespace std;
// entry point to our program
int main() {
	// set encoding for output
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	// first word(first text part) and second word (second text part)
	vector<char> chars;
	vector<char> chars2;
	// char variable
	char ch = 0;

	// initializing our formatting variables
	bool first_to_fill = true; // which word to fill
	int counter = 0; // if we want to process part of text file
	int count_add_gap_between = 0; // number of gaps between words
	int count_need_newlines_after_first_word = 0; // number of new lines after first word
	int count_need_newlines_before_first_word = 0; // number of new lines before first word
	bool print = false; // to print text in next step 

	// open file
	ifstream myfile("D:/text.txt");

	if (myfile.is_open())
	{
		// reading file char by char
		while (myfile.get(ch)) {
			/*counter++;
			if (counter == 600) { break; }*/
			// printing 
			if (print) {
				// adding new lines before text
				for (int i = 0; i < count_need_newlines_before_first_word; i++) {
					cout << "\n";
				}
				// adding new lines after first part of text
				for (int i = 0;i < count_need_newlines_after_first_word; i++) {
					chars.push_back('\n');
				}
				// printing first part of text
				for (const char& i : chars) {
					cout << i;
				}
				// printing gaps between text parts
				for (int i = 0; i < count_add_gap_between; i++) {
					cout << " ";;
				}
				// printing second part of text
				for (const char& i : chars2) {
					cout << i;
				}
				// clearing all variables to default
				chars.clear();
				chars2.clear();
				print = false;
				count_need_newlines_after_first_word = 0;
				count_need_newlines_before_first_word = 0;
				count_add_gap_between = 0;
			}
			// processing new line character
			if (ch == '\n') {
				// if we have new line and we ready to swap texts print it.
				if (!chars.empty() && !chars2.empty()) {
					print = true;
					first_to_fill = true;
					chars2.push_back(ch);
				}
				// we have only first part of text and we need to remember for future a new lines
				else if (chars.empty() && !chars2.empty()) {
					count_need_newlines_after_first_word++;
					chars2.push_back(' ');
					first_to_fill = false;
				}
				// we have no text at all and adding new lines before text begins
				else {
					count_need_newlines_before_first_word++;
				}
				continue;
			}
			// processing gap character
			if (ch == ' ') {
				// if we filled first text part, next fill second part
				if (first_to_fill) {
					first_to_fill = false;
					count_add_gap_between++;
					chars2.push_back(ch);
				}
				// reverse to prev and swaped print text
				else {
					first_to_fill = true;
					print = true;
					chars.push_back(ch);
				}
				continue;
			}
			// fill first part of text
			if (first_to_fill) {
				chars2.push_back(ch);
			}
			//fill second part of text
			else {
				chars.push_back(ch);
			}
		}

	}
	// file doesn't open
	else cout << "Unable to open file";
	// pause to see console output
	system("pause");
}