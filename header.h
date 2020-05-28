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

struct Date {
	int day;
	int month;
	int year;
};

struct Year {
	char* years;
	char* semesters;
	Year* pNext;
};

void introDone();
void inputYSC(char year[], char semester[], char className[]);
bool isSameStr(char a[], char b[]);
int ston(char a[]);
void logout();
void outro();

#endif // !_HEADER_H_

