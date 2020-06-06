#include "lecturer.h"
#include "staff.h"

bool check_stuaccount(Node* pHead1, char ID[])
{
	Node* cur = pHead1;
	while (cur != nullptr) {
		if (strcmp(cur->scb->stu->account, ID) == 0) {
			cout << "Full name: " << cur->scb->stu->name << endl;
			cout << "Midterm: " << cur->scb->sco->midterm << endl;
			cout << "Final: " << cur->scb->sco->final << endl;
			cout << "Bonus: " << cur->scb->sco->bonus << endl;
			cout << "Total: " << cur->scb->sco->total << endl << endl;
			return true;
		}
		cur = cur->next;
	}
	return false;
}

void view_result(char ID[])
{
	char year[20], semester[20], className[20];
	char fileAdd[500] = {};
	Node* phead = nullptr;
	Node* pcur = nullptr;
	Date root;
	Time Stime, Etime;
	input_YSC(year, semester, className);

	Node* pHead = nullptr;
	show_course(pHead, year, semester, className);
	delete_ScheduleNode(pHead);

	Node* pHead1 = nullptr;
	char v[500] = "";
	choose_course(pHead1, year, semester, className, v);
	int numStu;
	loadCourseFile(v, pHead1, root, Stime, Etime, numStu);

	system("cls");
	if (check_stuaccount(pHead1, ID) == false) {
		cout << "You are not in this course!!" << endl;
	}
	system("pause");

	cleanScoreBoard(pHead1);
}