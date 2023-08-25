#include "unit_tests.h"



void test_mode(){
    printf("TEST MODE ACTIVATED\n");

    bool all_correct = true;

    struct test_case tests[] = { // array of test cases
           //a        b           c           n           x1             x2
        {   1,        2,          1,          1,          -1,            NAN     //test 1
        },
        {
            0,        0,          0,          INF_ROOTS,   NAN,          NAN     //test 2
        },
        {
            1,        573,      -574,         2,          -574,          1       //test 3
        },
        {
            1,        2,          1,          1,          -1,            NAN     //test 4
        }
    };

    for(long unsigned int i = 0; i < sizeof(tests)/sizeof(tests[0]); i++){ // size_t
        all_correct &= unit_test(tests + i, i + 1);// &tests[i]
    }

    if(all_correct){
        printf(COLOR_GREEN
               "All tests passed successfully!\n"
               COLOR_NONE
               );
    }
}








bool unit_test(const test_case* test, size_t i){

    char err = WITHOUT_ERRORS;
    double x1 = NAN,
           x2 = NAN;

    int n = square_equation_solution((*test).a, (*test).b, (*test).c, &x1, &x2, &err);

    if(n == (*test).n_expected && err == WITHOUT_ERRORS){
            if(n == 0 || n == INF_ROOTS){
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


    printf( COLOR_RED
            "Error in test case %d.\n"
            "   Tested Equation: ",(int)i);
    output_equation((*test).a, (*test).b, (*test).c);
    printf( "\n"
            "   Expected results:\n");
    print_not_nan(test->x1_expected);
    print_not_nan(test->x2_expected);
    print_number_of_roots_dbg( test->n_expected);
    print_not_nan(x1);
    print_not_nan(x2);
    print_number_of_roots_dbg( n);
    printf(COLOR_NONE);
    return false;
}




void print_number_of_roots_dbg(int roots_n){
printf( "      Number of roots:");
    switch (roots_n){
        case(INF_ROOTS):
            printf("infinite");
            break;
        default:
            printf("%d",roots_n);
    }
printf("\n");
}


void print_not_nan(double x){
    if(!isnan(x)){
        printf( "       x=%lg\n", x);
    }
}


