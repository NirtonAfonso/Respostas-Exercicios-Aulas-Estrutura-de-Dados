#include <stdio.h>

// A struct Livro funciona como um "molde" exigido pelo enunciado.
struct Livro {
    int id;
    float preco;
};

int main(void) {
    // Passo 1: Declarar uma variável normal usando o molde da struct.
    struct Livro meu_livro;

    // Passo 2: Criar um ponteiro específico para esse molde e apontar para a variável.
    struct Livro *p = &meu_livro;

    // Passo 3: Atribuição via ponteiro.
    // O operador '->' (seta) é um atalho do C exigido no enunciado.
    // Ele faz duas coisas de uma vez: desreferencia o ponteiro e acessa o campo.
    // Escrever "p->id" é a forma elegante de escrever "(*p).id".
    p->id = 101;
    p->preco = 49.90;

    // Comprovando que a gravação funcionou acessando os dados pelo ponteiro.
    printf("--- Livro Cadastrado no Sistema ---\n");
    printf("ID do Livro: %d\n", p->id);
    printf("Preco: R$ %.2f\n", p->preco);

    return 0;
}