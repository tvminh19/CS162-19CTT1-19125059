#include "header.h"
#include "courses.h"
#include "students.h"
#include "staff.h"

//view checkin result
void StuViewCheckin() {
	//set variable
	char year[20], semester[20], className[20];
	char fileAdd[500] = {};
	Node* phead = nullptr;
	Node* pcur = nullptr;

	//to know year and semester
	Date a = getTimeNow();
	toKnowSemAndYear(a, year, semester);

	//course it not open
	if (!isExistSem(year, semester)) {
		system("cls");
		cout << "Semester is not update! Please tell staff.\n";
		system("pause");
		return;
	}

	//safe
	if (strcmp(semester, "0") == 0) {
		cout << "You can not view schedule now !\n";
		system("pause");
		return;
	}

	//input class
	inputC(year, semester, className);

	//make file address
	makeClassAdd(year, semester, className, fileAdd);

	//load file
	loadCourseEdit(year, semester, className, fileAdd, phead, pcur);

	//show to view
	print_Schedule(phead);

	//clean heap memory
	cleanScheduleNode(phead);

	system("pause");
	system("cls");
	cout << "Do you want to see more ? (1/0)\n";
	cout << "> ";
	int choose;
	cin >> choose;
	if (choose == 1)
		return StuViewCheckin();
	else {
		return;
	}
}