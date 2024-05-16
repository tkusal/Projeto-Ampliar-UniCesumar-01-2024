/*
    Escreva um programa que armazene a altura de 10 competidores e depois escreva na tela.
*/

#include <stdio.h>
#include <locale.h>

int main () {

    setlocale(LC_ALL, "Portuguese");

    float altura[10];

    for (int i = 0; i < 10; i++) {
        printf("Informe uma altura: ");
        scanf("%f", &altura[i]);
    }

    for (int i = 0; i < 10; i++) {
        printf("%.2f - ", altura[i]);
    }

    return 0;
}