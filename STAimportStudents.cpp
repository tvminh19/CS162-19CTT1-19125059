#include "header.h"
#include "allroles.h"
#include "class.h"

ifstream fi;
ofstream fo;

void importAndSave()
{
	char year[15], seme[11], className[15];

	inputYSC(year, seme, className);

	char dirD[] = "D:/Github/CS162-19CTT1-19125059/ZPMS/";
	char d[505] = "";
	strcat_s(d, 500, dirD);
	strcat_s(d, 500, year);
	strcat_s(d, 500, "/");
	strcat_s(d, 500, seme);
	strcat_s(d, 500, "/");
	strcat_s(d, 500, className);
	strcat_s(d, 500, "\\");
	strcat_s(d, 500, "Student.txt");

	StuNode* pHead = nullptr;
	int n_stu, n_all;
	importClass(pHead, n_stu);

	saveClass(pHead, n_stu, d);    // Individual class saved.

	char loginStuAdd[] = { "D:/Github/CS162-19CTT1-19125059/ZPMS/menu/Student.txt" };
	StuNode* pAll = nullptr;
	loadClass(pAll, n_all, loginStuAdd);
	int added = 0;

	mergeList(pAll, pHead, added);
	n_all += added;
	n_stu -= added;
	cout << "These students has the ID that is already in the list! Please check again!\n";
	displayClass(pHead, n_stu);
	system("pause");

	saveClass(pAll, n_all, loginStuAdd);

	introDone();

	deleteStuNodes(pAll);
	deleteStuNodes(pHead);
}

bool importClass(StuNode*& pHead, int& n)
{
	char csvAdd[205];
	cout << "We are going to import a csv file of a class.\n";
	cout << "Enter the csv file address: ";
	takeFileAdd(csvAdd);
	fi.open(csvAdd);
	if (fi.is_open())
	{
		fi.ignore(1000, '\n'); // ignore the title row first
		fi.get();

		char str[1005];
		StuNode* pCur = nullptr;
		n = 0; // total number of students

		while (!fi.eof())
		{
			fi.getline(str, 1000, '\n');
			fi.get();
			++n;
			if (pHead == nullptr)
			{
				pHead = new StuNode;
				pHead->stu = importStudent(str);
				pHead->pNext = nullptr;
				pCur = pHead;
			}
			else
			{
				pCur->pNext = new StuNode;
				pCur = pCur->pNext;
				pCur->stu = importStudent(str);
				pCur->pNext = nullptr;
			}
		}

		fi.close();
		return true;
	}
	else
	{
		cout << "Can't open csv file to import!\nThe file path might be incorrect!\nPlease enter the right path!\n";
		return false;
	}
}

void takeFileAdd(char fileAdd[])
{
	char str[205];
	cin.getline(str, 200, '\n');
	int id = 0;
	for (int i = 0; i < strlen(str); i++)
		if (str[i] == '\\')
		{
			fileAdd[id++] = '\\';
			fileAdd[id++] = '\\';
		}
		else fileAdd[id++] = str[i];
	fileAdd[id] = '\0';
}

Student importStudent(char str[])
{
	Student stu;
	int index = 0;
	while (str[index] != ',')
		index++;				 // ignore the No. column
	++index;

	stu.ID = getID(str, index);
	stu.sName = getsName(str, index);
	stu.DOB = getDOB(str, index);
	stu.sClass = getsClass(str, index);
	stu.gender = getGender(str, index);
	stu.password = genPassword(stu.DOB);

	return stu;
}

char* getID(char str[], int& index)
{
	int len = 0;
	while (str[index + len] != ',')
		len++;							// get the length of the ID

	char* ID = new char[len + 2];
	for (int i = 0; i < len; i++)
		ID[i] = str[index + i];
	ID[len] = '\0';

	index += len + 1;  // move over the next comma
	return ID;
}

char* getsName(char str[], int& index)
{
	int len = 0;
	while (str[index + len] != ',')
		len++;							// get the length of the name

	char* sName = new char[len + 2];
	for (int i = 0; i < len; i++)
		sName[i] = str[index + i];
	sName[len] = '\0';

	index += len + 1;  // move over the next comma
	return sName;
}

Date getDOB(char str[], int& index)
{
	Date DOB;
	DOB.year = 0;
	DOB.month = 0;
	DOB.day = 0;

	while (str[index] >= '0' && str[index] <= '9')
		DOB.year = DOB.year * 10 + (int)(str[index++] - '0');
	while (!(str[index] >= '0' && str[index] <= '9'))
		index++;										// in case there's any spaces or special characters between the data

	while (str[index] >= '0' && str[index] <= '9')
		DOB.month = DOB.month * 10 + (int)(str[index++] - '0');
	while (!(str[index] >= '0' && str[index] <= '9'))
		index++;

	while (str[index] >= '0' && str[index] <= '9')
		DOB.day = DOB.day * 10 + (int)(str[index++] - '0');
	while (str[index] != ',')
		index++;
	index++; // move over the next comma

	//cout << "DOB: " << stu.DOB.day << "/" << stu.DOB.month << "/" << stu.DOB.year << '\n';
	return DOB;
}

