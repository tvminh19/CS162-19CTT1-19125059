/* -------------------- this is Van's file for functions ------------------- */
#include "Header.h"

using namespace std;

ifstream fi;
ofstream fo;

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
		index++;										// in case there's any spaces or special charaters between the datas

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

	index += len + 1;  // move over the next comma
	return sClass;
}

int getGender(char str[], int& index)
{
	return str[index] - '0'; // 1 is female, 0 is male
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

void createAccount(Student& stu)
{
	int len = strlen(stu.ID);
	stu.account.userName = new char[len + 2];
	for (int i = 0; i < len; i++)
		stu.account.userName[i] = stu.ID[i];
	stu.account.userName[len] = '\0';

	//cout << "Username: " << stu.account.userName << '\n';

	stu.account.password = genPassword(stu.DOB);
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
	createAccount(stu);

	return stu;
}

void displayAccount(const Student& stu)
{
	cout << "Username: " << stu.account.userName << '\n';
	cout << "Password: " << stu.account.password << '\n';
}

void displayStudent(const Student& stu)
{
	cout << "ID: " << stu.ID << '\n';
	cout << "Name: " << stu.sName << '\n';
	cout << "DOB: " << stu.DOB.day << "/" << stu.DOB.month << "/" << stu.DOB.year << '\n';
	cout << "Class: " << stu.sClass << '\n';
	cout << "Gender: "; if (stu.gender) cout << "Female\n"; else cout << "Male\n";
}

bool importClass(StuNode*& pHead, int& n)
{
	fi.open("19CTT1-Student.csv");
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
		cout << "Can't open csv file to import!\n";
		return false;
	}
}

char* cpyStr(char str[])
{
	int len = strlen(str);
	char* str2 = new char[len + 2];
	for (int i = 0; i < len; i++)
		str2[i] = str[i];
	str2[len] = '\0';
	return str2;
}

bool sameStr(char* str1, char* str2)
{
	if (str1 == nullptr || str2 == nullptr)
		return false;
	if (strlen(str1) != strlen(str2))
		return false;
	int len = strlen(str1);
	for (int i = 0; i < len; i++)
		if (str1[i] != str2[i])
			return false;
	return true;
}

Student loadStudent()
{
	Student stu;
	char tmp[1005];
	fi.getline(tmp, 1000, '\n');
	//fi.get();
	stu.account.userName = cpyStr(tmp);

	fi.getline(tmp, 1000, '\n');
	//fi.get();
	stu.account.password = cpyStr(tmp);

	fi.getline(tmp, 1000, '\n');
	//fi.get();
	stu.ID = cpyStr(tmp);

	fi.getline(tmp, 1000, '\n');
	//fi.get();
	stu.sName = cpyStr(tmp);

	fi >> stu.DOB.year >> stu.DOB.month >> stu.DOB.day;
	fi.get();

	fi.getline(tmp, 1000, '\n');
	//fi.get();
	stu.sClass = cpyStr(tmp);

	fi >> stu.gender;
	fi.get();

	return stu;
}

void loadClass(StuNode*& pHead, int& n)
{
	fi.open("19CTT1-Student.txt");
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
				pHead->stu = loadStudent();
				pHead->pNext = nullptr;
				pCur = pHead;
			}
			else
			{
				pCur->pNext = new StuNode;
				pCur = pCur->pNext;
				pCur->stu = loadStudent();
				pCur->pNext = nullptr;
			}
			mem--;
			fi.get();
		}

		fi.close();
	}
	else cout << "Can't open txt file to load student!\n";
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

bool loginStu(StuNode* pHead, char userName[], char password[], StuNode*& pStu)
{
	StuNode* pCur = pHead;
	while (pCur != nullptr && !sameStr(pCur->stu.account.userName, userName))
		pCur = pCur->pNext;
	if (pCur == nullptr || !sameStr(pCur->stu.account.password, password))
		return false;
	pStu = pCur;
	return true;
}


bool changePassword(Student& stu)
{
	if (stu.account.password == nullptr)
		return false;
	cout << "Enter the old password: ";
	char pass[1005];
	cin.getline(pass, 1000, '\n');
	if (!sameStr(pass, stu.account.password))
		return false;
	while (1)
	{
		cout << "Enter the new password: ";
		cin.getline(pass, 1000, '\n');
		char pass2[1005];
		cout << "Enter the new password again to confirm: ";
		cin.getline(pass2, 1000, '\n');
		if (sameStr(pass, pass2))
			break;
		cout << "The new passwords don't match! Try again!\n";
	}

	delete[] stu.account.password;
	stu.account.password = cpyStr(pass);
	return true;
}

void saveStudent(const Student& stu)
{
	fo << stu.account.userName << '\n';
	fo << stu.account.password << '\n';
	fo << stu.ID << '\n';
	fo << stu.sName << '\n';
	fo << stu.DOB.year << ' ' << stu.DOB.month << ' ' << stu.DOB.day << '\n';
	fo << stu.sClass << '\n';
	fo << stu.gender << "\n\n";
}

void saveClass(StuNode* pHead, const int& n)
{
	fo.open("19CTT1-Student.txt");
	if (fo.is_open())
	{
		fo << n << '\n';
		StuNode* pCur = pHead;
		while (pCur != nullptr)
		{
			saveStudent(pCur->stu);
			pCur = pCur->pNext;
		}
		fo.close();
	}
	else cout << "Can't open txt file to save the class!\n";
}


void deleteStudent(Student stu)
{
	delete[] stu.account.userName;
	delete[] stu.account.password;
	delete[] stu.ID;
	delete[] stu.sName;
	delete[] stu.sClass;
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
