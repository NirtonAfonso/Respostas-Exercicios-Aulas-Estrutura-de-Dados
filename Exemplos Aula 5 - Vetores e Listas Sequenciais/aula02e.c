#include <stdio.h> // Permite o uso do printf e scanf em substituição ao cout/cin

// Protótipos
void inserir(float v[], float n, int *pos, int max); // Utilização de ponteiro int *pos para emular a passagem por referência

int main(void) { // Início do fluxo
    float notas[10]; // Declaração da lista estática com 10 posições
    int quantidade; // Variável que gerencia a ocupação atual da lista
    float n; // Elemento a ser manipulado via teclado

    quantidade = 0; // Estado inicial: 0 inserções realizadas

    do { // Inicia estrutura de repetição com teste no final
        printf("Digite valor: "); // Pedido de dado na interface de texto
        scanf("%f", &n); // Extração do float digitado
        if (n != 0) inserir(notas, n, &quantidade, 10); // Condicional garantindo que o número 0 atue apenas como condição de parada e não seja inserido (passando quantidade por ponteiro)
    } while(n != 0); // O loop repete continuamente até o usuário fornecer um valor nulo (0)

    return 0; // Retorno de sucesso ao sistema
} // Fim da main

void inserir(float v[], float n, int *pos, int max) { // Implementação do comportamento de inserção via ponteiro
    if (*pos >= max) printf("ERRO: Lista cheia!\n"); // Controle de overflow: se o índice atual bateu no limite
    else { // Caminho padrão de inserção
        v[*pos] = n; // Atribui 'n' diretamente no vetor na posição livre mais à esquerda
        (*pos)++; // O parêntese é essencial para incrementar o conteúdo da variável apontada (a quantidade), não o endereço do ponteiro
    } // Finalização condicional
} // Finalização da rotina