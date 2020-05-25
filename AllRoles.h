#pragma once
#include "header.h"
#include "students.h"
#include "staff.h"
#include "lecturer.h"

//1.1 login
int menu(int& typeAcc, char id[]);
void introLogin();
int login(ifstream& in, student*& stu, lecture*& lec, staff*& sta, int& result, int& countLogin, char id[]);
bool safeInput(char a[]);
int ston(char a[]);
bool isSameStr(char a[], char b[]);
void loadLoginFile(ifstream& in, student*& stu, lecture*& lec, staff*& sta, int& n1, int& n2, int& n3);
void introMenu();
void inputLogin(char user[], char passwd[]);
int checkExistAccount(student*& stu, lecture*& lec, staff*& sta, int& n1, int& n2, int& n3, char id[], char pass[], char name[], bool& gender); int resultLogin(ifstream& in, int& result, int& countLogin, bool gender, char nameLogin[], student*& stu, lecture*& lec, staff*& sta, int n1, int n2, int n3);
void loadStudentFile(ifstream& in, student*& stu, int& n1);
void loadLectureFile(ifstream& in, lecture*& lec, int& n2);
void loadStaffFile(ifstream& in, staff*& sta, int& n3);
void outro();
void logout();
void removeLogin(student*& stu, lecture*& lec, staff*& sta, int n1, int n2, int n3);
void timeNow();

//1.3 view info
void viewProfile(int accType, char ID[]);
bool loadStuFile(Student*& stuArr, int& n);
void viewStuProf(Student* stuArr, int n, char ID[]);
void deleteStudent(Student stu);
bool loadStaFile(staff*& staArr, int& n);
void viewStaProf(staff* staArr, int n, char ID[]);
void deleteStaff(staff sta);
bool loadLecFile(lecture*& lecArr, int& n);
void viewLecProf(lecture* lecArr, int n, char ID[]);
void deleteLecturer(lecture lec);
bool sameStr(char* str1, char* str2);
void displayStudent(const Student& stu);
staff loadStaff(ifstream& fi);
void displayStaff(const staff& sta);
Student loadStudent(ifstream& fi);
lecture loadLecturer(ifstream& fi);
char* cpyStr(char str[]);
void displayLecturer(const lecture& lec);
void displayDate(Date date);

// 1.4 Change Password
void changePassword(int accType, char ID[]);

bool changeStuPassword(Student& stu);
void saveStuFile(Student* stuArr, int n);
void saveStudent(const Student& stu, ofstream& fo);

bool changeStaPassword(staff& sta);
void saveStaFile(staff* staArr, int n);
void saveStaff(const staff& sta, ofstream& fo);

bool changeLecPassword(lecture& lec);
void saveLecFile(lecture* lecArr, int n);
void saveLecturer(const lecture& lec, ofstream& fo);

void inputAndHidePass(char password[]);
void saveDate(Date date, ofstream& fo);
















































