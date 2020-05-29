#include "header.h"
#include "courses.h"

void inputCourse() {
	ifstream in;
	ofstream out;
	Node* phead = nullptr;
	Node* pcur = nullptr;
	char className[10];
	char year[20];
	char semester[10];
	aPartOfinputCourse(in, phead, pcur, year, semester, className);
	outputSchedule(out, phead, year, semester, className);
	cleanScheduleNode(phead);
	introDone();
	return;
}

//a part of input course
void aPartOfinputCourse(ifstream& in, Node*& phead, Node*& pcur, char year[], char semester[], char className[]) {
	inputYSC(year, semester, className);
	//inport file
	importFile(phead, pcur);
}

//make file												
void outputSchedule(ofstream& out, Node* phead, char year[], char semester[], char className[]) {
	char fileAdd[500] = {};
	makeClassAdd(year, semester, className, fileAdd);

	out.open(fileAdd);
	Node* pcur = phead;
	while (pcur) {
		out << pcur->schedule->no << "\n";
		out << pcur->schedule->courseID << "\n";
		out << pcur->schedule->courseName << "\n";
		out << pcur->schedule->Class << "\n";
		out << pcur->schedule->lec->account << "\n";
		out << pcur->schedule->lec->name << "\n";
		out << pcur->schedule->lec->gender << "\n";
		out << pcur->schedule->Sdate.day << "\n";
		out << pcur->schedule->Sdate.month << "\n";
		out << pcur->schedule->Sdate.year << "\n";
		out << pcur->schedule->Edate.day << "\n";
		out << pcur->schedule->Edate.month << "\n";
		out << pcur->schedule->Edate.year << "\n";
		out << pcur->schedule->dayofweek << "\n";
		out << pcur->schedule->Stime.hours << "\n";
		out << pcur->schedule->Stime.mins << "\n";
		out << pcur->schedule->Etime.hours << "\n";
		out << pcur->schedule->Etime.mins << "\n";
		if (pcur->next)
			out << pcur->schedule->room << "\n";
		else
			out << pcur->schedule->room;
		pcur = pcur->next;
	}
	out.close();
}

//clean heap memory
void cleanScheduleNode(Node*& phead) {
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

//intro Done
void introDone() {
	system("cls");
	cout << "+=======================================+\n";
	cout << "+---------------SUCESSFULLY-------------+\n";
	cout << "+=======================================+\n";
	system("pause");
}

//input year - semester - year
void inputYSC(char year[], char semester[], char className[]) {
	//year
	ifstream in;
	in.open("D:/Github/CS162-19CTT1-19125059/ZPMS/Year.txt");
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
	if (!isExistYear(year)) {
		system("cls");
		cout << "Wrong!, Please enter again !\n";
		return inputYSC(year, semester, className);
	}
	in.close();

	//semester
	char fileAdd[499] = {};
	strcat(fileAdd, "D:/Github/CS162-19CTT1-19125059/ZPMS/");
	strcat(fileAdd, year);
	strcat(fileAdd, "/");
	strcat(fileAdd, "Semester.txt");

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
		//cout << "Semester: " << semester << endl;
	}
	if (!isExistSem(year, semester)) {
		system("cls");
		cout << "Wrong!, Please enter again !\n";
		return inputYSC(year, semester, className);
	}
	in.close();

	char fileAdd1[500] = {};
	strcat(fileAdd1, "D:/Github/CS162-19CTT1-19125059/ZPMS/");
	strcat(fileAdd1, year);
	strcat(fileAdd1, "/");
	strcat(fileAdd1, semester);
	strcat(fileAdd1, "/");
	strcat(fileAdd1, "Class.txt");
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
	if (!isExistClass(className, semester, year)) {
		system("cls");
		cout << "Wrong!, Please enter again !\n";
		return inputYSC(year, semester, className);
	}
	in.close();
	return;
}

//import file
void importFile(Node*& phead, Node*& pcur) {
	ifstream in;
	//input address of file
	char filepath[100];
	inputFileAddress(filepath);

	//load file and check
	in.open(filepath);
	if (!in.is_open()) {
		system("cls");
		cout << "Not exist file.\n";
		return importFile(phead, pcur);
	}

	//don't read the 1st line
	in.ignore(1000, '\n');
	while (!in.eof()) {
		getNodeSchedule(in, phead, pcur);
	}
	in.close();
}

//make address of class
void makeClassAdd(char year[], char semester[], char className[], char fileAdd[]) {
	strcat(fileAdd, "D:/Github/CS162-19CTT1-19125059/ZPMS/");
	strcat(fileAdd, year);
	strcat(fileAdd, "/");
	strcat(fileAdd, semester);
	strcat(fileAdd, "/");
	strcat(fileAdd, className);
	strcat(fileAdd, "/");
	strcat(fileAdd, "Schedule.txt");
}

