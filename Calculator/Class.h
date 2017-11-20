#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

class Class
{
private:
	std::string m_String_input;
	std::vector<char> m_Vector_char;//for the split
	std::vector<int> m_Vector_int;//for the split
public:
	void Class::getSplit_input(char new_char);
	void input(std::string str);
	double calculate();
	void output();
};