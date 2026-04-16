#include <stdio.h>

// Prototipação recomendada
void eleva_ao_quadrado(int *n);

int main(void) {
    int valor = 6;

    printf("Valor original antes da funcao: %d\n", valor);

    // O enunciado exige que a variável original seja alterada.
    // Por isso, passamos o ENDEREÇO de 'valor' (&valor) e não a cópia dele.
    // Isso é o que chamamos de "Passagem por Referência".
    eleva_ao_quadrado(&valor);

    // Se o código funcionar, o 'valor' original agora será 36.
    printf("Valor apos a funcao: %d\n", valor);

    return 0;
}

// Implementação: A função recebe um ponteiro (um endereço)
void eleva_ao_quadrado(int *n) {
    // Multiplicamos o "conteúdo apontado por n" por ele mesmo.
    // Em seguida, usamos o sinal de atribuição '=' para jogar esse resultado
    // de volta no MESMO endereço de memória original.
    *n = (*n) * (*n);
}