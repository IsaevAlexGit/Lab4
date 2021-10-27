#include <string>
#include <iostream>

#include "FlightSchedule.h"
using namespace std;

int main() {
	bool exceptCought = false;
	setlocale(0, "Russian");
	FlightSchedule fs;

	int answMode;
	cout << "����� ������ (0 - vector, 1 - map): ";
	cin >> answMode;
	if (answMode > 1) cout << "��� ������ ������ ������!" << endl;
	fs.setWorkMode(answMode);

	string ifName = "input.txt";
	cout << "������� �������� ����� �����: ";
	//cin >> ifName;
	try {
		fs.readDataFromFile(ifName);
	}
	catch (exception* e) {
		cout << e;
		system("pause");
		exceptCought = true;
	}
	if (exceptCought) return 0;

	string depDate, dstPoint;
	cout << "������� ���� ����������� � ����� ���������� ����� ����� ������: ";
	cin >> depDate >> dstPoint;

	fs.printInfoForDepDate(depDate, dstPoint);
	system("pause");
	return 0;
}