#include<iostream>
#include<stack>
using namespace std;

bool isOperator(char c)
{
	if(c=='+'||c=='-'||c=='*'||c=='/'||c=='^')
		return true;
	return false;
}

int precedence(char c) 
{ 
    if(c == '^') 
    return 3; 
    else if(c == '*' || c == '/') 
    return 2; 
    else if(c == '+' || c == '-') 
    return 1; 
    
	return -1; 
} 

string InfixToPostfix(string infix)
{
	stack<char> s;
	string postfix;
	
	for(int i=0;i<infix.length();i++)
	{
		// Case-1 For Operands
		if((infix[i] >= 'a' && infix[i] <= 'z') ||(infix[i] >= 'A' && infix[i] <= 'Z'))
		{
			postfix+=infix[i];
		}
		
		// Case-2 For Open-Brackets
		else if(infix[i] == '(')
		{
			s.push(infix[i]);
		}
		
		// Case-3 For Close-Bracket
		else if(infix[i] == ')')
		{
			while((s.top()!='(') && (!s.empty()))
			{
				postfix+=s.top();
				s.pop();
			}
			if(s.top()=='(')
			{
				s.pop();
			}
		}
		
		// Case-4 for Operators
		else if(isOperator(infix[i]))
		{
			if(s.empty()) // When Stack is empty
			{
				s.push(infix[i]);
			}
			
			else
			{
				if(precedence(infix[i])>precedence(s.top()))
				{
					s.push(infix[i]);
				}	
				
				else if((precedence(infix[i])==precedence(s.top()))&&(infix[i]=='^')) // Only for ^
				{
					s.push(infix[i]);
				}
				
				else
				{
					while((!s.empty())&& (precedence(infix[i])<=precedence(s.top())))
					{
						postfix+=s.top();
						s.pop();
					}
					s.push(infix[i]);
				}
			}
		}
	}
	while(!s.empty())
	{
		postfix+=s.top();
		s.pop();
	}
	
	return postfix;
}

int main() 
{  

  	string infix_exp, postfix_exp;
  	cout<<"Enter a Infix Expression :";
  	cin>>infix_exp;
  	
	cout<<"INFIX EXPRESSION: "<<infix_exp<<endl;
  	
	postfix_exp = InfixToPostfix( infix_exp);
	cout<<endl<<"POSTFIX EXPRESSION: "<<postfix_exp;
	  
	return 0;
}
