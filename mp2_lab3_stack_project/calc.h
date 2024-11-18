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

	int Priority(char a);
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

enum Function
{
	OPENED_BRECKET,
	CLOSED_BRECKET,

	PLUS,
	MINUS,
	MULT,
	DIV,
	DEGREE,

	UN_MINUS,
	SIN,
	COS,
	LOG,
	EXP
};