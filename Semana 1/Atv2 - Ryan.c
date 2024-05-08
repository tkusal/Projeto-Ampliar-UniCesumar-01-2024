/*
    Escreva um programa em C que receba o salário de uma pessoa e 
    informe quanto ele pagará de imposto de renda (alíquota: 15%)
*/

//STANDARD I/O (INPUT/OUTPUT) . HEADER
#include <stdio.h>
#include <locale.h>

int main(){

    setlocale(LC_ALL, "Portuguese");
    float salario, imposto;

    printf("Insira seu salario a ser calculado: \n");
    scanf("%f", &salario);

    imposto = salario * 0.15;

    printf("O valor pago de imposto renda é de %.2f!!!", imposto);

    return 0;
}