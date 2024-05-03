/*
    Crie um programa que receba números inteiros em uma matriz quadrada 3x3 e 
    exiba na tela a soma dos números em sua diagonal 
*/

#include <stdio.h>
#include <locale.h>
 
int main () {
 
    setlocale(LC_ALL, "Portuguese");

    int numeros[3][3], soma = 0;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {    
            printf("Insira um número, matriz[%d][%d]: ", i, j);
            scanf("%d", &numeros[i][j]);

            if (i == j) {
                soma += numeros[i][j];
            }
        }
    }

    printf("Soma diagonal é: %d", soma);

    return 0;
}