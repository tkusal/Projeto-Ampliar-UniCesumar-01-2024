/*
    Escreva um código que exiba na tela um menu com as opções:

    1. Somar 2 numeros
    2. Multiplicar 2 numeros
    3. Encerrar

    O programa só poderá ser finalizado quando o usuário escolher a opção 3
*/

#include <stdio.h>
#include <locale.h>

int main (){
    setlocale (LC_ALL, "Portuguese");

    int opc, n1, n2;

    do {
        printf("Escolha uma opção: \n");
        printf("1. Somar\n2. Multiplicar\n3. Encerrar\n");
        scanf("%d", &opc);

        switch (opc) {
            case 1:
                printf("Digite o primeiro número inteiro: ");
                scanf("%d", &n1);
                
                printf("Digite o segundo número inteiro: ");
                scanf("%d", &n2);

                printf("%d + %d = %d\n", n1, n2, n1+n2);
                break;
            case 2:
                printf("Digite o primeiro número inteiro: ");
                scanf("%d", &n1);
                
                printf("Digite o segundo número inteiro: ");
                scanf("%d", &n2);

                printf("%d x %d = %d\n", n1, n2, n1*n2);
                break;
            case 3:
                printf("Encerrando o programa.");
                return 0;
                break;
            default:
                printf("Opção inválida.\n");
                break;          
        }

    } while(1);
     
}
