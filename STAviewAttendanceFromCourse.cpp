#include "header.h"
#include "staff.h"
#include "courses.h"

//ask which course? 
void askCourse(Node*& phead, char a[]) {
	//ask in4
	char course[20];
	cout << "\n";
	cout << "> Please input name of course to view attendance list: ";
	cin.ignore(100, '\n');
	cin.get(course, 100, '\n');

	//view
	Node* pcur = phead;
	while (pcur) {
		if (isSameStr(pcur->schedule->courseID, course)) {
			strcpy(a, course);
			return;
		}
		pcur = pcur->next;
	}
	system("cls");
	print_Schedule(phead);
	cout << "\n";
	cout << "\nPlease input Again: ";
	askCourse(phead, a);
}

//make dir to course
char* courseDir(char year[], char semester[], char className[], char course[]){
	char fileAdd[500] = {};
	strcat(fileAdd, "D:/Github/CS162-19CTT1-19125059/ZPMS/");
	strcat(fileAdd, year);
	strcat(fileAdd, "/");
	strcat(fileAdd, semester);
	strcat(fileAdd, "/");
	strcat(fileAdd, className);
	strcat(fileAdd, "/");
	strcat(fileAdd, course);
	strcat(fileAdd, ".txt");
	return fileAdd;
}

//get node scoreboard
void getNodeScoreBoard(ifstream& in, Node*& phead, Node*& pcur){
	char a[500] = {};
	if (!phead){
		phead = new Node;
		phead->scb = new scoreboard;
		phead->scb->stu = new student;

		//id or account
		in.ignore(100, '\n');
		in.get(a, 100, '\n');
		phead->scb->stu->account = new char[strlen(a) + 1];
		strcpy(phead->scb->stu->account, a);

		//pass
		in.ignore(100, '\n');
		in.get(a, 100, '\n');
		phead->scb->stu->password = new char[strlen(a) + 1];
		strcpy(phead->scb->stu->password, a);

		//student name
		in.ignore(100, '\n');
		in.get(a, 100, '\n');
		phead->scb->stu->name = new char[strlen(a) + 1];
		strcpy(phead->scb->stu->name, a);

		//dob
		in.ignore(100, '\n');
		in.get(a, 100, '\n');
		phead->scb->stu->dob = new char[strlen(a) + 1];
		strcpy(phead->scb->stu->dob, a);

		//is acctive?;
		in >> phead->scb->isActive;

		//score
		phead->scb->sco = new score;

		in >> phead->scb->sco->midterm;
		in >> phead->scb->sco->final;
		in >> phead->scb->sco->bonus;
		in >> phead->scb->sco->total;

		//check attendance
		for (int i = 0; i < 10; ++i){
			in >> phead->scb->went2class[i];
		}

		phead->next = nullptr;
		pcur = phead;
	}
	else{
		pcur->next = new Node;
		pcur = pcur->next;
		pcur->scb = new scoreboard;
		pcur->scb->stu = new student;

		//id or account
		in.ignore(100, '\n');
		in.get(a, 100, '\n');
		pcur->scb->stu->account = new char[strlen(a) + 1];
		strcpy(pcur->scb->stu->account, a);

		//pass
		in.ignore(100, '\n');
		in.get(a, 100, '\n');
		pcur->scb->stu->password = new char[strlen(a) + 1];
		strcpy(pcur->scb->stu->password, a);

		//student name
		in.ignore(100, '\n');
		in.get(a, 100, '\n');
		pcur->scb->stu->name = new char[strlen(a) + 1];
		strcpy(pcur->scb->stu->name, a);

		//dob
		in.ignore(100, '\n');
		in.get(a, 100, '\n');
		pcur->scb->stu->dob = new char[strlen(a) + 1];
		strcpy(pcur->scb->stu->dob, a);

		//is acctive?
		in >> pcur->scb->isActive;

		//score
		pcur->scb->sco = new score;

		in >> pcur->scb->sco->midterm;
		in >> pcur->scb->sco->final;
		in >> pcur->scb->sco->bonus;
		in >> pcur->scb->sco->total;

		//check attendance
		for (int i = 0; i < 10; ++i){
			in >> pcur->scb->went2class[i];
		}

		pcur->next = nullptr;
	}
}

//open and load to struct
void loadCourseFile(char fileAdd[], Node*& phead, Date& root, Time& Stime, Time& Etime, int& numStu){
	ifstream in(fileAdd);
	if (!in.is_open()){
		cout << "error opening file.\n";
		exit(0);
	}
	else{
		Node* pcur = phead;
		in >> root.year;
		in >> root.month;
		in >> root.day;

		in >> Stime.hours;
		in >> Stime.mins;

		in >> Etime.hours;
		in >> Etime.mins;

		in >> numStu;
		for (int i = 0; i < numStu; ++i){
			//get Node scoreboard
			getNodeScoreBoard(in, phead, pcur);
		}
	}
	in.close();
}

//ask number of week
int numOfWeek(){
	system("cls");
	cout << "Please input week: ";
	int n;
	cin >> n;
	while (n < 0 && n >= 10){
		system("cls");
		cout << "Wrong! Please try again!\n";
		return numOfWeek();
	}
	return n;
}

//show attendance list
void showAttendanceList(int numOfWeek, Node* phead, Date root, Time Stime, Time Etime, int numStu){
	Node* pcur = phead;
	system("cls");
	cout << "=== WEEK " << numOfWeek << " ===\n";
	cout << "=== " << root.day << "/" << root.month << "/" << root.year << " ===\n";
	for (int i = 0; i < numStu; ++i){
		cout << "[" << i << "]. " << phead->scb->stu->name <<" ->            ";
		if (phead->scb->went2class[numOfWeek] == 1)
			cout << "YES.\n";
		else
			cout << "NO.\n";
		phead = phead->next;
	}
	cout << "========================\n";

	int countNotAtt = 0;
	for (int i = 0; i < numStu; ++i){
		if (pcur->scb->went2class[numOfWeek] == 0)
			countNotAtt++;
		pcur = pcur->next;
	}

	cout << "Total: " << numStu << "\n";
	cout << "Attended: " << numStu - countNotAtt << "\n";
	cout << "Not Attended: " << countNotAtt << "\n";
	system("pause");
}

//ask and show
void askNumAndShow(Node* phead, Date root, Time Stime, Time Etime, int numStu){
	//ask num of week
	int now;
	now = numOfWeek();

	//show attendance list
	showAttendanceList(now, phead, root, Stime, Etime, numStu);

	cout << "\nDo you want to try more: (1/0): ";
	int choose;
	cin >> choose;
	if (choose == 1)
		return askNumAndShow(phead, root, Stime, Etime, numStu);
	else{
		return;
	}
}

//clean heap memory
void cleanScoreBoard(Node*& phead){
	Node* pcur = phead;
	while (phead){
		pcur = phead->next;

		delete[] phead->scb->stu->account;
		delete[] phead->scb->stu->password;
		delete[] phead->scb->stu->name;
		delete[] phead->scb->stu->dob;
		delete phead->scb->sco;
		delete phead->scb->stu;

		phead = pcur;
	}
}

// view attendance list
void viewAttendance() {
	//set variable
	char year[20], semester[20], className[20];
	char fileAdd[500] = {};
	Node* phead = nullptr;
	Node* pcur = nullptr;
	Date root;
	Time Stime, Etime;
	
	//input year semester class course
	inputYSC(year, semester, className);

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

	//ask num of week and show attendance list
	askNumAndShow(phead, root, Stime, Etime, numStu);

	//clean heap memory
	cleanScoreBoard(phead);
}
