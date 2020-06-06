#ifndef _SCORE_H_
#define _SCORE_H_

#include "header.h"
#include "courses.h"
#include "students.h"

//4.1 Search and view the scoreboard of a course.
void view_scoreboard();
void Stu_S_B(Node*& pHead1, char year[], char semester[], char className[]);
void get_S_B(char v[], Node*& pHead1);
void get_stuaccount(ifstream& in, Node*& p, char a[]);
void get_stuname(ifstream& in, Node*& p, char a[]);
void get_Midterm(ifstream& in, Node*& p);
void get_Final(ifstream& in, Node*& p);
void get_Bonus(ifstream& in, Node*& p);
void get_Total(ifstream& in, Node*& p);
void print_S_B(Node* pHead1);

//4.2 Export a scoreboard to a csv file.
void export_Score();
void score_course(Node*& pHead1, char year[], char semester[], char className[]);
void export_score_csv(Node*& pHead1, char className[], char* course);


#endif // !_SCORE_H_