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
    //W01
    //menu function
    login(in, stu, lec, sta);
    system("pause");
    return 0;
}

/* ---------------------- this is end of main function ---------------------- */