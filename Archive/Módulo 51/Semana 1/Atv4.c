/*
Faça um programa que receba um número inteiro.
Como saí­da, deverá exibir na tela se é par ou í­mpar.
*/

#include <stdio.h>

int main () {

    int numero;

    printf("Insira um numero inteiro: ");
    scanf("%d",&numero);

    if (numero % 2 == 0) {
        printf("Par");
    }
    else {
        printf("Impar");
    }

    return 0;

}