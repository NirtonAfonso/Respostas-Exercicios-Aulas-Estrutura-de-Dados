#include <stdio.h> // Inclui biblioteca nativa

// Protótipos
void inserir(float v[], float n, int *pos, int max); // Ponteiro na inserção
void listar(float v[], int quantidade); // Impressão via cópia de variáveis
int buscar(float v[], int quantidade, int n); // Mantido assinatura original (n do tipo int) para refletir o C++ original (buscando valor truncado)

int main(void) { // Main
    float notas[10]; // Buffer central de dados
    int quantidade; // Tracker de estado atual
    float n; // Valor auxiliar para entrada de teclado
    int pos; // Armazena a localização devolvida por buscas

    quantidade = 0; // Zera a lista

    do { // Início interativo
        printf("Digite valor: "); // Texto console
        scanf("%f", &n); // Leitura com formatação de float
        if (n != 0) inserir(notas, n, &quantidade, 10); // Injeta o valor e delega a atualização de tamanho para a função
    } while(n != 0); // Gatilho de fim de digitação

    listar(notas, quantidade); // Mostra estado da lista pré-busca

    // Busca valor
    printf("Digite valor a buscar na lista: "); // Questiona o termo de pesquisa
    scanf("%f", &n); // Capta a resposta do usuário
    pos = buscar(notas, quantidade, (int)n); // Dispara algoritmo de busca sequencial; cast explícito para int visando coincidir com assinatura da função
    if (pos >= 0) printf("Encontrado em pos= %d\n", pos); // Identifica sucesso se índice retornar 0 ou positivo
    else printf("Valor nao encontrado na lista!\n"); // Feedback de fracasso em caso de retorno igual a -1

    return 0; // Termina
} // Fim rotina central

void inserir(float v[], float n, int *pos, int max) { // Regra de negócio de inserção
    if (*pos >= max) printf("ERRO: Lista cheia!\n"); // Validador físico
    else { // Confirmação
        v[*pos] = n; // Registro matricial
        (*pos)++; // O conteúdo apontado avança 1 casa
    } // Fim validador
} // Fim inserir

void listar(float v[], int quantidade) { // Regra de iteração
    int i; // Variável interna
    for (i=0; i<quantidade; i++) { // Otimização linear até 'quantidade'
        printf("%f\n", v[i]); // C-Style print
    } // Fim for
} // Fim listar

int buscar(float v[], int quantidade, int n) { // Regra de busca sequencial simples
    int i; // Variável interna
    for (i=0; i<quantidade; i++) { // Percorre a malha ativa
        if (v[i] == n) return i; // Verifica match; devolve a coordenada matemática onde ocorreu e interrompe loop precocemente
    } // Fim for de verificação
    return -1; // Flag padrão de ausência em estruturas de dados (índice inexistente)
} // Fim buscar