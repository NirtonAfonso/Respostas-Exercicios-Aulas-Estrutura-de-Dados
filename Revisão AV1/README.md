# Revisão focada em Ponteiros para AV1

1. Declare uma variável inteira `x = 10` e um ponteiro `p`. Faça `p` apontar para `x`. Escreva os comandos para imprimir:

   a) O endereço de `x`.

   b) O valor de `x` usando o ponteiro `p`.

   c) O endereço armazenado em `p`.

2. Dado o código:

   ```c
   int a = 5, b = 15;
   int *p1, *p2;
   p1 = &a;
   p2 = &b;
   ```

   Como você alteraria o valor de `a` para `100` e o valor de `b` para `200` usando apenas `p1` e `p2`?

3. Escreva um trecho de código que declare duas variáveis `float`, peça ao usuário para digitar os valores e, em seguida, use apenas ponteiros para calcular e exibir a soma delas.

4. Crie uma função chamada `eleva_ao_quadrado(int *n)` que receba um ponteiro para um inteiro e substitua o valor original pelo seu quadrado.

5. Implemente a função `void troca(int *a, int *b)` que inverta os valores das duas variáveis passadas por parâmetro sem usar o comando `return`.

6. Escreva uma função `void divisao(int dividendo, int divisor, int *quociente, int *resto)`. Ela deve calcular ambos os resultados e armazená-los nas variáveis apontadas pelos ponteiros.

7. Crie uma função que receba dois ponteiros para inteiros, `p1` e `p2`, e "retorne" através de um terceiro ponteiro `maior` o endereço da variável que contém o maior valor.

8. Defina uma `struct Livro` com `id` (`int`) e `preco` (`float`). No `main`, declare um livro e um ponteiro para ele. Como você acessa e atribui valores aos campos do livro usando o ponteiro e o operador `->`?

9. Crie uma `struct Jogador` com os campos `pontos` (`int`) e `nivel` (`int`). Escreva uma função `void ganhar_ponto(struct Jogador *j)` que incremente o campo `pontos` em 1 e, caso os pontos cheguem a 10, suba o `nivel` do jogador em 1.
