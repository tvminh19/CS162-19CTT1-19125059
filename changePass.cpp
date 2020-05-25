#include "allroles.h"

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
	ofstream fo("D:/Github/CS162-19CTT1-19125059/ZPMS/menu/Student.txt");
	if (fo.is_open())
	{
		fo << n << '\n';
		for (int i = 1; i <= n; i++)
			saveStudent(stuArr[i], fo);
		fo.close();
	}
	else cout << "Can't open student file!\n";
	fo.close();
}

void saveStudent(const Student& stu, ofstream& fo)
{
	fo << stu.ID << '\n';
	fo << stu.password << '\n';
	fo << stu.sName << '\n';
	saveDate(stu.DOB, fo);
	fo << stu.sClass << '\n';
	fo << stu.gender << "\n";
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

void saveStaFile(staff* staArr, int n)
{
	ofstream fo("D:/Github/CS162-19CTT1-19125059/ZPMS/menu/Staff.txt");
	if (fo.is_open())
	{
		fo << n << '\n';
		for (int i = 1; i <= n; i++)
			saveStaff(staArr[i], fo);
		fo.close();
	}
	else cout << "Can't open staff file!\n";
}

void saveStaff(const staff& sta, ofstream& fo)
{
	fo << sta.account << '\n';
	fo << sta.password << '\n';
	fo << sta.name << '\n';
	fo << sta.gender << "\n";
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

void saveLecFile(lecture* lecArr, int n)
{
	ofstream fo("D:/Github/CS162-19CTT1-19125059/ZPMS/menu/Lecturer.txt");
	if (fo.is_open())
	{
		fo << n << '\n';
		for (int i = 1; i <= n; i++)
			saveLecturer(lecArr[i], fo);
		fo.close();
	}
	else cout << "Can't open lecturer file!\n";
}

void saveLecturer(const lecture& lec, ofstream& fo)
{
	fo << lec.account << '\n';
	fo << lec.password << '\n';
	fo << lec.name << '\n';
	fo << lec.academy << '\n';
	fo << lec.gender << "\n";
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

void saveDate(Date date, ofstream& fo)
{
	fo << date.year << ' ';
	if (date.month < 10) fo << '0'; fo << date.month << ' ';
	if (date.day < 10) fo << '0'; fo << date.day << '\n';
}