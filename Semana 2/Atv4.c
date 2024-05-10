/*
    Escreva um programa que receba um número inteiro. Enquanto este número for menor que
    1000, o programa não poderá ser encerrado, devendo solicitar um novo número.
*/

#include <stdio.h>

int main() {
    int numero;

    do {
        printf("Insira um numero inteiro");
        scanf("%d", &numero);
    } while(numero < 1000);

    return 0;    
}