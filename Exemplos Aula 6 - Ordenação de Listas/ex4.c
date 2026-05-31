#include <stdio.h>

void listar(float v[], int n);
void inserirCresc(float v[], int *n, int max, float valor);
int buscaBinaria(float v[], int n, float valor);

// Protótipo da remoção. 
// Assim como a inserção, a remoção altera a quantidade total de itens (vai diminuir).
// Portanto, é obrigatório passar o ponteiro 'int *n' para modificarmos a variável original.
void remover(float v[], int *n, float valor); 

int main(void) {
    float notas[50], nota;
    int n = 0;
    int pos;

    // Popula a lista (já nasce ordenada)
    do {
        printf("Digite uma nota para INSERIR (negativo para parar): ");
        scanf("%f", &nota);
        if (nota >= 0) inserirCresc(notas, &n, 50, nota);
    } while (nota >= 0);

    printf("\n--- Lista Atual ---\n");
    listar(notas, n);

    // --- NOVA FUNCIONALIDADE: REMOÇÃO ---
    printf("\nDigite uma nota para REMOVER: ");
    scanf("%f", &nota);
    
    // Chama a função de remover mandando o vetor, o endereço de n, e a nota a ser apagada.
    remover(notas, &n, nota);
    
    printf("\n--- Lista Apos a Remocao ---\n");
    listar(notas, n); // Exibe a lista final para comprovarmos se o item sumiu e a ordem se manteve.
    
    return 0;
}

// --- COMO FUNCIONA A REMOÇÃO MANTENDO A ORDEM ---
void remover(float v[], int *n, float valor) {
    int i;
    int pos; // Para guardar o índice de quem vai ser apagado.
    
    // 1. Verificação de Vazio (Underflow)
    if (*n == 0) { 
        printf("ERRO: A lista ja esta vazia! Nao ha o que remover.\n");
        return; // Sai da função sem fazer nada.
    }
    
    // 2. Encontrar o Alvo
    // Para remover, primeiro precisamos saber ONDE o número está. 
    // Como nossa lista é ordenada, usamos a Busca Binária (que já programamos) para ser bem rápido.
    pos = buscaBinaria(v, *n, valor);
    
    if (pos == -1) { // Se a busca devolveu -1, o alvo não está na lista.
        printf("ERRO: O elemento %.2f nao foi encontrado na lista!\n", valor);
        return;
    }
    
    // 3. Apagar o Alvo e Fechar o Buraco (Shift para a esquerda)
    // Se apenas colocássemos um '0' na posição, quebraríamos a lista.
    // A técnica correta é puxar todo mundo que está DEPOIS do alvo uma casa para a ESQUERDA, 
    // essencialmente esmagando (sobrescrevendo) o valor que queremos apagar.
    
    // O laço começa exatamente na posição do alvo (pos) e vai até o penúltimo item.
    for (i = pos; i < (*n) - 1; i++) {
        
        v[i] = v[i + 1]; // A casa atual recebe uma cópia de quem está na casa da direita.
        
    }
    
    // 4. Atualizar o Contador Geral
    // Após puxar todos os itens e fechar o buraco, a nossa lista ficou 1 item menor.
    // Subtraímos 1 da variável apontada por 'n'.
    (*n)--;
    
    printf("Sucesso! Elemento removido.\n");
}

// (As funções buscaBinaria, inserirCresc e listar permanecem idênticas)
int buscaBinaria(float v[], int n, float valor) {
    int ini = 0, fim = n - 1, meio;
    while (ini <= fim) {
        meio = (ini + fim) / 2;
        if (valor == v[meio]) return meio;
        if (valor < v[meio]) fim = meio - 1;
        if (valor > v[meio]) ini = meio + 1;
    }
    return -1;
}

void inserirCresc(float v[], int *n, int max, float valor) {
    int i, pos;
    if (*n == max) return;
    i = 0;
    while (v[i] < valor && i < *n) i++;
    pos = i;
    for (i = *n; i > pos; i--) v[i] = v[i - 1];
    v[pos] = valor;
    (*n)++;
}

void listar(float v[], int n) {
    int i;
    for (i = 0; i < n; i++) printf("%.2f\n", v[i]);
}