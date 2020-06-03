#include "header.h"
#include "allroles.h"
#include "class.h"

void addNewStudent()
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

	StuNode* pNew = new StuNode;
	pNew->stu = inputStudent();
	pNew->stu.sClass = cpyStr(className);
	pNew->pNext = nullptr;

	if (stuNodeExists(pServer, pNew->stu.ID))
	{
		system("cls");
		cout << "The student has the ID that already exists in the server, do you want to replace it? (type YES or NO) ";
		char choice[15];
		cin.getline(choice, 10, '\n');
		if (choice[0] == 'Y' || choice[0] == 'y')
		{
			bool res = false;
			StuNode* pDel = removeStuNode(pServer, pNew->stu.ID, res);
			if (res)
			{
				system("cls");
				cout << "We are replacing this student from the server:\n";
				displayStudent(pDel->stu);
				system("pause");
				deleteStudent(pDel->stu);
				delete pDel;				 // delete the student we are replacing...

				nClass++;
				addStuNode(pClass, pNew);
				saveClass(pClass, nClass, d);
				StuNode* pCur = pClass;
				while (pCur->pNext != nullptr && pCur->pNext->pNext != nullptr)
					pCur = pCur->pNext;
				pCur->pNext = nullptr;				  // take pNew out of the class, now pNew is a lonely node...
				addStuNode(pServer, pNew);
				saveClass(pServer, nServer, serverAdd);
			}
			else
			{
				system("cls");
				cout << "Failed replacing the student!\nPlease try again later!\n";
				system("pause");
				return;
			}
		}
		else
		{
			cout << "The student won't be added to the class or the server!\n";
			system("pause");
			return;
		}
	}
	else
	{
		nClass++;
		nServer++;
		addStuNode(pClass, pNew);
		saveClass(pClass, nClass, d);
		StuNode* pCur = pClass;
		while (pCur->pNext != nullptr && pCur->pNext->pNext != nullptr)
			pCur = pCur->pNext;
		pCur->pNext = nullptr;				  // take pNew out of the class, now pNew is a lonely node...
		addStuNode(pServer, pNew);
		saveClass(pServer, nServer, serverAdd);
	}

	introDone();

	deleteStuNodes(pClass);
	deleteStuNodes(pServer);
}

Student inputStudent()
{
	Student stu;
	char tmp[1005];
	cout << "Input the student's ID: ";
	cin.getline(tmp, 1000, '\n');
	stu.ID = cpyStr(tmp);

	cout << "Input the student's name: ";
	cin.getline(tmp, 1000, '\n');
	stu.sName = cpyStr(tmp);

	cout << "Input the student's date of birth.\n";
	cout << "Year? ";
	cin >> stu.DOB.year;
	cout << "Month? ";
	cin >> stu.DOB.month;
	cout << "Day? ";
	cin >> stu.DOB.day;
	cin.get();

	cout << "Input the student's gender(type 1 if male, 0 if female): ";
	cin >> stu.gender;
	while (stu.gender != 1 && stu.gender != 0)
	{
		cout << "Invalid input! Input the student's gender(type 1 if male, 0 if female): ";
		cin >> stu.gender;
	}
	cin.get();

	stu.password = genPassword(stu.DOB);
	return stu;
}

void addStuNode(StuNode*& pHead, StuNode* pNew)
{
	if (pHead == nullptr)
	{
		pHead = pNew;
		return;
	}
	StuNode* pCur = pHead;
	while (pCur->pNext != nullptr)
		pCur = pCur->pNext;
	pCur->pNext = pNew;
	pCur = pCur->pNext;
	pCur->pNext = nullptr;
}
	
bool stuNodeExists(StuNode* pHead, char* ID)
{
	StuNode* pCur = pHead;
	while (pCur != nullptr)
	{
		if (sameStr(pCur->stu.ID, ID))
			return true;
		pCur = pCur->pNext;
	}
	return false;
}

StuNode* removeStuNode(StuNode*& pHead, char* ID, bool& res)
{
	res = false;
	if (pHead == nullptr)
		return nullptr;
	if (sameStr(pHead->stu.ID, ID))
	{
		StuNode* pDel = pHead;
		pHead = pHead->pNext;
		res = true;
		return pDel;
	}
	StuNode* pCur = pHead;
	while (pCur->pNext != nullptr)
	{
		if (sameStr(pCur->pNext->stu.ID, ID))
		{
			StuNode* pDel = pCur->pNext;
			pCur->pNext = pDel->pNext;
			res = true;
			return pDel;
		}
		pCur = pCur->pNext;
	}
	return nullptr;
}