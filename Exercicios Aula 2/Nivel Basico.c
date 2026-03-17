/*

Nível Básico
Calculadora de IMC: Peça
ao usuário o peso (float)
e a altura (float). Calcule
o IMC e use if/else para
imprimir se está no peso
ideal.

*/


#include <stdio.h>

int main() {
    // 1. Declaramos as variáveis para guardar as informações do usuário
    float peso;
    float altura;
    float imc;

    // 2. Pedimos os dados e guardamos nas variáveis correspondentes
    printf("Digite o seu peso em kg (ex: 70.5): ");
    scanf("%f", &peso);

    printf("Digite a sua altura em metros (ex: 1.75): ");
    scanf("%f", &altura);

    // 3. Calculamos o IMC (Peso dividido pela altura ao quadrado)
    imc = peso / (altura * altura);

    printf("O seu IMC e: %.2f\n", imc); // %.2f limita a resposta a duas casas decimais

    // 4. Estrutura de decisão para verificar se o IMC está no padrão ideal (entre 18.5 e 24.9)
    if (imc >= 18.5 && imc <= 24.9) {
        printf("Resultado: Voce esta no seu peso ideal! Parabens.\n");
    } else {
        printf("Resultado: Voce esta fora da faixa de peso ideal.\n");
    }

    return 0;
}