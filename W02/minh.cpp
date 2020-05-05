/* -------------------- this is Minh's file for functions ------------------- */
#include "header.h"
/* ---------------------------- string to number ---------------------------- */

int ston(char a[]) {
    int sum = 0;
    for (int i = 0; i < strlen(a); ++i) {
        a[i] -= '0';
        sum += a[i];
        sum *= 10;
    }
    return sum / 10;
}

/* ------------------------------- safe input ------------------------------- */
bool safeInput(char a[]) {
    for (int i = 0; i < strlen(a); ++i) {
        //difference number [0~9]
        if (48 <= a[i] && a[i] >= 57)   return false;
    }
    return true;
}


/* ---------------------------------- outro --------------------------------- */
void outro(){
    system("cls");
    introLogin();
    cout << "===================\n";
    cout << "+ Thank for using +\n";
    cout << "===================\n";
    system("pause");
}

/* --------------------------- check exist account -------------------------- */
bool checkSame(char a[], char b[]){
    if (strlen(a) != strlen(b)) return false;
    else {
        for (int i = 0; i < strlen(a); i++){
            if (a[i] != b[i]) return false;
        }
        return true;
    }
}

int checkExistAccount(student*& stu, lecture*& lec, staff*& sta, int& n1, int& n2, int& n3, char id[], char pass[], char name[], bool& gender) {
    //student
    for (int i = 0; i < n1; ++i){
        if (checkSame(stu[i].account, id) && checkSame(stu[i].password, pass)){
            strcpy(name, stu[i].name);
            strcpy(id, stu[i].account);
            gender = stu[i].gender;
            return 1;
        }
    }

    //lecture 
    for (int i = 0; i < n2; ++i){
        if (checkSame(lec[i].account, id) && checkSame(lec[i].password, pass)){
            strcpy(name, lec[i].name);
            strcpy(id, lec[i].account);
            gender = lec[i].gender;
            return 2;
        }
    }

    //staff
    for (int i = 0; i < n3; ++i){
        if (checkSame(sta[i].account, id) && checkSame(sta[i].password, pass)){
            strcpy(name, sta[i].name);
            strcpy(id, sta[i].account);
            gender = sta[i].gender;
            return 3;
        }
    }

    return 0;
}

/* ------------------ remove heap memory in login functions ----------------- */
void removeLogin(student*& stu, lecture*& lec, staff*& sta, int n1, int n2, int n3){
    //delete student
    for (int i = 0; i < n1; i++){
        delete[] stu[i].account;
        delete[] stu[i].password;
        delete[] stu[i].name;
        delete[] stu[i].className;
        delete[] stu[i].dob;
    }
    //delete lecture
    for (int i = 0; i < n2; i++){
        delete[] lec[i].account;
        delete[] lec[i].password;
        delete[] lec[i].name;
        delete[] lec[i].academy;
    }
    //delete staff
    for (int i = 0; i < n3; i++){
        delete[] sta[i].account;
        delete[] sta[i].password;
        delete[] sta[i].name;
    }
    delete[] sta;
    delete[] stu;
    delete[] lec;
}

/* -------------------------------- load file ------------------------------- */
void loadStaffFile(ifstream& in, staff*& sta, int& n3){
    in.open("D:\\Github\\CS162-19CTT1-19125059\\W02\\PMS\\menu\\Staff.txt");
    if (!in.is_open()){
        cout << "error at line 107 of minh.cpp.\n";
        return;
    }
    else {
        in >> n3;
        sta = new staff[n3];
        for (int i = 0; i < n3; ++i){
            in.ignore(1000, '\n');

            //input name of account
            char a[1000];
            in.get(a, 1000, '\n');
            sta[i].account = new char[strlen(a) + 1];
            strcpy(sta[i].account, a);

            //input password of account
            in.ignore(1000, '\n');
            in.get(a, 1000, '\n');
            sta[i].password = new char[strlen(a) + 1];
            strcpy(sta[i].password, a);

            //input name
            in.ignore(1000, '\n');
            in.get(a, 1000, '\n');
            sta[i].name = new char[strlen(a) + 1];
            strcpy(sta[i].name, a);

            //input gender
            in >> sta[i].gender;
        }
    }
    in.close();
}

