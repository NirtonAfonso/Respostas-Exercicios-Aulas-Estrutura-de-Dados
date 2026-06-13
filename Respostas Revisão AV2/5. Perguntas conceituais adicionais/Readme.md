Abaixo está o **tópico 5 completo**, no mesmo estilo dos anteriores, com linguagem simples e mais didática. Esse tópico da lista pede passagem por valor/referência e variáveis globais/locais, relacionando com o programa da Atividade Estruturada 2.

# Gabarito Comentado – Tópico 5

## Perguntas Conceituais Adicionais

---

# 5.1 Questão 1

## Passagem por valor e passagem por referência

## Enunciado

Na linguagem C, o que significa **passagem por valor** e **passagem por referência** através de ponteiros? Dê exemplos práticos e explique qual opção permite que uma função modifique variáveis definidas na função `main`.

---

## Resposta comentada

Na linguagem C, quando chamamos uma função e enviamos uma variável como parâmetro, existem duas formas principais de trabalhar com esse valor:

* passagem por valor;
* passagem por referência, usando ponteiros.

A diferença principal entre elas está em saber se a função recebe uma **cópia do valor** ou se recebe o **endereço da variável original**.

---

## 1) Passagem por valor

Na **passagem por valor**, a função recebe apenas uma cópia do valor da variável.

Isso significa que, se a função alterar esse parâmetro, ela altera somente a cópia.
A variável original, que está na função `main`, não é modificada.

Exemplo:

```c
#include <stdio.h>

/*
    Função alterarPorValor

    O parâmetro numero recebe uma cópia do valor enviado pela main.

    Se a main enviar uma variável que vale 10, essa função recebe uma cópia
    com o valor 10.

    Alterar numero aqui dentro não altera a variável original da main.
*/
void alterarPorValor(int numero) {

    /*
        Esta alteração acontece apenas na cópia local da função.
    */
    numero = numero + 5;

    printf("Dentro da função alterarPorValor: %d\n", numero);
}

int main(void) {

    /*
        Variável original criada dentro da main.
    */
    int x = 10;

    printf("Antes da função: %d\n", x);

    /*
        Chamada da função.

        Aqui passamos x sem &.

        Isso significa que o valor de x será copiado para o parâmetro numero.
    */
    alterarPorValor(x);

    /*
        Mesmo depois da função, x continua valendo 10.

        A função alterou apenas a cópia.
    */
    printf("Depois da função: %d\n", x);

    return 0;
}

/*
    Saída esperada:

    Antes da função: 10
    Dentro da função alterarPorValor: 15
    Depois da função: 10

    Explicação:

    O valor 10 foi copiado para a função.
    Dentro da função, a cópia virou 15.
    Porém, a variável x da main continuou valendo 10.

    Isso acontece porque foi usada passagem por valor.
*/
```

---

## Explicação detalhada da passagem por valor

Observe esta linha:

```c
alterarPorValor(x);
```

Como foi passado apenas `x`, sem o operador `&`, a função recebe uma cópia do valor.

A função recebe:

```c
void alterarPorValor(int numero)
```

Nesse caso, `numero` é uma variável local da função `alterarPorValor`.

Ela só existe enquanto essa função está executando.

Quando a função termina, essa variável local deixa de existir.

Por isso, qualquer alteração feita em `numero` não altera `x`.

Em resumo:

```c
x      -> variável original da main
numero -> cópia criada dentro da função
```

Se alterar `numero`, `x` não muda.

---

## 2) Passagem por referência usando ponteiro

Na **passagem por referência**, a função recebe o endereço da variável original.

Em C, fazemos isso usando ponteiros.

Para passar o endereço de uma variável, usamos o operador `&`.

Exemplo:

```c
alterarPorReferencia(&x);
```

O símbolo `&` significa “endereço de”.

Então, `&x` significa:

```c
endereço da variável x
```

Dentro da função, usamos um ponteiro para receber esse endereço:

```c
void alterarPorReferencia(int *numero)
```

O símbolo `*` indica que `numero` é um ponteiro para inteiro.

Ou seja, ele não guarda diretamente um número inteiro comum.
Ele guarda o endereço de uma variável inteira.

---

## Exemplo de passagem por referência

