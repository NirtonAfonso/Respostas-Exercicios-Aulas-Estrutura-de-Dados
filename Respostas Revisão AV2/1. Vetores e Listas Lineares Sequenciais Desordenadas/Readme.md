# Vetores e Listas Lineares Sequenciais Desordenadas

---

# 1.1 Questões teóricas

## 1) Explique o que é um vetor em C e o que se entende por lista linear sequencial desordenada. Comente como os elementos são armazenados e como o índice é utilizado para acesso aos dados.

Um **vetor em C** é uma estrutura que permite armazenar vários valores do mesmo tipo usando um único nome.

Por exemplo:

```c
float notas[50];
```

Nesse caso, foi criado um vetor chamado `notas`, capaz de armazenar até 50 valores do tipo `float`.

Cada valor dentro do vetor fica guardado em uma posição. Essas posições são acessadas por meio de **índices**. Em C, o primeiro índice é sempre `0`.

Então, em um vetor com 50 posições, os índices válidos são:

```c
notas[0]  // primeira posição
notas[1]  // segunda posição
notas[2]  // terceira posição
...
notas[49] // última posição
```

Não existe a posição `notas[50]` nesse vetor, porque, embora ele tenha 50 espaços, a contagem começa em `0` e termina em `49`.

Uma **lista linear sequencial desordenada** é uma lista implementada usando um vetor, em que os elementos são armazenados um depois do outro, sem seguir uma ordem específica.

Exemplo de lista desordenada:

```c
10   4   25   7   2
```

Ela é chamada de **desordenada** porque os valores não estão necessariamente em ordem crescente ou decrescente. Eles aparecem na ordem em que foram inseridos.

Ela é chamada de **sequencial** porque os elementos são armazenados em posições consecutivas do vetor.

Ela é chamada de **linear** porque existe uma sequência entre os elementos: primeiro elemento, segundo elemento, terceiro elemento, e assim por diante.

O índice é usado para acessar diretamente uma posição específica do vetor. Por exemplo:

```c
lista[2]
```

Esse comando acessa o elemento que está na terceira posição da lista, pois o índice `2` representa a terceira posição.

---

## 2) Por que uma variável de controle, por exemplo `quantidade`, é necessária em uma lista sequencial? Como ela indica que a lista está cheia ou vazia?

Quando usamos um vetor para representar uma lista, o vetor tem um tamanho fixo.

Por exemplo:

```c
int lista[50];
```

Esse vetor possui 50 posições disponíveis. Porém, isso não significa que todas essas posições estão sendo usadas.

Podemos ter uma lista com apenas 3 valores armazenados dentro de um vetor de 50 posições.

Exemplo:

```c
lista[0] = 10;
lista[1] = 20;
lista[2] = 30;
```

Nesse caso, apenas as posições `0`, `1` e `2` estão ocupadas. As outras posições existem no vetor, mas ainda não fazem parte da lista.

Por isso, usamos uma variável de controle, normalmente chamada de `quantidade`, `pos` ou `n`.

Exemplo:

```c
int quantidade = 0;
```

Essa variável indica quantos elementos válidos existem na lista.

Quando `quantidade` vale `0`, significa que a lista está vazia.

```c
if (quantidade == 0) {
    printf("Lista vazia");
}
```

Quando `quantidade` chega ao tamanho máximo do vetor, significa que a lista está cheia.

```c
if (quantidade == MAX) {
    printf("Lista cheia");
}
```

A variável `quantidade` também indica a próxima posição livre.

Exemplo:

```c
quantidade = 3;
```

Isso significa que existem 3 elementos válidos na lista, ocupando as posições:

```c
lista[0]
lista[1]
lista[2]
```

A próxima inserção deve acontecer em:

```c
lista[3]
```

Se não usássemos uma variável de controle, o programa não saberia quais posições do vetor possuem valores válidos e quais posições ainda não foram usadas.

---

## 3) Qual é a complexidade de tempo para inserir e remover um elemento no final de uma lista sequencial desordenada? Justifique.

