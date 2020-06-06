#include "courses.h"

void get_No(ifstream& in, Node*& p, char a[]) {
	p->schedule = new schedule;
	in >> p->schedule->no;
}

void get_CourseID(ifstream& in, Node*& p, char a[]) {
	in.ignore();
	in.get(a, 200, '\n');
	p->schedule->courseID = new char[strlen(a) + 1];
	strcpy(p->schedule->courseID, a);
}

void get_CourseName(ifstream& in, Node*& p, char a[]) {
	in.ignore();
	in.get(a, 200, '\n');
	p->schedule->courseName = new char[strlen(a) + 1];
	strcpy(p->schedule->courseName, a);
}

void get_ClassName(ifstream& in, Node*& p, char a[]) {
	in.ignore();
	in.get(a, 200, '\n');
	p->schedule->Class = new char[strlen(a) + 1];
	strcpy(p->schedule->Class, a);
}

void get_LecUserName(ifstream& in, Node*& p, char a[]) {
	p->schedule->lec = new lecture;
	in.ignore();
	in.get(a, 200, '\n');
	p->schedule->lec->account = new char[strlen(a) + 1];
	strcpy(p->schedule->lec->account, a);
}

void get_LecName(ifstream& in, Node*& p, char a[]) {
	in.ignore();
	in.get(a, 200, '\n');
	p->schedule->lec->name = new char[strlen(a) + 1];
	strcpy(p->schedule->lec->name, a);
}

void get_LecGender(ifstream& in, Node*& p, char a[]) {
	in.ignore();
	in.get(a, 200, '\n');
	p->schedule->lec->gender = ston(a);
}

void get_Sdate(ifstream& in, Node*& p, char a[]) {
	//start day month year
	in.ignore();
	in.get(a, 200, '\n');
	p->schedule->Sdate.day = ston(a);

	in.ignore();
	in.get(a, 200, '\n');
	p->schedule->Sdate.month = ston(a);

	in.ignore();
	in.get(a, 200, '\n');
	p->schedule->Sdate.year = ston(a);
}

void get_Edate(ifstream& in, Node*& p, char a[]) {
	//start day month year
	in.ignore();
	in.get(a, 200, '\n');
	p->schedule->Edate.day = ston(a);

	in.ignore();
	in.get(a, 200, '\n');
	p->schedule->Edate.month = ston(a);

	in.ignore();
	in.get(a, 200, '\n');
	p->schedule->Edate.year = ston(a);
}

void get_DayOfWeek(ifstream& in, Node*& p, char a[]) {
	in.ignore();
	in.get(a, 200, '\n');
	p->schedule->dayofweek = new char[strlen(a) + 1];
	strcpy(p->schedule->dayofweek, a);
}

void get_STime(ifstream& in, Node*& p, char a[]) {
	//start time hour and min
	in.ignore();
	in.get(a, 200, '\n');
	p->schedule->Stime.hours = ston(a);

	in.ignore();
	in.get(a, 200, '\n');
	p->schedule->Stime.mins = ston(a);
}

void get_ETime(ifstream& in, Node*& p, char a[]) {
	//end time hour and min
	in.ignore();
	in.get(a, 200, '\n');
	p->schedule->Etime.hours = ston(a);

	in.ignore();
	in.get(a, 200, '\n');
	p->schedule->Etime.mins = ston(a);
}

void get_Room(ifstream& in, Node*& p, char a[]) {
	in.ignore();
	in.get(a, 100, '\n');
	p->schedule->room = new char[strlen(a) + 1];
	strcpy(p->schedule->room, a);
	in.ignore(1000, '\n');
}

void delete_ScheduleNode(Node*& phead)
{
	Node* pcur = phead;
	while (phead) {
		pcur = pcur->next;
		delete[] phead->schedule->courseID;
		delete[] phead->schedule->courseName;
		delete[] phead->schedule->Class;
		delete[] phead->schedule->lec->account;
		delete[] phead->schedule->lec->name;
		delete[] phead->schedule->dayofweek;
		delete[] phead->schedule->room;
		delete phead->schedule->lec;
		delete phead->schedule;
		delete phead;
		phead = pcur;
	}
}

