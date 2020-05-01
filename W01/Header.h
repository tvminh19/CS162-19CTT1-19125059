#ifndef function
#define function
#include <iostream>
#include <fstream>
#include <string.h>
#include <typeinfo>
#include <cmath>
#include <cstdlib>
#include <windows.h>
#include <ctime>
using namespace std;

/* ----------------------------- Minh's funtions ---------------------------- */
//W00
//W01
struct student{
    char* account;
    char* password;
    char* name;
    char* dob;
    char* className;
    bool sexual;
};

struct lecture{
    char* account;
    char* password;
    char* name;
    char* academy;
    bool sexual;
};

struct staff{
    char* account;
    char* password;
    char* name;
    bool sexual;
};

int login(ifstream& in, student*& stu, lecture*& lec, staff*& sta);









/* ------------------------------ Vu's funtions ----------------------------- */








/* ----------------------------- Van's functions ---------------------------- */











#endif //function