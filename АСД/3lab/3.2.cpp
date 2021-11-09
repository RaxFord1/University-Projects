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
	// �������� ��� ������
	ofstream fin1("Z3.dat", ios::binary);
	if (!fin1.is_open()) { // ��������
		cout << "������� �������� �����!" << endl;
		return 1;
	}

	// ����� 8 ���� - ����� m
	fin1.write((char*)&m, sizeof(m));
	// ����� 8 ���� - ����� n
	fin1.write((char*)&n, sizeof(n));
	// ����� 4����*10 - ����� ������ arr1
	for (int i = 0; i < 10; i++) {
		fin1.write((char*)&arr1[i], sizeof(arr1[i]));
	}
	// ����� 1���� *3 - ����� ������ arr2
	for (int i = 0; i < 3; i++) {
		fin1.write((char*)&arr2[i], sizeof(arr2[i]));
	}
	fin1.close(); // �������� �����
	// �������� ��� �������
	ifstream fout("Z3.dat", ios::binary);
	if (!fout.is_open()) { // ��������
		cout << "������� �������� �����!" << endl;
		return 1;
	}
	fout.seekg(0, ios::end); // ������� � ����� �����
	// ������� ������� � ������, ������� �� �������
	long len = fout.tellg();
	cout << len << endl;
	fout.close(); // �������� �����
	// �������� ��� �������� � ����� �����
	ofstream fin2("Z3.dat", ios::binary | ios::app);
	if (!fin2.is_open()) {
		cout << " ������� �������� ����� !" << endl;
		return 1;
	}
	// ����� 4� - ����� len
	fin2.write((char*)&len, sizeof(len));
	fin2.close(); // �������� �����
	system("pause");
}