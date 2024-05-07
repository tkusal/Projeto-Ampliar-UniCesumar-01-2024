/*
    Escreva um programa em C que receba o sal�rio de uma pessoa e informe quanto ele pagar� de imposto de renda (al�quota: 15%)
*/

#include <stdio.h>
#include <locale.h>

int main(){

    setlocale(LC_ALL, "Portuguese");
    float salario, imposto;

    printf("Insira seu salario a ser calculado: \n");
    scanf("%f", &salario);

    imposto = salario * 0.15;

    printf("O valor pago de imposto renda eh de %.2f!!!", imposto);


   return 0;
}