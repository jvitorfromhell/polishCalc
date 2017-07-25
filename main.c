#include <stdio.h>
#include <stdlib.h>

#include "calc.h"

int main() {
    Pilha * calculadora = (Pilha *) malloc(sizeof(Pilha));
   
    printf("Resultado: %f\n", calcular(calculadora));

    return 0;
}