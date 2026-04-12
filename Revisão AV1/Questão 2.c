#include <stdio.h>

int main(void) {
    // Passo 1: O enunciado nos dá a declaração inicial das variáveis e ponteiros.
    int a = 5, b = 15;
    int *p1, *p2;

    // Conectando os ponteiros às variáveis originais.
    p1 = &a;
    p2 = &b;

    // Passo 2: A exigência é alterar 'a' e 'b' SEM tocar diretamente nelas.
    // Usamos o operador de desreferência '*' para acessar a casa de memória
    // apontada por p1 e p2 e sobrescrever os valores antigos.
    *p1 = 100; // Vai até a memória de 'a' e coloca 100 lá dentro.
    *p2 = 200; // Vai até a memória de 'b' e coloca 200 lá dentro.

    // Passo 3: Comprovação. Imprimimos as variáveis originais para os alunos
    // verem que a alteração indireta realmente funcionou.
    printf("Apos a alteracao indireta:\n");
    printf("Valor de a: %d\n", a);
    printf("Valor de b: %d\n", b);

    return 0;
}