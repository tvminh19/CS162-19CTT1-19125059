#pragma once
#include "header.h"

//3.1 Create / delete / view academic years and semesters.
void create_Year_Semester();
bool exist_Year(Year*& pHead, int& n, char* year);
void createNew_Year(Year*& pHead, int& n, char* year);
void delete_Year(Year*& pHead);
bool exist_Semester(Year*& pHead, int& n, char* semester, char* year);
void createNew_Semester(Year*& pHead, int& n, char* semester, char* year);
void delete_Semester(Year*& pHead1);

void delete_Year_Semester();
bool Year_exist(Year*& pHead, int& n);
void Semester_exist(Year*& pHead, int& n, int& m);
void nextStep(Year*& pHead, Year*& pHead1, char* your_choice, char* year, int& n, int& m);
void delete_AYear(Year*& pHead, int& n, char* year);
void delete_ASemester(Year*& pHead1, int& m, char* semester, char* year);
void input_your_choice(char* your_choice);

void view_Year_Semester();
void view_Semester(char* year);

//3.8 View list of courses in the current semester.
void view_Courses();
void output_Schedule(char year[], char semester[], char className[]);
void delete_ScheduleNode(Node*& phead);
void print_Schedule(Node* pHead);
void get_Schedule(char v[], Node*& pHead);
void get_No(ifstream& in, Node*& p, char a[]);
void get_CourseID(ifstream& in, Node*& p, char a[]);
void get_CourseName(ifstream& in, Node*& p, char a[]);
void get_ClassName(ifstream& in, Node*& p, char a[]);
void get_LecUserName(ifstream& in, Node*& p, char a[]);
void get_LecName(ifstream& in, Node*& p, char a[]);
void get_LecGender(ifstream& in, Node*& p, char a[]);
void get_Sdate(ifstream& in, Node*& p, char a[]);
void get_Edate(ifstream& in, Node*& p, char a[]);
void get_DayOfWeek(ifstream& in, Node*& p, char a[]);
void get_STime(ifstream& in, Node*& p, char a[]);
void get_ETime(ifstream& in, Node*& p, char a[]);
void get_Room(ifstream& in, Node*& p, char a[]);
void input_YSC(char year[], char semester[], char className[]);

//3.9 View list of students of a course.
void view_Student();
void show_course(Node*& pHead, char year[], char semester[], char className[]);
void show_schedule(Node* pHead);
void student_course(Node*& pHead1, char year[], char semester[], char className[]);
void get_student_course(char v[], Node*& pHead1);
void get_StuID(ifstream& in, Node*& p, char a[]);
void get_StuName(ifstream& in, Node*& p, char a[]);
void print_S_C(Node* pHead1);
void delete_S_C(Node*& pHead1);

//3.10

//3.11
void get_password(ifstream& in, Node*& p, char a[]);
void get_academy(ifstream& in, Node*& p, char a[]);
void view_Lecturers();
void print_Lecturers(Node* pHead);
void get_Lecturer(Node*& pHead);
void delete_NodeLecturer(Node*& pHead);