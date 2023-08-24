#ifndef PROJECTLIB_H_INCLUDED
#define PROJECTLIB_H_INCLUDED


#include <stdio.h>
#include <math.h>
#include <assert.h>

//constants

const double ESTIMATION = 1e-6;

const char WITHOUT_ERRORS = '0';
const char ERROR_INVALID_INPUT = '1';
const char ERROR_MATHEMATICAL = '2';
const char ERROR_UNCAUGHT = '3';

const char TWO_ROOTS_NUMBER = 2;
const int INFINITE_ROOTS_NUMBER = -574;
const int ONE_ROOT_NUMBER = 1;
const int NO_ROOTS = 0;

const int CORRECT_SCAN_STATUS = 3;

const int TRIES_TO_TYPE = 7;
const int LAST_TRY = 1;

//functions declarations
bool equal_double(double b1, double b2);
bool isZero(double b3);



#endif // PROJECTLIB_H_INCLUDED
