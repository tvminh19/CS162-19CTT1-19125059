#include "header.h"
#include "allroles.h"
#include "class.h"

void displayClassList()
{
	char year[30], semester[11], className[30];
	ifstream in;
	in.open("D:/Github/CS162-19CTT1-19125059/ZPMS/Year.txt");
	if (!in.is_open()) {
		cout << "Can't open Year.txt!\n";
		return;
	}
	else {
		system("cls");
		cout << "==== LIST ====\n";
		char a[20];
		int n;
		in >> n;
		for (int i = 0; i < n; ++i) {
			in.ignore(100, '\n');
			in.get(a, 20, '\n');
			cout << "[" << i + 1 << "]. " << a << '\n';
		}
		cout << "==================\n";
		cout << "Please input year: ";
		cin.ignore(100, '\n');
		cin.get(year, 20, '\n');
	}

	in.close();

	if (!isExistYear(year)) {
		system("cls");
		cout << "Wrong!, Please enter again !\n";
		return inputYSC(year, semester, className);
	}

	//semester
	char fileAdd[499] = {""};
	strcat(fileAdd, "D:/Github/CS162-19CTT1-19125059/ZPMS/");
	strcat(fileAdd, year);
	strcat(fileAdd, "/");
	strcat(fileAdd, "Semester.txt");

	in.open(fileAdd);
	if (!in.is_open()) {
		cout << "Error at input semester\n";
		return;
	}
	else {
		char a[20];
		system("cls");
		cout << "==== LIST ====\n";
		int n;
		in >> n;
		in.ignore(20, '\n');
		for (int i = 0; i < n; ++i) {
			in.get(a, 20, '\n');
			in.ignore(20, '\n');
			cout << "[" << i + 1 << "]. " << a << '\n';
		}
		cout << "==================\n";
		cout << "Please input semester: ";
		cin.ignore(10, '\n');
		cin.get(semester, 10, '\n');
	}
	in.close();

	if (!isExistSem(year, semester)) {
		system("cls");
		cout << "Wrong!, Please enter again !\n";
		return inputYSC(year, semester, className);
	}

	char fileAdd1[500] = {};
	strcat(fileAdd1, "D:/Github/CS162-19CTT1-19125059/ZPMS/");
	strcat(fileAdd1, year);
	strcat(fileAdd1, "/");
	strcat(fileAdd1, semester);
	strcat(fileAdd1, "/");
	strcat(fileAdd1, "Class.txt");
	in.open(fileAdd1);

	if (!in.is_open()) {
		cout << "Error opening\n";
		return;
	}
	else {
		char a[30];
		system("cls");
		int n;
		in >> n;
		cout << "====== LIST OF CLASSES ======\n";
		for (int i = 0; i < n; i++) {
			in.ignore(20, '\n');
			in.get(a, 20, '\n');
			cout << "[" << i + 1 << "]. " << a << '\n';
		}
		system("pause");
	}
	in.close();
	return;
}