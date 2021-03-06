#include "Class.h"

//-----------------------------INPUT-----------------------------
void Class::input(std::string str)
{
	std::cout << "Enter numbers with signs and spaces inbetween them (2 + 2): ";

	std::getline(std::cin, str);
	
	m_String_input = str + " ";
}

//-----------------------------SPLIT_INPUT-----------------------------
void Class::getSplit_input()
{
	int  str_to_int = 0;
	int	multiplier = 1;
	int end_value = 0;
	int middle_value = 1, first_num = 0;
	bool flag;
	std::string str;

	first_num = std::stoi(m_String_input); //Gets the very first colection of numbers
	m_Vector_int.push_back(first_num); //And puts them in a std::vector<int>

	for (int i = 0; i < m_String_input.size(); i++) //While we don't get to the end
	{
		if ((m_String_input.at(i) == '+' || m_String_input.at(i) == '-' || m_String_input.at(i) == '*' ||
			m_String_input.at(i) == '/') && m_String_input.at(i + 1) == ' ')
		{

			int j = i + 2;
			while (m_String_input.at(j) != ' ') //'345' goes from 3 to the space after 5
			{
				j++;
			}

			j -= 1; //Eliminatess the space

			flag = false;
			while (j != (i + 1))  // Goes from 5 to 3 and does some calculations
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
					middle_value = str_to_int;
					multiplier *= 10;
					middle_value *= multiplier;
					end_value += middle_value;
				}
				j--;
			}

			m_Vector_int.push_back(end_value); //Pushes the end_value
			m_Vector_char.push_back(m_String_input.at(i)); //Pushes the sign(+, -, *, /)

			//Resets the values
			end_value = 0;
			middle_value = 0;
			multiplier = 1;
			str_to_int = 0;

		}
	}
}

