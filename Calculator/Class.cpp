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
	int midle_value = 1, l = 0, first_num = 0;
	bool flag;
	std::string str;

	first_num = std::stoi(m_String_input); //Gets the very first colection of numbers
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
					midle_value = str_to_int;
					multiplier *= 10;
					midle_value *= multiplier;
					end_value += midle_value;
				}
				j--;
			}

			m_Vector_int.push_back(end_value); //Pushes the end_value
			m_Vector_char.push_back(m_String_input.at(i)); //Pushes the sign(+, -, *, /)

														   //Resets the values
			end_value = 0;
			midle_value = 0;
			multiplier = 1;
			str_to_int = 0;

		}
	}
}

double Class::calculate()
{
	double result = 0;
	double midel_var1;
	double midel_var2;
	double midel_var3;
	double midel_var4;
	int vector_int_index = 0;

	for (int i = 0; i < m_Vector_char.size(); i++) //Goes from the first to the last char in a vector(m_Vecotr_char)
	{
		
		switch (m_Vector_char.at(i))
		{
		case '+': //If 'm_Vector_char' that is being incremented by 'i' is '+' then...
			midel_var1 = double(m_Vector_int.at(vector_int_index));
			midel_var2 = double(m_Vector_int.at(vector_int_index + 1));
			if (m_Vector_char.at(i+1) == '*' || m_Vector_char.at(i + 1) == '/') //...it checks if the next index is '*' or '/'
			{
				break;
			}
			else if (i == 0) // If it's not then it check to see if 'i' is the first char in the program
			{
				result = midel_var1 + midel_var2; //If it is then the result is the value before + the value after '+'
			}
			else
				result += midel_var2;//If it's not the first sign in the program; the result is the result + the number after '+'
			break;

		case '-'://Same as the '+' but this time it's '-'
			midel_var1 = double(m_Vector_int.at(vector_int_index));
			midel_var2 = double(m_Vector_int.at(vector_int_index + 1));
			if (m_Vector_char.at(i + 1) == '*' || m_Vector_char.at(i + 1) == '/')
			{
				break;
			}
			if (i == 0)
			{
				result = midel_var1 - midel_var2;
			}
			else
				result -= midel_var2;
			break;

		case '*'://If 'm_Vector_char' that is being incremented by 'i' is '*' then...
			midel_var1 = double(m_Vector_int.at(vector_int_index));
			midel_var2 = double(m_Vector_int.at(vector_int_index + 1));

			if (i >= 1)//...it checks to see if it's the first char in a program or not
			{
				midel_var3 = midel_var1 * midel_var2;//If it is then the 'midel_var3' is the result of a multiplication of an element before and an element after '*'
				midel_var2 = double(m_Vector_int.at(vector_int_index - 1));
				if (m_Vector_char.at(i - 1) == '+')//Checks to see what is the caracter before '*'
				{
					midel_var4 = midel_var2 + midel_var3;
					result += midel_var4;
				}

				if (m_Vector_char.at(i - 1) == '-')
				{
					midel_var4 = midel_var2 - midel_var3;
					result += midel_var4;
				}

				if (m_Vector_char.at(i - 1) == '*')
				{
					midel_var2 = double(m_Vector_int.at(vector_int_index + 1));
					result *= midel_var2;
					
				}

				if (m_Vector_char.at(i - 1) == '/')
				{
					midel_var4 = midel_var2 / midel_var3;
					result += midel_var4;
				}
			}
			else
			{
				result = midel_var1 * midel_var2;
			}
			
			break;

		case '/':
			midel_var1 = double(m_Vector_int.at(vector_int_index));
			midel_var2 = double(m_Vector_int.at(vector_int_index + 1));
			if (i == 0)
			{
				result = midel_var1 / midel_var2;
			}
			else
				result /= midel_var2;
			break;

		default:
			std::cout << "Error\nInvalid sign!\nPlease restart the program and try again!";
			break;
		}
		vector_int_index++;
		
	}

	return result;
}
void Class::output()
{
	std::cout << "Numbers: ";
	for (int i = 0; i < m_Vector_int.size(); i++)
	{
		std::cout << m_Vector_int.at(i) << " ";
	}
	std::cout << "\n";
	std::cout << "Calculation: " << calculate();
}