#ifndef OUTPUT_ANSWERS_H_INCLUDED
#define OUTPUT_ANSWERS_H_INCLUDED

#include "debugger.h"
#include "projectlib.h"

void user_input_reading(double* a, double* b, double* c, char*err);
void output_answers(double a, double b, double c, int number, double x1, double x2, char* err);
bool buffer_eraser();


#endif // OUTPUT_ANSWERS_H_INCLUDED
