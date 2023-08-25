#include "equation_solution.h"

/*!
    discriminant function

    returns discriminant of the equation

    @param a - first quofficient of square equation a*x^2+b*x+c=0
    @param b - second quofficient of square equation
    @param c - third quofficient of square equation
 */
double discriminant(double a, double b, double c){
    return b * b - 4 * a * c;///returning double value of the discriminant
}

/*!
    linear_equation_solution function

    returns number of roots of linear equation, writes its values in x1  (if this root exists, of course)

    @param b - second quofficient of square equation b*x+c=0
    @param c - third quofficient of square equation
    @param n - number of roots of the equation
    @param x1 - first root of the equation
    @param err - variable where error code is to be stored
 */
int linear_equation_solution(double b, double c, double* x1, char*err){

    assert(x1 != nullptr);///null-pointer-exception avoid
    assert(err != nullptr);///null-pointer-exception avoid

    if (isZero(b)){
        if (isZero(c)){///case c==b==a==0
            return INF_ROOTS;///0=0 equation has infinite roots
        }else{///case a==b==0
            return NO_ROOTS;///c=0 has no roots if c!=0
        }
    }else{///case a==0
            *x1 = -c / b;///b*x+c==0 b*x==-c x==-c/b
        }
        return ONE_ROOT;///x==-c/b - only one root
}


/*!
    square_equation_solution function

    returns number of roots of square equation, writes their values in x1 and x2 (if these roots exist, of course)

    @param a - first quofficient of square equation a*x^2+b*x+c=0
    @param b - second quofficient of square equation
    @param c - third quofficient of square equation///preventing from wrong calculation/overflow/etc (i dont know)
    @param x1 - first root of the equation (may contain nan if not exists or infinite roots)
    @param x2 - second root of the equation (may contain nan if not exists or infinite roots)
    @param err - variable where error code is to be stored
 */
int square_equation_solution(double a, double b, double c, double* x1, double* x2, char* err){

    if(*err != WITHOUT_ERRORS){
        return NO_ROOTS;///if errors has occured before, don't do anything and return
    }

    assert(x1 != nullptr);///null-pointer-exception avoid
    assert(x2 != nullptr);///null-pointer-exception avoid
    assert(err != nullptr);///null-pointer-exception avoid
    assert(x1 != x2);///null-pointer-exception avoid

    if (isZero(a)) {
        return linear_equation_solution(b, c, x1, err);///if equation is linear, use another function to calculate answer
    }
    else{///a!=0, solving square equation

        double d = discriminant(a, b, c);///calculating discriminant

        if(isZero(d)){///null discriminant, one root only
            *x1 = -b / (2 * a);///calculation by formula
            if(!isfinite(*x1)){
                *err = ERROR_MATHEMATICAL;///preventing from wrong calculation/overflow/etc (i dont know)
            }
            return ONE_ROOT;///returning number of roots in this case
        }else if(d < 0){///negative discriminant, no roots
            return NO_ROOTS;///returning number of roots in this case

        }else{///positive discriminant, two roots
            *x1 = (-b + sqrt(d) ) / ( 2 * a );///calculation by formula
            *x2 = (-b - sqrt(d) ) / ( 2 * a );///calculation by formula

            if(!isfinite(*x1) || !isfinite(*x2)){
                *err = ERROR_MATHEMATICAL;///preventing from wrong calculation/overflow/etc (i dont know)
            }
            return TWO_ROOTS;///returning number of roots in this case
        }
    }
}
