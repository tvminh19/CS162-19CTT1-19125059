#pragma once

#include "header.h"
#include "students.h"
#include "score.h"
#include "courses.h"

struct lecture {
	char* account; //username
	char* password;
	char* name;
	char* academy;
	int gender;
};

//6.7 View a scoreboard
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
void delete_S_B(Node*& pHead);