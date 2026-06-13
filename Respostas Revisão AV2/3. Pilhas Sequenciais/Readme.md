# Gabarito Comentado – Tópico 3

## Pilhas Sequenciais

---

# 3.1 Questões teóricas

## 1) O que caracteriza uma pilha sequencial? Explique o conceito LIFO e como isso se diferencia de listas e filas.

Uma **pilha sequencial** é uma estrutura de dados implementada usando um **vetor** e uma variável de controle chamada, normalmente, de `topo`.

A pilha segue uma regra muito importante chamada **LIFO**.

LIFO significa:

```c
Last In, First Out
```

Em português:

```c
Último a entrar, primeiro a sair
```

Isso quer dizer que o último elemento inserido na pilha será o primeiro elemento removido.

Um exemplo simples é uma pilha de pratos.
Se colocamos um prato sobre o outro, o último prato colocado fica em cima. Quando vamos retirar um prato, normalmente retiramos primeiro o que está no topo.

Na programação, a ideia é a mesma.

Se empilhamos os valores nesta ordem:

```c
10
20
30
```

A pilha ficará assim:

```c
30  <- topo
20
10
```

O primeiro valor a sair será o `30`, porque ele foi o último a entrar.

Em uma pilha sequencial, usamos um vetor para armazenar os elementos:

```c
int pilha[50];
```

E usamos uma variável `topo` para indicar a posição do último elemento inserido:

```c
int topo;
```

Quando a pilha está vazia, normalmente fazemos:

```c
topo = -1;
```

Isso indica que não existe nenhum elemento na pilha.

Quando inserimos o primeiro valor, o `topo` passa para `0`.
Quando inserimos o segundo valor, o `topo` passa para `1`.
E assim por diante.

A diferença entre pilha, lista e fila está na forma de inserir e remover.

Em uma **lista**, dependendo da implementação, podemos inserir e remover em várias posições.

Em uma **fila**, o primeiro elemento inserido é o primeiro a sair.
Esse comportamento é chamado de **FIFO**.

Em uma **pilha**, o último elemento inserido é o primeiro a sair.
Esse comportamento é chamado de **LIFO**.

Resumo:

| Estrutura | Regra de remoção                        | Exemplo             |
| --------- | --------------------------------------- | ------------------- |
| Lista     | Pode remover de diferentes posições     | Lista de notas      |
| Fila      | Primeiro que entra é o primeiro que sai | Fila de atendimento |
| Pilha     | Último que entra é o primeiro que sai   | Pilha de pratos     |

---

## 2) Defina as operações inicializar, empilhar e desempilhar. Indique o que acontece com o índice `topo`.

Em uma pilha sequencial, as principais operações são:

* inicializar;
* empilhar;
* desempilhar.

A operação **inicializar** prepara a pilha para ser usada.

Como a pilha começa vazia, fazemos:

```c
topo = -1;
```

O valor `-1` é usado porque nenhum elemento ocupa a pilha.
Como o primeiro índice válido de um vetor em C é `0`, usar `-1` indica que ainda não existe posição ocupada.

Exemplo:

```c
void inicializarPilha(int *topo) {
    *topo = -1;
}
```

Usamos ponteiro porque a função precisa alterar o valor original da variável `topo`.

A operação **empilhar**, também chamada de `push`, insere um novo valor no topo da pilha.

Para empilhar, fazemos:

1. Verificar se a pilha não está cheia;
2. Aumentar o `topo`;
3. Inserir o valor na posição indicada pelo novo `topo`.

Exemplo:

```c
(*topo)++;
pilha[*topo] = valor;
```

A ordem é importante.
Primeiro aumentamos o `topo`, depois colocamos o valor.

Se fizéssemos o contrário, poderíamos sobrescrever a posição errada.

A operação **desempilhar**, também chamada de `pop`, remove o valor que está no topo da pilha.

Para desempilhar, fazemos:

1. Verificar se a pilha não está vazia;
2. Guardar o valor que está no topo;
3. Diminuir o `topo`;
4. Retornar o valor removido.

Exemplo:

```c
valor = pilha[*topo];
(*topo)--;
```

