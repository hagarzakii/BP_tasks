#include <stdio.h>
#include <math.h>
#include "Implementation_level\implementation_level.h"

int isDigit(char c)
{
	return (c >= '0' && c <= '9');
}

int precedent (char op1 , char op2)
{
	if(op1 == '$')
	{
		return 1 ;
	}
	if((op1 == '*') || (op1 == '/'))
	{
		return (op2 != '$');
	}
	if((op1 == '+') || (op2 == '-'))
	{
		return ((op2 != '$') && (op2 != '*') && (op2 != '/'));
	}
	return 0;
}

/*void infixToPostFix (char infix[] , char postFix[])
{
	int i , j;
	char op , c;
	Stack s;
	createStack(&s);
	for(i = 0 , j = 0 ; (c = infix[i]) != '\0' ; i++)
	{
		if(isDigit(c))
		{
			postFix[j++] = c;
		}
		else
		{
			if(!stackEmpty(&s))
			{
				stackTop(&op , &s);
				while(!stackEmpty(&s) && precedent(op , c))
				{
					pop(&op , &s);
					postFix[j++] = op;
					if(!stackEmpty(&s))
					{
						stackTop(&op , &s);
					}
				}
			}
		}
		push(c , &s);
	}
	while(!stackEmpty(&s))
	{
		pop(&op , &s);
		postFix[j++] = op;
	}
	postFix[j] = '\0';
}*/

double oper(char c , double op1 , double op2)
{
	switch(c){
		case '+' : return (op1 + op2);
		case '-' : return (op1 - op2);
		case '*' : return (op1 * op2);
		case '/' : return (op1 / op2);
		case '$' : return (pow(op1 , op2));
	}
	return 0;
}

double evaluatePostFix(char expr[])
{
	int i;
	char c;
	double op1 , op2 , val;
	Stack s;
	createStack(&s);
	for(i = 0 ; (c = expr[i]) != '\0' ; i++)
	{
		if(isDigit(c))
		{
			push((double)(c - '0') , &s);
		}
		else{
			pop(&op2 , &s);
			pop(&op1 , &s);
			val = oper(c , op1 , op2);
			push(val , &s);
		}
	}
	pop(&val , &s);
	return val;
}

void main()
{
	char infix[] = "1+2*3$4/5+6";
	char postFix[80];
	//infixToPostFix(infix , postFix);
	//printf("%s" , postFix);
	
	char expr[]="354*+2$";
	double x;
	x = evaluatePostFix(expr);
	printf("%f" , x);
}