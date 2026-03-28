// Ponteiro para Struct
#include <stdio.h>

struct aluno {
    int matricula;
    float nota;
};

int main(void) {
    // Declara dois alunos "a" e "b"
    struct aluno a, b;
    // Declara um ponteiro para um aluno
    struct aluno *p;

    a.matricula = 12011410;
    a.nota = 7.5;

    p = &a;     // Aponta "p" para o endereço de "a"
    b = a;      // Copia "a" para "b"

    // NÃO esqueça dos parênteses ao redor do (*p) !
    (*p).matricula = 13011410;  // Modifica matricula do aluno apontado por "p"
    (*p).nota = 9.5;            // Modifica nota do aluno apontado por "p"

   // Observe os valores impressos
    printf("   a.matr vale: %d\n", a.matricula);
    printf("   a.nota vale: %.1f\n", a.nota);
    printf("   b.matr vale: %d\n", b.matricula);
    printf("   b.nota vale: %.1f\n", b.nota);
    printf("(*p).matr vale: %d\n", (*p).matricula);
    printf("(*p).nota vale: %.1f\n", (*p).nota);

    // Observe os endereços
    printf("&a: %p\n", (void*)&a);
    printf("&b: %p\n", (void*)&b);
    printf(" p: %p\n", (void*)p);

    return 0;
}