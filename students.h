#ifndef _STUDENTS_H_
#define _STUDENTS_H_

#include "header.h"

struct student {
	char* account;
	char* password;
	char* name;
	char* dob;
	char* className;
	int gender;
	int isActive;
};

struct Student
{
	char* userName;
	char* password;
	char* ID;
	char* sName;
	Date DOB;
	char* sClass;
	int gender; // 1 if female
};

struct checkin {
	bool w[10];
};


#endif // !_STUDENTS_H_