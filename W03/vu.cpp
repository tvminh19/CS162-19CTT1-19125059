/* -------------------- this is Vu's file for functions ------------------- */
#include "Header.h"

//W01----------------------------------------------------------------------------------------------------

void notCorrect()
{
	system("cls");
	cout << "ALERT" << endl;
	cout << "       Your choice is not correct!" << endl;
	cout << "       Please input again!" << endl;
	Sleep(2000);
	system("cls");
}

void menuStudent()
{
	system("cls");
	string s;
	cout << "--------------- MENU ---------------" << endl;
	cout << "[0]. Back" << endl;
	cout << "[1]. Check-in." << endl;
	cout << "[2]. View check-in result." << endl;
	cout << "[3]. View schedule." << endl;
	cout << "[4]. View your scores of a coure." << endl << endl;
	cout << "Input your choice (0-4) > ";
	cin >> s;
	char* c = new char[s.length() + 1];
	strcpy(c, s.c_str());

	if (strcmp(c, "0") == 0) {
		//Back
		char a[100];
		displayAllroles(1, a);
	}

	else if (strcmp(c, "1") == 0) {
		//7.1
	}

	else if (strcmp(c, "2") == 0) {
		//7.2
	}

	else if (strcmp(c, "3") == 0) {
		//7.3
	}

	else if (strcmp(c, "4") == 0) {
		//7.4
	}

	else {
		notCorrect();
	}
	menuStudent();
	delete[] c;
}

void menuLecturer()
{
	system("cls");
	string s;

	cout << "----------------------- MENU -----------------------" << endl;
	cout << "[0]. Back" << endl;
	cout << "[1]. View list of courses in the current semester." << endl;
	cout << "[2]. View list of students of a course." << endl;
	cout << "[3]. View attendance list of a course." << endl;
	cout << "[4]. Edit an attendance." << endl;
	cout << "[5]. Import scoreboard of a course from a csv file." << endl;
	cout << "[6]. Edit grade of a student." << endl;
	cout << "[7]. View a scoreboard." << endl << endl;
	cout << "Input your choice (0-7) > ";
	cin >> s;
	char* c = new char[s.length() + 1];
	strcpy(c, s.c_str());

	if (strcmp(c, "0") == 0) {
		//Back
		char a[100];
		displayAllroles(2, a);
	}

	else if (strcmp(c, "1") == 0) {
		//6.1
	}

	else if (strcmp(c, "2") == 0) {
		//6.2
	}

	else if (strcmp(c, "3") == 0) {
		//6.3
	}

	else if (strcmp(c, "4") == 0) {
		//6.4
	}

	else if (strcmp(c, "5") == 0) {
		//6.5
	}

	else if (strcmp(c, "6") == 0) {
		//6.6
	}

	else if (strcmp(c, "7") == 0) {
		//6.7
	}

	else {
		notCorrect();
	}
	menuLecturer();
	delete[] c;
}

//-----------------------------------------------------------------------------------------

void Staff_class()
{
	system("cls");
	string s;

	cout << "------------- Academic Staff-class -------------" << endl;
	cout << "[0]. Back" << endl;
	cout << "[1]. Import students of a class from a csv file." << endl;
	cout << "[2]. Manually add a new student to a class." << endl;
	cout << "[3]. Edit an existing student." << endl;
	cout << "[4]. Remove a student." << endl;
	cout << "[5]. Change students from class A to class B." << endl;
	cout << "[6]. View list of classes." << endl;
	cout << "[7]. View list of students in a class." << endl << endl;
	cout << "Input your choice (0-7) > ";
	cin >> s;
	char* c = new char[s.length() + 1];
	strcpy(c, s.c_str());

	if (strcmp(c, "0") == 0) {
		//Back
		menuStaffRole();
	}

	else if (strcmp(c, "1") == 0) {
		//2.1
	}

	else if (strcmp(c, "2") == 0) {
		//2.2
	}

	else if (strcmp(c, "3") == 0) {
		//2.3
	}

	else if (strcmp(c, "4") == 0) {
		//2.4
	}

	else if (strcmp(c, "5") == 0) {
		//2.5
	}

	else if (strcmp(c, "6") == 0) {
		//2.6
	}

	else if (strcmp(c, "7") == 0) {
		//2.7
	}

	else {
		notCorrect();
	}
	Staff_class();
	delete[] c;
}

