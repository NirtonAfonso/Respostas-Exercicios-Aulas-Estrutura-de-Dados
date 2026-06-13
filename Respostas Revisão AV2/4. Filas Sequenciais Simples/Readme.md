# Gabarito Comentado – Tópico 4

## Filas Sequenciais Simples

---

# 4.1 Questões teóricas

## 1) Explique o que é uma fila sequencial simples e o que significa FIFO.

Uma **fila sequencial simples** é uma estrutura de dados implementada usando um **vetor** e duas variáveis de controle:

```c
inicio
fim
```

A variável `inicio` indica a posição do primeiro elemento da fila, ou seja, o próximo elemento que será removido.

A variável `fim` indica a posição do último elemento inserido na fila.

A fila segue a regra **FIFO**, que significa:

```c
First In, First Out
```

Em português:

```c
Primeiro a entrar, primeiro a sair
```

Isso quer dizer que o primeiro elemento inserido na fila será o primeiro elemento removido.

Um exemplo simples é uma fila de atendimento. A primeira pessoa que chega deve ser a primeira pessoa atendida.

Exemplo:

```c
Entrada na fila:
10, 20, 30
```

A remoção deve acontecer nesta mesma ordem:

```c
Saída da fila:
10, 20, 30
```

Em uma fila sequencial simples, usamos um vetor para armazenar os valores:

```c
int fila[50];
```

E usamos duas variáveis para controlar a fila:

```c
int inicio;
int fim;
```

Normalmente, ao inicializar a fila, fazemos:

```c
inicio = 0;
fim = -1;
```

O valor `fim = -1` indica que a fila está vazia. Como o primeiro índice válido do vetor é `0`, o valor `-1` mostra que ainda não existe nenhum elemento inserido.

Quando o primeiro valor é inserido, `fim` passa de `-1` para `0`, e o valor é colocado em:

```c
fila[0]
```

Quando removemos um elemento, não mexemos no `fim`. A remoção acontece pelo `inicio`.

---

## 2) Resuma as diferenças entre lista desordenada, pilha e fila.

As três estruturas podem ser implementadas com vetor, mas cada uma possui uma regra diferente de funcionamento.

Uma **lista desordenada** permite armazenar valores sem seguir uma ordem específica. Normalmente, em uma lista sequencial desordenada, inserimos no final e podemos buscar ou remover valores de diferentes posições, dependendo do exercício.

Exemplo:

```c
10   5   30   2
```

A ordem dos valores é simplesmente a ordem em que eles foram inseridos.

Uma **pilha** segue a regra **LIFO**:

```c
Last In, First Out
```

Ou seja:

```c
Último a entrar, primeiro a sair
```

Se empilhamos:

```c
10, 20, 30
```

o primeiro valor removido será:

```c
30
```

Isso acontece porque a remoção é feita pelo `topo`.

Já uma **fila** segue a regra **FIFO**:

```c
First In, First Out
```

Ou seja:

```c
Primeiro a entrar, primeiro a sair
```

Se enfileiramos:

```c
10, 20, 30
```

o primeiro valor removido será:

```c
10
```

Resumo:

| Estrutura         | Controle principal | Regra de remoção                  |
| ----------------- | ------------------ | --------------------------------- |
| Lista desordenada | `quantidade`       | Pode depender da posição desejada |
| Pilha             | `topo`             | Remove o último inserido          |
| Fila              | `inicio` e `fim`   | Remove o primeiro inserido        |

A principal diferença está no local de inserção e remoção.

Na pilha, inserimos e removemos pelo mesmo lado: o topo.

Na fila, inserimos no fim e removemos do início.

---

## 3) Por que são necessários dois índices, `inicio` e `fim`, para manipular uma fila sequencial?

Em uma fila, a inserção e a remoção acontecem em lados diferentes.

A inserção acontece no final da fila. Por isso, precisamos da variável:

```c
fim
```

A remoção acontece no início da fila. Por isso, precisamos da variável:

```c
inicio
```

