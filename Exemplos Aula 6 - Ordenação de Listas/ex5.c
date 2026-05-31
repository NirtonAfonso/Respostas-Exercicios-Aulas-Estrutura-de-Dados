#include <stdio.h>
// Biblioteca importante inserida no C99. Ela nos permite usar variáveis booleanas 
// (verdadeiro/falso) usando as palavras-chave 'bool', 'true' e 'false'.
#include <stdbool.h> 

void listar(float v[], int n);

// ATENÇÃO: Mudamos a inserção! Agora é uma inserção burra/simples. 
// Ela apenas joga o número no final do vetor, criando uma lista totalmente DESORDENADA.
void inserir(float v[], int *n, int max, float valor); 

// Protótipo do Algoritmo de Ordenação.
// Note que não precisamos do ponteiro (*n) aqui, pois ordenar uma lista
// não muda a quantidade de itens que ela tem, apenas muda a posição deles lá dentro.
void bubbleSort(float v[], int n); 

int main(void) {
    float notas[50], nota;
    int n = 0;

    do {
        printf("Digite uma nota (negativo para parar): ");
        scanf("%f", &nota);
        if (nota >= 0) inserir(notas, &n, 50, nota);
    } while (nota >= 0);

    printf("\n--- Lista ORIGINAL (Baguncada) ---\n");
    listar(notas, n); 
    
    // Chama o algoritmo para consertar a bagunça
    bubbleSort(notas, n); 
    
    printf("\n--- Lista ORDENADA (Apos Bubble Sort) ---\n");
    listar(notas, n); 

    return 0;
}

// --- COMO FUNCIONA O BUBBLE SORT (Método Bolha) ---
// Ele compara vizinhos de dois em dois. Se o da esquerda for maior que o da direita, 
// ele troca os dois de lugar. O efeito prático é que os números maiores "borbulham" 
// para o final do vetor rodada após rodada.
void bubbleSort(float v[], int n) {
    
    int i;
    
    // 'inverteu' é a nossa bandeira (flag) de fiscalização.
    // Ela vai nos dizer se durante uma passagem inteira pelo vetor, alguma troca ocorreu.
    bool inverteu; 
    
    // Variável temporária OBRIGATÓRIA para fazer a troca (Swap) de dois valores 
    // na memória sem que um apague o outro acidentalmente.
    float temp; 

    do { // Inicia uma varredura (passagem) pelo vetor.
        
        inverteu = false; // No começo da rodada, assumimos que a lista já está perfeita (falso para trocas).
        
        // Percorre a lista comparando o item atual (i) com o seu vizinho da frente (i+1).
        // CUIDADO: O laço VAI SÓ ATÉ (n - 1). Por que? Porque se formos até o último item (n),
        // o comando v[i+1] tentaria olhar para fora do vetor, causando um erro de memória!
        for (i = 0; i < n - 1; i++) {
            
            // O vizinho da esquerda é mais pesado (maior) que o da direita?
            if (v[i] > v[i + 1]) { // Se sim, eles estão fora de ordem!
                
                // --- MECÂNICA DE TROCA (SWAP) ---
                temp = v[i];       // 1. Salva o valor do vizinho da esquerda na variável de segurança (temp).
                v[i] = v[i + 1];   // 2. O vizinho da esquerda pode agora ser sobrescrito pelo da direita.
                v[i + 1] = temp;   // 3. O vizinho da direita recebe aquele valor original da esquerda que guardamos.
                
                // Levantamos a bandeira! Avisamos ao laço 'do-while': 
                // "Fizemos pelo menos uma troca. A lista ainda não estava pronta."
                inverteu = true; 
                
            } // Fim do IF
        } // Fim do laço FOR (uma varredura completa)

    // O laço 'do-while' repete tudo de novo SE a bandeira terminar a rodada como 'true'.
    // Quando ele varrer a lista inteira e não fizer nenhuma troca, 'inverteu' continuará 'false',
    // o laço vai quebrar, e saberemos que a lista está 100% ordenada.
    } while(inverteu); 
}

// Inserção simples: joga o dado direto na primeira posição vazia no fim do vetor.
void inserir(float v[], int *n, int max, float valor) {
    if (*n == max) return;
    
    v[*n] = valor; // O valor atual de 'n' serve perfeitamente como índice do primeiro "buraco" livre.
    (*n)++; // Sobe o contador de itens.
}

void listar(float v[], int n) {
    int i;
    for (i = 0; i < n; i++) printf("%.2f\n", v[i]);
}