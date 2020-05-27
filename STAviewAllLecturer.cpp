#include "courses.h"

void get_password(ifstream& in, Node*& p, char a[])
{
	in.ignore();
	in.get(a, 200, '\n');
	p->schedule->lec->password = new char[strlen(a) + 1];
	strcpy(p->schedule->lec->password, a);
}

void get_academy(ifstream& in, Node*& p, char a[])
{
	in.ignore();
	in.get(a, 200, '\n');
	p->schedule->lec->academy = new char[strlen(a) + 1];
	strcpy(p->schedule->lec->academy, a);
}

void get_Lecturer(Node*& pHead)
{
	system("cls");

	ifstream fin;
	fin.open("D:\\Github\\CS162-19CTT1-19125059\\ZPMS\\menu\\Lecturer.txt");
	int n;
	fin >> n;
	Node* cur = pHead;
	for (int i = 0; i < n; ++i) {
		char a[200];
		if (pHead == nullptr) {
			pHead = new Node;
			pHead->schedule = new schedule;
			get_LecUserName(fin, pHead, a);
			get_password(fin, pHead, a);
			get_LecName(fin, pHead, a);
			get_academy(fin, pHead, a);
			get_LecGender(fin, pHead, a);
			pHead->next = nullptr;
			cur = pHead;
		}
		else {
			cur->next = new Node;
			cur = cur->next;
			cur->schedule = new schedule;
			get_LecUserName(fin, cur, a);
			get_password(fin, cur, a);
			get_LecName(fin, cur, a);
			get_academy(fin, cur, a);
			get_LecGender(fin, cur, a);
			cur->next = nullptr;
		}
	}
	fin.close();
}

void print_Lecturers(Node* pHead)
{
	cout << setw(30) << left << "Lecturer username";
	cout << setw(30) << left << "Lecturer Name";
	cout << setw(15) << left << "Academy";
	cout << setw(15) << left << "Gender" << endl;
	cout << setfill('-');
	cout << setw(90) << "-" << endl;
	cout << setfill(' ');

	while (pHead != nullptr) {
		cout << setw(30) << left << pHead->schedule->lec->account;
		cout << setw(30) << left << pHead->schedule->lec->name;
		cout << setw(15) << left << pHead->schedule->lec->academy;
		if (pHead->schedule->lec->gender == 0)
			cout << setw(15) << left << "Female" << endl;
		else
			cout << setw(15) << left << "Male" << endl;
		pHead = pHead->next;
	}
}

void delete_NodeLecturer(Node*& pHead)
{
	Node* cur = pHead;
	while (pHead != nullptr) {
		pHead = pHead->next;
		delete[] cur->schedule->lec->account;
		delete[] cur->schedule->lec->password;
		delete[] cur->schedule->lec->name;
		delete[] cur->schedule->lec->academy;
		delete cur->schedule->lec;
		cur = pHead;
	}
}

void view_Lecturers()
{
	Node* pHead = nullptr;
	get_Lecturer(pHead);
	print_Lecturers(pHead);
	delete_NodeLecturer(pHead);
	system("pause");
}