#include <iostream>
#include <fstream>
#include <cstring>
#include <Windows.h> 
using namespace std;
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	// ������� ����� ����� � ������� �����������
	const int len = 81;
	char word[len], line[len]; // 1
	cout << "������ ����� ��� ������:";
	cin >> word;
	ifstream fin("D:/text_city_ukr2.txt"); // 2
	// �������� �������� ��������� ��'���� fin
	if (!fin) {
		cout << "������� �������� �����!" << endl;
		return 1;
	}
	while (fin.getline(line, len)) { // 3
		if (strstr(line, word)) {
			cout << "��������!" << endl;
			system("pause");
			return 1;
		}
	}
	cout << "³������!" << endl;
	system("pause");
}