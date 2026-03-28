#include <stdio.h>

#define MAX 3

struct _aluno {
    int matricula;
    float nota;
};

int main(void) {
    // Declara um aluno
    struct _aluno alunos[MAX];

    alunos[0].matricula = 12014432;
    alunos[0].nota = 7.5;

    alunos[1].matricula = 13022301;
    alunos[1].nota = 5.7;

    alunos[2].matricula = 11024122;
    alunos[2].nota = 9.0;

    printf("Mat.: %d\n", alunos[0].matricula);
    printf("Nota: %.1f\n", alunos[0].nota);

    printf("Mat.: %d\n", alunos[1].matricula);
    printf("Nota: %.1f\n", alunos[1].nota);

    printf("Mat.: %d\n", alunos[2].matricula);
    printf("Nota: %.1f\n", alunos[2].nota);
    
    return 0;
}