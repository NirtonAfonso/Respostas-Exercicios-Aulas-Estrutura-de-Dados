# Listas Sequenciais Ordenadas

---

# 2.1 Questões teóricas

## 1) Explique a diferença entre uma lista sequencial ordenada e uma desordenada. Por que a inserção em uma lista ordenada não pode ser feita simplesmente no final?

Uma **lista sequencial desordenada** é uma lista armazenada em vetor na qual os elementos são colocados normalmente no final, sem preocupação com ordem crescente, decrescente ou qualquer outro critério.

Exemplo de lista desordenada:

```c
10   3   25   7   1
```

Essa lista é desordenada porque os valores aparecem na ordem em que foram inseridos. O valor `1`, por exemplo, aparece no final, mesmo sendo o menor valor.

Já uma **lista sequencial ordenada** também é armazenada em vetor, mas seus elementos precisam seguir uma ordem. Normalmente, trabalhamos com ordem crescente.

Exemplo de lista ordenada crescente:

```c
1   3   7   10   25
```

Nesse caso, os valores estão organizados do menor para o maior.

A principal diferença está na forma de inserir novos elementos.

Na lista desordenada, se quisermos inserir o valor `5`, podemos simplesmente colocar no final:

```c
10   3   25   7   1   5
```

Isso não causa problema, porque a lista não tem obrigação de estar ordenada.

Na lista ordenada, não podemos fazer isso. Se temos:

```c
1   3   7   10   25
```

e queremos inserir o valor `5`, ele não pode ser colocado no final:

```c
1   3   7   10   25   5
```

Essa lista deixaria de estar ordenada.

O correto seria inserir o `5` entre o `3` e o `7`:

```c
1   3   5   7   10   25
```

Por isso, em uma lista ordenada, a inserção precisa encontrar a posição correta do novo valor. Além disso, os elementos maiores precisam ser deslocados uma posição para a direita para abrir espaço.

Se esse deslocamento não for feito, o valor pode sobrescrever outro elemento ou a lista pode perder a ordenação.

---

## 2) Descreva a ideia de manter uma lista sempre ordenada no momento da inserção e como isso afeta o desempenho de buscas e remoções.

Manter uma lista sempre ordenada no momento da inserção significa que cada novo valor já deve ser colocado diretamente na posição correta.

Por exemplo, considere a lista:

```c
2   4   8   12
```

Se quisermos inserir o valor `6`, não devemos colocar no final. O valor `6` deve ficar entre `4` e `8`.

Resultado correto:

```c
2   4   6   8   12
```

Para fazer isso, o programa precisa:

1. procurar a posição correta;
2. deslocar os elementos maiores para a direita;
3. inserir o novo valor na posição aberta;
4. atualizar a quantidade de elementos da lista.

A vantagem de manter a lista ordenada é que a busca pode ser mais eficiente. Em vez de procurar elemento por elemento, podemos usar a **busca binária**, que aproveita a organização dos dados.

A desvantagem é que a inserção pode ser mais trabalhosa. Se o novo valor precisar entrar no início da lista, todos os elementos existentes precisarão ser deslocados uma posição para a direita.

Exemplo:

```c
10   20   30   40
```

Inserindo `5`, todos os elementos precisam andar para a direita:

```c
5   10   20   30   40
```

A remoção também pode exigir deslocamento. Se removemos um valor do meio da lista, os elementos posteriores precisam ser movidos para a esquerda para ocupar o espaço deixado.

Exemplo:

```c
1   3   5   7   9
```

Removendo `5`:

```c
1   3   7   9
```

Para isso acontecer no vetor, o `7` precisa ir para a posição do `5`, e o `9` precisa ir para a posição do `7`.

Em resumo:

* manter a lista ordenada melhora a busca;
* mas a inserção e a remoção podem exigir deslocamentos.

---

## 3) Por que a busca binária é mais eficiente que a busca linear em listas ordenadas? Descreva o funcionamento básico da busca binária.

A **busca linear** verifica os elementos um por um.

Exemplo:

```c
for (int i = 0; i < n; i++) {
    if (v[i] == valor) {
        return i;
    }
}
```

Ela funciona, mas pode precisar percorrer muitos elementos até encontrar o valor.

A **busca binária** é mais eficiente porque só pode ser usada quando a lista está ordenada. Ela não verifica todos os elementos um por um. Em vez disso, ela analisa o elemento do meio da lista.

