#include "functions.h"
using namespace std;
//global variables :
int no_of_equations;

//there are 11 operations
 int operation = 0;
 //equations
 vector<Equation> equations;


  
int mapping_operation(string input)
{	
	//assign every command to an operation number 
	if (input == "quit") return 0;
	if (input == "num_vars") return 1;
	if (input.substr(0, 8) == "equation") return 2;
	if (input.substr(0, 6) == "column") return 3;
	if (input.substr(0, 3) == "add") return 4;
	if (input.substr(0, 8) == "subtract") return 5;

	if (input.substr(0, 10) == "substitute") return 6;
	if (input == "D") return 7;
	if (input.substr(0, 1) == "D" && input.length() < 7) return 8;
	if (input == "D_value") return 9;
	if (input == "solve") return 10;



	/* switch doesn't work on strings (:
	switch (input)
	{
	case "quit":
		return 0;
	}
	*/
	return 11;
}

// get all equations input data 
void read_user_equations()
{
	string input_line;
	//getline(cin>>ws,input_line);
	for (int i = 0; i < no_of_equations; i++)
	{
		//for some unholy reason retarded getline function fucks up at the first iteration
		if(i==0)getline(cin, input_line);
		getline(cin , input_line);
		//input_line = "x3+x2-1-551+126+14-16.3-2+x1+3-2.5-x2-3.2x4+x1+x1+x1+x1+x1+x1+x1+x1+x1+x1=0";
		//remove all spaces 
		input_line=remove_spaces(input_line);
		equations.push_back(parser(input_line));
	}
	//equations[0].print_equation_object();//cout for testing
}

string remove_spaces(string input_line)
{
	string result= input_line;
	int index = 0;
	for (int i = 0; i < input_line.length(); i++)
	{
		if (input_line[i]==' ')
		{
			continue;
		}
		result[index] = input_line[i];
		index++;
	}	
	return result.substr(0,index);
}

Equation parser(string input_line)
{
	//vectors to store terms then pass them to equation object
	vector<string> terms;
	vector<float> coefficients;
	vector<string>variables;
	float constant_term = 0;
	//the first char 
	string term;
	term = input_line[0];
	//loop over the string to get all terms
	for (int i = 1; i < input_line.length(); i++)
	{
		if (input_line[i] == '+' || input_line[i] == '-' || input_line[i] == '=')
		{
			// push back and clear term
			terms.push_back(term);
			term = "";
			term = (input_line[i] == '-') ? "-" : term;
			term = (input_line[i] == '=') ? "=" : term;

		}
		else
		{
			term += input_line[i];
		}


	}
	//push the last term
	terms.push_back(term);

	//first locate the "=" sign index to invert all terms after the "=" sign 
	int index_of_equal_sign = 0;
	for (int i = 0; i < terms.size(); i++)
	{
		if (terms[i][0] == '=')
		{
			index_of_equal_sign = i;
			//delete the = sign
			terms[i].erase(terms[i].begin());
		}
	}
	// now invert all terms after the = sign
	for (int i = index_of_equal_sign; i < terms.size(); i++)
	{
		if (terms[i][0] == '-') { terms[i].erase(terms[i].begin()); }
		else { terms[i] = "-" + terms[i]; }

	}
	//now we have all the terms stored in terms vector



	//step 1 of 4 -1 or 1 coefficients are optional
	for (int i = 0; i < terms.size(); i++)
	{
		if (terms[i][0] == 'x')
		{
			terms[i] = "1" + terms[i];
		}
		else if (terms[i][0] == '-' && terms[i][1] == 'x')
		{
			terms[i].erase(terms[i].begin());
			terms[i] = "-1" + terms[i];
		}

	}

	//step 2 of 4 constant term repetition

	for (int i = 0; i < terms.size(); i++)
	{
		if (terms[i].find('x') == string::npos)
		{
			constant_term += atof(terms[i].c_str());
			terms[i] = "";
		}
	}
		
	//remove any empty terms
	int flag = 1;
	while (flag)
	{
		flag = 0;
		auto it = find(terms.begin(), terms.end(), "");
		if (it != terms.end()) 
		{ terms.erase(it); flag = 1;}
			 
	}

	// divide terms into coefficients and variables 
	for (int i = 0; i < terms.size(); i++)
	{
		//store variables and coefficients in their respective vectors
		coefficients.push_back(atof(terms[i].c_str()));
		size_t found = terms[i].find("x");
		string find_variable = terms[i].substr(found, terms[i].size() - found);
		variables.push_back(find_variable);
	}

	//step 3 of 4 variable repetition
	for (int i = 0; i < variables.size(); i++)
	{
		for (int ii = i + 1; ii < variables.size(); ii++)
		{
			if (variables[ii] == variables[i])
			{
				//if repetition found add the coefficients and delete the repeated 
				coefficients[i] += coefficients[ii];
				coefficients[ii] = 0; variables[ii] = "";
			}
		}
	}

	//remove any empty variables. coefficients
	flag = 1;
	while (flag)
	{		
		flag = 0;//to make sure to keep 0 coefficients
		int index=0;
		int index2 =0;		
		auto  it = find(variables.begin(), variables.end(), "");
		if (it != variables.end())
		{
			index = distance(variables.begin(), it);
			variables.erase(it);
			coefficients.erase(coefficients.begin() + index);
			flag = 1;
		}
				
		
		
		
		
	}
	
	
	//step 4 of 4 sorting
	//using a map is so much easier than 2 vectors
	map <string, float> variables_and_coefficients;
	for (int i = 0; i < variables.size(); i++)
	{
		variables_and_coefficients[variables[i]] = coefficients[i];
	}
	/*
	//cout for testing
	for (auto it = variables_and_coefficients.begin(); it != variables_and_coefficients.cend(); ++it)
	{
		cout << it->first << " " << it->second << "\n";
	}
	
	for (int i = 0; i < terms.size(); i++)
	{
		cout << terms[i] << endl;
	}
	for (int i = 0; i < variables.size(); i++)
	{
		cout << variables[i] << endl << coefficients[i] << endl;
	}
	cout << constant_term << endl;

	*/
	
	//cout for testing
	


	//set the parsed result vectors into an equation object
	Equation result;
	for (auto it = variables_and_coefficients.begin(); it != variables_and_coefficients.end(); it++)
	{
		//get the index
		int index = 0;
		while (true) 
		{
			if (it->first == ("x" + to_string(index + 1)))break;
			index++ ;
		}
		
		result.set_variables(it->first, index);
		result.set_coefficients(it->second, index);
		
	}
	constant_term = (constant_term==0) ? 0 : constant_term*-1;
	result.set_constant_term(constant_term);
	//result.print_equation_object(); //cout for testing
	
	return result;
}

void num_vars()
{
	//must loop on all equations vector to count variables
	for (int i = 0; i < equations.size(); i++)
	{
		
		Equation::count_no_of_variables(equations[i]);
	}
	Equation::print_no_of_variables();
}

void print_equation_no_i(string input)
{
	//get the equation index
	int equation_index;
	equation_index = atof(input.substr(9, (input.length() - 9)).c_str())-1 ;
	if(equation_index<no_of_equations)
		equations[equation_index].print_equation_in_text_line_form();
	

}



