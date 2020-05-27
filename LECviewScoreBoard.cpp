#include "lecturer.h"

void get_stuaccount(ifstream& in, Node*& p, char a[])
{
	in.ignore(100, '\n');
	in.get(a, 200, '\n');
	p->scb->stu->account = new char[strlen(a) + 1];
	strcpy(p->scb->stu->account, a);
}
void get_stuname(ifstream& in, Node*& p, char a[])
{
	in.ignore(100, '\n');
	in.get(a, 200, '\n');
	p->scb->stu->name = new char[strlen(a) + 1];
	strcpy(p->scb->stu->name, a);
}

void get_Midterm(ifstream& in, Node*& p)
{
	in.ignore(200, '\n');
	in >> p->scb->sco->midterm;
}

void get_Final(ifstream& in, Node*& p)
{
	in.ignore(200, '\n');
	in >> p->scb->sco->final;
}

void get_Bonus(ifstream& in, Node*& p)
{
	in.ignore(200, '\n');
	in >> p->scb->sco->bonus;
}

void get_Total(ifstream& in, Node*& p)
{
	in.ignore(200, '\n');
	in >> p->scb->sco->total;
}

void get_S_B(char v[], Node*& pHead1)
{
	ifstream fin;
	fin.open(v);
	int n;
	fin.ignore(200, '\n');
	fin >> n;

	Node* cur = pHead1;
	for (int i = 0; i < n; ++i) {
		char a[100];
		if (pHead1 == nullptr) {
			pHead1 = new Node;
			pHead1->scb = new scoreboard;
			pHead1->scb->stu = new student;
			get_stuaccount(fin, pHead1, a);
			fin.ignore(100, '\n');
			get_stuname(fin, pHead1, a);
			fin.ignore(100, '\n');
			fin.ignore(100, '\n');
			pHead1->scb->sco = new score;
			get_Midterm(fin, pHead1);
			get_Final(fin, pHead1);
			get_Bonus(fin, pHead1);
			get_Total(fin, pHead1);
			for (int j = 0; j < 10; ++j)
				fin.ignore(100, '\n');
			cur = pHead1;
			cur->next = nullptr;
		}
		else {
			cur->next = new Node;
			cur = cur->next;

			cur->scb = new scoreboard;
			cur->scb->stu = new student;
			get_stuaccount(fin, cur, a);
			fin.ignore(100, '\n');
			get_stuname(fin, cur, a);
			fin.ignore(100, '\n');
			fin.ignore(100, '\n');
			cur->scb->sco = new score;
			get_Midterm(fin, cur);
			get_Final(fin, cur);
			get_Bonus(fin, cur);
			get_Total(fin, cur);
			for (int j = 0; j < 10; ++j)
				fin.ignore(100, '\n');
			cur->next = nullptr;
		}
	}
	fin.close();
}

void print_S_B(Node* pHead1)
{
	system("cls");
	int t = 0;
	cout << setw(5) << left << "No";
	cout << setw(15) << left << "ID";
	cout << setw(30) << left << "Student Name";
	cout << setw(10) << left << "Midterm";
	cout << setw(10) << left << "Final";
	cout << setw(10) << left << "Bonus";
	cout << setw(10) << left << "Total" << endl;
	cout << setfill('-');
	cout << setw(90) << "-" << endl;
	cout << setfill(' ');

	Node* cur = pHead1;
	while (cur != nullptr) {
		t += 1;
		cout << setw(5) << left << t;
		cout << setw(15) << left << cur->scb->stu->account;
		cout << setw(30) << left << cur->scb->stu->name;
		cout << setw(10) << left << cur->scb->sco->midterm;
		cout << setw(10) << left << cur->scb->sco->final;
		cout << setw(10) << left << cur->scb->sco->bonus;
		cout << setw(10) << left << cur->scb->sco->total << endl;
		cur = cur->next;
	}
	cout << endl;
}

void Stu_S_B(Node*& pHead1, char year[], char semester[], char className[])
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

	get_S_B(v, pHead1);
	print_S_B(pHead1);
}

void view_scoreboard()
{
	char year[20];
	char semester[10];
	char className[10];
	input_YSC(year, semester, className);
	Node* pHead = nullptr;
	show_course(pHead, year, semester, className);
	delete_ScheduleNode(pHead);

	Node* pHead1 = nullptr;
	Stu_S_B(pHead1, year, semester, className);
	delete_S_B(pHead1);
	system("pause");
}