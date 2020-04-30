/* -------------------- this is Minh's file for functions ------------------- */
#include "Header.h"

/* ----------------------------- login function ----------------------------- */
int login(ifstream& in, student*& stu, lecture*& lec, staff*& sta){
     loadLoginFile(in, stu, lec, sta);
}

/* -------------------------------- load file ------------------------------- */
void loadLoginFile(ifstream& in, student*& stu, lecture*& lec, staff*& sta){
    loadStudentFile(in, stu);
    loadLectureFile(in, lec);
    loadStaffFile(in, sta);
}

void loadStudentFile(ifstream& in, student*& stu){
    in.open("D:\\Github\\CS162-19CTT1-19125059\\W01\\PMS\\menu\\Student.txt");
    if (!in.is_open()){
        cout << "error at line 15 of minh.cpp.\n";
        return;
    }
    else{
        int n;
        in >> n;
        stu = new student[n];
        for (int i = 0; i < n; ++i){
            in.ignore(1000, '\n');

            //input name of account
            char a[1000];
            in.get(a, 1000, '\n');
            stu[i].account = new char[strlen(a) + 1];
            strcpy_s(stu[i].account, strlen(a) + 1, a);

            //input password of account
            in.ignore(1000, '\n');
            in.get(a, 1000, '\n');
            stu[i].password = new char[strlen(a) + 1];
            strcpy_s(stu[i].password, strlen(a) + 1, a);

            //input name of student
            in.ignore(1000, '\n');
            in.get(a, 1000, '\n');
            stu[i].name = new char[strlen(a) + 1];
            strcpy_s(stu[i].name, strlen(a) + 1, a);

            //input day of birth with syntax  yyyy/mm/dd
            in.ignore(1000, '\n');
            in.get(a, 1000, '\n');
            stu[i].dob = new char[strlen(a) + 1];
            strcpy_s(stu[i].dob, strlen(a) + 1, a);

            //input class name  
            in.ignore(1000, '\n');
            in.get(a, 1000, '\n');
            stu[i].className = new char[strlen(a) + 1];
            strcpy_s(stu[i].className, strlen(a) + 1, a);

            //input sexual
            in >> stu[i].sexual;
        }
    }
    in.close();
}

void loadLectureFile(ifstream& in, lecture*& lec){
    in.open("D:\\Github\\CS162-19CTT1-19125059\\W01\\PMS\\menu\\Lecturer.txt");
    if (!in.is_open()){
        cout << "error at line 64 of minh.cpp.\n";
        return;
    }
    else{
        int n;
        in >> n;
        lec = new lecture[n];
        for (int i = 0; i < n; ++i){
            in.ignore(1000, '\n');

            //input name of account
            char a[1000];
            in.get(a, 1000, '\n');
            lec[i].account = new char[strlen(a) + 1];
            strcpy_s(lec[i].account, strlen(a) + 1, a);

            //input password of account
            in.ignore(1000, '\n');
            in.get(a, 1000, '\n');
            lec[i].password = new char[strlen(a) + 1];
            strcpy_s(lec[i].password, strlen(a) + 1, a);

            //input name
            in.ignore(1000, '\n');
            in.get(a, 1000, '\n');
            lec[i].name = new char[strlen(a) + 1];
            strcpy_s(lec[i].name, strlen(a) + 1, a);

            //input academy
            in.ignore(1000, '\n');
            in.get(a, 1000, '\n');
            lec[i].academy = new char[strlen(a) + 1];
            strcpy_s(lec[i].academy, strlen(a) + 1, a);

            //input sexual
            in >> lec[i].sexual;
        }
    }
    in.close();
}

void loadStaffFile(ifstream& in, staff*& sta){
    in.open("D:\\Github\\CS162-19CTT1-19125059\\W01\\PMS\\menu\\Staff.txt");
    if (!in.is_open()){
        cout << "error at line 107 of minh.cpp.\n";
        return;
    }
    else{
        int n;
        in >> n;
        sta = new staff[n];
        for (int i = 0; i < n; ++i){
            in.ignore(1000, '\n');

            //input name of account
            char a[1000];
            in.get(a, 1000, '\n');
            sta[i].account = new char[strlen(a) + 1];
            strcpy_s(sta[i].account, strlen(a) + 1, a);

            //input password of account
            in.ignore(1000, '\n');
            in.get(a, 1000, '\n');
            sta[i].password = new char[strlen(a) + 1];
            strcpy_s(sta[i].password, strlen(a) + 1, a);

            //input name
            in.ignore(1000, '\n');
            in.get(a, 1000, '\n');
            sta[i].name = new char[strlen(a) + 1];
            strcpy_s(sta[i].name, strlen(a) + 1, a);

            //input sexual
            in >> sta[i].sexual;
        }
    }
    in.close();
}

/* --------------------------- check exist account -------------------------- */
bool checkExistAccount(ifstream& in){

}