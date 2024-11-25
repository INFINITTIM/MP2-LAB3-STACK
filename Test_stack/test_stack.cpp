#include "../mp2_lab3_stack_project/stack.h"
#include "../mp2_lab3_stack_project/calc.h"
#include "../mp2_lab3_stack_project/calc.cpp"

#include "gtest.h"


TEST(TStack, can_create_stack_with_positive_size)
{
  ASSERT_NO_THROW(TStack<int> m(5));
}

TEST(TStack, throws_when_create_stack_with_negative_length)
{
	ASSERT_ANY_THROW(TStack<int> m(-5));
}

TEST(TStack, can_create_copied_stack)
{
	TStack<int> m(5);

	ASSERT_NO_THROW(TStack<int> m1(m));
}

TEST(TStack, copied_stack_is_equal_to_source_one)
{
	TStack<int> m(5);
	TStack<int> m1(m);
	EXPECT_EQ(m, m1);
}

TEST(TStack, can_set_and_get_element)
{
    TStack<int> s(10);
    ASSERT_NO_THROW(s.Push(5));
    EXPECT_EQ(s.Top(), 5);
    EXPECT_EQ(s.Pop(), 5);
}

TEST(TStack, can_delete_element)
{
    TStack<int> s(2);
    s.Push(1);
    s.Push(2);
    ASSERT_NO_THROW(s.Pop());
    EXPECT_EQ(s.Top(), 1);
}

TEST(TStack, can_assign_stack_to_itself)
{
    TStack<int> s(4);
    ASSERT_NO_THROW(s = s);
}

TEST(TStack, can_assign_stacks_of_equal_size)
{
    const int size = 4;
    TStack<int> s1(size), s2(size);
    for (int i = 0; i < size; i++) {
        s1.Push(1);
        s2.Push(2);
    }
    ASSERT_NO_THROW(s1 = s2);
}

TEST(TStack, can_assign_stacks_of_different_size)
{
    const int size1 = 5, size2 = 10;
    TStack<int> s1(size1), s2(size2);
    for (int i = 0; i < size1; i++)
    {
        s1.Push(i);
    }
    ASSERT_NO_THROW(s2 = s1);
    EXPECT_EQ(s2, s1);
}

TEST(TStack, compare_equal_stacks_return_true)
{
    const int size = 10;
    TStack<int> s1(size), s2(size);
    for (int i = 0; i < size; i++) {
        s1.Push(i);
        s2.Push(i);
    }
    EXPECT_EQ(s1 == s2, 1);
}

TEST(TStack, compare_stack_with_itself_return_true)
{
    const int size = 10;
    TStack<int> s1(size);
    EXPECT_EQ(s1 == s1, 1);
}

TEST(TStack, stacks_with_different_size_are_not_equal)
{
    const int size1 = 5, size2 = 10;
    TStack<int> s1(size1), s2(size2);
    for (int i = 0; i < size1; i++) s1.Push(i);
    for (int j = 0; j < size2; j++) s2.Push(j);
    EXPECT_EQ(s1 != s2, 1);
}

TEST(TCalc, add_in_calc)
{
    TCalc a;
    std::string str = "2+2";
    a.SetInfix(str);
    double res = 4;
    double my_res = a.Calculator();
    EXPECT_EQ(res, my_res);
}

TEST(TCalc, sub_in_calc)
{
    TCalc a;
    std::string str = "10-2";
    a.SetInfix(str);
    double res = 8;
    double my_res = a.Calculator();
    EXPECT_EQ(res, my_res);
}


TEST(TCalc, mult_in_calc)
{
    TCalc a;
    std::string str = "2*22";
    a.SetInfix(str);
    double res = 44;
    double my_res = a.Calculator();
    EXPECT_EQ(res, my_res);
}

TEST(TCalc, div_in_calc)
{
    TCalc a;
    std::string str = "4/2";
    a.SetInfix(str);
    double res = 2;
    double my_res = a.Calculator();
    EXPECT_EQ(res, my_res);
}

TEST(TCalc, cant_div_for_none_in_calc)
{
    TCalc a;
    std::string str = "4/0";
    a.SetInfix(str);
    double my_res;
    ASSERT_ANY_THROW(my_res = a.Calculator());
}

TEST(TCalc, degree_in_calc)
{
    TCalc a;
    std::string str = "4^2";
    a.SetInfix(str);
    double res = 16;
    double my_res = a.Calculator();
    EXPECT_EQ(res, my_res);
}

TEST(TCalc, sin_in_calc)
{
    TCalc a;
    std::string str = "sin(23)";
    a.SetInfix(str);
    double res = 0.390731;
    double my_res = a.Calculator();
    EXPECT_EQ(res, my_res);
}

TEST(TCalc, cos_in_calc)
{
    TCalc a;
    std::string str = "cos(23)";
    a.SetInfix(str);
    double res = 0.920505;
    double my_res = a.Calculator();
    EXPECT_EQ(res, my_res);
}


TEST(TCalc, exp_in_calc)
{
    TCalc a;
    std::string str = "exp(2)";
    a.SetInfix(str);
    double res = 7.38906;
    double my_res = a.Calculator();
    EXPECT_EQ(res, my_res);
}


TEST(TCalc, hard_expression_in_calc)
{
    TCalc a;
    std::string str = "3*34/sin(34)+5^(exp(2)+(3+(-3)*45+(34+2)+11*(-1)))";
    a.SetInfix(str);
    double res = 182.40571680975975255024;
    double my_res = a.Calculator();
    EXPECT_EQ(res, my_res);
}

TEST(TCalc, hard_expression_second_in_calc)
{
    TCalc a;
    std::string str = "(-1)*(-3)+sin(43)/cos(11)+(exp(2)+(4^3)-3)";
    a.SetInfix(str);
    double res = 72.08382287836418811366;
    double my_res = a.Calculator();
    EXPECT_EQ(res, my_res);
}
