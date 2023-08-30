#include "equation_solution.h"
#include "input_output.h"
#include "debugger.h"
#include "unit_tests.h" //encommenting this line avoids including test mode files

 //#define TEST_MODE //to disable test code, encomment this line

/*!
    Function where code is executed
 */
int main(const int argc, const char *argv[]) {

    if (argc > 1) {
        for (int i = 1; i < argc; i ++){
            proceed_command_line(argv[i]);
            printf("\n");
        }
    } else {
        program(SQUARE_MODE);
    }
}

bool proceed_command_line(const char* arg){
    if (strlen(arg) > 1 && arg[0]=='-') {
        switch (arg[1]) {
            case 'h':
                help();
                break;
            case 'u':
                usage();
                break;
            case 't':

#ifdef TEST_MODE
                if (strlen(arg)<4) {
                    test_mode("texts.txt");
                } else if (arg[2]=='=') {
                    test_mode(arg+3);
                } else {
                    printf("Invalid syntax\n");
                    usage();
                }
#else
                printf("Test mode inactive, release version.\n");
#endif
                break;
            case 's':
                program(SQUARE_MODE);
                break;
            case 'l':
                program(LINEAR_MODE);
                break;
            default:
                printf("Unknown parameter -%c\n", arg[1]);
                usage();
        }
    } else {
        printf("Invalid syntax\n");
        usage();
    }
    return true;
}

void program(const int mode) {
    char err = WITHOUT_ERRORS;        //error catcher
    double a = NAN, b = NAN, c = NAN; //input values
    double x1 = NAN, x2 = NAN;        //answer data keeper
    int number_of_roots = INCORRECT_ROOTS;

    user_input_reading(&a, &b, &c, &err, mode); //importing values, 7 tries to type
    if (err == WITHOUT_ERRORS) {
        number_of_roots = square_equation_solution(a, b, c, &x1, &x2, &err); //solving equation
    }

    if (err == WITHOUT_ERRORS) {
        output_answers(a, b, c, number_of_roots, x1, x2, &err); //printing answer if no errors
    }

    print_errors_description(err); //printing errors if any (except errors already printed, as they just prevent output)
}

void usage() {
    printf("Usage: ./program"
#ifdef TEST_MODE
    "_test"
#endif
    " (-h help/-u usage/-t(=testfilename.ext) unit tests/-s forced standart mode)\n");
}
