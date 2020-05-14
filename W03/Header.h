#ifndef function
#define function
#include <iostream>
#include <fstream>
#include <string.h>
#include <string>
#include <cstring>
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
bool isSameStr(char a[], char b[]);

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
    int gender;
    int isActive;
};

struct lecture {
    char* account; //username
    char* password;
    char* name;
    char* academy;
    int gender;
};

struct staff {
    char* account;
    char* password;
    char* name;
    int gender;
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
bool isSameStr(char a[], char b[]);

//3.2 input course
void inputCourse();

//3.3 input a new course
void addANewCourse();



/* ------------------------------ Vu's funtions ----------------------------- */
//W01

void notCorrect();
void menuStudent();                                 //7
void menuLecturer();                                //6
void Staff_class();                                 //2
void Staff_course();                                //3
void Staff_scoreboard();                            //4
void Staff_attendanceList();                        //5
void menuStaffRole();
void showMenu(int typeAccount);                     //1.2
void displayAllroles(int typeAccount, char ID[]);   //1

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

//W03

struct Year {
    char* years;
    char* semesters;
    Year* pNext;
};

void create_Year_Semester();
bool exist_Year(Year*& pHead, int& n, char* year);
void createNew_Year(Year*& pHead, int& n, char* year);
void delete_Year(Year*& pHead);
bool exist_Semester(Year*& pHead, int& n, char* semester, char* year);
void createNew_Semester(Year*& pHead, int& n, char* semester, char* year);
void delete_Semester(Year*& pHead);


/* ----------------------------- Van's functions ---------------------------- */
// W02

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


bool loadStuFile(Student*& stuArr, int& n);
void viewStuProf(Student* stuArr, int n, char ID[]);
bool changeStuPassword(Student& stu);
void saveStuFile(Student* stuArr, int n);

staff loadStaff();
bool loadStaFile(staff*& staArr, int& n);

void displayStaff(const staff& sta);

void viewStaProf(staff* staArr, int n, char ID[]);

bool changeStaPassword(staff& sta);

void saveStaff(const staff& sta);
void saveStaFile(staff* staArr, int n);

void deleteStaff(staff sta);


lecture loadLecturer();
bool loadLecFile(lecture*& lecArr, int& n);

void displayLecturer(const lecture& lec);

void viewLecProf(lecture* lecArr, int n, char ID[]);

bool changeLecPassword(lecture& lec);

void saveLecturer(const lecture& lec);
void saveLecFile(lecture* lecArr, int n);

void deleteLecturer(lecture lec);


void viewProfile(int accType, char ID[]);
void changePassword(int accType, char ID[]);



/* ----------------------------- this is nothing ---------------------------- */
struct Node{
    student* stu;
    schedule* schedule;
    Node* next = nullptr;
};

#endif //function