#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <malloc.h>

#define MAX_EXPR_SIZE 100
#define MAX_STACK_SIZE 100

typedef enum {
	lparen, rparen, plus, minus, times, divide, mod, eos, operand
} precedence;

void* makeArray();
//void prostfix(void);
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

//static int isp[] = { 0,19,12,12,13,13,13,0 };
//static int icp[] = { 20,19,12,12,13,13,13,0 };

int main(void)
{
	char last[2] = " ";
	
	makeArray();

	scanf("%s", expr);
	strcat(expr, last);

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

//void prostfix(void)
//{
//	char symbol;
//	precedence token;
//	int n = 0;
//	int top = 0;
//	stack[0] = eos;
//	
//	for (token == getToken(&symbol, &n); token != eos; token == getToken(&symbol, &n)) {
//		if (token == operand) {
//			printf("%c", symbol);
//		}
//		else if (token == rparen) {
//			while (stack[top] != lparen) {
//				printToken(pop(&top));
//			}
//			pop(&top);
//		}
//		else {
//			while (isp[stack[top]] >= icp[token]) {
//				printToken(pop(&top));
//			}
//			add(&top, token);
//		}
//	}
//
//	while ((token = pop(&top)) != eos) {
//		printToken(token);
//	}
//
//	printf("\n");
//}

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