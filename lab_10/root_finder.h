#ifndef ROOT_FINDER_H
#define ROOT_FINDER_H

#include <stddef.h>
#include <iostream>
#include "table_printer.h"

double evaluate_func(double x);
void solve_by_chords(double a, double b, size_t max_iters);

#endif // ROOT_FINDER_H