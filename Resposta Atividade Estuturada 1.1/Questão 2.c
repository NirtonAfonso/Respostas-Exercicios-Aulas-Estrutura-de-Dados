#include <stdio.h>
#include <string.h>

// a) Definição do tipo abstrato de dado Planta.
struct Planta {
    char especie[50];
    int diasSemAgua;
    char statusRega; // 'N' para necessita de água, 'O' para ok
};

// b) Implementação: Função que recebe um PONTEIRO para a struct Planta.
// Em C, se não usarmos ponteiros, a função receberia apenas uma CÓPIA da planta.
// Usando o ponteiro (struct Planta *p), recebemos o endereço de memória da variável original,
// permitindo alterá-la de verdade.
void regarPlanta(struct Planta *p) {
    // Como 'p' é um ponteiro, NÃO podemos usar o ponto final (p.diasSemAgua).
    // O operador SETA (->) serve exatamente para isso: acessar um campo através de um ponteiro.
    if (p->diasSemAgua >= 3) {
        // Zeramos a contagem de dias
        p->diasSemAgua = 0;
        // Alteramos o status para 'O' (Ok)
        p->statusRega = 'O';
        printf("\n[SISTEMA] Planta regada com sucesso!\n\n");
    } else {
        printf("\n[SISTEMA] A planta ainda nao precisa de agua.\n\n");
    }
}

int main() {
    // c) Declaração de uma variável isolada (não é um vetor).
    struct Planta minhaPlanta;

    // Inicialização hardcoded (direta no código)
    // Usamos strcpy para strings. Para números e caracteres simples, usamos =
    strcpy(minhaPlanta.especie, "Samambaia");
    minhaPlanta.diasSemAgua = 4;
    minhaPlanta.statusRega = 'N';

    // d) Passo 1: Imprimindo o estado atual (antes da função)
    printf("--- ANTES DA REGA ---\n");
    printf("Especie: %s\n", minhaPlanta.especie);
    printf("Dias sem agua: %d\n", minhaPlanta.diasSemAgua);
    printf("Status de Rega: %c\n", minhaPlanta.statusRega);

    // d) Passo 2: Chamada da função por referência.
    // O operador E COMERCIAL (&) extrai o "endereço de memória" da variável minhaPlanta
    // e entrega para a função regarPlanta (que espera justamente um ponteiro).
    regarPlanta(&minhaPlanta);

    // d) Passo 3: Imprimindo o estado depois da chamada para comprovar a mutação.
    // Se não tivéssemos usado ponteiro na função, os dados aqui continuariam iguais ao Passo 1.
    printf("--- DEPOIS DA REGA ---\n");
    printf("Especie: %s\n", minhaPlanta.especie);
    printf("Dias sem agua: %d\n", minhaPlanta.diasSemAgua);
    printf("Status de Rega: %c\n", minhaPlanta.statusRega);

    return 0;
}