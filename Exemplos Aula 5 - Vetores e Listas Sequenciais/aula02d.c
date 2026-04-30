#include <stdio.h> // Inclui as funções de entrada e saída (I/O) nativas da linguagem C

// Protótipos
void inserir(float v[], float n, int *pos, int max); // Em C, a referência (&) do C++ é substituída por um ponteiro (*) para alterar a variável original

int main(void) { // Ponto de entrada do programa
    float notas[10]; // Cria a estrutura principal: um vetor de ponto flutuante com tamanho 10
    int quantidade; // Controla logicamente quantos elementos válidos existem na lista
    float n; // Armazena temporariamente o valor digitado pelo usuário

    quantidade = 0; // Inicializa a quantidade como zero (lista totalmente vazia)

    printf("Digite valor: "); // Mostra na tela o comando de entrada
    scanf("%f", &n); // Lê um float do console e guarda na variável 'n'
    inserir(notas, n, &quantidade, 10); // Invoca a inserção passando o endereço de memória de 'quantidade' para que ela seja incrementada

    return 0; // Finaliza execução
} // Fim do código principal

// Função que Insere N na posição apontada por POS no vetor V
void inserir(float v[], float n, int *pos, int max) { // Recebe um ponteiro para pos
    if (*pos >= max) printf("ERRO: Lista cheia!\n"); // Verifica se o valor guardado no ponteiro já alcançou a capacidade máxima permitida
    else { // Bloco executado se ainda houver espaço
        v[*pos] = n; // Coloca o valor 'n' no índice atualmente referenciado pelo ponteiro 'pos'
        (*pos)++; // Incrementa o valor de 'pos' (adiciona 1 à quantidade total de elementos registrados)
    } // Fim do else
} // Encerra o escopo da função