Exemplo de lista ordenada:

```c
1   3   5   7   9   11   13
```

Se procuramos o valor `11`, o algoritmo faz o seguinte:

1. Define o início da busca como a primeira posição.
2. Define o fim da busca como a última posição.
3. Calcula a posição do meio.
4. Compara o valor do meio com o valor procurado.
5. Se forem iguais, encontrou.
6. Se o valor procurado for menor que o valor do meio, procura na metade esquerda.
7. Se o valor procurado for maior que o valor do meio, procura na metade direita.
8. Repete o processo até encontrar o valor ou até a área de busca acabar.

A busca binária é eficiente porque, a cada comparação, ela descarta metade da lista.

A busca binária só funciona porque a lista está ordenada. Se a lista estivesse desordenada, não seria possível saber se o valor está antes ou depois do meio.

Exemplo desordenado:

```c
20   4   90   7   15
```

Se olharmos o valor do meio, não conseguimos concluir com segurança para qual lado devemos ir. Por isso, nesse caso, a busca binária não deve ser usada.

---

## 4) Aponte vantagens de manter uma lista ordenada e suas desvantagens.

Manter uma lista ordenada traz algumas vantagens importantes.

A primeira vantagem é que a busca pode ser mais rápida, pois podemos usar busca binária. Como os dados estão organizados, o programa consegue descartar metade da lista a cada comparação.

Outra vantagem é que os dados ficam mais fáceis de visualizar. Quando imprimimos uma lista ordenada, os valores aparecem de forma organizada.

Exemplo:

```c
2   5   8   10   15
```

Isso facilita a leitura e também pode ajudar em outras operações.

A lista ordenada também facilita comparações entre conjuntos de dados, pois os valores seguem uma sequência lógica.

Porém, existem desvantagens.

A principal desvantagem é que inserir um novo valor pode exigir deslocamento de elementos. Se o novo valor entra no meio da lista, os elementos maiores precisam ser movidos para a direita.

Outra desvantagem é que a remoção também pode exigir deslocamento. Quando removemos um valor do meio, os elementos seguintes precisam ser movidos para a esquerda.

Além disso, o código costuma ser um pouco mais detalhado do que em uma lista desordenada, porque a posição correta precisa ser respeitada.

Em resumo:

* a lista ordenada facilita a busca;
* mantém os dados organizados;
* mas exige mais cuidado na inserção e na remoção.

---

# 2.2 Questões práticas

---

# Prática 1

## Inserção em lista ordenada crescente

## Enunciado

Escreva a função:

```c
void inserirCresc(float v[], int *n, int max, float valor)
```

A função deve inserir um valor em um vetor ordenado de `float`, mantendo a ordenação crescente. O algoritmo deve procurar a posição correta, deslocar os elementos à direita e inserir o valor.

## Código comentado

