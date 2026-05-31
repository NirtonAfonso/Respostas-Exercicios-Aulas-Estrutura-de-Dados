#include <stdio.h> // Traz as funções padrão printf e scanf para usarmos

#define MAX 10 // Estabelece 10 como a lotação máxima da nossa fila

// --- PROTÓTIPOS ---
// O '*' (ponteiro) garante que a função possa ir na memória e alterar os índices originais da main
int enfileirar(int fila[], int *ffila, int valor);
int desenfileirar(int fila[], int *ifila, int ffila, int *valor);

int main(void) {
    
    // --- PREPARAÇÃO DA ESTRUTURA ---
    int fila[MAX];  // O vetor que guarda os números enfileirados
    int ifila = 0;  // Variável que marca onde a fila COMEÇA (índice 0)
    int ffila = -1; // Variável que marca onde a fila TERMINA (começa em -1 por estar vazia)

    int valor; // Variável para receber o que o usuário digitar ou o que a fila cuspir de volta

    printf("--- Alimentando a Fila ---\n");
    
    // Laço 'do-while': O programa vai pedir números repetidamente
    do {
        printf("Digite um numero inteiro positivo (0 ou negativo para parar): ");
        scanf("%d", &valor); // Lê o número e guarda na memória de 'valor'
        
        // A nossa regra de parada é o número negativo (ou zero). 
        // Portanto, só mandamos o número para a fila se ele for positivo.
        if (valor > 0) {
            
            // Chama a função e passa o ENDEREÇO da variável ffila usando '&'
            enfileirar(fila, &ffila, valor);
            
        } // Fim do if
        
    } while(valor > 0); // Continua no loop enquanto o número for positivo

    printf("\n--- Esvaziando a Fila (Regra FIFO) ---\n");
    // Lembrem-se: FIFO significa que o PRIMEIRO que você digitou será o PRIMEIRO a aparecer aqui!
    
    // O laço 'while' chama o desenfileirar. 
    // Se a função retornar 0, significa que deu certo e um número foi retirado.
    while(desenfileirar(fila, &ifila, ffila, &valor) == 0) {
        
        // Imprime o número que foi guardado na variável 'valor' lá dentro da função
        printf("%d\n", valor); 
        
    } // Quando a função retornar 1 (fila vazia), o laço while se encerra automaticamente.
    
    return 0; // Finaliza a execução do programa principal
}

// --- COMO A FILA CRESCE ---
int enfileirar(int fila[], int *ffila, int valor) {
    
    // Verifica se a variável de limite (*ffila) chegou no último espaço do vetor
    if (*ffila >= MAX - 1) {
        printf("ERRO: A fila esta cheia!\n");
        return 1; // Falha
    }
    
    // Como tem espaço, a porta de entrada da fila recua uma casa, abrindo a vaga
    *ffila = *ffila + 1;
    
    // A nova casa recebe o número do usuário
    fila[*ffila] = valor;
    
    return 0; // Sucesso
}

// --- COMO A FILA ANDA ---
int desenfileirar(int fila[], int *ifila, int ffila, int *valor) {
    
    // Se a marcação de INÍCIO ultrapassou a marcação de FIM, não há ninguém na fila.
    if (ffila < *ifila) {
        return 1; // Falha (Fila Vazia)
    }
    
    // O ponteiro '*valor' funciona como um balde. 
    // Pegamos a pessoa que está no início da fila e jogamos dentro desse balde para a função main pegar.
    *valor = fila[*ifila];
    
    // A pessoa saiu! Agora o NOVO início da fila é a pessoa que estava logo atrás.
    // Avançamos o índice do início em +1.
    *ifila = *ifila + 1;
    
    return 0; // Sucesso
}