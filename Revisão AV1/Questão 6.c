#include <stdio.h>

void divisao(int dividendo, int divisor, int *quociente, int *resto);

int main(void) {
    // Variáveis que servirão como "recipientes" para as respostas da função.
    int q, r;

    printf("Realizando a divisao de 17 por 5...\n");

    // Passamos os valores 17 e 5 normalmente por cópia.
    // Mas para o quociente e o resto, passamos os ENDEREÇOS (&q e &r)
    // para que a função escreva a resposta diretamente neles.
    divisao(17, 5, &q, &r);

    printf("\n--> Quociente (resultado inteiro): %d\n", q);
    printf("--> Resto da divisao: %d\n", r);

    return 0;
}

void divisao(int dividendo, int divisor, int *quociente, int *resto) {
    // Proteção matemática (semelhante ao if(N == 0) da struct do seu exemplo):
    // Impede o programa de "quebrar" tentando dividir por zero.
    if (divisor != 0) {
        // Armazena as respostas nos endereços apontados pelos ponteiros.
        *quociente = dividendo / divisor;
        *resto = dividendo % divisor;
    } else {
        printf("Erro fatal: Tentativa de divisao por zero!\n");
    }
}