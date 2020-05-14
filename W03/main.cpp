/* -------------------------------------------------------------------------- */
/* ---------------------- This is final project - cs162 --------------------- */
/* ------------------------------ from M2V Team ----------------------------- */
/* ------------------------------------o0o----------------------------------- */

#include "Header.h"

/* -------------------------- this is main function ------------------------- */
int main() {

/* ---------------------------------- login --------------------------------- */
    /*type of account
     * 1 -> student
     * 2 -> lecturer
     * 3 -> staff
     * 0 -> Wrong account
     */
    //save the user ID after Login
    int accType;
    char idAfterLogin[20];

    //menu function
    menu(accType, idAfterLogin);
    // accType = 3;
    
    //stop program if wrong account!
    if (accType == 0) return 0;


    //show menu after login
    displayAllroles(accType);
}

/* ---------------------- this is end of main function ---------------------- */