```c
#include <stdio.h>

/*
    Função alterarPorReferencia

    O parâmetro int *numero recebe o endereço de uma variável inteira.

    Como a função recebe o endereço, ela consegue alterar a variável original.
*/
void alterarPorReferencia(int *numero) {

    /*
        *numero significa:
        "acesse o valor que está no endereço guardado pelo ponteiro numero".

        Se numero aponta para x, então *numero representa o próprio x.
    */
    *numero = *numero + 5;

    printf("Dentro da função alterarPorReferencia: %d\n", *numero);
}

int main(void) {

    int x = 10;

    printf("Antes da função: %d\n", x);

    /*
        Aqui usamos &x.

        Isso significa que estamos passando o endereço da variável x,
        não apenas uma cópia do seu valor.
    */
    alterarPorReferencia(&x);

    /*
        Agora x foi alterado pela função.
    */
    printf("Depois da função: %d\n", x);

    return 0;
}

/*
    Saída esperada:

    Antes da função: 10
    Dentro da função alterarPorReferencia: 15
    Depois da função: 15

    Explicação:

    A função recebeu o endereço de x.
    Dentro da função, *numero acessou diretamente a variável x.
    Por isso, a alteração feita dentro da função modificou o valor original.
*/
```

---

## Explicação detalhada da passagem por referência

Observe a chamada:

```c
alterarPorReferencia(&x);
```

O `&x` envia o endereço da variável `x`.

A função recebe esse endereço aqui:

```c
void alterarPorReferencia(int *numero)
```

Dentro da função, `numero` é um ponteiro.

Para acessar ou alterar o valor que está nesse endereço, usamos:

```c
*numero
```

Então:

```c
*numero = *numero + 5;
```

significa:

1. vá até o endereço guardado em `numero`;
2. leia o valor que existe nesse endereço;
3. some 5;
4. grave o novo valor nesse mesmo endereço.

Como esse endereço é o endereço de `x`, a variável `x` da função `main` é alterada.

---

## Diferença entre `&` e `*`

Esses dois símbolos aparecem muito quando usamos passagem por referência.

## Operador `&`

O operador `&` pega o endereço de uma variável.

Exemplo:

```c
&x
```

Significa:

```c
endereço de x
```

Usamos `&` na chamada da função quando queremos permitir que a função altere a variável original.

Exemplo:

```c
alterarPorReferencia(&x);
```

---

## Operador `*`

O operador `*`, quando usado com ponteiro, acessa o valor que está no endereço.

Exemplo:

```c
*numero
```

Significa:

```c
valor armazenado no endereço apontado por numero
```

Se `numero` aponta para `x`, então `*numero` acessa o valor de `x`.

---

## O que aconteceria se fosse feito diferente?

Se a função deveria alterar uma variável da `main`, mas usássemos passagem por valor, a alteração não teria efeito fora da função.

Exemplo incorreto para alterar o valor original:

```c
void alterar(int numero) {
    numero = 100;
}
```

Chamando assim:

```c
int x = 10;
alterar(x);
```

`x` continuará valendo `10`.

Isso acontece porque `numero` é só uma cópia.

Para alterar `x`, o correto seria:

```c
void alterar(int *numero) {
    *numero = 100;
}
```

E a chamada deve ser:

```c
alterar(&x);
```

Se esquecermos o `&` na chamada, o programa não estará passando o endereço corretamente.

Se esquecermos o `*` dentro da função, estaremos mexendo no ponteiro em vez de mexer no valor apontado.

---

## Relação com listas, pilhas e filas

Nas atividades de listas, pilhas e filas, usamos ponteiros para alterar variáveis de controle.

Exemplos:

```c
void inserir(int v[], int valor, int *quantidade)
```

Nesse caso, `quantidade` precisa ser ponteiro porque a função de inserção aumenta a quantidade de elementos.

Outro exemplo:

```c
void push(int pilha[], int *topo, int valor)
```

Nesse caso, `topo` precisa ser ponteiro porque, ao empilhar, o topo muda.

Outro exemplo:

```c
void enfileirar(int fila[], int *fim, int valor)
```

Nesse caso, `fim` precisa ser ponteiro porque, ao enfileirar, o fim da fila avança.

Se essas variáveis fossem passadas por valor, a função até mudaria a cópia, mas a variável original da `main` continuaria igual. O programa não funcionaria corretamente.

---

## Resumo da questão 1

A **passagem por valor** envia uma cópia do valor para a função.
A função pode alterar essa cópia, mas a variável original não muda.

