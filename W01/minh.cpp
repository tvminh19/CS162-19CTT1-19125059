/* -------------------- this is Minh's file for functions ------------------- */
#include "Header.h"

int login(ifstream& in){
     
}

void loadLoginFIle(ifstream& in, student*& student, lecture*& lecture, staff*& staff){
    //
}

void loadStudentFle(ifstream& in, student*& stu){
    in.open("D:\\Github\\CS162-19CTT1-19125059\\W01\\PMS\\menu\\Student.txt");
    if (!in.is_open()){
        cout << "error at line 15 of minh.cpp.\n";
        return;
    }
    else{
        int n;
        in >> n;
        for (int i = 0; i < n; ++i){
            in.ignore(1000, '\n');
            //input name of account
            char a[1000];
            in.get(a, 1000, '\n');
            stu->account = new char[strlen(a) + 1];
            strcpy_s(stu->account, strlen(a) + 1, a);
            //input password of account
            in.ignore(1000, '\n');
            in.get(a, 1000, '\n');
            stu->password = new char[strlen(a) + 1];
            strcpy_s(stu->password, strlen(a) + 1, a);
            //input name of student
            in.ignore(1000, '\n');
            in.get(a, 1000, '\n');
            stu->name = new char[strlen(a) + 1];
            strcpy_s(stu->name, strlen(a) + 1, a);
            //input day of birth with syntax
        }
    }
}

bool checkExistAccount(ifstream& in){

}