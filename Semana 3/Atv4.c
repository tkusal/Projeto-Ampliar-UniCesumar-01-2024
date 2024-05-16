/*
    Escreva um algoritmo que receba números inteiros e armazene em uma matriz 4x2.
    Depois exiba na tela esses dados.
*/

#include <stdio.h>
#include <locale.h>

int main () {

    setlocale(LC_ALL, "Portuguese");

    int carros[4][2];

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 2; j++) {
            printf("Informe o um dado [%d][%d]: ", i, j);
            scanf("%d", &carros[i][j]);
        }
    }

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 2; j++) {
            printf("Dado [%d][%d]: %d \n", i, j, carros[i][j]);
        }
    }

    return 0;
}    