Se usássemos apenas uma variável, seria difícil controlar ao mesmo tempo onde inserir e de onde remover.

Exemplo:

```c
fila:
10   20   30
```

Nesse caso:

```c
inicio = 0
fim = 2
```

O próximo elemento a sair é:

```c
fila[inicio]
```

Ou seja:

```c
fila[0] = 10
```

Se um novo valor for inserido, ele deve entrar depois do `fim`.

Se inserirmos o valor `40`, fazemos:

```c
fim++;
fila[fim] = 40;
```

A fila ficará:

```c
10   20   30   40
```

Agora:

```c
inicio = 0
fim = 3
```

Se removermos um elemento, removemos do início:

```c
valor = fila[inicio];
inicio++;
```

Depois da remoção:

```c
inicio = 1
fim = 3
```

Agora o próximo elemento a sair será:

```c
fila[1] = 20
```

Por isso, `inicio` e `fim` têm funções diferentes e ambos são necessários.

---

## 4) Descreva o problema do desperdício de espaço em filas sequenciais simples e como ele é resolvido com fila circular.

Na fila sequencial simples, a variável `inicio` avança quando removemos elementos, e a variável `fim` avança quando inserimos elementos.

O problema é que, quando removemos elementos, as posições antigas no começo do vetor ficam livres, mas a fila simples não reaproveita automaticamente essas posições.

Exemplo:

```c
Vetor:
[10] [20] [30] [40] [50]

inicio = 0
fim = 4
```

Se removermos dois elementos, removemos `10` e `20`.

Depois disso:

```c
inicio = 2
fim = 4
```

As posições `0` e `1` estão livres, mas o `fim` continua na última posição.

Se tentarmos inserir um novo valor, a fila simples vai tentar avançar o `fim`.

Mas `fim` já está no final do vetor.

Então o programa pode dizer que a fila está cheia, mesmo existindo espaços vazios no começo.

Esse é o problema do **desperdício de espaço**.

A **fila circular** resolve esse problema permitindo que o índice volte para o começo do vetor quando chega ao final.

Porém, como o foco aqui é a **fila sequencial simples**, a implementação prática será feita apenas com:

```c
vetor
inicio
fim
```

Sem implementar fila circular.

---

# 4.2 Questões práticas

---

# Prática 1

## Menu de operações com fila

## Enunciado

Escreva um programa em C que apresente um menu com as opções:

* enfileirar um número inteiro positivo;
* desenfileirar todos os elementos e imprimir apenas os múltiplos de 2;
* encerrar o programa.

A fila deve ser implementada usando vetor e as variáveis `inicio` e `fim`.

---

## Código comentado

