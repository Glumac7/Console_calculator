#pragma once

class Class
{
private:
	std::vector<std::string> m_Vector_input;
	std::vector<std::string> m_Vector_splited;

public:

	const std::vector<std::string> Class::getSplit_input(std::string new_string, char new_char);
	void input(std::string str);
	void calculate();
};