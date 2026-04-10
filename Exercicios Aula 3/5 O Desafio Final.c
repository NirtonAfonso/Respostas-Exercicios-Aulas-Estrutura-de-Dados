/*
5 O Desafio Final:

Escreva uma função que receba uma string e verifique se é um palíndromo (lê-se igual de

trás para frente). A função deve retornar 1 para verdadeiro e 0 para falso. Teste com exemplos

como "arara".
*/

#include <stdio.h>
#include <string.h> // Necessário para usar a função strlen()

// Prototipo da função que verifica palíndromo
int eh_palindromo(char palavra[]);

    
int main() {
    char teste1[] = "arara";
    char teste2[] = "sistemas";

    printf("--- Teste de Palindromos ---\n");

    // Testando a primeira palavra
    if (eh_palindromo(teste1) == 1) {
        printf("A palavra '%s' E um palindromo!\n", teste1);
    } else {
        printf("A palavra '%s' NAO e um palindromo.\n", teste1);
    }

    // Testando a segunda palavra
    if (eh_palindromo(teste2) == 1) {
        printf("A palavra '%s' E um palindromo!\n", teste2);
    } else {
        printf("A palavra '%s' NAO e um palindromo.\n", teste2);
    }

    return 0;
}

// Função que verifica palíndromo: retorna 1 (Verdadeiro) ou 0 (Falso)
int eh_palindromo(char palavra[]) {
    // 1. Descobrimos o tamanho da palavra (ex: "arara" tem tamanho 5)
    int tamanho = strlen(palavra); 
    int inicio = 0;
    int fim = tamanho - 1; // O último índice é o tamanho menos 1

    // 2. Comparamos as letras das pontas até chegarmos ao meio da palavra
    while (inicio < fim) {
        // Se as letras das pontas forem diferentes, já sabemos que não é palíndromo
        if (palavra[inicio] != palavra[fim]) {
            return 0; // Falso
        }
        // Movemos os "dedos" para o meio
        inicio++;
        fim--;
    }

    // Se o laço terminar sem encontrar diferenças, é palíndromo!
    return 1; // Verdadeiro
}