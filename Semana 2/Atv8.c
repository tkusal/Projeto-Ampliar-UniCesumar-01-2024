/*
    Escreva um programa em C que encontre o fatorial de um número fornecido pelo usúrio
*/

#include <stdio.h>
#include <locale.h>

int main () {

    setlocale(LC_ALL, "Portuguese");
    int numero, i;

    printf("Informe um número inteiro: ");
    scanf("%d", &numero);

    // O número multiplicado por seus antecessores
    for (i = numero-1; i > 0; i--) {
        numero *= i;
        printf("%d * %d = %d\n", numero/i, i, numero);
    }

    return 0;
}