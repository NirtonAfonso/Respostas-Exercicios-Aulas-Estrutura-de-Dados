#include <stdio.h>
#include <string.h>

// a) A struct Funcionario funciona como um "molde" que agrupa as três informações 
// exigidas pelo enunciado para representar uma única entidade (um funcionário).
struct Funcionario {
    int codigo;
    char nome[50];
    float salario;
};

// Prototipação: Declaração das assinaturas das funções antes do main.
// Isso avisa ao compilador que essas funções existem e serão detalhadas mais abaixo.
void cadastrarFuncionarios(struct Funcionario vet[], int N);
void imprimirAcimaMedia(struct Funcionario vet[], int N);

int main(void) {
    // b) Criação do vetor com capacidade fixa para 50 elementos, garantindo o limite
    // exigido pela questão. Cada posição desse vetor é uma "ficha" de Funcionario.
    struct Funcionario funcionarios[50];
    int N;
    
    // Laço de validação: O enunciado pede para garantir que N >= 0 e N <= 50.
    // O 'do-while' prende o usuário nesta etapa até que ele digite um número válido,
    // impedindo que o programa tente cadastrar -1 ou 60 funcionários, por exemplo.
    do {
        printf("Quantos funcionarios deseja cadastrar (0 a 50)? ");
        scanf("%d", &N);
    } while (N < 0 || N > 50);
    
    // Se o usuário digitou um N válido e maior que zero, o fluxo segue normalmente.
    if (N > 0) {
        // Passamos o vetor e a quantidade exata N para que as funções trabalhem
        // apenas com a quantidade de dados reais, ignorando as posições vazias (até 50).
        cadastrarFuncionarios(funcionarios, N);
        imprimirAcimaMedia(funcionarios, N);
    } else {
        // Trata o caso logicamente possível de N = 0 (usuário não quis cadastrar ninguém).
        printf("Nenhum funcionario para cadastrar.\n");
    }

    return 0;
}

// c) Implementação: Função responsável por ler e armazenar os dados no vetor.
void cadastrarFuncionarios(struct Funcionario vet[], int N) {
    // O laço 'for' garante que a leitura ocorra exatamente N vezes.
    for (int i = 0; i < N; i++) {
        printf("\n--- Funcionario %d ---\n", i + 1);
        
        printf("Codigo: ");
        scanf("%d", &vet[i].codigo);
        
        // Quando digitamos o código e apertamos 'Enter', o 'Enter' (\n) fica na memória.
        // O getchar() consome esse 'Enter' para que ele não pule a leitura do nome abaixo.
        getchar(); 
        
        printf("Nome: ");
        // O fgets é usado no lugar do scanf para permitir ler nomes com espaços (ex: "Ana Silva").
        fgets(vet[i].nome, 50, stdin);
        
        printf("Salario: R$ ");
        scanf("%f", &vet[i].salario);
    }
}

// d) Implementação: Função responsável por calcular a média e filtrar os resultados.
void imprimirAcimaMedia(struct Funcionario vet[], int N) {
    // Proteção matemática: Se N for 0, saímos da função.
    // Isso impede um erro fatal no programa de tentar dividir um número por zero na média.
    if (N == 0) return; 
    
    float soma = 0.0, media;
    
    // Passo 1: Para encontrar a média, primeiro precisamos do valor total.
    // Este laço percorre os N funcionários somando o salário de cada um na variável 'soma'.
    for (int i = 0; i < N; i++) {
        soma += vet[i].salario;
    }
    
    // Passo 2: O cálculo real da média (Total da soma dividido pela quantidade N).
    media = soma / N;
    printf("\n--> Media salarial da empresa: R$ %.2f\n", media);
    printf("--> Funcionarios ganhando acima da media:\n");
    
    // Passo 3: Agora que sabemos a média, precisamos olhar o vetor inteiro de novo.
    for (int i = 0; i < N; i++) {
        // A condição 'estritamente acima' exigida pelo enunciado é representada pelo sinal '>'.
        // Se o salário do funcionário for maior que a média calculada, seus dados são impressos.
        if (vet[i].salario > media) {
            printf("- %s (Salario: R$ %.2f)\n", vet[i].nome, vet[i].salario);
        }
    }
}