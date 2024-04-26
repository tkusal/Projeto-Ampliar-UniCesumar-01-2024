/* 
    Faça um algoritmo em C que apresente um menu de opções para o usuário.
    Dentre as opções, terá: soma, subtração, multiplicação, divisão e raiz quadrada.
    Ao escolher o tipo de operação aritmética, o usuário deverá entrar com um ou mais valores para realizar os cálculos.
    Este programa só poderá ser encerrado se o usuário escolher a opção 0 no menu.
*/

#include <stdio.h>
#include <locale.h>
#include <math.h>

void entradaValores(int opcao, float *valor1, float *valor2);

int main() {
    setlocale(LC_ALL, "portuguese");

    int opc = 0, erro;
    float resultado, valor1, valor2;
    
    do {
        system("cls");
        erro = 0;

        printf("Escolha uma opção:\n");
        printf("0. Sair\n");
        printf("1. Soma\n");
        printf("2. Subtração\n");
        printf("3. Multiplicação\n");
        printf("4. Divisão\n");
        printf("5. Raiz quadrada\n");

        scanf("%d", &opc);
        while (getchar() != '\n' && getchar() != EOF);
        system("cls");

        switch (opc) {
            case 0:
                printf("\n\nEncerrando...\n");
                system("pause");
                return 0;
                break;
            case 1:
                printf("Operação: soma\n");
                entradaValores(opc, &valor1, &valor2);
                resultado = valor1 + valor2;
                break;
            case 2:
                printf("Operação: subtração\n");
                entradaValores(opc, &valor1, &valor2);
                resultado = valor1 - valor2;
                break;
            case 3:
                printf("Operação: multiplicação\n");
                entradaValores(opc, &valor1, &valor2);
                resultado = valor1 * valor2;
                break;
            case 4:
                printf("Operação: divisão\n");
                entradaValores(opc, &valor1, &valor2);
                if (valor2 == 0) {
                    printf("Não é possível dividir por 0! (Indefinido)\n");
                    erro = 1;
                    break;
                }
                resultado = valor1 / valor2;
                break;
            case 5:
                printf("Operação: raiz quadrada\n");
                entradaValores(opc, &valor1, &valor2);
                if (valor1 < 0) {
                    printf("Não é possível calcular a raiz quadrada de um número negativo!\n");
                    erro = 1;
                    break;
                }
                resultado = sqrt(valor1);
                break;
            default:
                printf("Opção inválida!\n");
                break;
        }

        if (!erro) {
            printf("\nResultado: %.2f\n", resultado);
        }
        system("pause");

    } while(1);
}

void entradaValores(int opcao, float *valor1, float *valor2) {
    if (opcao != 5) {
        printf("Digite o primeiro valor:\n");
        scanf("%f", valor1);
        while (getchar() != '\n' && getchar() != EOF);
        printf("Digite o segundo valor:\n");
        scanf("%f", valor2);
        while (getchar() != '\n' && getchar() != EOF);
    } else {
        printf("Digite o valor:\n");
        scanf("%f", valor1);
        while (getchar() != '\n' && getchar() != EOF);
    }
}