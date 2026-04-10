**a) Teste de mesa (As mudanças na memória passo a passo)**

Para entender o comportamento do programa, vamos mapear o valor das variáveis `a` e `b`, e o destino dos ponteiros `p` e `q` após a execução de cada linha de código:

| Linha de Código | Valor de `a` | Valor de `b` | Destino de `p` | Destino de `q` | O que aconteceu na memória? |
| :--- | :---: | :---: | :---: | :---: | :--- |
| `int a = 5, b = 12;` | 5 | 12 | N/A | N/A | Variáveis criadas e inicializadas com seus valores base. |
| `p = &a;` <br> `q = &b;` | 5 | 12 | `a` | `b` | `p` recebe o endereço de `a`. <br> `q` recebe o endereço de `b`. |
| `*p = *q + 3;` | **15** | 12 | `a` | `b` | Lemos o valor apontado por `q` (12), somamos 3 e guardamos (15) no local apontado por `p` (que é a variável `a`). |
| `b = *p * 2;` | 15 | **30** | `a` | `b` | Lemos o valor apontado por `p` (agora 15), multiplicamos por 2 e guardamos o resultado (30) diretamente na variável `b`. |
| `p = q;` | 15 | 30 | **`b`** | `b` | **Atenção aqui:** O ponteiro `p` muda de alvo. Ele copia o endereço que está em `q`. Agora, ambos apontam para `b`. |
| `*p = 10;` | 15 | **10** | `b` | `b` | Modificamos o valor no local apontado por `p`. Como `p` agora aponta para `b`, o valor de `b` é substituído por 10. |


**b) O que acontece na memória quando a instrução `p = q;` é executada?**

Pense nos ponteiros como **etiquetas** ou **placas de sinalização** que indicam onde um dado está guardado. 
Antes dessa instrução, a placa `p` indicava o caminho para a variável `a`, e a placa `q` indicava o caminho para a variável `b`. 

Ao executar `p = q;`, estamos dizendo: *"Copie o endereço de destino da placa `q` e coloque na placa `p`"*. Como resultado, **o ponteiro `p` deixa de apontar para `a` e passa a apontar para o mesmo lugar que `q`**. A partir deste momento, qualquer alteração feita usando `*p` ou `*q` afetará a mesma variável: a variável `b`.


**c) Quais serão os valores impressos na tela ao final da execução do programa?**

Observando o final do nosso teste de mesa, a variável `a` terminou com o valor 15 (modificada no início do código) e a variável `b` terminou com o valor 10 (modificada na última instrução através do ponteiro `p`).

A saída no console (terminal) será:
```text
A = 15
B = 10
```