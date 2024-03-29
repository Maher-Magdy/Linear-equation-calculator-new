#pragma once
#include"functions.h"
class Matrix
{public:
	static vector<vector<float>> coefficients;
	static vector<float> constant_terms;
	//static float determinant;

public:

	//constructor
	Matrix();
	// pseudo constructor
	static void _Matrix();
	static void print_column_no_i(string variable_name);
	static void add_or_subtract(int first_equation_index,int second_equation_index,string operation, int first_multiplication_factor,int second_multiplication_factor);
	static void substitute_equations(string variable_name,int first_equation_index,int second_equation_index);
	static void print_determinant(int variable_index);
	static float calc_determinant(int variable_index);
	static float online_determinant_calculator(float matrix[100][100], int n);
};

