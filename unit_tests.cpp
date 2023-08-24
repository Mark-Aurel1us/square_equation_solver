#include "unit_tests.h"



void test_mode(){
    printf("TEST MODE ACTIVATED\n");

    bool all_correct = true;

    struct test_case tests[] = { // array of test cases
        {
            1,//a
            2,//b
            1,//c

            1,//n
            -1,//x1
            NAN//x2
        },

        {
            0,
            0,
            0,

            INFINITE_ROOTS_NUMBER,
            NAN,
            NAN
        },

        {
            1,
            573,
            -574,

            2,
            -574,
            1
        },

        {
            1,
            2,
            1,

            0,
            NAN,
            NAN
        }/*,

        {
        a,//double
        b,//double
        c,//double//

        n,//int
        x1,//double
        x2//double
        }
        */
    };

    for(long unsigned int i = 0; i < sizeof(tests)/sizeof(tests[0]); i++){ // size_t
        all_correct &= unit_test(tests + i, i + 1);
    }

    if(all_correct){
        printf("All tests passed successfully!");
    }
}








bool unit_test(const test_case* test, size_t i){
/*        double a = (*test).a,
               b = (*test).b,
               c = (*test).c,
     x1_expected = (*test).x1_expected,
     x2_expected = (*test).x2_expected;
  int n_expected = (*test).n_expected;
*/
    char err = '0';
    double x1 = NAN,
           x2 = NAN;

    int n = square_equation_solution((*test).a, (*test).b, (*test).c, &x1, &x2, &err);

    if(n == (*test).n_expected && err == '0'){
            if(n == 0 || n == INFINITE_ROOTS_NUMBER){
                return true;
            }
            if(n == 1 && equal_double(x1, (*test).x1_expected)){
                return true;
            }
            if(n == 2 && equal_double(x1, (*test).x1_expected) && equal_double(x2, (*test).x2_expected)){
                return true;
            }

            if(n == 2 && equal_double(x2, (*test).x1_expected) && equal_double(x1, (*test).x2_expected)){
                return true;
            }
    }

    char a_sign = ((*test).a > 0) ? ' ' : '-';//write sign of a is less than 0
    char b_sign = ((*test).b > 0) ?  '+' : '-';//write sign of b
    char c_sign = ((*test).c > 0) ?  '+' : '-';//write sign of c

    printf( "Error in test case %d.\n"
            "   Tested Equation: %c%lg*x^2%c%lg*x%c%lg=0\n"
            "   Expected results:\n"
            "      x=%lg\n"
            "      x=%lg\n"
            "      Number of roots:%d\n"
            "   Instead got:\n"
            "       x=%lg\n"
            "       x=%lg\n"
            "       Number of roots:%d\n", i, a_sign, fabs(test->a), b_sign, fabs(test->b), c_sign, fabs(test->c), test->x1_expected, test->x2_expected, test->n_expected, x1, x2, n);
    return false;
}
