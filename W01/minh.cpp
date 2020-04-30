/* -------------------- this is Minh's file for functions ------------------- */
#include "Header.h"



/* --------------------------- check exist account -------------------------- */
bool checkSame(char a[], char b[]){
    if (strlen(a) != strlen(b)) return false;
    else{
        for (int i = 0; i < strlen(a); i++){
            if (a[i] != b[i]) return false;
        }
        return true;
    }
}

int checkExistAccount(student*& stu, lecture*& lec, staff*& sta, int& n1, int& n2, int& n3, char id[], char pass[]){
    //student
    for (int i = 0; i < n1; i++){
        if (checkSame(stu[i].account, id) && checkSame(stu[i].password, pass)){
            return 1;
        }
    }

    //lecture 
    for (int i = 0; i < n2; ++i){
        if (checkSame(lec[i].account, id), checkSame(lec[i].password, pass)){
            return 2;
        } 
    }

    //staff
    for (int i = 0; i < n3; ++i){
        if (checkSame(sta[i].account, id), checkSame(sta[i].password, pass)){
            return 3;
        }
    }
    
    return 0;
}

/* ------------------ remove heap memory in login functions ----------------- */
void removeLogin(student*& stu, lecture*& lec, staff*& sta, int n1, int n2, int n3){
    //delete student
    for (int i = 0; i < n1; i++){
        delete stu[i].account;
        delete stu[i].password;
        delete stu[i].name;
        delete stu[i].dob;
        delete stu[i].className;
    }
    delete[] stu;
    //delete lecture
    for (int i = 0; i < n2; i++){
        delete lec[i].account;
        delete lec[i].password;
        delete lec[i].name;
        delete lec[i].academy;
    }
    delete[] lec;
    //delete staff
    for (int i = 0; i < n3; i++){
        delete sta[i].account;
        delete sta[i].password;
        delete sta[i].name;
    }
    delete[] sta;
}

/* -------------------------------- load file ------------------------------- */
void loadStaffFile(ifstream& in, staff*& sta, int& n3){
    in.open("D:\\Github\\CS162-19CTT1-19125059\\W01\\PMS\\menu\\Staff.txt");
    if (!in.is_open()){
        cout << "error at line 107 of minh.cpp.\n";
        return;
    }
    else{
        in >> n3;
        sta = new staff[n3];
        for (int i = 0; i < n3; ++i){
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

void loadLectureFile(ifstream& in, lecture*& lec, int& n2){
    in.open("D:\\Github\\CS162-19CTT1-19125059\\W01\\PMS\\menu\\Lecturer.txt");
    if (!in.is_open()){
        cout << "error at line 64 of minh.cpp.\n";
        return;
    }
    else{
        in >> n2;
        lec = new lecture[n2];
        for (int i = 0; i < n2; ++i){
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

void loadStudentFile(ifstream& in, student*& stu, int& n1){
    in.open("D:\\Github\\CS162-19CTT1-19125059\\W01\\PMS\\menu\\Student.txt");
    if (!in.is_open()){
        cout << "error at line 15 of minh.cpp.\n";
        return;
    }
    else{
        in >> n1;
        stu = new student[n1];
        for (int i = 0; i < n1; ++i){
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

void loadLoginFile(ifstream& in, student*& stu, lecture*& lec, staff*& sta, int& n1, int& n2, int& n3){
    loadStudentFile(in, stu, n1);
    loadLectureFile(in, lec, n2);
    loadStaffFile(in, sta, n3);
}

/* ----------------------------- login function ----------------------------- */
int login(ifstream& in, student*& stu, lecture*& lec, staff*& sta){
    //load file 
    int n1, n2, n3;
    loadLoginFile(in, stu, lec, sta, n1, n2, n3);

    //intro
    cout << "--------------------------------------------------\n";
    cout << "------------------- WELCOME ----------------------\n";
    cout << "---------------- TO MINI MODDLE ------------------\n";
    cout << "--------------------------------------------------\n";
    system("clr");

    //input from keyboard
    //ID
    cout << "ID: ";
    char id[200];
    cin.get(id, 200, '\n');
    //password
    cout << "Password: ";
    char pass[200];
    cin.ignore(200, '\n');
    cin.get(pass, 200, '\n');

    //check if account is exist
    int result = checkExistAccount(stu, lec, sta, n1, n2, n3, id, pass);
    //control
    if (result == 0){
        cout << "Sorry, Wrong account!\n";
        return 0;
    }
    else{
        return result;
    }
    //remove in heap memory
    removeLogin(stu, lec, sta, n1, n2, n3);
}
