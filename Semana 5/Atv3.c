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
*/


#include <stdio.h>
#include <locale.h>

int n, n2;

void soma(){
   int result =  n + n2;
   printf("%d\n", result);
}

void sub(){
   int result =  n - n2;
   printf("%d", result);
}

void multip(){
   int result =  n * n2;
   printf("%d", result);
}

void divisao(){
   int result =  n / n2;
   printf("%d", result);
}

void operacao(){
    printf("Insira um numero: \n");
    scanf("%d", &n);
    
    printf("Insira outro numero: \n");
    scanf("%d", &n2);
}

int main() {
    int opc;
    setlocale(LC_ALL, "Portuguese");
    do {
        printf("Escolha uma opcao: \n");
        printf("1. Soma.\n2. Divisão.\n3. Multiplicação.\n4. Subtração.\n5. Sair. \n ");
        scanf("%d", &opc);

        switch(opc){
            case 1 : 
                operacao();
                soma();
                break;

            case 2 : 
                operacao();
                divisao();
                break;

            case 3 : 
                operacao();
                multip();
                break;

            case 4 : 
                operacao();
                sub();
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