A inserção no final de uma lista sequencial desordenada tem complexidade **O(1)**.

Isso acontece porque, para inserir no final, não precisamos procurar posição nem deslocar elementos.

Basta usar a variável `quantidade` para saber onde inserir o próximo valor.

Exemplo:

```c
lista[quantidade] = valor;
quantidade++;
```

A primeira linha coloca o valor na próxima posição livre.
A segunda linha atualiza a quantidade de elementos.

Essa operação não depende do tamanho da lista. Se a lista tem 5 elementos ou 40 elementos, a inserção no final funciona da mesma forma.

A remoção no final também tem complexidade **O(1)**.

Para remover o último elemento, basta diminuir a quantidade:

```c
quantidade--;
```

O valor pode até continuar fisicamente no vetor, mas deixa de ser considerado parte da lista, porque a variável `quantidade` foi reduzida.

Por exemplo, se a lista tinha 5 elementos e fazemos:

```c
quantidade--;
```

Agora o programa considera que a lista tem apenas 4 elementos.

É importante observar que essa resposta vale para inserção e remoção **no final**. Se a remoção fosse no meio da lista, seria necessário deslocar os elementos seguintes para a esquerda, e a operação seria mais trabalhosa.

---

## 4) Compare a busca linear em uma lista desordenada com a busca binária. Por que a busca binária não é utilizada nesse caso?

A **busca linear** percorre a lista do início ao fim, comparando cada elemento com o valor procurado.

Exemplo:

```c
for (int i = 0; i < quantidade; i++) {
    if (lista[i] == valor) {
        printf("Valor encontrado");
    }
}
```

Essa busca funciona em listas desordenadas porque ela não depende de os valores estarem organizados. O programa simplesmente verifica um por um.

Exemplo de lista desordenada:

```c
20   4   90   7   15
```

Se procuramos o valor `7`, precisamos percorrer a lista até encontrá-lo.

A **busca binária**, por outro lado, só funciona corretamente em listas ordenadas.

Ela compara o valor procurado com o elemento do meio da lista. Se o valor procurado for menor, continua procurando na metade esquerda. Se for maior, continua na metade direita.

Essa lógica só faz sentido se a lista estiver ordenada.

Exemplo de lista ordenada:

```c
4   7   15   20   90
```

Nesse caso, se o valor do meio é `15` e procuramos `7`, sabemos que devemos procurar antes do `15`.

Mas em uma lista desordenada, isso não funciona.

Exemplo:

```c
20   4   90   7   15
```

O valor do meio é `90`. Se procuramos `7`, não podemos concluir que ele está antes ou depois do `90`, porque a lista não segue ordem.

Por isso, em listas desordenadas, a busca correta é a **busca linear**.

---

## 5) Discorra sobre vantagens e desvantagens de listas sequenciais em relação a listas encadeadas.

As **listas sequenciais** são implementadas usando vetores.

Exemplo:

```c
int lista[50];
```

Elas possuem algumas vantagens:

* são mais simples de entender;
* são mais simples de implementar;
* permitem acessar diretamente uma posição pelo índice;
* funcionam bem quando já sabemos o tamanho máximo da lista;
* usam uma lógica parecida com a de vetores, conteúdo já trabalhado em aula.

Exemplo de acesso direto:

```c
lista[3]
```

Esse comando acessa diretamente a posição de índice `3`.

Por outro lado, listas sequenciais também possuem desvantagens:

* precisam de um tamanho máximo definido previamente;
* podem desperdiçar espaço se o vetor for grande e poucos elementos forem usados;
* podem ficar cheias se o número de elementos ultrapassar o limite;
* inserções e remoções no meio exigem deslocamento de elementos.

As **listas encadeadas** são diferentes. Elas não usam um vetor fixo. Cada elemento aponta para o próximo. Isso permite maior flexibilidade de tamanho, mas exige uso de ponteiros e alocação dinâmica de memória.

Como consequência, listas encadeadas são mais flexíveis, mas também são mais complexas de implementar.

