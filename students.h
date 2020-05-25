#pragma once

struct student {
	char* account;
	char* password;
	char* name;
	char* dob;
	char* className;
	int gender;
	int isActive;
};

struct Date {
	int day;
	int month;
	int year;
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