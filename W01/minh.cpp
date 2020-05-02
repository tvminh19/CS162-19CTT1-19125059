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

int checkExistAccount(student*& stu, lecture*& lec, staff*& sta, int& n1, int& n2, int& n3, char id[], char pass[], char name[], bool& sexual){
    //student
    for (int i = 0; i < n1; ++i){
        if (checkSame(stu[i].account, id) && checkSame(stu[i].password, pass)){
            strcpy(name, stu[i].name);
            sexual = stu[i].sexual;
            return 1;
        }
    }

    //lecture 
    for (int i = 0; i < n2; ++i){
        if (checkSame(lec[i].account, id) && checkSame(lec[i].password, pass)){
            strcpy(name, lec[i].name);
            sexual = lec[i].sexual;
            return 2;
        } 
    }

    //staff
    for (int i = 0; i < n3; ++i){
        if (checkSame(sta[i].account, id) && checkSame(sta[i].password, pass)){
            strcpy(name, sta[i].name);
            sexual = sta[i].sexual;
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
    delete[] stu;
    delete[] lec;
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

            //input sexual
            in >> sta[i].sexual;
        }
    }
    in.close();
}

void loadLectureFile(ifstream& in, lecture*& lec, int& n2){
    in.open("D:\\Github\\CS162-19CTT1-19125059\\W01\\PMS\\menu\\Lecturer.txt");
    if (!in.is_open()){
        cout << "error at line 111 of minh.cpp.\n";
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

            //input sexual
            in >> lec[i].sexual;
        }
    }
    in.close();
}

void loadStudentFile(ifstream& in, student*& stu, int& n1){
    in.open("D:\\Github\\CS162-19CTT1-19125059\\W01\\PMS\\menu\\Student.txt");
    if (!in.is_open()){
        cout << "error at line 154 of minh.cpp.\n";
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

/* ------------------------------ to know time ------------------------------ */
void timeNow(){
    time_t now = time(0);
    tm *cptr = localtime(&now);
    int t = cptr->tm_hour;
    if (0 <= t && t <= 11){
        cout << "Good morning, ";
    }
    else if (12 <= t && t <= 18){
        cout << "Good afternoon, ";
    }
    else{
        cout << "Good evening, ";
    }
}

/* --------------- show display hello then remove heap memory --------------- */
int resultLogin(ifstream& in, int& result, int& countLogin, bool sexual, char nameLogin[], student*& stu, lecture*& lec, staff*& sta, int n1, int n2, int n3){
    if (result == 0){
        char choosen;
        if (countLogin != 0){
            cout << "========================\n";
            cout << "Sorry, Wrong account!\n";
            cout << "Do you want to try again (y/n) ?\n";
            cout << "> ";
            cin >> choosen;
        }
        else{
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
            login(in, stu, lec, sta, result, countLogin); //TODO
        }
        else{
            system("cls");
            cout << "Thank for using !\n";
            return 0;
        }
    }
    else{
        timeNow();
        if (sexual){
            cout << "Mr.";
        }
        else{
            cout << "Ms.";
        }
        cout << nameLogin << "!" << endl;
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
    cout<<"User name: \n";
    cout << "> ";
    cin.get(user, 200, '\n');
    cout << "Password: \n";
    cout << "> ";
    while(ch = getch()){
        if (ch == 8 && strlen(passwd) - 1 == 0){
            continue;
        }
    	else if(ch == 13){
			break;
		}
        else if (ch == 8 && strlen(passwd) > 0){
            passwd[pos--] = '\0';
            cout << "\b \b";
        }
		else{
			cout<<"*";
			passwd[pos++] = ch;
		}
	}
	passwd[pos] = '\0';
    cout << "\n";
    return;
}

/* ---------------------------- intro when login ---------------------------- */
void introLogin(){
    cout << "--------------------------------------------------\n";
    cout << "------------------- WELCOME ----------------------\n";
    cout << "---------------- TO MINI MODDLE ------------------\n";
    cout << "--------------------------------------------------\n";
    Sleep(600);
    system("cls");
}

/* ----------------------------- login function ----------------------------- */
int login(ifstream& in, student*& stu, lecture*& lec, staff*& sta, int& result, int& countLogin){
    //slots of account
    int n1, n2, n3;

    //make color
    system("color a");

    //load file 
    loadLoginFile(in, stu, lec, sta, n1, n2, n3);

    //check replay main function
    if (countLogin == 4){ 
        //intro
        introLogin();
        
        //reback isFirst
        countLogin--;
    }
    //input from keyboard
    char id[200];
    char pass[200];
    inputLogin(id, pass);

    //check if account is exist
    char nameLogin[100];
    bool sexual;
    result = checkExistAccount(stu, lec, sta, n1, n2, n3, id, pass, nameLogin, sexual);
    //result and compele funtions
    resultLogin(in, result, countLogin, sexual, nameLogin, stu, lec, sta, n1, n2, n3);
    return 0;
}

/* ---------------------------- log out functions --------------------------- */
void logout(){
    return;
}