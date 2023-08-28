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
enum Errors {               ///zero code if no errors
    WITHOUT_ERRORS = '0',       ///one code for invalid input (for printing non-fatal input error)
    ERROR_INVALID_INPUT = '1',  ///two code for mathematical errors
    ERROR_MATHEMATICAL = '2',   ///three code for preventing output (also used when input is invalid but for non-outputting purpose)
    ERROR_UNCAUGHT = '3',
    ERROR_ROOTS_NUMBER = '4'
};

///possible roots counts codes
enum RootsNumber {     ///two roots
    TWO_ROOTS = 2,     ///infinite roots
    INF_ROOTS = 574,   ///one root
    ONE_ROOT = 1,      ///0 roots
    NO_ROOTS = 0,      ///example incorrect root number
    INCORRECT_ROOTS = 575
};

//definition of colours
#define COLOR_RED   "\033[31m"
#define COLOR_RESET "\033[39m"
#define COLOR_GREEN "\033[32m"


//macros
#define OUTERR(X) fprintf(stderr, X "\n");


//functions declarations
/*!
    equal_double function

    returns true if doubles are approximately equal
    else returns false
    NANs are equal !important


    @param a - first quofficient of square equation a*x^2+b*x+c=0
    @param b - second quofficient of square equation
    @param c - third quofficient of square equation
 */
bool equal_double(double first_double, double second_double);

/*!
    isZero function
    if number is very little, its module is less than epsilon (ESTIMATION), returns true
    else returns false

 */
bool isZero(double number);

/*!
    output_equation function
    prints equation canonically, e.g. 0=0, -x+3=0, x^2-7=0, etc

    @param a - first quotient of square equation a*x^2+b*x+c=0
    @param b - second quotient of square equation
    @param c - third quotient of square equation

 */
void output_equation(double a, double b, double c);

/*!
    format_output function

    just prevents from outputting "-0"
    returns 0 if number is near 0

    @param x - number being formatted
 */
void format_output(double* x);
/*!
    sign_no_prev function
    if there is no another summand before this summand, we mustn't write +, so,
    this function returns only negative sign of the summand (-). Instead of +, returns null-character '\0'

    @param a - quofficient of square equation

 */
char sign_no_prev(double a);
/*!
    sign_with_prev function
    if there is another summand before this summand, we have to write +, so,
    this function returns sign of the summand, + or -

    @param a - quofficient of square equation

 */
char sign_with_prev(double a);



#endif // PROJECTLIB_H_INCLUDED
