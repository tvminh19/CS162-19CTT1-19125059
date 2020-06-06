#ifndef _STUDENTS_H_
#define _STUDENTS_H_

#include "header.h"

//7.1 check in
void StuCheckin(char id[]);
void tick(Node*& phead, char id[], Date root);
int ABcompare(Date a, Date b);
void zetoon(Node*& phead, char id[], int numOfWeek);
int numOfStuWeek(Date root, Date now);
Date getTimeNow();
void updateCourse(char fileAdd[], Node* phead, Date root, Time Stime, Time Etime, int numStu);
void loadCourseFile(char fileAdd[], Node*& phead, Date& root, Time& Stime, Time& Etime, int& numStu);
void toKnowSemAndYear(Date now, char year[], char sem[]);

#endif // !_STUDENTS_H_