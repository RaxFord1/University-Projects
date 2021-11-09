//3.4
#include "windows.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>

using namespace std;

int main()
{
	//Українська мова в консолі
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	int quantityOfFiles = 2;//кількість файлів
	string path;//шлях до файлу
	ifstream* file = new ifstream[quantityOfFiles];//масив файлів для порівняння

	//ЗАДАННЯ ВІДПОВІДНИХ ФАЙЛІВ
	for (int i = 0; i < quantityOfFiles; i++) {
		cout << "Введіть шлях до файлу " << i << " :" << endl;
		cin >> path;
		file[i].open(path, ios::binary | ios::out);
		if (!file[i].is_open()) {
			cout << "Помилка відкриття файлу!" << endl;
			i--;
		}
	}

	//ПОРІВНЯННЯ ФАЙЛІВ
	//Довжина першого файла
	file[0].seekg(0, ios::end);
	int lengthOfFirst = file[0].tellg();
	file[0].seekg(0, ios::beg);

	//Довжина другого файла
	file[1].seekg(0, ios::end);
	int lengthOfSecond = file[1].tellg();
	file[1].seekg(0, ios::beg);

	//Вміст цих файлів
	char* content1 = new char[lengthOfFirst];
	char* content2 = new char[lengthOfSecond];

	//Зчитування вмісту
	file[0].read(content1, lengthOfFirst);
	file[1].read(content2, lengthOfSecond);
	//Порівняння
	if (lengthOfFirst != lengthOfSecond) {
		int i = 0;
		int j = 0;

		while (i < lengthOfFirst && j < lengthOfSecond) {
			if (content1[i] != content2[j]) {
				cout << "Різні за розміром та вмістом файли!" << endl;
				break;
			}
			else {
				i++;
				j++;
			}
		}

		if (i == lengthOfFirst - 1 || j == lengthOfSecond - 1) {
			cout << "Один файл є частиною іншого!" << endl;
		}
	}
	else {
		for (int i = 0; i < lengthOfFirst; i++) {
			if (content1[i] != content2[i]) {
				cout << "У файлів різний вміст та однаковий розмір!" << endl;
				break;
			}
		}
		cout << "Однакові за розміром та за вмістом файли!" << endl;
	}

	delete[]content1;
	delete[]content2;

	return 0;
}