void Staff_course()
{
	system("cls");
	string s;

	cout << "------------------------------ Academic Staff-course ------------------------------" << endl;
	cout << "[0].  Back" << endl;
	cout << "[1].  Create / Delete / View academic years (2019-2020) and semesters." << endl;
	cout << "[2].  From a semester, import courses from a csv file." << endl;
	cout << "[3].  Manually add a new course." << endl;
	cout << "[4].  Edit an existing course." << endl;
	cout << "[5].  Remove a course." << endl;
	cout << "[6].  Remove a specific student from a course." << endl;
	cout << "[7].  Add a specific student to a course." << endl;
	cout << "[8].  View list of courses in the current semester." << endl;
	cout << "[9].  View list of students of a course." << endl;
	cout << "[10]. View attendance list of a course." << endl;
	cout << "[11]. View all lecturers." << endl << endl;
	cout << "Input your choice (0-11) > ";
	cin >> s;
	char* c = new char[s.length() + 1];
	strcpy(c, s.c_str());

	if (strcmp(c, "0") == 0) {
		//Back
		menuStaffRole();
	}

	else if (strcmp(c, "1") == 0) {
		//3.1
		Year_Semester();
	}

	else if (strcmp(c, "2") == 0) {
		//3.2
		inputCourse();
	}

	else if (strcmp(c, "3") == 0) {
		//3.3
		addANewCourse();
	}

	else if (strcmp(c, "4") == 0) {
		//3.4
		editcourse();
	}

	else if (strcmp(c, "5") == 0) {
		//3.5
	}

	else if (strcmp(c, "6") == 0) {
		//3.6
	}

	else if (strcmp(c, "7") == 0) {
		//3.7
	}

	else if (strcmp(c, "8") == 0) {
		//3.8
		view_Courses();
	}

	else if (strcmp(c, "9") == 0) {
		//3.9
	}

	else if (strcmp(c, "10") == 0) {
		//3.10
	}

	else if (strcmp(c, "11") == 0) {
		//3.11
	}

	else {
		notCorrect();
	}
	Staff_course();
	delete[] c;
}

void Staff_scoreboard()
{
	system("cls");
	string s;

	cout << "---------- Academic Staff-scoreboard ----------" << endl;
	cout << "[0]. Back" << endl;
	cout << "[1]. Search and view the scoreboard of a course" << endl;
	cout << "[2]. Export a scoreboard to a csv file" << endl << endl;
	cout << "Input your choice (0-2) > ";
	cin >> s;
	char* c = new char[s.length() + 1];
	strcpy(c, s.c_str());

	if (strcmp(c, "0") == 0) {
		//Back
		menuStaffRole();
	}

	else if (strcmp(c, "1") == 0) {
		//4.1
	}

	else if (strcmp(c, "2") == 0) {
		//4.2
	}

	else {
		notCorrect();
	}
	Staff_scoreboard();
	delete[] c;
}

void Staff_attendanceList()
{
	system("cls");
	string s;

	cout << "---------- Academic Staff-attendance list ----------" << endl;
	cout << "[0]. Back" << endl;
	cout << "[1]. Search and view attendance list of a course." << endl;
	cout << "[2]. Export a attendance list to a csv file." << endl;
	cout << "Input your choice (0-2) > ";
	cin >> s;
	char* c = new char[s.length() + 1];
	strcpy(c, s.c_str());

	if (strcmp(c, "0") == 0) {
		//Back
		menuStaffRole();
	}

	else if (strcmp(c, "1") == 0) {
		//5.1
	}

	else if (strcmp(c, "2") == 0) {
		//5.2
	}

	else {
		notCorrect();
	}
	Staff_attendanceList();
	delete[] c;
}

void menuStaffRole()
{
	system("cls");
	string s;

	cout << "--------------- MENU ---------------" << endl;
	cout << "[0]. Back" << endl;
	cout << "[1]. Academic staff-Class." << endl;
	cout << "[2]. Academic staff-Course." << endl;
	cout << "[3]. Academic staff-Scoreboard." << endl;
	cout << "[4]. Academic staff-Attendance list." << endl << endl;
	cout << "Input your choice (0-4) > ";
	cin >> s;
	char* c = new char[s.length() + 1];
	strcpy(c, s.c_str());

	if (strcmp(c, "0") == 0) {
		//Back
		char a[100];
		displayAllroles(3, a);
	}

	else if (strcmp(c, "1") == 0) {
		Staff_class();
	}

	else if (strcmp(c, "2") == 0) {
		Staff_course();
	}

	else if (strcmp(c, "3") == 0) {
		Staff_scoreboard();
	}

	else if (strcmp(c, "4") == 0) {
		Staff_attendanceList();
	}

	else {
		notCorrect();
		menuStaffRole();
	}
	delete[] c;
}

