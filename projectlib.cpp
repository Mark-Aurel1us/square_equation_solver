#include "projectlib.h"

void format_output(double* x){
    assert(x != nullptr);
    *x = isZero(*x) ? 0 : *x;
}

bool equal_double(double first_double, double second_double){  //checks whether two numbers are equal or not, NAN==NAN
    if(isnan(second_double) && isnan(first_double)){
        return true;
    }

    return isZero(first_double - second_double);
    //todo: write for exp form: fabs (b1 - b2) < ESTIMATION * (fabs(b1) + fabs(b2))
} //finished

//change b1 b2 b3 names
bool isZero(double number){ //checks whether number is equal to 0
    return fabs(number) < ESTIMATION;
}

void output_equation(double a, double b, double c){

        char a_sign = sign_no_prev(a);//write sign of a is less than 0
        char b_sign = sign_with_prev(b);//write sign of b
        char c_sign = sign_with_prev(c);//write sign of c
        // functions

        //format_output(&a);
        //format_output(&b);
        //format_output(&c);
        if(!isZero(a)){
            printf("%c", a_sign);
            if(!equal_double(fabs(a), 1)){
                printf("%lg", fabs(a));
            }
            printf("x^2");

        }else if(!isZero(b)){
            b_sign = sign_no_prev(b);
        }

        if(!isZero(b)){
            printf("%c", b_sign);
            if(!equal_double(fabs(b), 1)){
                printf("%lg", fabs(b));
            }
            printf("x");
        }
        if(isZero(a) && isZero(b)){
            c_sign = sign_no_prev(c);
        }


        if((isZero(a) && isZero(b)) || !isZero(c)){
            printf("%c", c_sign);
            printf("%lg", fabs(c));
        }
        printf("=0");
}

char sign_with_prev(int a){
    return (a > 0) ? '+' : '-';
}

char sign_no_prev(int a){
    return (a > 0) ? '\0' : '-';
}

