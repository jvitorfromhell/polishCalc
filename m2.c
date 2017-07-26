// Nao se preocupem com isso
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Estruturas de Dados */

// Nodo da Pilha
struct Nodo {
    struct Nodo * prox;
    float num;
};

typedef struct Nodo Nodo;

// Pilha
struct Pilha {
    Nodo * topo;
};

typedef struct Pilha Pilha;

// Retorna 1 se a pilha estiver vazia, 0 caso contrario
int isEmpty(Pilha * pilha) {
    if (pilha->topo)
        return 0;
    return 1;
}

// Insere elemento no topo da pilha
void push(Pilha * pilha, float elemento) {
    // IMPLEMENTAR AQUI
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
Nodo * top(Pilha * pilha) {
    // IMPLEMENTAR AQUI
}

// Remove todos os elementos da pilha
void clear(Pilha * pilha) {
    while (!isEmpty(pilha)) {
        pop(pilha);
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
        op2 = top(calculadora)->num;
        pop(calculadora);
        op1 = top(calculadora)->num;        
        pop(calculadora);
        push(calculadora, op1 + op2);
    }
}

// Subtrai os dois valores no topo da pilha e armazena o resultado no topo da pilha
void subtracao(Pilha * calculadora) {
    if (temArgumentos(calculadora)) {
        // IMPLEMENTAR AQUI
    }
}

// Multiplica os dois valores no topo da pilha e armazena o resultado no topo da pilha
void multiplicacao(Pilha * calculadora) {
    if (temArgumentos(calculadora)) {
        // IMPLEMENTAR AQUI
    }
}

// Divide o segundo elemento na pilha pelo topo e armazena o resultado no topo da pilha
void divisao(Pilha * calculadora) {
    if (temArgumentos(calculadora)) {
        if (divisorValido(calculadora)) {
            float op1, op2;
            op2 = top(calculadora)->num;
            pop(calculadora);
            op1 = top(calculadora)->num;        
            pop(calculadora);
            push(calculadora, op1 / op2);
        }
    }
}

// Loop de insercao de valores e calculos
Nodo * calcular(Pilha * calculadora) {
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

int main() {
    Pilha * calculadora = (Pilha *) malloc(sizeof(Pilha));

    printf("---Testes de Validacao---\n");
    printf("1. Teste de insercao\n");
    if(calcular(calculadora)->num == 2) {
        printf(ANSI_COLOR_GREEN "PASS" ANSI_COLOR_RESET "\n");
    }
    else {
        printf(ANSI_COLOR_RED "FAIL" ANSI_COLOR_RESET "\n");
    }

    clear(calculadora);

    printf("2. Teste de soma\n");
    if(calcular(calculadora)->num == 4) {
        printf(ANSI_COLOR_GREEN "PASS" ANSI_COLOR_RESET "\n");
    }
    else {
        printf(ANSI_COLOR_RED "FAIL" ANSI_COLOR_RESET "\n");
    }

    clear(calculadora);

    printf("3. Teste de subtracao\n");
    if(calcular(calculadora)->num == -2) {
        printf(ANSI_COLOR_GREEN "PASS" ANSI_COLOR_RESET "\n");
    }
    else {
        printf(ANSI_COLOR_RED "FAIL" ANSI_COLOR_RESET "\n");
    }

    clear(calculadora);

    printf("4. Teste de multiplicacao\n");
    if(calcular(calculadora)->num == 4.5) {
        printf(ANSI_COLOR_GREEN "PASS" ANSI_COLOR_RESET "\n");
    }
    else {
        printf(ANSI_COLOR_RED "FAIL" ANSI_COLOR_RESET "\n");
    }

    clear(calculadora);

    printf("5. Teste de divisao\n");
    if(calcular(calculadora)->num == 5) {
        printf(ANSI_COLOR_GREEN "PASS" ANSI_COLOR_RESET "\n");
    }
    else {
        printf(ANSI_COLOR_RED "FAIL" ANSI_COLOR_RESET "\n");
    }

    clear(calculadora);

    printf("6. Teste de aritmetica complexo\n");
    if(calcular(calculadora)->num == 154) {
        printf(ANSI_COLOR_GREEN "PASS" ANSI_COLOR_RESET "\n");
    }
    else {
        printf(ANSI_COLOR_RED "FAIL" ANSI_COLOR_RESET "\n");
    }

    clear(calculadora);

    printf("7. Teste de nulidade da calculadora\n");
    if(calcular(calculadora) == NULL) {
        printf(ANSI_COLOR_GREEN "PASS" ANSI_COLOR_RESET "\n");
    }
    else {
        printf(ANSI_COLOR_RED "FAIL" ANSI_COLOR_RESET "\n");
    }

    clear(calculadora);

    printf("8. Teste de multiplas operacoes sem argumentos\n");
    if(calcular(calculadora) == NULL) {
        printf(ANSI_COLOR_GREEN "PASS" ANSI_COLOR_RESET "\n");
    }
    else {
        printf(ANSI_COLOR_RED "FAIL" ANSI_COLOR_RESET "\n");
    }

    free(calculadora);

    return 0;
}