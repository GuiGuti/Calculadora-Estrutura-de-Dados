#include <stdio.h>
#include <string.h>
#include "calculadora.h"

int main() {
    char expression[MAX_SIZE];

    printf("Digite a expressao pos-fixa (ou 'sair' para encerrar): ");
    while (fgets(expression, MAX_SIZE, stdin) != NULL) {
        expression[strcspn(expression, "\n")] = 0;

        if (strcmp(expression, "sair") == 0) {
            break;
        }

        double result = evaluatePostfix(expression);
        printf("Resultado: %.2f\n", result);

        printf("Digite a expressao pos-fixa (ou 'sair' para encerrar): ");
    }

    return 0;
}

