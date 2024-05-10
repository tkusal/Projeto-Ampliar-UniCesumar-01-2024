/*
    Escreva um programa em C que calcule o fatorial de um número fornecido pelo usúario
*/

#include <stdio.h>
#include <locale.h>

int main () {
    setlocale(LC_ALL, "Portuguese");
    
    int num;

    printf("Informe um número: ");
    scanf("%d", &num);

    //num = 5  ///    5*4*3*2*1 = 120   ///  i=4
    for (int i = num-1; i >= 1; i--)
    {
        num *= i;
    }

    printf("%d", num);

    return 0;
}