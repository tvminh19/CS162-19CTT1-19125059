#include "header.h"
#include "courses.h"
#include "students.h"
#include "staff.h"

void outResult(char fileAdd[], Node* phead, char id[], Date root) {
	while (phead) {
		if (isSameStr(id, phead->scb->stu->account)) {
			system("cls");
			for (int i = 0; i < 10; ++i) {
				cout << "[" << i << "]. ";
				Date a = dateOfWeek(root, i);
				cout << " " << a.day << "/" << a.month << "/" << a.year << "   =>  ";
				if (phead->scb->went2class[i] == 1)
					cout << "ATTENDED!\n";
				else
					cout << "NOT ATTENDED!.\n";
			}
		}
		phead = phead->next;
	}
	system("pause");
}

//check
bool checkView(Node*& phead, char id[], Date root) {
	//
	Date now = getTimeNow();

	//safe date
	if (ABcompare(root, now) == 1) {
		cout << "You don't have permission NOW!\n";
		return false;
	}

	//numofweek
	int NumOfWeek = numOfStuWeek(root, now);
	//safe week
	if (NumOfWeek >= 10 or NumOfWeek == -1) {
		cout << "You don't have permission NOW!\n";
		return false;
	}

	return true;
}

//view checkin result
void StuViewCheckin(char id[]) {
	//set variable
	char year[20], semester[20], className[20];
	char fileAdd[500] = {};
	Node* phead = nullptr;
	Node* pcur = nullptr;
	Date root;
	Time Stime, Etime;

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
		cout << "You can not checkin now !\n";
		system("pause");
		return;
	}

	//input class
	inputC(year, semester, className);

	//make file address
	makeClassAdd(year, semester, className, fileAdd);

	//load file
	loadCourseEdit(year, semester, className, fileAdd, phead, pcur);

	//show to edit
	print_Schedule(phead);

	//ask and edit
	char course[20] = {};
	askCourse(phead, course);

	//make dir to course
	strcpy(fileAdd, courseDir(year, semester, className, course));

	//safe
	ifstream in(fileAdd);
	if (!in.is_open()) {
		system("cls");
		cleanScheduleNode(phead);
		cout << "Database of course is not exist!\n";
		system("pause");
		return;
	}

	//clean heap memory
	cleanScheduleNode(phead);

	//open and load to struct
	int numStu;
	loadCourseFile(fileAdd, phead, root, Stime, Etime, numStu);

	//check
	if (!checkView(phead, id, root)) {
		system("pause");
		cleanScoreBoard(phead);
		return;
	}

	//update
	outResult(fileAdd, phead, id, root);

	//clean heap memory
	cleanScoreBoard(phead);
}
