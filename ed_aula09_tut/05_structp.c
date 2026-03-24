#include <stdio.h>

#define MAX 50

struct _aluno {
    int matricula;
    float nota;
};

int empilhar(struct _aluno v[], int *topo, struct _aluno aluno);
int desempilhar(struct _aluno v[], int *topo, struct _aluno *aluno);

int main(void) {
    // Declara um aluno
    struct _aluno alunos[MAX];
    int talunos = -1;
    struct _aluno temp;

    temp.matricula = 12014432;
    temp.nota = 7.5;
    empilhar(alunos, &talunos, temp);

    temp.matricula = 13022301;
    temp.nota = 5.7;
    empilhar(alunos, &talunos, temp);

    temp.matricula = 11024122;
    temp.nota = 9.0;
    empilhar(alunos, &talunos, temp);

    while(desempilhar(alunos, &talunos, &temp) == 0) {
        printf("Mat.: %d\n", temp.matricula);
        printf("Nota: %.1f\n", temp.nota);
    }

    return 0;
}

// Empilha um valor
int empilhar(struct _aluno v[], int *topo, struct _aluno valor) {
    if (*topo >= MAX - 1) {
        printf("ERRO: Pilha cheia!\n");
        return 1;
    }
    *topo = *topo + 1;
    v[*topo] = valor;
    return 0;
}

// Desempilha um valor
int desempilhar(struct _aluno v[], int *topo, struct _aluno *valor) {
    if (*topo < 0) {
        printf("ERRO: Pilha vazia!\n");
        return 1;
    }
    *valor = v[*topo];
    *topo = *topo - 1;
    return 0;
}