A **passagem por referência**, feita com ponteiros, envia o endereço da variável.
Assim, a função pode alterar diretamente a variável original.

Quando queremos que uma função modifique uma variável da `main`, devemos usar passagem por referência.

Exemplo:

```c
void funcao(int *x) {
    *x = *x + 1;
}
```

Chamada:

```c
funcao(&variavel);
```

---

# 5.2 Questão 2

## Variáveis globais e variáveis locais

## Enunciado

Diferencie variáveis globais de variáveis locais. Em que situações o uso de variáveis globais pode causar problemas? Referencie o programa da Atividade Estruturada 2 na análise.

---

## Resposta comentada

Na linguagem C, as variáveis podem ser declaradas em diferentes partes do programa.

Dependendo de onde uma variável é declarada, ela pode ser:

* variável global;
* variável local.

Essa diferença é importante porque define onde a variável pode ser usada e por quanto tempo ela existe na memória.

---

# 1) Variável global

Uma **variável global** é declarada fora de todas as funções.

Exemplo:

```c
#include <stdio.h>

int x = 20;

int main(void) {
    printf("%d", x);
    return 0;
}
```

Nesse exemplo, `x` é uma variável global porque foi declarada fora da função `main`.

Uma variável global pode ser acessada por várias funções do programa.

Exemplo:

```c
#include <stdio.h>

int x = 20;

void alterarX(void) {
    x++;
}

int main(void) {
    alterarX();
    printf("%d", x);
    return 0;
}
```

Nesse caso, a função `alterarX` consegue modificar `x`, mesmo `x` não tendo sido declarado dentro dela.

Isso acontece porque `x` é global.

---

## Vantagem da variável global

Uma variável global pode facilitar o acesso a um valor usado por várias funções.

Porém, esse uso deve ser feito com cuidado.

---

## Problema da variável global

O problema é que qualquer função pode alterar uma variável global.

Isso pode dificultar a leitura e a manutenção do código.

Exemplo:

```c
int x = 20;

void funcao1(void) {
    x++;
}

void funcao2(void) {
    x = 0;
}

void funcao3(void) {
    x--;
}
```

Nesse caso, várias funções podem modificar `x`.

Se o valor de `x` aparecer errado em algum momento, pode ser difícil descobrir qual função causou o problema.

Por isso, variáveis globais podem tornar o programa mais difícil de acompanhar.

---

# 2) Variável local

Uma **variável local** é declarada dentro de uma função ou dentro de um bloco.

Exemplo:

```c
void exemplo(void) {
    int numero = 10;
}
```

A variável `numero` só existe dentro da função `exemplo`.

Ela não pode ser usada diretamente em outra função.

Exemplo incorreto:

```c
void exemplo(void) {
    int numero = 10;
}

int main(void) {
    printf("%d", numero);
}
```

Esse código está errado, porque `numero` foi criada dentro da função `exemplo`.
A função `main` não conhece essa variável.

---

## Escopo de uma variável local

O **escopo** é a região do programa onde a variável existe e pode ser acessada.

Se uma variável foi criada dentro de uma função, seu escopo é aquela função.

Exemplo:

```c
void funcao(void) {
    int valor = 100;
}
```

A variável `valor` só existe dentro de `funcao`.

Quando a função termina, essa variável deixa de existir.

---

# 3) Referência ao programa da Atividade Estruturada 2

O programa da Atividade Estruturada 2 usa uma variável global chamada `x` e várias variáveis locais.

O programa segue a seguinte ideia:

```c
#include <stdio.h>

void Teste1(int);
void Teste2(int *);
int Teste3(int);

int x = 20;

int main(void) {
    int numero = 10, outroNumero;

    Teste1(numero);
    printf("Valor de numero (apos Teste1) = %d\n", numero);
    printf("X = %d\n", x);

    Teste2(&numero);
    printf("Valor de numero (apos Teste2) = %d\n", numero);
    printf("X = %d\n", x);

    outroNumero = Teste3(numero);
    printf("Valor de outro numero (apos Teste3) = %d\n", outroNumero);
    printf("X = %d\n", x);

    return 0;
}

void Teste1(int numero) {
    numero = numero + x;
    x++;
}

void Teste2(int *numero) {
    int valor = 100;
    *numero = *numero + valor;
    x++;
}

int Teste3(int n) {
    int valor = 200;
    n = n + valor;
    x--;
    return n;
}
```

