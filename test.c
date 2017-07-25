#include <stdio.h>
#include <stdlib.h>

#include "calc.h"

int main() {
    Pilha * calculadora = (Pilha *) malloc(sizeof(Pilha));

    printf("---Testes de Validacao---\n");
    printf("1. Teste de insercao\n");
    if(calcular(calculadora) == 2) {
        printf(ANSI_COLOR_GREEN "PASS" ANSI_COLOR_RESET "\n");
    }
    else {
        printf(ANSI_COLOR_RED "FAIL" ANSI_COLOR_RESET "\n");
    }

    printf("2. Teste de soma\n");
    if(calcular(calculadora) == 4) {
        printf(ANSI_COLOR_GREEN "PASS" ANSI_COLOR_RESET "\n");
    }
    else {
        printf(ANSI_COLOR_RED "FAIL" ANSI_COLOR_RESET "\n");
    }

    printf("3. Teste de subtracao\n");
    if(calcular(calculadora) == -2) {
        printf(ANSI_COLOR_GREEN "PASS" ANSI_COLOR_RESET "\n");
    }
    else {
        printf(ANSI_COLOR_RED "FAIL" ANSI_COLOR_RESET "\n");
    }

    printf("4. Teste de multiplicacao\n");
    if(calcular(calculadora) == 4.5) {
        printf(ANSI_COLOR_GREEN "PASS" ANSI_COLOR_RESET "\n");
    }
    else {
        printf(ANSI_COLOR_RED "FAIL" ANSI_COLOR_RESET "\n");
    }

    printf("5. Teste de divisao\n");
    if(calcular(calculadora) == 5) {
        printf(ANSI_COLOR_GREEN "PASS" ANSI_COLOR_RESET "\n");
    }
    else {
        printf(ANSI_COLOR_RED "FAIL" ANSI_COLOR_RESET "\n");
    }

    clear(calculadora);

    printf("6. Teste de aritmetica complexo\n");
    if(calcular(calculadora) == 154) {
        printf(ANSI_COLOR_GREEN "PASS" ANSI_COLOR_GREEN "\n");
    }
    else {
        printf(ANSI_COLOR_RED "FAIL" ANSI_COLOR_RESET "\n");
    }

    free(calculadora);

    return 0;
}