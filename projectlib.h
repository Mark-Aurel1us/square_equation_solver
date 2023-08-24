#ifndef PROJECTLIB_H_INCLUDED
#define PROJECTLIB_H_INCLUDED


#include <stdio.h>
#include <math.h>
#include <assert.h>

//constants
const int INFINITE_ROOTS_NUMBER = -574;
//const int INVALID_ROOTS_NUMBER = -573; //unused, deprecated
//const int DEFAULT_VAR_VALUE = -572;
//const int INVALID_INPUT = -571;
const double ESTIMATION = 1e-6;

const char WITHOUT_ERRORS = '0';
const char ERROR_INVALID_INPUT = '1';
const char ERROR_MATHEMATICAL = '2';
const char ERROR_UNCAUGHT = '3';


//functions declarations
bool equal_double(double b1, double b2);
bool isZero(double b3);



#endif // PROJECTLIB_H_INCLUDED
