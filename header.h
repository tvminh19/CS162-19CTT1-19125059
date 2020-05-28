#ifndef _HEADER_H_
#define _HEADER_H_

#include <iostream>
#include <fstream>
#include <string.h>
#include <iomanip>
#include <string>
#include <cstring>
#include <conio.h>
#include <cmath>
#include <cstdlib>
#include <windows.h>
#include <ctime>
#pragma warning (disable : 4996)
using namespace std;

struct Time {
	int hours;
	int mins;
};

struct Year {
	char* years;
	char* semesters;
	Year* pNext;
};

struct student {
	char* account;
	char* password;
	char* name;
	char* dob;
	char* className;
	int gender;
	int isActive;
};

struct Date {
	int day;
	int month;
	int year;
};

struct Student
{
	char* userName;
	char* password;
	char* ID;
	char* sName;
	Date DOB;
	char* sClass;
	int gender; // 1 if female
};

struct checkin {
	bool w[10];
};


struct staff {
	char* account;
	char* password;
	char* name;
	int gender;
};

struct score {
	float midterm;
	float final;
	float bonus;
	float total;
};

struct scoreboard {
	student* stu;
	int isActive;
	score* sco;
	int went2class[12];
};

struct lecture {
	char* account; //username
	char* password;
	char* name;
	char* academy;
	int gender;
};

struct schedule {
	int no;
	char* courseID;
	char* courseName;
	char* Class;
	lecture* lec;
	Date Sdate;
	Date Edate;
	char* dayofweek;
	Time Stime;
	Time Etime;
	char* room;
};

struct Node {
	student* stu;
	scoreboard* scb;
	schedule* schedule;
	Node* next = nullptr;
};

struct StuNode
{
	Student stu;
	StuNode* pNext = nullptr;
};

int main();
void introDone();
void inputYSC(char year[], char semester[], char className[]);
bool isSameStr(char a[], char b[]);
int ston(char a[]);
void logout();
void outro();

#endif // !_HEADER_H_

