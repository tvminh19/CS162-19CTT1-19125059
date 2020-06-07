#include "header.h"
#include "courses.h"

int askNotorm(Node*& phead, char fileAddcp[]) {
	//ask in4
	cout << "\n";
	cout << "> Please input #NO to edit: ";
	int no;
	cin >> no;

	//edit
	Node* pcur = phead;
	while (pcur) {
		if (pcur->schedule->no == no) {
			//edit
			strcat(fileAddcp, pcur->schedule->courseID);
			strcat(fileAddcp, ".txt");
			remove(fileAddcp);
			return no;
		}
		pcur = pcur->next;
	}
	system("cls");
	print_Schedule(phead);
	cout << "\n";
	cout << "\nPlease input Again: ";
	askNotorm(phead, fileAddcp);
}

void rmcourse(Node*& phead, int no) {
	Node* pcur = phead;
	Node* prev = phead;
	if (phead->schedule->no == no) {
		phead = phead->next;
		delete[] pcur->schedule->courseID;
		delete[] pcur->schedule->courseName;
		delete[] pcur->schedule->Class;
		delete[] pcur->schedule->lec->account;
		delete[] pcur->schedule->lec->name;
		delete[] pcur->schedule->dayofweek;
		delete[] pcur->schedule->room;
		delete pcur->schedule->lec;
		delete pcur->schedule;
		delete pcur;
		pcur = phead;
	}
	while (pcur) {
		if (pcur->schedule->no == no) {
			prev->next = pcur->next;
			Node* tmp = pcur;
			pcur = pcur->next;
			delete[] tmp->schedule->courseID;
			delete[] tmp->schedule->courseName;
			delete[] tmp->schedule->Class;
			delete[] tmp->schedule->lec->account;
			delete[] tmp->schedule->lec->name;
			delete[] tmp->schedule->dayofweek;
			delete[] tmp->schedule->room;
			delete tmp->schedule->lec;
			delete tmp->schedule;
			delete tmp;
		}
		else {
			prev = pcur;
			pcur = pcur->next;
		}
	}
	pcur = phead;
	int i = 1;
	while (pcur) {
		pcur->schedule->no = i;
		i++;
		pcur = pcur->next;
	}
}

void updateCo(char fileAdd[], Node* phead) {
	ofstream out;
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
//remove course
void removeCourse() {
	//varriable
	ofstream out;
	char year[20], semester[20], className[20], fileAdd[500] = {};
	Node* phead = nullptr;
	Node* pcur = nullptr;


	//input year semester class
	inputYSC(year, semester, className);

	char ad[200] = {};
	strcat(ad, "D:/Github/CS162-19CTT1-19125059/ZPMS/");
	strcat(ad, year);
	strcat(ad, "/");
	strcat(ad, semester);
	strcat(ad, "/");
	strcat(ad, className);
	strcat(ad, "/");

	//make file add
	makeClassAdd(year, semester, className, fileAdd);

	//load file
	loadCourseEdit(year, semester, className, fileAdd, phead, pcur);

	//show to edit
	print_Schedule(phead);

	//ask and edit
	int no = askNotorm(phead, ad);

	//remove
	rmcourse(phead, no);

	//update
	char ad1[200] = {};
	strcat(ad1, "D:/Github/CS162-19CTT1-19125059/ZPMS/");
	strcat(ad1, year);
	strcat(ad1, "/");
	strcat(ad1, semester);
	strcat(ad1, "/");
	strcat(ad1, className);
	strcat(ad1, "/");
	strcat(ad1, "Schedule.txt");
	updateCo(ad1, phead);

	//clean
	cleanScheduleNode(phead);

	//show "OK"
	introDone();
}