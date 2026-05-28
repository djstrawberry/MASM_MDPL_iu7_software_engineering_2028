#include "table_printer.h"
#include <iostream>
#include <iomanip>

namespace OperationsTable 
{
constexpr const char* COLOR_LINE = "\033[38;2;240;180;195m";
constexpr const char* COLOR_HEADER_BG = "\033[48;2;245;185;200m";
constexpr const char* COLOR_HEADER_FG = "\033[38;2;255;255;255m\033[1m";
constexpr const char* COLOR_TEXT = "\033[38;2;120;75;85m";
constexpr const char* COLOR_RESET = "\033[0m";

constexpr int WIDTH_COL1 = 23;
constexpr int WIDTH_COL2 = 8;
constexpr int WIDTH_COL3 = 12;

constexpr int ALIGN_COL1 = 21;
constexpr int ALIGN_COL2 = 6;
constexpr int ALIGN_COL3 = 10;

constexpr int PRECISION_TIME = 6;

void print_line(char left, char middle, char right, int col1, int col2, int col3)
{
    std::cout << COLOR_LINE << left;
    for (int i = 0; i < col1; ++i) std::cout << '-';
    std::cout << middle;
    for (int i = 0; i < col2; ++i) std::cout << '-';
    std::cout << middle;
    for (int i = 0; i < col3; ++i) std::cout << '-';
    std::cout << right << COLOR_RESET << std::endl;
}

void print_table_top()
{
    print_line('+', '+', '+', WIDTH_COL1, WIDTH_COL2, WIDTH_COL3);
}

void print_table_header()
{
    print_line('+', '+', '+', WIDTH_COL1, WIDTH_COL2, WIDTH_COL3);
    std::cout << COLOR_LINE << "|" << COLOR_RESET << COLOR_HEADER_BG << COLOR_HEADER_FG << " " << std::setw(ALIGN_COL1) << std::left << "Operation" << " " << COLOR_RESET
              << COLOR_LINE << "|" << COLOR_RESET << COLOR_HEADER_BG << COLOR_HEADER_FG << " " << std::setw(ALIGN_COL2) << std::left << "Type" << " " << COLOR_RESET
              << COLOR_LINE << "|" << COLOR_RESET << COLOR_HEADER_BG << COLOR_HEADER_FG << " " << std::setw(ALIGN_COL3) << std::left << "Time (s)" << " " << COLOR_RESET
              << COLOR_LINE << "|" << COLOR_RESET << std::endl;
}

void print_table_middle()
{
    print_line('+', '+', '+', WIDTH_COL1, WIDTH_COL2, WIDTH_COL3);
}

void print_table_bottom()
{
    print_line('+', '+', '+', WIDTH_COL1, WIDTH_COL2, WIDTH_COL3);
}

void print_row(const char* operation, const char* type, double time)
{
    std::cout << COLOR_LINE << "|" << COLOR_RESET << COLOR_TEXT << " " << std::setw(ALIGN_COL1) << std::left << operation << " "
              << COLOR_LINE << "|" << COLOR_RESET << COLOR_TEXT << " " << std::setw(ALIGN_COL2) << std::left << type << " "
              << COLOR_LINE << "|" << COLOR_RESET << COLOR_TEXT << " " << std::setw(ALIGN_COL3) << std::fixed << std::setprecision(PRECISION_TIME) << time << " "
              << COLOR_LINE << "|" << COLOR_RESET << std::endl;
}
}

