#include "header.h"
#include "students.h"
#include "courses.h"
#include "staff.h"

//is leap year
bool isLeapYear(int y) {
	if (y % 400 == 0 || y % 4 == 0 && y % 100 != 0)	return true;
	return false;
}

//day of month
int dayOfMonth(int m, int y) {
	if (m == 4 || m == 6 || m == 9 || m == 11)	return 30;
	else if (isLeapYear(y) && m == 2) return 29;
	else if (!isLeapYear(y) && m == 2) return 28;
	else
		return 31;
}

//return date
Date dateOfWeek(Date root, int dOfWeek) {
	for (int i = 0; i < dOfWeek; ++i) {
		if (dayOfMonth(root.month, root.year) - root.day <= 7) {
			root.day = 7 - (dayOfMonth(root.month, root.year) - root.day);
			root.month++;
		}
		else
			root.day += 7;
		//check month == 13
		if (root.month == 13) {
			root.month = 1;
			root.year++;
		}
	}
	return root;
}

/* -------------------------------------------------------------------------- */
/*                              student check in                              */
/* -------------------------------------------------------------------------- */

//ask class
void inputC(char year[], char semester[], char className[]) {
	ifstream in;
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
	in.close();

	if (!isExistClass(className, semester, year)) {
		system("cls");
		cout << "Wrong!, Please enter again !\n";
		return inputC(year, semester, className);
	}
	return;
}


//get time now
Date getTimeNow(){
	Date now;
	time_t now1 = time(0);
	tm* cptr = localtime(&now1);
	now.day = cptr->tm_mday;
	now.month = cptr->tm_mon + 1;
	now.year = cptr->tm_year + 1900;
	return now;
}

//num of week
int numOfStuWeek(Date root, Date now){
	for (int i = 0; i < 10; ++i) {
		if (ABcompare(dateOfWeek(root, i), now) == 0)
			return i;
	}
	return -1;
}

//change 0-1
void zetoon(Node*& phead, char id[], int numOfWeek){
	Node* pcur = phead;
	while (pcur){
		if (isSameStr(pcur->scb->stu->account, id)){
			pcur->scb->went2class[numOfWeek] = 1;
		}
		pcur = pcur->next;
	}
}

//compare date
int ABcompare(Date a, Date b){
    if (a.year > b.year)    return 1;
    else if (a.year < b.year) return -1;
    else{
        if (a.month > b.month) return 1;
        else if (a.month < b.month) return -1;
        else{
            if (a.day > b.day) return 1;
            else if (a.day < b.day) return -1;
            else return 0;
        }
    }
}

//tick
void tick(Node*& phead, char id[], Date root){
	//
	Date now = getTimeNow();

	//safe date
	if (ABcompare(root, now) == 1){
		cout << "You don't have permission NOW!\n";
		return;
	}

	//numofweek
	int NumOfWeek = numOfStuWeek(root, now);

	//safe week
	if (NumOfWeek >= 10){
		cout << "You don't have permission NOW!\n";
		return;
	}

	//change 0-1
	zetoon(phead, id, NumOfWeek);
}

//update course.txt
void updateCourse(char fileAdd[], Node* phead, Date root, Time Stime, Time Etime, int numStu){
	ofstream out(fileAdd);
	out << root.year << " ";
	out << root.month << " ";
	out << root.day << " ";
	out << Stime.hours << " ";
	out << Stime.mins << " ";
	out << Etime.hours << " ";
	out << Etime.mins << "\n";

	out << numStu << "\n";

	for (int i = 0; i < numStu; ++i){
		out << phead->scb->stu->account << "\n";
		out << phead->scb->stu->password << "\n";
		out << phead->scb->stu->name << "\n";
		out << phead->scb->stu->dob << "\n";
		out << phead->scb->isActive << "\n";
		out << phead->scb->sco->midterm << "\n";
		out << phead->scb->sco->final << "\n";
		out << phead->scb->sco->total << "\n";
		out << phead->scb->sco->bonus << "\n";
		for (int j = 0; j < 9; ++j){
			out << phead->scb->went2class[j] << "\n";
		}
		if (phead->next){
			out << phead->scb->went2class[9] << "\n";
		}
		else{
			out << phead->scb->went2class[9];
		}

		//
		phead = phead->next;
	}
	out.close();
}

//number to char
void ntoa(int n, char a[]) {
	int m = n;
	int count = 0;
	while (m) {
		count++;
		m /= 10;
	}

	m = n;
	for (int i = count - 1; i >= 0; --i) {
		int k = m % 10;
		char t = k + '0';
		a[i] = t;
		m /= 10;
	}
	a[count] = '\0';
}

//to know semester and year
void toKnowSemAndYear(Date now, char year[], char sem[]) {
	//semester
	if (now.month <= 12 && now.month >= 10)
		strcpy(sem, "1");
	else if (now.month <= 5 && now.month >= 2 && now.day - 18 > 0)
		strcpy(sem, "2");
	else if (now.month <= 8 && now.month >= 5 && now.day - 18 <= 0)
		strcpy(sem, "3");
	else
		strcpy(sem, "0");

	//year
	char rightYear[50] = {};
	char t[50];

	int yearLess = now.year - 1;
	ntoa(yearLess, t);

	strcat(rightYear, t);
	strcat(rightYear, "-");

	ntoa(now.year, t);
	strcat(rightYear, t);

	strcpy(year, rightYear);
	year[strlen(year)] = '\0';
}

//checkin
void StuCheckin(char id[]) {
	//set variable
	char year[20], semester[20], className[20];
	char fileAdd[500] = {};
	Node* phead = nullptr;
	Node* pcur = nullptr;
	Date root;
	Time Stime, Etime;
	
	//to know year and semester
	Date a = getTimeNow();
	toKnowSemAndYear(a, year, semester);

	//course it not open
	if (!isExistSem(year, semester)) {
		system("cls");
		cout << "Semester is not update! Please tell staff.\n";
		system("pause");
		return;
	}

	//safe
	if (strcmp(semester, "0") == 0) {
		cout << "You can not checkin now !\n";
		system("pause");
		return;
	}

	//input class
	inputC(year, semester, className);

	//make file address
	makeClassAdd(year, semester, className, fileAdd);

	//load file
	loadCourseEdit(year, semester, className, fileAdd, phead, pcur);

	//show to edit
	print_Schedule(phead);

	//ask and edit
	char course[20] = {};
	askCourse(phead, course);

	//make dir to course
	strcpy(fileAdd, courseDir(year, semester, className, course));

	//clean heap memory
	cleanScheduleNode(phead);

	//open and load to struct
	int numStu;
	loadCourseFile(fileAdd, phead, root, Stime, Etime, numStu);
	
	//doing
	tick(phead, id, root);

	//update
	updateCourse(fileAdd, phead, root, Stime, Etime, numStu);

    //show done
    introDone();

	//clean heap memory
	cleanScoreBoard(phead);
}









