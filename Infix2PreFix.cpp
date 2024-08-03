#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

bool isOperator(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^') 
        return true;
    return false;
}

int precedence(char c)
{
    if (c == '^') return 3;
    else if (c == '*' || c == '/') return 2;
    else if (c == '+' || c == '-') return 1;
    else return -1;
}

string InfixToPrefix(string infix)
{
	stack<char> s;
    string prefix;
    
    // reversing the string
    reverse(infix.begin(), infix.end());

	// Converting ( -> ) & ) -> (
    for (int i = 0; i < infix.length(); i++)
	{
        if (infix[i] == '(')
            infix[i] = ')';
        else if (infix[i] == ')') 
            infix[i] = '(';
    }
    
    for (int i = 0; i < infix.length(); i++) 
	{
		// Case-1 For Operands
        if ((infix[i] >= 'a' && infix[i] <= 'z') || (infix[i] >= 'A' && infix[i] <= 'Z')) 
		{
            prefix += infix[i];
        }
        
        // Case-2 For Open-Brackets
		else if (infix[i] == '(') 
		{
            s.push(infix[i]);
        }
        
        // Case-3 For Close-Bracket
		else if (infix[i] == ')') 
		{
            while ((s.top() != '(') && (!s.empty())) 
			{
                prefix += s.top();
                s.pop();
            }

            if (s.top() == '(') 
			{
                s.pop();
            }
        }
        
        // Case-4 for Operators
        else if (isOperator(infix[i])) 
		{
            if (s.empty()) // When Stack is empty
			{
                s.push(infix[i]);
            }
            
			else 
			{
                if (precedence(infix[i]) > precedence(s.top())) 
				{
                    s.push(infix[i]);
                }
                
				else if((precedence(infix[i]) == precedence(s.top())) && (infix[i] == '^')) // Only for ^
				{
                    while ((precedence(infix[i]) == precedence(s.top())) && (infix[i] == '^'))
					{
                        prefix += s.top();
                        s.pop();
                    }
                    s.push(infix[i]);
                }
                
				else if (precedence(infix[i]) == precedence(s.top())) 
				{
                    s.push(infix[i]);
                }
                
				else 
				{
                    while ((!s.empty()) && (precedence(infix[i]) < precedence(s.top())))
					{
                        prefix += s.top();
                        s.pop();
                    }
                    s.push(infix[i]);
                }
            }
        }
    }

    while (!s.empty())
	{
        prefix += s.top();
        s.pop();
    }

	// Again Reversing to Get Final Result
    reverse(prefix.begin(), prefix.end());
    return prefix;
}

int main()
{

    string infix, prefix;
    cout << "Enter a Infix Expression :" << endl;
    cin >> infix;
    cout << "INFIX EXPRESSION: " << infix << endl;
    prefix = InfixToPrefix(infix);
    cout << endl<< "PREFIX EXPRESSION: " << prefix;

    return 0;
}
