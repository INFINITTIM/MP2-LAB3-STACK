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

int TCalc::Priority(Function a)
{
	if (a == DEGREE)
		return 3;
	if (a == MULT || a == DIV)
		return 2;
	if (a == PLUS || a == MINUS)
		return 1;
	return 0;
}

int TCalc::Factorial(int n)
{
	if (n <= 1) return 1;
	return n * Factorial(n - 1);
}

/*
void TCalc::ToPostfix()
{
	postfix = "";
	Stack_with_symbol.clear();
	string infix_time = '(' + infix + ')';
	for (int i = 0; i < infix_time.size(); i++)
	{
		if (infix_time[i] >= '0' && infix_time[i] <= '9' || infix_time[i] == '.')
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
}*/
/*
double TCalc::CalculatorPostfix()
{
	stack_with_numbers.clear();
	for (int i = 0; i < postfix.size(); i++)
	{
		if (postfix[i] >= '0' && postfix[i] <= '9' || postfix[i] == '.')
		{
			size_t idx;
			double tmp = stod(&postfix[i], &idx);
			stack_with_numbers.Push(tmp);
			i += idx - 1;
		}
		if (postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/'|| postfix[i] == '^')
		{
			double second_number = stack_with_numbers.Pop();
			double first_number = stack_with_numbers.Pop();
			double res = 0;
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
}*/

double TCalc::Calculator()
{
	string infix_time = '(' + infix + ')';
	Stack_with_symbol.clear();
	stack_with_numbers.clear();
	string check_string = "";

	double const pi = 3.1415926535;

	for (int i = 0; i < infix_time.size(); i++)
	{
		char tmp = infix_time[i];

		// Обработка функций
		if (tmp >= 'a' && tmp <= 'z')
		{
			check_string += tmp;
			if (check_string == "sin")
			{
				Stack_with_symbol.Push(SIN);
				check_string.clear();
				i++;
			}
			else if (check_string == "cos")
			{
				Stack_with_symbol.Push(COS);
				check_string.clear();
				i++;
			}
			else if (check_string == "exp")
			{
				Stack_with_symbol.Push(EXP);
				check_string.clear();
				i++;
			}
			else if (check_string == "pi")
			{
				stack_with_numbers.Push(pi);
			}
		}

		// Обработка чисел
		if ((tmp >= '0' && tmp <= '9') || tmp == '.')
		{
			size_t idx;
			double num = stod(&infix_time[i], &idx);
			stack_with_numbers.Push(num);
			i += idx - 1; // Увеличиваем индекс на количество прочитанных символов
		}

		// Обработка скобок
		if (tmp == '(')
		{
			if (infix_time[i + 1] == '-' && i + 1 < infix_time.size())
			{
				size_t idx;
				double num = stod(&infix_time[i+1], &idx);
				stack_with_numbers.Push(num);
				i += idx;
			}
			Stack_with_symbol.Push(OPENED_BRECKET);
		}

		// Обработка закрывающей скобки
		if (tmp == ')')
		{
			Function a = Stack_with_symbol.Pop();
			while (a != OPENED_BRECKET && a != SIN && a != COS && a != EXP)
			{
				double second_number = stack_with_numbers.Pop();
				double first_number = stack_with_numbers.Pop();
				double res = 0;

				switch (a)
				{
				case PLUS:
					res = first_number + second_number;
					break;
				case MINUS:
					res = first_number - second_number;
					break;
				case MULT:
					res = first_number * second_number;
					break;
				case DIV:
					res = first_number / second_number;
					break;
				case DEGREE:
					res = pow(first_number, second_number);
					break;
				}
				stack_with_numbers.Push(res);
				a = Stack_with_symbol.Pop();
			}

			// Обработка функций
			if (a == SIN || a == COS || a == EXP)
			{
				double func_number = stack_with_numbers.Pop();
				double func_number_rad = func_number * (pi / 180);
				double ress = 0;

				switch (a)
				{
				case SIN:
					ress = func_number_rad - 
						(pow(func_number_rad, 3) / Factorial(3)) +
						(pow(func_number_rad, 5) / Factorial(5)) -
						(pow(func_number_rad, 7) / Factorial(7)) +
						(pow(func_number_rad, 9) / Factorial(9));
					break;

				case COS:
					ress = 1 - 
						(pow(func_number_rad, 2) / Factorial(2)) +
						(pow(func_number_rad, 4) / Factorial(4)) -
						(pow(func_number_rad, 6) / Factorial(6)) +
						(pow(func_number_rad, 8) / Factorial(8));
					break;

				case EXP:
					ress = 1 + func_number +
						(pow(func_number, 2) / Factorial(2)) +
						(pow(func_number, 3) / Factorial(3)) +
						(pow(func_number, 4) / Factorial(4)) +
						(pow(func_number, 5) / Factorial(5)) +
						(pow(func_number, 6) / Factorial(6)) +
						(pow(func_number, 7) / Factorial(7)) +
						(pow(func_number, 8) / Factorial(8)) +
						(pow(func_number, 9) / Factorial(9)) +
						(pow(func_number, 10) / Factorial(10)) +
						(pow(func_number, 11) / Factorial(11)) +
						(pow(func_number, 12) / Factorial(12)) +
						(pow(func_number, 13) / Factorial(13));
					break;
				}
				stack_with_numbers.Push(ress);
			}
			//continue;
		}

		// Обработка операторов
		if (tmp == '+' || tmp == '-' || tmp == '*' || tmp == '/' || tmp == '^')
		{
			Function op;
			switch (tmp)
			{
			case '+': op = PLUS; break;
			case '-': op = MINUS; break;
			case '*': op = MULT; break;
			case '/': op = DIV; break;
			case '^': op = DEGREE; break;
			}

			while (!Stack_with_symbol.Empty() && Priority(op) <= Priority(Stack_with_symbol.Top()))
			{
				double second_number = stack_with_numbers.Pop();
				double first_number = stack_with_numbers.Pop();
				double res = 0;
				Function a = Stack_with_symbol.Pop();

				switch (a)
				{
				case PLUS:
					res = first_number + second_number;
					break;
				case MINUS:
					res = first_number - second_number;
					break;
				case MULT:
					res = first_number * second_number;
					break;
				case DIV:
					res = first_number / second_number;
					break;
				case DEGREE:
					res = pow(first_number, second_number);
					break;
				}
				stack_with_numbers.Push(res);
			}
			Stack_with_symbol.Push(op);
		}
	}

	double result_with_stack = stack_with_numbers.Pop();
	if (!stack_with_numbers.Empty())
		throw - 1;

	return result_with_stack;
}
