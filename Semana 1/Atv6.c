/*
Faça uma calculadora que execute as 4 operações aritméticas.
A calculadora deverá exibir um menu para o usuário escolher qual operação ele deseja fazer.
*/

//  STANDARD INPUT OUTPUT . HEADER

#include <stdio.h>
#include<locale.h>

int main() {
    // Definição de regional
    setlocale(LC_ALL, "Portuguese");

    // Declaração de variáveis
    float n1, n2, resultado;
    int opc;

    // Menu de escolha de operação    
    printf("Escolhe uma opção:\n1- Soma\n2- Subtração\n3- Multiplicação\n4- Divisão\n");
    scanf("%d", &opc);

    // Entrada dos números a serem calculados
    printf("Digite o primeiro número: ");
    scanf("%f", &n1);
    printf("Digite o segundo número: ");
    scanf("%f", &n2);

    // Estrutura Condicional com o processamento das operações
    switch(opc){
        case 1:
            resultado = n1+n2;
            printf("O resultado da soma: %.2f", resultado);
            break;
        case 2:            
            printf("O resultado da subtração: %.2f", n1-n2);
            break;
        case 3:
            resultado = n1*n2;
            printf("O resultado da multiplicação: %.2f", resultado);
            break;
        case 4:
            resultado = n1/n2;
            printf("O resultado da divisão: %.2f", resultado);
            break;
        default:
            printf("Operação inválida");
            break;
    }

    return 0;
}