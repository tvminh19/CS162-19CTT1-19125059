#ifndef function
#define function
#include <iostream>
#include <fstream>
#include <string.h>
#include <string>
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

struct Date {
    int day;
    int month;
    int year;
};

struct student {
    char* account;
    char* password;
    char* name;
    char* dob;
    char* className;
    bool gender;
    bool isActive;
};

struct lecture {
    char* account; //username
    char* password;
    char* name;
    char* academy;
    bool gender;
};

struct staff {
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

void notCorrect();
void menuStudent();                     //7
void menuLecturer();                    //6
void Staff_class();                     //2
void Staff_course();                    //3
void Staff_scoreboard();                //4
void Staff_attendanceList();            //5
void menuStaffRole();
void showMenu(int typeAccount);         //1.2
void displayAllroles(int typeAccount);  //1

//W02
struct Time{
    int hours;
    int mins;
};

struct schedule{
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

struct score{
    float midterm;
    float final;
    float bonus;
    float total;
};

struct checkin{
    bool w[10];
};
struct course{
    student* stu;
    score* sco;
    checkin* ck;
    char* timeStudy[10];
};

void Year_Semester();                   //3.1




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