---

# 4) Identificação das variáveis globais e locais

## Variável global

```c
int x = 20;
```

A variável `x` é global porque foi declarada fora de todas as funções.

Ela pode ser acessada e alterada por:

* `main`;
* `Teste1`;
* `Teste2`;
* `Teste3`.

Isso significa que todas essas funções enxergam a mesma variável `x`.

Se uma função altera `x`, essa alteração permanece para as próximas funções.

---

## Variáveis locais da função `main`

```c
int numero = 10, outroNumero;
```

As variáveis `numero` e `outroNumero` são locais da função `main`.

Elas só existem dentro da `main`.

A variável `numero` começa valendo `10`.

A variável `outroNumero` será usada depois para receber o retorno da função `Teste3`.

---

## Variável local da função `Teste1`

```c
void Teste1(int numero)
```

A variável `numero` que aparece em `Teste1` é local dessa função.

Mesmo tendo o mesmo nome da variável `numero` da `main`, ela não é a mesma variável.

Esse é um ponto importante.

Na chamada:

```c
Teste1(numero);
```

o valor de `numero` da `main` é copiado para o parâmetro `numero` da função `Teste1`.

Então existem duas variáveis diferentes:

```c
numero da main
numero da Teste1
```

Alterar o `numero` dentro de `Teste1` não altera o `numero` da `main`.

---

## Variáveis locais da função `Teste2`

```c
void Teste2(int *numero)
```

Aqui, `numero` é um ponteiro local da função `Teste2`.

Ele recebe o endereço da variável `numero` da `main`.

Dentro de `Teste2`, também existe:

```c
int valor = 100;
```

A variável `valor` é local da função `Teste2`.

Ela só existe enquanto `Teste2` está sendo executada.

---

## Variáveis locais da função `Teste3`

```c
int Teste3(int n)
```

A variável `n` é local da função `Teste3`.

Ela recebe uma cópia do valor enviado pela `main`.

Dentro de `Teste3`, também existe:

```c
int valor = 200;
```

A variável `valor` é local da função `Teste3`.

Ela só existe durante a execução da função.

---

# 5) Tipos de passagem de parâmetros no programa

## Função `Teste1`

```c
void Teste1(int numero)
```

Essa função recebe `numero` por valor.

Isso significa que ela recebe uma cópia.

Dentro da função:

```c
numero = numero + x;
```

altera apenas o `numero` local da função.

Não altera o `numero` da `main`.

Mas esta linha:

```c
x++;
```

altera a variável global `x`.

---

## Função `Teste2`

```c
void Teste2(int *numero)
```

Essa função recebe um ponteiro.

Na chamada:

```c
Teste2(&numero);
```

a função recebe o endereço da variável `numero` da `main`.

Dentro da função:

```c
*numero = *numero + valor;
```

o uso de `*numero` acessa o conteúdo da variável original.

Por isso, essa função altera o `numero` da `main`.

Ela também altera a variável global:

```c
x++;
```

---

## Função `Teste3`

```c
int Teste3(int n)
```

Essa função recebe `n` por valor.

Ou seja, recebe uma cópia.

Dentro da função:

```c
n = n + valor;
```

altera apenas a variável local `n`.

Mas, ao final, a função retorna esse valor:

```c
return n;
```

Por isso, a `main` consegue guardar o resultado em:

```c
outroNumero = Teste3(numero);
```

A função também altera a variável global:

```c
x--;
```

---

# 6) Análise passo a passo do programa

## Estado inicial

Antes de chamar qualquer função:

```c
x = 20
numero = 10
```

A variável `x` é global.

A variável `numero` pertence à `main`.

---

## Chamada de `Teste1(numero)`

A função é chamada assim:

```c
Teste1(numero);
```

Como `Teste1` recebe por valor, ela recebe uma cópia de `numero`.

Dentro de `Teste1`:

```c
numero = numero + x;
```

Nesse momento:

```c
numero local = 10
x = 20
```

Então:

```c
numero local = 10 + 20
numero local = 30
```

Mas esse `numero` é local da função `Teste1`.

O `numero` da `main` continua valendo:

```c
numero da main = 10
```

Depois:

```c
x++;
```

Então:

```c
x = 21
```

