#include "header.h"
#include "courses.h"

//load node 
void loadNodeEdit(Node*& phead, Node*& pcur, char fileAdd[]) {
	char a[50];
	ifstream in(fileAdd);
	while (!in.eof()) {
		if (!phead) {
			phead = new Node;
			//data
			//#no
			phead->schedule = new schedule;

			in >> phead->schedule->no;

			//course id
			in.ignore(50, '\n');
			in.get(a, 50, '\n');
			phead->schedule->courseID = new char[strlen(a) + 1];
			strcpy(phead->schedule->courseID, a);

			//course name
			in.ignore(50, '\n');
			in.get(a, 50, '\n');
			phead->schedule->courseName = new char[strlen(a) + 1];
			strcpy(phead->schedule->courseName, a);

			//class
			in.ignore(50, '\n');
			in.get(a, 50, '\n');
			phead->schedule->Class = new char[strlen(a) + 1];
			strcpy(phead->schedule->Class, a);

			phead->schedule->lec = new lecture;

			//lecture username
			in.ignore(50, '\n');
			in.get(a, 50, '\n');
			phead->schedule->lec->account = new char[strlen(a) + 1];
			strcpy(phead->schedule->lec->account, a);

			//lecture name
			in.ignore(50, '\n');
			in.get(a, 50, '\n');
			phead->schedule->lec->name = new char[strlen(a) + 1];
			strcpy(phead->schedule->lec->name, a);

			//lecturer gender
			in >> phead->schedule->lec->gender;

			//day month year start
			in >> phead->schedule->Sdate.day;
			in >> phead->schedule->Sdate.month;
			in >> phead->schedule->Sdate.year;

			//day month year end
			in >> phead->schedule->Edate.day;
			in >> phead->schedule->Edate.month;
			in >> phead->schedule->Edate.year;

			//day of week
			in.ignore(50, '\n');
			in.get(a, 50, '\n');
			phead->schedule->dayofweek = new char[strlen(a) + 1];
			strcpy(phead->schedule->dayofweek, a);

			//time start
			in >> phead->schedule->Stime.hours;
			in >> phead->schedule->Stime.mins;

			//time end
			in >> phead->schedule->Etime.hours;
			in >> phead->schedule->Etime.mins;

			//room
			in.ignore(50, '\n');
			in.get(a, 50, '\n');
			phead->schedule->room = new char[strlen(a) + 1];
			strcpy(phead->schedule->room, a);

			//update
			pcur = phead;
			phead->next = nullptr;
		}
		else {
			pcur->next = new Node;
			pcur = pcur->next;

			pcur->schedule = new schedule;
			//data
			//#no
			in >> pcur->schedule->no;

			//course id
			in.ignore(50, '\n');
			in.get(a, 50, '\n');
			pcur->schedule->courseID = new char[strlen(a) + 1];
			strcpy(pcur->schedule->courseID, a);

			//course name
			in.ignore(50, '\n');
			in.get(a, 50, '\n');
			pcur->schedule->courseName = new char[strlen(a) + 1];
			strcpy(pcur->schedule->courseName, a);

			//class
			in.ignore(50, '\n');
			in.get(a, 50, '\n');
			pcur->schedule->Class = new char[strlen(a) + 1];
			strcpy(pcur->schedule->Class, a);

			pcur->schedule->lec = new lecture;

			//lecture username
			in.ignore(50, '\n');
			in.get(a, 50, '\n');
			pcur->schedule->lec->account = new char[strlen(a) + 1];
			strcpy(pcur->schedule->lec->account, a);

			//lecture name
			in.ignore(50, '\n');
			in.get(a, 50, '\n');
			pcur->schedule->lec->name = new char[strlen(a) + 1];
			strcpy(pcur->schedule->lec->name, a);

			//lecturer gender
			in >> pcur->schedule->lec->gender;

			//day month year start
			in >> pcur->schedule->Sdate.day;
			in >> pcur->schedule->Sdate.month;
			in >> pcur->schedule->Sdate.year;

			//day month year end
			in >> pcur->schedule->Edate.day;
			in >> pcur->schedule->Edate.month;
			in >> pcur->schedule->Edate.year;

			//day of week
			in.ignore(50, '\n');
			in.get(a, 50, '\n');
			pcur->schedule->dayofweek = new char[strlen(a) + 1];
			strcpy(pcur->schedule->dayofweek, a);

			//time start
			in >> pcur->schedule->Stime.hours;
			in >> pcur->schedule->Stime.mins;

			//time end
			in >> pcur->schedule->Etime.hours;
			in >> pcur->schedule->Etime.mins;

			//room
			in.ignore(50, '\n');
			in.get(a, 50, '\n');
			pcur->schedule->room = new char[strlen(a) + 1];
			strcpy(pcur->schedule->room, a);

			//update
			pcur->next = nullptr;
		}
	}
}

