#include <stdio.h>

void listar(float v[], int n);

// Protótipo da inserção ordenada. 
// MUITA ATENÇÃO AQUI: Como essa função vai ADICIONAR um item, o tamanho da lista vai crescer.
// Para que a função consiga alterar a variável 'n' original que está lá na main, 
// somos obrigados a pedir o ENDEREÇO dela. Por isso usamos o ponteiro 'int *n'.
void inserirCresc(float v[], int *n, int max, float valor);

int main(void) {
    float notas[50]; // O nosso vetor com capacidade máxima de 50.
    float nota;      // Variável para guardar temporariamente o que o usuário digitar.
    int n = 0;       // Quantidade de itens ocupados inicia em zero.

    do { // Inicia o laço para o usuário ir populando a nossa lista.
        
        printf("Digite uma nota (negativo para parar): ");
        scanf("%f", &nota); // Lê o número e guarda no endereço de memória da variável 'nota'.
        
        // Regra de negócio: Se o número for positivo, nós o adicionamos à lista.
        // O número negativo funciona como um "botão de parada" (sentinela).
        if (nota >= 0) {
            
            // Enviamos o vetor, o ENDEREÇO da variável n (&n), o limite de 50, e a nota digitada.
            inserirCresc(notas, &n, 50, nota);
            
        }
    } while (nota >= 0); // Continua pedindo notas infinitamente, até vir um negativo.

    printf("\n--- Lista Final ---\n");
    listar(notas, n); // Mostra como ficou a lista após todas as inserções.
    
    return 0;
}

// --- COMO FUNCIONA A INSERÇÃO ORDENADA ---
void inserirCresc(float v[], int *n, int max, float valor) {
    int i;
    int pos; // Vai guardar o índice exato onde o novo número deve ser inserido.

    // 1. Verificação de Espaço (Overflow)
    // O asterisco (*) acessa o valor que está dentro da memória apontada por 'n'.
    if (*n == max) { 
        printf("ERRO: Lista cheia! Nao cabe mais ninguem.\n");
        return; // Aborta a função imediatamente.
    }

    // 2. Encontrar a Posição Correta (para manter a ordem crescente)
    i = 0;
    
    // Vamos andando pelo vetor enquanto o número que está lá for MENOR que o novo 'valor',
    // e enquanto não chegarmos no final dos itens válidos (i < *n).
    while (v[i] < valor && i < *n) {
        i++; // Avança uma casa.
    }
    
    // Quando o while para, 'i' representa exatamente o "buraco" onde o novo valor deve entrar.
    pos = i; 

    // 3. Abrir Espaço (Shift para a direita)
    // Se achamos a posição no meio da lista, não podemos simplesmente jogar o valor lá, 
    // senão apagamos quem já estava! Temos que empurrar todo mundo uma casa para a direita.
    // Começamos do último elemento (*n) e vimos copiando de trás para frente até a posição 'pos'.
    for (i = *n; i > pos; i--) {
        v[i] = v[i - 1]; // O item da direita recebe uma cópia do item da esquerda.
    }

    // 4. Efetivar a Inserção
    v[pos] = valor; // O espaço foi aberto. Agora podemos guardar o novo valor na posição correta.
    
    // 5. Atualizar o Contador Geral
    // Aumenta a quantidade total de itens. Os parênteses garantem que estamos 
    // somando +1 ao VALOR apontado por 'n', e não alterando o endereço de memória.
    (*n)++; 
}

void listar(float v[], int n) { // Função de listagem (idêntica ao ex1).
    int i;
    for (i = 0; i < n; i++) printf("%.2f\n", v[i]); // Adicionado .2 para formatar duas casas decimais.
}