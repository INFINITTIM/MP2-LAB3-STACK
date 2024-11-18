#include <iostream>

#include "stack.h"
#include "calc.h"

using namespace std;

int main()
{
	TCalc a;

	string str = "sin(23)*(-1)+34/4*3+234";
	//cout << "1.2 30 + 40.3 5 * + 8 4.453000 3 + * + (right answer)" << endl;
	a.SetInfix(str);
	cout << a.Calculator() << endl;
	//a.ToPostfix();

	//cout << a.GetPostfix() << " (my answer)" << endl;
	//cout << "Calculator answer: " << a.CalculatorPostfix() << endl;
}