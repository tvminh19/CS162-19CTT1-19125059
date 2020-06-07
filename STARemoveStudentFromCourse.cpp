#include "header.h"
#include "courses.h"
#include "students.h"
#include "staff.h"

//ask id student
void askstu(char id[], Node*& phead) {
	cout << "ID of student: ";
	cin.ignore(100, '\n');
	cin.get(id, 100, '\n');
	Node* pcur = phead;
	Node* prev = phead;

	if (strcmp(phead->scb->stu->account, id) == 0) {
		phead = phead->next;
		delete[] pcur->scb->stu->account;
		delete[] pcur->scb->stu->password;
		delete[] pcur->scb->stu->name;
		delete[] pcur->scb->stu->dob;
		delete pcur->scb->sco;
		delete pcur->scb->stu;
		delete pcur;
		pcur = phead;
		return;
	}

	while (pcur) {
		if (strcmp(pcur->scb->stu->account, id) == 0) {
			prev->next = pcur->next;
			Node* tmp = pcur;
			pcur = pcur->next;
			delete[] tmp->scb->stu->account;
			delete[] tmp->scb->stu->password;
			delete[] tmp->scb->stu->name;
			delete[] tmp->scb->stu->dob;
			delete tmp->scb->sco;
			delete tmp->scb->stu;
			delete tmp;
			return;
		}
		else {
			prev = pcur;
			pcur = pcur->next;
		}
	}
	system("cls");
	cout << "Wrong id, please try again:\n";
	system("pause");
	return askstu(id, phead);
}

//view student
void viewstu(Node* phead) {
	system("cls");
	while (phead) {
		cout << "[" << phead->scb->stu->account << "]. " << phead->scb->stu->name << "\n";
		phead = phead->next;
	}
}

//remove student from course
void removeStufromCo() {
	//set variable
	char year[20], semester[20], className[20];
	char fileAdd[500] = {};
	Node* phead = nullptr;
	Node* pcur = nullptr;
	Date root;
	Time Stime, Etime;

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

	//safe
	ifstream in(fileAdd);
	if (!in.is_open()) {
		system("cls");
		cleanScheduleNode(phead);
		cout << "Database of course is not exist!\n";
		system("pause");
		return;
	}

	//clean heap memory
	cleanScheduleNode(phead);

	//open and load to struct
	int numStu;
	loadCourseFile(fileAdd, phead, root, Stime, Etime, numStu);
	
	//view student
	viewstu(phead);

	//ask student
	char id[20];
	askstu(id, phead);

	//update
	numStu--;
	updateCourse(fileAdd, phead, root, Stime, Etime, numStu);

	//clean heap memory
	cleanScoreBoard(phead);

	introDone();
}