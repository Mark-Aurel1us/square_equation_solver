#ifndef OUTPUT_ANSWERS_H_INCLUDED
#define OUTPUT_ANSWERS_H_INCLUDED

#include "debugger.h"
#include "projectlib.h"

const int TRIES_TO_TYPE = 7;
const int CORRECT_SCAN_STATUS = 3;

/*!
    user_input_reading function

    @param a - first quofficient of square equation a*x^2+b*x+c=0
    @param b - second quofficient of square equation
    @param c - third quofficient of square equation
    @param err (out) - variable where error code is to be stored
 */
void user_input_reading(double* a, double* b, double* c, char* err, const int mode);

/*!
    output_answers function

    @param a - first quofficient of square equation a*x^2+b*x+c=0
    @param b - second quofficient of square equation
    @param c - third quofficient of square equation
    @param n - number of roots of the equation
    @param x1 - first root of the equation (may contain nan if not exists or infinite roots)
    @param x2 - second root of the equation (may contain nan if not exists or infinite roots)
    @param err (out) - variable where error code is to be stored
 */
void output_answers(double a, double b, double c, int number, double x1, double x2, char* err);

/*!
    buffer_eraser function
    erases buffer until the end of the line
    returns true if buffer has garbage (not isspace)
    returns false if everything is ok
 */
bool buffer_eraser();


#endif // OUTPUT_ANSWERS_H_INCLUDED
