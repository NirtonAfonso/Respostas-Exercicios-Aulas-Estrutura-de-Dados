#include <stdio.h>

struct _aluno {
    int matricula;
    float nota;
};

int main(void) {
    // Declara um aluno
    struct _aluno joao;

    joao.matricula = 12014432;
    joao.nota = 7.5;

    printf("Mat.: %d\n", joao.matricula);
    printf("Nota: %.1f\n", joao.nota);

    return 0;
}