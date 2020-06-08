#include "courses.h"

bool exist_Year(Year*& pHead, int& n, char* year)
{
	ifstream fin;
	fin.open("D:\\Github\\CS162-19CTT1-19125059\\ZPMS\\year.txt");
	fin >> n;
	int m = n;
	if (m == 0) {
		fin.close();
		return false;
	}
	else {
		Year* cur = pHead;
		while (m > 0) {
			if (pHead == nullptr) {
				pHead = new Year;
				char c[15];
				fin.ignore();
				fin.get(c, 15, '\n');
				pHead->years = new char[strlen(c) + 1];
				strcpy(pHead->years, c);
				cur = pHead;
				pHead->pNext = nullptr;
			}
			else {
				cur->pNext = new Year;
				cur = cur->pNext;
				char c[15];
				fin.ignore();
				fin.get(c, 15, '\n');
				cur->years = new char[strlen(c) + 1];
				strcpy(cur->years, c);
				cur->pNext = nullptr;
			}
			m--;
		}
		fin.close();
		cur = pHead;
		while (cur != nullptr) {
			if (strcmp(cur->years, year) == 0)
				return true;
			cur = cur->pNext;
		}
		return false;
	}
}

void createNew_Year(Year*& pHead, int& n, char* year)
{
	ofstream fout;
	fout.open("D:\\Github\\CS162-19CTT1-19125059\\ZPMS\\year.txt");

	Year* cur = pHead;
	n += 1;
	fout << n << endl;
	if (pHead == nullptr) {
		pHead = new Year;
		pHead->years = year;
		pHead->pNext = nullptr;
		fout << pHead->years;
	}
	else {
		while (cur != nullptr) {
			fout << cur->years << endl;
			cur = cur->pNext;
		}
		cur = new Year;
		cur->years = year;
		fout << cur->years;
		cur->pNext = nullptr;
	}
	fout.close();

	char dirD[] = "D:\\Github\\CS162-19CTT1-19125059\\ZPMS\\";
	char c[500] = "";
	strcat(c, dirD);
	strcat(c, year);
	CreateDirectoryA(c, NULL);
	strcat(c, "\\semester.txt");

	fout.open(c);
	fout << 0;
	fout.close();
}

void delete_Year(Year*& pHead)
{
	Year* cur = pHead;
	while (pHead != nullptr) {
		pHead = pHead->pNext;
		delete[] cur->years;
		delete cur;
		cur = pHead;
	}
}

bool exist_Semester(Year*& pHead, int& n, char* semester, char* year)
{
	char dirD[] = "D:\\Github\\CS162-19CTT1-19125059\\ZPMS\\";
	char c[500] = "";
	strcat(c, dirD);
	strcat(c, year);
	strcat(c, "\\semester.txt");

	ifstream fin;
	fin.open(c);
	fin >> n;
	int m = n;
	if (m == 0) {
		fin.close();
		return false;
	}
	else {
		Year* cur = pHead;
		while (m > 0) {
			if (pHead == nullptr) {
				pHead = new Year;
				char c[15];
				fin.ignore();
				fin.get(c, 15, '\n');
				pHead->semesters = new char[strlen(c) + 1];
				strcpy(pHead->semesters, c);
				cur = pHead;
				pHead->pNext = nullptr;
			}
			else {
				cur->pNext = new Year;
				cur = cur->pNext;
				char c[15];
				fin.ignore();
				fin.get(c, 15, '\n');
				cur->semesters = new char[strlen(c) + 1];
				strcpy(cur->semesters, c);
				cur->pNext = nullptr;
			}
			m--;
		}
		fin.close();
		cur = pHead;
		while (cur != nullptr) {
			if (strcmp(cur->semesters, semester) == 0)
				return true;
			cur = cur->pNext;
		}
		return false;
	}
}

void createNew_Semester(Year*& pHead, int& n, char* semester, char* year)
{
	char dirD[] = "D:\\Github\\CS162-19CTT1-19125059\\ZPMS\\";
	char c[500] = "";
	strcat(c, dirD);
	strcat(c, year);
	strcat(c, "\\semester.txt");

	ofstream fout;
	fout.open(c);

	Year* cur = pHead;
	n += 1;
	fout << n << endl;
	if (pHead == nullptr) {
		pHead = new Year;
		pHead->semesters = semester;
		pHead->pNext = nullptr;
		fout << pHead->semesters;
	}
	else {
		while (cur != nullptr) {
			fout << cur->semesters << endl;
			cur = cur->pNext;
		}
		cur = new Year;
		cur->semesters = semester;
		fout << cur->semesters;
		cur->pNext = nullptr;
	}
	fout.close();

	char d[500] = "";
	strcat(d, dirD);
	strcat(d, year);
	strcat(d, "\\");
	strcat(d, semester);
	CreateDirectoryA(d, NULL);

	strcat(d, "\\class.txt");
	fout.open(d);
	fout << 0;
	fout.close();
}

