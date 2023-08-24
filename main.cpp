#include "equation_solution.h"
#include "input_output.h"
#include "debugger.h" //error catcher

#include "unit_tests.h" //encommenting this line avoids including test mode files

#undef  TEST_MODE //to enable test code, encomment this line




int main(){
    char err = WITHOUT_ERRORS; //error catcher
    double a = NAN, b = NAN, c = NAN, //input values
           x1 = NAN, x2 = NAN;       //answers

    #ifdef TEST_MODE
    test_mode();
    #else
    user_input_reading(&a, &b, &c, &err, 7); //importing values, 7 tries to type
    int number_of_roots;
    number_of_roots = square_equation_solution(a, b, c, &x1, &x2, &err);
    output_answers(number_of_roots, x1, x2, err);
    debug(err);
    #endif
}
