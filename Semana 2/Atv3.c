/*
    Escreva um código que imprima na tela todos os números pares de 0 a 100
*/

#include <stdio.h>

int main () {

    int i;

    for (i = 0; i <= 100; i=i+2)
    {
        printf("%d\n", i);
    }

    printf("Valor final: %d", i);

    return 0;
}