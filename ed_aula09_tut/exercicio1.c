// EXERCICIO 1
// Modidique esse programa para que apenas os alunos com
// nota igual ou superior a 6.0 tenham sua matrícula exibida

#include <stdio.h>

#define MAX 50

struct aluno {
    int matricula;
    float nota;
};

void imprime(struct aluno v[], int num);

int main(void) {
    // Declara um array de alunos
    struct aluno alunos[MAX];

    alunos[0].matricula = 12014432;
    alunos[0].nota = 7.5;
    alunos[1].matricula = 13022301;
    alunos[1].nota = 5.9;
    alunos[2].matricula = 11024122;
    alunos[2].nota = 4.0;
    alunos[3].matricula = 11014120;
    alunos[3].nota = 6.1;
    alunos[4].matricula = 11024012;
    alunos[4].nota = 8.0;
    alunos[5].matricula = 11014117;
    alunos[5].nota = 3.5;

    imprime(alunos, 6);

    return 0;
}

void imprime(struct aluno v[], int num) {
    int i;

    for (i = 0; i < num; i++) {
        printf("Mat.: %d\n", v[i].matricula);
        printf("Nota: %.1f\n", v[i].nota);
    }
}