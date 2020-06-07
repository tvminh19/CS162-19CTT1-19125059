#include "header.h"
#include "courses.h"
#include "students.h"
#include "staff.h"

//add in4 stu
void addStu(Node*& phead) {
	Node* tmp = new Node;
	tmp->scb = new scoreboard;
	tmp->scb->stu = new student;

	char a[200];
	cout << "Student ID: ";
	cin.ignore(100, '\n');
	cin.get(a, 100, '\n');
	tmp->scb->stu->account = new char[strlen(a) + 1];
	strcpy(tmp->scb->stu->account, a);

	//pass
	tmp->scb->stu->password = new char[10];
	strcpy(tmp->scb->stu->password, "xxxxxxx");

	//student name
	cout << "Student Name: ";
	cin.ignore(100, '\n');
	cin.get(a, 100, '\n');
	tmp->scb->stu->name = new char[strlen(a) + 1];
	strcpy(tmp->scb->stu->name, a);

	//dob
	cout << "Student Dob: ";
	cin.ignore(100, '\n');
	cin.get(a, 100, '\n');
	tmp->scb->stu->dob = new char[strlen(a) + 1];
	strcpy(tmp->scb->stu->dob, a);

	//is active?
	tmp->scb->isActive = 1;

	//score
	tmp->scb->sco = new score;

	tmp->scb->sco->midterm = 0;
	tmp->scb->sco->final = 0;
	tmp->scb->sco->bonus = 0;
	tmp->scb->sco->total = 0;

	//check attendance
	for (int i = 0; i < 10; ++i) {
		tmp->scb->went2class[i] = 0;
	}

	//
	tmp->next = phead;
	phead = tmp;
}

//add student to course
void addStuToCo() {
	//set variable
	char year[20], semester[20], className[20];
	char fileAdd[500] = {};
	Node* phead = nullptr;
	Node* pcur = nullptr;
	Date root;
	Time Stime, Etime;

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

	//view student
	viewstu(phead);

	//input student
	addStu(phead);

	//update
	numStu++;
	updateCourse(fileAdd, phead, root, Stime, Etime, numStu);

	//clean heap memory
	cleanScoreBoard(phead);

	introDone();
}