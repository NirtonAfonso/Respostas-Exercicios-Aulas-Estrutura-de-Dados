#include <stdio.h>

// A questão exige retornar um ENDEREÇO.
// Portanto, o tipo de retorno da função não é 'int', mas sim 'int *' (ponteiro para int).
int* maior_valor(int *p1, int *p2);

int main(void) {
    int a = 42, b = 89;

    // Este é o terceiro ponteiro mencionado na questão.
    // Ele servirá apenas para receber o endereço que a função vai cuspir de volta.
    int *maior;

    // Chamamos a função passando os endereços de 'a' e 'b'.
    // O retorno (que é um endereço) é guardado no ponteiro 'maior'.
    maior = maior_valor(&a, &b);

    // Para imprimir o resultado, acessamos o conteúdo do ponteiro retornado.
    printf("O maior valor entre %d e %d eh: %d\n", a, b, *maior);

    return 0;
}

int* maior_valor(int *p1, int *p2) {
    // Comparamos os CONTEÚDOS apontados por p1 e p2.
    if (*p1 > *p2) {
        // Se p1 apontar para o maior valor, retornamos O PONTEIRO p1
        // (que contém o endereço), e não o valor (*p1).
        return p1;
    } else {
        // Caso contrário, retornamos o ponteiro p2.
        return p2;
    }
}