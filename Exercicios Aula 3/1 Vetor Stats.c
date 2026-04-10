/*
1 Vetor Stats:

Crie um programa que leia 10 inteiros do usuário e armazene em um vetor. Em seguida,

calcule e exiba a soma, a média, o maior e o menor valor contido no vetor.
*/

#include <stdio.h>

int main() {
    int numeros[10];
    int soma = 0;
    int maior, menor;
    float media;

    printf("--- Analisador de Numeros ---\n");

    // 1. Preenchendo o vetor com dados do usuário
    for (int i = 0; i < 10; i++) {
        printf("Digite o %dª numero: ", i + 1);
        scanf("%d", &numeros[i]);
        
        // Acumulamos o valor na variável soma
        soma = soma + numeros[i];
    }

    // 2. Inicializamos 'maior' e 'menor' com o PRIMEIRO elemento do vetor
    maior = numeros[0];
    menor = numeros[0];

    // 3. Percorremos do segundo elemento (índice 1) em diante para comparar
    for (int i = 1; i < 10; i++) {
        if (numeros[i] > maior) {
            maior = numeros[i];
        }
        if (numeros[i] < menor) {
            menor = numeros[i];
        }
    }

    // 4. Calculamos a média (forçamos a conversão para float para não perder os decimais)
    media = (float)soma / 10;

    printf("\n--- Resultados ---\n");
    printf("Soma total: %d\n", soma);
    printf("Media: %.2f\n", media);
    printf("Maior valor: %d\n", maior);
    printf("Menor valor: %d\n", menor);

    return 0;
}