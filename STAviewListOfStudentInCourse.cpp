#include "courses.h"

void get_StuID(ifstream& in, Node*& p, char a[])
{
	in.ignore(100, '\n');
	in.get(a, 200, '\n');
	p->stu->account = new char[strlen(a) + 1];
	strcpy(p->stu->account, a);
}

void get_StuName(ifstream& in, Node*& p, char a[])
{
	in.ignore(100, '\n');
	in.get(a, 200, '\n');
	p->stu->name = new char[strlen(a) + 1];
	strcpy(p->stu->name, a);
}

void get_student_course(char v[], Node*& pHead1)
{
	ifstream fin;
	fin.open(v);
	int n;
	fin.ignore(100, '\n');
	fin >> n;

	Node* cur = pHead1;
	for (int i = 0; i < n; ++i) {
		char a[200];
		if (pHead1 == nullptr) {
			pHead1 = new Node;
			pHead1->stu = new student;
			get_StuID(fin, pHead1, a);
			fin.ignore(100, '\n');
			get_StuName(fin, pHead1, a);
			fin.ignore(100, '\n');
			fin.ignore(100, '\n');
			fin >> pHead1->stu->isActive;
			for (int j = 1; j <= 14; ++j)
				fin.ignore(100, '\n');
			cur = pHead1;
			cur->next = nullptr;
		}
		else {
			cur->next = new Node;
			cur = cur->next;
			cur->stu = new student;
			get_StuID(fin, cur, a);
			fin.ignore(100, '\n');
			get_StuName(fin, cur, a);
			fin.ignore(100, '\n');
			fin.ignore(100, '\n');
			fin >> cur->stu->isActive;
			for (int j = 1; j <= 14; ++j)
				fin.ignore(100, '\n');
			cur->next = nullptr;
		}
	}
	fin.close();
}

void print_S_C(Node* pHead1)
{
	system("cls");
	int t = 0;
	cout << setw(5) << left << "No";
	cout << setw(15) << left << "ID";
	cout << setw(30) << left << "Student Name" << endl;
	cout << setfill('-');
	cout << setw(40) << "-" << endl;
	cout << setfill(' ');

	while (pHead1 != nullptr) {
		if (pHead1->stu->isActive == 1) {
			t += 1;
			cout << setw(5) << left << t;
			cout << setw(15) << left << pHead1->stu->account;
			cout << setw(30) << left << pHead1->stu->name << endl;
		}
		pHead1 = pHead1->next;
	}
	cout << endl;
}

void student_course(Node*& pHead1, char year[], char semester[], char className[])
{
	cout << endl << "Input your choice (course) > ";
	char c[100];
	cin.ignore();
	cin.get(c, 100, '\n');
	char* course = new char[strlen(c) + 1];
	strcpy(course, c);

	char dirD[] = "D:\\Github\\CS162-19CTT1-19125059\\ZPMS\\";
	char v[500] = "";
	strcat(v, dirD);
	strcat(v, year);
	strcat(v, "\\");
	strcat(v, semester);
	strcat(v, "\\");
	strcat(v, className);
	strcat(v, "\\");
	strcat(v, course);
	strcat(v, ".txt");

	get_student_course(v, pHead1);
	print_S_C(pHead1);
	delete[] course;
}

void show_schedule(Node* pHead)
{
	int t = 0;
	cout << "=== Courses ===" << endl;
	while (pHead != nullptr) {
		t += 1;
		cout << "[" << t << "]. " << pHead->schedule->courseID << endl;
		pHead = pHead->next;
	}
}

void show_course(Node*& pHead, char year[], char semester[], char className[])
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

	get_Schedule(v, pHead);
	show_schedule(pHead);
}

void delete_S_C(Node*& pHead1)
{
	Node* cur = pHead1;
	while (pHead1 != nullptr) {
		pHead1 = pHead1->next;
		delete[] cur->stu->account;
		delete[] cur->stu->name;
		delete cur->stu;
		delete cur;
		cur = pHead1;
	}
}

void view_Student()
{
	char year[20];
	char semester[10];
	char className[10];
	input_YSC(year, semester, className);
	Node* pHead = nullptr;
	show_course(pHead, year, semester, className);
	delete_ScheduleNode(pHead);

	Node* pHead1 = nullptr;
	student_course(pHead1, year, semester, className);
	delete_S_C(pHead1);
	system("pause");
}