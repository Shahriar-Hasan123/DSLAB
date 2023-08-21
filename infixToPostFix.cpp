#include <bits/stdc++.h>
using namespace std;
#define N 1000
char Stack[N];
int top = -1;

void push(char data)
{
    if (top == N - 1)
    {
        cout << "Overflow" << endl;
        return;
    }
    top++;
    Stack[top] = data;
}
void pop()
{
    if (top == -1)
    {
        cout << "Underflow" << endl;
        return;
    }
    top--;
}
bool empty()
{
    if (top == -1)
        return true;
    return false;
}
char Top()
{
    if (top == -1)
    {
        cout << "The Stack is empty(-1)!!";
        return -1;
    }
    return Stack[top];
}
int prec(char c)
{
    if (c == '^')
        return 3;
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return 0;
}
void infixToPostfix(string s)
{
    cout << "\nInfix expression is : " << s << endl;
    string result = "";
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z' || s[i] >= '0' && s[i] <= '9' || s[i] >= 'A' && s[i] <= 'Z')
            result = result + s[i];
        else if (s[i] == '(')
            push(s[i]);
        else if (s[i] == ')')
        {
            while (Top() != '(')
            {
                result = result + Top();
                pop();
            }
            pop();
        }
        else
        {
            while (!empty() && prec(s[i]) <= prec(Top()))
            {
                result = result + Top();
                pop();
            }
            push(s[i]);
        }
    }
    while (!empty())
    {
        result = result + Top();
        pop();
    }
    cout << "\nPostfix expressions is : " << result << endl;
}
int main()
{
    string s = "x^y/(5*z)+2";
    infixToPostfix(s);
}