void loadLectureFile(ifstream& in, lecture*& lec, int& n2){
    in.open("D:\\Github\\CS162-19CTT1-19125059\\W02\\PMS\\menu\\Lecturer.txt");
    if (!in.is_open()){
        cout << "error at line 111 of minh.cpp.\n";
        return;
    }
    else {
        in >> n2;
        lec = new lecture[n2];
        for (int i = 0; i < n2; ++i){
            in.ignore(1000, '\n');

            //input name of account
            char a[1000];
            in.get(a, 1000, '\n');
            lec[i].account = new char[strlen(a) + 1];
            strcpy(lec[i].account, a);

            //input password of account
            in.ignore(1000, '\n');
            in.get(a, 1000, '\n');
            lec[i].password = new char[strlen(a) + 1];
            strcpy(lec[i].password, a);

            //input name
            in.ignore(1000, '\n');
            in.get(a, 1000, '\n');
            lec[i].name = new char[strlen(a) + 1];
            strcpy(lec[i].name, a);

            //input academy
            in.ignore(1000, '\n');
            in.get(a, 1000, '\n');
            lec[i].academy = new char[strlen(a) + 1];
            strcpy(lec[i].academy, a);

            //input gender
            in >> lec[i].gender;
        }
    }
    in.close();
}

void loadStudentFile(ifstream& in, student*& stu, int& n1){
    in.open("D:\\Github\\CS162-19CTT1-19125059\\W02\\PMS\\menu\\Student.txt");
    if (!in.is_open()){
        cout << "error at line 154 of minh.cpp.\n";
        return;
    }
    else {
        in >> n1;
        stu = new student[n1];
        for (int i = 0; i < n1; ++i){
            in.ignore(1000, '\n');

            //input name of account
            char a[1000];
            in.get(a, 1000, '\n');
            stu[i].account = new char[strlen(a) + 1];
            strcpy(stu[i].account, a);

            //input password of account
            in.ignore(1000, '\n');
            in.get(a, 1000, '\n');
            stu[i].password = new char[strlen(a) + 1];
            strcpy(stu[i].password, a);

            //input name of student
            in.ignore(1000, '\n');
            in.get(a, 1000, '\n');
            stu[i].name = new char[strlen(a) + 1];
            strcpy(stu[i].name, a);

            //input day of birth with syntax  yyyy/mm/dd
            in.ignore(1000, '\n');
            in.get(a, 1000, '\n');
            stu[i].dob = new char[strlen(a) + 1];
            strcpy(stu[i].dob, a);

            //input class name  
            in.ignore(1000, '\n');
            in.get(a, 1000, '\n');
            stu[i].className = new char[strlen(a) + 1];
            strcpy(stu[i].className, a);

            //input gender
            in >> stu[i].gender;
        }
    }
    in.close();
}

void loadLoginFile(ifstream& in, student*& stu, lecture*& lec, staff*& sta, int& n1, int& n2, int& n3){
    loadStudentFile(in, stu, n1);
    loadLectureFile(in, lec, n2);
    loadStaffFile(in, sta, n3);
}

/* ------------------------------ to know time ------------------------------ */
void timeNow(){
    time_t now = time(0);
    tm* cptr = localtime(&now);
    int t = cptr->tm_hour;
    if (0 <= t && t <= 11) {
        cout << "Good morning, ";
    }
    else if (12 <= t && t <= 18){
        cout << "Good afternoon, ";
    }
    else {
        cout << "Good evening, ";
    }
}

/* --------------- show display hello then remove heap memory --------------- */
int resultLogin(ifstream& in, int& result, int& countLogin, bool gender, char nameLogin[], student*& stu, lecture*& lec, staff*& sta, int n1, int n2, int n3) {
    if (result == 0) {
        char choosen;
        if (countLogin != 0){
            cout << "========================\n";
            cout << "Sorry, Wrong account!\n";
            cout << "Do you want to try again (y/n) ?\n";
            cout << "> ";
            cin >> choosen;
        }
        else {
            cout << "You have exceeded the number of times allowed!\n";
            return 0;
        }
        if (choosen == 'y' || choosen == 'Y'){
            //remove before you make a new once
            removeLogin(stu, lec, sta, n1, n2, n3);
            cin.ignore();
            system("cls");
            cout << "You have " << countLogin << " time(s) to try!\n";
            countLogin--;
            return login(in, stu, lec, sta, result, countLogin, nameLogin);
        }
        else {
            outro();
            return 0;
        }
    }
    else {
        system("cls");
        cout << "===========================================\n";
        timeNow();
        if (gender) {
            cout << "Mr.";
        }
        else {
            cout << "Ms.";
        }
        cout << nameLogin << "!" << endl;
        cout << "===========================================\n";
        Sleep(1000);
        system("pause");
    }
    //remove in heap memory
    removeLogin(stu, lec, sta, n1, n2, n3);
    //return funciton 
    return result;
}

