#include <stdio.h> // Biblioteca padrão para usarmos printf (saída) e scanf (entrada)

#define MAX 10 // Define uma constante para o tamanho máximo da nossa fila. Facilita manutenções futuras.

// --- PROTÓTIPOS DAS FUNÇÕES DA FILA ---
// 'ffila' (fim da fila) precisa ser ponteiro (*) porque quem enfileira altera a posição do fim.
int enfileirar(int fila[], int *ffila, int valor);

// 'ifila' (início da fila) é ponteiro (*) porque quem desenfileira altera a posição do início.
// 'ffila' é passado normalmente porque a função só precisa LER onde é o fim para saber se a fila acabou.
// 'valor' é ponteiro (*) para conseguirmos resgatar o número que saiu da fila.
int desenfileirar(int fila[], int *ifila, int ffila, int *valor);

int main(void) {

    // --- DECLARAÇÃO E INICIALIZAÇÃO DA FILA ---
    int fila[MAX];  // O vetor que será a estrutura física da nossa fila
    int ifila = 0;  // O INÍCIO da fila sempre começa na posição 0 (primeira porta de saída)
    int ffila = -1; // O FIM da fila começa em -1 (indicando que não há ninguém lá dentro ainda)
    
    int op; // Variável para armazenar a opção digitada no menu
    int v;  // Variável para armazenar temporariamente o número digitado ou removido

    // Laço de repetição que mantém o menu na tela até o usuário escolher sair
    do {
        printf("\n1. Enfileirar inteiro positivo\n"); // Exibe a opção 1
        printf("2. Desenfileirar todos\n"); // Exibe a opção 2
        printf("3. Sair\n"); // Exibe a opção 3
        printf("Opcao: "); // Pede a escolha
        scanf("%d", &op); // Lê o que o usuário digitou e guarda na variável 'op'

        // Estrutura de decisão para executar a ação correspondente
        switch(op) {
            case 1: // O usuário quer ENFILEIRAR
                printf("Digite um numero inteiro positivo: "); 
                scanf("%d", &v); // Lê o número e guarda em 'v'
                
                // Chama a função passando o vetor, o endereço do fim da fila (&ffila) e o número digitado
                enfileirar(fila, &ffila, v); 
                break; // Sai do switch
                
            case 2: // O usuário quer DESENFILEIRAR TUDO
                printf("\n--- Retirando da Fila ---\n");
                // A função desenfileirar vai tentar retirar um item. Se conseguir, ela retorna 0.
                // O loop while vai continuar rodando enquanto houver itens para tirar (retorno == 0).
                while (desenfileirar(fila, &ifila, ffila, &v) == 0) {
                    
                    // O exercício pede para mostrar APENAS os números que são múltiplos de 5
                    // Se o resto da divisão do número por 5 for igual a zero, é múltiplo!
                    if (v % 5 == 0) {
                        printf("%d\n", v); // Imprime o número
                    }
                }
                break; // Sai do switch
        }
    } while (op != 3); // Se a opção for 3, o laço quebra e o programa termina.
    
    return 0; // Finaliza o main com sucesso
}

// Retorna 0 em caso de sucesso e 1 em caso de fila cheia
int enfileirar(int fila[], int *ffila, int valor) {
    // 1. Verificar se a fila está cheia. 
    // O topo (*ffila) chegou no último índice permitido do vetor (MAX - 1)?
    if (*ffila >= MAX - 1) {
        return 1; // Retorna 1 avisando que deu erro por falta de espaço
    }
    
    // Se não estiver cheia:
    // 2. Incrementar a posição final. A porta de entrada se move uma casa para frente.
    *ffila = *ffila + 1; 
    
    // 3. Guardar o valor na nova posição final. A pessoa/número ocupou seu lugar na fila.
    fila[*ffila] = valor; 
    
    // 4. Indica sucesso
    return 0; 
}

// Retorna 0 em caso de sucesso e 1 em caso de fila vazia
int desenfileirar(int fila[], int *ifila, int ffila, int *valor) {
    // 1. Verificar se a fila tá vazia (e retornar erro se sim)
    // A fila acaba quando o início ultrapassa o fim. Ou seja, todo mundo que estava lá já saiu.
    if (ffila < *ifila) {
        return 1; // Retorna erro de fila vazia
    }
    
    // 2. Ler o elemento do início da fila e salvar dentro do endereço de 'valor'
    *valor = fila[*ifila]; 
    
    // 3. Atualizar o início da fila. 
    // O primeiro da fila saiu! Então o novo "início" agora é o cara que estava atrás dele (índice seguinte).
    *ifila = *ifila + 1; 
    
    // 4. Retornar sucesso
    return 0; 
}