#ifndef UNIT_TESTS_H_INCLUDED
#define UNIT_TESTS_H_INCLUDED

#include "projectlib.h"
#include "equation_solution.h"


void test_mode();
bool unit_test(const struct test_case* test, size_t i);


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
