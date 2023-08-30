#ifndef UNIT_TESTS_H_INCLUDED
#define UNIT_TESTS_H_INCLUDED

#include "projectlib.h"
#include "equation_solution.h"



bool file_unit_tests(const char* filename);
void test_mode(const char* filename);
bool unit_test(const struct test_case* test, size_t i);
void error_test_case(const test_case* test, double x1, double x2, int n, int i);
void print_root_test(double x);
//structures
/**

 test case structure
 where one unit test is to be stored

*/
struct test_case {
    ///first quotient of square equation
    double a; ///second quotient of square equation
    double b; ///third quotient of square equation
    double c; ///expected number of roots
    int n_expected; ///expected root (no roots or infinite roots)
    double x1_expected; ///expected root (NAN if 1 root, no roots or infinite roots)
    double x2_expected;
};

#endif // UNIT_TESTS_H_INCLUDED
