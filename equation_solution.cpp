#include "equation_solution.h"



double discriminant(const double a, const double b, const double c){
    return b * b - 4 * a * c;//returning double value of the discriminant
}


int linear_equation_solution(double b, double c, double* x1, char*err){

    assert(x1 != nullptr);  //null-pointer-exception avoid
    assert(err != nullptr); //null-pointer-exception avoid

    if (isZero(b)) {
        if (isZero(c)) { //case c==b==a==0
            return INF_ROOTS;//0=0 equation has infinite roots
        } else { //case a==b==0
            return NO_ROOTS;//c=0 has no roots if c!=0
        }
    } else { //case a==0
            *x1 = -c / b; //b*x+c==0 b*x==-c x==-c/b
        }
        return ONE_ROOT; //x==-c/b - only one root
}


int square_equation_solution(double a, double b, double c, double* x1, double* x2, char* err){
     // TODO err != NULL
    if (*err != WITHOUT_ERRORS){
        return NO_ROOTS;//if errors has occured before, don't do anything and return
    }

    assert(x1 != nullptr);//null-pointer-exception avoid
    assert(x2 != nullptr);
    assert(err != nullptr);
    assert(x1 != x2);

    if (isZero(a)) {
        return linear_equation_solution(b, c, x1, err);//if equation is linear, use another function to calculate answer
    }

    double d = discriminant(a, b, c);//calculating discriminant

    if(isZero(d)){//null discriminant, one root only
        *x1 = -b / (2 * a);//calculation by formula
        if(!isfinite(*x1)){
            *err = ERROR_MATHEMATICAL;//preventing from wrong calculation/overflow/etc (i dont know)
        }
        return ONE_ROOT;
    }

    else {
        if(d < 0){
            return NO_ROOTS;
        }

        *x1 = (-b + sqrt(d) ) / ( 2 * a );//calculation by formula
        *x2 = (-b - sqrt(d) ) / ( 2 * a );//calculation by formula

        if(!isfinite(*x1) || !isfinite(*x2)){
            *err = ERROR_MATHEMATICAL;//preventing from wrong calculation/overflow/etc (i dont know)
        }
        return TWO_ROOTS;//returning number of roots in this case
    }
}
