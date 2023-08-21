#include <bits/stdc++.h>
using namespace std;
#define N 1000
int top = -1, Stack[N];
void push(int data)
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
        cout << "UnderFlow" << endl;
        return;
    }
    top--;
}
bool empty()
{
    if (top == -1)
        return true;
    else
        false;
}
int Top()
{
    if (top == -1)
    {
        cout << "The Stack is empty(-1)!!";
        return -1;
    }
    return Stack[top];
}
void postFixEvaluation(string s)  
{
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
            push(s[i] - 48);
        else
        {
            int a = Top(), result;   
            pop();
            int b = Top();
            pop();
            if (s[i] == '/')
                result = b / a;
            else if (s[i] == '+')
                result = b + a;
            else if (s[i] == '-')
                result = b - a;
            else if (s[i] == '*')
                result = b * a;
            else
                result = pow(b, a);

            push(result);
        }
    }
    int result = Top();
    cout << "\nThe value of PostFixEvaluation is : " << result << endl;
}
int main()
{
    string s = "231*+9-";

    postFixEvaluation(s);
}