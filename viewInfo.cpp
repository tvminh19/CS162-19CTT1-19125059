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

void deleteStudent(Student stu)
{
	delete[] stu.ID;
	delete[] stu.password;
	delete[] stu.sName;
	delete[] stu.sClass;
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