Em resumo:

* lista sequencial é mais simples, mas tem tamanho fixo;
* lista encadeada é mais flexível, mas exige mais controle com ponteiros.

---

# 1.2 Questões práticas

---

# Prática 1

## Lista de notas com funções `inserir` e `listar`

## Enunciado

Considere que você precisa armazenar notas de alunos em um vetor de `float` com tamanho máximo conhecido. Escreva um programa em C que:

* inicialize uma lista vazia, definindo a variável de quantidade como `0`;
* possua uma função `inserir` que insira um valor no final da lista se houver espaço;
* possua uma função `listar` que imprima todos os elementos armazenados na lista;
* leia valores do teclado até o usuário digitar um número negativo, inserindo somente valores não negativos.

## Código comentado

```c
#include <stdio.h>

/*
    A biblioteca stdio.h é incluída porque o programa usa funções de entrada
    e saída, como printf e scanf.

    printf é usado para mostrar mensagens na tela.
    scanf é usado para ler dados digitados pelo usuário.
*/

/*
    MAX representa a capacidade máxima da lista.

    Como a lista será feita com vetor, precisamos definir previamente
    quantas posições estarão disponíveis.

    Neste caso, a lista poderá armazenar no máximo 50 notas.
*/
#define MAX 50

/*
    Função inserir

    Objetivo:
    Inserir uma nova nota no final da lista, se ainda houver espaço.

    Parâmetros:
    float lista[]:
        vetor onde as notas serão armazenadas.

    int *quantidade:
        ponteiro para a variável que controla quantos elementos existem
        na lista.

    float valor:
        nota que será inserida na lista.

    Por que quantidade é ponteiro?

    Porque a função precisa alterar a variável quantidade que está dentro
    da função main.

    Se usássemos apenas:

        int quantidade

    a função receberia uma cópia do valor. Ela poderia até alterar essa cópia,
    mas a quantidade original dentro do main continuaria igual.

    Por isso usamos:

        int *quantidade

    e, na chamada da função, passamos:

        &quantidade
*/
void inserir(float lista[], int *quantidade, float valor) {

    /*
        Antes de inserir, verificamos se a lista está cheia.

        A lista está cheia quando a quantidade de elementos já atingiu
        o limite máximo permitido.

        Como MAX vale 50, a lista está cheia quando *quantidade for 50.
    */
    if (*quantidade >= MAX) {

        /*
            Se a lista estiver cheia, mostramos uma mensagem.

            O return encerra a função imediatamente.
            Isso impede que o programa tente inserir fora do vetor.
        */
        printf("Lista cheia. Não foi possível inserir %.2f.\n", valor);
        return;
    }

    /*
        Se a lista não está cheia, podemos inserir o valor.

        O novo valor entra na posição indicada por *quantidade.

        Exemplo:
        Se *quantidade vale 0, o valor entra em lista[0].
        Se *quantidade vale 1, o valor entra em lista[1].
        Se *quantidade vale 2, o valor entra em lista[2].

        Isso funciona porque a quantidade também indica a próxima posição livre.
    */
    lista[*quantidade] = valor;

    /*
        Depois de inserir, aumentamos a quantidade.

        Isso informa ao programa que agora existe mais um elemento válido
        dentro da lista.

        Os parênteses em (*quantidade)++ são importantes.

        Se escrevêssemos:

            *quantidade++

        o programa interpretaria de outra forma, tentando avançar o ponteiro,
        e não aumentar o valor apontado.

        Por isso, o correto é:

            (*quantidade)++;
    */
    (*quantidade)++;
}

/*
    Função listar

    Objetivo:
    Mostrar todos os valores armazenados na lista.

    Parâmetros:
    float lista[]:
        vetor que contém as notas.

    int quantidade:
        número de elementos válidos na lista.

    Aqui quantidade não precisa ser ponteiro, pois a função não altera
    a quantidade. Ela apenas usa esse valor para saber até onde deve imprimir.
*/
void listar(float lista[], int quantidade) {

    /*
        Se quantidade for 0, significa que nenhum valor foi inserido.
    */
    if (quantidade == 0) {
        printf("Lista vazia.\n");
        return;
    }

    printf("\nNotas cadastradas:\n");

    /*
        O laço percorre apenas as posições válidas da lista.

        Começa em i = 0, pois o primeiro índice do vetor é 0.

        Continua enquanto i < quantidade.

        Se quantidade vale 3, os índices válidos são:
        0, 1 e 2.

        Por isso o laço usa i < quantidade, e não i <= quantidade.
    */
    for (int i = 0; i < quantidade; i++) {

        /*
            Mostra o índice e o valor armazenado naquela posição.

            %.2f mostra o número com duas casas decimais.
        */
        printf("Posição %d: %.2f\n", i, lista[i]);
    }
}

int main(void) {

    /*
        Declaramos o vetor notas com tamanho MAX.

        Como MAX vale 50, esse vetor possui 50 posições:
        notas[0] até notas[49].
    */
    float notas[MAX];

    /*
        A variável quantidade controla quantas notas foram inseridas.

        Começa com 0 porque, no início do programa, a lista está vazia.
    */
    int quantidade = 0;

    /*
        A variável entrada guarda temporariamente cada nota digitada
        pelo usuário.
    */
    float entrada;

    printf("Digite as notas dos alunos.\n");
    printf("Digite um valor negativo para encerrar.\n\n");

    /*
        while (1) cria uma repetição sem condição inicial de parada.

        Isso é usado porque o programa só deve parar quando o usuário
        digitar um valor negativo.

        O comando break será usado para sair do laço.
    */
    while (1) {

        printf("Nota: ");

        /*
            scanf lê um número do tipo float.

            Usamos &entrada porque scanf precisa do endereço da variável
            onde o valor será armazenado.
        */
        scanf("%f", &entrada);

        /*
            Se o valor digitado for negativo, encerramos a leitura.

            Esse valor negativo não deve ser inserido na lista.
        */
        if (entrada < 0) {
            break;
        }

        /*
            Se o valor não for negativo, chamamos a função inserir.

            Passamos:
            notas       -> vetor onde o valor será armazenado;
            &quantidade -> endereço da variável quantidade;
            entrada     -> valor digitado pelo usuário.
        */
        inserir(notas, &quantidade, entrada);
    }

    /*
        Depois que o usuário encerra a leitura, chamamos listar
        para mostrar todas as notas armazenadas.
    */
    listar(notas, quantidade);

    /*
        return 0 indica que o programa terminou corretamente.
    */
    return 0;
}

/*
    Explicação final:

    Este programa usa um vetor para representar uma lista sequencial
    desordenada de notas.

    A variável quantidade é fundamental porque indica quantas posições do
    vetor estão realmente ocupadas.

    A função inserir coloca o novo valor no final da lista. Antes disso,
    verifica se ainda existe espaço no vetor.

    Essa verificação é importante porque, em C, tentar acessar uma posição
    fora do vetor pode causar erro ou comportamento inesperado.

    A função listar percorre apenas as posições válidas, de 0 até
    quantidade - 1.

    Se o programa imprimisse até MAX, poderia mostrar valores inválidos,
    pois nem todas as posições do vetor necessariamente foram preenchidas.

    O uso de ponteiro em inserir é necessário porque a quantidade precisa
    ser alterada dentro da função. Sem ponteiro, a função alteraria apenas
    uma cópia da variável.
*/
```