Se o topo vale `2`, significa que o último elemento inserido está em `pilha[2]`.
Depois de remover esse valor, o topo passa a valer `1`.

Assim, a pilha passa a considerar que o elemento da posição `2` não faz mais parte dela.

---

## 3) Cite pelo menos três aplicações práticas do uso de pilhas em computação.

As pilhas são usadas em vários problemas de programação porque são úteis quando precisamos inverter uma ordem ou controlar o último elemento inserido.

Uma aplicação comum é o comando **desfazer**.

Em um editor de texto, por exemplo, a última ação feita deve ser a primeira a ser desfeita.
Isso segue exatamente a lógica da pilha: o último a entrar é o primeiro a sair.

Outra aplicação é a **conversão de decimal para binário**.

Quando dividimos um número por `2`, os restos aparecem na ordem inversa da resposta final.
A pilha ajuda porque permite empilhar os restos e depois desempilhar para mostrar os bits na ordem correta.

Exemplo:

```c
13 / 2 = resto 1
6  / 2 = resto 0
3  / 2 = resto 1
1  / 2 = resto 1
```

Os restos aparecem como:

```c
1 0 1 1
```

Ao desempilhar, conseguimos imprimir corretamente:

```c
1101
```

Outra aplicação é a verificação de **parênteses balanceados**.

Quando encontramos um parêntese de abertura `(`, empilhamos.
Quando encontramos um fechamento `)`, precisamos remover um parêntese de abertura da pilha.

Se tentarmos fechar e a pilha estiver vazia, existe erro.
Se ao final ainda houver algo na pilha, também existe erro.

Pilhas também são usadas para verificar palíndromos, inverter palavras e avaliar expressões em notação pós-fixa.

---

# 3.2 Questões práticas – Pilhas Sequenciais


---

## Prática 1: Conversão de decimal para binário usando pilha

**Enunciado**
Implemente um programa em C que leia um número inteiro positivo e converta esse número para binário usando uma pilha.

A lógica esperada é:

1. Ler um número decimal positivo;
2. Dividir esse número sucessivamente por 2;
3. Empilhar os restos das divisões;
4. Desempilhar os restos para mostrar o número binário na ordem correta.

**Código comentado**

