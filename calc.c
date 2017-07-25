#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "calc.h"

// Insere elemento no topo da pilha
void push(Pilha * pilha, float elemento) {
    Nodo * novo = (Nodo*) malloc(sizeof(Nodo));
    novo->num = elemento;
    
    novo->prox = pilha->topo;
    pilha->topo = novo;
}

// Remove elemento do topo da pilha, se a pilha nao estiver vazia
void pop(Pilha * pilha) {
    if (!isEmpty(pilha)) {
        Nodo * remover = pilha->topo;
        pilha->topo = remover->prox;
        free(remover);   
    }
}

// Retorna valor do topo da pilha, se a pilha nao estiver vazia
float top(Pilha * pilha) {
    if (isEmpty(pilha))
        return;
    return pilha->topo->num;
}

// Retorna 1 se a pilha estiver vazia, 0 caso contrario
int isEmpty(Pilha * pilha) {
    if (pilha->topo)
        return 0;
    return 1;
}

// Remove todos os elementos da pilha
void clear(Pilha * pilha) {
    while (!isEmpty(pilha)) {
        pop(pilha);
    }
}

// Loop de insercao de valores e calculos
float calcular(Pilha * calculadora) {
    float valor = 0;
    char entrada[256];
    char modo;
    

    while (1) {
        // Parsing da entrada de dados
        fgets(entrada, sizeof(entrada), stdin);
        if (strlen(entrada) == 2) {
            if (entrada[0] >= '0' && entrada[0] <= '9') {
                valor = strtod(entrada, NULL);
                modo = 'n';
            }
            else {
                modo = entrada[0];
            }
        }
        else {
            valor = strtod(entrada, NULL);
            modo = 'n';
        }

        // Execucao da funcao adequada
        switch (modo) {
            case 'n': push(calculadora, valor);
                      break;

            case '+': soma(calculadora);
                      break;
            
            case '-': subtracao(calculadora);
                      break;
            
            case '*': multiplicacao(calculadora);
                      break;
            
            case '/': divisao(calculadora);
                      break;
            
            case '=': return top(calculadora);

            default:  printf("Entrada invalida\n");
        }
    }
}

// Verifica se a calculadora tem elementos o suficiente para realizar determinada operacao
int temArgumentos(Pilha * calculadora) {
    if (calculadora->topo && calculadora->topo->prox)
        return 1;
    return 0;
}

// Verifica se o divisor de uma divisao eh valido, ou seja, se eh diferente de zero
int divisorValido(Pilha * calculadora) {
    if (calculadora->topo->num != 0.0f)
        return 1;
    return 0;
}

// Soma os dois valores no topo da pilha e armazena o resultado no topo da pilha
void soma(Pilha * calculadora) {
    if (temArgumentos(calculadora)) {
        float op1, op2;
        op2 = top(calculadora);
        pop(calculadora);
        op1 = top(calculadora);        
        pop(calculadora);
        push(calculadora, op1 + op2);
    }
}

// Subtrai os dois valores no topo da pilha e armazena o resultado no topo da pilha
void subtracao(Pilha * calculadora) {
    if (temArgumentos(calculadora)) {
        float op1, op2;
        op2 = top(calculadora);
        pop(calculadora);
        op1 = top(calculadora);        
        pop(calculadora);
        push(calculadora, op1 - op2);
    }
}

// Multiplica os dois valores no topo da pilha e armazena o resultado no topo da pilha
void multiplicacao(Pilha * calculadora) {
    if (temArgumentos(calculadora)) {
        float op1, op2;
        op2 = top(calculadora);
        pop(calculadora);
        op1 = top(calculadora);        
        pop(calculadora);
        push(calculadora, op1 * op2);
    }
}

// Divide o segundo elemento na pilha pelo topo e armazena o resultado no topo da pilha
void divisao(Pilha * calculadora) {
    if (temArgumentos(calculadora)) {
        if (divisorValido(calculadora)) {
            float op1, op2;
            op2 = top(calculadora);
            pop(calculadora);
            op1 = top(calculadora);        
            pop(calculadora);
            push(calculadora, op1 / op2);
        }
    }
}