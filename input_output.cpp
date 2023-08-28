#include "input_output.h"


void output_answers(const double a, const double b, const double c, const int number, double x1, double x2, char* err){
    format_output(&x1);// avoid -0 output
    format_output(&x2);// avoid -0 output

    if(*err != WITHOUT_ERRORS){
        return;//preventing from outputting invalid results
    }

    printf("Equation ");
    output_equation(a, b, c);//outputting equation canonically
    printf(" has ");

    switch(number){//depending on how much roots the equation has, prints amount of roots
    case NO_ROOTS://if equation has no roots
        printf("no roots");
        break;
    case ONE_ROOT://if equation has one root
        printf("1 root: %lg", x1);
        break;
    case TWO_ROOTS://if equation has two roots
        printf("2 roots: %lg and %lg", x1, x2);
        break;
    case INF_ROOTS://if equation has infinite roots
        printf("infinite amount of roots");
        break;
    default:
        *err = ERROR_ROOTS_NUMBER;//error code to be proceeded by debug function
    }

    printf("\n\n");//new line
}



void user_input_reading(double* a, double* b, double* c, char* err){

    for(int i = 0; i < TRIES_TO_TYPE; i++){//backward counter to prevent from long recursion and to output help docs only the first time user typed wrong

        assert(a != nullptr);
        assert(b != nullptr);
        assert(c != nullptr);

        printf("Input 3 numbers\n");//ask user to type
        int scan_status = scanf("%lg %lg %lg", a, b, c);// scanning numbers, counting how much scanned successfully (must be CORRECT_SCAN_STATUS=3)

        if (buffer_eraser() || scan_status != CORRECT_SCAN_STATUS){ //if garbage found or scanned less than 3 variables
            print_errors_description(ERROR_INVALID_INPUT);//throwing exception via dbg function if something wrong with input

            if(i == 0){//the first time user typed wrong
                help();//output help documentation
                printf("Please, read documentation and try again.\n");//ask user to retry
            }

        }else{
            *err = WITHOUT_ERRORS;
            return;
        }

    }

    printf(COLOR_RED "Shut down, stupid user! You are too silly even to type three numbers correctly!\n" COLOR_RESET);//warning user
    *err = ERROR_UNCAUGHT;//preventing wrong output with error code

}


bool buffer_eraser(){
    bool ret = false; //this variable checks whether string has garbage or not
    int c = getchar();//reading next character

    while(c != '\n'&& c != EOF){//until the end of line checks
        if(!isspace(c)){
            ret = true;
        }
        c = getchar();//reading next character
    }

    return ret;//returning logic value
}

