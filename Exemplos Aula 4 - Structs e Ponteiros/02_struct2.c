#include <stdio.h>

struct _aluno {
    int matricula;
    float nota;
};

void imprime(struct _aluno aluno);

int main(void) {
    // Declara um aluno
    struct _aluno joao;

    joao.matricula = 12014432;
    joao.nota = 7.5;

    imprime(joao);

    return 0;
}

void imprime(struct _aluno aluno) {
    printf("Mat.: %d\n", aluno.matricula);
    printf("Nota: %.1f\n", aluno.nota);
}