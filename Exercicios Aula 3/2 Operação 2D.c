/*
2 Operação 2D:

Desenvolva um programa que utilize uma matriz 3x3. Preencha-a com valores do usuário

usando laços aninhados. Após o preenchimento, percorra e imprima apenas os Iementos da

diagonal principal.
*/

#include <stdio.h>

int main() {
    int matriz[3][3];

    printf("--- Preenchendo a Matriz 3x3 ---\n");

    // 1. Laço externo para as LINHAS
    for (int linha = 0; linha < 3; linha++) {
        // 2. Laço interno para as COLUNAS
        for (int coluna = 0; coluna < 3; coluna++) {
            printf("Digite o valor para a posicao [Linha %d][Coluna %d]: ", linha, coluna);
            scanf("%d", &matriz[linha][coluna]);
        }
    }

    printf("\n--- Elementos da Diagonal Principal ---\n");
    
    // 3. Percorrendo a matriz novamente para imprimir a diagonal
    for (int linha = 0; linha < 3; linha++) {
        for (int coluna = 0; coluna < 3; coluna++) {
            // A diagonal principal ocorre sempre que o índice da linha for igual ao da coluna (0,0), (1,1), (2,2)
            if (linha == coluna) {
                printf("%d ", matriz[linha][coluna]);
            }
        }
    }
    printf("\n");

    return 0;
}