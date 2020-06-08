#include "header.h"
#include "courses.h"

//clean heap memory
void cleanInputCourse(schedule& c) {
	delete[] c.courseID;
	delete[] c.courseName;
	delete[] c.Class;
	delete[] c.lec->account;
	delete[] c.lec->name;
	delete c.lec;
	delete[] c.dayofweek;
	delete[] c.room;
}

//count line..
int countLine(ifstream& in, int group) {
	char a[200];
	int count = 0;
	while (!in.eof()) {
		in.getline(a, 200);
		++count;
	}
	return count / group;
}

//check if the course is exiting ?
bool isExistCourse(char courseID[], char year[], char semester[], char className[], char fileAdd[], int& maxno) {
	ifstream in;
	char a[200] = {};
	strcat(a, "D:/Github/CS162-19CTT1-19125059/ZPMS/");
	strcat(a, year);
	strcat(a, "/");
	strcat(a, semester);
	strcat(a, "/");
	strcat(a, className);
	strcat(a, "/Schedule.txt");
	strcpy(fileAdd, a);
	in.open(fileAdd);
	if (!in.is_open()) {
		cout << "Error open schedule.txt.\n";
		exit(0);
	}
	maxno = countLine(in, 19);
	in.close();
	in.open(fileAdd);
	if (!in.is_open()) {
		cout << "error openning at isExistCourse function\n";
		exit(0);
	}
	else {
		char a[200];
		while (!in.eof()) {
			in.get(a, 200, '\n');
			in.ignore(200, '\n');
			if (isSameStr(a, courseID)) {
				in.close();
				return true;
			}
		}
	}
	in.close();
	return false;
}

//input data of course
void inputCourseData(schedule& c, char id[], int maxno, char className[]) {
	char a[200];
	c.no = maxno + 1;

	c.courseID = new char[strlen(id) + 1];
	strcpy(c.courseID, id);

	//cin.ignore(100, '\n');
	cout << "Course Name: ";
	cin.get(a, 200, '\n');
	c.courseName = new char[strlen(a) + 1];
	strcpy(c.courseName, a);

	c.Class = new char[strlen(className) + 1];
	strcpy(c.Class, className);

	c.lec = new lecture;

	cout << "Lecturer's username: ";
	cin.ignore(200, '\n');
	cin.get(a, 200, '\n');
	c.lec->account = new char[strlen(a) + 1];
	strcpy(c.lec->account, a);

	cout << "Lecturer's Name: ";
	cin.ignore(200, '\n');
	cin.get(a, 200, '\n');
	c.lec->name = new char[strlen(a) + 1];
	strcpy(c.lec->name, a);

	cout << "Gender: (1/0): ";
	cin >> c.lec->gender;

	cout << "Start day: ";
	cin >> c.Sdate.day;
	cout << "Start month: ";
	cin >> c.Sdate.month;
	cout << "Start year: ";
	cin >> c.Sdate.year;

	cout << "End day: ";
	cin >> c.Edate.day;
	cout << "End month: ";
	cin >> c.Edate.month;
	cout << "End year: ";
	cin >> c.Edate.year;

	cout << "Day of week: ";
	cin.ignore(200, '\n');
	cin.get(a, 200, '\n');
	c.dayofweek = new char[strlen(a) + 1];
	strcpy(c.dayofweek, a);

	cout << "start hour: ";
	cin >> c.Stime.hours;
	cout << "start minute: ";
	cin >> c.Stime.mins;

	cout << "End hour: ";
	cin >> c.Etime.hours;
	cout << "End minute: ";
	cin >> c.Etime.mins;

	cout << "Room: ";
	cin.ignore(200, '\n');
	cin.get(a, 200, '\n');
	c.room = new char[strlen(a) + 1];
	strcpy(c.room, a);
}

//input data of course
void inputCourse(schedule& c, char year[], char semester[], char className[], char fileAdd[]) {
	system("cls");
	cout << "=== PLEASE INPUT SOME INFORMATION ===\n";
	char id[20];
	cout << "Course ID: ";
	cin.ignore(200, '\n');
	cin.get(id, 20, '\n');


	//check if the course is existing
	int maxno = 0;
	if (isExistCourse(id, year, semester, className, fileAdd, maxno)) {
		system("cls");
		cout << "The course has already create please try again\n";
		system("pause");
		inputCourse(c, year, semester, className, fileAdd);
	}
	else {
		//
		char ad[200] = {};
		strcat(ad, "D:/Github/CS162-19CTT1-19125059/ZPMS/");
		strcat(ad, year);
		strcat(ad, "/");
		strcat(ad, semester);
		strcat(ad, "/");
		strcat(ad, className);
		strcat(ad, "/");
		strcat(ad, id);
		strcat(ad, ".txt");
		ofstream out(ad);
		//
		cin.ignore(100, '\n');
		inputCourseData(c, id, maxno, className);
	}
}

//update course data
void updateCourseData(schedule c, char fileAdd[]) {
	ofstream out(fileAdd, ios::app);
	out << "\n";
	out << c.no << "\n";
	out << c.courseID << "\n";
	out << c.courseName << "\n";
	out << c.Class << "\n";
	out << c.lec->account << "\n";
	out << c.lec->name << "\n";
	out << c.lec->gender << "\n";
	out << c.Sdate.day << "\n";
	out << c.Sdate.month << "\n";
	out << c.Sdate.year << "\n";
	out << c.Edate.day << "\n";
	out << c.Edate.month << "\n";
	out << c.Edate.year << "\n";
	out << c.dayofweek << "\n";
	out << c.Stime.hours << "\n";
	out << c.Stime.mins << "\n";
	out << c.Etime.hours << "\n";
	out << c.Etime.mins << "\n";
	out << c.room;
}

//add a new course
void addANewCourse() {
	//create varriable
	char year[20], semester[20], className[20];
	char fileAdd[500];
	schedule c;

	//input year semester class
	inputYSC(year, semester, className);

	//input data about the course
	inputCourse(c, year, semester, className, fileAdd);

	//show messess
	introDone();

	//update the data of schedule.txt file
	updateCourseData(c, fileAdd);

	//clean heap memory
	cleanInputCourse(c);
}