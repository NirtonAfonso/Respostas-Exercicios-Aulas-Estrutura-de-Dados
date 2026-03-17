/*
Nível Avançado

Menu Interativo: Crie uma tela usando printf e switch-case com opções (1-Saudação, 2-Data, 3- Sair). Coloque tudo dentro de um do-while para manter o menu ativo até a escolha 3.
*/


#include <stdio.h>

int main() {
    int opcao;

    // 1. O 'do-while' garante que o menu seja mostrado pelo menos UMA vez
    do {
        printf("\n****** MENU INTERATIVO *********\n");
        printf("1 - Saudacao\n");
        printf("2 - Data\n");
        printf("3 - Sair\n");

        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        // 2. O 'switch' avalia a opção escolhida e vai direto para o bloco correspondente
        switch (opcao) {
            case 1:
                printf("\nHello Word!\n");
                break; // O break impede que o programa execute os códigos das opções de baixo
            case 2:
                printf("\nA data de hoje eh 10/03/2026\n");
                break;
            case 3:
                printf("\nVoce escolheu sair!\n");
                break;
            default:
                // O 'default' serve para capturar qualquer número que não seja 1, 2 ou 3
                printf("\nOpcao invalida! Por favor, tente novamente.\n");
        }

    } while (opcao != 3); // O laço só termina se a opção for exatamente 3

    return 0;
}