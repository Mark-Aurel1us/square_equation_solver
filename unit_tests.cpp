#include "unit_tests.h"

/*!
 testing function. Helps to test the code.
*/
void test_mode(const char* filename) {

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

    for (size_t i = 0; i < sizeof(tests)/sizeof(tests[0]); i++) {
        all_correct &= unit_test(tests + i, i + 1);// &tests[i]
    }

    all_correct &= file_unit_tests(filename);

    if (all_correct) {
        printf(COLOR_GREEN "All tests passed successfully!\n" COLOR_RESET);
    }
}

/*!
 Single unit test function. Tests once, outall_correctputs wrong answers if any. Returns true if everything is correct, else returns false
 @param test - single test data
 @param i - test id. Required to output which test went wrong.
*/
bool unit_test(const test_case* test, size_t i) {

    char err = WITHOUT_ERRORS;
    double x1 = NAN,
           x2 = NAN;

    int n = square_equation_solution(test->a, test->b, test->c, &x1, &x2, &err);

    if (n == test->n_expected && err == WITHOUT_ERRORS) {
        if (n == 0 || n == INF_ROOTS) {
            return true;
        }
        if (n == 1 && equal_double(x1, test->x1_expected)) {
            return true;
        }
        if (n == 2 && equal_double(x1, test->x1_expected) && equal_double(x2, test->x2_expected)) {
            return true;
        }

        if (n == 2 && equal_double(x2, test->x1_expected) && equal_double(x1, test->x2_expected)) {
            return true;
        }
    }
    error_test_case(test, x1, x2, n, (int)i);
    return false;
}

/*!
 function which returns information about wrong answer of one unit test
 @param test - single test data
 @param i - test id. Required to output which test went wrong.
 @param x1 - got answer
 @param x2 - got answer
 @param n - got roots count
*/
void error_test_case(const test_case* test, double x1, double x2, int n, int i) { // print_failed_test_info
    printf(COLOR_RED);
    printf( "Error in test case %d.\n"
            COLOR_RESET
            "   Tested Equation: ", i);
    output_equation(test->a, test->b, test->c);
    printf("\n"
            "   Expected results:\n     ");
    print_number_of_roots(test->n_expected);
    if (test->n_expected > 0) { print_root_test(test->x1_expected);}
    if (test->n_expected == 2) { print_root_test(test->x2_expected);}

    printf(COLOR_RED);
    printf("   Got results:\n     ");
    print_number_of_roots(n);
    if (n > 0) { print_root_test(x1); }
    if (n == 2) { print_root_test(x2); }
    printf(COLOR_RESET);
}
/*!
    prints one root
 */
void print_root_test(double x) {
    printf("       x=%lg\n", x);
}

/*!
 Function that run unit tests from file tests.txt, if it is found. Returns true if passed all tests
*/
bool file_unit_tests(const char* filename) {

    bool ok = true;
    struct test_case file_test;
    int stat = 6;
    int i = 0;
    FILE *file_ptr = fopen(filename, "r");

    if (file_ptr == nullptr) {
        printf(COLOR_RED "File with tests not found. Create %s file with valid unit tests in this directory" COLOR_RED "\n", filename);
        OUTERR("File not found")
        return true;
    }
    printf("Tests from file are running now.\n");

    while (stat == 6) {
        stat = fscanf(file_ptr, "%lg %lg %lg %d %lg %lg", &(file_test.a), &(file_test.b), &(file_test.c), &(file_test.n_expected), &(file_test.x1_expected), &(file_test.x2_expected));
        if (stat == 6) {
            ok &= unit_test(&file_test, i + 1);
        }
        i++;
    }
    if (ok) {
        printf("%d tests from file ran successfully\n", i - 1);
    }
    fclose(file_ptr);//check
    return ok;
}
