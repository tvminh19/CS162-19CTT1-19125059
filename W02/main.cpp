/* -------------------------------------------------------------------------- */
/* ---------------------- This is final project - cs162 --------------------- */
/* ------------------------------ from M2V Team ----------------------------- */
/* ------------------------------------o0o----------------------------------- */

#include "Header.h"

/* -------------------------- this is main function ------------------------- */
int main() {
    int typeAcc;
    //char idAfterLogin[20];
    menu(typeAcc);
    if (typeAcc == 0) return 0;
    //show menu after login
    displayAllroles(typeAcc);
}

/* ---------------------- this is end of main function ---------------------- */