#include "Class.h"


void Class::input(std::string str)
{
	std::cout << "Enter some numbers with signes in between them(+, -, *, /): ";
	std::getline(std::cin, str);

	m_String_input =  str;
}

void Class::getSplit_input()
{
	int  str_to_int = 0, al, d = 1;
	bool flag = false;
	std::string str;

	int k = 1, l = 0, dd = 0;

	dd = std::stoi(m_String_input);
	m_Vector_int.push_back(dd);

	/*for (int i = 0;i <= m_String_input.size(); i++)
	  {
		  std::cout << i;
		  if (m_String_input.at(i) == ' ')
		  {
			  l = i + 1;
			  if (m_String_input.at(l) == '+' || m_String_input.at(l) == '-' || m_String_input.at(l) == '*' || m_String_input.at(l) == '/')
			  {
				  for (int j = (i - 1); j >= 0; j--)
				  {
					  if (!flag)
					  {
						  flag = true;
						  str = m_String_input.at(j);
						  str_to_int = std::stoi(str);
						  al = str_to_int;
					  }
					  else
					  {
						  str = m_String_input.at(j);
						  str_to_int = std::stoi(str);
						  k = str_to_int;
						  d *= 10;
						  k *= d;
						  al += k;

					  }


					  m_Vector_int.push_back(al);
					  m_Vector_char.push_back(l);
				  }
			  }
		  }
	}*/
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