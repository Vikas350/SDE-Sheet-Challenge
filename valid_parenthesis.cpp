#include <bits/stdc++.h>
using namespace std;
bool isValidParenthesis(string expression)
{
    // Write your code here.
    stack<char> s;
    char x;
    int n = expression.length();
    for (int i = 0; i < n; i++)
    {
        if (expression[i] == '(' || expression[i] == '{' || expression[i] == '[')
        {
            s.push(expression[i]);
        }
        else
        {
            if (s.size() == 0)
                return false;

            x = s.top();

            if (expression[i] == ')' && x != '(')
                return false;
            else if (expression[i] == '}' && x != '{')
                return false;
            else if (expression[i] == ']' && x != '[')
                return false;

            s.pop();
        }
    }

    return s.empty();
}