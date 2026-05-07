#include <stdio.h> // Ponto de partida do código C para habilitar printf/scanf

// Protótipos
void inserir(float v[], float n, int *pos, int max); // Transição do & do C++ para o * do C
void listar(float v[], int quantidade); // Protótipo da listagem

int main(void) { // Bloco executável
    float notas[10]; // Instancia a lista na memória estática
    int quantidade; // Determina a fronteira entre dados reais e posições vazias
    float n; // Acolhe a entrada temporária

    quantidade = 0; // Garante confiabilidade iniciando limpo

    do { // Inicia cadastro em lote
        printf("Digite valor: "); // Feedback de prompt
        scanf("%f", &n); // Scan do buffer de teclado
        if (n != 0) inserir(notas, n, &quantidade, 10); // Condição: não armazena o comando de escape (0), passando quantidade como ponteiro
    } while(n != 0); // A submissão do número 0 rompe este ciclo

    // Imprime vetor
    listar(notas, quantidade); // Aqui a função listar finalmente é invocada no fluxo, exibindo tudo que foi inserido

    return 0; // Código de saída padrão
} // Fim Main

void inserir(float v[], float n, int *pos, int max) { // Recebe referência da posição (ponteiro)
    if (*pos >= max) printf("ERRO: Lista cheia!\n"); // Evita invasão de memória (Segmentation Fault)
    else { // Condição saudável de inserção
        v[*pos] = n; // Copia N para a base do vetor com o deslocamento apontado
        (*pos)++; // Evolui o cursor da lista principal
    } // Fecha bloco
} // Retorno de execução

void listar(float v[], int quantidade) { // Executa a leitura formatada
    int i; // Declaração antecipada exigida por versões clássicas do C
    for (i=0; i<quantidade; i++) { // Loop de percurso linear limitado pela fronteira virtual
        printf("%f\n", v[i]); // Despeja o conteúdo no terminal com carriage return
    } // Fechamento for
} // Fechamento sub-rotina