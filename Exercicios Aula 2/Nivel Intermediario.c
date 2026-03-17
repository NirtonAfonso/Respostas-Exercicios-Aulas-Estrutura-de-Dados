/*
Nível Intermediário

Somador Infinito: Use um laço while para ler números inteiros do teclado e somá-los. O programa deve parar e imprimir o total apenas quando o usuário digitar o valor 0.
*/

#include <stdio.h>

int main() {
    // 1. Iniciamos o número com um valor diferente de zero para garantir que o laço comece
    int numero_digitado = -1; 
    
    // 2. A soma PRECISA começar em 0, pois será o nosso acumulador e não queremos que pegue lixo na memória
    int soma_total = 0;

    // 3. O laço repete ENQUANTO o usuário não digitar 0
    while (numero_digitado != 0) {
        printf("Digite um numero para somar: ");
        scanf("%d", &numero_digitado);

        // 4. Pegamos o valor atual da soma e adicionamos o novo número digitado
        // (Se o usuário digitar 0, ele vai somar 0, o que não altera o resultado final)
        soma_total = soma_total + numero_digitado;
	// ou pode calcular com
	// soma += numero digitado;
    }

    // 5. Quando o laço termina (porque o usuário digitou 0), mostramos o resultado
    printf("\nA soma total dos numeros e: %d\n", soma_total);

    return 0;
}