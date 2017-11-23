#include "Class.h"


int main()
{
	std::string s;

	Class clas;

	clas.input(s);

	clas.getSplit_input();

	clas.calculate();

	clas.output();

	std::cin.get();
}