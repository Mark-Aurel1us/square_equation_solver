#ifndef PROJECTLIB_H_INCLUDED
#define PROJECTLIB_H_INCLUDED


#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <ctype.h>
#include <limits.h>

//constants

const int CORRECT_SCAN_STATUS = 3;
const double ESTIMATION = 1e-5;
const double EXPONENTIAL_ESTIMATION = 1e-6;
const int TRIES_TO_TYPE = 7;
const int LAST_TRY = 1;

//enums
///error codes
 enum Errors {                  ///zero code if no errors
    WITHOUT_ERRORS = '0',       ///one code for invalid input (for printing non-fatal input error)
    ERROR_INVALID_INPUT = '1',  ///two code for mathematical errors
    ERROR_MATHEMATICAL = '2',   ///three code for preventing output (also used when input is invalid but for non-outputting purpose)
    ERROR_UNCAUGHT = '3'
 };
 ///possible roots counts codes
 enum RootsNumber { ///two roots
    TWO_ROOTS = 2,  ///infinite roots
    INF_ROOTS = 574,///one root
    ONE_ROOT = 1,   ///0 roots
    NO_ROOTS = 0
 };

//definition of colours
#define COLOR_RED   "\033[31m"
#define COLOR_NONE  "\033[39m"
#define COLOR_GREEN "\033[32m"


//macros
#define OUTERR(X) fprintf(stderr, X "\n");



//functions declarations
bool equal_double(double first_double, double second_double);
bool isZero(double number);
void output_equation(double a, double b, double c);
void format_output(double* x);
char sign_no_prev(double a);
char sign_with_prev(double a);



#endif // PROJECTLIB_H_INCLUDED
