#include <stdio.h> // Importa a biblioteca de entrada e saída padrão (printf, scanf)

void lerDados(int v[], int n); // Declara a função de leitura de dados (void em C)
void dobrarDados(int v[], int n); // Declara a função de duplicação de dados
void imprimirDados(int v[], int n); // Declara a função de exibição de dados

int main(void) { // Função principal
    int v[3], w[4], z[6]; // Declara três vetores de tamanhos diferentes (3, 4 e 6 elementos)

    printf("*** Digite os valores do vetor v...\n"); // Solicita os valores para o vetor v
    lerDados(v,3); // Popula o vetor v com 3 leituras
    printf("*** Digite os valores do vetor w...\n"); // Solicita os valores para o vetor w
    lerDados(w,4); // Popula o vetor w com 4 leituras
    printf("*** Digite os valores do vetor z...\n"); // Solicita os valores para o vetor z
    lerDados(z,6); // Popula o vetor z com 6 leituras

    printf("*** Duplicando os valores em v...\n"); // Informa duplicação no vetor v
    dobrarDados(v,3); // Duplica os 3 elementos de v
    printf("*** Duplicando os valores em w...\n"); // Informa duplicação no vetor w
    dobrarDados(w,4); // Duplica os 4 elementos de w
    printf("*** Duplicando os valores em z...\n"); // Informa duplicação no vetor z
    dobrarDados(z,6); // Duplica os 6 elementos de z

    printf("*** Resultados:\n"); // Imprime o cabeçalho final de resultados
    imprimirDados(v,3); // Lista o vetor v
    imprimirDados(w,4); // Lista o vetor w
    imprimirDados(z,6); // Lista o vetor z
    
    return 0; // Finaliza o programa
} // Fim da main

void lerDados(int v[], int n) { // Lógica da leitura genérica de vetores
    int i; // Variável iteradora
    for (i=0; i<n; i=i+1) { // Percorre 'n' vezes
        printf("Digite valor: "); // Exibe prompt de digitação
        scanf("%d", &v[i]); // Lê o inteiro e grava na respectiva posição
    } // Fim do for
} // Fim de lerDados

void dobrarDados(int v[], int n) { // Lógica de duplicação genérica
    int i; // Variável iteradora
    for (i=0; i<n; i=i+1) v[i] = 2 * v[i]; // Atualiza o vetor com o dobro do valor original
} // Fim de dobrarDados

void imprimirDados(int v[], int n) { // Lógica de impressão genérica
    int i; // Variável iteradora
    for (i=0; i<n; i=i+1) printf("%d\n", v[i]); // Imprime o inteiro lido e quebra a linha
} // Fim de imprimirDados