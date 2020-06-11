#include "header.h"
#include "allroles.h"
#include "class.h"

void changeStudentClass()
{
	char yearA[15], semeA[11], classNameA[15];
	char yearB[15], semeB[11], classNameB[15];
	char dirD[] = { "D:/Github/CS162-19CTT1-19125059/ZPMS/" };
	char serverAdd[] = { "D:/Github/CS162-19CTT1-19125059/ZPMS/menu/Student.txt" };
	char dA[505] = { "" }, dB[505] = { "" };

	system("cls");
	cout << "Input the info of the current class of that student.\n";
	system("pause");

	inputYSC(yearA, semeA, classNameA);

	strcat_s(dA, 500, dirD);
	strcat_s(dA, 500, yearA);
	strcat_s(dA, 500, "/");
	strcat_s(dA, 500, semeA);
	strcat_s(dA, 500, "/");
	strcat_s(dA, 500, classNameA);
	strcat_s(dA, 500, "/");
	strcat_s(dA, 500, "Student.txt");

	system("cls");
	cout << "Input the info of the class you what to transfer the student into.\n";
	system("pause");

	inputYSC(yearB, semeB, classNameB);
	cin.get();

	strcat_s(dB, 500, dirD);
	strcat_s(dB, 500, yearB);
	strcat_s(dB, 500, "/");
	strcat_s(dB, 500, semeB);
	strcat_s(dB, 500, "/");
	strcat_s(dB, 500, classNameB);
	strcat_s(dB, 500, "/");
	strcat_s(dB, 500, "Student.txt");

	StuNode* pClassA = nullptr, * pClassB = nullptr, * pServer = nullptr;
	int nClassA, nClassB, nServer;
	loadClass(pClassA, nClassA, dA);
	loadClass(pClassB, nClassB, dB);
	loadClass(pServer, nServer, serverAdd);

	system("cls");
	cout << "Student list of " << classNameA << '\n';

	int id_tmp = 0;
	StuNode* pTmp = pClassA;
	while (pTmp != nullptr)
	{
		cout << "#" << ++id_tmp << '\n';
		displayStudent(pTmp->stu);
		pTmp = pTmp->pNext;
		cout << '\n';
	}

	char ID[55];
	bool resCl = false, resSe = false;
	cout << "Input the ID of the student that you want to transfer: ";
	cin.getline(ID, 50, '\n');

	StuNode* pStuClassA = removeStuNode(pClassA, ID, resCl);
	StuNode* pStuServer = findStuNode(pServer, ID);

	if (resCl && pStuServer != nullptr)
	{
		delete[] pStuClassA->stu.sClass;
		delete[] pStuServer->stu.sClass;
		pStuClassA->stu.sClass = cpyStr(classNameB);
		pStuServer->stu.sClass = cpyStr(classNameB);
		nClassA--;

		addStuNode(pClassB, pStuClassA);
		nClassB++;

		introDone();
	}
	else
	{
		addStuNode(pClassA, pStuClassA);			  // added back in... (if failed)
		system("cls");
		cout << "Sorry... We can't find the student on the student list or on the server!\n";
		system("pause");
	}

	saveClass(pClassA, nClassA, dA);
	saveClass(pClassB, nClassB, dB);
	saveClass(pServer, nServer, serverAdd);

	deleteStuNodes(pClassA);
	deleteStuNodes(pClassB);
	deleteStuNodes(pServer);
}