//is exit year
bool isExistYear(char year[]) {
	ifstream in;
	in.open("D:/Github/CS162-19CTT1-19125059/ZPMS/Year.txt");
	if (!in.is_open()) {
		cout << "Error opening Year.txt\n";
		return false;
	}
	else {
		int n;
		in >> n;
		char a[50];
		in.ignore(100, '\n');
		for (int i = 0; i < n; i++) {
			in.get(a, 20, '\n');
			in.ignore(100, '\n');
			if (strcmp(a, year) != 0) return false;
		}
	}
	return true;
}

//is exist semester
bool isExistSem(char year[], char sem[]) {
	ifstream in;
	char fileAdd[500] = {};
	strcat(fileAdd, "D:/Github/CS162-19CTT1-19125059/ZPMS/");
	strcat(fileAdd, year);
	strcat(fileAdd, "/");
	strcat(fileAdd, "Semester.txt");
	in.open(fileAdd);
	if (!in.is_open()) {
		cout << "error at check semester function\n";
		return false;
	}
	else {
		int n;
		in >> n;
		char a[20];
		in.ignore(200, '\n');
		for (int i = 0; i < n; ++i) {
			in.get(a, 1000, '\n');
			in.ignore(200, '\n');
			if (isSameStr(a, sem)) {
				in.close();
				return true;
			}
		}
		in.close();
		return false;
	}
}

//check is exist class
bool isExistClass(char className[], char sem[], char year[]) {
	ifstream in;
	char fileAdd[500] = {};
	strcat(fileAdd, "D:/Github/CS162-19CTT1-19125059/ZPMS/");
	strcat(fileAdd, year);
	strcat(fileAdd, "/");
	strcat(fileAdd, sem);
	strcat(fileAdd, "/");
	strcat(fileAdd, "Class.txt");
	in.open(fileAdd);
	if (!in.is_open()) {
		cout << "Error at checkClassExist function.\n";
		return false;
	}
	else {
		int n;
		in >> n;
		char str[10];
		in.ignore(100, '\n');
		for (int i = 0; i < n; i++) {
			in.get(str, 10, '\n');
			in.ignore(100, '\n');
			if (isSameStr(str, className)) return true;
		}
	}
	in.close();
	return false;
}

/* --------------------------- check exist account -------------------------- */
bool isSameStr(char a[], char b[]) {
	if (strlen(a) != strlen(b)) return false;
	for (int i = 0; i < strlen(a); ++i) {
		if (a[i] != b[i]) return false;
	}
	return true;
}

//ask file address
void inputFileAddress(char a[]) {
	cin.ignore(100, '\n');
	cout << "File address: ";
	cin.get(a, 100, '\n');
}

//getNode schedule
void getNodeSchedule(ifstream& in, Node*& phead, Node*& pcur) {
	char a[200];
	if (!phead) {
		phead = new Node;
		getNo(in, phead, a);
		getCourseID(in, phead, a);
		getCourseName(in, phead, a);
		getClassName(in, phead, a);
		getLecUserName(in, phead, a);
		getLecName(in, phead, a);
		getLecGender(in, phead, a);
		getSdate(in, phead, a);
		getEdate(in, phead, a);
		getDayOfWeek(in, phead, a);
		getSTime(in, phead, a);
		getETime(in, phead, a);
		getRoom(in, phead, a);

		phead->next = nullptr;
		pcur = phead;
	}
	else {
		pcur->next = new Node;
		pcur = pcur->next;

		getNo(in, pcur, a);
		getCourseID(in, pcur, a);
		getCourseName(in, pcur, a);
		getClassName(in, pcur, a);
		getLecUserName(in, pcur, a);
		getLecName(in, pcur, a);
		getLecGender(in, pcur, a);
		getSdate(in, pcur, a);
		getEdate(in, pcur, a);
		getDayOfWeek(in, pcur, a);
		getSTime(in, pcur, a);
		getETime(in, pcur, a);
		getRoom(in, pcur, a);

		pcur->next = nullptr;
	}
}

//getNo
void getNo(ifstream& in, Node*& p, char a[]) {
	p->schedule = new schedule;
	//in.get(a, 200, ',');
	in >> p->schedule->no;
	// cout << p->schedule->no << "\n";
	// system("pause");
}

//get Course ID
void getCourseID(ifstream& in, Node*& p, char a[]) {
	in.ignore(200, ',');
	in.get(a, 200, ',');
	p->schedule->courseID = new char[strlen(a) + 1];
	strcpy(p->schedule->courseID, a);
	//cout << p->schedule->courseID << "\n";
}

