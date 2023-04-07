#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define MAX_EXPR_SIZE 100
#define MAX_STACK_SIZE 100

typedef enum {
	lparen, rparen, plus, minus, times, divide, mod, eos, operand
} precedence;

void* makeArray();
int eval(void);
precedence getToken(char* symbol, int* n);
int pop();
void push(int symbol);

//char expr[MAX_EXPR_SIZE];
//int stack[MAX_STACK_SIZE];
char* expr;
int* stack;
int top;
int n;

int main(void)
{
	makeArray();

	scanf("%[^\n]s", expr);

	printf("%d", eval());

	free(expr);
	free(stack);

	return 0;
}

void* makeArray()
{
	expr = (char*)malloc(sizeof(char) * MAX_EXPR_SIZE);
	stack = (int*)malloc(sizeof(int) * MAX_STACK_SIZE);

	return expr, stack;
}

int eval(void)
{
	precedence token;
	char symbol;
	int op1, op2;
	int n = 0;
	int top = -1;
	token = getToken(&symbol, &n);

	while (token != eos) {
		if (token == operand) {
			push((int)symbol - (int)'0');
		}
		else {
			op2 = pop();
			op1 = pop();
			switch (token) {
			case plus: push(op1 + op2); break;
			case minus: push(op1 - op2); break;
			case times: push(op1 * op2); break;
			case divide: push(op1 / op2); break;
			case mod: push(op1 % op2); break;
			}
		}

		token = getToken(&symbol, &n);
	}

	return pop();
}

precedence getToken(char* symbol, int* n)
{
	*symbol = expr[(*n)++];

	switch (*symbol) {
	case '(': return lparen;
	case ')': return rparen;
	case '+': return plus;
	case '-': return minus;
	case '/': return divide;
	case '*': return times;
	case '%': return mod;
	case ' ': return eos;
	default: return operand;
	}
}

int pop()
{
	return stack[top--];
}

void push(int symbol)
{
	stack[++top] = symbol;
}