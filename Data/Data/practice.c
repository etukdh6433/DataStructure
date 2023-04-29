//#define _CRT_SECURE_NO_WARNINGS
//
//#include <stdio.h>
//#include <malloc.h>
//
//#define MAX_EXPR_SIZE 100
//#define MAX_STACK_SIZE 100
//
//typedef enum {
//	lparen, rparen, times, divide, mod, plus, minus, eos, operand
//} precedence;
//
//char* expr;
//int* stack;
//int top;
//int n;
//
//void* makeArray()
//{
//	expr = (char*)malloc(sizeof(char) * MAX_EXPR_SIZE);
//	stack = (int*)malloc(sizeof(int) * MAX_STACK_SIZE);
//
//	return expr, stack;
//}
//
//int pop()
//{
//	return stack[top--];
//}
//
//void push(int val)
//{
//	stack[++top] = val;
//}
//
//precedence getToken(char* symbol, int* n)
//{
//	*symbol = expr[(*n)++];
//
//	switch (*symbol) {
//	case '(': return lparen;
//	case ')': return rparen;
//	case '*': return times;
//	case '/': return divide;
//	case '%': return mod;
//	case '+': return plus;
//	case '-': return minus;
//	case ' ': return eos;
//	default: return operand;
//	}
//}
//
//int eval()
//{
//	precedence token;
//	char symbol;
//	int op1, op2;
//	int top = -1;
//	int n = 0;
//
//	token = getToken(&symbol, &n);
//
//	while (token != eos) {
//		if (token == operand) {
//			push((int)token - (int)'0');
//		}
//		else {
//			op2 = pop();
//			op1 = pop();
//
//			switch (token) {
//			case times: push(op2 * op1); break;
//			case divide: push(op2 / op1); break;
//			case mod: push(op2 % op1); break;
//			case plus: push(op2 + op1); break;
//			case minus: push(op2 - op1); break;
//			}
//		}
//
//		token = getToken(&symbol, &n);
//	}
//
//	return pop();
//}
//
//int main(void)
//{
//	makeArray();
//
//	scanf("%[^\n]s", expr);
//
//	printf("%d", eval());
//
//	free(expr);
//	free(stack);
//
//	return 0;
//}