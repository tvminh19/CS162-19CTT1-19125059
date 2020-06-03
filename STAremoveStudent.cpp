#include "header.h"
#include "allroles.h"
#include "class.h"

void removeStudent()
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
	char serverAdd[] = { "D:/Github/CS162-19CTT1-19125059/ZPMS/menu/Student.txt" };

	StuNode* pClass = nullptr, * pServer = nullptr;
	int nClass, nServer;
	loadClass(pClass, nClass, d);
	loadClass(pServer, nServer, serverAdd);

	char ID[55];
	bool resCl = false, resSe = false;
	system("cls");
	cout << "Input the ID of the student that you want to remove: ";
	cin.getline(ID, 50, '\n');
	StuNode* pStuClass = removeStuNode(pClass, ID, resCl);
	StuNode* pStuServer = findStuNode(pServer, ID);

	if (resCl && pStuServer != nullptr)
	{
		system("cls");
		cout << "Student removed from " << className << ":\n";
		displayStudent(pStuClass->stu);
		system("pause");
		deleteStudent(pStuClass->stu);
		delete pStuClass;
		nClass--;

		int choice;
		char unknwn[] = { "Unknown" };

		system("cls");
		cout << "============ CHOICES ============\n";
		cout << "[1]. Remove that student entirely from the server. (Note that student can no longer login).\n";
		cout << "[2]. Delete the student's class name. IE: from \"" << className << "\" to \"Unknown\".\n";
		cout << "[3]. Change nothing in the server!\n";
		cout << "Input your choice (1 --> 3): ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			pStuServer = removeStuNode(pServer, ID, resSe);
			deleteStudent(pStuServer->stu);
			delete pStuServer;
			nServer--;
			break;
		case 2:
			delete[] pStuServer->stu.sClass;
			pStuServer->stu.sClass = cpyStr(unknwn);
			break;
		}
	}
	else
	{
		system("cls");
		cout << "Sorry... We can't find the student on the student list or on the server!\n";
		system("pause");
	}

	saveClass(pClass, nClass, d);
	saveClass(pServer, nServer, serverAdd);

	introDone();

	deleteStuNodes(pClass);
	deleteStuNodes(pServer);
}