#pragma once
#include<string>
#include<vector>
using namespace std;
class Equation
{
public:
	vector<float> coefficients;
	vector<string> variables;
	float constant_term;
	static vector<string> no_of_variables;

public:
	//constructor
	Equation();
	
	void set_coefficients(float value , int index);
	void set_variables(string value, int index);
	float* get_coefficient();
	void set_constant_term(float value);
	void print_equation_object();
	void print_equation_in_text_line_form();
	static void count_no_of_variables(Equation equation);
	vector < string > get_variables();
	static void print_no_of_variables();
	
};

