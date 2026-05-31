#include <stdio.h> // Diretiva de compilação para incluir bibliotecas padrão do C

// Protótipos
void inserir(float v[], float n, int *pos, int max); // Assinatura exigindo o endereço de memória para o parâmetro pos
void listar(float v[], int quantidade); // Assinatura da nova função que varre a lista, mantendo passagem por valor pois não altera o número de elementos

int main(void) { // Corpo principal
    float notas[10]; // Repositório da lista sequencial
    int quantidade; // Marcador da última posição livre
    float n; // Buffer de leitura

    quantidade = 0; // Lista inicia limpa

    do { // Inicia o recebimento de n dados
        printf("Digite valor: "); // Imprime comando
        scanf("%f", &n); // Lê valor em formato de ponto flutuante
        if (n != 0) inserir(notas, n, &quantidade, 10); // Realiza a chamada da inserção passando o ponteiro da quantidade
    } while(n != 0); // Continua caso a entrada não seja o sentinela 0

    return 0; // Código termina aqui sem exibir (a função listar é declarada mas não chamada na main nesta etapa)
} // Encerra main

void inserir(float v[], float n, int *pos, int max) { // Módulo de inserção com proteção de memória
    if (*pos >= max) printf("ERRO: Lista cheia!\n"); // Interrompe e avisa caso tente extrapolar o array de 10 itens
    else { // Escopo válido
        v[*pos] = n; // Efetiva a gravação do dado na caixinha correta do array
        (*pos)++; // Adiciona 1 na métrica de quantidade do programa principal
    } // Fim Else
} // Fim inserir

void listar(float v[], int quantidade) { // Módulo de iteração puramente visual
    int i; // Controlador do loop
    for (i=0; i<quantidade; i++) { // Roda de zero até o último elemento preenchido de fato (ignora lixo de memória residual do vetor)
        printf("%f\n", v[i]); // Equivalente C ao `cout << v[i] << endl`
    } // Fim do For
} // Fim da listagem