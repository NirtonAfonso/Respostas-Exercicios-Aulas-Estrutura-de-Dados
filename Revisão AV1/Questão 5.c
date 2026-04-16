#include <stdio.h>

// Assinatura da função exigida pelo enunciado: não pode ter retorno (void)
void troca(int *a, int *b);

int main(void) {
    int x = 10, y = 50;

    printf("ESTADO INICIAL:\n");
    printf("x = %d | y = %d\n", x, y);

    // Enviamos os endereços das variáveis para que a função possa manipulá-las.
    troca(&x, &y);

    printf("\nESTADO FINAL (Apos Troca):\n");
    printf("x = %d | y = %d\n", x, y);

    return 0;
}

void troca(int *a, int *b) {
    // Lógica crucial: Se fizermos *a = *b direto, perderemos o valor original de 'a'.
    // Portanto, criamos uma variável temporária normal (int) para "salvar" o valor de 'a'.
    int temp = *a;

    // Agora que o valor de 'a' está salvo, podemos sobrescrever a memória de 'a'
    // com o conteúdo de 'b'.
    *a = *b;

    // Por fim, a memória de 'b' recebe o valor original de 'a' que estava salvo em 'temp'.
    *b = temp;
}