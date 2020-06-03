#include "header.h"
#include "allroles.h"
#include "class.h"

void editStudent()
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
	system("cls");
	cout << "Input the ID of the student that you want to edit: ";
	cin.getline(ID, 50, '\n');
	StuNode* pStuClass = findStuNode(pClass, ID);
	StuNode* pStuServer = findStuNode(pServer, ID);

	if (pStuServer != nullptr && pStuClass != nullptr)
	{
		int choice;
		system("cls");
		cout << "What information do you want to edit?\n";
		cout << "=====================================\n";
		cout << "[0]. Back.\n";
		cout << "[1]. Name: " << pStuClass->stu.sName << '\n';
		cout << "[2]. DOB: "; displayDate(pStuClass->stu.DOB);
		cout << "[3]. Gender: " << pStuClass->stu.gender << '\n';
		cout << "=====================================\n";
		cout << "Input your choice (0 --> 3): ";
		cin >> choice;
		cin.get();
		while (choice >= 1 && choice <= 3)
		{
			switch (choice)
			{
			case 1:
			{
				char editedName[105];
				cout << "Edit the name to: ";
				cin.getline(editedName, 100, '\n');
				delete[] pStuClass->stu.sName;
				delete[] pStuServer->stu.sName;
				pStuClass->stu.sName = cpyStr(editedName);
				pStuServer->stu.sName = cpyStr(editedName);

				system("cls");
				cout << "Name changed successfully!\n";
				system("pause");
				break;
			}
			case 2:
			{
				cout << "Edit the year to: ";
				cin >> pStuClass->stu.DOB.year;
				pStuServer->stu.DOB.year = pStuClass->stu.DOB.year;

				cout << "Edit the month to: ";
				cin >> pStuClass->stu.DOB.month;
				pStuServer->stu.DOB.month = pStuClass->stu.DOB.month;

				cout << "Edit the day to: ";
				cin >> pStuClass->stu.DOB.day;
				pStuServer->stu.DOB.day = pStuClass->stu.DOB.day;

				system("cls");
				cout << "DOB changed successfully!\n";
				system("pause");
				break;
			}
			case 3:
			{
				cout << "Edit the gender to (type 1 if male, 0 if female): ";
				cin >> pStuClass->stu.gender;
				pStuServer->stu.gender = pStuClass->stu.gender;

				system("cls");
				cout << "Gender changed successfully!\n";
				system("pause");
				break;
			}
			}
			system("cls");
			cout << "What information do you want to edit?\n";
			cout << "=====================================\n";
			cout << "[0]. Back.\n";
			cout << "[1]. Name: " << pStuClass->stu.sName << '\n';
			cout << "[2]. DOB: "; displayDate(pStuClass->stu.DOB);
			cout << "[3]. Gender: " << pStuClass->stu.gender << '\n';
			cout << "=====================================\n";
			cout << "Input your choice (0 --> 4): ";
			cin >> choice;
			cin.get();
		}
	}
	else
	{
		system("cls");
		cout << "Can't find the student on the server or on the student list!\n";
		system("pause");
	}

	saveClass(pClass, nClass, d);
	saveClass(pServer, nServer, serverAdd);

	deleteStuNodes(pClass);
	deleteStuNodes(pServer);
}

StuNode* findStuNode(StuNode* pHead, char* ID)
{
	StuNode* pCur = pHead;
	while (pCur != nullptr)
	{
		if (sameStr(pCur->stu.ID, ID))
			return pCur;
		pCur = pCur->pNext;
	}
	return nullptr;
}