```c
#include <stdio.h>

/*
    Incluímos a biblioteca stdio.h porque o programa usa:

    printf -> para mostrar mensagens na tela;
    scanf  -> para ler valores digitados pelo usuário.

    Sem essa biblioteca, o compilador não reconheceria corretamente
    essas funções de entrada e saída.
*/

/*
    MAX define o tamanho máximo da pilha.

    Como a pilha será representada por um vetor, precisamos definir
    previamente quantas posições ela poderá armazenar.

    Neste exercício, usamos 32 porque um número inteiro comum pode ser
    representado usando até 32 bits.

    Poderíamos usar um valor maior, como 50 ou 100, mas 32 já é suficiente
    para o objetivo didático da conversão de inteiro para binário.
*/
#define MAX 32

/*
    Função inicializarPilha

    Objetivo:
    Preparar a pilha para ser usada.

    Parâmetro:
    int *topo

    O topo é passado por ponteiro porque a função precisa alterar o valor
    da variável original que está na função main.

    Se fosse usado apenas:

        int topo

    a função receberia uma cópia do valor. Nesse caso, mudar topo dentro
    da função não mudaria o topo original do main.
*/
void inicializarPilha(int *topo) {

    /*
        Em pilhas sequenciais, usamos topo = -1 para representar pilha vazia.

        Por que -1?

        Porque o primeiro índice válido de um vetor em C é 0.

        Se topo fosse 0 no início, pareceria que já existe um elemento na
        posição pilha[0].

        Então:
        topo = -1  -> pilha vazia
        topo = 0   -> existe um elemento na posição 0
        topo = 1   -> existem elementos nas posições 0 e 1
    */
    *topo = -1;
}

/*
    Função pilhaVazia

    Objetivo:
    Verificar se a pilha está vazia.

    Parâmetro:
    int topo

    Aqui não precisamos de ponteiro porque a função apenas consulta o valor
    do topo. Ela não altera o topo.
*/
int pilhaVazia(int topo) {

    /*
        A pilha está vazia quando topo é igual a -1.

        A expressão topo == -1 retorna:
        1 se for verdadeira;
        0 se for falsa.

        Em C, 1 representa verdadeiro e 0 representa falso.
    */
    return topo == -1;
}

/*
    Função pilhaCheia

    Objetivo:
    Verificar se a pilha está cheia.

    A pilha está cheia quando o topo está na última posição válida do vetor.

    Se o vetor tem MAX posições, seus índices vão de 0 até MAX - 1.
*/
int pilhaCheia(int topo) {

    /*
        Se topo for igual a MAX - 1, significa que a última posição já
        está ocupada.

        Nesse caso, não há mais espaço para empilhar.
    */
    return topo == MAX - 1;
}

/*
    Função push

    Objetivo:
    Empilhar um valor, ou seja, inserir um valor no topo da pilha.

    Parâmetros:

    int pilha[]:
        vetor que armazena os elementos da pilha.

    int *topo:
        ponteiro para a variável que controla o topo.

    int valor:
        valor que será inserido.

    O topo precisa ser ponteiro porque empilhar altera o topo.
*/
void push(int pilha[], int *topo, int valor) {

    /*
        Antes de inserir, verificamos se a pilha está cheia.

        Se não fizermos essa verificação, o programa pode tentar gravar
        fora do vetor, causando erro ou comportamento inesperado.
    */
    if (pilhaCheia(*topo)) {
        printf("Pilha cheia.\n");
        return;
    }

    /*
        Para empilhar corretamente, primeiro incrementamos o topo.

        Exemplo:
        topo inicialmente vale -1.

        Ao empilhar o primeiro valor:
        (*topo)++ faz topo passar para 0.

        Então o primeiro valor será colocado em pilha[0].
    */
    (*topo)++;

    /*
        Agora colocamos o valor na posição indicada pelo topo.

        Essa posição é a nova posição do topo da pilha.
    */
    pilha[*topo] = valor;
}

/*
    Função pop

    Objetivo:
    Desempilhar um valor, ou seja, remover e retornar o valor que está no topo.

    Parâmetros:

    int pilha[]:
        vetor que representa a pilha.

    int *topo:
        ponteiro para o topo da pilha.

    Retorno:
        retorna o valor removido do topo.

    Neste exercício, se a pilha estiver vazia, retornamos -1.
    Como os valores empilhados são restos da divisão por 2, só teremos 0 e 1.
    Então -1 funciona como um sinal simples de erro.
*/
int pop(int pilha[], int *topo) {

    /*
        Antes de remover, verificamos se a pilha está vazia.

        Não é possível remover um elemento de uma pilha vazia.
    */
    if (pilhaVazia(*topo)) {
        return -1;
    }

    /*
        Guardamos o valor do topo em uma variável auxiliar.

        Isso é necessário porque, depois que diminuirmos o topo, aquela
        posição deixará de ser considerada parte da pilha.
    */
    int valor = pilha[*topo];

    /*
        Diminuímos o topo.

        Isso faz a pilha "esquecer" o elemento que estava no topo.
        O valor ainda pode continuar fisicamente no vetor, mas não é mais
        considerado parte da pilha.
    */
    (*topo)--;

    /*
        Retornamos o valor que foi removido.
    */
    return valor;
}

int main(void) {

    /*
        Vetor usado para representar a pilha.

        Não usamos struct.
        A pilha é formada apenas por:
        - vetor pilha[MAX];
        - variável topo.
    */
    int pilha[MAX];

    /*
        Variável que controla a posição do topo da pilha.
    */
    int topo;

    /*
        Variável que receberá o número decimal digitado pelo usuário.
    */
    int numero;

    /*
        Antes de qualquer operação, a pilha precisa ser inicializada.

        Se não inicializarmos o topo, ele pode começar com lixo de memória.
        Isso faria o programa acreditar que a pilha já tem elementos,
        mesmo estando vazia.
    */
    inicializarPilha(&topo);

    printf("Digite um número inteiro positivo: ");
    scanf("%d", &numero);

    /*
        O exercício pede um número positivo.

        Se o usuário digitar zero ou número negativo, a conversão não será feita.
    */
    if (numero <= 0) {
        printf("Número inválido.\n");
        return 0;
    }

    /*
        Guardamos uma cópia do número original.

        Por quê?

        Porque a variável numero será alterada durante as divisões por 2.
        Se não guardássemos uma cópia, perderíamos o valor digitado inicialmente.
    */
    int original = numero;

    /*
        Processo de conversão decimal para binário.

        A conversão é feita dividindo o número por 2 repetidamente.

        O resto da divisão por 2 será sempre 0 ou 1.
        Esses restos formam os bits do número binário.
    */
    while (numero > 0) {

        /*
            Calcula o resto da divisão por 2.

            Exemplo:
            13 % 2 = 1
            6  % 2 = 0
            3  % 2 = 1
            1  % 2 = 1
        */
        int resto = numero % 2;

        /*
            Empilhamos o resto.

            Os restos aparecem na ordem inversa da resposta final.
            Por isso, a pilha é usada para inverter essa ordem depois.
        */
        push(pilha, &topo, resto);

        /*
            Atualizamos o número dividindo por 2.

            Como numero é inteiro, a divisão descarta a parte decimal.

            Exemplo:
            13 / 2 = 6
            6  / 2 = 3
            3  / 2 = 1
            1  / 2 = 0
        */
        numero = numero / 2;
    }

    printf("%d em binário: ", original);

    /*
        Agora desempilhamos todos os restos.

        Como a pilha segue LIFO, o último resto empilhado será o primeiro
        a ser impresso.

        Isso corrige a ordem dos bits.
    */
    while (!pilhaVazia(topo)) {
        printf("%d", pop(pilha, &topo));
    }

    printf("\n");

    return 0;
}

/*
    Explicação final:

    A conversão decimal para binário gera os bits de trás para frente.

    Por exemplo, para o número 13:

    13 / 2 = 6, resto 1
    6  / 2 = 3, resto 0
    3  / 2 = 1, resto 1
    1  / 2 = 0, resto 1

    Os restos aparecem assim:

        1 0 1 1

    Mas o binário correto de 13 é:

        1 1 0 1

    Como a pilha remove primeiro o último valor inserido, ela inverte
    a ordem dos restos.

    Se imprimíssemos os restos diretamente dentro do while, o resultado
    sairia invertido.

    A implementação segue o padrão da aula:

    - vetor para guardar os dados;
    - variável topo para controlar a pilha;
    - função push para empilhar;
    - função pop para desempilhar;
    - ponteiro quando a função precisa alterar o topo.
*/

```

