#include "Class.h"


void Class::input(std::string str)
{
	std::cout << "Enter some numbers with signes in between them(+, -, *, /): ";
	std::getline(std::cin, str);

	m_Vector_input.push_back(str);
}

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

double Class::calculate()
{
	double res = 0;
	std::vector<double> test;

	std::string str;
	for (const auto &piece : m_Vector_input) str += piece;

	//std::vector<std::string> splited_string{ getSplit_input(str, ' ') };
	//for (auto n : m_Vector_splited) std::cout << n << std::endl;

	int i = 1;
	int	j = 0;

	while (i <= str.length())
	{
		if (str.at(i) == '+')
		{
			str = str.at(j);
			res += std::stod(str);
		}

		if (str.at(i) == '-')
		{
			str = str.at(j);
			res -= std::stod(str);
		}

		if (str.at(i) == '*')
		{
			str = str.at(j);
			res *= std::stod(str);
		}

		if (str.at(i) == '/')
		{
			str = str.at(j);
			res /= std::stod(str);
		}

		j++;
		i += 2;
	}

	return res;
}