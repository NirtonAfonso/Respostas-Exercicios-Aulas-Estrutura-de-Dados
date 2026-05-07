# Atividade Prática – Listas Lineares Sequenciais

---

### Exercício 1

Crie um programa para gerenciar uma lista de **notas** (valores do tipo `float`). A lista deve ter capacidade máxima de **10 elementos**.

O programa deve oferecer um menu interativo com as seguintes opções:

```
1 – Inserir nota
2 – Listar notas
3 – Buscar nota
4 – Remover nota
5 – Sair
```

A lista deve começar vazia e o menu deve ser exibido repetidamente até que o usuário escolha a opção 5.

Funcionamento esperado de cada opção:

- **Inserir nota:** lê um valor do teclado e o insere na lista. Se a lista estiver cheia, exibe uma mensagem de erro e não realiza a inserção.
- **Listar notas:** exibe todos os valores atualmente armazenados.
- **Buscar nota:** lê um valor e informa em qual posição da lista ele se encontra (primeira ocorrência). Se o valor não estiver presente, exibe mensagem informando que não foi encontrado.
- **Remover nota:** lê um valor e remove a primeira ocorrência desse valor da lista. Se a lista estiver vazia ou o valor não existir, exibe mensagem de erro.

Organize o código utilizando funções específicas para cada operação. Lembre-se de passar os parâmetros adequadamente, utilizando ponteiros quando uma função precisar alterar a quantidade de elementos da lista.

---

### Exercício 2

Modifique o programa do **Exercício 1** para que a lista de notas **não aceite valores repetidos**. 

Implemente uma nova função de inserção com o seguinte protótipo:

```c
void inserirSemRepetir(float v[], float valor, int *quant, int max);
```

Essa função deve inserir `valor` apenas se ele ainda não existir na lista. Caso o valor já esteja presente, deve exibir uma mensagem de erro e não modificar a lista.

Adapte o menu para utilizar essa nova função no lugar da inserção original. As demais operações (listar, buscar, remover) podem ser mantidas sem alterações.

---

### Exercício 3

Ainda sobre o programa modificado no **Exercício 2**, acrescente uma nova funcionalidade de **remoção por índice**.

Adicione ao menu a seguinte opção:

```
5 – Remover nota por índice
```

(e ajuste a numeração da opção **Sair** para 6).

Implemente uma função com o protótipo:

```c
void removerPeloIndice(float v[], int *quant, int indice);
```

Requisitos da função:

- Verificar se o índice informado é válido (0 ≤ `indice` < `*quant`). Caso contrário, exibir mensagem de erro e encerrar a função.
- Remover o elemento da posição indicada, deslocando todos os elementos que estão à direita uma posição para a esquerda. Dessa forma, a ordem original dos demais elementos é mantida.
- Decrementar a quantidade de elementos da lista.

No programa principal, a opção de remoção por índice deve solicitar o índice ao usuário e chamar essa função. Exiba a lista antes e depois da remoção para confirmação.

---

### Exercício 4

Crie um novo programa para gerenciar uma lista de **alunos**. Diferentemente dos exercícios anteriores, agora cada elemento da lista será uma estrutura composta.

Defina a seguinte estrutura:

```c
typedef struct {
    int matricula;
    char nome[50];
    float nota;
} Aluno;
```

A lista deve ter capacidade máxima de **20 alunos** e **não pode haver dois alunos com a mesma matrícula**.

Implemente as seguintes funções:

```c
void inserirAluno(Aluno v[], Aluno novo, int *quant, int max);
void listarAlunos(Aluno v[], int quant);
int buscarPorMatricula(Aluno v[], int quant, int matricula);
void removerPorMatricula(Aluno v[], int *quant, int matricula);
```

Descrição do comportamento de cada função:

- `inserirAluno`: insere um novo aluno na lista apenas se sua matrícula ainda não estiver presente. Em caso de repetição, exibe mensagem de erro.
- `listarAlunos`: imprime matrícula, nome e nota de todos os alunos armazenados.
- `buscarPorMatricula`: retorna o índice do aluno que possui a matrícula informada. Se não existir, retorna `-1`.
- `removerPorMatricula`: remove o aluno cuja matrícula corresponde ao valor passado. A remoção deve preservar a ordem relativa dos demais alunos, deslocando os elementos seguintes uma posição para a esquerda. Se a lista estiver vazia ou a matrícula não for encontrada, exibe mensagem de erro.

O programa principal deve exibir um menu interativo com as seguintes opções:

```
1 – Inserir aluno
2 – Listar alunos
3 – Buscar aluno por matrícula
4 – Remover aluno por matrícula
5 – Sair
```

Para a inserção, os dados do aluno (matrícula, nome e nota) devem ser lidos do teclado. Utilize `strcpy` (da biblioteca `<string.h>`) para copiar o nome para a estrutura.

---

**Observações gerais**

- Em todos os exercícios, sempre que uma operação não puder ser concluída (lista cheia, vazia, elemento não encontrado, índice inválido etc.), exiba uma mensagem de erro clara e objetiva.
- Utilize passagem de parâmetros **por ponteiro** (`int *`) para variáveis que representam a quantidade de elementos e precisam ser alteradas dentro das funções.
- Organize o código em funções, respeitando os protótipos indicados e mantendo a lógica de cada operação separada.
