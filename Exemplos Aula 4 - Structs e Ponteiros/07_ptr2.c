// Compreensão da Definição de Ponteiros
// E os operadores & e *

#include <stdio.h>

int main(void) {

    int x = 10;     // Uma variável inteira inicializada com 10
    int y;          // Uma variável inteira não inicializada
    int * p;        // Um ponteiro para um inteiro

    p = &x;         // Faz "p" apontar para o endereço de "x"
    y = *p;         // Copia o valor apontado por "p" para y

    x = 20;         // Observe que o valor de Y não será modificado!

    // Observe os valores impressos
    printf(" X vale: %d\n", x);
    printf(" Y vale: %d\n", y);
    printf("*P vale: %d\n", *p);

    // Observe os endereços
    printf("&X vale: %p\n", (void*)&x);
    printf("&Y vale: %p\n", (void*)&y);
    printf(" P vale: %p\n", (void*)p);

    return 0;
}