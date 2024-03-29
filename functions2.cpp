#include"functions2.h"


void print_column_no_i(string input_line)
{
	//get the variable name
	string variable_name;
	variable_name = input_line.substr(7, (input_line.length() - 7)).c_str();
	//now access matrix object to print a column
	Matrix::print_column_no_i(variable_name);
}

void add_equations(string input_line)
{
	//get the index for functions
	string first_equation_name = input_line.substr(4, (input_line.length() - 4));
	string second_equation_name;
    stringstream ss(input_line.substr(4, (input_line.length() - 4)).c_str());      
	while (getline(ss, second_equation_name, ' ')) { ; }
	int first_equation_index= atof(first_equation_name.c_str())-1;
	int second_equation_index = atof(second_equation_name.c_str()) - 1;
	Matrix::add_or_subtract(first_equation_index, second_equation_index,"add",1,1);
}
void subtract_equations(string input_line)
{
	//get the index for functions
	string first_equation_name = input_line.substr(9, (input_line.length() - 9));
	string second_equation_name;
	stringstream ss(input_line.substr(9, (input_line.length() - 9)).c_str());
	while (getline(ss, second_equation_name, ' ')) { ; }
	int first_equation_index = atof(first_equation_name.c_str()) - 1;
	int second_equation_index = atof(second_equation_name.c_str()) - 1;
	Matrix::add_or_subtract(first_equation_index, second_equation_index, "subtract",1,1);
}

void substitute_equations(string input_line)
{
	//get the index for functions
	string variable_name;
	string first_equation_name;
	string second_equation_name;
	string s;
	stringstream ss(input_line.substr(11, (input_line.length() - 11)).c_str());
	int i = 0;
	while (getline(ss, s, ' ')&&i<3) 
	{
		switch (i)
		{
		case 0:	variable_name = s;	break;
		case 1:	first_equation_name = s;	break;
		case 2:	second_equation_name = s; break;
		}

		i++ ;

	}
	int first_equation_index = atof(first_equation_name.c_str()) - 1;
	int second_equation_index = atof(second_equation_name.c_str()) - 1;
	Matrix::substitute_equations(variable_name ,first_equation_index, second_equation_index);
}

void Print_determinant()
{
	Matrix::print_determinant(100);
}

void Print_determinant_of_equation_i(string input_line)
{
	//get the variable index	
	int variable_index;	
	variable_index = atof(input_line.substr(3, (input_line.length() - 3)).c_str()) - 1;
	Matrix::print_determinant(variable_index);

}

void print_determinant_value()
{
	cout << Matrix::calc_determinant(100)<<endl;
}

void solve()
{
	float carmer_matrix_value = Matrix::calc_determinant(100);
	//check if dividing/0
	if (carmer_matrix_value == 0) 
	{
		cout << "No Solution"<<endl; return;
	}
	for (int i = 0; i < no_of_equations; i++)
	{
		float result = Matrix::calc_determinant(i) / carmer_matrix_value;	
		
			cout << "x"<<i+1 << "=" << result  << endl;
	}
}