---

## Prática 2: Verificação de parênteses usando pilha

**Enunciado**
Utilize uma pilha para verificar se uma expressão possui parênteses balanceados.
A regra é:

* Quando encontrar `(`, empilhar;
* Quando encontrar `)`, desempilhar;
* Se aparecer `)` e a pilha estiver vazia, a expressão está incorreta;
* Se ao final ainda houver elementos na pilha, a expressão também está incorreta.

**Código comentado**

```c
#include <stdio.h>

/*
    A biblioteca stdio.h será usada para printf e fgets.
*/

/*
    MAX define o tamanho máximo da expressão e da pilha.

    A expressão poderá ter até 99 caracteres úteis, pois uma string em C
    também precisa guardar o caractere especial '\0' no final.
*/
#define MAX 100

/*
    Função inicializarPilha

    Define topo como -1, indicando pilha vazia.
*/
void inicializarPilha(int *topo) {
    *topo = -1;
}

/*
    Função pilhaVazia

    Retorna verdadeiro quando topo é -1.
*/
int pilhaVazia(int topo) {
    return topo == -1;
}

/*
    Função pilhaCheia

    Retorna verdadeiro quando topo chegou à última posição válida.
*/
int pilhaCheia(int topo) {
    return topo == MAX - 1;
}

/*
    Função push para pilha de caracteres.

    Neste exercício, a pilha guardará apenas parênteses de abertura '('.
*/
void push(char pilha[], int *topo, char valor) {

    /*
        Verificamos se existe espaço antes de empilhar.
    */
    if (pilhaCheia(*topo)) {
        printf("Pilha cheia.\n");
        return;
    }

    /*
        Primeiro incrementamos o topo.
    */
    (*topo)++;

    /*
        Depois colocamos o caractere na posição do topo.
    */
    pilha[*topo] = valor;
}

/*
    Função pop para pilha de caracteres.

    Remove o caractere que está no topo.
*/
char pop(char pilha[], int *topo) {

    /*
        Se a pilha estiver vazia, retornamos '\0'.

        Esse retorno representa ausência de caractere.
    */
    if (pilhaVazia(*topo)) {
        return '\0';
    }

    /*
        Guardamos o caractere do topo.
    */
    char valor = pilha[*topo];

    /*
        Diminuímos o topo, removendo logicamente o elemento.
    */
    (*topo)--;

    /*
        Retornamos o caractere removido.
    */
    return valor;
}

int main(void) {

    /*
        Vetor que guarda a expressão digitada pelo usuário.
    */
    char expressao[MAX];

    /*
        Vetor usado como pilha.

        Como vamos verificar parênteses, a pilha será de char.
    */
    char pilha[MAX];

    /*
        Variável que controla o topo da pilha.
    */
    int topo;

    /*
        Inicializamos a pilha antes de usar.
    */
    inicializarPilha(&topo);

    printf("Digite uma expressão: ");

    /*
        Usamos fgets para ler a linha inteira.

        Diferente do scanf("%s"), o fgets consegue ler espaços.

        Exemplo:
        (a + b) * (c - d)

        Se usássemos scanf("%s"), ele pararia no primeiro espaço.
    */
    fgets(expressao, MAX, stdin);

    /*
        Percorremos a expressão caractere por caractere.

        Em C, uma string termina com o caractere especial '\0'.
        Por isso, o laço continua até encontrar esse caractere.
    */
    for (int i = 0; expressao[i] != '\0'; i++) {

        /*
            Se o caractere atual for '(', significa que abrimos
            um novo parêntese.

            Então empilhamos esse caractere.
        */
        if (expressao[i] == '(') {
            push(pilha, &topo, expressao[i]);
        }

        /*
            Se o caractere atual for ')', significa que precisamos fechar
            algum parêntese que foi aberto anteriormente.
        */
        else if (expressao[i] == ')') {

            /*
                Se a pilha está vazia, significa que apareceu um fechamento
                sem abertura correspondente.

                Exemplo:
                a + b)

                Nesse caso, a expressão é inválida.
            */
            if (pilhaVazia(topo)) {
                printf("Expressão inválida.\n");
                return 0;
            }

            /*
                Se a pilha não está vazia, removemos um '('.

                Isso representa que encontramos um par correto:
                um abre parêntese e um fecha parêntese.
            */
            pop(pilha, &topo);
        }

        /*
            Qualquer outro caractere é ignorado.

            Letras, números, operadores e espaços não interferem
            no balanceamento dos parênteses.
        */
    }

    /*
        Depois de percorrer toda a expressão, verificamos se a pilha ficou vazia.

        Se ficou vazia, todos os parênteses abertos foram fechados.

        Se ainda há elementos, significa que sobraram '(' sem fechamento.
    */
    if (pilhaVazia(topo)) {
        printf("Expressão válida.\n");
    } else {
        printf("Expressão inválida.\n");
    }

    return 0;
}

/*
    Explicação final:

    A pilha é adequada para esse problema porque o último parêntese aberto
    deve ser o primeiro a ser fechado.

    Exemplo:

        (a + (b * c))

    O parêntese antes de b foi aberto depois do primeiro parêntese.
    Portanto, ele precisa ser fechado antes.

    Isso é exatamente o comportamento LIFO da pilha.

    Se encontrarmos ')', precisamos ter um '(' disponível na pilha.
    Se não houver, a expressão está incorreta.

    Se ao final sobrarem '(' na pilha, também está incorreta.

    Se usássemos apenas um contador simples, ele poderia dizer que a quantidade
    de '(' e ')' é igual, mas não garantiria que a ordem está correta.

    Exemplo:

        ) (

    Tem um abre e um fecha, mas a ordem está errada.

    A pilha resolve esse problema porque controla a ordem correta dos pares.
*/

```

