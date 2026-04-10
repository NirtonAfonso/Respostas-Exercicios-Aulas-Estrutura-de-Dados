/*
3 Análise de Texto:

Escreva um programa que leia uma string usando 'fgets'. Percorra a string para contar e exibir

o número de vogais e consoantes, ignorando acentos e diferenciando maiúsculas/minúsculas.
*/

#include <stdio.h>

int main() {
    char texto[100];
    int vogais = 0;
    int consoantes = 0;

    printf("Digite uma frase (sem acentos): ");
    // fgets lê a string com espaços, limitando a 100 caracteres
    fgets(texto, 100, stdin);

    // Percorremos a string até encontrar o caractere '\0' (que indica o fim do texto)
    for (int i = 0; texto[i] != '\0'; i++) {
        char letra = texto[i];

        // 1. Verificamos se é uma vogal (maiúscula ou minúscula)
        if (letra == 'a' || letra == 'e' || letra == 'i' || letra == 'o' || letra == 'u' ||
            letra == 'A' || letra == 'E' || letra == 'I' || letra == 'O' || letra == 'U') {
            vogais++;
        } 
        // 2. Se não for vogal, verificamos se é uma letra do alfabeto (para ignorar espaços e pontuação)
        else if ((letra >= 'a' && letra <= 'z') || (letra >= 'A' && letra <= 'Z')) {
            consoantes++;
        }
    }

    printf("\n--- Analise do Texto ---\n");
    printf("Total de vogais: %d\n", vogais);
    printf("Total de consoantes: %d\n", consoantes);

    return 0;
}