#include "equation_solution.h"





double discriminant(double a, double b, double c){
    return b * b - 4 * a * c;
}

double linear_equation_solution(double b, double c, double* x1, char*err){
    assert(x1 != nullptr);
    assert(err != nullptr);

    if (isZero(b)){
        if (isZero(c)){//c==b==a==0
            return INFINITE_ROOTS_NUMBER;
        }else{//a==b==0
            return 0;
        }
    }else{//a==0
            *x1= -c / b;
        }
        return 1;
}//finished

int square_equation_solution(double a, double b, double c, double* x1, double* x2, char* err){
    assert(x1 != nullptr);
    assert(x2 != nullptr);
    assert(err != nullptr);
    assert(x1 != x2);

    if (isZero(a)) {
        return linear_equation_solution(b, c, x1, err);
    }
    else{//a!=0

        double d = discriminant(a, b, c);//Discriminant

        if(d < 0){

            return 0;

        }else if(isZero(d)){//d==0

            *x1 = -b / (2 * a);
            if(!isfinite(*x1)){
                *err = ERROR_MATHEMATICAL;
            }
            return 1;
        }else{
            *x1 = (-b + sqrt(d) )/( 2 * a );
            *x2 = (-b - sqrt(d) )/( 2 * a );

            if(!isfinite(*x1) || !isfinite(*x2)){
                *err = ERROR_MATHEMATICAL;
            }
            return 2;
        }
    }
}
