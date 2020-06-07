#ifndef _STUDENTS_H_
#define _STUDENTS_H_

#include "header.h"

//7.1 check in
void StuCheckin(char id[]);
bool tick(Node*& phead, char id[], Date root);
int ABcompare(Date a, Date b);
void zetoon(Node*& phead, char id[], int numOfWeek);
int numOfStuWeek(Date root, Date now);
Date getTimeNow();
void updateCourse(char fileAdd[], Node* phead, Date root, Time Stime, Time Etime, int numStu);
void loadCourseFile(char fileAdd[], Node*& phead, Date& root, Time& Stime, Time& Etime, int& numStu);
void toKnowSemAndYear(Date now, char year[], char sem[]);
void inputC(char year[], char semester[], char className[]);

//7.2 view checkin result
void outResult(char fileAdd[], Node* phead, char id[], Date root);
bool checkView(Node*& phead, char id[], Date root);
void StuViewCheckin(char id[]);

//7.3 view schedule
void StuViewCheckin();

//7.4 View his/her scores of a course.
bool check_stuaccount(Node* pHead1, char ID[]);
void view_result(char ID[]);
void StuViewCheckin(char id[]);

#endif // !_STUDENTS_H_