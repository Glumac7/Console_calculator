#include "Class.h"


void Class::input(std::string str)
{
	std::cout << "Enter some numbers with signes in between them(+, -, *, /): ";
	std::getline(std::cin, str);

	m_String_input =  str;
}

void Class::getSplit_input(char new_char)
{
	std::vector<int> local_vector;
	std::string str;

	for (const auto &piece : m_String_input) str += piece;

	local_vector.push_back(std::stoi(str));

	for (int i = 0; m_String_input.size(); i++)
	{
		if (m_String_input.at(i) == ' ' && (m_String_input.at(i++) == '+' || m_String_input.at(i++) == '-' || m_String_input.at(i++) == '*' || m_String_input.at(i++) == '/'))
		{
			m_Vector_char.push_back(i++);
		}
	}
}

double Class::calculate()
{
	double res = 0;

	std::string str;
	for (const auto &piece : m_String_input) str += piece;

	int i = 1;
	int	j = 0;

	while (i <= m_String_input.size())
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
void Class::output()
{
	std::cout << "SSS" << calculate();
}