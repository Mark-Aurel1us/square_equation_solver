#include "unit_tests.h"


/*
 testing function. Helps to test the code.
*/
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

    for(size_t i = 0; i < sizeof(tests)/sizeof(tests[0]); i++){
        all_correct &= unit_test(tests + i, i + 1);// &tests[i]
    }

    all_correct &= file_unit_tests();

    if(all_correct){
        printf(COLOR_GREEN "All tests passed successfully!\n" COLOR_RESET);
    }
}



/*
 Single unit test function. Tests once, outputs wrong answers if any. Returns true if everything is correct, else returns false
 @param test - single test data
 @param i - test id. Required to output which test went wrong.
*/
bool unit_test(const test_case* test, size_t i){

    char err = WITHOUT_ERRORS;
    double x1 = NAN,
           x2 = NAN;

    int n = square_equation_solution(test->a, test->b, test->c, &x1, &x2, &err);

    if(n == test->n_expected && err == WITHOUT_ERRORS){
            if(n == 0 || n == INF_ROOTS){
                return true;
            }
            if(n == 1 && equal_double(x1, test->x1_expected)){
                return true;
            }
            if(n == 2 && equal_double(x1, test->x1_expected) && equal_double(x2, test->x2_expected)){
                return true;
            }

            if(n == 2 && equal_double(x2, test->x1_expected) && equal_double(x1, test->x2_expected)){
                return true;
            }
    }
    error_test_case(test, x1, x2, n, i);
    return false;
}





/*
 function which returns information about wrong answer of one unit test
 @param test - single test data
 @param i - test id. Required to output which test went wrong.
 @param x1 - got answer
 @param x2 - got answer
 @param n - got roots count
*/
void error_test_case(const test_case* test, double x1, double x2, int n, int i){ // print_failed_test_info
    printf(COLOR_RED);
    printf("Error in test case %d.\n"
            "   Tested Equation: ",(int)i);
    output_equation(test->a, test->b, test->c);
    printf("\n"
            "   Expected results:\n");
    print_number_of_roots_dbg( test->n_expected);
    print_not_nan(test->x1_expected);
    print_not_nan(test->x2_expected);

    printf("   Got results:\n");
    print_number_of_roots_dbg( n);
    print_not_nan(x1);
    print_not_nan(x2);
    printf(COLOR_RESET);
}



/*
 Function that outputs number of roots
 @param n - number of roots
*/
void print_number_of_roots_dbg(int roots_n){
    printf("     ");
    switch (roots_n){
        case(INF_ROOTS):
            printf("All real numbers");
            break;
        case(NO_ROOTS):
            printf("No roots");
            break;
        case(ONE_ROOT):
            printf("One root:");
            break;
        case(TWO_ROOTS):
            printf("Two roots:");
            break;
        default:;
    }
    printf("\n");
}

/*
 Function that prints root if it is not NAN
*/

void print_not_nan(double x){
    if(!isnan(x)){
        printf("       x=%lg\n", x);
    }
}


/*
 Function that run unit tests from file tests.txt, if it is found. Returns true if passed all tests
*/

bool file_unit_tests(){
    bool ok = true;
    struct test_case file_test;
    int stat = 6;
    int i = 0;
    FILE *file_ptr = fopen("tests.txt", "r");
    if(file_ptr == nullptr){
        printf(COLOR_RED "File with tests not found. Create texts.txt file with valid unit tests in this directory" COLOR_RED "\n");
        OUTERR("File not found")
        return true;
    }
    printf("Tests from file are running now.\n");

    while(stat == 6){
        stat = fscanf(file_ptr, "%lg %lg %lg %d %lg %lg", &(file_test.a), &(file_test.b), &(file_test.c), &(file_test.n_expected), &(file_test.x1_expected), &(file_test.x2_expected));
        if(stat == 6){
            ok &= unit_test(&file_test, i + 1);
        }
        i++;
    }
    if(ok){printf("%d tests from file ran successfully\n", i - 1);}
    fclose(file_ptr);//check
    return ok;
}



