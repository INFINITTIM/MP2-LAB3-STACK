/*#include <iostream>

#include "stack.h"

using namespace std;

//���� ����� � �������������� �����, ��������� �������������� ��������� � ��������� ������������ ����������� ������

bool Check(string str) {
    TStack<char>s;
    bool res = true;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == '(') s.Push('(');

        if (str[i] == ')') {
            s.Pop();
            if (s.Empty()) return false;

        }
    }
    if (!s.Empty()) return false;
}*/