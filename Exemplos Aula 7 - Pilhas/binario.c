#include <stdio.h> // Importa a biblioteca padrão para permitir o uso das funções printf (saída) e scanf (entrada).

#define MAX 50 // Cria uma macro constante que dita que o limite da nossa pilha será de 50 posições.

// Assinaturas das funções essenciais da Pilha. Os ponteiros (*) garantem a modificação das variáveis reais da main.
int empilhar(int v[], int *topo, int valor); // Prepara a função de inserção no topo da pilha.
int desempilhar(int v[], int *topo, int *valor); // Prepara a função de remoção do topo da pilha.

int main(void) { // Ponto de partida do nosso programa.
    
    int bin[MAX]; // Cria o vetor 'bin' de inteiros, que será o corpo da nossa pilha para guardar os restos.
    int topo = -1; // Topo igual a -1 é a regra de ouro para dizer: "a pilha está vazia neste exato momento".

    int dado; // Variável criada para receber o número decimal que o usuário digitar no teclado.
    int vazia; // Variável de suporte que vai receber 0 ou 1 para nos dizer se a pilha terminou de ser esvaziada.
    int resto; // Variável matemática para guardar o resto da divisão por 2 (que sempre será 0 ou 1, os nossos bits).
    int quociente; // Variável matemática para guardar o resultado inteiro da divisão por 2.

    printf("Digite um numero inteiro: "); // Pede na tela para o usuário fornecer o número a ser convertido.
    
    scanf("%d", &dado); // Lê o número inteiro (%d) e armazena diretamente no endereço de memória da variável 'dado' (&).

    // LÓGICA DA CONVERSÃO: Dividimos por 2 e empilhamos os restos. A pilha (LIFO) inverterá a ordem perfeitamente no final.
    do { // Inicia o laço de repetição que fará as divisões sucessivas.
        
        quociente = dado / 2; // Realiza a divisão inteira do número atual por 2 e salva na variável quociente.
        
        resto = dado % 2; // A operação módulo (%) captura apenas o resto dessa mesma divisão (0 ou 1).
        
        empilhar(bin, &topo, resto); // Coloca esse bit (resto) no topo da pilha. Passamos o endereço de topo (&topo).
        
        dado = quociente; // Atualiza a variável 'dado' com o quociente. Ele será o alvo da divisão no próximo ciclo.
        
    } while(dado > 0); // O laço se repete até que o número seja reduzido a zero (condição de parada da conversão).

    // LÓGICA DA IMPRESSÃO: Ao desempilhar, o último resto calculado será o primeiro a sair.
    do { // Inicia o laço que vai "sacar" os bits da pilha um por um.
        
        vazia = desempilhar(bin, &topo, &dado); // Chama a função que retira do topo. O bit retirado será salvo na variável 'dado'.
        
        if (vazia == 0) { // Avalia se a tentativa de desempilhar foi bem sucedida (0 significa sucesso, sem erros).
            printf("%d", dado); // Imprime o bit na tela. Note que NÃO tem '\n', para que os bits fiquem colados lado a lado.
        } // Fim do if.
        
    } while (vazia == 0); // Continua o processo de puxar bits e imprimir até que a função retorne 1 (pilha secou).

    printf("b\n"); // Imprime a letra 'b' minúscula e pula uma linha, apenas para identificar formalmente que é base binária.
    
    return 0; // Finaliza o programa indicando que nenhuma falha ocorreu.
} // Fim da main.

int empilhar(int v[], int *topo, int valor) { // Início do bloco que define como um item entra na pilha.
    
    if (*topo >= MAX - 1) { // Verifica o limite da pilha. Se o topo atual for maior ou igual a 49 (MAX 50 - 1), não cabe mais.
        return 1; // Retorna 1 silenciosamente (sem printf) informando que a operação falhou por falta de espaço.
    } // Fim do teste limite.
    
    *topo = *topo + 1; // Altera o valor real da variável topo da main, somando 1. Criou-se o espaço.
    
    v[*topo] = valor; // Usa esse novo valor de topo como índice para guardar o bit no vetor.
    
    return 0; // Confirma que a inserção ocorreu de forma perfeita.
} // Fim da função empilhar.

int desempilhar(int v[], int *topo, int *valor) { // Início do bloco que define como um item sai da pilha.
    
    if (*topo < 0) { // Testa se o índice de controle do topo indica vazio (-1 ou menor).
        return 1; // Retorna 1 silenciosamente, avisando que não dá para tirar algo do nada.
    } // Fim do teste de pilha vazia.
    
    *valor = v[*topo]; // Acessa o número no topo do vetor e o copia para dentro do endereço apontado por '*valor'.
    
    *topo = *topo - 1; // O grande truque do LIFO: rebaixamos o topo. O dado foi "removido" da área útil da pilha.
    
    return 0; // Confirma que a remoção e o resgate do valor funcionaram perfeitamente.
} // Fim da função desempilhar.