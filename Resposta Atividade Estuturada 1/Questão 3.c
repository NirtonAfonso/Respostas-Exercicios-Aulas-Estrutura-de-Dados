#include <stdio.h>
#include <string.h>

// a) Reutilização da struct exigida, atuando como o tipo de dado que 
// agrupa as informações de um único funcionário.
struct Funcionario {
    int codigo;
    char nome[50];
    float salario;
};

// Prototipação: Assinatura da função antes do main. 
// O asterisco (*) avisa que a função não receberá um funcionário comum, 
// mas sim o "endereço de memória" de onde o funcionário está guardado.
void aplicarAumento(struct Funcionario *f, float percentual);

int main(void) {
    // c) Declaração de uma variável isolada (não é um vetor desta vez, apenas um funcionário).
    struct Funcionario func;
    
    // Preenchimento manual dos dados conforme pedido na questão.
    func.codigo = 1001;
    func.salario = 3500.00;
    // Como 'nome' é um vetor de caracteres, a linguagem C não permite usar o sinal de igual (=).
    // A função strcpy (string copy) resolve isso copiando o texto desejado para dentro da variável.
    strcpy(func.nome, "Ana Paula Souza"); 
    
    // Impressão do estado inicial (salário base)
    printf("---- ANTES DO AUMENTO ----\n");
    printf("Funcionario: %s\n", func.nome);
    printf("Salario Original: R$ %.2f\n\n", func.salario);
    
    // O operador '&' (e comercial) significa "endereço de".
    // Em vez de enviar uma cópia dos dados da Ana Paula, enviamos o local da memória
    // onde ela está. Isso é o que garante que a alteração do salário ocorra "de verdade"
    // e reflita aqui dentro do escopo da main.
    aplicarAumento(&func, 10.0); 
    
    // Impressão após a execução da função para provar que a variável 'func' 
    // foi alterada de fora para dentro.
    printf("---- DEPOIS DO AUMENTO (10%%) ----\n");
    printf("Funcionario: %s\n", func.nome);
    printf("Salario Atualizado: R$ %.2f\n", func.salario);

    return 0;
}

// b) Implementação da função que altera o dado original usando ponteiros.
void aplicarAumento(struct Funcionario *f, float percentual) {
    // Passo 1: Cálculo matemático do aumento.
    // O operador '->' (seta) é a forma exigida pela linguagem C para acessar um campo
    // de uma struct quando estamos usando um ponteiro. Ele substitui a notação '(*f).salario'.
    // A fórmula pega a porcentagem (ex: 10), divide por 100 para virar decimal (0.10) 
    // e multiplica pelo salário original para descobrir o valor em Reais do aumento.
    float aumento = f->salario * (percentual / 100.0);
    
    // Passo 2: Atualização.
    // O salário antigo recebe ele mesmo somado ao valor do aumento que acabamos de calcular.
    f->salario = f->salario + aumento;
}