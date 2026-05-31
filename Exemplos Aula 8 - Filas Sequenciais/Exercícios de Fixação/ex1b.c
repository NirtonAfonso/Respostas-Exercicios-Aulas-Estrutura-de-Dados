#include <stdio.h> // Inclui a biblioteca padrão de entrada e saída (printf, scanf)

#define MAX 10 // Define o tamanho máximo da fila como 10 posições

// --- PROTÓTIPOS DAS FUNÇÕES BÁSICAS DA FILA ---
int enfileirar(int fila[], int *ffila, int valor); // O fim da fila (*ffila) muda ao enfileirar
int desenfileirar(int fila[], int *ifila, int ffila, int *valor); // O início (*ifila) e o valor mudam ao desenfileirar

// --- PROTÓTIPOS DAS FUNÇÕES DE INTERFACE ---
int menu(void); // Função simples que apenas desenha o menu e devolve a escolha do usuário

// COMO ESSAS FUNÇÕES VÃO REPASSAR DADOS PARA A FILA, ELAS PRECISAM RECEBER PONTEIROS (*)
// 'opcao1' vai inserir, então ela precisa saber o endereço do FIM da fila na memória.
void opcao1(int fila[], int *fim); 

// 'opcao2' vai remover, então ela precisa saber o endereço do INÍCIO e o valor atual do FIM.
void opcao2(int fila[], int *ini, int fim); 

int main(void) {

    // --- DECLARAÇÃO DA FILA ---
    int fila[MAX];  // O vetor que será a fila
    int ifila = 0;  // O início da fila (porta de saída) começa no índice 0
    int ffila = -1; // O fim da fila (porta de entrada) começa em -1 (vazia)
    
    int op; // Variável que vai receber a escolha do menu

    // Laço de repetição do programa principal
    do {
        op = menu(); // Chama a função menu(). O número que o usuário digitar lá, será guardado em 'op' aqui.
        
        if (op == 1) { // Se escolheu 1 (Enfileirar)
            // Chamamos a função opcao1 e passamos o ENDEREÇO da variável ffila usando '&'
            opcao1(fila, &ffila); 
        }
        
        if (op == 2) { // Se escolheu 2 (Desenfileirar)
            // Chamamos a função opcao2 e passamos o ENDEREÇO de ifila (&ifila) e o valor de ffila
            opcao2(fila, &ifila, ffila); 
        }
        
    } while (op != 3); // O programa repete enquanto a opção não for 3 (Sair)
    
    return 0; // Finaliza o programa
}

// --- IMPLEMENTAÇÃO DA OPÇÃO 2 (REMOVER) ---
void opcao2(int fila[], int *ini, int fim) {
    int v; // Variável local para receber o número que sairá da fila
    
    printf("\n--- Retirando da Fila ---\n");
    
    // A GRANDE LIÇÃO DOS PONTEIROS: 
    // A variável 'ini' JÁ CHEGOU AQUI COMO UM PONTEIRO (olhe o *ini no cabeçalho da função).
    // Por isso, ao passá-la para a função desenfileirar, NÃO colocamos o '&' na frente dela! 
    // Ela já é um endereço de memória. A variável 'v', por outro lado, foi criada aqui, então precisa do '&'.
    while( desenfileirar(fila, ini, fim, &v) == 0 ) { // Repete enquanto conseguir tirar itens
        
        if (v % 5 == 0) { // Regra do exercício: só imprime na tela se for múltiplo de 5
            printf("%d\n", v);
        }
    }
}

// --- IMPLEMENTAÇÃO DA OPÇÃO 1 (INSERIR) ---
void opcao1(int fila[], int *fim) {
    int v; // Variável local para receber o número que o usuário vai digitar
    
    printf("Digite um inteiro positivo: ");
    scanf("%d", &v); // Lê o número e guarda em 'v'
    
    // Novamente: a variável 'fim' já é um ponteiro! Nós apenas a repassamos para frente sem o '&'.
    enfileirar(fila, fim, v);
}

// --- IMPLEMENTAÇÃO DO MENU ---
int menu(void) {
    int op; // Variável local para guardar a escolha
    
    printf("\n1. Enfileira\n"); // Desenha opção 1
    printf("2. Desenfileira\n"); // Desenha opção 2
    printf("3. Termina\n"); // Desenha opção 3
    printf("Opcao: "); // Pede a digitação
    
    scanf("%d", &op); // Lê do teclado
    
    return op; // Devolve o número escolhido para a função main
}

// =====================================
// FUNÇÕES MECÂNICAS DA FILA
// =====================================

// Função para colocar na fila
int enfileirar(int fila[], int *ffila, int valor) {
    if (*ffila >= MAX - 1) { // Verifica se a posição atual do fim já bateu no teto do vetor
        printf("ERRO: Fila cheia!\n");
        return 1; // Retorna erro
    }
    
    *ffila = *ffila + 1; // A porta de entrada avança um índice
    fila[*ffila] = valor; // O novo número é colocado nesse novo índice
    
    return 0; // Sucesso
}

// Função para retirar da fila
int desenfileirar(int fila[], int *ifila, int ffila, int *valor) {
    if (ffila < *ifila) { // Verifica se a porta de saída já passou da porta de entrada (vazia)
        return 1; // Retorna erro
    }
    
    *valor = fila[*ifila]; // Copia o número que está na posição de saída para a variável do usuário
    *ifila = *ifila + 1; // A porta de saída avança um índice, "esquecendo" o item anterior
    
    return 0; // Sucesso
}