```c
#include <stdio.h>

/*
    Função inserirCresc

    Objetivo:
    Inserir um novo valor em uma lista que já está em ordem crescente.

    Parâmetros:

    float v[]:
        vetor que representa a lista ordenada.

    int *n:
        ponteiro para a quantidade de elementos válidos da lista.

    int max:
        tamanho máximo do vetor.

    float valor:
        valor que será inserido na lista.

    Por que n é ponteiro?

    Porque a função precisa aumentar a quantidade de elementos depois
    da inserção.

    Se n fosse passado sem ponteiro, a função alteraria apenas uma cópia
    da variável, e a quantidade original no main não seria atualizada.
*/
void inserirCresc(float v[], int *n, int max, float valor) {

    /*
        Primeiro verificamos se a lista está cheia.

        Se *n for igual ou maior que max, significa que não existe
        posição livre no vetor.
    */
    if (*n >= max) {
        printf("Lista cheia.\n");
        return;
    }

    /*
        Começamos a análise pelo último elemento válido da lista.

        Se a lista possui *n elementos, o último elemento está na posição:

            *n - 1

        Exemplo:
        Se *n vale 5, os índices válidos são:
        0, 1, 2, 3 e 4.

        O último índice é 4, que é *n - 1.
    */
    int i = *n - 1;

    /*
        Este while desloca os elementos maiores que o valor a ser inserido.

        Condição 1:
            i >= 0

        Essa condição impede que o índice fique negativo.

        Condição 2:
            v[i] > valor

        Essa condição verifica se o elemento atual é maior que o valor
        que queremos inserir.

        Enquanto o elemento atual for maior, ele precisa andar uma posição
        para a direita, para abrir espaço.
    */
    while (i >= 0 && v[i] > valor) {

        /*
            Copiamos o elemento da posição i para a posição i + 1.

            Isso desloca o elemento para a direita.

            Exemplo:
            v[i + 1] = v[i];

            Se i for 3, o elemento da posição 3 vai para a posição 4.
        */
        v[i + 1] = v[i];

        /*
            Depois de deslocar, voltamos uma posição para continuar verificando
            os elementos anteriores.
        */
        i--;
    }

    /*
        Quando o while termina, existem duas possibilidades:

        1. i ficou menor que 0:
           isso significa que o valor a ser inserido é menor que todos
           os elementos da lista.

        2. v[i] <= valor:
           isso significa que encontramos a posição anterior ao local
           correto de inserção.

        Em ambos os casos, o valor deve ser inserido na posição i + 1.
    */
    v[i + 1] = valor;

    /*
        Após inserir, aumentamos a quantidade de elementos válidos.
    */
    (*n)++;
}

/*
    Explicação final:

    A função inserirCresc mantém a lista em ordem crescente.

    Ela não insere diretamente no final porque isso poderia quebrar a ordem
    da lista.

    O algoritmo começa do final e desloca para a direita todos os elementos
    maiores que o novo valor.

    Se o novo valor for maior que todos os outros, nenhum deslocamento ocorre,
    e ele entra no final.

    Se o novo valor for menor que todos, todos os elementos são deslocados,
    e ele entra na posição 0.

    A variável n é passada por ponteiro porque a função precisa atualizar
    a quantidade de elementos após a inserção.
*/
```

---

# Prática 2

## Busca binária

## Enunciado

Implemente a função:

```c
int buscaBinaria(float v[], int n, float valor)
```

A função deve retornar o índice do valor no vetor ordenado ou `-1` caso ele não exista.

## Código comentado

```c
#include <stdio.h>

/*
    Função buscaBinaria

    Objetivo:
    Procurar um valor em uma lista ordenada.

    Parâmetros:

    float v[]:
        vetor ordenado em ordem crescente.

    int n:
        quantidade de elementos válidos no vetor.

    float valor:
        valor que será procurado.

    Retorno:
        retorna o índice se encontrar o valor.
        retorna -1 se o valor não existir na lista.
*/
int buscaBinaria(float v[], int n, float valor) {

    /*
        inicio representa o primeiro índice da região onde ainda estamos
        procurando.
    */
    int inicio = 0;

    /*
        fim representa o último índice da região onde ainda estamos procurando.

        Como os índices começam em 0, o último elemento válido está em n - 1.
    */
    int fim = n - 1;

    /*
        O laço continua enquanto a região de busca for válida.

        Se inicio passar de fim, significa que não há mais onde procurar.
    */
    while (inicio <= fim) {

        /*
            Calculamos a posição do meio.

            A divisão entre inteiros retorna um número inteiro.
            Por exemplo:

            (0 + 5) / 2 = 2

            Então meio recebe o índice central da região atual.
        */
        int meio = (inicio + fim) / 2;

        /*
            Se o valor do meio for exatamente o valor procurado,
            a busca terminou.
        */
        if (v[meio] == valor) {
            return meio;
        }

        /*
            Se o valor do meio for maior que o valor procurado,
            então o valor procurado, se existir, está antes do meio.

            Isso só é verdade porque a lista está ordenada.
        */
        if (v[meio] > valor) {

            /*
                Diminuímos o fim para ignorar a metade direita.
            */
            fim = meio - 1;
        }

        /*
            Caso contrário, o valor do meio é menor que o valor procurado.

            Então o valor procurado, se existir, está depois do meio.
        */
        else {

            /*
                Aumentamos o início para ignorar a metade esquerda.
            */
            inicio = meio + 1;
        }
    }

    /*
        Se o laço terminou sem retornar, o valor não foi encontrado.
    */
    return -1;
}

/*
    Explicação final:

    A busca binária só funciona em listas ordenadas.

    O algoritmo sempre compara o valor procurado com o elemento do meio.

    Se encontrar, retorna o índice.

    Se o valor procurado for menor, busca na metade esquerda.
    Se for maior, busca na metade direita.

    Se usássemos essa busca em uma lista desordenada, o resultado poderia
    estar errado, pois não seria possível decidir corretamente para qual lado
    continuar.

    O retorno -1 é usado para indicar que o valor não existe na lista.
*/
```