```c
#include <stdio.h>

/*
    Incluímos stdio.h porque o programa usa printf e scanf.

    printf é usado para mostrar mensagens na tela.
    scanf é usado para ler valores digitados pelo usuário.
*/

/*
    MAX define a capacidade máxima da fila.

    Como a fila será implementada com vetor, precisamos definir previamente
    quantas posições estarão disponíveis.
*/
#define MAX 50

/*
    Função inicializarFila

    Objetivo:
    Preparar a fila para uso.

    Parâmetros:
    int *inicio:
        ponteiro para a variável inicio.

    int *fim:
        ponteiro para a variável fim.

    Por que são ponteiros?

    Porque a função precisa alterar as variáveis originais que estão no main.
    Se recebesse apenas int inicio e int fim, alteraria somente cópias.
*/
void inicializarFila(int *inicio, int *fim) {

    /*
        inicio começa em 0 porque, quando o primeiro elemento for inserido,
        ele será colocado na posição 0 do vetor.
    */
    *inicio = 0;

    /*
        fim começa em -1 para indicar que a fila está vazia.

        Como o primeiro índice válido do vetor é 0, usar -1 deixa claro
        que ainda não existe nenhum elemento inserido.
    */
    *fim = -1;
}

/*
    Função filaVazia

    Objetivo:
    Verificar se a fila está vazia.

    Parâmetros:
    int inicio:
        posição atual do início da fila.

    int fim:
        posição atual do fim da fila.

    Retorno:
    retorna 1 se a fila estiver vazia;
    retorna 0 se a fila tiver elementos.
*/
int filaVazia(int inicio, int fim) {

    /*
        A fila está vazia quando fim é menor que inicio.

        No início:
        inicio = 0
        fim = -1

        Como -1 < 0, a fila está vazia.

        Depois de remover todos os elementos, também teremos uma situação
        em que inicio fica maior que fim.
    */
    return fim < inicio;
}

/*
    Função filaCheia

    Objetivo:
    Verificar se a fila está cheia.

    Parâmetro:
    int fim:
        posição atual do último elemento da fila.

    Retorno:
    retorna 1 se a fila estiver cheia;
    retorna 0 se ainda houver espaço.
*/
int filaCheia(int fim) {

    /*
        A fila simples está cheia quando fim chega à última posição do vetor.

        Se o vetor tem MAX posições, os índices válidos são de 0 até MAX - 1.
    */
    return fim == MAX - 1;
}

/*
    Função enfileirar

    Objetivo:
    Inserir um valor no fim da fila.

    Parâmetros:
    int fila[]:
        vetor que representa a fila.

    int *fim:
        ponteiro para a variável fim.

    int valor:
        número que será inserido na fila.

    O fim precisa ser ponteiro porque ele muda quando inserimos um novo valor.
*/
void enfileirar(int fila[], int *fim, int valor) {

    /*
        Antes de inserir, verificamos se a fila está cheia.

        Se a fila estiver cheia e mesmo assim tentarmos inserir,
        o programa pode escrever fora dos limites do vetor.
    */
    if (filaCheia(*fim)) {
        printf("Fila cheia.\n");
        return;
    }

    /*
        Para inserir, primeiro avançamos o fim.

        Exemplo:
        Se fim vale -1, ele passa a valer 0.
        O primeiro valor será inserido em fila[0].
    */
    (*fim)++;

    /*
        Depois colocamos o valor na posição indicada pelo fim.
    */
    fila[*fim] = valor;
}

/*
    Função desenfileirar

    Objetivo:
    Remover e retornar o elemento que está no início da fila.

    Parâmetros:
    int fila[]:
        vetor que representa a fila.

    int *inicio:
        ponteiro para a variável inicio.

    int fim:
        valor atual do fim da fila.

    Retorno:
    retorna o valor removido;
    retorna -1 se a fila estiver vazia.

    Neste exercício, como os valores inseridos devem ser positivos,
    o retorno -1 pode ser usado como sinal de fila vazia.
*/
int desenfileirar(int fila[], int *inicio, int fim) {

    /*
        Antes de remover, verificamos se a fila está vazia.

        Não é possível remover de uma fila vazia.
    */
    if (filaVazia(*inicio, fim)) {
        return -1;
    }

    /*
        Guardamos o valor que está no início da fila.

        Esse é o valor que deve sair primeiro, respeitando a regra FIFO.
    */
    int valor = fila[*inicio];

    /*
        Avançamos o início.

        Isso faz com que o próximo elemento passe a ser considerado
        o primeiro da fila.
    */
    (*inicio)++;

    /*
        Retornamos o valor removido.
    */
    return valor;
}

/*
    Função desenfileirarMultiplosDe2

    Objetivo:
    Remover todos os elementos da fila e imprimir apenas os múltiplos de 2.

    Parâmetros:
    int fila[]:
        vetor que representa a fila.

    int *inicio:
        ponteiro para o início, porque a função vai remover elementos
        e, portanto, alterar o início.

    int fim:
        posição final atual da fila.
*/
void desenfileirarMultiplosDe2(int fila[], int *inicio, int fim) {

    /*
        Primeiro verificamos se a fila está vazia.

        Se estiver vazia, não há elementos para remover.
    */
    if (filaVazia(*inicio, fim)) {
        printf("Fila vazia.\n");
        return;
    }

    printf("Múltiplos de 2: ");

    /*
        Enquanto a fila não estiver vazia, continuamos removendo.

        A cada remoção, a variável inicio é incrementada.
    */
    while (!filaVazia(*inicio, fim)) {

        /*
            Removemos o primeiro elemento da fila.
        */
        int valor = desenfileirar(fila, inicio, fim);

        /*
            Um número é múltiplo de 2 quando o resto da divisão por 2 é 0.
        */
        if (valor % 2 == 0) {
            printf("%d ", valor);
        }
    }

    printf("\n");
}

int main(void) {

    /*
        Vetor que representa a fila.

        A fila será armazenada nas posições desse vetor.
    */
    int fila[MAX];

    /*
        inicio controla a posição do primeiro elemento da fila.

        fim controla a posição do último elemento da fila.
    */
    int inicio;
    int fim;

    /*
        opcao guarda a escolha do usuário no menu.

        valor guarda o número digitado para ser inserido na fila.
    */
    int opcao;
    int valor;

    /*
        Inicializamos a fila antes de qualquer operação.

        Se isso não fosse feito, inicio e fim poderiam começar com lixo de memória.
    */
    inicializarFila(&inicio, &fim);

    /*
        O menu será repetido até o usuário escolher a opção 0.
    */
    do {

        printf("\n1 - Enfileirar\n");
        printf("2 - Desenfileirar e mostrar múltiplos de 2\n");
        printf("0 - Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);

        /*
            O switch executa uma ação conforme a opção digitada.
        */
        switch (opcao) {

            case 1:

                /*
                    Opção 1: inserir número positivo na fila.
                */
                printf("Digite um número positivo: ");
                scanf("%d", &valor);

                /*
                    O enunciado pede número positivo.

                    Por isso, validamos antes de inserir.
                */
                if (valor > 0) {
                    enfileirar(fila, &fim, valor);
                } else {
                    printf("O número deve ser positivo.\n");
                }

                break;

            case 2:

                /*
                    Opção 2: remover todos os elementos e mostrar
                    apenas os múltiplos de 2.
                */
                desenfileirarMultiplosDe2(fila, &inicio, fim);
                break;

            case 0:

                /*
                    Opção 0: encerrar.
                */
                printf("Encerrando.\n");
                break;

            default:

                /*
                    Qualquer outra opção é inválida.
                */
                printf("Opção inválida.\n");
        }

    } while (opcao != 0);

    return 0;
}

/*
    Explicação final:

    Este programa implementa uma fila sequencial simples usando apenas:

    - vetor;
    - variável inicio;
    - variável fim.

    Para inserir, a função enfileirar incrementa fim e coloca o valor em fila[fim].

    Para remover, a função desenfileirar lê o valor em fila[inicio] e depois
    incrementa inicio.

    Essa lógica respeita o comportamento FIFO: o primeiro valor inserido é
    o primeiro a ser removido.

    A função desenfileirarMultiplosDe2 remove todos os elementos da fila,
    mas imprime apenas aqueles que são múltiplos de 2.

    Como é uma fila simples, as posições já removidas no início do vetor
    não são reaproveitadas automaticamente.

    Nenhuma struct foi usada. A implementação segue o padrão das aulas.
*/
```

