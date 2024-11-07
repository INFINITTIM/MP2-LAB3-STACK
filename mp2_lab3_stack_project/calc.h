#pragma once

#include <iostream>
#include "stack.h"
#include "string"

using namespace std;

class TCalc
{
private:
	string infix;
	string postfix;

	TStack<double> stack_with_numbers;
	TStack<char> Stack_with_symbol;

	//bool Check(string str);
	int Priority(char a);
public:
	TCalc();

	void SetInfix(string str);
	string GetInfix();

	void SetPostfix(string str);
	string GetPostfix();

	void ToPostfix();

	double CalculatorPostfix();
	double Calculator(); // вычислить выражение за один проход
};
