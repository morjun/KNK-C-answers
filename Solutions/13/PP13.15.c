//
// Created by JediMasterJune on 21. 6. 8..
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../15/PP15.5/stack.h"


#define STACK_SIZE 100
#define N 100

typedef int stk;

bool isEmpty(stk stack[], int* topP);
bool isFull(stk stack[], int* topP);
void makeEmpty(int* topP);
void push(stk stack[], int* topP, stk num);
stk pop(stk stack[], int* topP);
int calculateRPN(const char* expression, stk stack[], int* topP);
void stackUnderflow(void);
void stackOverflow(void);

int main(void)
{
    stk numStack[STACK_SIZE] = {0};
    //char parenthesesCheck[STACK_SIZE] = {0};
    char expression[N + 1];
    
    int top = 0;
    int* topP = &top;
    int result;
    
    for (;;) {
        printf("Enter an RPN expression: ");
        gets(expression);
        result = calculateRPN(expression, numStack, topP);
        printf("Value of expression: %d\n", result);
    }
    
    return 0;
}

int calculateRPN(const char* expression, stk stack[], int* topP)
{
    makeEmpty(topP);
    int num1, num2;
    int result;
    //char ch;
    
    while (*expression != '=' && *expression != '\0') {
        if ('0' <= *expression && *expression <= '9') {
            push(stack, topP, *expression - '0');
        }
        else {
            switch (*expression) {
                case '+':
                    num2 = pop(stack, topP);
                    num1 = pop(stack, topP);
                    result = num1 + num2;
                    push(stack, topP, result);
                    break;
                case '-':
                    num2 = pop(stack, topP);
                    num1 = pop(stack, topP);
                    result = num1 - num2;
                    push(stack, topP, result);
                    break;
                case '/':
                    num2 = pop(stack, topP);
                    num1 = pop(stack, topP);
                    result = num1 / num2;
                    push(stack, topP, result);
                    break;
                case '*':
                    num2 = pop(stack, topP);
                    num1 = pop(stack, topP);
                    result = num1 * num2;
                    push(stack, topP, result);
                    break;
                default:
                    if (*expression != '\0' && *expression != ' ')
                        exit(EXIT_SUCCESS);
            }
        }
        expression++;
    }
    return result;
}

void stackUnderflow(void)
{
    printf("Stack Underflow~!\n");
    exit(EXIT_FAILURE);
}

void stackOverflow(void)
{
    printf("Stack Overflow~!\n");
    exit(EXIT_FAILURE);
}

void push(struct node* stk, stk num)
{

}

void makeEmpty(int* topP)
{
    *(topP) = 0;
}

bool isEmpty(stk stack[], int* topP)
{
    return (*topP == 0);
}

bool isFull(stk stack[], int* topP)
{
    return (*topP == STACK_SIZE - 1);
}

void push(stk stack[], int* topP, stk num)
{
    if (!isFull(stack, topP)) {
        stack[(*topP)++] = num;
    }
    else {
        stackOverflow();
    }
}

stk pop(stk stack[], int* topP)
{
    if (!isEmpty(stack, topP)) {
        /*
        char temp = stack[*topP];
        stack[(*topP)--] = 0;
        return temp;
         */ // 실제로 배열을 비우지 않아도 된다.
        return stack[--(*topP)]; //StackPointer를 1 감소시킨 후에 리턴
    }
    else {
        stackUnderflow();
    }
}
