#include <stdio.h>   // Biblioteca padrão para entrada e saída de dados (printf, fgets)
#include <ctype.h>   // Importa a função isalpha(), que descobre se um caractere é letra
#include <string.h>  // Importa a função strcspn(), útil para limpar o 'Enter' da leitura do texto

#define MAX 50 // Define o tamanho máximo para ambas as estruturas (Fila e Pilha)

// --- PROTÓTIPOS DA FILA (A regra é FIFO: O primeiro que entra é o primeiro que sai) ---
int enfileirar(char fila[], int *ffila, char valor);
int desenfileirar(char fila[], int *ifila, int ffila, char *valor);

// --- PROTÓTIPOS DA PILHA (A regra é LIFO: O último que entra é o primeiro que sai) ---
int empilhar(char pilha[], int *tpilha, char valor);
int desempilhar(char pilha[], int *tpilha, char *valor);

int main(void) {
    // --- CRIANDO A FILA ---
    char fila[MAX]; // Vetor para a fila
    int ifila = 0;  // Porta de saída
    int ffila = -1; // Porta de entrada

    // --- CRIANDO A PILHA ---
    char pilha[MAX]; // Vetor para a pilha
    int tpilha = -1; // Topo (única porta de entrada e saída)

    char texto[MAX]; // Vetor de caracteres para guardar a frase que o usuário digitar
    char valor;      // Variável temporária de transporte de caracteres
    int i;           // Contador do laço

    printf("Digite um texto:\n");
    // O fgets lê a linha inteira, não para no primeiro espaço como o scanf faria
    fgets(texto, MAX, stdin);
    // Remove o caractere de quebra de linha '\n' que o fgets captura do teclado
    texto[strcspn(texto, "\n")] = '\0'; 

    // --- 1ª FASE: ALIMENTAR A FILA ---
    // Varremos a frase inteira, letra por letra, até encontrar o aviso de fim de string ('\0')
    for (i = 0; texto[i] != '\0'; i++) {
        enfileirar(fila, &ffila, texto[i]); // Guarda o caractere atual no final da fila
    }

    // --- 2ª FASE: TIRAR DA FILA E JOGAR NA PILHA ---
    // O laço chama a função desenfileirar continuamente. Como a fila mantém a ordem, 
    // os caracteres sairão exatamente na mesma ordem em que foram digitados.
    while(desenfileirar(fila, &ifila, ffila, &valor) == 0) {
        
        // Verifica se o caractere atual é uma letra do alfabeto (ignora espaços, pontos, números)
        if (isalpha(valor) != 0) {
            
            // --- O TRUQUE BINÁRIO DE CONVERSÃO PARA MAIÚSCULA ---
            // Na tabela ASCII, a diferença entre qualquer letra minúscula (ex: 'a'=97) e sua 
            // versão maiúscula (ex: 'A'=65) é sempre exatamente 32. 
            // O número 32 em binário é o "6º bit".
            // Quando fazemos uma operação AND (&) com (255 - 32), nós forçamos esse 6º bit a desligar.
            // O resultado disso é que a letra minúscula vira MAIÚSCULA instantaneamente!
            valor = valor & (255 - 32);
            
            // Agora que é maiúscula, colocamos no topo da PILHA
            empilhar(pilha, &tpilha, valor);

        } else {
            // Se for um espaço ou um sinal de pontuação, não fazemos conta nenhuma.
            // Apenas empilhamos do jeito que está.
            empilhar(pilha, &tpilha, valor);
        }
    }

    // --- 3ª FASE: IMPRIMIR E ESVAZIAR A PILHA ---
    printf("\n--- Resultado (Ordem Invertida) ---\n");
    
    // Aqui a mágica final acontece: Como a PILHA funciona na regra "Último a entrar é o primeiro a sair",
    // a última letra da frase será a primeira a ser impressa na tela!
    while(desempilhar(pilha, &tpilha, &valor) == 0) {
        printf("%c", valor); // Imprime caractere por caractere
    }
    printf("\n"); // Pula uma linha no final por estética
    
    return 0; // Finaliza o programa
}

// =====================================
// FUNÇÕES DA FILA
// =====================================
int enfileirar(char fila[], int *ffila, char valor) {
    if (*ffila >= MAX - 1) return 1; // Se a fila bateu no teto, falha
    *ffila = *ffila + 1; // A fila anda para frente
    fila[*ffila] = valor; // O valor entra no final
    return 0; // Sucesso
}

int desenfileirar(char fila[], int *ifila, int ffila, char *valor) {
    if (ffila < *ifila) return 1; // Se a fila secou, falha
    *valor = fila[*ifila]; // Resgata o primeiro da fila
    *ifila = *ifila + 1; // A fila corta o primeiro, movendo o início para o próximo
    return 0; // Sucesso
}

// =====================================
// FUNÇÕES DA PILHA
// =====================================
int empilhar(char pilha[], int *tpilha, char valor) {
    if (*tpilha >= MAX - 1) return 1; // Se a pilha bateu no teto, falha
    *tpilha = *tpilha + 1; // Sobe o topo (empilha o prato)
    pilha[*tpilha] = valor; // Coloca o valor lá
    return 0; // Sucesso
}

int desempilhar(char pilha[], int *tpilha, char *valor) {
    if (*tpilha < 0) return 1; // Se o topo for negativo, a pilha tá vazia
    *valor = pilha[*tpilha]; // Resgata o valor do topo (tira o prato)
    *tpilha = *tpilha - 1; // Desce o topo
    return 0; // Sucesso
}