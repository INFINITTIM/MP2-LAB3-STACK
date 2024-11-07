#include "calc.h"
#include "Check.cpp"

TCalc::TCalc()
{
	TStack<double> stack_with_numbers;
	TStack<char> Stack_with_symbol;
}

void TCalc::SetInfix(string str)
{
	infix = str;
}

string TCalc::GetInfix()
{
	return infix;
}

void TCalc::SetPostfix(string str)
{
	postfix = str;
}

string TCalc::GetPostfix()
{
	return postfix;
}

int TCalc::Priority(char a)
{
	if (a == '^')
		return 3;
	if (a == '*' || a == '/')
		return 2;
	if (a == '+' || a == '-')
		return 1;
	return 0;
}

void TCalc::ToPostfix()
{
	/*if (!(Check(infix)))
		cout << "not correct" << endl;*/
	postfix = "";
	Stack_with_symbol.clear();
	string infix_time = '(' + infix + ')';
	for (int i = 0; i < infix_time.size(); i++)
	{
		if (infix_time[i] >= '0' && infix_time[i] <= '9')
			postfix += infix_time[i];
		if (infix_time[i] == '(')
			Stack_with_symbol.Push(infix_time[i]);
		if (infix_time[i] == ')')
		{
			while (Stack_with_symbol.Top() != '(')
			{
				postfix += ' ';
				postfix += Stack_with_symbol.Pop();
			}
			Stack_with_symbol.Pop();
		}
		if (infix_time[i] == '+' || infix_time[i] == '-' || infix_time[i] == '*' || infix_time[i] == '/' || infix_time[i] == '^')
		{
			postfix += ' ';
			while ((Priority(infix_time[i]) <= Priority(Stack_with_symbol.Top())) && (!Stack_with_symbol.Empty()))
			{
				postfix += Stack_with_symbol.Pop();
				postfix += ' ';
			}
			Stack_with_symbol.Push(infix_time[i]);
		}
	}
	//while (!(Stack_with_symbol.Empty()))
	//	postfix += Stack_with_symbol.Pop();
}

double TCalc::CalculatorPostfix()
{
	stack_with_numbers.clear();
	for (int i = 0; i < postfix.size(); i++)
	{
		if (postfix[i] >= '0' && postfix[i] <= '9' || postfix[i] == '.') // проверка что данных элемент число
		{
			//stack_with_numbers.Push(postfix[i] - '0'); // в стек ложим число
			size_t idx;
			double tmp = stod(&postfix[i], &idx);
			stack_with_numbers.Push(tmp);
			i += idx - 1;
		}
		if (postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/'|| postfix[i] == '^')
		{
			double second_number = stack_with_numbers.Pop();
			double first_number = stack_with_numbers.Pop();
			double res;
			switch (postfix[i])
			{
			case'+':
				res = first_number + second_number;
				break;
			case'-':
				res = first_number - second_number;
				break;
			case'*':
				res = first_number * second_number;
				break;
			case'/':
				res = first_number / second_number;
				break;
			case'^':
				res = pow(first_number, second_number);
				break;
			}
			stack_with_numbers.Push(res);
		}
	}
	double result_with_stack = stack_with_numbers.Pop();
	if (!(stack_with_numbers.Empty()))
		throw - 1;
	return result_with_stack;
}

//atoi(char*) реализовать
//double stod(char*) реализовать