---

# Prática 2

## Inserção sem repetição

## Enunciado

Baseando-se na Atividade Estruturada 2, implemente em C a função:

```c
void inserirSemRepetir(int v[], int valor, int *pos, int max)
```

Essa função deve inserir um inteiro em uma lista desordenada somente se ele ainda não estiver presente. A função deve atualizar a variável que controla a quantidade de elementos e apresentar mensagem caso a lista esteja cheia ou o valor já exista.

## Código comentado

```c
#include <stdio.h>

/*
    Incluímos stdio.h para usar printf e scanf.
*/

/*
    MAX define o tamanho máximo da lista.

    Como estamos usando vetor, o tamanho precisa ser definido antes.
*/
#define MAX 100

/*
    Função inserirSemRepetir

    Objetivo:
    Inserir um valor inteiro em uma lista apenas se esse valor ainda
    não existir na lista.

    Parâmetros:

    int v[]:
        vetor que representa a lista.

    int valor:
        número que queremos inserir.

    int *pos:
        ponteiro para a variável que indica a próxima posição livre.
        Essa variável também representa a quantidade de elementos válidos.

    int max:
        tamanho máximo do vetor.

    O nome pos pode ser entendido como "posição atual de inserção".
    Se pos vale 0, a próxima inserção será em v[0].
    Se pos vale 3, a próxima inserção será em v[3].
*/
void inserirSemRepetir(int v[], int valor, int *pos, int max) {

    /*
        Primeiro verificamos se a lista está cheia.

        Se *pos for maior ou igual a max, significa que todas as posições
        disponíveis já foram ocupadas.
    */
    if (*pos >= max) {
        printf("Lista cheia. Não foi possível inserir %d.\n", valor);
        return;
    }

    /*
        Agora verificamos se o valor já existe na lista.

        O laço percorre de 0 até *pos - 1, pois essas são as posições
        que já possuem valores válidos.

        Não devemos percorrer até max, porque as posições depois de *pos
        ainda não fazem parte da lista.
    */
    for (int i = 0; i < *pos; i++) {

        /*
            Se v[i] for igual ao valor que queremos inserir, isso significa
            que o valor já está na lista.

            Nesse caso, não devemos inserir novamente.
        */
        if (v[i] == valor) {
            printf("Valor %d já existe na lista.\n", valor);
            return;
        }
    }

    /*
        Se o programa chegou até esta parte, significa que:
        - a lista não está cheia;
        - o valor ainda não existe na lista.

        Então podemos inserir o valor na posição *pos.
    */
    v[*pos] = valor;

    /*
        Depois da inserção, aumentamos pos em 1.

        Isso indica que a lista ganhou mais um elemento e que a próxima
        posição livre mudou.
    */
    (*pos)++;
}

int main(void) {

    /*
        Vetor usado para armazenar os números inteiros.
    */
    int lista[MAX];

    /*
        quantidade começa em 0 porque a lista está vazia.

        Essa variável será passada para a função como ponteiro.
    */
    int quantidade = 0;

    /*
        Variável usada para armazenar o valor digitado pelo usuário.
    */
    int valor;

    printf("Digite números inteiros.\n");
    printf("Digite 0 para encerrar.\n\n");

    /*
        O laço continua até o usuário digitar 0.
    */
    while (1) {

        printf("Valor: ");
        scanf("%d", &valor);

        /*
            O valor 0 será usado apenas como critério de parada.

            Ele não será inserido na lista.
        */
        if (valor == 0) {
            break;
        }

        /*
            Chamada da função inserirSemRepetir.

            lista:
                vetor que receberá o valor.

            valor:
                número digitado.

            &quantidade:
                endereço da variável quantidade.

            MAX:
                capacidade máxima do vetor.
        */
        inserirSemRepetir(lista, valor, &quantidade, MAX);
    }

    printf("\nLista final:\n");

    /*
        Imprime apenas as posições válidas da lista.
    */
    for (int i = 0; i < quantidade; i++) {
        printf("%d ", lista[i]);
    }

    printf("\n");

    return 0;
}

/*
    Explicação final:

    Este programa cria uma lista desordenada de inteiros sem repetição.

    A função inserirSemRepetir faz duas verificações antes de inserir:

    1. Verifica se a lista está cheia.
       Se estiver cheia, não existe espaço para novo valor.

    2. Verifica se o valor já existe.
       Se já existir, o valor não deve ser inserido novamente.

    Somente depois dessas verificações o valor é colocado no final da lista.

    Se a verificação de repetição fosse removida, o programa aceitaria
    valores duplicados.

    Se a verificação de lista cheia fosse removida, o programa poderia tentar
    gravar fora dos limites do vetor.

    A variável quantidade precisa ser passada por ponteiro porque a função
    deve alterar seu valor original.
*/
```

