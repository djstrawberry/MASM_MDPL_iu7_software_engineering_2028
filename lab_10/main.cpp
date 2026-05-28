#include "table_printer.h"
#include "ops_test.h"
#include "sin_test.h"
#include "root_finder.h"

int main() {
    run_ops_tests();
    run_sin_precision_tests();
    solve_by_chords(2.0, 2.5, 10);

    return 0;
}