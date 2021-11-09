//3.5
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
		cout << "������ ���� �� �����:" << endl;
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

	//�����, �� ������ ������ ���������
	vector<char> different;

	//���������
	int partOfFirst = 0;
	int partOfSecond = 0;

	if (lengthOfFirst != lengthOfSecond) {
		int i = 0;
		int j = 0;

		while (i < lengthOfFirst && j < lengthOfSecond) {
			if (content1[i] != content2[j]) {
				different.push_back(content1[i]);
				different.push_back(content2[j]);

				partOfFirst++;
				partOfSecond++;

				i++;
				j++;
			}
			else {
				i++;
				j++;
			}
		}

		if (i < lengthOfFirst - 1) {
			while (i < lengthOfFirst)
			{
				different.push_back(content1[i]);
				partOfFirst++;
				i++;
			}
		}
		else if (j < lengthOfSecond - 1) {
			while (j < lengthOfFirst)
			{
				different.push_back(content2[j]);
				partOfSecond++;
				j++;
			}
		}
	}
	else {
		for (int i = 0; i < lengthOfFirst; i++) {
			if (content1[i] != content2[i]) {
				different.push_back(content1[i]);
				different.push_back(content2[i]);

				partOfFirst++;
				partOfSecond++;
			}
		}
	}

	//����� � ����� ����
	ofstream result("result.txt", ios::binary);
	if (!result.is_open()) {
		cout << "������� �������� �����!" << endl;
	}
	else {
		char* rez = new char[partOfFirst + partOfSecond];//������ �� ����������
		for (int i = 0; i < partOfFirst + partOfSecond; i++) {
			rez[i] = different[i];
		}
		result.write(rez, partOfFirst + partOfSecond);
		result.close();
	}

	cout << partOfFirst << endl;
	cout << partOfSecond << endl;

	//��������� �������
	int sum = partOfFirst + partOfSecond;
	int persentFirst = (float)partOfFirst * 100 / sum;
	int persentSecond = (float)partOfSecond * 100 / sum;

	cout << "³������ ������� �����: " << persentFirst << endl;
	cout << "³������ ������� �����: " << persentSecond << endl;

	delete[]content1;
	delete[]content2;

	file[0].close();
	file[1].close();

	return 0;
}
