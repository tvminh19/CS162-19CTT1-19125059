
/* -------------------- this is Minh's file for functions ------------------- */
#include "header.h"
/* ---------------------------- string to number ---------------------------- */

//intro Done
void introDone(){
    system("cls");
    cout << "+=======================================+\n";
    cout << "+------------------DONE-----------------+\n";
    cout << "+=======================================+\n";
    system("pause");
}

//count line
int countLine(ifstream& in, int group){
    char a[200];
    int count = 0;
    while (!in.eof()){
        in.getline(a, 200);
        ++count;
    }
    return count / group;
}

//conver strong to number
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
bool isSameStr(char a[], char b[]){
    if (strlen(a) != strlen(b)) return false;
    for (int i = 0; i < strlen(a); ++i){
        if (a[i] != b[i]) return false;
    }
    return true;
}

int checkExistAccount(student*& stu, lecture*& lec, staff*& sta, int& n1, int& n2, int& n3, char id[], char pass[], char name[], bool& gender) {
    //student
    for (int i = 0; i < n1; ++i){
        if (isSameStr(stu[i].account, id) && isSameStr(stu[i].password, pass)){
            strcpy(name, stu[i].name);
            strcpy(id, stu[i].account);
            gender = stu[i].gender;
            return 1;
        }
    }

    //lecture 
    for (int i = 0; i < n2; ++i){
        if (isSameStr(lec[i].account, id) && isSameStr(lec[i].password, pass)){
            strcpy(name, lec[i].name);
            strcpy(id, lec[i].account);
            gender = lec[i].gender;
            return 2;
        }
    }

    //staff
    for (int i = 0; i < n3; ++i){
        if (isSameStr(sta[i].account, id) && isSameStr(sta[i].password, pass)){
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

/* -------------------------------------------------------------------------- */
/*                        INPUT COURSE FROM A CSV FILE                        */
/* -------------------------------------------------------------------------- */

//ask class
void inputClassName(char a[]){
    cin.ignore(100, '\n');
    cout << "Please enter the name of class: ";
    cin.get(a, 10, '\n');
}

//check is exist class
bool isExistClass(ifstream& in, char className[], char sem[], char year[]){
    char fileAdd[500];
    strcat(fileAdd, "D:/Github/CS162-19CTT1-19125059/ZPMS/");
    strcat(fileAdd, year);
    strcat(fileAdd, "/");
    strcat(fileAdd, sem);
    strcat(fileAdd, "/");
    strcat(fileAdd, "class.txt");
    in.open(fileAdd);
    if (!in.is_open()){
        cout << "Error at checkClassExist function.\n";
        return false;
    }
    else{
        int n;
        in >> n;
        char str[10];
        
        for (int i = 0; i < n; i++){
            in.ignore(100, '\n');
            in.get(str, 10, '\n');
            if (isSameStr(str, a)) return true;
        }
        return false;
    }
    in.close();
}

//ask file address
void inputFileAddress(char a[]){
    cin.ignore(100, '\n');
    cout << "File address: ";
    cin.get(a, 100, '\n');
}

//getNo
void getNo(ifstream& in, Node*& p, char a[]){
    p->schedule = new schedule;
    in.get(a, 200, ',');
    p->schedule->no = ston(a);
    //cout << p->schedule->no << "\n";
}

//get Course ID
void getCourseID(ifstream& in, Node*& p, char a[]){
    in.ignore(200, ',');
    in.get(a, 200, ',');
    p->schedule->courseID = new char[strlen(a) + 1];
    strcpy(p->schedule->courseID, a);
    //cout << p->schedule->courseID << "\n";
}

//get course name
void getCourseName(ifstream& in, Node*& p, char a[]){
    in.ignore(200, ',');
    in.get(a, 200, ',');
    p->schedule->courseName = new char[strlen(a) + 1];
    strcpy(p->schedule->courseName, a);
    //cout << p->schedule->courseName << "\n";
}

//get class
void getClassName(ifstream& in, Node*& p, char a[]){
    in.ignore(200, ',');
    in.get(a, 200, ',');
    p->schedule->Class = new char[strlen(a) + 1];
    strcpy(p->schedule->Class, a);
    //cout << p->schedule->Class << "\n";
}

//get lec user name
void getLecUserName(ifstream& in, Node*& p, char a[]){
    p->schedule->lec = new lecture;

    in.ignore(200, ',');
    in.get(a, 200, ',');
    p->schedule->lec->account = new char[strlen(a) + 1];
    strcpy(p->schedule->lec->account, a);
    //cout << p->schedule->lec->account << "\n";
}

//get lec name
void getLecName(ifstream& in, Node*& p, char a[]){
    in.ignore(200, ',');
    in.get(a, 200, ',');
    p->schedule->lec->name = new char[strlen(a) + 1];
    strcpy(p->schedule->lec->name, a);
    //cout << p->schedule->lec->name << "\n";
}

//get lec gender
void getLecGender(ifstream& in, Node*& p, char a[]){
    in.ignore(200, ',');
    in.get(a, 200, ',');
    p->schedule->lec->gender = ston(a);
}

//get Start date
void getSdate(ifstream& in, Node*& p, char a[]){
    //start day month year
    in.ignore(200, ',');
    in.get(a, 200, '/');
    p->schedule->Sdate.day = ston(a);
    //cout << p->schedule->Sdate.day << "\n";

    in.ignore(200, '/');
    in.get(a, 200, '/');
    p->schedule->Sdate.month = ston(a);
    //cout << p->schedule->Sdate.month << "\n";

    in.ignore(200, '/');
    in.get(a, 200, ',');
    p->schedule->Sdate.year = ston(a);
    //cout << p->schedule->Sdate.year << "\n";
}

//get End date
void getEdate(ifstream& in, Node*& p, char a[]){
    //start day month year
    in.ignore(200, ',');
    in.get(a, 200, '/');
    p->schedule->Edate.day = ston(a);
    //cout << p->schedule->Edate.day << "\n";

    in.ignore(200, '/');
    in.get(a, 200, '/');
    p->schedule->Edate.month = ston(a);
    //cout << p->schedule->Edate.month << "\n";

    in.ignore(200, '/');
    in.get(a, 200, ',');
    p->schedule->Edate.year = ston(a);
    //cout << p->schedule->Edate.year << "\n";
}

//get day of week
void getDayOfWeek(ifstream& in, Node*& p, char a[]){
    in.ignore(200, ',');
    in.get(a, 200, ',');
    p->schedule->dayofweek = new char[strlen(a) + 1];
    strcpy(p->schedule->dayofweek, a);
    //cout << p->schedule->dayofweek << "\n";
}

//get Start time
void getSTime(ifstream& in, Node*& p, char a[]){
    //start time hour and min
    in.ignore(200, ',');
    in.get(a, 200, ',');
    p->schedule->Stime.hours = ston(a);
    //cout << p->schedule->Stime.hours << "\n";

    in.ignore(200, ',');
    in.get(a, 200, ',');
    p->schedule->Stime.mins = ston(a);
    //cout << p->schedule->Stime.mins << "\n";
}

//get end time
void getETime(ifstream& in, Node*& p, char a[]){
    //start time hour and min
    in.ignore(200, ',');
    in.get(a, 200, ',');
    p->schedule->Etime.hours = ston(a);
    //cout << p->schedule->Etime.hours << "\n";

    in.ignore(200, ',');
    in.get(a, 200, ',');
    p->schedule->Etime.mins = ston(a);
    //cout << p->schedule->Etime.mins << "\n";
}

//get room 
void getRoom(ifstream& in, Node*& p, char a[]){
    in.ignore(100, ',');
    in.get(a, 100, '\n');
    p->schedule->room = new char[strlen(a) + 1];
    strcpy(p->schedule->room, a);
    //cout << p->schedule->room << "\n";
    in.ignore(1000, '\n');
}

//getNode schedule
void getNodeSchedule(ifstream& in, Node*& phead, Node*& pcur){
    char a[200];
    if (!phead){
        phead = new Node;
        getNo(in, phead, a);
        getCourseID(in, phead, a);
        getCourseName(in, phead, a);
        getClassName(in, phead, a);
        getLecUserName(in, phead, a);
        getLecName(in, phead, a);
        getLecGender(in, phead, a);
        getSdate(in, phead, a);
        getEdate(in, phead, a);
        getDayOfWeek(in, phead, a);
        getSTime(in, phead, a);
        getETime(in, phead, a);
        getRoom(in, phead, a);

        phead->next = nullptr;
        pcur = phead;
    }
    else{
        pcur->next = new Node;
        pcur = pcur->next;
        
        getNo(in, pcur, a);
        getCourseID(in, pcur, a);
        getCourseName(in, pcur, a);
        getClassName(in, pcur, a);
        getLecUserName(in, pcur, a);
        getLecName(in, pcur, a);
        getLecGender(in, pcur, a);
        getSdate(in, pcur, a);
        getEdate(in, pcur, a);
        getDayOfWeek(in, pcur, a);
        getSTime(in, pcur, a);
        getETime(in, pcur, a);
        getRoom(in, pcur, a);

        pcur->next = nullptr;
    }
}

//make address of class
void makeClassAdd(char nameClass[], char str[]){
    strcat(str, "D:/Github/CS162-19CTT1-19125059/W02/PMS/class/");
    strcat(str, nameClass);
    strcat(str, "/");
    strcat(str, "Schedule.txt");
}

//import file
void importFile(Node*& phead, Node*& pcur){
    ifstream in;
    //input address of file
    char filepath[100];
    inputFileAddress(filepath);

    //load file and check
    in.open(filepath);
    if (!in.is_open()){
        system("cls");
        cout << "Not exist file.\n";
        return importFile(phead, pcur);
    }

    //don't read the 1st line
    in.ignore(1000, '\n');
    while(!in.eof()){
        getNodeSchedule(in, phead, pcur);
    }
    in.close();
}

//clean heap memory
void cleanScheduleNode(Node*& phead){
    Node* pcur = phead;
    while (phead){
        pcur = pcur->next;
        delete[] phead->schedule->courseID;
        delete[] phead->schedule->courseName;
        delete[] phead->schedule->Class;
        delete[] phead->schedule->lec->account;
        delete[] phead->schedule->lec->name;
        delete[] phead->schedule->dayofweek;
        delete[] phead->schedule->room;
        delete phead->schedule->lec;
        delete phead->schedule;
        delete phead;
        phead = pcur;
    }
}

//input year 
void inputYSC(char year[], char semester[], char className[]){
    cin.ignore(100, '\n');
    cout << "Please enter Year: ";
    cin.get(year, 20, '\n');

    cin.ignore(100, '\n');
    cout << "Please enter semester: ";
    cin.get(semester, 20, '\n');

    cin.ignore(100, '\n');
    cout << "Please enter Name of class: ";
    cin.get(className, 20, '\n');
    cin.ignore(100, '\n');
}

//is exit year
bool isExistYear(char year[]){
    ifstream in;
    in.open("D:/Github/CS162-19CTT1-19125059/ZPMS/year.txt");
    if (!in.is_open()){
        cout << "Error opening year.txt\n";
        return;
    }
    else{
        int n;
        in >> n;
        char a[50];
        for (int i = 0; i < n; i++){
            in.ignore(100, '\n');
            in.get(a, 20, '\n');
            if (strcmp(a, year) != 0) return false;
        }
    }
    return true;
}

//a part of input course
void aPartOfinputCourse(ifstream& in, Node*& phead, Node*& pcur, char a[]){
    char year[20];
    //input year
    inputYear(year);

    //check is exist year
    if (!isExistYear(year)){
        system("cls");
        cout << "We can't find year !\n";
        cout << "Please input Again: ";
        return inputCourse();
    }

    //input from staff
    inputClassName(a);
    
    //check
    if (!isExistClass(in, a, year)){
        system("cls");
        cout << "Wrong Name, Please enter again !\n";
        return inputCourse();
    }
    else{
        importFile(phead, pcur);
    }
}

//make file
void outputSchedule(ofstream& out, Node* phead, char className[]){
    char fileAdd[500];
    makeClassAdd(className, fileAdd);

    out.open(fileAdd);
    Node* pcur = phead;
    while (pcur){
        out << pcur->schedule->no << "\n";
        out << pcur->schedule->courseID << "\n";
        out << pcur->schedule->courseName << "\n";
        out << pcur->schedule->Class << "\n";
        out << pcur->schedule->lec->account << "\n";
        out << pcur->schedule->lec->name << "\n";
        out << pcur->schedule->lec->gender << "\n";
        out << pcur->schedule->Sdate.day << "\n";
        out << pcur->schedule->Sdate.month << "\n";
        out << pcur->schedule->Sdate.year << "\n";
        out << pcur->schedule->Edate.day << "\n";
        out << pcur->schedule->Edate.month << "\n";
        out << pcur->schedule->Edate.year << "\n";
        out << pcur->schedule->dayofweek << "\n";
        out << pcur->schedule->Stime.hours << "\n";
        out << pcur->schedule->Stime.mins << "\n";
        out << pcur->schedule->Etime.hours << "\n";
        out << pcur->schedule->Etime.mins << "\n";
        out << pcur->schedule->room;
        pcur = pcur->next;
    }
    out.close();
}

//input course
void inputCourse(){
    ifstream in;
    ofstream out;
    Node* phead = nullptr;
    Node* pcur = nullptr;
    char className[10];
    aPartOfinputCourse(in, phead, pcur, className);
    outputSchedule(out, phead, className);
    cleanScheduleNode(phead);
    introDone();
    return;
}