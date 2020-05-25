#include "allroles.h"

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

bool loadStuFile(Student*& stuArr, int& n)
{
	ifstream fi("D:/Github/CS162-19CTT1-19125059/ZPMS/menu/Student.txt");
	if (fi.is_open())
	{
		fi >> n;
		fi.get();
		stuArr = new Student[n + 1];
		for (int i = 1; i <= n; i++)
			stuArr[i] = loadStudent(fi);
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

void deleteStudent(Student stu)
{
	delete[] stu.ID;
	delete[] stu.password;
	delete[] stu.sName;
	delete[] stu.sClass;
}

bool loadStaFile(staff*& staArr, int& n)
{
	ifstream fi("D:/Github/CS162-19CTT1-19125059/ZPMS/menu/Staff.txt");
	if (fi.is_open())
	{
		fi >> n;
		fi.get();
		staArr = new staff[n + 1];
		for (int i = 1; i <= n; i++)
			staArr[i] = loadStaff(fi);
		fi.close();
		return true;
	}
	fi.close();
	return false;
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

void deleteStaff(staff sta)
{
	delete[] sta.account;
	delete[] sta.password;
	delete[] sta.name;
}

bool loadLecFile(lecture*& lecArr, int& n)
{
	ifstream fi("D:/Github/CS162-19CTT1-19125059/ZPMS/menu/Lecturer.txt");
	if (fi.is_open())
	{
		fi >> n;
		fi.get();
		lecArr = new lecture[n + 1];
		for (int i = 1; i <= n; i++)
			lecArr[i] = loadLecturer(fi);
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

void deleteLecturer(lecture lec)
{
	delete[] lec.account;
	delete[] lec.password;
	delete[] lec.name;
	delete[] lec.academy;
}

Student loadStudent(ifstream& fi)
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

void displayStudent(const Student& stu)
{
	cout << "ID: " << stu.ID << '\n';
	cout << "Name: " << stu.sName << '\n';
	cout << "DOB: "; displayDate(stu.DOB);
	cout << "Class: " << stu.sClass << '\n';
	cout << "Gender: "; if (stu.gender == 0) cout << "Female\n"; else cout << "Male\n";
}

staff loadStaff(ifstream& fi)
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

void displayStaff(const staff& sta)
{
	cout << "Account: " << sta.account << '\n';
	cout << "Name: " << sta.name << '\n';
	cout << "Gender: "; if (sta.gender == 0) cout << "Female\n"; else cout << "Male\n";
}

lecture loadLecturer(ifstream& fi)
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

char* cpyStr(char str[])
{
	int len = strlen(str);
	char* str2 = new char[len + 2];
	for (int i = 0; i < len; i++)
		str2[i] = str[i];
	str2[len] = '\0';
	return str2;
}

void displayDate(Date date)
{
	if (date.day < 10) cout << '0'; cout << date.day << '/';
	if (date.month < 10) cout << '0'; cout << date.month << '/';
	cout << date.year << '\n';
}

void displayLecturer(const lecture& lec)
{
	cout << "Account: " << lec.account << '\n';
	cout << "Name: " << lec.name << '\n';
	cout << "Academy: " << lec.academy << '\n';
	cout << "Gender: "; if (lec.gender == 0) cout << "Female\n"; else cout << "Male\n";
}























