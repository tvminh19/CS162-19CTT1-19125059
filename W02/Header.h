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
    bool gender;
};

struct lecture{
    char* account;
    char* password;
    char* name;
    char* academy;
    bool gender; 
};

struct staff{
    char* account;
    char* password;
    char* name;
    bool gender;
};

//menu function
int menu(int& typeAcc, char id[]);

//intro
void introLogin();

//sub function in menu function
int login(ifstream& in, student*& stu, lecture*& lec, staff*& sta, int& result, int& countLogin, char id[]);

//safe to check input
bool safeInput(char a[]);

//string to number
int ston(char a[]);

//check is same string
bool checkSame(char a[], char b[]);




/* ------------------------------ Vu's funtions ----------------------------- */
//W01
void displayAllroles(int typeAccount);
void menuStaffRole();







/* ----------------------------- Van's functions ---------------------------- */
// W02

struct Account
{
    char* userName;
    char* password;
};

struct Student
{
    Account account;
    char* ID;
    char* sName;
    Date DOB;
    char* sClass;
    int gender; // 1 if female
};

struct StuNode
{
    Student stu;
    StuNode* pNext = nullptr;
};

char* getID(char str[], int& index);
char* getsName(char str[], int& index);
Date getDOB(char str[], int& index);
char* getsClass(char str[], int& index);
char* genPassword(Date DOB);
void createAccount(Student& stu);

void displayAccount(const Student& stu);
void displayStudent(const Student& stu);
void displayClass(StuNode* pHead, const int& n);

Student importStudent(char str[]);
bool importClass(StuNode*& pHead, int& n);

void saveStudent(const Student& stu);
void saveClass(StuNode* pHead, const int& n);

char* cpyStr(char str[]);
bool sameStr(char* str1, char* str2);

Student loadStudent();
void loadClass(StuNode*& pHead, int& n);

bool loginStu(StuNode* pHead, char userName[], char password[], StuNode*& pStu);
bool changePassword(Student& stu);


void deleteStudent(Student stu);
void deleteStuNodes(StuNode*& pHead);

#endif //function