void print_Schedule(Node* pHead)
{
	system("cls");
	cout << setw(5) << left << "No";
	cout << setw(15) << left << "Course ID";
	cout << setw(40) << left << "Course name";
	cout << setw(30) << left << "Lecturer Name";
	cout << setw(15) << left << "Start Date";
	cout << setw(15) << left << "End Date";
	cout << setw(20) << left << "Date of Week";
	cout << setw(15) << left << "Start time";
	cout << setw(15) << left << "End time";
	cout << setw(10) << left << "Room" << endl;
	cout << setfill('-');
	cout << setw(180) << "-" << endl;
	cout << setfill(' ');

	while (pHead != nullptr) {
		cout << setw(5) << left << pHead->schedule->no;
		cout << setw(15) << left << pHead->schedule->courseID;
		cout << setw(40) << left << pHead->schedule->courseName;
		cout << setw(30) << left << pHead->schedule->lec->name;
		cout << pHead->schedule->Sdate.day << "/" << pHead->schedule->Sdate.month << "/";
		cout << setw(10) << left << pHead->schedule->Sdate.year;
		cout << pHead->schedule->Edate.day << "/" << pHead->schedule->Edate.month << "/";
		cout << setw(10) << left << pHead->schedule->Edate.year;
		cout << setw(20) << left << pHead->schedule->dayofweek;

		if (pHead->schedule->Stime.hours < 10)
			cout << "0" << pHead->schedule->Stime.hours << ":";
		else
			cout << pHead->schedule->Stime.hours << ":";
		cout << setw(12) << left << pHead->schedule->Stime.mins;

		if (pHead->schedule->Etime.hours < 10)
			cout << "0" << pHead->schedule->Etime.hours << ":";
		else
			cout << pHead->schedule->Etime.hours << ":";
		cout << setw(12) << left << pHead->schedule->Etime.mins;

		cout << setw(10) << left << pHead->schedule->room << endl;
		pHead = pHead->next;
	}
	cout << endl;
	delete_ScheduleNode(pHead);
}
void output_Schedule(char year[], char semester[], char className[])
{
	char dirD[] = "D:\\Github\\CS162-19CTT1-19125059\\ZPMS\\";
	char v[500] = "";
	strcat(v, dirD);
	strcat(v, year);
	strcat(v, "\\");
	strcat(v, semester);
	strcat(v, "\\");
	strcat(v, className);
	strcat(v, "\\");
	strcat(v, "Schedule.txt");

	Node* pHead = nullptr;
	get_Schedule(v, pHead);
	print_Schedule(pHead);
}

void get_Schedule(char v[], Node*& pHead)
{
	system("cls");
	Node* pcur = pHead;
	ifstream fin;
	fin.open(v);
	while (true) {
		char a[200];
		if (pHead == nullptr) {
			pHead = new Node;
			get_No(fin, pHead, a);
			get_CourseID(fin, pHead, a);
			get_CourseName(fin, pHead, a);
			get_ClassName(fin, pHead, a);
			get_LecUserName(fin, pHead, a);
			get_LecName(fin, pHead, a);
			get_LecGender(fin, pHead, a);
			get_Sdate(fin, pHead, a);
			get_Edate(fin, pHead, a);
			get_DayOfWeek(fin, pHead, a);
			get_STime(fin, pHead, a);
			get_ETime(fin, pHead, a);
			get_Room(fin, pHead, a);

			pHead->next = nullptr;
			pcur = pHead;
		}
		else {
			pcur->next = new Node;
			pcur = pcur->next;

			get_No(fin, pcur, a);
			get_CourseID(fin, pcur, a);
			get_CourseName(fin, pcur, a);
			get_ClassName(fin, pcur, a);
			get_LecUserName(fin, pcur, a);
			get_LecName(fin, pcur, a);
			get_LecGender(fin, pcur, a);
			get_Sdate(fin, pcur, a);
			get_Edate(fin, pcur, a);
			get_DayOfWeek(fin, pcur, a);
			get_STime(fin, pcur, a);
			get_ETime(fin, pcur, a);
			get_Room(fin, pcur, a);

			pcur->next = nullptr;
		}
		if (fin.eof())
			break;
	}

	fin.close();
}

void input_YSC(char year[], char semester[], char className[]) {
	//year
	ifstream in;
	in.open("D:/Github/CS162-19CTT1-19125059/ZPMS/year.txt");
	if (!in.is_open()) {
		cout << "Error at inputYSC\n";
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

	//semester
	char fileAdd[499] = {};
	strcat(fileAdd, "D:/Github/CS162-19CTT1-19125059/ZPMS/");
	strcat(fileAdd, year);
	strcat(fileAdd, "/");
	strcat(fileAdd, "semester.txt");

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
		cout << "semester: " << semester << endl;
	}
	in.close();

	//class
	char fileAdd1[500] = {};
	strcat(fileAdd1, "D:/Github/CS162-19CTT1-19125059/ZPMS/");
	strcat(fileAdd1, year);
	strcat(fileAdd1, "/");
	strcat(fileAdd1, semester);
	strcat(fileAdd1, "/");
	strcat(fileAdd1, "class.txt");
	in.open(fileAdd1);

	if (!in.is_open()) {
		cout << "Error opening\n";
		return;
	}
	else {
		char a[20];
		system("cls");
		int n;
		in >> n;
		for (int i = 0; i < n; i++) {
			in.ignore(20, '\n');
			in.get(a, 20, '\n');
			cout << "[" << i + 1 << "]. " << a << '\n';
		}
		cout << "==================\n";
		cout << "Please input class: ";
		cin.ignore(20, '\n');
		cin.get(className, 20, '\n');
	}
	in.close();
	return;
}

void view_Courses()
{
	char year[20];
	char semester[10];
	char className[10];
	input_YSC(year, semester, className);
	output_Schedule(year, semester, className);
	system("pause");
}