---

# Prática 2

## Fila de caracteres com pilha

## Enunciado

Escreva um programa que:

* leia uma sequência de caracteres;
* enfileire todos os caracteres;
* desenfileire um por um;
* se o caractere for letra, converta para minúscula;
* empilhe o caractere processado;
* ao final, desempilhe todos os caracteres e imprima.

---

## Código comentado

```c
#include <stdio.h>
#include <ctype.h>

/*
    stdio.h:
        usado para printf e fgets.

    ctype.h:
        usado para isalpha e tolower.

    isalpha verifica se um caractere é letra.
    tolower converte letra maiúscula para minúscula.
*/

#define MAX 100

/*
    Função inicializarFila

    Define inicio e fim para representar fila vazia.
*/
void inicializarFila(int *inicio, int *fim) {
    *inicio = 0;
    *fim = -1;
}

/*
    Função inicializarPilha

    Define topo como -1 para indicar pilha vazia.
*/
void inicializarPilha(int *topo) {
    *topo = -1;
}

/*
    Verifica se a fila está vazia.
*/
int filaVazia(int inicio, int fim) {
    return fim < inicio;
}

/*
    Enfileira um caractere no fim da fila.
*/
void enfileirar(char fila[], int *fim, char valor) {

    /*
        Verifica se ainda há espaço no vetor.
    */
    if (*fim < MAX - 1) {
        (*fim)++;
        fila[*fim] = valor;
    }
}

/*
    Remove e retorna o caractere do início da fila.
*/
char desenfileirar(char fila[], int *inicio, int fim) {

    if (filaVazia(*inicio, fim)) {
        return '\0';
    }

    char valor = fila[*inicio];
    (*inicio)++;

    return valor;
}

/*
    Empilha um caractere.
*/
void empilhar(char pilha[], int *topo, char valor) {

    if (*topo < MAX - 1) {
        (*topo)++;
        pilha[*topo] = valor;
    }
}

/*
    Desempilha um caractere.
*/
char desempilhar(char pilha[], int *topo) {

    if (*topo >= 0) {
        char valor = pilha[*topo];
        (*topo)--;
        return valor;
    }

    return '\0';
}

int main(void) {

    /*
        texto guarda a sequência digitada.
    */
    char texto[MAX];

    /*
        fila será usada para armazenar os caracteres na ordem de entrada.
    */
    char fila[MAX];

    /*
        pilha será usada para armazenar os caracteres processados.
    */
    char pilha[MAX];

    /*
        Variáveis da fila.
    */
    int inicio;
    int fim;

    /*
        Variável da pilha.
    */
    int topo;

    inicializarFila(&inicio, &fim);
    inicializarPilha(&topo);

    printf("Digite uma sequência de caracteres: ");

    /*
        fgets lê a linha inteira, incluindo espaços.
    */
    fgets(texto, MAX, stdin);

    /*
        Primeiro passo:
        enfileirar todos os caracteres digitados.
    */
    for (int i = 0; texto[i] != '\0'; i++) {
        enfileirar(fila, &fim, texto[i]);
    }

    /*
        Segundo passo:
        desenfileirar cada caractere, tratar e empilhar.
    */
    while (!filaVazia(inicio, fim)) {

        char c = desenfileirar(fila, &inicio, fim);

        /*
            isalpha verifica se c é uma letra.

            O uso de (unsigned char) evita problemas com alguns caracteres
            em determinadas implementações da linguagem C.
        */
        if (isalpha((unsigned char)c)) {

            /*
                Se for letra, convertemos para minúscula antes de empilhar.
            */
            empilhar(pilha, &topo, tolower((unsigned char)c));
        } else {

            /*
                Se não for letra, empilhamos sem alteração.
            */
            empilhar(pilha, &topo, c);
        }
    }

    printf("Resultado: ");

    /*
        Terceiro passo:
        desempilhar e imprimir.
    */
    while (topo >= 0) {
        printf("%c", desempilhar(pilha, &topo));
    }

    printf("\n");

    return 0;
}

/*
    Explicação final:

    O programa usa duas estruturas sequenciais:

    1. Fila:
       controlada por vetor, inicio e fim.

    2. Pilha:
       controlada por vetor e topo.

    A fila preserva a ordem de entrada dos caracteres durante a primeira parte.

    Depois, cada caractere é removido da fila e empilhado.

    Se for uma letra, é convertido para minúscula usando tolower.

    Ao desempilhar, a ordem fica invertida, pois pilha segue LIFO.

    Se o caractere não for letra, como espaço, número ou pontuação, ele é
    mantido como está.

    O código não usa struct. A fila e a pilha são representadas apenas com
    vetores e variáveis de controle.
*/
```