void delete_Semester(Year*& pHead1)
{
	Year* cur = pHead1;
	while (pHead1 != nullptr) {
		pHead1 = pHead1->pNext;
		delete[] cur->semesters;
		delete cur;
		cur = pHead1;
	}
}

bool exist_Class(Year*& pHead, int& n, char* semester, char* year, char* className)
{
	char dirD[] = "D:\\Github\\CS162-19CTT1-19125059\\ZPMS\\";
	char c[500] = "";
	strcat(c, dirD);
	strcat(c, year);
	strcat(c, "\\");
	strcat(c, semester);
	strcat(c, "\\class.txt");

	ifstream fin;
	fin.open(c);
	fin >> n;
	int m = n;
	if (m == 0) {
		fin.close();
		return false;
	}
	else {
		Year* cur = pHead;
		while (m > 0) {
			if (pHead == nullptr) {
				pHead = new Year;
				char c[15];
				fin.ignore();
				fin.get(c, 15, '\n');
				pHead->className = new char[strlen(c) + 1];
				strcpy(pHead->className, c);
				cur = pHead;
				pHead->pNext = nullptr;
			}
			else {
				cur->pNext = new Year;
				cur = cur->pNext;
				char c[15];
				fin.ignore();
				fin.get(c, 15, '\n');
				cur->className = new char[strlen(c) + 1];
				strcpy(cur->className, c);
				cur->pNext = nullptr;
			}
			m--;
		}
		fin.close();
		cur = pHead;
		while (cur != nullptr) {
			if (strcmp(cur->className, className) == 0)
				return true;
			cur = cur->pNext;
		}
		return false;
	}
}

void createNew_Class(Year*& pHead, int& n, char* semester, char* year, char* className)
{
	char dirD[] = "D:\\Github\\CS162-19CTT1-19125059\\ZPMS\\";
	char c[500] = "";
	strcat(c, dirD);
	strcat(c, year);
	strcat(c, "\\");
	strcat(c, semester);
	strcat(c, "\\class.txt");

	ofstream fout;
	fout.open(c);

	Year* cur = pHead;
	n += 1;
	fout << n << endl;

	if (pHead == nullptr) {
		pHead = new Year;
		pHead->className = className;
		pHead->pNext = nullptr;
		fout << pHead->className;
	}
	else {
		while (cur != nullptr) {
			fout << cur->className << endl;
			cur = cur->pNext;
		}
		cur = new Year;
		cur->className = className;
		fout << cur->className;
		cur->pNext = nullptr;
	}
	fout.close();

	char d[500] = "";
	strcat(d, dirD);
	strcat(d, year);
	strcat(d, "\\");
	strcat(d, semester);
	strcat(d, "\\");
	strcat(d, className);
	CreateDirectoryA(d, NULL);

}

void delete_Class(Year*& pHead2)
{
	Year* cur = pHead2;
	while (pHead2 != nullptr) {
		pHead2 = pHead2->pNext;
		delete[] cur->className;
		delete cur;
		cur = pHead2;
	}
}

void create_Year_Semester()
{
	system("cls");

	char tmpY[500];
	cout << "Year: ";
	cin.ignore(1000, '\n');
	cin.get(tmpY, 500, '\n');
	char* year = new char[strlen(tmpY) + 1];
	strcpy(year, tmpY);
	int n = 0;

	// YEAR
	Year* pHead = nullptr;
	if (!exist_Year(pHead, n, year)) {
		// create new year
		createNew_Year(pHead, n, year);
	}
	else {
		cout << "You already has this year!" << endl;
	}

	// SEMESTER
	char tmpS[500];
	cout << "Semester: ";
	cin.ignore(100, '\n');
	cin.get(tmpS, 500, '\n');
	char* semester = new char[strlen(tmpS) + 1];
	strcpy(semester, tmpS);

	n = 0;
	Year* pHead1 = nullptr;
	if (!exist_Semester(pHead1, n, semester, year)) {
		createNew_Semester(pHead1, n, semester, year);
	}
	else {
		cout << "You already has this semester!" << endl;
	}

	//CLASS
	char tmpC[500];
	cout << "Class: ";
	cin.ignore(100, '\n');
	cin.get(tmpC, 500, '\n');
	char* className = new char[strlen(tmpS) + 1];
	strcpy(className, tmpC);

	n = 0;
	Year* pHead2 = nullptr;
	if (!exist_Class(pHead2, n, semester, year, className)) {
		createNew_Class(pHead2, n, semester, year, className);
		introDone();
	}
	else {
		cout << "You already has this class!" << endl;
		Sleep(500);
		system("pause");
	}

	delete_Year(pHead);
	delete_Semester(pHead1);
	delete_Class(pHead2);

	system("pause");
}

