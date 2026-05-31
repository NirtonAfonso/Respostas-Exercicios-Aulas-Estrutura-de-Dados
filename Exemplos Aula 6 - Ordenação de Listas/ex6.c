#include <stdio.h>
#include <stdbool.h>

void listar(float v[], int n);
void inserir(float v[], int *n, int max, float valor);
void bubbleSort(float v[], int n);

int main(void) {
    float notas[50], nota;
    int n = 0;

    // Popula a lista desordenada
    do {
        printf("Digite uma nota (negativo para parar): ");
        scanf("%f", &nota);
        if (nota >= 0) inserir(notas, &n, 50, nota);
    } while (nota >= 0);

    printf("\n--- Lista ORIGINAL (Baguncada) ---\n");
    listar(notas, n);
    
    // Chama a versão mais inteligente e rápida do algoritmo
    bubbleSort(notas, n); 
    
    printf("\n--- Lista ORDENADA (Bubble Sort Otimizado) ---\n");
    listar(notas, n);

    return 0;
}

// --- COMO FUNCIONA O BUBBLE SORT OTIMIZADO ---
// A falha do Bubble Sort clássico é que ele compara o vetor inteiro até o fim todas as vezes.
// Mas pense na lógica da "bolha": na 1ª varredura, o MAIOR número de todos é empurrado até a 
// última casa. Na 2ª varredura, o 2º maior é empurrado até a penúltima casa, e assim por diante.
// Ou seja, o "fundo" do vetor vai ficando ordenado aos poucos, e não precisamos mais checá-lo!
void bubbleSort(float v[], int n) {
    
    int i;
    int fim; // Variável nova! Vai funcionar como um "muro" que se move.
    bool inverteu;
    float temp;

    // Inicialmente, o "muro" fica no último índice válido para comparação.
    fim = n - 1; 
    
    do {
        inverteu = false;
        
        // A OTIMIZAÇÃO ACONTECE AQUI:
        // O laço não vai mais até (n-1) fixamente. Ele vai apenas até onde o "muro" ('fim') permite.
        for (i = 0; i < fim; i++) {
            
            if (v[i] > v[i + 1]) {
                // Rotina de troca (Swap) igual à anterior
                temp = v[i];
                v[i] = v[i + 1];
                v[i + 1] = temp;
                
                inverteu = true;
            }
        }
        
        // O PULO DO GATO:
        // Terminamos uma varredura. Temos 100% de certeza que o maior elemento desse ciclo 
        // já bateu lá no final do vetor e não vai mais sair de lá.
        // Portanto, puxamos o nosso muro uma casa para trás. 
        // Na próxima rodada, o laço fará uma comparação a menos. Isso poupa o processador!
        fim--; 
        
    } while(inverteu); // Repete até não haver mais trocas
}

// (As funções inserir e listar permanecem idênticas ao ex5)
void inserir(float v[], int *n, int max, float valor) {
    if (*n == max) return;
    v[*n] = valor;
    (*n)++;
}

void listar(float v[], int n) {
    int i;
    for (i = 0; i < n; i++) printf("%.2f\n", v[i]);
}