---

# Prática 3

## Remoção em lista ordenada

## Enunciado

Crie a função:

```c
void remover(float v[], int *n, float valor)
```

A função deve remover um valor específico de uma lista ordenada, deslocando os elementos subsequentes para a esquerda.

## Código comentado

```c
#include <stdio.h>

/*
    Função buscaBinaria

    Esta função será usada dentro da função remover.

    Primeiro procuramos o valor.
    Depois, se ele existir, fazemos a remoção.
*/
int buscaBinaria(float v[], int n, float valor) {

    int inicio = 0;
    int fim = n - 1;

    while (inicio <= fim) {

        int meio = (inicio + fim) / 2;

        if (v[meio] == valor) {
            return meio;
        }

        if (v[meio] > valor) {
            fim = meio - 1;
        } else {
            inicio = meio + 1;
        }
    }

    return -1;
}

/*
    Função remover

    Objetivo:
    Remover um valor específico da lista ordenada.

    Parâmetros:

    float v[]:
        vetor onde os valores estão armazenados.

    int *n:
        ponteiro para a quantidade de elementos.

    float valor:
        valor que deverá ser removido.

    Por que n é ponteiro?

    Porque, depois da remoção, a lista terá um elemento a menos.
    A função precisa alterar a quantidade original.
*/
void remover(float v[], int *n, float valor) {

    /*
        Primeiro procuramos a posição do valor usando busca binária.

        Se o valor existir, pos receberá o índice onde ele está.
        Se o valor não existir, pos receberá -1.
    */
    int pos = buscaBinaria(v, *n, valor);

    /*
        Se pos for -1, o valor não foi encontrado.

        Nesse caso, a função não deve tentar remover nada.
    */
    if (pos == -1) {
        printf("Valor %.2f não encontrado.\n", valor);
        return;
    }

    /*
        Para remover um valor do vetor, precisamos deslocar os elementos
        posteriores uma posição para a esquerda.

        Exemplo:

        Antes:
        índice:  0    1    2    3
        valor:  2    4    6    8

        Removendo o valor da posição 1:

        O valor da posição 2 vai para a posição 1.
        O valor da posição 3 vai para a posição 2.

        Depois:
        valor:  2    6    8
    */
    for (int i = pos; i < *n - 1; i++) {

        /*
            Copia o elemento da direita para a posição atual.
        */
        v[i] = v[i + 1];
    }

    /*
        Depois do deslocamento, diminuímos a quantidade.

        Mesmo que o último valor ainda esteja fisicamente no vetor,
        ele deixa de fazer parte da lista porque n foi reduzido.
    */
    (*n)--;
}

/*
    Explicação final:

    A função remover primeiro localiza o valor usando busca binária.

    Se o valor não existir, a função mostra uma mensagem e encerra.

    Se existir, os elementos posteriores são deslocados uma posição para
    a esquerda.

    Esse deslocamento é necessário porque, em uma lista sequencial, os
    elementos válidos devem continuar ocupando posições consecutivas.

    Se o deslocamento não fosse feito, ficaria uma posição inválida no meio
    da lista.

    A variável n é passada por ponteiro porque a quantidade precisa ser
    atualizada após a remoção.
*/
```

---

# Prática 4

## Bubble sort

## Enunciado

Dado um vetor desordenado de inteiros, escreva a função:

```c
void bubbleSort(int v[], int n)
```

A função deve ordenar o vetor em ordem crescente usando o método bubble sort. Explique nos comentários do programa por que esse algoritmo tem complexidade quadrática.

## Código comentado

