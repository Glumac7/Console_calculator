#include "Class.h"


int main()
{
	std::string s;
	char caracter = '_';

	//do
	//{
		Class clas;

		clas.input(s);

		clas.getSplit_input();

		clas.calculate();

		clas.output();

		std::cout << "\nDo you wanna play again(Y / N): ";
		std::cin >> caracter;

	//} while (caracter != 'n' || caracter != 'N');

	std::cin.get();
}