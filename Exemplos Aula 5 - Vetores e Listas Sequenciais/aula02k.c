#include <stdio.h> // Core de input/output do C padrão

// Protótipos
void inserir(float v[], float n, int *pos, int max); // Conversão & para * para acessar escopo externo
void listar(float v[], int quantidade); // Função estática de visualização
int buscar(float v[], int quantidade, int n); // Função utilitária de varredura
void remover(float v[], int *quantidade, int n); // Função de destruição, altera o estado, requer ponteiro *quantidade

int main(void) { // Thread principal
    float notas[10]; // Estrutura contínua de memória para floats
    int quantidade; // Tamanho virtual do vetor (quantos dados de fato importam)
    float n; // Caixa registradora temporária do valor do IO
    int pos; // Variável que receberá posições confirmadas

    quantidade = 0; // Formata os atributos vitais de início

    // Leitura de N dado
    do { // Força a execução pelo menos 1 vez
        printf("Digite valor: "); // Sinaliza input
        scanf("%f", &n); // Popula a memória local 'n'
        if (n != 0) inserir(notas, n, &quantidade, 10); // Transmite o endereço &quantidade, para ser tratada como ponteiro int*
    } while(n != 0); // Verifica integridade do sentinela na base do laço

    listar(notas, quantidade); // Mostra o progresso logo após as inserções

    // Busca valor
    printf("Digite valor a buscar na lista: "); // Fase 2: Pesquisa
    scanf("%f", &n); // Lê novo alvo em 'n'
    pos = buscar(notas, quantidade, (int)n); // Realiza conversão estática implícita float->int que existia no código original do C++
    if (pos >= 0) printf("Encontrado em pos= %d\n", pos); // Se obteve sucesso em achar (índices vão de 0 pra cima)
    else printf("Valor nao encontrado na lista!\n"); // Fallback textual de erro 

    // Remover um valor
    printf("Digite valor a remover da lista: "); // Fase 3: Exclusão lógica
    scanf("%f", &n); // Absorve alvo da exclusão
    remover(notas, &quantidade, (int)n); // Envia alvo em formato int para função de deleção passando ponteiro e referências corretamente

    listar(notas, quantidade); // Prova visual de que o elemento desapareceu e a lista foi condensada

    return 0; // Libera processo ao sistema hospedeiro
} // Destrói stack main

void inserir(float v[], float n, int *pos, int max) { // Onde a mágica de preenchimento acontece
    if (*pos >= max) printf("ERRO: Lista cheia!\n"); // Barreira de segurança contra buffer overrun (compara valor referenciado)
    else { // Fluxo de dados limpo
        v[*pos] = n; // Crava o elemento no slot vazio
        (*pos)++; // Empurra o limite da lista uma posição para frente operando diretamente na memória raiz da var de contagem
    } // Exit do controle
} // Destrói escopo função

void listar(float v[], int quantidade) { // Funcionalidade de report
    int i; // Variável auxiliar pré-declarada (C89 style obrigatório)
    for (i=0; i<quantidade; i++) { // Passa pelos validos
        printf("%f\n", v[i]); // Joga pro log (substitui cout e endl)
    } // Encerra rodada
} // Finaliza report

int buscar(float v[], int quantidade, int n) { // Motor lógico de encontrar o agulha no palheiro
    int i; // Variável loop
    for (i=0; i<quantidade; i++) { // Passada iterativa
        if (v[i] == n) return i; // Critério de match: valor do index é igual procurado? Volta o index numérico
    } // Termina passadas
    return -1; // Índice de erro convencional no desenvolvimento de algoritmos
} // Finaliza motor

void remover(float v[], int *quantidade, int n) { // Otimização de tempo constante em exclusão de listas não ordenadas
    int pos; // Espaço local p/ armazenar o índex vindo da busca
    if (*quantidade == 0) printf("ERRO: Lista Vazia!\n"); // Verificação lógica primária: underflow (nada a remover)
    else { // Verificação validou que existem membros
        pos = buscar(v, *quantidade, n); // Chama rotina buscar para rastrear endereço index do membro
        if (pos < 0) printf("ERRO: Elemento inexistente!\n"); // Valida se o membro escolhido realmente existe entre os válidos
        else { // Bloco onde a remoção efetiva ocorre
            v[pos] = v[*quantidade - 1]; // Puxa o último elemento da lista de dados e o joga por cima do que você quer deletar. Isso bagunça a ordem, mas elimina gaps (buracos na lista) instantaneamente sem uso de laços.
            (*quantidade)--; // Agora que o último elemento está "duplicado", apenas diminuímos em 1 o tamanho lógico do vetor para que a casa final antiga seja considerada área "morta/inválida" pelo algoritmo
        } // Fim bloco de efetivação de deleção
    } // Fim tratamento erro inexistente
} // Fim do escopo da exclusão