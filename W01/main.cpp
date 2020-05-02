/* -------------------------------------------------------------------------- */
/* ---------------------- This is final project - cs162 --------------------- */
/* ------------------------------ from M2V Team ----------------------------- */
/* ------------------------------------o0o----------------------------------- */

#include "Header.h"

/* -------------------------- this is main function ------------------------- */
int main(){
    ifstream in;
    ofstream out;

    student* stu = nullptr;
    lecture* lec = nullptr;
    staff* sta = nullptr; 
    //to know what is type of account
    int typeAccount = 0;
    //DO_NOT change countLogin !!! => some bug if you change
    int countLogin = 4; 
    //W01
    //menu function
    login(in, stu, lec, sta, typeAccount, countLogin);
    cout << "TypeAccount";
    system("pause");
    return 0;
}

/* ---------------------- this is end of main function ---------------------- */