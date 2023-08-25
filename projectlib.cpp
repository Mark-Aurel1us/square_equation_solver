#include "projectlib.h"


/*!
    format_output function

    just prevents from outputting "-0"
    returns 0 if number is near 0

    @param x - number being formatted
 */
void format_output(double* x){
    assert(x != nullptr);
    *x = isZero(*x) ? 0 : *x;
}





/*!
    equal_double function

    returns true if doubles are approximately equal
    else returns false
    NANs are equal !important


    @param a - first quofficient of square equation a*x^2+b*x+c=0
    @param b - second quofficient of square equation
    @param c - third quofficient of square equation
 */

bool equal_double(double first_double, double second_double){  ///checks whether two numbers are equal or not, NAN==NAN
    if(isnan(second_double) && isnan(first_double)){
        return true;///NAN==NAN there
    }

    if(isZero(first_double - second_double)){ ///if difference between numbers is near 0, they are equal
        return true;
    }

    if(first_double * second_double > 0 && fabs(log(fabs(first_double))) - log(fabs(second_double)) < EXPONENTIAL_ESTIMATION){///
        ///exponential difference for big scientific numbers of equal sign, e.g. 1,000000001e32 and 9.99999999e31 (idk)
         return true; ///if exponential difference is small, numbers must have been equal,
    }
    return false;    ///otherwise,
    //todo: write for exp form: fabs (b1 - b2) < ESTIMATION * (fabs(b1) + fabs(b2))
}



/*!
    isZero function
    if number is very little, its module is less than epsilon (ESTIMATION), returns true
    else returns false

 */     //change b1 b2 b3 names //done!
bool isZero(double number){ //checks whether number is equal to 0
    return fabs(number) < ESTIMATION;///returning comparison
}



/*!
    output_equation function
    prints equation canonically, e.g. 0=0, -x+3=0, x^2-7=0, etc

    @param a - first quofficient of square equation a*x^2+b*x+c=0
    @param b - second quofficient of square equation
    @param c - third quofficient of square equation

 */
void output_equation(double a, double b, double c){

        char a_sign = sign_no_prev(a);///write sign of a only if it is less than 0
        char b_sign = sign_with_prev(b);///write sign of b
        char c_sign = sign_with_prev(c);///write sign of c

        if(!isZero(a)){///if x^2 is to be printed
            printf("%c", a_sign);///print sign of a
            if(!equal_double(fabs(a), 1)){///if quofficient is not 1 or -1
                printf("%lg", fabs(a));///print a
            }
            printf("x^2");///print x^2

        }else if(!isZero(b)){///if x^2 is not to be printed, but x is
            b_sign = sign_no_prev(b);///write sign of b only if it is less than 0
        }

        if(!isZero(b)){///if x is to be printed
            printf("%c", b_sign);///print sign of b
            if(!equal_double(fabs(b), 1)){///if quofficient is not 1 or -1
                printf("%lg", fabs(b));///print b
            }
            printf("x");///print x
        }

        if(isZero(a) && isZero(b)){///if no x^2 or x
            c_sign = sign_no_prev(c);///write sign of c only if it is less than 0
        }

        if((isZero(a) && isZero(b)) || !isZero(c)){///if no x^2 or x, but c is not 0
            printf("%c", c_sign);///print sign of c
            printf("%lg", fabs(c));///print c itself
        }

        printf("=0");///equation print finishing
}


/*!
    sign_with_prev function
    if there is another summand before this summand, we have to write +, so,
    this function returns sign of the summand, + or -

    @param a - quofficient of square equation

 */
char sign_with_prev(double a){
    if(isZero(a)){return '+';}///not to write -0
    return (a > 0) ? '+' : '-';///return sign of summand
}


/*!
    sign_no_prev function
    if there is no another summand before this summand, we mustn't write +, so,
    this function returns only negative sign of the summand (-). Instead of +, returns null-character '\0'

    @param a - quofficient of square equation

 */
char sign_no_prev(double a){
    if(isZero(a)){return '\0';}///not to write -0
    return (a > 0) ? '\0' : '-';///return sign of summand
}

