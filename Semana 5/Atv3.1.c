/*
    Escreva um programa, que exiba o seguinte menu ao usuário:

    1. Soma
    2. Divisão
    3. Multiplicação
    4. Subtração
    5. Sair

    O usuário deverá informar 2 números após escolher a operação.
    O programa só pode ser encerrado quando o usuário escolher a opção de sair.
    Cada operação deverá ser uma subrotina.
    A entrada de dados, também deverá ser uma subrotina.

    NÃO USE VARIAVEIS GLOBAIS
*/


#include <stdio.h>
#include <locale.h>

void soma(int n, int n2){
   int result =  n + n2;
   printf("%d\n", result);
}

void sub(int n, int n2){
   int result =  n - n2;
   printf("%d", result);
}

void multip(int n, int n2){
   int result =  n * n2;
   printf("%d", result);
}

void divisao(int n, int n2){
   int result =  n / n2;
   printf("%d", result);
}

int operacao(){
    int n;
    printf("Insira um numero: \n");
    scanf("%d", &n);
    return n;
}

int main() {
    int num1, num2, opc;
    setlocale(LC_ALL, "Portuguese");
    do {
        printf("\nEscolha uma opcao: \n");
        printf("1. Soma.\n2. Divisão.\n3. Multiplicação.\n4. Subtração.\n5. Sair.");
        scanf("%d", &opc);

        switch(opc){
            case 1 : 
                num1 = operacao();
                num2 = operacao();
                soma(num1, num2);
                break;

            case 2 : 
                num1 = operacao();
                num2 = operacao();
                divisao(num1, num2);
                break;

            case 3 : 
                num1 = operacao();
                num2 = operacao();
                multip(num1, num2);
                break;

            case 4 : 
                num1 = operacao();
                num2 = operacao();
                sub(num1, num2);
                break;

            case 5 : 
                printf("Programa encerrado!");
                return 0;

            default :
                printf("Opcao invalida.");
                break;
        }

    }while (1);

}