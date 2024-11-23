#include <iostream>

#include "stack.h"
#include "calc.h"

int main()
{
	TCalc a;

	std::string str = "(sin(23)+24)/4";

	a.SetInfix(str);

	double res;

	try
	{
		res = a.Calculator();

		std::cout << res << std::endl;
	}
	catch (...)
	{
		std::cout << "incorrect";
	}
}