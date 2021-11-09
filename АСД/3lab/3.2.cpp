//3.2.1
#include <iostream>
#include <fstream>
#include <locale.h>
#include <windows.h>
using namespace std;
int main() {
	int arr1[] = { 0, 10, 4, 25, 1000, 14, 0, 47, 11, 1 };
	char arr2[] = { 'a', '\ 0', 'b' };
	double m = 3.14, n = 0.0003;
	// відкриття для запису
	ofstream fin1("Z3.dat", ios::binary);
	if (!fin1.is_open()) { // перевірка
		cout << "Помилка відкриття файлу!" << endl;
		return 1;
	}

	// Запис 8 Байт - розмір m
	fin1.write((char*)&m, sizeof(m));
	// Запис 8 Байт - розмір n
	fin1.write((char*)&n, sizeof(n));
	// Запис 4Байт*10 - розмір масиву arr1
	for (int i = 0; i < 10; i++) {
		fin1.write((char*)&arr1[i], sizeof(arr1[i]));
	}
	// Запис 1Байт *3 - розмір масиву arr2
	for (int i = 0; i < 3; i++) {
		fin1.write((char*)&arr2[i], sizeof(arr2[i]));
	}
	fin1.close(); // закриття файлу
	// відкриття для читання
	ifstream fout("Z3.dat", ios::binary);
	if (!fout.is_open()) { // перевірка
		cout << "Помилка відкриття файлу!" << endl;
		return 1;
	}
	fout.seekg(0, ios::end); // перехід в кінець файлу
	// поточна позиція в байтах, виміряна від початку
	long len = fout.tellg();
	cout << len << endl;
	fout.close(); // закриття файлу
	// відкриття для дозапису в кінець файлу
	ofstream fin2("Z3.dat", ios::binary | ios::app);
	if (!fin2.is_open()) {
		cout << " Помилка відкриття файлу !" << endl;
		return 1;
	}
	// Запис 4Б - розмір len
	fin2.write((char*)&len, sizeof(len));
	fin2.close(); // закриття файлу
	system("pause");
}