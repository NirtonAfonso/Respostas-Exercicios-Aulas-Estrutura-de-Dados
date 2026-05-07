#include <stdio.h> // Inclui headers padrão do C

// Protótipos
void inserir(float v[], float n, int *pos, int max); // Adaptação de sintaxe para ponteiro
void listar(float v[], int quantidade); // Inalterado logicamente
int buscar(float v[], int quantidade, int n); // Inalterado
void remover(float v[], int *quantidade, int n); // Novo protótipo: necessita alterar a quantidade principal, usa ponteiro

int main(void) { // Início de bloco
    float notas[10]; // Coleção array fixo
    int quantidade; // Tamanho manipulável da lista
    float n; // Variável transitória
    int pos; // Coordenada resgatada

    quantidade = 0; // Reset inicial lógico

    do { // Rotina de popular vetor
        printf("Digite valor: "); // Texto de interface
        scanf("%f", &n); // Capta o número do SO
        if (n != 0) inserir(notas, n, &quantidade, 10); // Realiza o push no vetor com referência à raiz de quantidade
    } while(n != 0); // Escape de laço com o dígito zero

    listar(notas, quantidade); // Verifica povoamento

    // Busca valor
    printf("Digite valor a buscar na lista: "); // Etapa de busca
    scanf("%f", &n); // Lê a intenção do usuário
    pos = buscar(notas, quantidade, (int)n); // O cast explícito previne warnings, conectando float da main ao int da função
    if (pos >= 0) printf("Encontrado em pos= %d\n", pos); // Resultado lógico satisfatório
    else printf("Valor nao encontrado na lista!\n"); // Resultado lógico falho

    return 0; // Termino (Neste estágio, remover não é chamado)
} // Fim de escopo

void inserir(float v[], float n, int *pos, int max) { // Inserção com controle rigoroso
    if (*pos >= max) printf("ERRO: Lista cheia!\n"); // Check overflow
    else { // Ação validada
        v[*pos] = n; // Sobrescreve com o argumento 'n'
        (*pos)++; // Soma 1 no contador alocado na main()
    } // Fecha bloco
} // Retorna

void listar(float v[], int quantidade) { // Renderiza a lista no terminal
    int i; // Indice de loop
    for (i=0; i<quantidade; i++) { // Iteração confinada ao tamanho útil
        printf("%f\n", v[i]); // Ponto flutuante via IO padrão do C
    } // Termina varredura
} // Encerra listar

int buscar(float v[], int quantidade, int n) { // Encontra valor
    int i; // Indice
    for (i=0; i<quantidade; i++) { // Scan O(n)
        if (v[i] == n) return i; // Return aborta o loop e a função ao mesmo tempo na primeira ocorrência
    } // Fim de scan
    return -1; // Código de erro clássico
} // Encerra buscar

void remover(float v[], int *quantidade, int n) { // Implementação de Deleção não ordenada com manipulação via ponteiro
    int pos; // Local para guardar o retorno de busca
    if (*quantidade == 0) printf("ERRO: Lista Vazia!\n"); // Check Underflow (se vazio, não há o que remover)
    else { // Se tiver pelo menos 1
        pos = buscar(v, *quantidade, n); // Aciona a inteligência de busca da outra função para descobrir ONDE o elemento está
        if (pos < 0) printf("ERRO: Elemento inexistente!\n"); // Se retorno de buscar foi -1, avisa do erro lógico
        else { // Se o número de fato estiver no vetor
            v[pos] = v[*quantidade - 1]; // Técnica otimizada para listas não ordenadas: pega o último item da lista e o copia para a casinha recém excluída
            (*quantidade)--; // Reduz globalmente o volume de dados conhecidos (excluindo de fato o número antigo)
        } // Fim lógica remoção
    } // Fim if-else pai
} // Fim remover