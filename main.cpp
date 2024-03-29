#include "functions2.h"

using namespace std;

int main()
{
	//the first user input indicates the number of equations	
	cin >> no_of_equations;
		
	
	// get all the equations
	read_user_equations();

	
	//get all user commands until quit is entered
	
	do
	{
		string input_line;
		getline(cin, input_line);		
		operation = mapping_operation(input_line);
		switch (operation)
		{
		case 1:num_vars(); break;
		case 2:print_equation_no_i(input_line); break;
		case 3:print_column_no_i(input_line); break;
		case 4:add_equations(input_line); break;
		case 5:subtract_equations(input_line); break;
		case 6:substitute_equations(input_line); break;
		case 7:Print_determinant(); break;
		case 8:Print_determinant_of_equation_i(input_line); break;
		case 9:print_determinant_value(); break;
		case 10:solve(); break;
		}
		
	}
	while (operation); //quit is operation 0
	
	

	return 0;
}