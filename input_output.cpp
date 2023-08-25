#include "input_output.h"


/*!
    output_answers function

    @param a - first quofficient of square equation a*x^2+b*x+c=0
    @param b - second quofficient of square equation
    @param c - third quofficient of square equation
    @param n - number of roots of the equation
    @param x1 - first root of the equation (may contain nan if not exists or infinite roots)
    @param x2 - second root of the equation (may contain nan if not exists or infinite roots)
    @param err - variable where error code is to be stored
 */
void output_answers(double a, double b, double c, int number, double x1, double x2, char* err){
    format_output(&x1);/// avoid -0 output
    format_output(&x2);/// avoid -0 output
    if(*err != WITHOUT_ERRORS){
        return;///preventing from outputting invalid results
    }
    printf("Equation ");
    output_equation(a,b,c);///outputting equation canonically
    printf(" has ");
    switch(number){///depending on how much roots the equation has, prints amount of roots
    case NO_ROOTS:///if equation has no roots
        printf("no roots");
        break;
    case ONE_ROOT:///if equation has one root
        printf("1 root: %lg", x1);
        break;
    case TWO_ROOTS:///if equation has two roots
        printf("2 roots: %lg and %lg", x1, x2);
        break;
    case INF_ROOTS:///if equation has infinite roots
        printf("infinite amount of roots");
        break;
    default:
        *err = ERROR_UNCAUGHT;///error code to be proceeded by debug function
    }
    printf("\n\n");///new line
}


/*!
    user_input_reading function

    @param a - first quofficient of square equation a*x^2+b*x+c=0
    @param b - second quofficient of square equation
    @param c - third quofficient of square equation
    @param err - variable where error code is to be stored
 */

void user_input_reading(double* a, double* b, double* c, char* err){ // rewrite with cycle

    static int i = TRIES_TO_TYPE;///backward counter to prevent from long recursion and to output help docs only the first time user typed wrong

    assert(a != nullptr);
    assert(b != nullptr);
    assert(c != nullptr);
    assert(err != nullptr);

    if(i < LAST_TRY){///if too many bad tries
        printf(COLOR_RED "Shut down, stupid user! You are too silly even to type three numbers correctly!\n" COLOR_NONE);///warning user
        *err = ERROR_UNCAUGHT;///preventing wrong output with error code
        return;
    }

    printf("Input 3 numbers\n");///ask user to type
    int scan_status = scanf("%lg %lg %lg", a, b, c);/// scanning numbers, counting how much scanned successfully (must be CORRECT_SCAN_STATUS=3)




    if (buffer_eraser() || scan_status != CORRECT_SCAN_STATUS){ ///if garbage found or scanned less than 3 variables
        debug(ERROR_INVALID_INPUT);///throwing exception via dbg function if something wrong with input
        if(i == TRIES_TO_TYPE){///the first time user typed wrong
            help();///output help documentation
            printf("Please, read documentation and try again.\n");///ask user to retry
        }
        i--;///decreasing counter before recursively calling function to avoid infinite cycle and
        user_input_reading(a, b, c, err);///recursively calling this function in order to give user next try
    }
}


/*!
    buffer_eraser function
    erases buffer until the end of the line
    returns true if buffer has garbage (not ' ' or '\n')
    returns false if everything is ok


 */
bool buffer_eraser(){
    bool ret = false; //!<this variable checks whether string has garbage or not
    int c = getchar();///reading next character
    while(c != '\n'){///until the end of line checks
        if(c != ' '){ret = true;}///if garbage found (garbage is everything except ' ' and '\n')
        c = getchar();///reading next character
    }
    return ret;///returning logic value
}

