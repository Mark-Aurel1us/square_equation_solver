#ifndef PROJECTLIB_H_INCLUDED
#define PROJECTLIB_H_INCLUDED


#include <stdio.h>
#include <math.h>
#include <assert.h>

//constants

const double ESTIMATION = 1e-6;

 enum Errors { ///error codes
WITHOUT_ERRORS = '0', ///zero code if no errors
ERROR_INVALID_INPUT = '1', ///one code for invalid input
ERROR_MATHEMATICAL = '2', ///two code for mathematical errors
ERROR_UNCAUGHT = '3' ///three code for preventing output (used when input is invalid)
};
 enum RootsNumber {
    TWO_ROOTS = 2,  ///two
    INF_ROOTS = 574,
    ONE_ROOT = 1,
    NO_ROOTS = 0
};
const int CORRECT_SCAN_STATUS = 3;

const int TRIES_TO_TYPE = 7;
const int LAST_TRY = 1;

//functions declarations
bool equal_double(double first_double, double second_double);
bool isZero(double number);
void output_equation(double a, double b, double c);
void format_output(double* x);
char sign_no_prev(double a);
char sign_with_prev(double a);



#endif // PROJECTLIB_H_INCLUDED
