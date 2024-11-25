#include <iostream>
#include <iomanip>

#include "stack.h"
#include "calc.h"

int main()
{
	TCalc a;

	std::string str = "(-1)*(-3)+sin(43)/cos(11)+(exp(2)+(4^3)-3)";

	a.SetInfix(str);

	double res;

	try
	{
		res = a.Calculator();

		std::cout << res << std::endl;

		std::cout << std::fixed << std::setprecision(20) << res << std::endl;
	}
	catch (...)
	{
		std::cout << "incorrect";
	}
}