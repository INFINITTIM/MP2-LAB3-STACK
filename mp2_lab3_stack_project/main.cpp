#include <iostream>

#include "stack.h"
#include "calc.h"

using namespace std;

int main()
{
	TCalc a;

	string str = "(4+30)+40*5+8*(4000+3)";
	//34 + 200 + 8 * 4003 = 234 + 32024 = 32258
	//4 3 + 4 5 * + 8 4 3 + * +

	a.SetInfix(str);
	a.ToPostfix();

	cout << a.GetPostfix() << " (my answer)" << endl;
	cout << "4 30 + 40 5 * + 8 4000 3 + * + (right answer)" << endl;
	cout << "Calculator answer: " << a.CalculatorPostfix() << endl;
}