//2.1.2
bool Year_exist(Year*& pHead, int& n)
{
	ifstream fin;
	fin.open("D:\\Github\\CS162-19CTT1-19125059\\ZPMS\\year.txt");
	fin >> n;
	if (n == 0) {
		fin.close();
		return false;
	}
	else {
		Year* cur = pHead;
		cout << "-------- Years --------" << endl;
		for (int i = 1; i <= n; ++i) {
			if (pHead == nullptr) {
				pHead = new Year;
				char c[15];
				fin.ignore();
				fin.get(c, 15, '\n');
				pHead->years = new char[strlen(c) + 1];
				strcpy(pHead->years, c);
				cur = pHead;
				pHead->pNext = nullptr;
				cout << "[" << i << "]. " << pHead->years << endl;
			}
			else {
				cur->pNext = new Year;
				cur = cur->pNext;
				char c[15];
				fin.ignore();
				fin.get(c, 15, '\n');
				cur->years = new char[strlen(c) + 1];
				strcpy(cur->years, c);
				cur->pNext = nullptr;
				cout << "[" << i << "]. " << cur->years << endl;
			}
		}
		fin.close();
		return true;
	}
}

void Semester_exist(Year*& pHead, int& n, int& m)
{
	cout << endl << "Input your choice (year) > ";
	char u[100];
	cin.ignore();
	cin.get(u, 100, '\n');
	char* year = new char[strlen(u) + 1];
	strcpy(year, u);

	char dirD[] = "D:\\Github\\CS162-19CTT1-19125059\\ZPMS\\";
	char v[500] = "";
	strcat(v, dirD);
	strcat(v, year);
	strcat(v, "\\semester.txt");
	Year* pHead1 = nullptr;
	char* your_choice = nullptr;

	ifstream fin;
	fin.open(v);
	fin >> m;
	if (m == 0) {
		fin.close();
		system("cls");
		cout << "There are no semesters existed" << endl;
		cout << "[" << m + 1 << "]. Year " << year << endl << endl;
		cout << "Input your choice (year or a semester) > ";
		char e[100];
		cin.ignore();
		cin.get(e, 100, '\n');
		your_choice = new char[strlen(e) + 1];
		strcpy(your_choice, e);
		nextStep(pHead, pHead1, your_choice, year, n, m);
	}
	else {
		system("cls");
		cout << "----- Delete Year or Semester -----" << endl;
		Year* cur = pHead1;
		for (int i = 1; i <= m; ++i) {
			if (pHead1 == nullptr) {
				pHead1 = new Year;
				char c[15];
				fin.ignore();
				fin.get(c, 15, '\n');
				pHead1->semesters = new char[strlen(c) + 1];
				strcpy(pHead1->semesters, c);
				cur = pHead1;
				pHead1->pNext = nullptr;
				cout << "[" << i << "]. Semester " << pHead1->semesters << endl;
			}
			else {
				cur->pNext = new Year;
				cur = cur->pNext;
				char c[15];
				fin.ignore();
				fin.get(c, 15, '\n');
				cur->semesters = new char[strlen(c) + 1];
				strcpy(cur->semesters, c);
				cur->pNext = nullptr;
				cout << "[" << i << "]. Semester " << cur->semesters << endl;
			}
		}
		fin.close();
		cout << "[" << m + 1 << "]. Year " << year << endl << endl;
		cout << "Input your choice (year or a semester) > ";
		char e[100];
		cin.ignore();
		cin.get(e, 100, '\n');
		your_choice = new char[strlen(e) + 1];
		strcpy(your_choice, e);
		//here
		nextStep(pHead, pHead1, your_choice, year, n, m);

		delete[] your_choice;
	}
	delete[] year;
	if (pHead1 != nullptr) {
		delete_Semester(pHead1);
	}
}

void input_your_choice(char* your_choice)
{
	char e[100];
	cin.ignore();
	cin.get(e, 100, '\n');
	your_choice = new char[strlen(e) + 1];
	strcpy(your_choice, e);
}

void delete_AYear(Year*& pHead, int& n, char* year)
{
	if (pHead == nullptr)
		return;
	Year* cur = pHead;

	if (strcmp(pHead->years, year) == 0) {
		pHead = pHead->pNext;
		delete[] cur->years;
		delete cur;
		cur = pHead;
	}
	while (cur->pNext != nullptr) {
		if (strcmp(cur->pNext->years, year) == 0) {
			Year* tmp = cur->pNext;
			cur->pNext = tmp->pNext;
			delete[] tmp->years;
			delete tmp;
			break;
		}
		cur = cur->pNext;
	}
	ofstream fout;
	fout.open("D:\\Github\\CS162-19CTT1-19125059\\ZPMS\\year.txt");
	n -= 1;
	fout << n << endl;
	if (n == 0) {
		fout.close();
		return;
	}

	Year* pcur = pHead;
	while (pcur != nullptr) {
		fout << pcur->years << endl;
		pcur = pcur->pNext;
	}

	fout.close();
}