char* getsClass(char str[], int& index)
{
	int len = 0;
	while (str[index + len] != ',')
		len++;							// get the length of the class name

	char* sClass = new char[len + 2];
	for (int i = 0; i < len; i++)
		sClass[i] = str[index + i];
	sClass[len] = '\0';

	//cout << stu.sClass << '\n';

	index = len + 1;  // move over the next comma
	return sClass;
}

int getGender(char str[], int& index)
{
	return str[index] - '0'; // 1 is male, 0 is female
}

char* genPassword(Date DOB)
{
	char* pass = new char[10];
	int len = 0;
	pass[len++] = (char)('0' + DOB.year / 1000); DOB.year %= 1000;
	pass[len++] = (char)('0' + DOB.year / 100); DOB.year %= 100;
	pass[len++] = (char)('0' + DOB.year / 10); DOB.year %= 10;
	pass[len++] = (char)('0' + DOB.year);
	pass[len++] = (char)('0' + DOB.month / 10);
	pass[len++] = (char)('0' + DOB.month % 10);
	pass[len++] = (char)('0' + DOB.day / 10);
	pass[len++] = (char)('0' + DOB.day % 10);
	pass[len] = '\0';
	//cout << "Password: " << pass << '\n';
	return pass;
}

void saveClass(StuNode* pHead, const int& n, char fileAdd[])
{
	fo.open(fileAdd);
	fo << n << '\n';
	StuNode* pCur = pHead;
	while (pCur != nullptr)
	{
		saveStudent(pCur->stu, fo);
		pCur = pCur->pNext;
	}
	fo.close();
}

void loadClass(StuNode*& pHead, int& n, char fileAdd[])
{
	fi.open(fileAdd);
	if (fi.is_open())
	{
		fi >> n;
		fi.get();
		int mem = n;
		StuNode* pCur = nullptr;
		while (mem > 0)
		{
			if (pHead == nullptr)
			{
				pHead = new StuNode;
				pHead->stu = loadStudent(fi);
				pHead->pNext = nullptr;
				pCur = pHead;
			}
			else
			{
				pCur->pNext = new StuNode;
				pCur = pCur->pNext;
				pCur->stu = loadStudent(fi);
				pCur->pNext = nullptr;
			}
			mem--;
			fi.get();
		}

		fi.close();
	}
	else cout << "Can't open text file to load student!\n";
}

void mergeList(StuNode*& pH1, StuNode*& pH2, int& added)
{
	if (pH1 == nullptr)
	{
		pH1 = pH2;
		pH2 = nullptr;
		return;
	}
	if (pH2 == nullptr)
		return;
	StuNode* pCur = pH1;
	while (pCur->pNext != nullptr)
		pCur = pCur->pNext;					   // at the end of the whole big list...

	while (pH2 != nullptr && !findStuNode(pH1, pH2))
	{
		StuNode* pTmp = pH2;
		pH2 = pH2->pNext;
		pCur->pNext = pTmp;
		pCur = pCur->pNext;
		pCur->pNext = nullptr;
		added++;
	}

	if (pH2 == nullptr)
		return;
	StuNode* pCur2 = pH2;
	while (pCur2->pNext != nullptr)
	{
		if (!findStuNode(pH1, pCur2->pNext))
		{
			StuNode* pTmp = pCur2->pNext;
			pCur2->pNext = pTmp->pNext;
			pTmp->pNext = nullptr;
			pCur->pNext = pTmp;
			pCur = pCur->pNext;
			added++;
		}
		else pCur2 = pCur2->pNext;
	}
}

void displayClass(StuNode* pHead, const int& n)
{
	cout << n << '\n';
	StuNode* pCur = pHead;
	while (pCur != nullptr)
	{
		displayStudent(pCur->stu);
		pCur = pCur->pNext;
		cout << '\n';
	}
}

void deleteStuNodes(StuNode*& pHead)
{
	StuNode* pCur;
	while (pHead != nullptr)
	{
		pCur = pHead;
		pHead = pHead->pNext;
		deleteStudent(pCur->stu);
		delete pCur;
	}
}

bool findStuNode(StuNode* pHead, StuNode* pStu)
{
	StuNode* pCur = pHead;
	while (pCur != nullptr)
	{
		if (sameStr(pCur->stu.ID, pStu->stu.ID))
			return true;
		pCur = pCur->pNext;
	}
	return false;
}