#include <stdio.h>

void listar(float v[], int n);
void inserirCresc(float v[], int *n, int max, float valor);

// Protótipo da busca binária. 
// Ela recebe o vetor, a quantidade de itens válidos 'n', e o valor que queremos achar.
// Retorna um inteiro (que será o índice onde o valor está, ou -1 se não existir).
int buscaBinaria(float v[], int n, float valor);

int main(void) {
    float notas[50], nota;
    int n = 0;
    int pos; // Vai receber a resposta da nossa função de busca.

    // Bloco de inserção idêntico ao ex2. Garante que a lista nasça ordenada.
    do {
        printf("Digite uma nota (negativo para parar): ");
        scanf("%f", &nota);
        if (nota >= 0) inserirCresc(notas, &n, 50, nota);
    } while (nota >= 0);

    printf("\n--- Lista Atual ---\n");
    listar(notas, n);

    // --- NOVA FUNCIONALIDADE: BUSCA ---
    printf("\nProcurar qual nota? ");
    scanf("%f", &nota);
    
    // Dispara a busca binária mandando o vetor, o limite atual 'n', e a nota alvo.
    pos = buscaBinaria(notas, n, nota);
    
    // A função nos devolve um número. Precisamos tratar o que esse número significa.
    if (pos == -1) { // -1 é o nosso código combinado para "Não achei".
        printf("Valor nao encontrado!\n"); 
    } else { // Se não é -1, é um índice válido do vetor.
        printf("Encontrado na posicao (indice): %d\n", pos); 
    }
    
    return 0;
}

// --- COMO FUNCIONA A BUSCA BINÁRIA ---
// CUIDADO: Esta mágica SÓ funciona se a lista estiver RIGIDAMENTE ORDENADA.
// É como procurar uma palavra num dicionário: você abre no meio, vê se passou ou se falta,
// e joga metade do livro fora. É extremamente rápido!
int buscaBinaria(float v[], int n, float valor) {
    
    // 1. Marca os ponteiros iniciais delimitando a nossa área de busca.
    int ini = 0;        // Começa apontando para o primeiro elemento (índice 0).
    int fim = n - 1;    // Começa apontando para o último elemento válido.
    int meio;           // Variável para guardar onde fica o centro exato.

    // O laço continua enquanto a área de busca for válida (início não cruzar com o fim).
    while (ini <= fim) {
        
        // Calcula o índice que está bem no meio do nosso intervalo atual.
        meio = (ini + fim) / 2; 
        
        // CENÁRIO 1: O tiro acertou no alvo! 
        // O valor que está no meio é exatamente o que procuramos.
        if (valor == v[meio]) {
            return meio; // Devolve o índice e encerra a função na hora.
        }
        
        // CENÁRIO 2: O valor procurado é MENOR que o do meio.
        // Se a lista está em ordem crescente, é impossível ele estar na metade da direita.
        // Então, nós "apagamos" a metade direita puxando o ponteiro de 'fim' para antes do meio.
        if (valor < v[meio]) {
            fim = meio - 1; 
        }
        
        // CENÁRIO 3: O valor procurado é MAIOR que o do meio.
        // Ele obrigatoriamente está na metade da direita. 
        // Então, "apagamos" a metade esquerda puxando o ponteiro de 'ini' para depois do meio.
        if (valor > v[meio]) {
            ini = meio + 1;
        }
        
    } // Fim do laço while. A área de busca vai encolhendo até achar ou os ponteiros se cruzarem.

    // Se o while terminou e o código chegou até aqui, os ponteiros se cruzaram.
    // Isso significa que o elemento não existe na lista. Retornamos o código de erro -1.
    return -1;
}

// (As funções inserirCresc e listar permanecem idênticas ao ex2)
void inserirCresc(float v[], int *n, int max, float valor) {
    int i, pos;
    if (*n == max) { return; }
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