#include <stdio.h>  // Inclui a biblioteca padrão do C para usar comandos de entrada e saída (printf, fgets).
#include <ctype.h>  // Inclui a biblioteca com funções prontas para testar caracteres (como isalpha e isdigit).
#include <string.h> // Inclui a biblioteca para manipulação de textos, necessária para limpar o 'Enter' da leitura.

#define MAX 50 // Define a capacidade máxima das nossas pilhas. Se precisarmos de pilhas maiores, mudamos apenas este número.

// Abaixo, declaramos as funções que vão manipular as pilhas.
// O asterisco (*) no '*topo' indica que a função receberá o endereço de memória da variável, permitindo alterá-la diretamente.
int empilhar(char v[], int *topo, char valor); // Função responsável por colocar um item no topo da pilha.
int desempilhar(char v[], int *topo, char *valor); // Função responsável por retirar o item do topo da pilha.

int main(void) { // Início da função principal, onde o programa começa a rodar.
    
    // --- CONSTRUÇÃO DA PRIMEIRA PILHA (LETRAS) ---
    char letras[MAX]; // Cria o vetor que servirá como a estrutura física da pilha de letras.
    int ltopo = -1;   // Inicializa o topo em -1. Como os índices de vetor em C começam em 0, -1 indica que a pilha está 100% vazia.
    
    // --- CONSTRUÇÃO DA SEGUNDA PILHA (DÍGITOS) ---
    char digitos[MAX]; // Cria o vetor que servirá como a estrutura física da pilha de números.
    int dtopo = -1;    // Inicializa o topo da pilha de números em -1 (vazia).

    char texto[2*MAX]; // Cria um vetor de caracteres para armazenar a frase completa que o usuário vai digitar.
    int vazia;         // Cria uma variável para receber a resposta da função desempilhar (0 = sucesso, 1 = erro/vazia).
    char dado;         // Cria uma variável que vai servir de "cesta" para guardar o item que for retirado da pilha.
    int i;             // Cria a variável 'i' que será usada como contador para navegar pela frase digitada.

    printf("Digite uma mensagem com letras e numeros:\n"); // Exibe a instrução para o usuário na tela.
    
    fgets(texto, 2*MAX, stdin); // Lê a frase inteira digitada no teclado (stdin) e guarda no vetor 'texto', respeitando o limite de tamanho.
    
    texto[strcspn(texto, "\n")] = '\0'; // Procura o 'Enter' (\n) que o fgets captura acidentalmente e o substitui por '\0' (fim da string).

    i = 0; // Inicializa o contador 'i' em 0 para começarmos a ler a primeira letra da frase (índice 0).
    
    while (texto[i] != '\0') { // Inicia um laço que vai se repetir até encontrar o terminador da string ('\0').
        
        if (isdigit(texto[i])) { // Testa se o caractere atual (texto[i]) é um número (0 a 9).
            empilhar(digitos, &dtopo, texto[i]); // Se for número, empilha no vetor 'digitos'. O '&' envia o endereço de memória do 'dtopo'.
        } // Fim do teste de número.
        
        if (isalpha(texto[i])) { // Testa se o caractere atual (texto[i]) é uma letra do alfabeto.
            empilhar(letras, &ltopo, texto[i]); // Se for letra, empilha no vetor 'letras'. O '&' envia o endereço de 'ltopo'.
        } // Fim do teste de letra.
        
        i = i + 1; // Soma 1 ao contador 'i' para que o próximo ciclo do while avalie o próximo caractere da frase.
    } // Fim do laço while de separação e empilhamento.

    // --- PROCESSO DE DESEMPILHAMENTO (LIFO) ---
    printf("Letras...\n"); // Imprime um cabeçalho avisando que as letras começarão a sair da pilha.
    
    do { // Inicia um laço do tipo "faça-enquanto" para esvaziar a pilha de letras.
        vazia = desempilhar(letras, &ltopo, &dado); // Tenta retirar o item do topo. Passamos o endereço de 'ltopo' e da cesta 'dado' (&dado).
        if (vazia == 0) { // Verifica se o desempilhamento retornou 0 (o que significa que deu certo, a pilha não estava vazia).
            printf("%c\n", dado); // Se deu certo, imprime a letra que foi parar dentro da variável 'dado'.
        } // Fim da verificação de sucesso.
    } while (vazia == 0);  // O laço se repete continuamente enquanto conseguirmos desempilhar itens (vazia == 0).

    printf("Numeros...\n"); // Imprime um cabeçalho avisando que os números começarão a sair da pilha.
    
    do { // Inicia um laço "faça-enquanto" para esvaziar a pilha de números.
        vazia = desempilhar(digitos, &dtopo, &dado); // Tenta retirar um número do topo. Retorna 0 se sucesso, 1 se estiver vazia.
        if (vazia == 0) { // Se retornou 0, conseguimos tirar um número da pilha com sucesso.
            printf("%c\n", dado); // Imprime o número que foi desempilhado e armazenado na variável 'dado'.
        } // Fim da verificação de sucesso.
    } while (vazia == 0); // Continua repetindo e esvaziando até que a função retorne 1 (indicando que a pilha zerou).
    
    return 0; // Encerra o programa principal e retorna 0 para o sistema operacional, indicando execução sem falhas.
} // Fim da função main.

// --- IMPLEMENTAÇÃO DAS FUNÇÕES DA PILHA ---

int empilhar(char v[], int *topo, char valor) { // Declaração da função empilhar. Recebe o vetor, o ponteiro do topo e o novo caractere.
    
    if (*topo >= MAX - 1) { // Verifica se o valor atual do topo já atingiu o último índice permitido do vetor (MAX - 1).
        printf("ERRO: Pilha cheia!\n"); // Se sim, avisa o usuário que houve um transbordamento (Stack Overflow).
        return 1; // Aborta a operação de empilhar e retorna 1 (código de erro).
    } // Fim da verificação de pilha cheia.
    
    *topo = *topo + 1; // Incrementa o valor do topo em 1. É como "subir um andar" na nossa pilha para o novo item.
    
    v[*topo] = valor; // Pega o caractere recebido e o guarda exatamente na nova posição (novo andar) que acabamos de criar.
    
    return 0; // A operação foi concluída com sucesso. Retorna 0.
} // Fim da função empilhar.

int desempilhar(char v[], int *topo, char *valor) { // Declaração da função desempilhar. Usa ponteiro no 'valor' para salvar o item retirado.
    
    if (*topo < 0) { // Verifica se o índice do topo é menor que 0. Se for, significa que não há itens armazenados.
        printf("ERRO: Pilha vazia!\n"); // Avisa o usuário que não há nada para remover (Stack Underflow).
        return 1; // Aborta a operação e retorna 1 (código de erro).
    } // Fim da verificação de pilha vazia.
    
    *valor = v[*topo]; // Copia o caractere que está atualmente no topo do vetor e o salva dentro da variável apontada por '*valor'.
    
    *topo = *topo - 1; // Reduz o valor do topo em 1. O item fisicamente ainda está no vetor, mas ignoramos ele "descendo um andar".
    
    return 0; // A operação de remoção foi um sucesso. Retorna 0.
} // Fim da função desempilhar.