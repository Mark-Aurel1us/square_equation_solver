#ifndef DEBUGGER_H_INCLUDED
#define DEBUGGER_H_INCLUDED

#include "projectlib.h"


void help();
void debug(char err);

const char HELP_PRINT[] = "Sharipov Akram`s Square Equation Solver\n"
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
            "\n";

#endif // DEBUGGER_H_INCLUDED
