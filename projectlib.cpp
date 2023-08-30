#include "projectlib.h"

void format_output(double* x) { // fix_zero

    assert(x != nullptr);
    *x = is_zero(*x) ? 0 : *x;
}

bool equal_double(double first_double, double second_double) {

    if (isnan(second_double) || isnan(first_double)) {
        return false;
    }

    if (is_zero(first_double - second_double)) { //if difference between numbers is near 0, they are equal
        return true;
    }

    if (first_double * second_double > 0 && fabs(log(fabs(first_double))) - log(fabs(second_double)) < EXPONENTIAL_ESTIMATION) {///
        //exponential difference for big scientific numbers of equal sign, e.g. 1,000000001e32 and 9.99999999e31 (idk)
         return true; //if exponential difference is small, numbers must have been equal,
    }

    return false;    //otherwise,
}

bool is_zero(double number) { //checks whether number is equal to 0

    return fabs(number) < ESTIMATION;//returning comparison
}

void output_equation(double a, double b, double c) {

        char a_sign = sign_no_prev(a);//write sign of a only if it is less than 0
        char b_sign = sign_with_prev(b);//write sign of b
        char c_sign = sign_with_prev(c);//write sign of c

        //if x^2 is to be printed
        if (!is_zero(a)) {
            printf("%c", a_sign);
            if (!equal_double(fabs(a), 1)) {
                printf("%lg", fabs(a));
            }
            printf("x^2");//print x^2

        } else {
            b_sign = sign_no_prev(b);
        }


        if (!is_zero(b)) {//if x is to be printed
            printf("%c", b_sign);//print sign of b
            if (!equal_double(fabs(b), 1)) {//if quofficient is not 1 or -1
                printf("%lg", fabs(b));//print b
            }
            printf("x");//print x
        }


        if (is_zero(a) && is_zero(b)) {
            c_sign = sign_no_prev(c);
        }

        if ((is_zero(a) && is_zero(b)) || !is_zero(c)) {//if no x^2 or x, but c is not 0
            printf("%c", c_sign);//print sign of c
            printf("%lg", fabs(c));//print c itself
        }


        printf("=0");//equation print finishing
}

char sign_with_prev(double t) {

    if (is_zero(t)) {
        return '+';
    }//not to write -0
    return (t > 0) ? '+' : '-';//return sign of summand
}

char sign_no_prev(double t) {

    if (is_zero(t)) {
        return ' ';
    }//not to write -0
    return (t > 0) ? ' ' : '-';//return sign of summand
}

void print_number_of_roots(int roots_n) {

    switch (roots_n){
        case (INF_ROOTS):
            printf("infinite roots");
            break;
        case (NO_ROOTS):
            printf("no roots");
            break;
        case (ONE_ROOT):
            printf("one root:");
            break;
        case (TWO_ROOTS):
            printf("two roots:");
            break;
        default:;
    }
    printf("\n");
}

void print_not_nan(double x) {

    if (!isnan(x)) {
        printf("       x=%lg\n", x);
    }
}

