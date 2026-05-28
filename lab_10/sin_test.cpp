#include "sin_test.h"
#include "table_printer.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

static void print_sin_row(const std::string& source, double pi_val);
static double get_hardware_pi();
static double asm_sin(double x);

void run_sin_precision_tests() {
    SinTable::print_table_header();
    SinTable::print_table_top();
    print_sin_row("3.14", 3.14);
    SinTable::print_table_middle();
    print_sin_row("3.141596", 3.141596);
    SinTable::print_table_middle();
    print_sin_row("fldpi", get_hardware_pi());
    SinTable::print_table_bottom();
}

static void print_sin_row(const std::string& source, double pi_val)
{
    double sin_pi = asm_sin(pi_val);
    double sin_pi_2 = asm_sin(pi_val / 2.0);

    SinTable::print_row(source.c_str(), pi_val, sin_pi, sin_pi_2);
}

static double get_hardware_pi() 
{
    double pi;
    __asm__ (
        "fldpi\n\t"   
        "fstpl %0"    
        : "=m" (pi)
    );
    return pi;
}

static double asm_sin(double x) 
{
    double res;
    __asm__ (
        "fldl %1\n\t" 
        "fsin\n\t"    
        "fstpl %0"     
        : "=m" (res)
        : "m" (x)
    );
    return res;
}