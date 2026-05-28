#ifndef TABLE_PRINTER_H
#define TABLE_PRINTER_H

#include <string>

namespace OperationsTable 
{
void print_table_header();
void print_table_top();
void print_table_middle();
void print_table_bottom();
void print_row(const char* operation, const char* type, double time);
} // namespace OperationsTable

namespace SinTable
{
void print_table_header();
void print_table_top();
void print_table_middle();
void print_table_bottom();
void print_row(const char* source, double pi_val, double sin_pi, double sin_pi_2);
} // namespace SinTable 

namespace ChordMethodTable
{
void print_table_header();
void print_table_top();
void print_table_middle();
void print_table_bottom();
void print_row(size_t iter, double root, double f);
} // namespace ChordMethodTable
    
#endif // TABLE_PRINTER_H