---

## Prática 3: Verificação de palíndromo usando pilha

**Enunciado**
Escreva um programa que leia uma palavra e verifique se ela é um palíndromo.
Uma palavra é palíndromo quando pode ser lida da mesma forma da esquerda para a direita e da direita para a esquerda.

**Exemplos:**

* arara
* radar
* ovo

A ideia do exercício é:

1. Empilhar a primeira metade da palavra;
2. Ignorar o caractere central se a palavra tiver tamanho ímpar;
3. Comparar a segunda metade com os caracteres desempilhados.

**Código comentado**

```c
#include <stdio.h>
#include <string.h>

/*
    stdio.h é usado para printf e scanf.

    string.h é usado porque precisamos da função strlen.

    strlen calcula o tamanho de uma string.
*/

/*
    MAX define o tamanho máximo da palavra e da pilha.
*/
#define MAX 100

/*
    Função inicializarPilha

    Coloca topo em -1, indicando pilha vazia.
*/
void inicializarPilha(int *topo) {
    *topo = -1;
}

/*
    Função push

    Empilha um caractere.
*/
void push(char pilha[], int *topo, char valor) {

    /*
        Verifica se ainda existe espaço na pilha.

        Se topo for MAX - 1, a pilha está cheia.
    */
    if (*topo < MAX - 1) {

        /*
            Primeiro incrementamos o topo.
        */
        (*topo)++;

        /*
            Depois colocamos o caractere na posição do topo.
        */
        pilha[*topo] = valor;
    }
}

/*
    Função pop

    Desempilha um caractere.
*/
char pop(char pilha[], int *topo) {

    /*
        Só podemos desempilhar se topo for maior ou igual a 0.
    */
    if (*topo >= 0) {

        /*
            Guardamos o caractere do topo.
        */
        char valor = pilha[*topo];

        /*
            Diminuímos o topo.
        */
        (*topo)--;

        /*
            Retornamos o caractere removido.
        */
        return valor;
    }

    /*
        Se a pilha estiver vazia, retornamos '\0'.
    */
    return '\0';
}

int main(void) {

    /*
        Vetor que armazenará a palavra digitada.
    */
    char palavra[MAX];

    /*
        Vetor usado como pilha.
    */
    char pilha[MAX];

    /*
        Variável que controla o topo da pilha.
    */
    int topo;

    /*
        Inicializamos a pilha.
    */
    inicializarPilha(&topo);

    printf("Digite uma palavra: ");

    /*
        scanf com %s lê uma palavra sem espaços.

        Para este exercício, isso é suficiente, pois estamos analisando
        apenas uma palavra.
    */
    scanf("%s", palavra);

    /*
        strlen retorna o tamanho da palavra.

        Exemplo:
        strlen("arara") retorna 5.
    */
    int tamanho = strlen(palavra);

    /*
        metade indica quantos caracteres serão empilhados.

        Como usamos divisão inteira, se o tamanho for ímpar, a parte decimal
        é descartada.

        Exemplo:
        tamanho = 5
        metade = 5 / 2 = 2

        Então empilhamos apenas os dois primeiros caracteres.
    */
    int metade = tamanho / 2;

    /*
        Empilhamos a primeira metade da palavra.

        Exemplo:
        palavra = arara

        posições:
        palavra[0] = a
        palavra[1] = r
        palavra[2] = a
        palavra[3] = r
        palavra[4] = a

        metade = 2

        Serão empilhados:
        palavra[0] e palavra[1]
    */
    for (int i = 0; i < metade; i++) {
        push(pilha, &topo, palavra[i]);
    }

    /*
        Agora precisamos descobrir onde começa a segunda metade da palavra.

        Se o tamanho for par:

            exemplo: abba
            tamanho = 4
            metade = 2

            primeira metade: posições 0 e 1
            segunda metade: posições 2 e 3

            então a segunda metade começa em metade.

        Se o tamanho for ímpar:

            exemplo: arara
            tamanho = 5
            metade = 2

            primeira metade: posições 0 e 1
            caractere central: posição 2
            segunda metade: posições 3 e 4

            então a segunda metade começa em metade + 1.

        O caractere central é ignorado porque ele não precisa ser comparado.
    */
    int inicioSegundaMetade;

    if (tamanho % 2 == 0) {
        inicioSegundaMetade = metade;
    } else {
        inicioSegundaMetade = metade + 1;
    }

    /*
        Agora comparamos a segunda metade com os caracteres desempilhados.

        A pilha inverte a ordem da primeira metade.

        Isso é exatamente o que precisamos para comparar com a segunda metade.
    */
    for (int i = inicioSegundaMetade; i < tamanho; i++) {

        /*
            Retiramos um caractere do topo da pilha.
        */
        char valor = pop(pilha, &topo);

        /*
            Comparamos o caractere desempilhado com o caractere atual
            da segunda metade.

            Se forem diferentes, a palavra não é palíndromo.
        */
        if (valor != palavra[i]) {
            printf("Não é palíndromo.\n");
            return 0;
        }
    }

    /*
        Se todas as comparações deram certo, a palavra é palíndromo.
    */
    printf("É palíndromo.\n");

    return 0;
}

/*
    Explicação final:

    O programa usa pilha porque a pilha inverte a ordem dos caracteres.

    Para uma palavra como:

        arara

    A primeira metade é:

        a r

    Ao empilhar:
        primeiro entra a
        depois entra r

    Ao desempilhar:
        primeiro sai r
        depois sai a

    Isso forma:

        r a

    Que pode ser comparado com a segunda metade da palavra:

        r a

    Como os caracteres coincidem, a palavra é palíndromo.

    Se a palavra fosse:

        casa

    Primeira metade:
        c a

    Desempilhando:
        a c

    Segunda metade:
        s a

    Como a primeira comparação já falha, o programa informa que não é
    palíndromo.

    Se tentássemos comparar a primeira metade diretamente sem pilha,
    a ordem estaria errada.

    A pilha resolve justamente porque inverte a ordem dos elementos.
*/

```