//-----------------------------CALCULATION-----------------------------
double Class::calculate()
{
	double result = 0;
	double middle_var1;
	double middle_var2;
	double middle_var3;
	double middle_var4;
	double middle_var5 = 0;
	double middle_var6 = 0;
	char sign = '_';
	char sign2 = '|';
	int vector_int_index = 0;
	int j;
	bool flag1 = false;
	bool flag2 = false;

	for (int i = 0; i < m_Vector_char.size(); i++) //Goes from the first to the last char in a vector(m_Vecotr_char)
	{
		middle_var1 = double(m_Vector_int.at(vector_int_index));
		j = i;
		switch (m_Vector_char.at(i))
		{
		case '+': //If 'm_Vector_char' that is being incremented by 'i' is '+' then...
			if (m_Vector_char.size() > 1 && i < m_Vector_char.size() - 1)
				if (m_Vector_char.at(i + 1) == '*' || m_Vector_char.at(i + 1) == '/') //...it checks if the next index is '*' or '/'
				{
					flag1 = false;
					flag2 = false;
					break;
				}
					

			middle_var2 = double(m_Vector_int.at(vector_int_index + 1));
			if (i == 0) // If it's not then it check to see if '+' is the first char in the program
			{
				result = middle_var1 + middle_var2; //If it is then the result is the value before, +, the value after '+'
			}
			else
			{
				result += middle_var2;
			}
			break;

		case '-'://Same as the '+' but this time it's '-'
			if (m_Vector_char.size() > 1 && i < m_Vector_char.size() - 1)//It check sto see if '-' is the only sign and if it's not the last sign in the program or not
				if (m_Vector_char.at(i + 1) == '*' || m_Vector_char.at(i + 1) == '/')//If it is then it checks to see if th next sign is '*' or '/'
				{
					flag1 = false;
					flag2 = false;
					break; //It breaks becouse the * and / come before + or -
				}

			middle_var2 = double(m_Vector_int.at(vector_int_index + 1));
			if (i == 0)//If '-' is the first sign in the program...
			{
				result = middle_var1 - middle_var2;
			}
			else
			{
				result -= middle_var2;
			}
			break;

		case '*'://If 'm_Vector_char' that is being incremented by 'i' is '*' then...
			middle_var2 = double(m_Vector_int.at(vector_int_index + 1));
			if (i > 0)//If '*' is not the first sign in the program..
			{
				if (m_Vector_char.at(i - 1) == '/')//If the sign before '*' is '/'...
				{
					middle_var4 = middle_var2;
				}
				else
					middle_var4 = middle_var1 * middle_var2;
			}
			else
				middle_var4 = middle_var1 * middle_var2;

			if (i >= 0 && i < m_Vector_char.size() - 1)//...it checks to see if it's the first char in a program or not
			{
				if (m_Vector_char.at(i + 1) == '*')//If the next sign is '*'...
				{
					while (m_Vector_char.at(j) == '*' && j < m_Vector_char.size() - 1 )//While the sign at j is '*' and it's not the last sign...
					{
						
						if (m_Vector_char.at(j + 1) == '+' || m_Vector_char.at(j + 1) == '-' || m_Vector_char.at(j + 1) == '/')
							break;//If the next sign is not '*' it breaks
						else//It * a number to the left and right of the '*'
						{
							middle_var2 = double(m_Vector_int.at(j + 2));
							middle_var4 *= middle_var2;
						}
						j++;
					}

				}
				
				if (i == 0)//If '*' is the first sign in the program
				{
					result = middle_var4;
				}

				if (i > 0)//If '*' is not the first sign in the program
				{
					if (j < m_Vector_char.size() - 1)//If '*' is not the last sign in the program
					{
						if (m_Vector_char.at(j + 1) != '/')//If the next sign is not '/'
						{
							if (m_Vector_char.at(i - 1) == '+')//If the sign before '*' is '+' result is being added by the *
								result += middle_var4;

							if (m_Vector_char.at(i - 1) == '-')//If the sign before '*' is '-' result is being  by the *
								result -= middle_var4;
						}

						else//If the next sign is not '/' it stores the sign before '*' and middle_var5 with result for further processing
						{
							sign = m_Vector_char.at(i - 1);
							middle_var5 = result;
						}
					}
					
					else
					{
						if (m_Vector_char.at(i - 1) == '+')
							result += middle_var4;

						if (m_Vector_char.at(i - 1) == '-')
							result -= middle_var4;

					}
					
					if (i == 1)//If '*' is the second sign in the program ...
					{
						middle_var2 = double(m_Vector_int.at(vector_int_index - 1));
						if (j < m_Vector_char.size() - 1)//if j is not at the end...
						{
							if (m_Vector_char.at(j + 1) != '/')//If the next sign is not '/'...
							{
								if (m_Vector_char.at(i - 1) == '+')//If the sign before '*' is '+'...
									result = middle_var2 + middle_var4;//The result is the number before '+' and the * after '+'

								if (m_Vector_char.at(i - 1) == '-')//If the sign before '*' is '-'...
									result = middle_var2 - middle_var4;//The result is the number before '-' and the * after '-'

							}
							else//If the next sign is '/'...
							{
								sign = m_Vector_char.at(i - 1);//Puts the sign before '*' into the var sign
								middle_var5 = middle_var2;//Puts the number before '*' into the var middle_var5
							}
						}

						else//If j is at the end...
						{
							if (m_Vector_char.at(i - 1) == '+')
								result = middle_var2 + middle_var4;
							if (m_Vector_char.at(i - 1) == '-')
								result = middle_var2 - middle_var4;
						}
						
					}
				}

				
			}
			else
			{
				if (i == 1)
				{
					middle_var2 = double(m_Vector_int.at(vector_int_index - 1));
					if (j < m_Vector_char.size() - 1)
					{
						if (m_Vector_char.at(j + 1) != '/')
						{
							if (m_Vector_char.at(i - 1) == '+')
							{
								result = middle_var2;
								result += middle_var4;
							}

							if (m_Vector_char.at(i - 1) == '-')
							{
								result = middle_var2;
								result -= middle_var4;
							}
						}

						else
						{
							sign = m_Vector_char.at(i - 1);
							middle_var5 = middle_var2;
						}
					}
					else
					{
						if (m_Vector_char.at(i - 1) == '+')
						{
							result = middle_var2;
							result += middle_var4;
						}

						if (m_Vector_char.at(i - 1) == '-')
						{
							result = middle_var2;
							result -= middle_var4;
						}
					}
				}
				else if (m_Vector_char.size() > 1)
				{
					if (j < m_Vector_char.size() - 1)
					{
						if (m_Vector_char.at(j + 1) != '/')
						{
							if (m_Vector_char.at(i - 1) == '+')
							{
								result += middle_var4;
							}

							if (m_Vector_char.at(i - 1) == '-')
							{
								result -= middle_var4;
							}

							if (m_Vector_char.at(i - 1) == '/')
							{
								middle_var2 = double(m_Vector_int.at(i + 1));
								result *= middle_var2;
							}
						}
						else
						{
							sign = m_Vector_char.at(i - 1);
							middle_var5 = result;
						}
					}
					else
					{
						if (m_Vector_char.at(i - 1) == '+')
						{
							result += middle_var4;
						}

						if (m_Vector_char.at(i - 1) == '-')
						{
							result -= middle_var4;
						}

					}
				}
				else
					result = middle_var4;
			}

			if (i > 0)
			{
				if (m_Vector_char.at(i - 1) == '/')
				{
					if (!flag1)
					{
						result = middle_var3 * middle_var4;
						flag1 = true;
						flag2 = true;
					}
						
					else
						result *= middle_var4;	
				}
			}

			if (sign2 == '+')
			{
				result += middle_var6;
				sign2 = '_';
				middle_var6 = 0;
			}

			if (sign2 == '-')
			{
				result = middle_var6 - result;
				sign2 = '_';
				middle_var6 = 0;
			}

			i = j;
			vector_int_index = i;
			break;

		case '/':
			middle_var2 = double(m_Vector_int.at(vector_int_index + 1));
			if (i > 0)
			{
				if (m_Vector_char.at(i - 1) == '*')
					middle_var3 = middle_var2;
				else
					middle_var3 = middle_var1 / middle_var2;
			}
			else
				middle_var3 = middle_var1 / middle_var2;

		
			if (i >= 0 && i < m_Vector_char.size() - 1)//...it checks to see if it's the first char in a program or not
			{
				if (m_Vector_char.at(i + 1) == '/')
				{
					while (m_Vector_char.at(j) == '/' && j < m_Vector_char.size() - 1)
					{
						if (m_Vector_char.at(j + 1) == '+' || m_Vector_char.at(j + 1) == '-' || m_Vector_char.at(j + 1) == '*')
							break;

						if (i > 0 && m_Vector_char.at(i - 1) == '*')
						{
							middle_var2 = double(m_Vector_int.at(j + 2));
							middle_var3 *= middle_var2;
						}
						else
						{
							middle_var2 = double(m_Vector_int.at(j + 1));
							middle_var3 /= middle_var2;
						}
						
						j++;
					}
				}

				if (i == 0)
				{
					result = middle_var3;
				}

				if (i > 0)
				{
					if (j < m_Vector_char.size() - 1)
					{
						if (m_Vector_char.at(j + 1) != '*')/////////////////////
						{
							if (m_Vector_char.at(i - 1) == '+')
								result += middle_var3;

							if (m_Vector_char.at(i - 1) == '-')
								result -= middle_var3;
						}

						else
						{
							sign2 = m_Vector_char.at(i - 1);
							middle_var6 = result;
						}
					}

					else
					{
						if (m_Vector_char.at(i - 1) == '+')
							result += middle_var3;

						if (m_Vector_char.at(i - 1) == '-')
							result -= middle_var3;
					}
					

					if (i == 1)
					{
						middle_var2 = double(m_Vector_int.at(vector_int_index - 1));
						if (j < m_Vector_char.size() - 1)
						{
							if (m_Vector_char.at(j + 1) != '*')
							{
								if (m_Vector_char.at(i - 1) == '+')
									result = middle_var2 + middle_var3;

								if (m_Vector_char.at(i - 1) == '-')
									result = middle_var2 - middle_var3;

							}
							else
							{
								sign2 = m_Vector_char.at(i - 1);
								middle_var6 = middle_var2;
							}
						}

						else
						{
							if (m_Vector_char.at(i - 1) == '+')
								result = middle_var2 + middle_var3;

							if (m_Vector_char.at(i - 1) == '-')
								result = middle_var2 - middle_var3;
						}
						
					}
				}
			}
			else
			{
				if (i == 1)
				{
					middle_var2 = double(m_Vector_int.at(vector_int_index - 1));
					if (j < m_Vector_char.size() - 1)
					{
						if (m_Vector_char.at(j + 1) != '/')
						{
							if (m_Vector_char.at(i - 1) == '+')
							{
								result = middle_var2;
								result += middle_var3;
							}

							if (m_Vector_char.at(i - 1) == '-')
							{
								result = middle_var2;
								result -= middle_var3;
							}
						}

						else
						{
							sign2 = m_Vector_char.at(i - 1);
							middle_var6 = middle_var2;
						}
					}
					else
					{
						if (m_Vector_char.at(i - 1) == '+')
						{
							result = middle_var2;
							result += middle_var3;
						}

						if (m_Vector_char.at(i - 1) == '-')
						{
							result = middle_var2;
							result -= middle_var3;
						}
					}
					
				}
				else if (m_Vector_char.size() > 1)
				{
					if (j < m_Vector_char.size() - 1)
					{
						if (m_Vector_char.at(j + 1) != '*')
						{
							if (m_Vector_char.at(i - 1) == '+')
							{
								result += middle_var3;
							}

							if (m_Vector_char.at(i - 1) == '-')
							{
								result -= middle_var3;
							}

							if (m_Vector_char.at(i - 1) == '*')
							{
								middle_var2 = double(m_Vector_int.at(i + 1));
								result /= middle_var2;
							}
						}
						else
						{
							sign2 = m_Vector_char.at(i - 1);
							middle_var6 = result;
						}
					}
					else
					{
						if (m_Vector_char.at(i - 1) == '+')
						{
							result += middle_var3;
						}

						if (m_Vector_char.at(i - 1) == '-')
						{
							result -= middle_var3;
						}

					}
					
				}
				else
					result = middle_var3;
			}
			
			if (i > 0)
				if (m_Vector_char.at(i - 1) == '*')
				{
					if (!flag2)
					{
						result = middle_var4 / middle_var3;
						flag1 = true;
						flag2 = true;
					}
						
					else
					{
						result /= middle_var3;
						
					}
					
				}

			if (sign == '+')
			{
				result += middle_var5;
				sign = '_';
				middle_var5 = 0;
			}
				
			if (sign == '-')
			{
				result = middle_var5 - result;
				sign = '_';
				middle_var5 = 0;
			}
			
			i = j;
			vector_int_index = i;

			break;

		default:
			std::cout << "Error\nInvalid sign!\nPlease restart the program and try again!";
			break;
		}
		vector_int_index++;
		
	}

	return result;
}


//-----------------------------OUTPUT-----------------------------
void Class::output()
{
	std::cout << "\n";
	std::cout << "Calculation: " << calculate() << "\n";
}