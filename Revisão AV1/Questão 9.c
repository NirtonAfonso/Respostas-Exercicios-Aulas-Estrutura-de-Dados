#include <stdio.h>

// Molde do jogador.
struct Jogador {
    int pontos;
    int nivel;
};

// Prototipação. A função precisa alterar os dados originais,
// logo, ela deve receber um ponteiro para a struct.
void ganhar_ponto(struct Jogador *j);

int main(void) {
    // Inicialização direta da struct: O primeiro valor vai para 'pontos', o segundo para 'nivel'.
    // Começamos o teste perto do limite (8 pontos) para facilitar a verificação da regra.
    struct Jogador player1 = {8, 1};

    printf("STATUS INICIAL: Nivel %d | Pontos: %d\n", player1.nivel, player1.pontos);

    // Simulação do jogo chamando a função e passando o ENDEREÇO do jogador.
    printf("\n> O jogador pegou 3 itens de ponto no mapa...\n");
    ganhar_ponto(&player1); // Pontos vão para 9
    ganhar_ponto(&player1); // Pontos vão para 10 -> Ativa a regra de subida de nível
    ganhar_ponto(&player1); // Ganha o primeiro ponto do nível 2

    // Verificação do estado final após as chamadas da função.
    printf("\nSTATUS FINAL: Nivel %d | Pontos: %d\n", player1.nivel, player1.pontos);

    return 0;
}

// Implementação da função
void ganhar_ponto(struct Jogador *j) {
    // Acessa a memória original do jogador via seta (->) e incrementa os pontos.
    j->pontos++;

    // Regra do enunciado: "caso os pontos cheguem a 10, suba o nível".
    if (j->pontos == 10) {
        j->nivel++;       // Sobe o nível em 1
        j->pontos = 0;    // Reseta os pontos para o novo nível
        printf("   [ALERTA] Parabens! Voce subiu para o nivel %d!\n", j->nivel);
    }
}