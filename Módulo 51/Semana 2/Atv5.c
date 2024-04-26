/*
    Escreva um código que solicite ao usuário que insira números inteiro positivos e calcule a soma desses
    numero até que ele insira um número 0.
*/

#include <stdio.h>
#include <locale.h>

int main () {

    setlocale (LC_ALL, "Portuguese");
    int n1 = 1, resultado = 0;

    while (n1 > 0) {
        printf("Insira o um n�mero inteiro positivo: ");
        scanf("%d", &n1);

        resultado = n1+resultado;
        printf("Soma: %d\n", resultado);
    }

    return 0;
}