//load file to edit
void loadCourseEdit(char year[], char semester[], char className[], char fileAdd[], Node*& phead, Node*& pcur) {
	ifstream in(fileAdd);
	if (!in.is_open()) {
		system("cls");
		cout << "Wrong please input again\n";
		system("pause");
		editcourse();
	}
	else {
		loadNodeEdit(phead, pcur, fileAdd);
	}
	in.close();
}

//edit course
void editCo(Node*& p) {
	char a[200];
	system("cls");
	cout << "=== EDIT ===\n";

	cout << "Course ID: ";
	cin.ignore(200, '\n');
	cin.get(a, 200, '\n');
	delete[] p->schedule->courseID;
	p->schedule->courseID = new char[strlen(a) + 1];
	strcpy(p->schedule->courseID, a);

	cout << "Course Name: ";
	cin.ignore(200, '\n');
	cin.get(a, 200, '\n');
	delete[] p->schedule->courseName;
	p->schedule->courseName = new char[strlen(a) + 1];
	strcpy(p->schedule->courseName, a);

	//p->schedule->lec = new lecture;

	cout << "Lecturer's username: ";
	cin.ignore(200, '\n');
	cin.get(a, 200, '\n');
	delete[] p->schedule->lec->account;
	p->schedule->lec->account = new char[strlen(a) + 1];
	strcpy(p->schedule->lec->account, a);

	cout << "Lecturer's Name: ";
	cin.ignore(200, '\n');
	cin.get(a, 200, '\n');
	delete[] p->schedule->lec->name;
	p->schedule->lec->name = new char[strlen(a) + 1];
	strcpy(p->schedule->lec->name, a);

	cout << "Gender: (1/0): ";
	cin >> p->schedule->lec->gender;

	cout << "Start day: ";
	cin >> p->schedule->Sdate.day;
	cout << "Start month: ";
	cin >> p->schedule->Sdate.month;
	cout << "Start year: ";
	cin >> p->schedule->Sdate.year;

	cout << "End day: ";
	cin >> p->schedule->Edate.day;
	cout << "End month: ";
	cin >> p->schedule->Edate.month;
	cout << "End year: ";
	cin >> p->schedule->Edate.year;

	cout << "Day of week: ";
	cin.ignore(200, '\n');
	cin.get(a, 200, '\n');
	delete[] p->schedule->dayofweek;
	p->schedule->dayofweek = new char[strlen(a) + 1];
	strcpy(p->schedule->dayofweek, a);

	cout << "start hour: ";
	cin >> p->schedule->Stime.hours;
	cout << "start minute: ";
	cin >> p->schedule->Stime.mins;

	cout << "End hour: ";
	cin >> p->schedule->Etime.hours;
	cout << "End minute: ";
	cin >> p->schedule->Etime.mins;

	cout << "Room: ";
	cin.ignore(200, '\n');
	cin.get(a, 200, '\n');
	delete[] p->schedule->room;
	p->schedule->room = new char[strlen(a) + 1];
	strcpy(p->schedule->room, a);
}

//ask no 
void askNo(Node*& phead) {
	//ask in4
	cout << "\n";
	cout << "> Please input #NO to edit: ";
	int no;
	cin >> no;

	//edit
	Node* pcur = phead;
	while (pcur) {
		if (pcur->schedule->no == no) {
			//edit
			editCo(pcur);
			exit(0);
		}
		pcur = pcur->next;
	}
	system("cls");
	print_Schedule(phead);
	cout << "\n";
	cout << "\nPlease input Again: ";
	askNo(phead);
}

//edit course
void editcourse() {
	//varriable
	char year[20], semester[20], className[20], fileAdd[500] = {};
	Node* phead = nullptr;
	Node* pcur = nullptr;


	//input year semester class
	inputYSC(year, semester, className);

	//make file add
	makeClassAdd(year, semester, className, fileAdd);

	//load file
	loadCourseEdit(year, semester, className, fileAdd, phead, pcur);

	//show to edit
	print_Schedule(phead);

	//ask and edit
	askNo(phead);

	//update
	outputSchedule(out, phead, year, semester, className);

	//clean
	cleanScheduleNode(phead);

	//show "OK"
	introDone();
}