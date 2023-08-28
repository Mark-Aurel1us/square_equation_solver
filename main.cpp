#include "equation_solution.h"
#include "input_output.h"
#include "debugger.h"
#include "unit_tests.h" //encommenting this line avoids including test mode files

// #define TEST_MODE //to disable test code, encomment this line

/*!
    main function

    where code executes
 */
int main(){

#ifdef TEST_MODE
    test_mode(); //testing
#else
    char err = WITHOUT_ERRORS;        //error catcher
    double a = NAN, b = NAN, c = NAN; //input values
    double x1 = NAN, x2 = NAN;        //answer data keeper
    int number_of_roots = INCORRECT_ROOTS;

    user_input_reading(&a, &b, &c, &err); //importing values, 7 tries to type
    if(err == WITHOUT_ERRORS){
        number_of_roots = square_equation_solution(a, b, c, &x1, &x2, &err); //solving equation
    }

    if(err == WITHOUT_ERRORS){
        output_answers(a, b, c, number_of_roots, x1, x2, &err); //printing answer if no errors
    }
    print_errors_description(err); //printing errors if any (except errors already printed, as they just prevent output)

#endif // TEST_MODE
}
