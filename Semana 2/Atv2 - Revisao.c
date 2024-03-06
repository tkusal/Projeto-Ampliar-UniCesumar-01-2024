/*
    Escreva um programa que recebe o comprimento dos 3 lados de um triâgulo, verifique e escreva na tela
    se é um triâgulo válido. Se for um triâgulo válido, escreva na tela sua classificação: equilátero, isósceles ou escaleno.

    (a + b > c) E (b + c > a) E (c + a > b) = triagulo válido
    
    Equilátero - Todos os lados são iguais
    Isóceles - Apenas 2 lados iguais
    Escaleno - Todos os lados diferentes
*/

#include <stdio.h>

int main() {

    float lado1, lado2, lado3;

    printf("Insira o lado 1: ");
    scanf("%f", &lado1);

    printf("Insira o lado 2: ");
    scanf("%f", &lado2);

    printf("Insira o lado 3: ");
    scanf("%f", &lado3);

    if(lado1 + lado2 > lado3 && lado2 + lado3 > lado1 && lado3 + lado1 > lado2) {
        printf("Triagunlo Valido");
        if (lado1 == lado2 && lado1 == lado3 && lado3 == lado2)
        {
            printf("\nEquilatero");
        } else if (lado1 != lado2 && lado1 != lado3 && lado3 != lado2) {
            printf("\nEscaleno");
        } else {
            printf("\nIsoceles");
        }
        
    } else {
        printf("Invalido");
    }

    return 0;
}