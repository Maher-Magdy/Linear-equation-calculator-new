#pragma once
#include"matrix.h"
//global variables
extern Matrix equation_matrix;
//functions declaration
void print_column_no_i(string input);
void add_equations(string input_line);
void subtract_equations(string input_line);
void substitute_equations(string input_line);
void Print_determinant();
void Print_determinant_of_equation_i(string input_line);
void print_determinant_value();
void solve();