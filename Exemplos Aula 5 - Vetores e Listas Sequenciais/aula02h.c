#include <stdio.h> // Inclui a biblioteca de entrada e saída padrão do C (substitui iostream)

// Protótipos
void inserir(float v[], float n, int *pos, int max); // Substitui a referência (&) por ponteiro (*) para poder alterar a variável original no C
void listar(float v[], int quantidade); // Mantém passagem por valor, pois apenas faz leitura dos dados
int buscar(float v[], int quantidade, int n); // Declaração da função de busca (mesmo sem ser usada na main neste trecho)

// Programa Principal
int main(void) { // Início da função principal
    // Declaração da lista de notas
    float notas[10]; // Declara um vetor estático de 10 posições para armazenar valores reais
    int quantidade; // Variável que controlará o número de elementos válidos no vetor
    // Valor a ser lido
    float n; // Variável auxiliar para receber os valores digitados pelo usuário

    // Inicializa a Lista: contém, inicialmente, zero elementos
    quantidade = 0; // Define o estado inicial da lista como vazia

    // Leitura de N dado
    do { // Inicia um loop que executará pelo menos uma vez
        printf("Digite valor: "); // Imprime na tela a solicitação de entrada de dados
        scanf("%f", &n); // Lê um número real (float) do teclado e guarda na variável 'n'
        if (n != 0) inserir(notas, n, &quantidade, 10); // Se o valor não for zero, chama a função de inserir passando o endereço da variável 'quantidade'
    } while(n != 0); // O loop continua executando até que o usuário digite o sentinela 0

    // Imprime vetor
    listar(notas, quantidade); // Chama a função para exibir todos os valores válidos que foram inseridos no vetor

    return 0; // Encerra a função principal com código de sucesso
} // Fim da função main

// Função que Insere N na posição apontada por POS do vetor V
void inserir(float v[], float n, int *pos, int max) { // O parâmetro 'pos' agora é um ponteiro para um inteiro
    if (*pos >= max) printf("ERRO: Lista cheia!\n"); // Verifica se o valor apontado por 'pos' atingiu o limite máximo do vetor
    else { // Caso haja espaço livre
        v[*pos] = n; // Armazena o valor 'n' na posição atual indicada pelo conteúdo do ponteiro 'pos'
        (*pos)++; // Incrementa o valor numérico armazenado na variável original (aumenta o tamanho da lista em 1)
    } // Fim do else
} // Fim da função inserir

// Função que imprime os valores de um vetor
void listar(float v[], int quantidade) { // Recebe o vetor e a quantidade de elementos efetivamente preenchidos
    int i; // Declara a variável iteradora
    for (i=0; i<quantidade; i++) { // Percorre o vetor do índice 0 até o último item válido
        printf("%f\n", v[i]); // Imprime o valor float na tela seguido de uma quebra de linha (substitui cout e endl)
    } // Fim do loop for
} // Fim da função listar

// Função que busca um valor N dentro do vetor V
int buscar(float v[], int quantidade, int n) { // Recebe o array, a quantidade válida e o inteiro de busca
    int i; // Declara a variável de controle do loop
    for (i=0; i<quantidade; i++) { // Faz uma busca sequencial verificando cada elemento válido
        if (v[i] == n) return i; // Se o valor da posição atual for igual ao procurado, retorna imediatamente este índice
    } // Fim da varredura
    return -1; // Se o loop terminar sem retornos, significa que o valor não existe, então devolve -1 (código de erro padrão)
} // Fim da função buscar