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

    print_number_of_roots(number);
    print_not_nan(x1);
    print_not_nan(x2);
    printf(COLOR_RESET);

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