---

# Prática 3

## Buscar e remover em fila

## Enunciado

Implemente funções para:

* verificar se um valor está presente na fila;
* remover um único elemento do início da fila;
* testar essas funções em um programa com menu.

---

## Código comentado

```c
#include <stdio.h>

#define MAX 50

/*
    Inicializa a fila.
*/
void inicializarFila(int *inicio, int *fim) {
    *inicio = 0;
    *fim = -1;
}

/*
    Verifica se a fila está vazia.
*/
int filaVazia(int inicio, int fim) {
    return fim < inicio;
}

/*
    Verifica se a fila está cheia.
*/
int filaCheia(int fim) {
    return fim == MAX - 1;
}

/*
    Insere um valor no fim da fila.
*/
void enfileirar(int fila[], int *fim, int valor) {

    if (filaCheia(*fim)) {
        printf("Fila cheia.\n");
        return;
    }

    (*fim)++;
    fila[*fim] = valor;
}

/*
    Lista os elementos da fila.
*/
void listar(int fila[], int inicio, int fim) {

    if (filaVazia(inicio, fim)) {
        printf("Fila vazia.\n");
        return;
    }

    printf("Fila: ");

    /*
        A fila deve ser listada do início até o fim.
    */
    for (int i = inicio; i <= fim; i++) {
        printf("%d ", fila[i]);
    }

    printf("\n");
}

/*
    Busca um valor na fila.

    Retorna 1 se encontrar.
    Retorna 0 se não encontrar.
*/
int buscar(int fila[], int inicio, int fim, int valor) {

    /*
        Percorre do início até o fim da fila.
    */
    for (int i = inicio; i <= fim; i++) {

        if (fila[i] == valor) {
            return 1;
        }
    }

    return 0;
}

/*
    Remove um elemento do início da fila.
*/
int desenfileirar(int fila[], int *inicio, int fim) {

    if (filaVazia(*inicio, fim)) {
        return -1;
    }

    /*
        O elemento removido deve ser o que está no início.
    */
    int valor = fila[*inicio];

    /*
        Avançamos o início.
    */
    (*inicio)++;

    return valor;
}

int main(void) {

    int fila[MAX];
    int inicio;
    int fim;

    int opcao;
    int valor;

    inicializarFila(&inicio, &fim);

    do {
        printf("\n1 - Inserir\n");
        printf("2 - Listar\n");
        printf("3 - Buscar\n");
        printf("4 - Remover\n");
        printf("0 - Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);

        switch (opcao) {

            case 1:
                printf("Valor: ");
                scanf("%d", &valor);
                enfileirar(fila, &fim, valor);
                break;

            case 2:
                listar(fila, inicio, fim);
                break;

            case 3:
                printf("Valor para buscar: ");
                scanf("%d", &valor);

                if (buscar(fila, inicio, fim, valor)) {
                    printf("Valor encontrado.\n");
                } else {
                    printf("Valor não encontrado.\n");
                }

                break;

            case 4:
                valor = desenfileirar(fila, &inicio, fim);

                if (valor == -1) {
                    printf("Fila vazia.\n");
                } else {
                    printf("Valor removido: %d\n", valor);
                }

                break;

            case 0:
                printf("Encerrando.\n");
                break;

            default:
                printf("Opção inválida.\n");
        }

    } while (opcao != 0);

    return 0;
}

/*
    Explicação final:

    Este programa implementa operações básicas de uma fila sequencial simples.

    A função enfileirar insere no fim.
    A função desenfileirar remove do início.
    A função buscar percorre do início até o fim procurando um valor.
    A função listar imprime os valores na ordem em que devem sair da fila.

    O comportamento FIFO é respeitado porque a remoção sempre ocorre na
    posição indicada por inicio.

    O retorno -1 em desenfileirar representa fila vazia. Nesta versão simples,
    isso funciona melhor quando os valores esperados não são negativos.

    A implementação usa apenas vetor, inicio e fim, sem struct.
*/
```
