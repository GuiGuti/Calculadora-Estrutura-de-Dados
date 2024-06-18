#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "calculadora.h"

void initialize(Stack *s) { s->top = -1; }
int isEmpty(Stack *s) { return s->top == -1; }
int isFull(Stack *s) { return s->top == MAX_SIZE - 1; }
void push(Stack *s, double value) {
    if (isFull(s)) {
        printf("Erro: Pilha cheia!\n");
        exit(EXIT_FAILURE);
    }
    s->items[++s->top] = value;
}
double pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Erro: Pilha vazia!\n");
        exit(EXIT_FAILURE);
    }
    return s->items[s->top--];
}

double evaluatePostfix(char *expression) {
    Stack s;
    initialize(&s);
    char *token = strtok(expression, " ");

    while (token != NULL) {
        if (isdigit(*token) || (*token == '-' && isdigit(*(token + 1)))) {
            push(&s, atof(token));
        } else {
            double val2 = pop(&s);
            double val1 = 0;
            if (*token != 'r' && *token != 's' && *token != 'c' && *token != 't' && *token != 'l') {
                val1 = pop(&s);
            }
            switch (*token) {
                case '+': push(&s, val1 + val2); break;
                case '-': push(&s, val1 - val2); break;
                case '*': push(&s, val1 * val2); break;
                case '/': 
                    if (val2 == 0) {
                        printf("Erro: Divisao por zero!\n");
                        exit(EXIT_FAILURE);
                    }
                    push(&s, val1 / val2); 
                    break;
                case '^': push(&s, pow(val1, val2)); break;
                case 'r': push(&s, sqrt(val2)); break;
                case 's': push(&s, sin(val2 * M_PI / 180)); break;
                case 'c': push(&s, cos(val2 * M_PI / 180)); break;
                case 't': push(&s, tan(val2)); break;
                case 'l': push(&s, log10(val2)); break;
                default:
                    printf("Erro: Operador invalido %c\n", *token);
                    exit(EXIT_FAILURE);
            }
        }
        token = strtok(NULL, " ");
    }

    return pop(&s);
}

