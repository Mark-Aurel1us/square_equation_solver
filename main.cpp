#include "equation_solution.h"
#include "input_output.h"
#include "debugger.h" //error catcher
#include "unit_tests.h" //encommenting this line avoids including test mode files

#define TEST_MODE //to disable test code, encomment this line


 /*
  *
  *
  *
  *
  *
  *
  *
  *
  *
  *
  *
  *
  *
  *
  *
  *
  *
  *
  *
  *
  *
  */
int main(){


#ifdef TEST_MODE
    test_mode();
#else
    char err = WITHOUT_ERRORS;        //error catcher
    double a = NAN, b = NAN, c = NAN, //input values
           x1 = NAN, x2 = NAN;        //answers

    user_input_reading(&a, &b, &c, &err, TRIES_TO_TYPE); //importing values, 7 tries to type

    int number_of_roots = square_equation_solution(a, b, c, &x1, &x2, &err);

    output_answers(number_of_roots, x1, x2, err);
    debug(err);
#endif // TEST_MODE
}
