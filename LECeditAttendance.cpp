#include "header.h"
#include "staff.h"
#include "courses.h"


// edit attendance
void editAttendance() {
	//set variable
	char year[20], semester[20], className[20];
	char fileAdd[500] = {};
	Node* phead = nullptr;
	Node* pcur = nullptr;
	Date root;
	Time Stime, Etime;

	//input year semester class course
	inputYSC(year, semester, className);

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

	//clean heap memory
	cleanScheduleNode(phead);

	//open and load to struct
	int numStu;
	loadCourseFile(fileAdd, phead, root, Stime, Etime, numStu);

	//ask num of week and show attendance list
	askNumAndEdit(phead, root, Stime, Etime, numStu);

	//update attendance list
	updateCourse(fileAdd, phead, root, Stime, Etime, numStu);

	//clean heap memory
	cleanScoreBoard(phead);
}

void askNumAndEdit(Node* phead, Date root, Time Stime, Time Etime, int numStu) {
	//ask num of week
	int now;
	now = numOfWeek();

	//show attendance list
	editAttendanceList(now, phead, root, Stime, Etime, numStu);

	cout << "\nDo you want to edit more: (1/0): ";
	int choose;
	cin >> choose;
	if (choose == 1)
		return askNumAndEdit(phead, root, Stime, Etime, numStu);
}

void editAttendanceList(int numOfWeek, Node* phead, Date root, Time Stime, Time Etime, int numStu) {
	Node* pcur = phead;
	system("cls");
	cout << "=== WEEK " << numOfWeek << " ===\n";
	cout << "=== " << root.day << "/" << root.month << "/" << root.year << " ===\n";
	for (int i = 0; i < numStu; ++i) {
		cout << "[" << i << "]. " << phead->scb->stu->name << " ->            ";
		if (phead->scb->went2class[numOfWeek] == 1)
			cout << "YES.\n";
		else
			cout << "NO.\n";
		phead = phead->next;
	}
	cout << "========================\n";

	int id, choice;
	cout << "Which attendance do you want to edit? (0 to " << numStu - 1 << "): ";
	cin >> id;
	cout << "[0]. Absent\n[1]. Attended\nYour choice (0 or 1): ";
	cin >> choice;
	while (choice != 0 && choice != 1)
	{
		cout << "Enter again!\n";
		cin >> choice;
	}

	for (int i = 0; i < id; ++i)
		pcur = pcur->next;
	if (pcur != nullptr)
		pcur->scb->went2class[numOfWeek] = choice;

	introDone();
}
