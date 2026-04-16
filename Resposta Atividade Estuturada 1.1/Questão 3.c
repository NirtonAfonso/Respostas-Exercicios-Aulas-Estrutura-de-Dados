#include <stdio.h>
#include <string.h>

// a) A struct Projeto3D agrupa os dados de uma peça na fila de impressão.
// Em C clássico, não existe o tipo "boolean" (true/false) nativamente.
// Por isso, usamos um 'int' comum como "flag" (bandeira de estado):
// convencionou-se que o número 0 significa FALSO e o número 1 significa VERDADEIRO.
struct Projeto3D {
    char nomePeca[50];
    float tempoEstimadoMinutos;
    int concluido; // Flag booleana (0 = Falso/Pendente, 1 = Verdadeiro/Concluído)
};

// c) Implementação: Função que recebe o vetor e altera os status.
// ATENÇÃO (Ponteiros e Vetores): Em C, quando passamos um vetor para uma função,
// ele "decai" (se transforma) automaticamente em um ponteiro que aponta para o
// endereço de memória da sua primeira posição (índice 0).
// É por isso que não usamos '&' na main. E é por isso que, ao alterar 'vetor[i]'
// aqui dentro, a alteração é permanente e reflete no vetor original da função main!
void finalizarProjetosRapidos(struct Projeto3D *vetor, int tamanho, float limite) {
    int i;
    // O laço percorre todas as posições do vetor, até o tamanho informado.
    for(i = 0; i < tamanho; i++) {
        // Se o tempo estimado da peça atual for menor ou igual ao limite tolerado...
        if(vetor[i].tempoEstimadoMinutos <= limite) {
            // ...marcamos a peça como concluída (1).
            vetor[i].concluido = 1;
        }
    }
}

int main() {
    // b) Declarando e inicializando o vetor de structs DIRETAMENTE no código (Hardcoded).
    // Ao invés de usar o scanf para pedir os dados ao usuário, nós já criamos o vetor preenchido.
    //
    // COMO FUNCIONA A SINTAXE DE INICIALIZAÇÃO COM CHAVES {}:
    // 1. As chaves MAIORES (externas) agrupam todo o vetor (todas as 4 posições).
    // 2. Cada bloco de chaves MENORES (internas) representa UMA ÚNICA posição do vetor (um projeto).
    // 3. A ordem dos valores dentro das chaves internas é rigorosa! Ela DEVE ser exatamente a
    //    mesma ordem em que os campos foram declarados na 'struct' lá no início do arquivo:
    //    - 1º valor (String) -> vai para a variável 'nomePeca'
    //    - 2º valor (Float)  -> vai para a variável 'tempoEstimadoMinutos'
    //    - 3º valor (Int)    -> vai para a variável 'concluido' (usamos 0 pois iniciam pendentes)
    struct Projeto3D filaDeImpressao[4] = {
        {"Vaso Decorativo", 120.5, 0},   // Posição 0 do vetor -> acessível via filaDeImpressao[0]
        {"Chaveiro", 15.0, 0},           // Posição 1 do vetor -> acessível via filaDeImpressao[1]
        {"Suporte de Celular", 45.5, 0}, // Posição 2 do vetor -> acessível via filaDeImpressao[2]
        {"Action Figure", 300.0, 0}      // Posição 3 do vetor -> acessível via filaDeImpressao[3]
    };

    int i;
    float tempoLimite = 60.0; // Definindo o limite temporal (ex: projetos de até 1 hora)

    printf("--- FILA ORIGINAL DE IMPRESSAO ---\n");
    for(i = 0; i < 4; i++) {
        printf("- %s (%.1f min) - Status: %d\n", filaDeImpressao[i].nomePeca, filaDeImpressao[i].tempoEstimadoMinutos, filaDeImpressao[i].concluido);
    }

    // d) Passo 1: Chamando a função.
    // Como 'filaDeImpressao' é um vetor, não precisamos colocar o '&' comercial antes dele.
    // Apenas escrever o nome do vetor já envia o endereço inicial de memória para a função.
    finalizarProjetosRapidos(filaDeImpressao, 4, tempoLimite);

    // d) Passo 2: Imprimindo os resultados filtrados.
    printf("\n--- RESULTADO (PROJETOS CONCLUIDOS EM ATE %.1f MIN) ---\n", tempoLimite);

    for(i = 0; i < 4; i++) {
        // Verificamos o campo 'concluido' para saber se a função acima alterou o status desta peça.
        if(filaDeImpressao[i].concluido == 1) {
            printf("[CONCLUIDO] %s\n", filaDeImpressao[i].nomePeca);
        }
    }

    return 0;
}