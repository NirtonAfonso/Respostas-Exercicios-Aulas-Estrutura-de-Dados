#include <stdio.h>
#include <string.h>

// a) A struct Notebook funciona como um "molde" ou "ficha" que agrupa as informações
// exigidas pelo enunciado para representar uma única entidade (um computador).
struct Notebook {
    char marca[50];
    char modelo[50];
    int quantidadeRAM;
    float preco;
};

int main() {
    // b) Criação do vetor com capacidade fixa para 3 elementos.
    // Cada posição (0, 1 e 2) conterá uma "ficha" completa de Notebook.
    struct Notebook estoque[3];
    int i;

    // Variável para guardar o ÍNDICE (posição no vetor) do notebook com mais RAM.
    // Começamos assumindo que o primeiro notebook (índice 0) é o que tem mais memória.
    int indiceMaiorRAM = 0;

    printf("--- CADASTRO DE NOTEBOOKS ---\n");

    // c) Laço de repetição: O 'for' garante que a leitura ocorra exatamente 3 vezes.
    for(i = 0; i < 3; i++) {
        printf("\nNotebook %d:\n", i + 1);

        printf("Marca: ");
        // Usamos fgets para ler a string de forma mais segura, permitindo espaços.
        // O 'stdin' indica que a leitura vem do teclado.
        fgets(estoque[i].marca, 50, stdin);

        // O fgets captura o 'Enter' (\n) digitado pelo utilizador e guarda no fim da palavra.
        // A função strcspn encontra onde esse '\n' está e substituímos por '\0' (fim de string).
        estoque[i].marca[strcspn(estoque[i].marca, "\n")] = '\0';

        printf("Modelo: ");
        fgets(estoque[i].modelo, 50, stdin);
        estoque[i].modelo[strcspn(estoque[i].modelo, "\n")] = '\0';

        printf("Quantidade de RAM (GB): ");
        scanf("%d", &estoque[i].quantidadeRAM);

        printf("Preco (R$): ");
        scanf("%f", &estoque[i].preco);

        // ATENÇÃO: Limpeza do buffer do teclado!
        // Quando lemos números com o scanf, o 'Enter' (\n) fica preso na memória do teclado.
        // Precisamos usar o getchar() para "engolir" esse \n. Se não fizermos isto, o fgets
        // da próxima volta do laço vai capturar esse Enter falso e pular a leitura da "Marca".
        getchar();
    }

    // d) Passo 1: Busca pelo notebook com maior RAM.
    // Como já assumimos que o índice 0 é o maior, começamos o laço a partir do índice 1.
    for(i = 1; i < 3; i++) {
        // Se a RAM do notebook atual for maior que a RAM do notebook que achávamos ser o maior...
        if(estoque[i].quantidadeRAM > estoque[indiceMaiorRAM].quantidadeRAM) {
            // ...então atualizamos o nosso índice para apontar para o novo "campeão".
            indiceMaiorRAM = i;
        }
    }

    // d) Passo 2: Imprimindo o resultado usando o índice que encontrámos.
    printf("\n========================================\n");
    printf("NOTEBOOK COM MAIOR MEMORIA RAM:\n");
    printf("Modelo: %s\n", estoque[indiceMaiorRAM].modelo);
    printf("Preco: R$ %.2f\n", estoque[indiceMaiorRAM].preco);
    printf("RAM: %d GB\n", estoque[indiceMaiorRAM].quantidadeRAM);
    printf("========================================\n");

    return 0;
}