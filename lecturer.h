#ifndef _lecturer_h_
#define _lecturer_h_

#include "header.h"
#include "students.h"
#include "courses.h"

//6.5 Import scoreboard of a course from a csv file
void choose_course(Node*& pHead1, char year[], char semester[], char className[], char v[]);
void import_scoreboard();
void inputFile_Address(char*& b);
void change_scoreboard(char* b, Node*& pHead);


//6.7 View a scoreboard
void view_scoreboard();
void Stu_S_B(Node*& pHead1, char year[], char semester[], char className[]);
void get_stuaccount(ifstream& in, Node*& p, char a[]);
void get_stuname(ifstream& in, Node*& p, char a[]);
void get_Midterm(ifstream& in, Node*& p);
void get_Final(ifstream& in, Node*& p);
void get_Bonus(ifstream& in, Node*& p);
void get_Total(ifstream& in, Node*& p);
void print_S_B(Node* pHead1);
void delete_S_B(Node*& pHead);
void get_S_B(char v[], Node*& pHead1);



#endif