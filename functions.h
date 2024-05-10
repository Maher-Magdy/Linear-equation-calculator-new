#pragma once
#include "Equation.h"
#include<iostream>
#include<string>
#include <vector> 
#include "math.h"
#include <cmath>
#include<cstdlib>
#include<sstream>
#include<map>
using namespace std;

//global variables :

// the number of system equations
extern int no_of_equations;
// the request input from user
//extern string request;
//there are 11 operations
extern int operation;
// create n no of equations classes to store their attributes
extern vector<Equation> equations;





//functions declaration :
int mapping_operation(string input);
void read_user_equations();
string remove_spaces(string input_line);

//the parser function
Equation parser(string input_line);
// print number of variables function for operation 1
void num_vars();
// print equation number i-1 for operation 2
void print_equation_no_i(string input);


