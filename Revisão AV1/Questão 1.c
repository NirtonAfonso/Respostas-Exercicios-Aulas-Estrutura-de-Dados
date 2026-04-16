#include <stdio.h>

int main(void) {
    // a) Declaração da variável normal. O sistema reserva um espaço na memória para ela.
    int x = 10;
    
    // b) O operador '&' significa "endereço de". 
    // Aqui criamos o ponteiro 'p' e guardamos dentro dele o endereço físico onde 'x' está na memória.
    int *p = &x; 

    // Letra a do enunciado: Imprimir o endereço de x.
    // Usamos o especificador de formato '%p' (de pointer) para imprimir endereços.
    // O (void*) é um cast de segurança recomendado pela linguagem C ao imprimir endereços.
    printf("a) O endereco de x na memoria eh: %p\n", (void*)&x);

    // Letra b do enunciado: Imprimir o valor de x usando o ponteiro.
    // O operador '*' antes de um ponteiro significa "conteúdo apontado por".
    // Ou seja, "vá até o endereço que p guarda e pegue o valor que está lá".
    printf("b) O valor de x acessado via ponteiro p eh: %d\n", *p);

    // Letra c do enunciado: Imprimir o endereço armazenado em p.
    // Como 'p' guarda o endereço de 'x', o resultado aqui DEVE ser idêntico ao da letra 'a'.
    printf("c) O endereco que esta guardado dentro de p eh: %p\n", (void*)p);

    return 0;
}