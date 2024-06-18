#ifndef CALCULADORA_H
#define CALCULADORA_H

#define MAX_SIZE 100

typedef struct {
    double items[MAX_SIZE];
    int top;
} Stack;

void initialize(Stack *s);
int isEmpty(Stack *s);
int isFull(Stack *s);
void push(Stack *s, double value);
double pop(Stack *s);
double evaluatePostfix(char *expression);

#endif 

