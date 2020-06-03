#include "header.h"
#include "allroles.h"
#include "class.h"

void displayStudentsInClass()
{
	char year[15], seme[11], className[15];

	inputYSC(year, seme, className);
	cin.get();

	char dirD[] = { "D:/Github/CS162-19CTT1-19125059/ZPMS/" };
	char d[505] = { "" };
	strcat_s(d, 500, dirD);
	strcat_s(d, 500, year);
	strcat_s(d, 500, "/");
	strcat_s(d, 500, seme);
	strcat_s(d, 500, "/");
	strcat_s(d, 500, className);
	strcat_s(d, 500, "/");
	strcat_s(d, 500, "Student.txt");

	StuNode* pClass = nullptr;
	int nClass;
	loadClass(pClass, nClass, d);
	
	system("cls");
	cout << className << " has " << nClass << " students:\n";

	StuNode* pCur = pClass;
	int cnt = 0;
	while (pCur != nullptr)
	{
		++cnt;
		cout << "#" << cnt << ":\n";
		displayStudent(pCur->stu);
		cout << '\n';
		pCur = pCur->pNext;
	}
	deleteStuNodes(pClass);
	system("pause");
}