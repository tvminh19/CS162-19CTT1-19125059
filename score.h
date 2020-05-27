#pragma once
#include "header.h"
#include "score.h"
#include "students.h"
#include "courses.h"

struct score {
	float midterm;
	float final;
	float bonus;
	float total;
};

struct scoreboard {
	student* stu;
	int isActive;
	score* sco;
	int went2class[12];
};

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
