/*
    Escreva um programa em C que peça ao usuário para digitar um número e imprima a tabuada de multiplicação desse número
*/

#include <stdio.h>
#include <locale.h>

int main () {

    setlocale(LC_ALL, "Portuguese");
    int numero, resultado;

    printf("Digite um número: ");
    scanf("%d", &numero);

    for(int i = 0; i <= 10; i++) {
        resultado = numero * i;
        printf("%d x %d = %d\n", i, numero, resultado);
    }

    return 0;
}