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
	//��������� ���� � ������
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	int quantityOfFiles = 2;//������� �����
	string path;//���� �� �����
	ifstream* file = new ifstream[quantityOfFiles];//����� ����� ��� ���������

	//������� ²���²���� ���˲�
	for (int i = 0; i < quantityOfFiles; i++) {
		cout << "������ ���� �� ����� " << i << " :" << endl;
		cin >> path;
		file[i].open(path, ios::binary | ios::out);
		if (!file[i].is_open()) {
			cout << "������� �������� �����!" << endl;
			i--;
		}
	}

	//��в������ ���˲�
	//������� ������� �����
	file[0].seekg(0, ios::end);
	int lengthOfFirst = file[0].tellg();
	file[0].seekg(0, ios::beg);

	//������� ������� �����
	file[1].seekg(0, ios::end);
	int lengthOfSecond = file[1].tellg();
	file[1].seekg(0, ios::beg);

	//���� ��� �����
	char* content1 = new char[lengthOfFirst];
	char* content2 = new char[lengthOfSecond];

	//���������� �����
	file[0].read(content1, lengthOfFirst);
	file[1].read(content2, lengthOfSecond);
	//���������
	if (lengthOfFirst != lengthOfSecond) {
		int i = 0;
		int j = 0;

		while (i < lengthOfFirst && j < lengthOfSecond) {
			if (content1[i] != content2[j]) {
				cout << "г�� �� ������� �� ������ �����!" << endl;
				break;
			}
			else {
				i++;
				j++;
			}
		}

		if (i == lengthOfFirst - 1 || j == lengthOfSecond - 1) {
			cout << "���� ���� � �������� ������!" << endl;
		}
	}
	else {
		for (int i = 0; i < lengthOfFirst; i++) {
			if (content1[i] != content2[i]) {
				cout << "� ����� ����� ���� �� ��������� �����!" << endl;
				break;
			}
		}
		cout << "������� �� ������� �� �� ������ �����!" << endl;
	}

	delete[]content1;
	delete[]content2;

	return 0;
}
