#include "functions.h"


vector<string> Equation:: no_of_variables;

Equation::Equation()
{
	
	//initialize variables and coofecients
	for (int i = 0; i < 100; i++)
	{		
		variables.push_back( "x" + to_string(i + 1));
		coefficients.push_back(0);
	}
	constant_term = 0;
	
}

void Equation::set_coefficients(float value, int index)
{
	coefficients[index] = value;
}

void Equation::set_variables(string value, int index)
{
	variables[index] = value;
}

float* Equation::get_coefficient()
{
	//return  this->coefficients;
	return 0;
}

void Equation::set_constant_term(float value)
{
	constant_term = value;	
}

void Equation::print_equation_object()
{
	for (int i = 0; i < variables.size(); i++)
	{
		cout << coefficients[i] << " " << variables[i] << endl;
	}
	cout << constant_term << endl;
}

void Equation::print_equation_in_text_line_form()
{
	int fisrt_variable_flag = 1;
	for (int i = 0; i < coefficients.size(); i++)
	{
		
		if (coefficients[i] != 0)
		{
			if (!fisrt_variable_flag && coefficients[i] > 0)
			{
				cout << "+" << coefficients[i] << variables[i];
			}

			else
			{
				cout << coefficients[i] << variables[i];
				fisrt_variable_flag = 0;
			}
		}

	}
	cout <<"="<< constant_term << endl;
}

void Equation::count_no_of_variables(Equation equation)
{
	//loop over no_of_variables and add any new x
	//for the very first x
	for (int i = 0; i < equation.variables.size(); i++)
	{
		if(Equation::no_of_variables.size()==0&& equation.coefficients[i] != 0)
		{Equation::no_of_variables.push_back(equation.variables[i]);}
	}
    
	for (int i = 0; i < equation.variables.size(); i++)
	{	
		int flag = 1;
		for (int ii = 0; ii < Equation::no_of_variables.size(); ii++)
		{
			if (equation.variables[i] == Equation::no_of_variables[ii]||
				equation.coefficients[i]==0)
			{
				flag = 0;break; 
			}
		}
		if(flag)
		{Equation::no_of_variables.push_back(equation.variables[i]);}
	
	}
	
	return;
}

vector<string> Equation::get_variables()
{
	return vector<string>();
}

void Equation::print_no_of_variables()
{
	cout << Equation::no_of_variables.size()<<endl;
}