void delete_ASemester(Year*& pHead1, int& m, char* semester, char* year)
{
	if (pHead1 == nullptr)
		return;

	Year* cur = pHead1;
	if (strcmp(pHead1->semesters, semester) == 0) {
		pHead1 = pHead1->pNext;
		delete[] cur->semesters;
		delete cur;
		cur = pHead1;
	}
	while (cur != nullptr && cur->pNext != nullptr) {
		if (strcmp(cur->pNext->semesters, semester) == 0) {
			Year* tmp = cur->pNext;
			cur->pNext = tmp->pNext;
			delete[] tmp->semesters;
			delete tmp;
			break;
		}
		cur = cur->pNext;
	}
	char dirD[] = "D:\\Github\\CS162-19CTT1-19125059\\ZPMS\\";
	char c[500] = "";
	strcat(c, dirD);
	strcat(c, year);
	strcat(c, "\\");
	strcat(c, "semester.txt");

	ofstream fout;
	fout.open(c);
	m -= 1;
	fout << m << endl;
	if (m == 0) {
		fout.close();
		return;
	}

	Year* pcur = pHead1;
	while (pcur != nullptr) {
		fout << pcur->semesters << endl;
		pcur = pcur->pNext;
	}

	fout.close();
}

void nextStep(Year*& pHead, Year*& pHead1, char* your_choice, char* year, int& n, int& m)
{
	char dirD[] = "D:\\Github\\CS162-19CTT1-19125059\\ZPMS\\";
	char c[500] = "";
	strcat(c, "RD /S /Q ");
	strcat(c, dirD);
	strcat(c, year);

	if (strcmp(your_choice, year) == 0) {
		system(c);
		delete_AYear(pHead, n, your_choice);
	}
	else {
		strcat(c, "\\");
		strcat(c, your_choice);
		system(c);
		delete_ASemester(pHead1, m, your_choice, year);
	}
	introDone();
}

void delete_Year_Semester()
{
	system("cls");

	Year* pHead = nullptr;
	int n, m;
	if (!Year_exist(pHead, n)) {
		cout << "There are no years existed" << endl;
		//Year_Semester();
	}
	else {
		Semester_exist(pHead, n, m);
	}
	delete_Year(pHead);
}
//2.1.3
void view_Semester(char* year)
{
	char dirD[] = "D:\\Github\\CS162-19CTT1-19125059\\ZPMS\\";
	char v[500] = "";
	strcat(v, dirD);
	strcat(v, year);
	strcat(v, "\\semester.txt");

	ifstream fin;
	fin.open(v);

	int m;
	fin >> m;
	if (m == 0) {
		cout << "There are no semesters existed" << endl;
		fin.close();
		return;
	}
	else {
		system("cls");
		cout << "----- Semesters -----" << endl;
		Year* pHead1 = nullptr;
		Year* cur = pHead1;
		for (int i = 1; i <= m; ++i) {
			if (pHead1 == nullptr) {
				pHead1 = new Year;
				char c[15];
				fin.ignore();
				fin.get(c, 15, '\n');
				pHead1->semesters = new char[strlen(c) + 1];
				strcpy(pHead1->semesters, c);
				cur = pHead1;
				pHead1->pNext = nullptr;
				cout << "[" << i << "]. Semester " << pHead1->semesters << endl;
			}
			else {
				cur->pNext = new Year;
				cur = cur->pNext;
				char c[15];
				fin.ignore();
				fin.get(c, 15, '\n');
				cur->semesters = new char[strlen(c) + 1];
				strcpy(cur->semesters, c);
				cur->pNext = nullptr;
				cout << "[" << i << "]. Semester " << cur->semesters << endl;
			}
		}
		fin.close();
		cout << endl;
		system("pause");
		delete(pHead1);
	}
}

void view_Year_Semester()
{
	system("cls");
	Year* pHead = nullptr;
	int n;
	if (!Year_exist(pHead, n)) {
		cout << "There are no years existed." << endl;
	}
	else {
		cout << endl << "Do you want to view semester in specific year? (0:no , 1:yes) > ";
		bool next;
		cin >> next;
		if (next == 1) {
			cout << "Input year > ";
			char c[100];
			cin.ignore();
			cin.get(c, 100, '\n');
			char* year = new char[strlen(c) + 1];
			strcpy(year, c);
			view_Semester(year);
		}
	}
	delete_Year(pHead);
}