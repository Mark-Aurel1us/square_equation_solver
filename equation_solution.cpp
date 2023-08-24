#include "equation_solution.h"

/**
 * A function that counts discriminant of square equation
 * @param a - first quofficient
 */
double discriminant(double a, double b, double c){
    return b * b - 4 * a * c;
}

int linear_equation_solution(double b, double c, double* x1, char*err){
    assert(x1 != nullptr);
    assert(err != nullptr);

    if (isZero(b)){
        if (isZero(c)){//c==b==a==0
            return INF_ROOTS;
        }else{//a==b==0
            return NO_ROOTS;
        }
    }else{//a==0
            *x1 = -c / b;
        }
        return ONE_ROOT;
}//finished

int square_equation_solution(double a, double b, double c, double* x1, double* x2, char* err){
    if(*err != WITHOUT_ERRORS){return NO_ROOTS;}

    assert(x1 != nullptr);
    assert(x2 != nullptr);
    assert(err != nullptr);
    assert(x1 != x2);

    if (isZero(a)) {
        return linear_equation_solution(b, c, x1, err);
    }
    else{//a!=0

        double d = discriminant(a, b, c);//Discriminant

        if(isZero(d)){
            *x1 = -b / (2 * a);
            if(!isfinite(*x1)){
                *err = ERROR_MATHEMATICAL;
            }
            return ONE_ROOT;
        }else if(d < 0){
            return NO_ROOTS;

        }else{
            *x1 = (-b + sqrt(d) ) / ( 2 * a );
            *x2 = (-b - sqrt(d) ) / ( 2 * a );

            if(!isfinite(*x1) || !isfinite(*x2)){
                *err = ERROR_MATHEMATICAL;
            }
            return TWO_ROOTS;
        }
    }
}
