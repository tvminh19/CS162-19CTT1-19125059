#pragma once
#include "header.h"
#include "score.h"
#include "students.h"
#include "lecturer.h"

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

//3.2

void aPartOfinputCourse(ifstream& in, Node*& phead, Node*& pcur, char year[], char semester[], char className[]);
void outputSchedule(ofstream& out, Node* phead, char year[], char semester[], char className[]);
void cleanScheduleNode(Node*& phead);
void importFile(Node*& phead, Node*& pcur);
void makeClassAdd(char year[], char semester[], char className[], char fileAdd[]);
bool isExistYear(char year[]);
bool isExistSem(char year[], char sem[]);
bool isExistClass(char className[], char sem[], char year[]);
void inputFileAddress(char a[]);
void getNodeSchedule(ifstream& in, Node*& phead, Node*& pcur);
void getNo(ifstream& in, Node*& p, char a[]);
void getCourseID(ifstream& in, Node*& p, char a[]);
void getCourseName(ifstream& in, Node*& p, char a[]);
void getClassName(ifstream& in, Node*& p, char a[]);
void getLecUserName(ifstream& in, Node*& p, char a[]);
void getLecName(ifstream& in, Node*& p, char a[]);
void getLecGender(ifstream& in, Node*& p, char a[]);
void getSdate(ifstream& in, Node*& p, char a[]);
void getEdate(ifstream& in, Node*& p, char a[]);
void getDayOfWeek(ifstream& in, Node*& p, char a[]);
void getSTime(ifstream& in, Node*& p, char a[]);
void getETime(ifstream& in, Node*& p, char a[]);
void getRoom(ifstream& in, Node*& p, char a[]);