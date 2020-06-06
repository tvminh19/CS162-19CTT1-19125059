#include "lecturer.h"
#include "staff.h"

bool check_ID_exist(Node*& pHead1, char* tmp_ID)
{
	Node* cur = pHead1;
	while (cur != nullptr) {
		if (strcmp(cur->scb->stu->account, tmp_ID) == 0) {
			cout << endl;
			cout << "Full name: " << cur->scb->stu->name << endl;
			cout << "Midterm: " << cur->scb->sco->midterm << endl;
			cout << "Final: " << cur->scb->sco->final << endl;
			cout << "Bonus: " << cur->scb->sco->bonus << endl;
			cout << "Total: " << cur->scb->sco->total << endl << endl;

			cout << "=== Edit score ===" << endl;
			cout << "New Midterm: ";
			cin >> cur->scb->sco->midterm;
			cout << "New Final: ";
			cin >> cur->scb->sco->final;
			cout << "New Bonus: ";
			cin >> cur->scb->sco->bonus;
			cout << "New Total: ";
			cin >> cur->scb->sco->total;

			introDone();

			return true;
		}
		cur = cur->next;
	}
	return false;
}

void change_score(Node*& pHead1)
{
	char a[50];
	cout << "Input student ID: ";
	cin.ignore();
	cin.get(a, 50, '\n');
	char* tmp_ID = new char[strlen(a) + 1];
	strcpy(tmp_ID, a);

	if (check_ID_exist(pHead1, tmp_ID) == false) {
		cout << "Cannot find this ID in the course!!" << endl;
		cout << "Please input again" << endl;
		system("pause");
		system("cls");
		change_score(pHead1);
	}

}

void edit_grade()
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
	print_S_B(pHead1);
	system("pause");
	system("cls");

	change_score(pHead1);

	//print out again
	updateCourse(v, pHead1, root, Stime, Etime, numStu);

	cleanScoreBoard(pHead1);
}