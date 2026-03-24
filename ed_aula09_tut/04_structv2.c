#include <stdio.h>

#define MAX 50

struct _aluno {
    int matricula;
    float nota;
};

void imprime(struct _aluno v[], int num);

int main(void) {
    // Declara um aluno
    struct _aluno alunos[MAX];

    alunos[0].matricula = 12014432;
    alunos[0].nota = 7.5;

    alunos[1].matricula = 13022301;
    alunos[1].nota = 5.7;

    alunos[2].matricula = 11024122;
    alunos[2].nota = 9.0;

    imprime(alunos, 3);

    return 0;
}

void imprime(struct _aluno v[], int num) {
    int i;

    for (i = 0; i < num; i++) {
        printf("Mat.: %d\n", v[i].matricula);
        printf("Nota: %.1f\n", v[i].nota);
    }
}