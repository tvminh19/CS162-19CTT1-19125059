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

void inputAndHidePass(char password[])
{
	int ch;
	int pos = 0;
	while (ch = getch()) {
		if (ch == 8 && strlen(password) - 1 == 0) {
			continue;
		}
		else if (ch == 13) {
			break;
		}
		else if (ch == 8 && strlen(password) > 0) {
			password[pos--] = '\0';
			cout << "\b \b";
		}
		else {
			cout << "*";
			password[pos++] = ch;
		}
	}
	password[pos] = '\0';
	cout << "\n";
	return;
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
	cout << "Gender: "; if (stu.gender == 0) cout << "Female\n"; else cout << "Male\n";
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
	fo << stu.gender << "\n";
}

void saveClass(StuNode* pHead, const int& n, char fileAdd[])
{
	fo.open(fileAdd);
	fo << n << '\n';
	StuNode* pCur = pHead;
	while (pCur != nullptr)
	{
		saveStudent(pCur->stu);
		pCur = pCur->pNext;
	}
	fo.close();
}

void create_Year_Semester_Class(char*& year, char*& semester)
{
	system("cls");

	char tmpY[500];
	cout << "Year: ";
	cin.ignore(1000, '\n');              //Notice this shit
	cin.get(tmpY, 500, '\n');
	year = new char[strlen(tmpY) + 1];
	strcpy(year, tmpY);
	int n = 0;

	// YEAR
	Year* pHead = NULL;
	if (!exist_Year(pHead, n, year))
	{
		// create new year
		createNew_Year(pHead, n, year);
		cout << "New year folder is created!\n";
	}
	else
	{
		cout << "Please continue!\n" << endl;
	}
	delete_Year(pHead);

	// SEMESTER
	char tmpS[500];
	cout << "Semester: ";
	cin.ignore(100, '\n');
	cin.get(tmpS, 500, '\n');
	semester = new char[strlen(tmpS) + 1];
	strcpy(semester, tmpS);

	n = 0;
	Year* pHead1 = NULL;
	if (!exist_Semester(pHead1, n, semester, year))
	{
		createNew_Semester(pHead1, n, semester, year);
		cout << "New semester folder is created!\n";
		//introDone();
	}
	else
	{
		cout << "Please continue!\n" << endl;
		// Sleep(500);
		// system("pause");
	}
	delete_Semester(pHead1);
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

void importAndSave()
{
	char year[15], seme[11], className[15];

	inputYSC(year, seme, className);

	char dirD[] = "D:\\Github\\CS162-19CTT1-19125059\\ZPMS\\";
	char d[500] = "";
	strcat(d, dirD);
	strcat(d, year);
	strcat(d, "\\");
	strcat(d, seme);

	char tmp[500] = "";
	strcat(tmp, d);
	strcat(tmp, "\\Class.txt");

	fo.open(tmp);
	fo.close();

	int n;
	char** classList;
	bool exist = false;
	fi.open(tmp);
	fi >> n;
	fi.get();
	cout << n << "\n";
	classList = new char* [n + 2];
	for (int i = 1; i <= n; i++)
		classList[i] = new char[15];

	cout << "Still works thou2!\n";
	for (int i = 1; i <= n; i++)
		fi.getline(classList[i], 14, '\n');
	for (int i = 1; i <= n; i++)
		if (sameStr(classList[i], className))
		{
			exist = true;
			break;
		}
		else cout << "Can't open input file!\n";
	fi.close();

	cout << "Still works thou3!\n";

	if (!exist)
	{
		fo.open(tmp);
		fo << n + 1 << '\n';
		for (int i = 1; i <= n; i++)
			fo << classList[i] << '\n';
		fo << className << '\n';
		fo.close();

		strcat(d, "\\");
		strcat(d, className);
		CreateDirectoryA(d, NULL);
		cout << "New class folder is created!\n";

		StuNode* pHead = nullptr;
		int n_stu, n_all;
		importClass(pHead, n_stu);

		strcat(d, "\\");
		strcat(d, "Student.txt");

		saveClass(pHead, n_stu, d);    // Individual class saved.

		char loginStuAdd[] = { "D:\\Github\\CS162-19CTT1-19125059\\ZPMS\\menu\\Student.txt" };
		StuNode* pAll = nullptr;
		loadClass(pAll, n_all, loginStuAdd);
		int added = 0;

		mergeList(pAll, pHead, added);
		n_all += added;
		n -= added;
		cout << "These students has the ID that is already in the list! Please check again!\n";
		displayClass(pHead, n);
		system("pause");

		saveClass(pAll, n_all, loginStuAdd);

		introDone();

		deleteStuNodes(pAll);
		deleteStuNodes(pHead);
	}
	else
	{
		cout << "The class already exists!\n";
		system("pause");
	}

	for (int i = 1; i <= n; i++)
		delete[] classList[i];
	delete[] classList;

	delete[] year;
	delete[] seme;
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
	fi.open("D:/Github/CS162-19CTT1-19125059/ZPMS/menu/Student.txt");
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
	fi.close();
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
	inputAndHidePass(pass);
	if (!sameStr(pass, stu.password))
		return false;
	while (1)
	{
		cout << "Enter the new password: ";
		inputAndHidePass(pass);
		char pass2[1005];
		cout << "Enter the new password again to confirm: ";
		inputAndHidePass(pass2);
		if (sameStr(pass, pass2))
			break;
		else {
			system("cls");
			cout << "The new passwords don't match! Try again!\n";
		}
	}

	delete[] stu.password;
	stu.password = cpyStr(pass);
	return true;
}

void saveStuFile(Student* stuArr, int n)
{
	fo.open("D:/Github/CS162-19CTT1-19125059/ZPMS/menu/Student.txt");
	if (fo.is_open())
	{
		fo << n << '\n';
		for (int i = 1; i <= n; i++)
			saveStudent(stuArr[i]);
		fo.close();
	}
	else cout << "Can't open student file!\n";
	fo.close();
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
	fi.open("D:/Github/CS162-19CTT1-19125059/ZPMS/menu/Staff.txt");
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
	fi.close();
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
	cout << "Gender: "; if (sta.gender == 0) cout << "Female\n"; else cout << "Male\n";
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
	inputAndHidePass(pass);
	if (!sameStr(pass, sta.password))
		return false;
	while (1)
	{
		cout << "Enter the new password: ";
		inputAndHidePass(pass);
		char pass2[1005];
		cout << "Enter the new password again to confirm: ";
		inputAndHidePass(pass2);
		if (sameStr(pass, pass2))
			break;
		else {
			system("cls");
			cout << "The new passwords don't match! Try again!\n";
		}
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
	fo.open("D:/Github/CS162-19CTT1-19125059/ZPMS/menu/Staff.txt");
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
	cout << "Gender: "; if (lec.gender == 0) cout << "Female\n"; else cout << "Male\n";
}

bool loadLecFile(lecture*& lecArr, int& n)
{
	fi.open("D:/Github/CS162-19CTT1-19125059/ZPMS/menu/Lecturer.txt");
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
	fi.close();
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
	inputAndHidePass(pass);
	if (!sameStr(pass, lec.password))
		return false;
	while (1)
	{
		cout << "Enter the new password: ";
		inputAndHidePass(pass);
		char pass2[1005];
		cout << "Enter the new password again to confirm: ";
		inputAndHidePass(pass2);
		if (sameStr(pass, pass2))
			break;
		else {
			system("cls");
			cout << "The new passwords don't match! Try again!\n";
		}
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
	fo.open("D:/Github/CS162-19CTT1-19125059/ZPMS/menu/Lecturer.txt");
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
	system("cls");
	cout << "=== information === \n";
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
	else if (accType == 3)
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
	else if (accType == 2)
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
	cout << "===================\n";
	system("pause");
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
					system("pause");
				}

			saveStuFile(stuArr, n);
			for (int i = 1; i <= n; i++)
				deleteStudent(stuArr[i]);
			delete[] stuArr;
		}
		else cout << "Can't open student file!\n";
	}
	if (accType == 3)
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
	if (accType == 2)
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
	system("pause");
}

//2.1 - 2.2

