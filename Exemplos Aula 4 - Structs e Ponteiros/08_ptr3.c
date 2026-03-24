// Ponteiro Nulo: aquele que não indica nenhum endereço de memória

#include <stdio.h>

int main(void) {
    int x = 10;
    int * p;
    int * q;
    int * r;

    p = &x;     // Aponta "p" para o endereço de X
    q = p;      // Faz "q" apontar para o endereço atual de "p"
    *q = 20;    // Modifica o valor do endereço apontado por "q"
    r = NULL;   // Indica que "r" não aponta para nenhum endereço
                // NULL é uma constante pré-definida no C/C++

   // Observe os valores impressos
    printf(" X vale: %d\n", x);
    printf("*P vale: %d\n", *p);
    printf("*Q vale: %d\n", *q);

    // Observe os endereços
    printf("&X vale: %p\n", (void*)&x);
    printf(" P vale: %p\n", (void*)p);
    printf(" Q vale: %p\n", (void*)q);
    printf(" R vale: %p\n", (void*)r);

    // Não tente imprimir o valor de um ponteiro nulo!
    // printf("*R vale: %d\n", *r);

    return 0;
}