#include "windows.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>

using namespace std;

const int ROWS = 5;
const int COLS = 5;

bool isNumber(const string& str);

void printArr(int arr[], int size);
void resetToZero(int arr[], int size);
void fillArr(int arr[], int size);

void printArr(int arr[ROWS][COLS]);
void resetToZero(int arr[ROWS][COLS]);
void fillArr(int arr[ROWS][COLS]);

int main() {


	srand(time(NULL));
	// Input a type of array
	int type = -1;
	string number;
	while (type < 0 || type > 2) {
		cout << "Choose type of array u want to work with:" << endl;
		cout << "\t1 - 1d array" << endl;
		cout << "\t2 - 2d array" << endl;

		cin >> number;
		if (!isNumber(number)) continue;
		type = atoi(number.c_str());
	}
	number = "a";
	//----------1D Array---------//
	if (type == 1) {
		ofstream out("array.txt", ios::binary);

		if (!out.is_open()) {
			cout << "Couldnt open file on write!" << endl;
		}
		//Array size
		int sizeOfArray = -1;
		while (sizeOfArray < 0) {
			cout << "Enter size of array:" << endl;
			cin >> number;
			if (!isNumber(number)) continue;
			sizeOfArray = atoi(number.c_str());
		}
		number = "a";
		cout << endl;
		//Array we will write to file
		int* arr = new int[sizeOfArray];
		fillArr(arr, sizeOfArray);

		//Write random values to array
		out.write((char*)arr, sizeof(int) * sizeOfArray);
		out.close();
		delete[]arr;

		//Creating array
		int* control = new int[sizeOfArray];
		int answer = -1;

		while (answer < 0 || answer > 3) {
			cout << "Enter action u want to do with elements:" << endl;
			cout << "\t1 - Edit" << endl;
			cout << "\t2 - Delete" << endl;
			cout << "\t3 - Add" << endl;
			cin >> number;
			if (!isNumber(number)) continue;
			answer = atoi(number.c_str());
		}
		number = "a";


		if (answer == 1) {
			//Open 1d array file
			fstream file("array.txt", ios::binary | ios::in | ios::out);

			if (!file.is_open()) {
				cout << "Couldnt open file on read and write!" << endl;
			}
			else {
				int index = -1;// index of element
				int newValue;//new value of element
				int newPosition;//position for element to change in file

				//array that we have for changes
				file.read((char*)control, sizeof(int) * sizeOfArray);
				cout << "Array in file:" << endl;
				printArr(control, sizeOfArray);
				resetToZero(control, sizeOfArray);
				cout << endl;

				//Edits in file

				while (index < 0 || index >= sizeOfArray) {
					cout << "Enter index of element (0 to " << sizeOfArray << "):" << endl;
					cin >> number;
					if (!isNumber(number)) continue;
					index = atoi(number.c_str());
				}
				number = "a";
				while (!isNumber(number)) {
					cout << "Enter new value of element:" << endl;
					cin >> number;
					if (!isNumber(number)) continue;
					newValue = atoi(number.c_str());
				}
				number = "a";
				cout << endl;

				//Moving on position
				newPosition = index * sizeof(int);
				file.seekg(newPosition, ios::beg);

				//New values writing
				file.write((char*)&newValue, sizeof(int));
				file.seekg(0, ios::beg);

				//Array that we store after changes
				file.read((char*)control, sizeof(int) * sizeOfArray);
				cout << "Array after changes:" << endl;
				printArr(control, sizeOfArray);
				cout << endl;

				file.close();
				delete[]control;
			}
		}
		else if (answer == 2) {
			//Open file on read
			ifstream fileForRead("array.txt", ios::binary);

			if (!fileForRead.is_open()) {
				cout << "Couldnt open file on read!" << endl;
			}
			else {
				int index = -1;//Enter index of element we want to delete

				//Array that we store before changes
				fileForRead.read((char*)control, sizeof(int) * sizeOfArray);
				fileForRead.close();

				cout << "Array in file:" << endl;
				printArr(control, sizeOfArray);
				cout << endl;

				//Delete element
				while (index < 0 || index >= sizeOfArray) {
					cout << "Enter index of element (0 to " << sizeOfArray << "):" << endl;
					cin >> number;
					if (!isNumber(number)) continue;
					index = atoi(number.c_str());
				}
				number = "a";
				cout << endl;

				//Array that we changed
				int* arrForWrite = new int[sizeOfArray - 1];
				for (int i = 0; i < sizeOfArray - 1; i++) {
					if (i < index) {
						arrForWrite[i] = control[i];
					}
					else if (i >= index) {
						arrForWrite[i] = control[i + 1];
					}
				}
				resetToZero(control, sizeOfArray);

				//Writing to file
				ofstream fileForWrite("array.txt", ios::binary);

				if (!fileForWrite.is_open()) {
					cout << "Couldnt open file on write!" << endl;
				}
				else {
					fileForWrite.write((char*)arrForWrite, (sizeOfArray - 1) * sizeof(int));
					fileForWrite.close();
				}

				//Checking on array
				ifstream ready("array.txt", ios::binary);

				if (!ready.is_open()) {
					cout << "Couldnt open file on write!" << endl;
				}
				else {
					ready.seekg(0, ios::end);
					int length = ready.tellg();
					ready.seekg(0, ios::beg);

					int* rez = new int[length];
					ready.read((char*)rez, length);

					cout << "Array after changes:" << endl;
					printArr(rez, length / sizeof(int));
					cout << endl;

					delete[]rez;
					ready.close();
				}

				delete[]control;
				delete[]arrForWrite;
			}
		}
		else {
			//Open file on read
			ifstream fileForRead("array.txt", ios::binary);

			if (!fileForRead.is_open()) {
				cout << "Couldnt open file on read!" << endl;
			}
			else {
				int index = -1;//Enter index of element we want to delete
				int newValue;

				//Array that we store before changes
				fileForRead.read((char*)control, sizeof(int) * sizeOfArray);
				fileForRead.close();

				cout << "Array in file:" << endl;
				printArr(control, sizeOfArray);
				cout << endl;

				//Add element
				while (!isNumber(number)) {
					cout << "Enter new value of element:" << endl;
					cin >> number;
					if (!isNumber(number)) continue;
					newValue = atoi(number.c_str());
				}
				number = "a";
				cout << endl;

				//Array that we changed
				int* arrForWrite = new int[sizeOfArray + 1];
				for (int i = 0; i < sizeOfArray; i++) {
					arrForWrite[i] = control[i];
				}
				arrForWrite[sizeOfArray] = newValue;
				resetToZero(control, sizeOfArray);

				//Writing to file
				fstream fileForWrite("array.txt", ios::binary | ios::in | ios::out);

				if (!fileForWrite.is_open()) {
					cout << "Couldnt open file on write!" << endl;
				}
				else {
					fileForWrite.seekg(0, ios::end);
					fileForWrite.write((char*)&newValue, sizeof(int));
					fileForWrite.close();
				}

				//Checking on array
				ifstream ready("array.txt", ios::binary);

				if (!ready.is_open()) {
					cout << "Couldnt open file on write!" << endl;
				}
				else {
					ready.seekg(0, ios::end);
					int length = ready.tellg();
					ready.seekg(0, ios::beg);

					int* rez = new int[length];
					ready.read((char*)rez, length);

					cout << "Array after changes:" << endl;
					printArr(rez, length / sizeof(int));
					cout << endl;

					delete[]rez;
					ready.close();
				}

				delete[]control;
				delete[]arrForWrite;
			}
		}
	}
	else {//-----------2D file---------//	
		ofstream out("array2d.txt", ios::binary);

		if (!out.is_open()) {
			cout << "Couldnt open file on write!" << endl;
		}
		else {
			//Array that we will write
			int arr[ROWS][COLS];
			fillArr(arr);

			//Array for checking results 
			int control[ROWS][COLS];
			//char test[2][2] = { {'a','b'}, {'c', 'd'} };

			//Writing array in file
			out.write((char*)arr, ROWS * COLS * sizeof(int));
			out.close();

			//Open file on read
			fstream file("array2d.txt", ios::binary | ios::in | ios::out);

			if (!file.is_open()) {
				cout << "Couldn't open file on read or write!" << endl;
			}
			else {
				//ÌÀÑÈÂ, ÙÎ ÇÁÅÐ²ÃÀªÒÜÑß Ó ÔÀÉË² ÄÎ ÂÍÅÑÅÍÍß ÇÌ²Í
				file.read((char*)&control, ROWS * COLS * sizeof(int));
				cout << "Array in file:" << endl;
				printArr(control);
				resetToZero(control);
				cout << endl;

				//Edit file
				int index1 = -1;//first index
				int index2 = -1;//second index
				int newValue;//new value of element
				int newPosition;//position of coursor


				while (index1 < 0 || index1 >= ROWS) {
					cout << "Enter first index of Row (0 to " << ROWS << "):" << endl;
					cin >> number;
					if (!isNumber(number)) continue;
					index1 = atoi(number.c_str());
				}
				number = "a";
				while (index2 < 0 || index2 >= COLS) {
					cout << "Enter second index of Column(0 to " << COLS << "):" << endl;
					cin >> number;
					if (!isNumber(number)) continue;
					index2 = atoi(number.c_str());
				}
				number = "a";
				while (!isNumber(number)) {
					cout << "Enter new value of element:" << endl;
					cin >> number;
					newValue = atoi(number.c_str());
				}
				number = "a";
				cout << endl;


				//Moving coursor
				newPosition = index1 * COLS * sizeof(int) + index2 * sizeof(int);
				file.seekg(newPosition, ios::beg);

				//New value writing
				file.write((char*)&newValue, sizeof(int));
				file.seekg(0, ios::beg);

				//Array after changes
				file.read((char*)control, sizeof(int) * ROWS * COLS);
				cout << "Array after changes:" << endl;
				printArr(control);
				cout << endl;

				file.close();
			}
		}
	}
}

//2D Array
void fillArr(int arr[ROWS][COLS]) {
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			arr[i][j] = rand() % 9 + 1;
		}
	}
}
void resetToZero(int arr[ROWS][COLS]) {
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			arr[i][j] = 0;
		}
	}
}
void printArr(int arr[ROWS][COLS]) {
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			cout << arr[i][j] << '\t';
		}
		cout << endl;
	}
	cout << endl;
}
//1D Array 
void fillArr(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		arr[i] = rand() % 9 + 1;
	}
}
void resetToZero(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		arr[i] = 0;
	}
}
void printArr(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

//Check if value is digit
bool isNumber(const string& str) {
	int digits = 0;	//Num of digits in a number

	for (auto& element : str) {
		if (isdigit(element) || element == '-')
		{
			digits++;
		}
	}

	if (digits == str.length()) {
		return true;
	}
	else {
		return false;
	}
}

