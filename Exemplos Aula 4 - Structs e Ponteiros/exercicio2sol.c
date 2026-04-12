// EXERCICIO 2
// Modifique essse programa para que ele empilhe as
// cartas do baralho e depois desempilhe-as

#include <stdio.h>
#include <string.h>

#define MAX 52

struct carta {
    int valor;
    char naipe[10];
};

int empilhar(struct carta v[], int *topo, struct carta dado);
int desempilhar(struct carta v[], int *topo, struct carta *dado);

int main(void) {
    // Declara um vetor de cartas
    struct carta cartas[MAX];

    struct carta pcartas[MAX];
    int tcartas = -1;
    struct carta temp;

    int i;

    // Cria cartas
    for(i = 0; i < MAX; i++) {
        cartas[i].valor = (i % 13) + 1;
        if (i / 13 < 1) strcpy(cartas[i].naipe, "ouros");
        else if (i / 13 < 2) strcpy(cartas[i].naipe, "paus");
        else if (i / 13 < 3) strcpy(cartas[i].naipe, "copas");
        else strcpy(cartas[i].naipe, "espadas");
    }

    // As cartas são de cartas[0] a cartas[51]
    for (i = 0; i < MAX; i++) {
        empilhar(pcartas, &tcartas, cartas[i]);
    }

    while (desempilhar(pcartas, &tcartas, &temp) == 0) {
        printf("%d %s\n", temp.valor, temp.naipe);
    }

    return 0;
}

// Empilha um valor
int empilhar(struct carta v[], int *topo, struct carta dado) {
    // Se a pilha está cheia... retorna 1
    if (*topo >= MAX - 1) {
        printf("ERRO: Pilha cheia!\n");
        return 1;
    }
    // Se pilha não está cheia, vamos empilhar
    *topo = *topo + 1;
    v[*topo] = dado;
    // Indica que valor foi empilhado
    return 0;
}

// Desempilha um valor
int desempilhar(struct carta v[], int *topo, struct carta *dado) {
    // Se a pilha está vazia... retorna 1
    if (*topo < 0) {
        printf("ERRO: Pilha vazia!\n");
        return 1;
    }
    // Se pilha não está vazia, vamos desempilhar
    *dado = v[*topo];
    *topo = *topo - 1;
    // Indica que valor foi desempilhado
    return 0;
}