---

# Prática 3

## Intercalação, interseção, união e remoção por índice

## Enunciado

Crie dois vetores de inteiros sem repetição e, utilizando funções:

* imprima ambos os vetores;
* gere e imprima uma terceira lista resultante da intercalação alternada dos elementos das duas listas;
* gere e imprima a interseção dos conjuntos, ou seja, os elementos comuns;
* gere e imprima a união dos conjuntos, sem repetição;
* implemente uma função `removerPeloIndice(int v[], int *quantidade, int indice)` para remover um valor pelo índice na lista da união, verificando a validade do índice antes da remoção.

## Código comentado

```c
#include <stdio.h>

/*
    MAX define a capacidade máxima de cada uma das listas principais.
*/
#define MAX 50

/*
    Função listar

    Objetivo:
    Imprimir os elementos válidos de um vetor de inteiros.

    Parâmetros:
    int v[]:
        vetor que será impresso.

    int quantidade:
        quantidade de elementos válidos no vetor.
*/
void listar(int v[], int quantidade) {

    /*
        Percorre de 0 até quantidade - 1.

        Não percorre até MAX, pois nem todas as posições do vetor
        necessariamente estão ocupadas.
    */
    for (int i = 0; i < quantidade; i++) {
        printf("%d ", v[i]);
    }

    printf("\n");
}

/*
    Função inserirSemRepetir

    Objetivo:
    Inserir valores em uma lista sem permitir repetição.

    Essa função será usada para montar a lista A e a lista B.
*/
void inserirSemRepetir(int v[], int valor, int *quantidade, int max) {

    /*
        Verifica se ainda existe espaço.
    */
    if (*quantidade >= max) {
        printf("Lista cheia.\n");
        return;
    }

    /*
        Verifica se o valor já existe na lista.
    */
    for (int i = 0; i < *quantidade; i++) {
        if (v[i] == valor) {
            printf("Valor %d já existe.\n", valor);
            return;
        }
    }

    /*
        Se passou pelas verificações, insere no final.
    */
    v[*quantidade] = valor;

    /*
        Atualiza a quantidade.
    */
    (*quantidade)++;
}

/*
    Função intercalar

    Objetivo:
    Criar uma nova lista alternando elementos da lista A e da lista B.

    Exemplo:

    A = 10 20 30
    B = 1 2 3

    Resultado = 10 1 20 2 30 3

    Parâmetros:
    a[]:
        primeira lista.

    qa:
        quantidade de elementos da primeira lista.

    b[]:
        segunda lista.

    qb:
        quantidade de elementos da segunda lista.

    resultado[]:
        vetor onde será guardada a intercalação.
*/
int intercalar(int a[], int qa, int b[], int qb, int resultado[]) {

    /*
        ia controla a posição atual da lista A.
        ib controla a posição atual da lista B.
        ir controla a próxima posição livre do vetor resultado.
    */
    int ia = 0;
    int ib = 0;
    int ir = 0;

    /*
        O laço continua enquanto ainda houver elementos em A ou em B.

        Usamos || porque basta uma das listas ainda ter elementos
        para continuar o processo.
    */
    while (ia < qa || ib < qb) {

        /*
            Se ainda existe elemento em A, copiamos esse elemento
            para o resultado.
        */
        if (ia < qa) {
            resultado[ir] = a[ia];

            /*
                Depois da cópia, avançamos os dois índices:
                ir para a próxima posição do resultado;
                ia para o próximo elemento de A.
            */
            ir++;
            ia++;
        }

        /*
            Se ainda existe elemento em B, copiamos esse elemento
            para o resultado.
        */
        if (ib < qb) {
            resultado[ir] = b[ib];

            /*
                Avançamos os índices correspondentes.
            */
            ir++;
            ib++;
        }
    }

    /*
        Ao final, ir representa a quantidade de elementos inseridos
        no vetor resultado.
    */
    return ir;
}

/*
    Função intersecao

    Objetivo:
    Encontrar os elementos que aparecem nas duas listas.

    Exemplo:

    A = 10 20 30 40
    B = 30 40 50 60

    Interseção = 30 40
*/
int intersecao(int a[], int qa, int b[], int qb, int resultado[]) {

    /*
        ir controla quantos elementos já foram inseridos no resultado.
    */
    int ir = 0;

    /*
        O primeiro laço percorre a lista A.
    */
    for (int i = 0; i < qa; i++) {

        /*
            Para cada elemento de A, percorremos toda a lista B.
        */
        for (int j = 0; j < qb; j++) {

            /*
                Se a[i] é igual a b[j], encontramos um valor comum.
            */
            if (a[i] == b[j]) {

                /*
                    Antes de inserir no resultado, verificamos se esse valor
                    já foi inserido antes.

                    Isso evita repetição na interseção.
                */
                int repetido = 0;

                for (int k = 0; k < ir; k++) {
                    if (resultado[k] == a[i]) {
                        repetido = 1;
                        break;
                    }
                }

                /*
                    Se repetido continua 0, significa que o valor ainda
                    não está no resultado.
                */
                if (repetido == 0) {
                    resultado[ir] = a[i];
                    ir++;
                }
            }
        }
    }

    /*
        Retorna a quantidade de elementos da interseção.
    */
    return ir;
}

/*
    Função uniao

    Objetivo:
    Criar uma lista com todos os valores da lista A e da lista B,
    sem repetir elementos.

    Exemplo:

    A = 10 20 30
    B = 30 40 50

    União = 10 20 30 40 50
*/
int uniao(int a[], int qa, int b[], int qb, int resultado[]) {

    /*
        ir representa a próxima posição livre no resultado.
    */
    int ir = 0;

    /*
        Primeiro copiamos todos os elementos de A para resultado.

        Como a lista A já foi criada sem repetição, podemos copiar todos.
    */
    for (int i = 0; i < qa; i++) {
        resultado[ir] = a[i];
        ir++;
    }

    /*
        Agora analisamos os elementos de B.

        Cada elemento de B só será inserido se ainda não estiver no resultado.
    */
    for (int j = 0; j < qb; j++) {

        /*
            existe começa como 0, assumindo que o valor ainda não foi encontrado.
        */
        int existe = 0;

        /*
            Percorremos o resultado para verificar se b[j] já está lá.
        */
        for (int k = 0; k < ir; k++) {
            if (resultado[k] == b[j]) {
                existe = 1;
                break;
            }
        }

        /*
            Se existe continua 0, o valor de B ainda não está no resultado.
            Então podemos inserir.
        */
        if (existe == 0) {
            resultado[ir] = b[j];
            ir++;
        }
    }

    /*
        Retorna a quantidade de elementos da união.
    */
    return ir;
}

/*
    Função removerPeloIndice

    Objetivo:
    Remover um elemento de uma lista a partir do seu índice.

    Parâmetros:
    v[]:
        vetor onde será feita a remoção.

    quantidade:
        ponteiro para a quantidade de elementos da lista.

    indice:
        posição que deve ser removida.
*/
void removerPeloIndice(int v[], int *quantidade, int indice) {

    /*
        Primeiro verificamos se o índice é válido.

        Um índice válido:
        - não pode ser menor que 0;
        - não pode ser maior ou igual à quantidade.

        Se quantidade vale 5, os índices válidos são:
        0, 1, 2, 3 e 4.
    */
    if (indice < 0 || indice >= *quantidade) {
        printf("Índice inválido.\n");
        return;
    }

    /*
        Para remover de um vetor, precisamos deslocar todos os elementos
        posteriores uma posição para a esquerda.

        Exemplo:

        Antes:
        índice:  0   1   2   3
        valor:  10  20  30  40

        Removendo índice 1:

        O 30 vai para a posição 1.
        O 40 vai para a posição 2.

        Depois:
        valor:  10  30  40
    */
    for (int i = indice; i < *quantidade - 1; i++) {
        v[i] = v[i + 1];
    }

    /*
        Após o deslocamento, a lista tem um elemento a menos.
    */
    (*quantidade)--;
}

int main(void) {

    /*
        Vetores principais.

        listaA e listaB guardarão os conjuntos iniciais.
    */
    int listaA[MAX];
    int listaB[MAX];

    /*
        qa controla a quantidade de elementos da lista A.
        qb controla a quantidade de elementos da lista B.
    */
    int qa = 0;
    int qb = 0;

    /*
        Inserimos alguns valores de exemplo na lista A.
    */
    inserirSemRepetir(listaA, 10, &qa, MAX);
    inserirSemRepetir(listaA, 20, &qa, MAX);
    inserirSemRepetir(listaA, 30, &qa, MAX);
    inserirSemRepetir(listaA, 40, &qa, MAX);

    /*
        Inserimos alguns valores de exemplo na lista B.

        Os valores 30 e 40 aparecem nas duas listas para que exista interseção.
    */
    inserirSemRepetir(listaB, 30, &qb, MAX);
    inserirSemRepetir(listaB, 40, &qb, MAX);
    inserirSemRepetir(listaB, 50, &qb, MAX);
    inserirSemRepetir(listaB, 60, &qb, MAX);

    /*
        Imprime as listas originais.
    */
    printf("Lista A: ");
    listar(listaA, qa);

    printf("Lista B: ");
    listar(listaB, qb);

    /*
        O vetor intercalada precisa comportar elementos de A e B.
        Por isso usamos MAX * 2.
    */
    int intercalada[MAX * 2];

    /*
        qi recebe a quantidade de elementos da lista intercalada.
    */
    int qi = intercalar(listaA, qa, listaB, qb, intercalada);

    printf("Intercalada: ");
    listar(intercalada, qi);

    /*
        Vetor que guardará os valores comuns entre A e B.
    */
    int comum[MAX];

    /*
        qc recebe a quantidade de elementos da interseção.
    */
    int qc = intersecao(listaA, qa, listaB, qb, comum);

    printf("Interseção: ");
    listar(comum, qc);

    /*
        Vetor que guardará a união.

        Pode ter até a soma dos tamanhos das duas listas.
    */
    int unida[MAX * 2];

    /*
        qu recebe a quantidade de elementos da união.
    */
    int qu = uniao(listaA, qa, listaB, qb, unida);

    printf("União: ");
    listar(unida, qu);

    /*
        Exemplo de remoção pelo índice.

        Aqui removemos o elemento de índice 2 da lista de união.
    */
    removerPeloIndice(unida, &qu, 2);

    printf("União após remover índice 2: ");
    listar(unida, qu);

    return 0;
}

/*
    Explicação final:

    Este programa usa apenas vetores e variáveis de controle, seguindo o
    padrão trabalhado nas aulas.

    A lista A é controlada pela variável qa.
    A lista B é controlada pela variável qb.

    A função inserirSemRepetir evita valores duplicados dentro de cada lista.

    A função intercalar cria uma nova lista alternando valores de A e B.
    Ela usa três índices: um para A, um para B e um para o resultado.

    A função intersecao procura valores comuns entre A e B.
    Para cada valor de A, ela percorre B procurando igualdade.

    A função uniao copia todos os valores de A e depois adiciona apenas
    os valores de B que ainda não existem no resultado.

    A função removerPeloIndice remove um valor pela sua posição.
    Para isso, desloca todos os elementos seguintes uma posição para a esquerda.

    Se esse deslocamento não fosse feito, a lista ficaria com um espaço
    inválido no meio ou com um valor repetido no final.

    Nenhuma estrutura do tipo struct foi usada. A implementação segue o
    mesmo padrão das aulas: vetor, quantidade, funções e ponteiros quando
    a função precisa alterar uma variável do main.
*/
```
