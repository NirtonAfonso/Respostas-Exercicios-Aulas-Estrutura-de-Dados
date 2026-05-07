#include <stdio.h> // Inclui a biblioteca padrão para funções de I/O em C

void lerDados(int v[], int n); // Protótipo da função lerDados (tipo alterado para void pois não há retorno de valor)
void dobrarDados(int v[], int n); // Protótipo da função dobrarDados (tipo alterado para void)
void imprimirDados(int v[], int n); // Protótipo da função imprimirDados (tipo alterado para void)
void imprimirDadosR(int v[], int n); // Protótipo da função imprimirDadosR (tipo alterado para void)

int main(void) { // Declara a função principal do programa
    int v[3]; // Declara um vetor inteiro 'v' de 3 posições

    printf("*** Digite os valores do vetor v...\n"); // Exibe na tela as instruções para o usuário
    lerDados(v,3); // Chama a função lerDados passando o vetor e o número de elementos (3)

    printf("*** Duplicando os valores em v...\n"); // Informa o processo de cálculo na tela
    dobrarDados(v,3); // Chama a função dobrarDados para multiplicar os elementos por 2

    printf("*** Resultados:\n"); // Informa que o resultado normal será exibido
    imprimirDados(v,3); // Chama a função imprimirDados para exibir os 3 elementos do vetor
    
    printf("*** Resultados:\n"); // Informa que o resultado reverso será exibido
    imprimirDadosR(v,0); // Chama a função imprimirDadosR passando o limite inferior (0) para parada
    
    return 0; // Retorna 0 para finalizar a execução
} // Fim da função principal

void lerDados(int v[], int n) { // Implementação da função que lê 'n' valores e guarda no vetor 'v'
    int i; // Declara o índice do laço
    for (i=0; i<n; i=i+1) { // Inicia o laço de repetição de 0 até n-1
        printf("Digite valor: "); // Solicita a entrada
        scanf("%d", &v[i]); // Captura o valor digitado e salva no vetor
    } // Fim do laço
} // Fim da função lerDados

void dobrarDados(int v[], int n) { // Implementação da função que duplica 'n' valores no vetor 'v'
    int i; // Declara o índice do laço
    for (i=0; i<n; i=i+1) v[i] = 2 * v[i]; // Multiplica cada um dos elementos por 2
} // Fim da função dobrarDados

void imprimirDados(int v[], int n) { // Implementação da função que imprime os elementos do vetor
    int i; // Declara o índice do laço
    for (i=0; i<n; i=i+1) printf("%d\n", v[i]); // Imprime o valor de cada posição saltando uma linha
} // Fim da função imprimirDados

void imprimirDadosR(int v[], int n) { // Implementação da função que imprime de trás para frente
    int i; // Declara o índice do laço
    for (i=2; i>=n; i=i-1) printf("%d\n", v[i]); // Imprime a partir do índice 2 decrementando até o limite 'n'
} // Fim da função imprimirDadosR