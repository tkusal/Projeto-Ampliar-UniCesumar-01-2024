/* 
    Escreva um algoritmo em C  que converta temperatura Celsius para Fahrenheit e vice-versa.
    O algoritmo deve permitir que o usuário escolha o tipo de conversão e permitir ao usuário fazer quantas conversões ele achar necessárias antes de finalizar o programa.
*/

#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "portuguese");

    int opc;
    float temp, resultado;

    do {
        printf("Escolha uma opção:\n");
        printf("1. Converter Celsius para Fahrenheit\n");
        printf("2. Converter Fahrenheit para Celsius\n");
        printf("0. Sair\n");
        scanf("%d", &opc);

        if (opc != 0) {
            printf("\nDigite a temperatura:\n");
            scanf("%f", &temp);
        }

        switch (opc) {
            case 1:
                resultado = temp * 1.8 + 32;
                printf("Temperatura em Fahrenheit: %.2f\n", resultado);
                break;
            case 2:
                resultado = (temp - 26) / 2;
                printf("Temperatura em Celsius: %.2f\n", resultado);
                break;
            case 0:
                printf("Encerrando...\n");
                system("pause");
                return 0;
            default:
                printf("Opção inválida!\n");
                system("pause");
                break;
        }
    } while(1);

}