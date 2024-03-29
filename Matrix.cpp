#include "Matrix.h"
//
vector<vector<float>> Matrix::coefficients;
vector<float> Matrix::constant_terms;
//float Matrix::determinant;

//constructor
Matrix::Matrix()
{
	for(int i=0;i<equations.size();i++)
	{
		coefficients.push_back(equations[i].coefficients);
		constant_terms.push_back(equations[i].constant_term);
		//for (int ii = 0; ii < equations.size(); ii++) cout << coefficients[i][ii]<<endl ;//cout for testing			
	}
}

void Matrix::_Matrix()
{
	coefficients.clear();
	constant_terms.clear();
}

void Matrix::print_column_no_i(string variable_name)
{
	//construct matrix
	Matrix::Matrix();
	//get variable index from variable name
	int index = atof(variable_name.substr(1, variable_name.length() - 1).c_str())-1;
	
	for (int i = 0; i < coefficients.size(); i++)
	{
		cout << coefficients[i][index]<<endl ;
	}
	//delete matrix
	Matrix::_Matrix();
}

void Matrix::add_or_subtract(int first_equation_index, int second_equation_index, string operation, int first_multiplication_factor, int second_multiplication_factor)
{
	//construct matrix
	Matrix::Matrix();
	if (operation == "add")
	{
		vector<float> added_coefficients;
		vector<string> variable_names;
		for (int i = 0; i < coefficients[first_equation_index].size(); i++)
		{
			added_coefficients.push_back(coefficients[first_equation_index][i]* first_multiplication_factor + coefficients[second_equation_index][i] * second_multiplication_factor);
			variable_names.push_back("x" + to_string(i + 1));
		}
		int first_variable_flag = 1;
		for (int i = 0; i < coefficients[first_equation_index].size(); i++)
		{

			if (added_coefficients[i] < 0)
			{
				cout << added_coefficients[i] << variable_names[i];
				first_variable_flag = 0;
			}
			else if (added_coefficients[i] > 0)
			{
				if (first_variable_flag)
				{
					cout << added_coefficients[i] << variable_names[i];
					first_variable_flag = 0;
				}
				else
					cout <<"+"<< added_coefficients[i] << variable_names[i] ;
			}
		}
		cout << "=" << constant_terms[first_equation_index]* first_multiplication_factor + constant_terms[second_equation_index] * second_multiplication_factor << endl;


	}
	else if(operation == "subtract")
	{

		vector<float> added_coefficients;
		vector<string> variable_names;
		for (int i = 0; i < coefficients[first_equation_index].size(); i++)
		{
			added_coefficients.push_back(coefficients[first_equation_index][i]* first_multiplication_factor - coefficients[second_equation_index][i]* second_multiplication_factor);
			variable_names.push_back("x" + to_string(i + 1));
		}
		int first_variable_flag = 1;
		for (int i = 0; i < coefficients[first_equation_index].size(); i++)
		{

			if (added_coefficients[i] < 0)
			{
				cout << added_coefficients[i] << variable_names[i];
				first_variable_flag = 0;
			}
			else if (added_coefficients[i] > 0)
			{
				if (first_variable_flag)
				{
					cout << added_coefficients[i] << variable_names[i];
					first_variable_flag = 0;
				}
				else
					cout << "+" << added_coefficients[i] << variable_names[i];
			}
		}
		cout << "=" << constant_terms[first_equation_index]* first_multiplication_factor - constant_terms[second_equation_index]* second_multiplication_factor << endl;


	
	}
	//delete matrix
	Matrix::_Matrix();

}

void Matrix::substitute_equations(string variable_name, int first_equation_index, int second_equation_index)
{
	//construct matrix
	Matrix::Matrix();
	//turn variable name to column index
	int index_of_variable_name = atof(variable_name.substr(1, variable_name.length()-1).c_str())-1;
	// get the coefficients of variable name x	
	int first_substituted_coefficient = coefficients[second_equation_index][index_of_variable_name];
	int second_substituted_coefficient = coefficients[first_equation_index][index_of_variable_name] ;
	
	//delete matrix
	Matrix::_Matrix();
	add_or_subtract(first_equation_index, second_equation_index,"subtract", first_substituted_coefficient,second_substituted_coefficient);
	
	
}