```c
#include <stdio.h>

/*
    Função bubbleSort

    Objetivo:
    Ordenar um vetor de inteiros em ordem crescente.

    Parâmetros:

    int v[]:
        vetor que será ordenado.

    int n:
        quantidade de elementos válidos no vetor.
*/
void bubbleSort(int v[], int n) {

    /*
        O laço externo controla a quantidade de passagens pelo vetor.

        Em um vetor com n elementos, fazemos n - 1 passagens.

        Exemplo:
        Se n vale 5, fazemos 4 passagens.
    */
    for (int i = 0; i < n - 1; i++) {

        /*
            O laço interno compara pares de elementos vizinhos.

            A cada passagem completa, o maior valor que ainda não estava
            em sua posição correta vai para o final.

            Por isso usamos:

                n - 1 - i

            O -i evita comparar novamente os elementos que já foram
            organizados no final do vetor.
        */
        for (int j = 0; j < n - 1 - i; j++) {

            /*
                Comparamos o elemento atual com o próximo.

                Se v[j] for maior que v[j + 1], eles estão fora de ordem.
            */
            if (v[j] > v[j + 1]) {

                /*
                    Para trocar dois valores, precisamos de uma variável
                    temporária.

                    Se fizéssemos apenas:

                        v[j] = v[j + 1];

                    perderíamos o valor original de v[j].
                */
                int temp = v[j];

                /*
                    Agora colocamos o menor valor na posição da esquerda.
                */
                v[j] = v[j + 1];

                /*
                    E colocamos o valor guardado em temp na posição da direita.
                */
                v[j + 1] = temp;
            }
        }
    }
}

/*
    Explicação final:

    O bubble sort ordena o vetor comparando elementos vizinhos e trocando
    quando estão fora de ordem.

    O método usa dois laços for, um dentro do outro.

    O primeiro laço controla as passagens.
    O segundo laço faz as comparações dentro de cada passagem.

    Por haver um laço dentro de outro, a quantidade de comparações cresce
    de forma quadrática conforme o tamanho do vetor aumenta.

    Por isso, dizemos que o bubble sort tem complexidade O(n²).

    O bubble sort é simples de entender e implementar, mas não é o método
    mais eficiente para vetores muito grandes.
*/
```

---

# Prática 5

## Programa completo com lista ordenada

## Enunciado

Escreva um programa que:

* leia `n` números e armazene em um vetor;
* ordene o vetor com bubble sort;
* ofereça ao usuário um menu com as opções:

  * inserir um número mantendo a ordem;
  * remover um número;
  * buscar um número usando busca binária;
  * listar a lista;
  * sair do programa.

## Código comentado

