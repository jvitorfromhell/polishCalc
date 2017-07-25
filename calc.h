#ifndef calc
#define calc

// Nao se preocupem com isso
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

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

/* Funcoes de acesso a pilha */

// Insere elemento no topo
void push(Pilha * pilha, float elemento);

// Remove elemento no topo
void pop(Pilha * pilha);

// Retorna valor do elemento no topo, sem remover
float top(Pilha * pilha);

// Verifica se a pilha esta vazia
int isEmpty(Pilha * pilha);

// Limpa a pilha
void clear(Pilha * pilha);

/* Funcoes de avaliacao de argumentos para a calculadora */ 

// Loop de calculos que retorna o valor do topo da pilha quando se informa a entrada '='
float calcular(Pilha * calculadora);

// Verifica se a pilha tem argumentos o suficiente para realizar operacao
int temArgumentos(Pilha * calculadora);

// Verifica se o valor do divisor em uma divisao eh valido, ou seja, nao eh zero
int divisorValido(Pilha * calculadora);

/* Funcoes para realizar operacoes */ 

// Soma os dois valores no topo da pilha e armazena o resultado no topo da pilha
void soma(Pilha * calculadora);

// Subtrai os dois valores no topo da pilha e armazena o resultado no topo da pilha
void subtracao(Pilha * calculadora);

// Multiplica os dois valores no topo da pilha e armazena o resultado no topo da pilha
void multiplicacao(Pilha * calculadora);

// Divide o segundo elemento na pilha pelo topo e armazena o resultado no topo da pilha
void divisao(Pilha * calculadora);

#endif