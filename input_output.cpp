#include "input_output.h"


void format_output(double* x){
    assert(x != nullptr);
    *x = isZero(*x) ? 0 : *x;
}

void output_answers(int number, double x1, double x2, char err){
    format_output(&x1);
    format_output(&x2);
    if(err != WITHOUT_ERRORS){
        return;//preventing from outputting invalid results
    }

    switch(number){
    case NO_ROOTS:
        printf("This expressions has no answers");
        break;
    case ONE_ROOT_NUMBER:printf("This expressions has 1 answer: %lg", x1); // format
        break;
    case TWO_ROOTS_NUMBER:printf("This expressions has 2 answers: %lg and %lg", x1, x2);
        break;
    case INFINITE_ROOTS_NUMBER:
        printf("This expressions has infinite amount of roots");
        break;
    }
    printf("\n\n");
}


void user_input_reading(double* a, double* b, double* c, char* err, int n){
    assert(a != nullptr);
    assert(b != nullptr);
    assert(c != nullptr);
    assert(err != nullptr);

    if(n < LAST_TRY){
        printf("Shut down, stupid user! You are too silly even to type three numbers correctly!\n");
        *err = ERROR_UNCAUGHT; // ???
        return;
    }


    printf("Input 3 numbers\n");
    int scan_status = scanf("%lg %lg %lg", a, b, c);

    if (scan_status != CORRECT_SCAN_STATUS){
        debug(ERROR_INVALID_INPUT);//throwing exception via dbg function if something wrong with input
        if(n==TRIES_TO_TYPE){
            help();
            printf("Please, read documentation and try again:\n");
        }
        user_input_reading(a, b, c, err, n - 1);
    }
}
