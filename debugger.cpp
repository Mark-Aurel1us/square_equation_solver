#include "debugger.h"

void help() {

    printf(HELP_PRINT);//outputs documentation
}

void print_errors_description(char err) {

    switch (err) {
        case WITHOUT_ERRORS:
            break;
        case ERROR_INVALID_INPUT:
            printf(COLOR_RED "Error 1: Invalid Input\n" COLOR_RESET);
            OUTERR("Invalid Input")
            break;
        case ERROR_MATHEMATICAL:
            printf(COLOR_RED "Error 2: Mathematical error (while trying to calculate answer an error has occured)" COLOR_RESET);
            OUTERR("Maths Error")
            break;
        case ERROR_UNCAUGHT:
            break;
        case ERROR_ROOTS_NUMBER:
            printf(COLOR_RED "Error 4: Roots number error (while trying to calculate answer an error has occured)" COLOR_RESET);
            OUTERR("Roots number Error")
            break;
        default:
            printf(COLOR_RED "Unknown Error %d\n" COLOR_RESET, err);
            OUTERR("Unknown Error")
    }
}
