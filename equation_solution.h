#ifndef EQUATION_SOLUTION_H_INCLUDED
#define EQUATION_SOLUTION_H_INCLUDED

#include "projectlib.h"



/*!
    square_equation_solution function

    returns number of roots of square equation, writes their values in x1 and x2 (if these roots exist, of course)

    @param a - first quotient of square equation a*x^2+b*x+c=0
    @param b - second quotient of square equation
    @param c - third quotient of square equation///preventing from wrong calculation/overflow/etc (i dont know)
    @param x1 - first root of the equation (may contain nan if not exists or infinite roots)
    @param x2 - second root of the equation (may contain nan if not exists or infinite roots)
    @param err - variable where error code is to be stored
 */
int square_equation_solution(double a, double b, double c, double* x1, double* x2, char* err);

/*!
    linear_equation_solution function

    returns number of roots of linear equation, writes its values in x1  (if this root exists, of course)

    @param b - second quotient of square equation b*x+c=0
    @param c - third quotient of square equation
    @param n - number of roots of the equation
    @param x1 - first root of the equation
    @param err - variable where error code is to be stored
 */
int linear_equation_solution(double b, double c, double* x1, char*err);

/*!
    discriminant function

    returns discriminant of the equation

    @param a - first quofficient of square equation a*x^2+b*x+c=0
    @param b - second quofficient of square equation
    @param c - third quofficient of square equation
 */
double discriminant(double a, double b, double c);



#endif // EQUATION_SOLUTION_H_INCLUDED
