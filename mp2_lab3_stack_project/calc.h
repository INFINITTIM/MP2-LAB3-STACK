#pragma once

#include <iostream>
#include "stack.h"
#include "string"

using namespace std;

enum Function
{
	OPENED_BRECKET,
	PLUS,
	MINUS,
	MULT,
	DIV,
	DEGREE,
	SIN,
	COS,
	EXP
};


class TCalc
{
private:
	string infix;
	string postfix;

	TStack<double> stack_with_numbers;
	TStack<Function> Stack_with_symbol;

	int Priority(Function a);
	int Factorial(int number);
public:
	TCalc();

	void SetInfix(string str);
	string GetInfix();

	void SetPostfix(string str);
	string GetPostfix();

	void ToPostfix();

	double CalculatorPostfix();
	double Calculator();
};