```c
#include <stdio.h>

/*
    MAX representa a capacidade máxima da lista.
*/
#define MAX 50

/*
    Função listar

    Objetivo:
    Imprimir os elementos válidos da lista.
*/
void listar(float v[], int n) {

    /*
        Se n vale 0, a lista está vazia.
    */
    if (n == 0) {
        printf("Lista vazia.\n");
        return;
    }

    printf("Lista: ");

    /*
        Percorre apenas as posições válidas.
    */
    for (int i = 0; i < n; i++) {
        printf("%.2f ", v[i]);
    }

    printf("\n");
}

/*
    Função bubbleSort

    Objetivo:
    Ordenar um vetor de float em ordem crescente.

    Esta função segue a mesma lógica do bubble sort com inteiros.
    Aqui usamos float porque a lista do programa trabalha com float,
    assim como a função inserirCresc.
*/
void bubbleSort(float v[], int n) {

    for (int i = 0; i < n - 1; i++) {

        for (int j = 0; j < n - 1 - i; j++) {

            if (v[j] > v[j + 1]) {

                /*
                    temp precisa ser float porque os valores do vetor são float.
                */
                float temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
            }
        }
    }
}

/*
    Função inserirCresc

    Objetivo:
    Inserir um valor mantendo a lista ordenada.
*/
void inserirCresc(float v[], int *n, int max, float valor) {

    if (*n >= max) {
        printf("Lista cheia.\n");
        return;
    }

    /*
        Começa pelo último elemento válido.
    */
    int i = *n - 1;

    /*
        Desloca para a direita os valores maiores que o novo valor.
    */
    while (i >= 0 && v[i] > valor) {
        v[i + 1] = v[i];
        i--;
    }

    /*
        Insere o valor na posição correta.
    */
    v[i + 1] = valor;

    /*
        Atualiza a quantidade.
    */
    (*n)++;
}

/*
    Função buscaBinaria

    Objetivo:
    Procurar um valor em lista ordenada.
*/
int buscaBinaria(float v[], int n, float valor) {

    int inicio = 0;
    int fim = n - 1;

    while (inicio <= fim) {

        int meio = (inicio + fim) / 2;

        if (v[meio] == valor) {
            return meio;
        }

        if (v[meio] > valor) {
            fim = meio - 1;
        } else {
            inicio = meio + 1;
        }
    }

    return -1;
}

/*
    Função remover

    Objetivo:
    Remover um valor da lista ordenada.
*/
void remover(float v[], int *n, float valor) {

    /*
        Primeiro localizamos o valor.
    */
    int pos = buscaBinaria(v, *n, valor);

    if (pos == -1) {
        printf("Valor não encontrado.\n");
        return;
    }

    /*
        Desloca os elementos posteriores para a esquerda.
    */
    for (int i = pos; i < *n - 1; i++) {
        v[i] = v[i + 1];
    }

    /*
        Atualiza a quantidade.
    */
    (*n)--;
}

int main(void) {

    /*
        Vetor principal que representa a lista.
    */
    float lista[MAX];

    /*
        n indica quantos valores existem na lista.
    */
    int n;

    printf("Quantos números deseja inserir inicialmente? ");
    scanf("%d", &n);

    /*
        Se o usuário digitar um valor maior que MAX, limitamos n.

        Isso evita tentativa de leitura acima do tamanho do vetor.
    */
    if (n > MAX) {
        n = MAX;
    }

    /*
        Se o usuário digitar um valor negativo, ajustamos para 0.

        Não existe quantidade negativa de elementos.
    */
    if (n < 0) {
        n = 0;
    }

    /*
        Leitura dos valores iniciais.
    */
    for (int i = 0; i < n; i++) {
        printf("Valor %d: ", i + 1);
        scanf("%f", &lista[i]);
    }

    /*
        Após ler os valores, ordenamos a lista.

        Isso é necessário porque o usuário pode ter digitado os valores
        em qualquer ordem.
    */
    bubbleSort(lista, n);

    /*
        Variáveis usadas no menu.
    */
    int opcao;
    float valor;

    /*
        O menu será repetido até o usuário escolher a opção 0.
    */
    do {

        printf("\nMenu\n");
        printf("1 - Inserir\n");
        printf("2 - Remover\n");
        printf("3 - Buscar\n");
        printf("4 - Listar\n");
        printf("0 - Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);

        /*
            switch escolhe o bloco de código de acordo com a opção digitada.
        */
        switch (opcao) {

            case 1:
                /*
                    Inserção mantendo a lista ordenada.
                */
                printf("Valor para inserir: ");
                scanf("%f", &valor);

                inserirCresc(lista, &n, MAX, valor);
                break;

            case 2:
                /*
                    Remoção de um valor da lista.
                */
                printf("Valor para remover: ");
                scanf("%f", &valor);

                remover(lista, &n, valor);
                break;

            case 3:
                /*
                    Busca de um valor usando busca binária.
                */
                printf("Valor para buscar: ");
                scanf("%f", &valor);

                int pos;
                pos = buscaBinaria(lista, n, valor);

                if (pos != -1) {
                    printf("Valor encontrado na posição %d.\n", pos);
                } else {
                    printf("Valor não encontrado.\n");
                }

                break;

            case 4:
                /*
                    Listagem dos valores.
                */
                listar(lista, n);
                break;

            case 0:
                /*
                    Encerramento do programa.
                */
                printf("Encerrando.\n");
                break;

            default:
                /*
                    Caso o usuário digite uma opção que não existe.
                */
                printf("Opção inválida.\n");
        }

    } while (opcao != 0);

    return 0;
}

/*
    Explicação final:

    Este programa reúne as principais operações com listas sequenciais
    ordenadas.

    Primeiro, o usuário informa uma quantidade de valores e digita esses
    valores em qualquer ordem.

    Depois, o programa ordena o vetor usando bubble sort.

    A partir daí, o menu permite inserir, remover, buscar e listar.

    A inserção usa inserirCresc para manter a lista ordenada.
    Se a inserção fosse feita simplesmente no final, a lista poderia perder
    sua ordem e a busca binária deixaria de funcionar corretamente.

    A remoção usa busca binária para localizar o valor e depois desloca os
    elementos posteriores para a esquerda.

    A busca usa busca binária, que só funciona porque a lista está ordenada.

    O programa usa apenas vetor, variável de controle e funções, seguindo
    o mesmo padrão das aulas.
*/
```
