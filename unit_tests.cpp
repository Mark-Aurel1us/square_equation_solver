#include "unit_tests.h"



void test_mode(){
    printf("TEST MODE ACTIVATED\n");

    bool all_correct = true;

    struct test_case tests[] = { // array of test cases
           //a                    b                       c                      n                     x1                    x2
        {
            1,                    2,                      1,                     1,                    -1,                   NAN     //test 1
        },

        {
            0,                    0,                      0,                     INFINITE_ROOTS_NUMBER, NAN,                 NAN     //test 2
        },

        {
            1,                    573,                    -574,                  2,                    -574,                 1       //test 3
        },

        {
            1,                    2,                       1,                     1,                     -1,                 NAN     //test 4
        }
    };

    for(long unsigned int i = 0; i < sizeof(tests)/sizeof(tests[0]); i++){ // size_t
        all_correct &= unit_test(tests + i, i + 1);// &tests[i]
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
    char err = WITHOUT_ERRORS;
    double x1 = NAN,
           x2 = NAN;

    int n = square_equation_solution((*test).a, (*test).b, (*test).c, &x1, &x2, &err);

    if(n == (*test).n_expected && err == WITHOUT_ERRORS){
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
    char b_sign = ((*test).b > 0) ? '+' : '-';//write sign of b
    char c_sign = ((*test).c > 0) ? '+' : '-';//write sign of c

        printf( "Error in test case %d.\n"
                "   Tested Equation: %c%lg*x^2%c%lg*x%c%lg=0\n"
                "   Expected results:\n", (int)i, a_sign, fabs(test->a), b_sign, fabs(test->b), c_sign, fabs(test->c));
    if(!isnan(test->x1_expected)){
        printf( "      x=%lg\n", test->x1_expected);
    }
    if(!isnan(test->x2_expected)){
        printf( "      x=%lg\n", test->x2_expected);
    }
       print_number_of_roots_dbg( test->n_expected);
        printf( "   Instead got:\n");
    if(!isnan(x1)){
        printf( "       x=%lg\n", x1);
    }
    if(!isnan(x2)){
        printf( "       x=%lg\n", x2);
    }
        print_number_of_roots_dbg( n);
        return false;
}


void print_number_of_roots_dbg(int roots_n){
printf( "      Number of roots:");
    switch (roots_n){
        case(INFINITE_ROOTS_NUMBER):
            printf("infinite");
        default:
            printf("%d",roots_n);
    }
printf("\n");
}


