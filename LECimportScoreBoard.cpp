#include "lecturer.h"

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

void get_stu_ID(ifstream& in, Node*& p, char a[])
{
	in.ignore(200, ',');
	in.get(a, 200, ',');
	p->scb->stu->account = new char[strlen(a) + 1];
	strcpy(p->scb->stu->account, a);
}

void get_stu_name(ifstream& in, Node*& p, char a[])
{
	in.ignore(200, ',');
	in.get(a, 200, ',');
	p->stu->name = new char[strlen(a) + 1];
	strcpy(p->stu->name, a);
}

void get_midterm(ifstream& in, Node*& p)
{
	in.ignore(200, ',');
	in >> p->scb->sco->midterm;
}

void get_final(ifstream& in, Node*& p)
{
	in.ignore(200, ',');
	in >> p->scb->sco->final;
}

void get_bonus(ifstream& in, Node*& p)
{
	in.ignore(200, ',');
	in >> p->scb->sco->bonus;
}

void get_total(ifstream& in, Node*& p)
{
	in.ignore(200, ',');
	in >> p->scb->sco->total;
}

void get_scoreborad(char* b, Node*& pHead)
{
	ifstream fin;
	fin.open(b);
	cin.ignore(500, '\n');
	Node* cur = pHead;

	while (!fin.eof()) {
		char a[100];
		if (pHead == nullptr) {
			get_No(fin, pHead, a);
			pHead->scb = new scoreboard;
			pHead->scb->stu = new student;
			get_stu_ID(fin, pHead, a);
			get_stu_name(fin, pHead, a);
			pHead->scb->sco = new score;
			get_midterm(fin, pHead);
			get_final(fin, pHead);
			get_bonus(fin, pHead);
			get_total(fin, pHead);
			fin.ignore(100, '\n');
		}
		else {
			cur->next = new Node;
			cur = cur->next;

			get_No(fin, cur, a);
			cur->scb = new scoreboard;
			cur->scb->stu = new student;
			get_stu_ID(fin, cur, a);
			get_stu_name(fin, cur, a);
			cur->scb->sco = new score;
			get_midterm(fin, cur);
			get_final(fin, cur);
			get_bonus(fin, cur);
			get_total(fin, cur);
			fin.ignore(100, '\n');
		}
	}

	fin.close();
}
/*
void delete_S_B(Node*& pHead)
{
	Node* cur = pHead;
	while (pHead != nullptr) {
		pHead = pHead->next;
		delete[] cur->scb->stu->account;
		delete[] cur->scb->stu->name;
		delete cur->scb->sco;
		delete cur->scb->stu;
		delete cur->scb;
		cur = pHead;
	}
}
*/
void import_scoreboard()
{
	char year[20];
	char semester[10];
	char className[10];
	input_YSC(year, semester, className);

	char* b = nullptr;
	inputFile_Address(b);
	Node* pHead = nullptr;
	get_scoreborad(b, pHead);

	delete[] b;
	//delete_S_B(pHead);
}