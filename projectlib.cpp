#include "projectlib.h"






bool equal_double(double b1, double b2){  //checks whether two numbers are equal or not, NAN==NAN
    if(isnan(b1) && isnan(b2)){
        return true;
    }
    return fabs (b1 - b2) < ESTIMATION * (fabs(b1) + fabs(b2) + 1);
} //finished

bool isZero(double b3){ //checks whether number is equal to 0
    return equal_double(b3, 0);
}

