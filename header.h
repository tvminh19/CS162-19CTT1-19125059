#pragma once
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

void introDone();
void inputYSC(char year[], char semester[], char className[]);
bool isSameStr(char a[], char b[]);
int ston(char a[]);
void logout();
void outro();