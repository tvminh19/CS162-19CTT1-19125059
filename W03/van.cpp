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

bool loadStuFile(Student*& stuArr, int& n)
{
	fi.open("Student.txt");
	if (fi.is_open())
	{
		fi >> n;
		fi.get();
		stuArr = new Student[n + 1];
		for (int i = 1; i <= n; i++)
			stuArr[i] = loadStudent();
		fi.close();
		return true;
	}
	return false;
}

void viewStuProf(Student* stuArr, int n, char ID[])
{
	for (int i = 1; i <= n; i++)
		if (sameStr(stuArr[i].ID, ID))
		{
			displayStudent(stuArr[i]);
			return;
		}
}

bool changeStuPassword(Student& stu)
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

void saveStuFile(Student* stuArr, int n)
{
	fo.open("Student.txt");
	if (fo.is_open())
	{
		fo << n << '\n';
		for (int i = 1; i <= n; i++)
			saveStudent(stuArr[i]);
		fo.close();
	}
	else cout << "Can't open student file!\n";
}

staff loadStaff()
{
	staff sta;
	char tmp[1005];
	fi.getline(tmp, 1000, '\n');
	//fi.get();
	sta.account = cpyStr(tmp);

	fi.getline(tmp, 1000, '\n');
	//fi.get();
	sta.password = cpyStr(tmp);

	fi.getline(tmp, 1000, '\n');
	//fi.get();
	sta.name = cpyStr(tmp);

	fi >> sta.gender;
	fi.get();

	return sta;
}

bool loadStaFile(staff*& staArr, int& n)
{
	fi.open("Staff.txt");
	if (fi.is_open())
	{
		fi >> n;
		fi.get();
		staArr = new staff[n + 1];
		for (int i = 1; i <= n; i++)
			staArr[i] = loadStaff();
		fi.close();
		return true;
	}
	return false;
}

void deleteStaff(staff sta)
{
	delete[] sta.account;
	delete[] sta.password;
	delete[] sta.name;
}

void displayStaff(const staff& sta)
{
	cout << "Account: " << sta.account << '\n';
	cout << "Name: " << sta.name << '\n';
	cout << "Gender: "; if (sta.gender) cout << "Female\n"; else cout << "Male\n";
}

void viewStaProf(staff* staArr, int n, char ID[])
{
	for (int i = 1; i <= n; i++)
		if (sameStr(staArr[i].account, ID))
		{
			displayStaff(staArr[i]);
			return;
		}
}

bool changeStaPassword(staff& sta)
{
	if (sta.password == nullptr)
		return false;
	cout << "Enter the old password: ";
	char pass[1005];
	cin.getline(pass, 1000, '\n');
	if (!sameStr(pass, sta.password))
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

	delete[] sta.password;
	sta.password = cpyStr(pass);
	return true;
}

void saveStaff(const staff& sta)
{
	fo << sta.account << '\n';
	fo << sta.password << '\n';
	fo << sta.name << '\n';
	fo << sta.gender << "\n";
}

void saveStaFile(staff* staArr, int n)
{
	fo.open("Staff.txt");
	if (fo.is_open())
	{
		fo << n << '\n';
		for (int i = 1; i <= n; i++)
			saveStaff(staArr[i]);
		fo.close();
	}
	else cout << "Can't open staff file!\n";
}

lecture loadLecturer()
{
	lecture lec;
	char tmp[1005];
	fi.getline(tmp, 1000, '\n');
	//fi.get();
	lec.account = cpyStr(tmp);

	fi.getline(tmp, 1000, '\n');
	//fi.get();
	lec.password = cpyStr(tmp);

	fi.getline(tmp, 1000, '\n');
	//fi.get();
	lec.name = cpyStr(tmp);

	fi.getline(tmp, 1000, '\n');
	//fi.get();
	lec.academy = cpyStr(tmp);

	fi >> lec.gender;
	fi.get();

	return lec;
}

void deleteLecturer(lecture lec)
{
	delete[] lec.account;
	delete[] lec.password;
	delete[] lec.name;
	delete[] lec.academy;
}

void displayLecturer(const lecture& lec)
{
	cout << "Account: " << lec.account << '\n';
	cout << "Name: " << lec.name << '\n';
	cout << "Academy: " << lec.academy << '\n';
	cout << "Gender: "; if (lec.gender) cout << "Female\n"; else cout << "Male\n";
}