void Matrix::print_determinant(int variable_index)
{
	//construct matrix
	Matrix::Matrix();
	if (variable_index == 100)
	{
		for (int i = 0; i < no_of_equations; i++)
		{
			for (int ii = 0; ii < no_of_equations; ii++)
			{
				if (ii == no_of_equations - 1)
					cout << coefficients[i][ii];
				else
					cout << coefficients[i][ii] << " ";
			
			}
			cout << endl;
		}
	}
	else
	{		
		for (int i = 0; i < no_of_equations; i++)
		{
			coefficients[i][variable_index] = constant_terms[i];
			for (int ii = 0; ii < no_of_equations; ii++)
			{
				if (ii == no_of_equations - 1)
					cout << coefficients[i][ii];
				else
					cout << coefficients[i][ii] << " ";

			}
			cout << endl;
		}

	}
	//delete matrix
	Matrix::_Matrix();
}

float Matrix::calc_determinant(int variable_index)
{
	//construct
	Matrix::Matrix();
	float det = 0;
	float coefficient_array[100][100];
	for (int i = 0; i < 100; i++)
	{
		for (int ii = 0; ii < 100; ii++)
		{
			coefficient_array[i][ii] = 0;
		}
	}
	
	if (variable_index == 100)
	{
		for (int i = 0; i < no_of_equations; i++)
		{
			for (int ii = 0; ii < 100; ii++)
			{
				coefficient_array[i][ii] = coefficients[i][ii];

			}
		}
				
		det=online_determinant_calculator(coefficient_array, no_of_equations);
	}
	else 
	{
		for (int i = 0; i < no_of_equations; i++)
		{
			coefficients[i][variable_index] = constant_terms[i];
		}
		for (int i = 0; i < no_of_equations; i++)
		{
			for (int ii = 0; ii < 100; ii++)
			{
				coefficient_array[i][ii] = coefficients[i][ii];

			}
		}
		
		det = online_determinant_calculator(coefficient_array, no_of_equations );
	}
	
	
	
	//destroy
	Matrix::_Matrix();
	return det;
}
	/*
		
		//now create hyper determinant
		vector<vector<float>> hyper_determinant;
		for (int i = 0; i < no_of_equations; i++)
		{
			vector<float> temp;
			for (int j = 0; j < no_of_equations; j++)
			{
				temp.push_back(coefficients[i][j]);
			}
			hyper_determinant.push_back(temp);

			for (int ii = 0; ii < no_of_equations - 1; ii++)
			{
				hyper_determinant[i].push_back(coefficients[i][ii]);

			}
		}

		//calculate the hyper determinant using 

		//return result1 - result2;
		
		
float Matrix::determ(float a[100][100], int n)
{
	float det = 0;
	float temp[100][100];
	int p, h, k, i, j;
	if (n == 1) {
		return a[0][0];
	}
	else if (n == 2) {
		det = (a[0][0] * a[1][1] - a[0][1] * a[1][0]);
		return det;
	}
	else {
		for (p = 0; p < n; p++) {
			h = 0;
			k = 0;
			for (i = 1; i < n; i++) {
				for (j = 0; j < n; j++) {
					if (j == p) {
						continue;
					}
					temp[h][k] = a[i][j];
					k++;
					if (k == n - 1) {
						h++;
						k = 0;
					}
				}
			}
			det = det + a[0][p] * pow(-1, p) * determ(temp, n - 1);
		}
		return det;
	}
}
*/
//stolen code online but can't calculate more than 4x4 sometime !!
float Matrix::online_determinant_calculator(float matrix[100][100], int n)
{
	int det = 0;
	float submatrix[100][100];
	if (n == 2)
		return ((matrix[0][0] * matrix[1][1]) - (matrix[1][0] * matrix[0][1]));
	else {
		for (int x = 0; x < n; x++) {
			int subi = 0;
			for (int i = 1; i < n; i++) {
				int subj = 0;
				for (int j = 0; j < n; j++) {
					if (j == x)
						continue;
					submatrix[subi][subj] = matrix[i][j];
					subj++;
				}
				subi++;
			}
			det = det + (pow(-1, x) * matrix[0][x] * online_determinant_calculator(submatrix, n - 1));
		}
	}
	return det;
}