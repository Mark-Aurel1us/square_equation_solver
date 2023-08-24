#ifndef EQUATION_SOLUTION_H_INCLUDED
#define EQUATION_SOLUTION_H_INCLUDED

#include "projectlib.h"




int square_equation_solution(double a, double b, double c, double* x1, double* x2, char* err);
double linear_equation_solution(double b, double c, double* x1, char*err);
double discriminant(double a, double b, double c);



#endif // EQUATION_SOLUTION_H_INCLUDED
