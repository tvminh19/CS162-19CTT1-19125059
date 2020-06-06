#include "lecturer.h"
#include "courses.h"
#include "staff.h"

void inputFile_Address(char*& b)
{
	char d[200];
	cout << "Input file address: ";
	cin.ignore();
	cin.get(d, 200, '\n');
	b = new char[strlen(d) + 1];
	strcpy(b, d);
	ifstream fin;
	fin.open(b);
	if (!fin.is_open()) {
		cout << "Wrong file address!!" << endl;
		delete[] b;
		inputFile_Address(b);
	}
	else {
		introDone();
	}
	fin.close();
}

void change_scoreboard(char* b, Node*& pHead)
{
	ifstream fin;
	fin.open(b);
	cin.ignore(500, '\n');
	Node* cur = pHead;

	while (!fin.eof()) {
		fin.ignore(500, '\n');
		fin.ignore(100, ',');
		fin.ignore(100, ',');
		fin.ignore(100, ',');

		fin >> cur->scb->sco->midterm;
		fin.ignore(100, ',');
		fin >> cur->scb->sco->final;
		fin.ignore(100, ',');
		fin >> cur->scb->sco->bonus;
		fin.ignore(100, ',');
		fin >> cur->scb->sco->total;

		cur = cur->next;
	}
	fin.close();
}

void choose_course(Node*& pHead1, char year[], char semester[], char className[], char v[])
{
	cout << endl << "Input your choice (course) > ";
	char c[100];
	cin.ignore();
	cin.get(c, 100, '\n');
	char* course = new char[strlen(c) + 1];
	strcpy(course, c);

	char dirD[] = "D:\\Github\\CS162-19CTT1-19125059\\ZPMS\\";

	strcat(v, dirD);
	strcat(v, year);
	strcat(v, "\\");
	strcat(v, semester);
	strcat(v, "\\");
	strcat(v, className);
	strcat(v, "\\");
	strcat(v, course);
	strcat(v, ".txt");

}

void import_scoreboard()
{
	char year[20], semester[20], className[20];
	char fileAdd[500] = {};
	Node* phead = nullptr;
	Node* pcur = nullptr;
	Date root;
	Time Stime, Etime;
	input_YSC(year, semester, className);

	Node* pHead = nullptr;
	show_course(pHead, year, semester, className);
	delete_ScheduleNode(pHead);

	Node* pHead1 = nullptr;
	char v[500] = "";
	choose_course(pHead1, year, semester, className, v);
	int numStu;
	loadCourseFile(v, pHead1, root, Stime, Etime, numStu);

	char* b = nullptr;
	inputFile_Address(b);
	change_scoreboard(b, pHead1);
	updateCourse(v, pHead1, root, Stime, Etime, numStu);

	delete[] b;
	cleanScoreBoard(pHead1);
}