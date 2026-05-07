#include <stdio.h> // Inclui a biblioteca padrão de entrada e saída da linguagem C

int main(void) { // Declara a função principal do programa, que retorna um inteiro
    int v[3]; // Declara um vetor de números inteiros chamado 'v' com capacidade para 3 elementos
    int i; // Declara uma variável inteira 'i' que servirá como índice nos laços de repetição

    printf("*** Digite os valores do vetor v...\n"); // Imprime uma mensagem na tela solicitando a entrada de dados
    for (i=0; i<3; i=i+1) { // Inicia um laço de repetição que vai de 0 até 2 (3 iterações)
        printf("Digite valor: "); // Imprime na tela o pedido para que o usuário digite um valor
        scanf("%d", &v[i]); // Lê um número inteiro do teclado e o armazena no endereço de memória da posição 'i' do vetor 'v'
    } // Fim do bloco do laço for de leitura

    printf("*** Duplicando os valores em v...\n"); // Imprime uma mensagem indicando o início do processo de duplicação
    for (i=0; i<3; i=i+1) v[i] = 2 * v[i]; // Percorre o vetor 'v' multiplicando o conteúdo de cada posição por 2

    printf("*** Resultados:\n"); // Imprime uma mensagem indicando que os resultados serão exibidos
    for (i=0; i<3; i=i+1) printf("%d\n", v[i]); // Percorre o vetor do início ao fim imprimindo cada valor seguido de quebra de linha
    
    printf("*** Resultados:\n"); // Imprime novamente a mensagem de resultados
    for (i=2; i>=0; i=i-1) printf("%d\n", v[i]); // Percorre o vetor de trás para frente (de 2 até 0) imprimindo os valores
    
    return 0; // Finaliza a função principal retornando 0, indicando sucesso
} // Fim da função principal