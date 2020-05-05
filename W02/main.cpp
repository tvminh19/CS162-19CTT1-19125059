/* -------------------------------------------------------------------------- */
/* ---------------------- This is final project - cs162 --------------------- */
/* ------------------------------ from M2V Team ----------------------------- */
/* ------------------------------------o0o----------------------------------- */

#include "header.h"

/* -------------------------- this is main function ------------------------- */
int main() {

/* ---------------------------------- login --------------------------------- */
    /*type of account
     * 1 -> student
     * 2 -> lecturer
     * 3 -> staff
     * 0 -> Wrong account
     */
    int typeAcc;

    //save user name after login
    char idAfterLogin[20];
    menu(typeAcc);
    
    //stop program if wrong account or hack !
    if (typeAcc == 0) return 0;

    //show menu after login
    displayAllroles(typeAcc);
}

/* ---------------------- this is end of main function ---------------------- */