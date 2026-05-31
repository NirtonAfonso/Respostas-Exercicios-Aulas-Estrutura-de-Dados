#include <stdio.h> // Inclui os comandos básicos do C para interagir com o usuário no terminal (printf, scanf).

#define MAX 50 // Estabelece 50 como o teto máximo de elementos que a nossa pilha vai aguentar.

// Os cabeçalhos das nossas funções. Funções de pilha em C precisam de ponteiros para alterar os controles da estrutura.
int empilhar(int v[], int *topo, int valor); // Empilha: precisa do vetor, do endereço do topo, e do número a inserir.
int desempilhar(int v[], int *topo, int *valor); // Desempilha: precisa do vetor, do endereço do topo, e de um endereço para salvar o item resgatado.

int main(void) { // Abertura da rotina principal do nosso código.
    
    int pilha[MAX]; // A declaração do vetor que vai efetivamente armazenar os números, comportando-se como uma pilha.
    int topo = -1; // O controlador da pilha. Ele começa apontando pro "subsolo" (-1), mostrando que não há andar térreo (0) ainda.

    int dado; // Reservamos essa memória para guardar temporariamente os números que o usuário vai digitar ou os que vão ser desempilhados.
    int vazia; // Variável chave para o laço de repetição saber a hora exata de parar de desempilhar.

    // A PRIMEIRA FASE: ALIMENTANDO A PILHA
    do { // Comando 'do' inicia um bloco que vai executar ao menos uma vez antes de testar a condição.
        
        printf("Digite um numero inteiro (negativo para parar): "); // Escreve a instrução para o usuário.
        
        scanf("%d", &dado); // Lê a digitação, formata como número inteiro (%d) e grava dentro do endereço da variável 'dado'.
        
        if (dado >= 0) { // Condicional que bloqueia números negativos. Eles não devem entrar na pilha.
            empilhar(pilha, &topo, dado); // Aciona a função de colocar no topo. Passa o vetor, a referência do topo e o número digitado.
        } // Fim do if.
        
    } while(dado >= 0); // A regra do looping: se o usuário digitou 0 ou positivo, repita tudo. Se digitou negativo, quebre o looping.

    printf("\n--- Esvaziando a Pilha (Regra LIFO) ---\n"); // Mensagem puramente estética para organizar a exibição no terminal.

    // A SEGUNDA FASE: CONSUMINDO A PILHA
    do { // Inicia o laço responsável por destruir (consumir) a pilha do topo até a base.
        
        vazia = desempilhar(pilha, &topo, &dado); // Aciona a função que remove itens. O número removido vai 'pousar' na variável 'dado'.
        
        if (vazia == 0) { // Checa o sinal da função. Retorno 0 é o sinal verde informando "consegui remover um item pra você".
            printf("%d\n", dado); // Imprime na tela o número que a função acabou de jogar dentro da variável 'dado', e pula a linha.
        } // Fim do if.
        
    } while (vazia == 0); // Fica preso nesse ciclo de remover e imprimir enquanto a resposta da função for sinal verde (0).
    
    return 0; // Finaliza o sistema, devolvendo 0 ao sistema operacional, o que representa um encerramento padrão e limpo.
} // Fim definitivo do programa.

// BLOCO FUNCIONAL: COMO A PILHA CRESCE
int empilhar(int v[], int *topo, int valor) { // A função recebe a estrutura e o novo integrante.
    
    if (*topo >= MAX - 1) { // Consulta o limite. Como os índices vão de 0 a 49 (para um MAX de 50), o limite superior é MAX - 1.
        printf("ERRO: Pilha cheia!\n"); // Alerta de transbordamento. O prato não cabe na pilha de pratos.
        return 1; // Retorna o código 1, abortando a função imediatamente sem fazer a inserção.
    } // Fim da checagem de limite.
    
    *topo = *topo + 1; // Atualiza o marcador do topo original na memória. Agora a pilha tem mais um "andar" ativo.
    
    v[*topo] = valor; // O novo número é colocado exatamente no índice correspondente a esse andar recém-criado.
    
    return 0; // Devolve o código 0, selando o sucesso da operação de empilhamento.
} // Fim da lógica de empilhar.

// BLOCO FUNCIONAL: COMO A PILHA ENCOLHE
int desempilhar(int v[], int *topo, int *valor) { // A função recebe a estrutura e um "balde" (ponteiro *valor) para colocar o item retirado.
    
    if (*topo < 0) { // Olha para o controlador do topo. Se for negativo, é matematicamente impossível ter itens no vetor.
        printf("ERRO: Pilha vazia!\n"); // Alerta o usuário que ele está tentando tirar algo do vazio.
        return 1; // Retorna código de falha (1) e sai da função.
    } // Fim da checagem de escassez.
    
    *valor = v[*topo]; // Aqui acontece o resgate: o elemento que está no topo do vetor é duplicado para dentro do espaço de memória do '*valor'.
    
    *topo = *topo - 1; // Aqui acontece a remoção lógica: o topo é rebaixado. Para o nosso programa, aquele índice anterior foi invalidado.
    
    return 0; // Retorna 0 atestando que o dado foi extraído e o topo foi atualizado sem problemas.
} // Fim da lógica de desempilhar.