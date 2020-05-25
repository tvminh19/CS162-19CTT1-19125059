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

//1.2 view info
void viewProfile(int accType, char ID[]);
bool loadStuFile(Student*& stuArr, int& n);
void viewStuProf(Student* stuArr, int n, char ID[]);
void deleteStudent(Student stu);
bool loadStaFile(staff*& staArr, int& n);
void viewStaProf(staff* staArr, int n, char ID[]);
void deleteStaff(staff sta);

















