bool loadLecFile(lecture*& lecArr, int& n)
{
	fi.open("Lecturer.txt");
	if (fi.is_open())
	{
		fi >> n;
		fi.get();
		lecArr = new lecture[n + 1];
		for (int i = 1; i <= n; i++)
			lecArr[i] = loadLecturer();
		fi.close();
		return true;
	}
	return false;
}

void viewLecProf(lecture* lecArr, int n, char ID[])
{
	for (int i = 1; i <= n; i++)
		if (sameStr(lecArr[i].account, ID))
		{
			displayLecturer(lecArr[i]);
			return;
		}
}

bool changeLecPassword(lecture& lec)
{
	if (lec.password == nullptr)
		return false;
	cout << "Enter the old password: ";
	char pass[1005];
	cin.getline(pass, 1000, '\n');
	if (!sameStr(pass, lec.password))
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

	delete[] lec.password;
	lec.password = cpyStr(pass);
	return true;
}

void saveLecturer(const lecture& lec)
{
	fo << lec.account << '\n';
	fo << lec.password << '\n';
	fo << lec.name << '\n';
	fo << lec.academy << '\n';
	fo << lec.gender << "\n";
}

void saveLecFile(lecture* lecArr, int n)
{
	fo.open("Lecturer.txt");
	if (fo.is_open())
	{
		fo << n << '\n';
		for (int i = 1; i <= n; i++)
			saveLecturer(lecArr[i]);
		fo.close();
	}
	else cout << "Can't open lecturer file!\n";
}

void viewProfile(int accType, char ID[])
{
	int n;
	if (accType == 1)
	{
		Student* stuArr = nullptr;

		if (loadStuFile(stuArr, n))
		{
			viewStuProf(stuArr, n, ID);

			for (int i = 1; i <= n; i++)
				deleteStudent(stuArr[i]);
			delete[] stuArr;
		}
		else cout << "Can't open student file!\n";
	}
	if (accType == 2)
	{
		staff* staArr = nullptr;

		if (loadStaFile(staArr, n))
		{
			viewStaProf(staArr, n, ID);

			for (int i = 1; i <= n; i++)
				deleteStaff(staArr[i]);
			delete[] staArr;
		}
		else cout << "Can't open staff file!\n";
	}
	if (accType == 3)
	{
		lecture* lecArr = nullptr;

		if (loadLecFile(lecArr, n))
		{
			viewLecProf(lecArr, n, ID);

			for (int i = 1; i <= n; i++)
				deleteLecturer(lecArr[i]);
			delete[] lecArr;
		}
		else cout << "Can't open lecturer file!\n";
	}
}



void changePassword(int accType, char ID[])
{
	int n;
	if (accType == 1)
	{
		Student* stuArr = nullptr;

		if (loadStuFile(stuArr, n))
		{
			for (int i = 1; i <= n; i++)
				if (sameStr(stuArr[i].ID, ID))
				{
					if (changeStuPassword(stuArr[i]))
						cout << "Change password successfully!\n";
					else cout << "Failed to change password!\n";
				}

			saveStuFile(stuArr, n);
			for (int i = 1; i <= n; i++)
				deleteStudent(stuArr[i]);
			delete[] stuArr;
		}
		else cout << "Can't open student file!\n";
	}
	if (accType == 2)
	{
		staff* staArr = nullptr;

		if (loadStaFile(staArr, n))
		{
			for (int i = 1; i <= n; i++)
				if (sameStr(staArr[i].account, ID))
				{
					if (changeStaPassword(staArr[i]))
						cout << "Change password successfully!\n";
					else cout << "Failed to change password!\n";
				}

			saveStaFile(staArr, n);
			for (int i = 1; i <= n; i++)
				deleteStaff(staArr[i]);
			delete[] staArr;
		}
		else cout << "Can't open staff file!\n";
	}
	if (accType == 3)
	{
		lecture* lecArr = nullptr;

		if (loadLecFile(lecArr, n))
		{
			for (int i = 1; i <= n; i++)
				if (sameStr(lecArr[i].account, ID))
				{
					if (changeLecPassword(lecArr[i]))
						cout << "Change password successfully!\n";
					else cout << "Failed to change password!\n";
				}

			saveLecFile(lecArr, n);
			for (int i = 1; i <= n; i++)
				deleteLecturer(lecArr[i]);
			delete[] lecArr;
		}
		else cout << "Can't open lecturer file!\n";
	}
}