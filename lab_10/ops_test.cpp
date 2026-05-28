#include "ops_test.h"
#include "table_printer.h"
#include "config.h"
#include <chrono>

static void run_cpp_float_benchmarks();
static void run_cpp_double_benchmarks();
static void run_asm_float_benchmarks();
static void run_asm_double_benchmarks();

void run_ops_tests() 
{
	OperationsTable::print_table_header();
	OperationsTable::print_table_top();

	run_cpp_float_benchmarks();
	OperationsTable::print_table_middle();

	run_cpp_double_benchmarks();
	OperationsTable::print_table_middle();

	run_asm_float_benchmarks();
	OperationsTable::print_table_middle();

	run_asm_double_benchmarks();
	OperationsTable::print_table_bottom();
}

static void run_cpp_float_benchmarks()
{
	float a = 1.0001f;
	float b = 0.0002f;
	auto start_add = std::chrono::high_resolution_clock::now();
	for (size_t i = 0; i < ITERATIONS; ++i)
		a += b;
	auto end_add = std::chrono::high_resolution_clock::now();
	OperationsTable::print_row("float addition", "C++", std::chrono::duration<double>(end_add - start_add).count());

	float c = 1.0001f;
	float d = 1.000002f;
	auto start_mul = std::chrono::high_resolution_clock::now();
	for (size_t i = 0; i < ITERATIONS; ++i)
		c *= d;
	auto end_mul = std::chrono::high_resolution_clock::now();
	OperationsTable::print_row("float multiplication", "C++", std::chrono::duration<double>(end_mul - start_mul).count());
}

static void run_cpp_double_benchmarks()
{
	double a = 1.0001;
	double b = 0.0002;
	auto start_add = std::chrono::high_resolution_clock::now();
	for (size_t i = 0; i < ITERATIONS; ++i)
		a += b;
	auto end_add = std::chrono::high_resolution_clock::now();
	OperationsTable::print_row("double addition", "C++", std::chrono::duration<double>(end_add - start_add).count());
	double c = 1.0001;
	double d = 1.000002;
	auto start_mul = std::chrono::high_resolution_clock::now();
	for (size_t i = 0; i < ITERATIONS; ++i)
		c *= d;
	auto end_mul = std::chrono::high_resolution_clock::now();
	OperationsTable::print_row("double multiplication", "C++", std::chrono::duration<double>(end_mul - start_mul).count());
}	

static void run_asm_float_benchmarks()
{
	float a = 1.0001f;
	float b = 0.0002f;
	auto start_add = std::chrono::high_resolution_clock::now();
	for (size_t i = 0; i < ITERATIONS; ++i)
	{
		__asm__(
			"flds %1\n\t"
			"flds %2\n\t"
			"faddp\n\t"
			"fstps %0\n\t"
			: "+m" (a)
			: "m" (b)
		);
	}
	auto end_add = std::chrono::high_resolution_clock::now();
	OperationsTable::print_row("float addition", "ASM", std::chrono::duration<double>(end_add - start_add).count());

	float c = 1.0001f;
	float d = 1.000002f;
	auto start_mul = std::chrono::high_resolution_clock::now();
	for (size_t i = 0; i < ITERATIONS; ++i)
	{
		__asm__(
			"flds %1\n\t"
			"flds %2\n\t"
			"fmulp\n\t"
			"fstps %0\n\t"
			: "+m" (c)
			: "m" (d)
		);
	}
	auto end_mul = std::chrono::high_resolution_clock::now();
	OperationsTable::print_row("float multiplication", "ASM", std::chrono::duration<double>(end_mul - start_mul).count());
}

static void run_asm_double_benchmarks()
{
	double a = 1.0001;
	double b = 0.0002;
	auto start_add = std::chrono::high_resolution_clock::now();
	for (size_t i = 0; i < ITERATIONS; ++i)
	{
		__asm__(
			"fldl %1\n\t"
			"fldl %2\n\t"
			"faddp\n\t"
			"fstpl %0\n\t"
			: "+m" (a)
			: "m" (b)
		);
	}
	auto end_add = std::chrono::high_resolution_clock::now();
	OperationsTable::print_row("double addition", "ASM", std::chrono::duration<double>(end_add - start_add).count());
	double c = 1.0001;
	double d = 1.000002;
	auto start_mul = std::chrono::high_resolution_clock::now();
	for (size_t i = 0; i < ITERATIONS; ++i)
	{
		__asm__(
			"fldl %1\n\t"
			"fldl %2\n\t"
			"fmulp\n\t"
			"fstpl %0\n\t"
			: "+m" (c)
			: "m" (d)
		);
	}
	auto end_mul = std::chrono::high_resolution_clock::now();
	OperationsTable::print_row("double multiplication", "ASM", std::chrono::duration<double>(end_mul - start_mul).count());
}