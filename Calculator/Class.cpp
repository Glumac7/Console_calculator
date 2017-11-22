#include "Class.h"


void Class::input(std::string str)
{
	std::cout << "Enter some numbers with signes in between them(+, -, *, /): ";
	std::getline(std::cin, str);

	m_String_input =  str + " ";
}

void Class::getSplit_input()
{
	int  str_to_int = 0, multiplier = 1, end_value = 0;
	int k = 1, l = 0, first_num = 0;
	bool flag;
	std::string str;

	first_num = std::stoi(m_String_input); //Gets the very firstcolection of numbers
	m_Vector_int.push_back(first_num); //And puts them in a std::vector<int>

	for (int i = 0; i < m_String_input.size(); i++) //While we don't get to the end
	{
		l = i + 1;
		if ((m_String_input.at(i) == '+' || m_String_input.at(i) == '-' || m_String_input.at(i) == '*' ||
			m_String_input.at(i) == '/') && m_String_input.at(l) == ' ')
		{
			int j = l + 1;
			while (m_String_input.at(j) != ' ') //'345' goes from 3 to the space after 5
			{
				j++;
			}

			j -= 1; //Eliminatess the space

			flag = false;
			while (j != l)  // Goes from 5 to 3 and does some calculations
			{
				if (!flag)
				{
					flag = true;
					str = m_String_input.at(j);
					str_to_int = std::stoi(str);
					end_value = str_to_int;
				}
				else
				{
					str = m_String_input.at(j);
					str_to_int = std::stoi(str);
					k = str_to_int;
					multiplier *= 10;
					k *= multiplier;
					end_value += k;
				}
				j--;
			}

			m_Vector_int.push_back(end_value); //Pushes the end_value
			m_Vector_char.push_back(i); //Pushes the sign(+, -, *, /)

										//Resets the values
			end_value = 0;
			k = 0;
			multiplier = 1;
			str_to_int = 0;

		}
	}
}

double Class::calculate()
{
	double res = 0;


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