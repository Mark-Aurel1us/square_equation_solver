#ifndef PROJECTLIB_H_INCLUDED
#define PROJECTLIB_H_INCLUDED

#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <string.h>

//constants
const double ESTIMATION = 1e-5;
const double EXPONENTIAL_ESTIMATION = 1e-6;

//enums
///error codes
enum errors {               ///zero code if no errors
    WITHOUT_ERRORS = '0',       ///one code for invalid input (for printing non-fatal input error)
    ERROR_INVALID_INPUT = '1',  ///two code for mathematical errors
    ERROR_MATHEMATICAL = '2',   ///three code for preventing output (also used when input is invalid but for non-outputting purpose)
    ERROR_UNCAUGHT = '3',
    ERROR_ROOTS_NUMBER = '4',   ///5 code for invalid mode
    ERROR_INVALID_MODE = '5'
};

///possible roots counts codes
enum roots_number {     ///two roots
    TWO_ROOTS = 2,     ///infinite roots, negative in order not to output roots if there are infinite (comparison with 0 shows whether to show roots or no)
    INF_ROOTS = -574,   ///one root
    ONE_ROOT = 1,      ///0 roots
    NO_ROOTS = 0,      ///example incorrect root number
    INCORRECT_ROOTS = 575
};
///work modes, shows number of roots to input
enum work_mode {        ///solving square equation
    SQUARE_MODE = 3,    ///solving linear equation
    LINEAR_MODE = 2
};

//definition of colours
#define COLOR_RED   "\033[31m"
#define COLOR_RESET "\033[39m"
#define COLOR_GREEN "\033[32m"

//macros
#define OUTERR(X) fprintf(stderr, X "\n");

//functions declarations
/*!
    Function that returns true if doubles are approximately equal
    else returns false


    @param a - first quofficient of square equation a*x^2+b*x+c=0
    @param b - second quofficient of square equation
    @param c - third quofficient of square equation
 */
bool equal_double(double first_double, double second_double);

/*!
    if number is very little, its module is less than epsilon (ESTIMATION), returns true
    else returns false

 */
bool is_zero(double number);

/*!
   Function that prints equation canonically, e.g. 0=0, -x+3=0, x^2-7=0, etc

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
    this function returns only negative sign of the summand (-). Instead of +, returns ' '

    @param a - quofficient of square equation

 */
char sign_no_prev(double t);

/*!
    sign_with_prev function
    if there is another summand before this summand, we have to write +, so,
    this function returns sign of the summand, + or -

    @param a - quofficient of square equation

 */
char sign_with_prev(double t);

/*!
 Function that outputs number of roots
 @param n - number of roots
*/
void print_number_of_roots(int roots_n);

/*!
 Function that prints root if it is not NAN
*/
void print_not_nan(double x);


/*!
 If no command line arguments, this program is executed
*/
void program(const int mode);

/*!
 Outputs command line usage if user inputs wrong command arguments
*/
void usage();

/*!
 Proceeds single param from command line
 */
bool proceed_command_line(const char* arg);
#endif // PROJECTLIB_H_INCLUDED
