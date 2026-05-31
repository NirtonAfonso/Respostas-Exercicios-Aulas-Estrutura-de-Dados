#include <stdio.h> // Importa a biblioteca padrão do C para usarmos comandos como printf.

// Protótipo da função listar. 
// ATENÇÃO: Aqui passamos o vetor (v[]) e a variável 'n' (que guarda a quantidade de itens).
// Como a intenção dessa função é APENAS ler e mostrar os dados na tela, não precisamos usar 
// ponteiros (*). A função não vai alterar o tamanho da lista original.
void listar(float v[], int n);

int main(void) { // Ponto de partida do nosso programa.
    
    // Declara um vetor estático capaz de armazenar até 50 números com casas decimais (float).
    // Pense nisso como uma prateleira com 50 caixas vazias.
    float notas[50]; 
    
    // Variável de controle fundamental: ela indica quantos elementos REAIS (válidos) existem 
    // na nossa lista neste exato momento. Inicia em 0 (lista totalmente vazia).
    int n = 0; 

    // Chama a função para tentar listar os elementos. 
    // Como enviamos 'n' valendo 0, a função vai perceber que não há nada para imprimir.
    listar(notas, n); 

    return 0; // Finaliza o programa indicando que tudo correu bem.
}

// --- IMPLEMENTAÇÃO DA FUNÇÃO LISTAR ---
void listar(float v[], int n) { // Recebe a prateleira (v) e a quantidade de caixas ocupadas (n).
    
    int i; // Declara a variável 'i' que servirá de índice para navegarmos pelo vetor.
    
    // Laço de repetição que vai do índice 0 até um número antes de 'n' (n-1).
    // Se n for 0, a condição (0 < 0) já dá falso logo de cara, e o laço nem inicia.
    for (i = 0; i < n; i++) { 
        
        // Imprime o valor da posição atual do vetor. 
        // Usamos %f porque o vetor é do tipo float. O \n quebra a linha para ficar organizado.
        printf("%f\n", v[i]); 
        
    } // Fim do laço for.
}