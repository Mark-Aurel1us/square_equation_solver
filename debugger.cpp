#include "debugger.h"



void help(){    //outputs documentation
    printf( "Sharipov Akram`s Square Equation Solver\n"
            "(C) 2023, Akram Sharipov, Republic of Bashkortostan\n"
            "Usage:\n"
            "\n"
            "To solve equation like a*x^2+b*x+c=0,\n"
            "just enter three numbers a,b,c in a correct (abc) order, dividing with one whitespace\n"
            "For example (for 5*x^2+6*x+7=0):\n"
            "5 6 7\n"
            "\n"
            "The program will output number of roots, their values, or output error if you type wrong\n"
            "\n"
            "\n"
    );
}



void buffer_eraser(){
    while(getchar()!='\n'){}
}

void debug(char err){
    switch(err){
        case WITHOUT_ERRORS:
            break;
        case ERROR_INVALID_INPUT:
            printf("Error 1: Invalid Input\n");
            buffer_eraser();
            printf("Please, read documentation and try again:\n");
            help();
            break;
        case ERROR_MATHEMATICAL:
            printf("Error 2: Mathematical error (while trying to calculate answer an error has occured)");
            break;
        case ERROR_UNCAUGHT:
            break;
        default:
            printf("Unknown Error %d\n", err);
    }
}

