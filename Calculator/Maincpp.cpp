#include "Class.h"
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

int main()
{
	std::string s;

	Class clas;

	clas.input(s);

	clas.getSplit_input(s, ' ');

	clas.calculate();

	std::cin.get();
}