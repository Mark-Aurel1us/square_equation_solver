#ifndef UNIT_TESTS_H_INCLUDED
#define UNIT_TESTS_H_INCLUDED

#include "projectlib.h"
#include "equation_solution.h"



bool file_unit_tests();
void test_mode();
bool unit_test(const struct test_case* test, size_t i);
void print_number_of_roots_dbg(int roots_n);
void print_not_nan(double x);
void error_test_case(const test_case* test, double x1, double x2, int n, int i);
//structures
struct test_case {
    double a;
    double b;
    double c;
    int n_expected;
    double x1_expected;
    double x2_expected;
};

#endif // UNIT_TESTS_H_INCLUDED