/* --------------------- input id and pass from keyboard -------------------- */
void inputLogin(char user[], char passwd[]){
    int ch;
    int pos = 0;
    cout << "User name: \n";
    cout << "> ";
    cin.get(user, 200, '\n');
    cout << "Password: \n";
    cout << "> ";
    while (ch = getch()){
        if (ch == 8 && strlen(passwd) - 1 == 0){
            continue;
        }
        else if (ch == 13){
            break;
        }
        else if (ch == 8 && strlen(passwd) > 0){
            passwd[pos--] = '\0';
            cout << "\b \b";
        }
        else {
            cout << "*";
            passwd[pos++] = ch;
        }
    }
    passwd[pos] = '\0';
    cout << "\n";
    return;
}

/* ---------------------------- intro when login ---------------------------- */
void introLogin() {
    cout << "================================================================================\n";
    cout << "+ ----------------------- This is final project - cs162 ---------------------- +\n";
    cout << "+ ------------------------------- from M2V Team ------------------------------ +\n";
    cout << "================================================================================\n";
    system("pause");
    system("cls");
}

void introMenu(){
    system("cls");
    cout << "/* ========================================================================== */\n";
    cout << "/* ---------------------------------- LOADING ------------------------------- */\n";
    cout << "/* ========================================================================== */\n";
    Sleep(600);
    system("cls");
}

/* ----------------------------- login function ----------------------------- */
int login(ifstream& in, student*& stu, lecture*& lec, staff*& sta, int& result, int& countLogin, char id[]) {
    //slots of account
    int n1, n2, n3;

    //make color
    system("color a");

    //load file 
    loadLoginFile(in, stu, lec, sta, n1, n2, n3);

    //check replay main function
    if (countLogin == 4){
        //intro
        introMenu();

        //reback isFirst
        countLogin--;
    }
    //input from keyboard
    char pass[200];
    inputLogin(id, pass);

    //check if account is exist
    char name[20];
    bool gender;
    result = checkExistAccount(stu, lec, sta, n1, n2, n3, id, pass, name, gender);

    //result and compele funtions
    resultLogin(in, result, countLogin, gender, name, stu, lec, sta, n1, n2, n3);
    return 0;
}

/* ---------------------------- log out functions --------------------------- */
void logout(){
    return;
}

/* ---------------------------------- menu ---------------------------------- */
int menu(int& typeAcc, char id[]) {

    //setup color and I/O file
    system("color a");
    ifstream in;
    ofstream out;

    //struct
    student* stu = nullptr;
    lecture* lec = nullptr;
    staff* sta = nullptr;

    //DO_NOT change countLogin !!! => some bug if you change
    int countLogin = 4;

    //menu function
    system("cls");
    introLogin();
    cout << "=~=~=~=~=~=~=~=~=\n";
    cout << "+  [1]. Login.  +\n";
    cout << "+  [2]. Exit.   +\n";
    cout << "=~=~=~=~=~=~=~=~=\n";
    cout << "> ";

    //input 
    char n[3];
    cin.get(n, 3, '\n');
    while (!safeInput(n)) {
        system("cls");
        cout << "=~=~=~=~=~=~=~=~=~=~=~=~=~=\n";
        cout << "+ Wrong! please try again +\n";
        cout << "=~=~=~=~=~=~=~=~=~=~=~=~=~=\n";
        cout << "=~=~=~=~=~=~=~=~=\n";
        cout << "+  [1]. Login.  +\n";
        cout << "+  [2]. Exit.   +\n";
        cout << "=~=~=~=~=~=~=~=~=\n";
        cout << "> ";
        cin.ignore(1000, '\n');
        cin.get(n, 3, '\n');
    }
    if (safeInput(n) && ston(n) == 1){
        cin.ignore(1000, '\n');
        login(in, stu, lec, sta, typeAcc, countLogin, id);
    }
    else{
        outro();
        typeAcc = 0;
        logout();
    }
    return 0;
}