void showMenu(int typeAccount)
{
	system("cls");

	//student
	if (typeAccount == 1) {
		menuStudent();
	}

	//lecturer
	else if (typeAccount == 2) {
		menuLecturer();
	}

	//staff
	else if (typeAccount == 3) {
		menuStaffRole();
	}
}

void displayAllroles(int typeAccount, char ID[])
{
	system("cls");
	string s;

	//All roles
	cout << "======== MENU ========" << endl;
	cout << "[1]. Show menu" << endl;
	cout << "[2]. View profile info" << endl;
	cout << "[3]. Change password" << endl;
	cout << "[4]. Logout" << endl << endl;
	cout << "Input your choice (1-4) > ";
	cin >> s;
	char* c = new char[s.length() + 1];
	strcpy(c, s.c_str());

	//Show menu
	if (strcmp(c, "1") == 0) {
		//1.2
		showMenu(typeAccount);
	}

	//View profile info
	else if (strcmp(c, "2") == 0) {
		//1.3
		viewProfile(typeAccount, ID);
	}

	//Change password
	else if (strcmp(c, "3") == 0) {
		//1.4
		changePassword(typeAccount, ID);
	}

	//Logout
	else if (strcmp(c, "4") == 0) {
		//1.5
		cin.ignore();
		char id[20];
		menu(typeAccount, id);
	}

	else {
		notCorrect();
		char a[100];
		displayAllroles(typeAccount, a);
	}
	delete[] c;
}

//W02----------------------------------------------------------------------------------------------------

void Year_Semester()
{
	system("cls");
	string s;

	cout << "-------------------- MENU --------------------" << endl;
	cout << "[0]. Back" << endl;
	cout << "[1]. Create an academic year and semesters" << endl;
	cout << "[2]. Delete an academic year and semesters" << endl;
	cout << "[3]. View an academic year and semesters" << endl << endl;
	cout << "Input your choice (0-4) > ";
	cin >> s;
	char* c = new char[s.length() + 1];
	strcpy(c, s.c_str());

	if (strcmp(c, "0") == 0) {
		//Back
		Staff_course();
	}

	else if (strcmp(c, "1") == 0) {
		//Create
		create_Year_Semester();
	}

	else if (strcmp(c, "2") == 0) {
		//Delete
		//delete_Year_Semester();
	}

	else if (strcmp(c, "3") == 0) {
		//View
		view_Year_Semester();
	}

	else {
		notCorrect();
	}
	Year_Semester();
	delete[] c;
}

//W03----------------------------------------------------------------------------------------------------

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
		fout << cur->years << endl;
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
		fout << cur->semesters << endl;
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

void delete_Semester(Year*& pHead)
{
	Year* cur = pHead;
	while (pHead != nullptr) {
		pHead = pHead->pNext;
		delete[] cur->semesters;
		delete cur;
		cur = pHead;
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
	delete_Year(pHead);

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
		introDone();
	}
	else {
		cout << "You already has this semester!" << endl;
		Sleep(500);
		system("pause");
	}

	delete[] year;
	delete[] semester;
	delete_Semester(pHead1);
}
//----------------------------------------------------------------------------------------------------
bool Year_exist(Year*& pHead)
{
	ifstream fin;
	fin.open("D:\\Github\\CS162-19CTT1-19125059\\ZPMS\\year.txt");
	int n;
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

void Semester_exist(Year*& pHead)
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
		cout << "----- Delete Year or Semester -----" << endl;
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
		cout << "[" << m + 1 << "]. Year " << year << endl << endl;
		cout << endl << "Input your choice (year or a semester) > ";
		char e[100];
		cin.ignore();
		cin.get(e, 100, '\n');
		char* your_choice = new char[strlen(e) + 1];
		strcpy(your_choice, e);

		nextStep(pHead, pHead1, your_choice, year);

		delete[] your_choice;
	}

	delete[] year;
}

void nextStep(Year*& pHead, Year*& pHead1, char* your_choice, char* year)
{
	char dirD[] = "D:\\Github\\CS162-19CTT1-19125059\\ZPMS\\";
	char c[500] = "";
	strcat(c, dirD);
	strcat(c, year);

	if (strcmp(your_choice, year) == 0) {
		RemoveDirectoryA(c);
	}
	else {
		strcat(c, "\\");
		strcat(c, your_choice);
		RemoveDirectoryA(c);
	}
	delete_Semester(pHead1);
}

void delete_Year_Semester()
{
	system("cls");

	Year* pHead = nullptr;
	if (!Year_exist(pHead)) {
		cout << "There are no years existed" << endl;
		//Year_Semester();
	}
	else {
		Semester_exist(pHead);
	}
	delete_Year(pHead);
}
//----------------------------------------------------------------------------------------------------
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
	if (!Year_exist(pHead)) {
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