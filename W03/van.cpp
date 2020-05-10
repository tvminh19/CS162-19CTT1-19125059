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

void displayAccount(const Student& stu)
{
	cout << "Username: " << stu.ID << '\n';
	cout << "Password: " << stu.password << '\n';
}

void displayDate(Date date)
{
	if (date.day < 10) cout << '0'; cout << date.day << '/';
	if (date.month < 10) cout << '0'; cout << date.month << '/';
	cout << date.year << '\n';
}

void displayStudent(const Student& stu)
{
	cout << "ID: " << stu.ID << '\n';
	cout << "Name: " << stu.sName << '\n';
	cout << "DOB: "; displayDate(stu.DOB);
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
	stu.ID = cpyStr(tmp);

	fi.getline(tmp, 1000, '\n');
	//fi.get();
	stu.password = cpyStr(tmp);

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
	while (pCur != nullptr && !sameStr(pCur->stu.ID, userName))
		pCur = pCur->pNext;
	if (pCur == nullptr || !sameStr(pCur->stu.password, password))
		return false;
	pStu = pCur;
	return true;
}


bool changePassword(Student& stu)
{
	if (stu.password == nullptr)
		return false;
	cout << "Enter the old password: ";
	char pass[1005];
	cin.getline(pass, 1000, '\n');
	if (!sameStr(pass, stu.password))
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

	delete[] stu.password;
	stu.password = cpyStr(pass);
	return true;
}

void saveDate(Date date)
{
	fo << date.year << ' ';
	if (date.month < 10) fo << '0'; fo << date.month << ' ';
	if (date.day < 10) fo << '0'; fo << date.day << '\n';
}

void saveStudent(const Student& stu)
{
	fo << stu.ID << '\n';
	fo << stu.password << '\n';
	fo << stu.sName << '\n';
	saveDate(stu.DOB);
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
	delete[] stu.ID;
	delete[] stu.password;
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