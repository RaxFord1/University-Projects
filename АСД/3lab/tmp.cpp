//3.1,3.2.2
#include "windows.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{

	ifstream in("D://Shakespeare_WinterTale.txt", ios::binary);//read file
	ofstream out("questions.txt", ios::binary);//Create file with questions
	int numOfQuestions = 0;//Number of questions
	if (!in.is_open()) {
		cout << "Couldn't open file on read!" << endl;
		in.close();
		return 1;
	}
	if (!out.is_open()) {
		cout << "Couln't open file on write!" << endl;
		out.close();
		return 1;
	}
	//Num of chars 
	in.seekg(0, ios::end);
	int length = in.tellg();
	in.seekg(0, ios::beg);

	//Declare space for text
	char* text = new char[length + 1];
	in.read(text, length);
	text[length] = '\0';

	int startOfSentence = 0;
	int  i = 0;
	string sentence = "";
	//find end of sentence 
	for (i = startOfSentence; i < length; i++) {
		sentence += text[i];
		if (text[i] == '.' || text[i] == '?' || text[i] == '!' || (text[i] == '.' && text[i + 1] == '.' && text[i + 2] == '.')) {//Κ³νεφό πεχεννÿ
			if (text[i] == '.' && text[i + 1] == '.' && text[i + 2] == '.') {
				startOfSentence = i + 3; // if "...", skip 3
			}
			else {
				startOfSentence = i + 1; // if ?,!,. skip 1
			}

			if (sentence[sentence.length() - 1] == '?') {
				numOfQuestions++;
				out.write(sentence.c_str(), sentence.length());
			}

			sentence = "";
		}
	}
	cout << "Num of questions: " << numOfQuestions << endl;
	delete[]text;
	in.close();
	in.clear();
	out.close();
	out.clear();

	//Dump file
	in.open("questions.txt", ios::binary);

	if (!in.is_open()) {
		cout << "Couldn't open file for read dump!" << endl;
		return 1;
	}
	//file length
	in.seekg(0, ios::end);
	length = in.tellg();
	in.seekg(0, ios::beg);

	//text from file
	char* textFromFile = new char[length + 1];
	textFromFile[length] = '\n';

	//Reading text
	in.read(textFromFile, length);
	in.close();

	ofstream dumpFile("dump.dat", ios::binary);
	if (!dumpFile.is_open()) {
		cout << "Couldn't open file for write dump!" << endl;
		return 1;
	}
	for (int j = 0; j < length; j++) {
		dumpFile.write((char*)&textFromFile[j], sizeof(textFromFile[j]));
	}
	//dumpFile.write(textFromFile, length);
	dumpFile.close();
	cout << "Dump succesfully written!" << endl;

	delete[]textFromFile;

}