//get course name
void getCourseName(ifstream& in, Node*& p, char a[]) {
	in.ignore(200, ',');
	in.get(a, 200, ',');
	p->schedule->courseName = new char[strlen(a) + 1];
	strcpy(p->schedule->courseName, a);
	//cout << p->schedule->courseName << "\n";
}

//get class
void getClassName(ifstream& in, Node*& p, char a[]) {
	in.ignore(200, ',');
	in.get(a, 200, ',');
	p->schedule->Class = new char[strlen(a) + 1];
	strcpy(p->schedule->Class, a);
	//cout << p->schedule->Class << "\n";
}

//get lec user name
void getLecUserName(ifstream& in, Node*& p, char a[]) {
	p->schedule->lec = new lecture;

	in.ignore(200, ',');
	in.get(a, 200, ',');
	p->schedule->lec->account = new char[strlen(a) + 1];
	strcpy(p->schedule->lec->account, a);
	//cout << p->schedule->lec->account << "\n";
}

//get lec name
void getLecName(ifstream& in, Node*& p, char a[]) {
	in.ignore(200, ',');
	in.get(a, 200, ',');
	p->schedule->lec->name = new char[strlen(a) + 1];
	strcpy(p->schedule->lec->name, a);
	//cout << p->schedule->lec->name << "\n";
}

//get lec gender
void getLecGender(ifstream& in, Node*& p, char a[]) {
	in.ignore(200, ',');
	in.get(a, 200, ',');
	p->schedule->lec->gender = ston(a);
}

//get Start date
void getSdate(ifstream& in, Node*& p, char a[]) {
	//start day month year
	in.ignore(200, ',');
	in.get(a, 200, '/');
	p->schedule->Sdate.day = ston(a);
	//cout << p->schedule->Sdate.day << "\n";

	in.ignore(200, '/');
	in.get(a, 200, '/');
	p->schedule->Sdate.month = ston(a);
	//cout << p->schedule->Sdate.month << "\n";

	in.ignore(200, '/');
	in.get(a, 200, ',');
	p->schedule->Sdate.year = ston(a);
	//cout << p->schedule->Sdate.year << "\n";
}

//get End date
void getEdate(ifstream& in, Node*& p, char a[]) {
	//start day month year
	in.ignore(200, ',');
	in.get(a, 200, '/');
	p->schedule->Edate.day = ston(a);
	//cout << p->schedule->Edate.day << "\n";

	in.ignore(200, '/');
	in.get(a, 200, '/');
	p->schedule->Edate.month = ston(a);
	//cout << p->schedule->Edate.month << "\n";

	in.ignore(200, '/');
	in.get(a, 200, ',');
	p->schedule->Edate.year = ston(a);
	//cout << p->schedule->Edate.year << "\n";
}

//get day of week
void getDayOfWeek(ifstream& in, Node*& p, char a[]) {
	in.ignore(200, ',');
	in.get(a, 200, ',');
	p->schedule->dayofweek = new char[strlen(a) + 1];
	strcpy(p->schedule->dayofweek, a);
	//cout << p->schedule->dayofweek << "\n";
}

//get Start time
void getSTime(ifstream& in, Node*& p, char a[]) {
	//start time hour and min
	in.ignore(200, ',');
	in.get(a, 200, ',');
	p->schedule->Stime.hours = ston(a);
	//cout << p->schedule->Stime.hours << "\n";

	in.ignore(200, ',');
	in.get(a, 200, ',');
	p->schedule->Stime.mins = ston(a);
	//cout << p->schedule->Stime.mins << "\n";
}

//get end time
void getETime(ifstream& in, Node*& p, char a[]) {
	//start time hour and min
	in.ignore(200, ',');
	in.get(a, 200, ',');
	p->schedule->Etime.hours = ston(a);
	//cout << p->schedule->Etime.hours << "\n";

	in.ignore(200, ',');
	in.get(a, 200, ',');
	p->schedule->Etime.mins = ston(a);
	//cout << p->schedule->Etime.mins << "\n";
}

//get room 
void getRoom(ifstream& in, Node*& p, char a[]) {
	in.ignore(100, ',');
	in.get(a, 100, '\n');
	p->schedule->room = new char[strlen(a) + 1];
	strcpy(p->schedule->room, a);
	//cout << p->schedule->room << "\n";
	in.ignore(1000, '\n');
}

//conver strong to number
int ston(char a[]) {
	int sum = 0;
	for (int i = 0; i < strlen(a); ++i) {
		a[i] -= '0';
		sum += a[i];
		sum *= 10;
	}
	return sum / 10;
}