namespace SinTable
{
constexpr const char* COLOR_LINE = "\033[38;2;165;210;185m";
constexpr const char* COLOR_HEADER_BG = "\033[48;2;175;220;195m";
constexpr const char* COLOR_HEADER_FG = "\033[38;2;255;255;255m\033[1m";
constexpr const char* COLOR_TEXT = "\033[38;2;55;90;75m";
constexpr const char* COLOR_RESET = "\033[0m";

constexpr int WIDTH_COL1 = 16;
constexpr int WIDTH_COL2 = 20;
constexpr int WIDTH_COL3 = 16;
constexpr int WIDTH_COL4 = 16;

constexpr int ALIGN_COL1 = 14;
constexpr int ALIGN_COL2 = 18;
constexpr int ALIGN_COL3 = 14;
constexpr int ALIGN_COL4 = 14;

constexpr int PRECISION_PI = 15;
constexpr int PRECISION_SIN_PI = 6;
constexpr int PRECISION_SIN_PI_2 = 12;

void print_line(char left, char middle, char right, int col1 = WIDTH_COL1, int col2 = WIDTH_COL2, int col3 = WIDTH_COL3, int col4 = WIDTH_COL4)
{
    std::cout << COLOR_LINE << left;
    for (int i = 0; i < col1; ++i) std::cout << '-';
    std::cout << middle;
    for (int i = 0; i < col2; ++i) std::cout << '-';
    std::cout << middle;
    for (int i = 0; i < col3; ++i) std::cout << '-';
    std::cout << middle;
    for (int i = 0; i < col4; ++i) std::cout << '-';
    std::cout << right << COLOR_RESET << std::endl;
}

void print_table_top()
{
    print_line('+', '+', '+');
}

void print_table_header()
{
    print_line('+', '+', '+');
    std::cout << COLOR_LINE << "|" << COLOR_RESET << COLOR_HEADER_BG << COLOR_HEADER_FG << " " << std::setw(ALIGN_COL1) << std::left << "PI source" << " " << COLOR_RESET
              << COLOR_LINE << "|" << COLOR_RESET << COLOR_HEADER_BG << COLOR_HEADER_FG << " " << std::setw(ALIGN_COL2) << std::left << "PI value" << " " << COLOR_RESET
              << COLOR_LINE << "|" << COLOR_RESET << COLOR_HEADER_BG << COLOR_HEADER_FG << " " << std::setw(ALIGN_COL3) << std::left << "sin(PI)" << " " << COLOR_RESET
              << COLOR_LINE << "|" << COLOR_RESET << COLOR_HEADER_BG << COLOR_HEADER_FG << " " << std::setw(ALIGN_COL4) << std::left << "sin(PI / 2)" << " " << COLOR_RESET
              << COLOR_LINE << "|" << COLOR_RESET << std::endl;
}

void print_table_middle()
{
    print_line('+', '+', '+');
}

void print_table_bottom()
{
    print_line('+', '+', '+');
}

void print_row(const char* pi_source, double pi_value, double sin_pi, double sin_pi_2)
{
    std::cout << COLOR_LINE << "|" << COLOR_RESET << COLOR_TEXT << " " << std::setw(ALIGN_COL1) << std::left << pi_source << " "
              << COLOR_LINE << "|" << COLOR_RESET << COLOR_TEXT << " " << std::setw(ALIGN_COL2) << std::fixed << std::setprecision(PRECISION_PI) << pi_value << " "
              << COLOR_LINE << "|" << COLOR_RESET << COLOR_TEXT << " " << std::setw(ALIGN_COL3) << std::scientific << std::setprecision(PRECISION_SIN_PI) << sin_pi << " "
              << COLOR_LINE << "|" << COLOR_RESET << COLOR_TEXT << " " << std::setw(ALIGN_COL4) << std::fixed << std::setprecision(PRECISION_SIN_PI_2) << sin_pi_2 << " "
              << COLOR_LINE << "|" << COLOR_RESET << std::endl;
}
}

namespace ChordMethodTable
{
constexpr const char* COLOR_LINE = "\033[38;2;195;185;235m";
constexpr const char* COLOR_HEADER_BG = "\033[48;2;200;190;240m";
constexpr const char* COLOR_HEADER_FG = "\033[38;2;255;255;255m\033[1m";
constexpr const char* COLOR_TEXT = "\033[38;2;75;65;105m";
constexpr const char* COLOR_RESET = "\033[0m";

constexpr int WIDTH_COL1 = 16;
constexpr int WIDTH_COL2 = 20;
constexpr int WIDTH_COL3 = 16;

constexpr int ALIGN_COL1 = 14;
constexpr int ALIGN_COL2 = 18;
constexpr int ALIGN_COL3 = 14;

constexpr int PRECISION_ROOT = 15;
constexpr int PRECISION_F = 6;

void print_line(char left, char middle, char right, int col1 = WIDTH_COL1, int col2 = WIDTH_COL2, int col3 = WIDTH_COL3)
{
    std::cout << COLOR_LINE << left;
    for (int i = 0; i < col1; ++i) std::cout << '-';
    std::cout << middle;
    for (int i = 0; i < col2; ++i) std::cout << '-';
    std::cout << middle;
    for (int i = 0; i < col3; ++i) std::cout << '-';
    std::cout << right << COLOR_RESET << std::endl;
}

void print_table_top()
{
    print_line('+', '+', '+');
}

void print_table_header()
{
    print_line('+', '+', '+');
    std::cout << COLOR_LINE << "|" << COLOR_RESET << COLOR_HEADER_BG << COLOR_HEADER_FG << " " << std::setw(ALIGN_COL1) << std::left << "Iter" << " " << COLOR_RESET
              << COLOR_LINE << "|" << COLOR_RESET << COLOR_HEADER_BG << COLOR_HEADER_FG << " " << std::setw(ALIGN_COL2) << std::left << "Root" << " " << COLOR_RESET
              << COLOR_LINE << "|" << COLOR_RESET << COLOR_HEADER_BG << COLOR_HEADER_FG << " " << std::setw(ALIGN_COL3) << std::left << "f(x)" << " " << COLOR_RESET
              << COLOR_LINE << "|" << COLOR_RESET << std::endl;
}

void print_table_middle()
{
    print_line('+', '+', '+');
}

void print_table_bottom()
{
    print_line('+', '+', '+');
}

void print_row(size_t iter, double root, double f)
{
    std::cout << COLOR_LINE << "|" << COLOR_RESET << COLOR_TEXT << " " << std::setw(ALIGN_COL1) << std::left << iter << " "
              << COLOR_LINE << "|" << COLOR_RESET << COLOR_TEXT << " " << std::setw(ALIGN_COL2) << std::fixed << std::setprecision(PRECISION_ROOT) << root << " "
              << COLOR_LINE << "|" << COLOR_RESET << COLOR_TEXT << " " << std::setw(ALIGN_COL3) << std::scientific << std::setprecision(PRECISION_F) << f << " "
              << COLOR_LINE << "|" << COLOR_RESET << std::endl;
}
}