Ao voltar para a `main`, será impresso:

```c
Valor de numero (apos Teste1) = 10
X = 21
```

---

## Chamada de `Teste2(&numero)`

Agora a função é chamada assim:

```c
Teste2(&numero);
```

Nesse caso, a função recebe o endereço de `numero`.

Dentro de `Teste2`:

```c
int valor = 100;
```

Então:

```c
valor = 100
```

Depois:

```c
*numero = *numero + valor;
```

Como `numero` é ponteiro, `*numero` representa a variável `numero` da `main`.

Antes da operação:

```c
numero da main = 10
valor = 100
```

Então:

```c
numero da main = 10 + 100
numero da main = 110
```

Depois:

```c
x++;
```

Como `x` estava valendo 21:

```c
x = 22
```

Ao voltar para a `main`, será impresso:

```c
Valor de numero (apos Teste2) = 110
X = 22
```

---

## Chamada de `Teste3(numero)`

Agora:

```c
numero da main = 110
x = 22
```

A chamada é:

```c
outroNumero = Teste3(numero);
```

A função `Teste3` recebe por valor.

Então `n` recebe uma cópia de `numero`.

Dentro de `Teste3`:

```c
n = 110
```

Depois:

```c
int valor = 200;
```

Então:

```c
valor = 200
```

Depois:

```c
n = n + valor;
```

Logo:

```c
n = 110 + 200
n = 310
```

Depois:

```c
x--;
```

Como `x` estava valendo 22:

```c
x = 21
```

A função retorna:

```c
return n;
```

Ou seja, retorna `310`.

Na `main`:

```c
outroNumero = 310;
```

Então será impresso:

```c
Valor de outro numero (apos Teste3) = 310
X = 21
```

---

# 7) Saída final do programa

A saída será:

```c
Valor de numero (apos Teste1) = 10
X = 21
Valor de numero (apos Teste2) = 110
X = 22
Valor de outro numero (apos Teste3) = 310
X = 21
```

---

# 8) Por que variáveis globais podem causar problemas?

O programa da Atividade Estruturada 2 mostra bem esse problema.

A variável `x` é global:

```c
int x = 20;
```

Ela é alterada em três funções:

```c
x++;
x++;
x--;
```

Isso significa que o valor de `x` depende da ordem em que as funções são chamadas.

Se alguém mudar a ordem das chamadas, o resultado final de `x` pode mudar.

Exemplo:

```c
Teste2(&numero);
Teste1(numero);
Teste3(numero);
```

Essa ordem poderia gerar outro comportamento para `x` e para os valores calculados.

Esse é o risco das variáveis globais: elas podem ser alteradas em vários pontos do programa, o que dificulta acompanhar o valor correto.

Em programas pequenos, isso ainda é fácil de seguir.
Mas em programas maiores, pode causar confusão.

Por isso, quando possível, é melhor usar variáveis locais e passar os valores por parâmetro.

---

# 9) Resumo da questão 2

Variável global é declarada fora das funções e pode ser acessada por várias funções.

Variável local é declarada dentro de uma função e só pode ser usada dentro daquela função.

No programa da Atividade Estruturada 2:

```c
int x = 20;
```

é global.

As variáveis:

```c
numero
outroNumero
valor
n
```

são locais, dependendo da função em que aparecem.

O uso de variável global pode causar problemas porque qualquer função pode alterar seu valor. Isso dificulta o controle do programa e pode gerar erros difíceis de encontrar.

A passagem por referência, usada em `Teste2`, permite alterar diretamente uma variável da `main`.
A passagem por valor, usada em `Teste1` e `Teste3`, trabalha apenas com cópias, a menos que o valor seja retornado pela função.

---

# Fechamento do tópico 5

Este tópico reforça dois pontos muito importantes para entender funções em C:

1. **Passagem de parâmetros**

   * Por valor: a função recebe uma cópia.
   * Por referência: a função recebe o endereço e pode alterar a variável original.

2. **Escopo de variáveis**

   * Global: pode ser usada por várias funções.
   * Local: pertence apenas à função onde foi declarada.

Esses conceitos aparecem diretamente nas listas, pilhas e filas, principalmente quando usamos ponteiros para atualizar variáveis como:

```c
quantidade
topo
inicio
fim
```

Sempre que uma função precisa alterar uma dessas variáveis originais, usamos ponteiro.
