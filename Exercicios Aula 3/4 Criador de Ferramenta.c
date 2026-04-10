/*
4 Criador de Ferramenta:

Implemente a função `int maior(int a, int b)` que retorna o maior entre dois inteiros.

Crie um "main" para testar a função com diferentes valores e exibir o resultado.
*/

#include <stdio.h>

// 1. Protótipo da função ANTES do main
int maior(int a, int b);

int main() {
    int num1, num2, resultado;

    printf("Digite o primeiro numero: ");
    scanf("%d", &num1);

    printf("Digite o segundo numero: ");
    scanf("%d", &num2);

    // 2. Chamando (usando) a ferramenta que criamos
    resultado = maior(num1, num2);

    printf("O maior numero entre %d e %d e: %d\n", num1, num2, resultado);

    return 0;
}

// 3. Implementação da função
// Ela promete devolver um 'int' e pede dois ingredientes 'int a' e 'int b'
int maior(int a, int b) {
    if (a > b) {
        return a; // Devolve o 'a' e encerra a função
    } else {
        return b; // Devolve o 'b' e encerra a função
    }
}