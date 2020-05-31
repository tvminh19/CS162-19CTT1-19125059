#include "header.h"
#include "score.h"

void export_score_csv(Node*& pHead1, char className[], char* course)
{
	char dirD[] = "D:\\Github\\CS162-19CTT1-19125059\\ZPMS\\2019-2020\\1\\19CTT1\\";
	char v[500] = "";
	strcat(v, dirD);
	strcat(v, className);
	strcat(v, "-");
	strcat(v, course);
	strcat(v, "-Score.csv");
	ofstream fout;
	fout.open(v);

	fout << "No,Student ID,Full name,Midterm,Final,Bonus,Total" << endl;
	int t = 1;
	Node* cur = pHead1;
	while (cur != nullptr) {
		fout << t << ",";
		fout << cur->scb->stu->account << ",";
		fout << cur->scb->stu->name << ",";
		fout << cur->scb->sco->midterm << ",";
		fout << cur->scb->sco->final << ",";
		fout << cur->scb->sco->bonus << ",";
		fout << cur->scb->sco->total;
		if (cur->next != nullptr)
			fout << endl;
		cur = cur->next;
		t++;
	}
	fout.close();
}

void score_course(Node*& pHead1, char year[], char semester[], char className[])
{
	cout << endl << "Input your choice (course) > ";
	char c[100];
	cin.ignore();
	cin.get(c, 100, '\n');
	char* course = new char[strlen(c) + 1];
	strcpy(course, c);

	char dirD[] = "D:\\Github\\CS162-19CTT1-19125059\\ZPMS\\";
	char v[500] = "";
	strcat(v, dirD);
	strcat(v, year);
	strcat(v, "\\");
	strcat(v, semester);
	strcat(v, "\\");
	strcat(v, className);
	strcat(v, "\\");
	strcat(v, course);
	strcat(v, ".txt");

	get_S_B(v, pHead1);
	export_score_csv(pHead1, className, course);
}

void export_Score()
{
	char year[10];
	char semester[20];
	char className[10];
	input_YSC(year, semester, className);
	Node* pHead = nullptr;
	show_course(pHead, year, semester, className);
	delete_ScheduleNode(pHead);

	Node* pHead1 = nullptr;
	score_course(pHead1, year, semester, className);
	delete_S_B(pHead1);
	introDone();
}