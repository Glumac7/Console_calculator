#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

class Class
{
private:
	std::string m_String_input;
	std::vector<char> m_Vector_char;//Holds all signs
	std::vector<int> m_Vector_int;//Holds all numbers

public:
	void input(std::string str);//User inputs numbers and signs
	void Class::getSplit_input();//Splits the input to signs and numbers
	double calculate();//Does some calculations
	void output();//Outputs the result to the screen
};