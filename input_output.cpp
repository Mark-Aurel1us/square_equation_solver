#include "input_output.h"



void output_answers(double a, double b, double c, int number, double x1, double x2, char* err){
    format_output(&x1);
    format_output(&x2);
    if(*err != WITHOUT_ERRORS){
        return;//preventing from outputting invalid results
    }
    printf("Equation ");
    output_equation(a,b,c);
    printf(" has ");
    switch(number){
    case NO_ROOTS:
        printf("no roots");
        break;
    case ONE_ROOT:
        printf("1 root: %lg", x1); // format
        break;
    case TWO_ROOTS:
        printf("2 roots: %lg and %lg", x1, x2);
        break;
    case INF_ROOTS:
        printf("infinite amount of roots");
        break;
    default:
        *err = ERROR_UNCAUGHT;
    }
    printf("\n\n");
}


void user_input_reading(double* a, double* b, double* c, char* err){ // remove n parameter; use static variable

    static int i = TRIES_TO_TYPE;
    assert(a != nullptr);
    assert(b != nullptr);
    assert(c != nullptr);
    assert(err != nullptr);

    if(i < LAST_TRY){
        printf(COLOR_RED "Shut down, stupid user! You are too silly even to type three numbers correctly!\n" COLOR_NONE);
        *err = ERROR_UNCAUGHT;
        return;
    }

    printf("Input 3 numbers\n");
    int scan_status = scanf("%lg %lg %lg", a, b, c);

    if (buffer_eraser() || scan_status != CORRECT_SCAN_STATUS){ ///if garbage found or scanned less than 3 variables
        debug(ERROR_INVALID_INPUT);///throwing exception via dbg function if something wrong with input
        if(i == TRIES_TO_TYPE){

            help();
            printf("Please, read documentation and try again:\n");
        }
        i--;///decreasing counter before recursively calling function to avoid infinite cycle
        user_input_reading(a, b, c, err);
    }
}

bool buffer_eraser(){
    bool ret = false; //!<this variable checks whether string has garbage or not
    int c = getchar();///reading next character
    while(c != '\n'){
        if(c != ' '){ret = true;}///if garbage found (garbage is everything except ' ' and '\n')
        c = getchar();///reading next character
    }
    return ret;
}

