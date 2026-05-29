#include "root_finder.h"

void solve_by_chords(double a, double b, size_t max_iters)
{
    double f_a = evaluate_func(a);
    double f_b = evaluate_func(b);

    if (f_a * f_b >= 0)
    {
        std::cout << "Sign(f(a)) = Sign(f(b))" << std::endl;
        return;
    }

    ChordMethodTable::print_table_header();

    double c = 0.0;
    double f_c = 0.0;
    double eps = 1e-12;
    int should_break = 0;

    for (size_t i = 1; i <= max_iters; ++i)
    {
        __asm__(
            ".intel_syntax noprefix\n\t"
            "fld qword ptr [%[pa]]\n\t"
            "fmul qword ptr [%[pf_b]]\n\t"
            "fld qword ptr [%[pb]]\n\t"
            "fmul qword ptr [%[pf_a]]\n\t"
            "fsubp st(1), st(0)\n\t"
            "fld qword ptr [%[pf_b]]\n\t"
            "fsub qword ptr [%[pf_a]]\n\t"
            "fdivp st(1), st(0)\n\t"
            "fstp qword ptr [%[pc]]\n\t"
            ".att_syntax"
            :
            : [pa] "r" (&a), [pb] "r" (&b), [pf_a] "r" (&f_a), [pf_b] "r" (&f_b), [pc] "r" (&c)
            : "memory"
        );

        f_c = evaluate_func(c);

        __asm__ (
            ".intel_syntax noprefix\n\t"
            "fld qword ptr [%[pf_c]]\n\t"
            "fabs\n\t"
            "fcomp qword ptr [%[peps]]\n\t"
            "fstsw ax\n\t"
            "sahf\n\t"
            "jae 1f\n\t"
            "mov dword ptr [%[pshould_break]], 1\n\t"
            "1:\n\t"
            ".att_syntax"
            :
            : [pf_c] "r" (&f_c), [peps] "r" (&eps), [pshould_break] "r" (&should_break)
            : "ax", "cc", "memory"
        );

        ChordMethodTable::print_row(i, c, f_c);

        if (should_break)
        {
            break;
        }

        __asm__ (
            ".intel_syntax noprefix\n\t"
            "fld qword ptr [%[pf_c]]\n\t"
            "fmul qword ptr [%[pf_b]]\n\t"
            "ftst\n\t"
            "fstsw ax\n\t"
            "sahf\n\t"
            "fstp st(0)\n\t"
            "jb 2f\n\t"

            "fld qword ptr [%[pc]]\n\t"
            "fstp qword ptr [%[pb]]\n\t"
            "fld qword ptr [%[pf_c]]\n\t"
            "fstp qword ptr [%[pf_b]]\n\t"
            "jmp 3f\n\t"

        "2:\n\t"
            "fld qword ptr [%[pc]]\n\t"
            "fstp qword ptr [%[pa]]\n\t"
            "fld qword ptr [%[pf_c]]\n\t"
            "fstp qword ptr [%[pf_a]]\n\t"

        "3:\n\t"
            ".att_syntax"
            :
            : [pa] "r" (&a), [pb] "r" (&b), [pf_a] "r" (&f_a), [pf_b] "r" (&f_b), [pc] "r" (&c), [pf_c] "r" (&f_c)
            : "ax", "cc", "memory"
        );
    }

    ChordMethodTable::print_table_bottom();
}

double evaluate_func(double x)
{
    // Function: f(x) = sin(x^2 - 5)
    double res;
    double const_five = 5.0;
    double const_two = 2.0;
    
    __asm__ (
        "fldl %[x]\n\t"             
        "fmul %%st(0), %%st(0)\n\t" 
        "fsubl %[five]\n\t"         
        "fsin\n\t"                
        "fmull %[two]\n\t"         
        "fstpl %[res]"             
        : [res] "=m" (res)
        : [x] "m" (x), [five] "m" (const_five), [two] "m" (const_two)
    );
    return res;
}