#ifndef function
#define function
#include <iostream>
#include <fstream>
#include <string.h>
#include <conio.h>
#include <cmath>
#include <cstdlib>
#include <windows.h>
#include <ctime>
#pragma warning (disable : 4996)
using namespace std;

/* ----------------------------- Minh's funtions ---------------------------- */
//W00
//W01

struct Date{
    int day;
    int month;
    int year;
};

struct student{
    char* account;
    char* password;
    char* name;
    char* dob;
    char* className;
    bool sexual;
};

struct lecture{
    char* account;
    char* password;
    char* name;
    char* academy;
    bool sexual; 
};

struct staff{
    char* account;
    char* password;
    char* name;
    bool sexual;
};

int menu(int& typeAcc);
int login(ifstream& in, student*& stu, lecture*& lec, staff*& sta, int& result, int& countLogin);







/* ------------------------------ Vu's funtions ----------------------------- */
void displayAllroles(int typeAccount);
void menuStaffRole();







/* ----------------------------- Van's functions ---------------------------- */











#endif //function