#include <stdio.h>

int main(void) {
    // Declaração das variáveis normais exigidas pelo enunciado.
    float v1, v2, soma;

    // Criação dos ponteiros e associação aos endereços das variáveis.
    // Lembrete aos alunos: p1 agora "enxerga" a mesma casa de memória que v1.
    float *p1 = &v1;
    float *p2 = &v2;
    float *pSoma = &soma;

    printf("Digite o primeiro valor float: ");
    // Realizamos a leitura da forma clássica, passando o endereço da variável normal (&v1).
    // O valor digitado será guardado diretamente na memória de v1.
    scanf("%f", &v1);

    printf("Digite o segundo valor float: ");
    // Mesma coisa para v2.
    scanf("%f", &v2);

    // Agora vem a exigência do enunciado: o cálculo via ponteiros.
    // Como p1 e p2 estão apontando para v1 e v2, '*p1' e '*p2' vão acessar
    // os valores que o usuário acabou de digitar.
    // Lemos os conteúdos (*p1 e *p2), somamos, e guardamos o resultado no conteúdo de pSoma.
    *pSoma = *p1 + *p2;

    // Imprimindo o resultado lendo o conteúdo apontado pelo ponteiro de soma.
    printf("\n--> A soma dos valores eh: %.2f\n", *pSoma);

    return 0;
}