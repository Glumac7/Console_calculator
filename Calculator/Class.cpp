#include "Class.h"
#include <iostream>
#include <string>
#include <vector>


void Class::input(std::string str)
{
	std::cout << "Enter some numbers with signes in between them(+, -, *, /): ";
	std::getline(std::cin, str);

	m_Vector_input.push_back(str);
}

/*std::vector<std::string> splited_string{ getSplit_input(str, ' ') };
	for (auto n : splited_string) std::cout << n << std::endl;*/

const std::vector<std::string> Class::getSplit_input(std::string new_string, char new_char)
{
	std::string buff{ "" };

	for (auto n:new_string)
	{
		if (n != new_char) buff += n;

		if (n == new_char && buff != "") 
		{ 
			m_Vector_splited.push_back(buff); buff = ""; 
		}
	}
	if (buff != "") m_Vector_splited.push_back(buff);

	return m_Vector_splited;
}

void Class::calculate()
{
	std::vector<std::string> splited_string{ getSplit_input(m_Vector_input, ' ') };
	for (auto n : m_Vector_splited) std::cout << n << std::endl;

	switch (m_Vector_splited)
	{
	default:
		break;
	}
}