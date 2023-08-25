#include "debugger.h"


/*!
    help function

    outputs documentation for mentally ill users

 */
void help(){
    printf(HELP_PRINT);///outputs documentation
}


/*!
    debug function
    outputs errors depending on error code

    @param err - variable where error code is to be stored
 */
void debug(char err){
    switch(err){
        case WITHOUT_ERRORS:
            break;
        case ERROR_INVALID_INPUT:
            printf(COLOR_RED "Error 1: Invalid Input\n" COLOR_NONE);
            break;
        case ERROR_MATHEMATICAL:
            printf(COLOR_RED "Error 2: Mathematical error (while trying to calculate answer an error has occured)" COLOR_NONE);
            break;
        case ERROR_UNCAUGHT:
            break;
        default:
            printf(COLOR_RED "Unknown Error %d\n" COLOR_NONE, err);
    }
}