---

## Prática 4: Avaliação de expressão pós-fixa usando pilha

**Enunciado**
Implemente um avaliador de expressões pós-fixas usando pilha.

Considere:

* Operandos de 0 a 9;
* Operadores `+`, `-`, `*` e `/`.

**Exemplo:** `23+5*`
Essa expressão representa: `(2 + 3) * 5`
Resultado: `25`

**Código comentado**

```c
#include <stdio.h>
#include <ctype.h>

/*
    stdio.h é usado para printf e scanf.

    ctype.h é usado para a função isdigit.

    isdigit verifica se um caractere representa um número de 0 a 9.
*/

/*
    MAX define o tamanho máximo da expressão e da pilha.
*/
#define MAX 100

/*
    Função inicializarPilha

    Coloca topo em -1, indicando que a pilha está vazia.
*/
void inicializarPilha(int *topo) {
    *topo = -1;
}

/*
    Função push

    Empilha um número inteiro.
*/
void push(int pilha[], int *topo, int valor) {

    /*
        Verificamos se ainda existe espaço.

        Se topo estiver na última posição, não podemos inserir.
    */
    if (*topo < MAX - 1) {

        /*
            Incrementamos o topo.
        */
        (*topo)++;

        /*
            Guardamos o valor na posição do topo.
        */
        pilha[*topo] = valor;
    }
}

/*
    Função pop

    Desempilha um número inteiro.
*/
int pop(int pilha[], int *topo) {

    /*
        Verifica se existe elemento para remover.
    */
    if (*topo >= 0) {

        /*
            Guarda o valor do topo.
        */
        int valor = pilha[*topo];

        /*
            Diminui o topo.
        */
        (*topo)--;

        /*
            Retorna o valor removido.
        */
        return valor;
    }

    /*
        Se a pilha estiver vazia, retornamos 0.

        Neste exercício, consideramos que a expressão digitada está correta.
        Em um programa mais completo, seria possível tratar esse erro com
        mensagens específicas.
    */
    return 0;
}

int main(void) {

    /*
        Vetor de caracteres que armazenará a expressão pós-fixa.

        Exemplo:
        23+5*
    */
    char expressao[MAX];

    /*
        Vetor de inteiros usado como pilha.

        Aqui a pilha armazena números, não caracteres.
    */
    int pilha[MAX];

    /*
        Variável que controla o topo da pilha.
    */
    int topo;

    /*
        Inicializamos a pilha.
    */
    inicializarPilha(&topo);

    printf("Digite a expressão pós-fixa: ");

    /*
        Lemos a expressão como uma string.

        scanf("%s") lê até encontrar espaço.

        Isso significa que este programa espera expressões sem espaço,
        como:

            23+5*

        e não:

            2 3 + 5 *
    */
    scanf("%s", expressao);

    /*
        Percorremos cada caractere da expressão.
    */
    for (int i = 0; expressao[i] != '\0'; i++) {

        /*
            c recebe o caractere atual.
        */
        char c = expressao[i];

        /*
            Verificamos se c é um dígito.

            Exemplo:
            se c for '2', isdigit(c) retorna verdadeiro.
        */
        if (isdigit(c)) {

            /*
                Em C, '2' não é o mesmo que o número 2.

                '2' é um caractere, armazenado por um código.

                Para transformar o caractere numérico em número inteiro,
                fazemos:

                    c - '0'

                Exemplo:
                    '2' - '0' = 2
                    '7' - '0' = 7

                Se empilhássemos apenas c, estaríamos empilhando o código
                do caractere, e não o número que queremos calcular.
            */
            push(pilha, &topo, c - '0');
        }

        /*
            Se não for número, tratamos como operador.
        */
        else {

            /*
                Quando encontramos um operador em uma expressão pós-fixa,
                precisamos retirar dois operandos da pilha.

                A ordem é muito importante.

                O primeiro pop retorna o segundo operando.
                O segundo pop retorna o primeiro operando.

                Exemplo:
                expressão: 52-

                Primeiro empilha 5.
                Depois empilha 2.
                Quando aparece -, fazemos:

                    b = 2
                    a = 5

                Resultado:
                    a - b = 5 - 2 = 3

                Se fizéssemos b - a, o resultado seria 2 - 5 = -3,
                que estaria errado.
            */
            int b = pop(pilha, &topo);
            int a = pop(pilha, &topo);

            /*
                resultado guardará o valor da operação.
            */
            int resultado = 0;

            /*
                O switch escolhe a operação de acordo com o operador encontrado.
            */
            switch (c) {

                case '+':
                    resultado = a + b;
                    break;

                case '-':
                    resultado = a - b;
                    break;

                case '*':
                    resultado = a * b;
                    break;

                case '/':
                    resultado = a / b;
                    break;

                default:
                    /*
                        Se o caractere não for operador válido, encerramos.
                    */
                    printf("Operador inválido.\n");
                    return 0;
            }

            /*
                Depois de calcular, empilhamos o resultado.

                Esse resultado pode ser usado em uma próxima operação.
            */
            push(pilha, &topo, resultado);
        }
    }

    /*
        Depois que a expressão inteira foi processada, o resultado final
        estará no topo da pilha.

        Então fazemos pop para obter esse resultado.
    */
    printf("Resultado: %d\n", pop(pilha, &topo));

    return 0;
}

/*
    Explicação final:

    Em expressões pós-fixas, os operadores aparecem depois dos operandos.

    Exemplo:

        23+

    significa:

        2 + 3

    A pilha é usada para guardar os operandos até que apareça um operador.

    Quando aparece um número, empilhamos.

    Quando aparece um operador:
    - removemos dois valores da pilha;
    - aplicamos a operação;
    - empilhamos o resultado.

    Exemplo com 23+5*:

    Lê 2:
        empilha 2

    Lê 3:
        empilha 3

    Lê +:
        desempilha 3 e 2
        calcula 2 + 3 = 5
        empilha 5

    Lê 5:
        empilha 5

    Lê *:
        desempilha 5 e 5
        calcula 5 * 5 = 25
        empilha 25

    Ao final, o resultado é 25.

    A ordem dos operandos é importante principalmente em subtração e divisão.

    Por isso usamos:

        b = pop(...)
        a = pop(...)

    e calculamos:

        a operador b

    A implementação segue o padrão da aula:
    vetor de inteiros para a pilha, variável topo e funções push/pop.
*/

```