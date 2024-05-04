/*
    Escreva um programa que leia o nome, peso e altura de um atleta.
    O programa informar como saída o nome do atleta e seu IMC.
    Fórmula:   IMC = peso / altura²
    Obs.: Peso precisa ser em Kilograma e Altura deverá ser em metros.
*/

#include <stdio.h>
#include <math.h>

int main() {

    float altura, peso, imc;
    char nome[10];

    printf("Insira o nome: ");
    scanf("%s", nome);

    printf("Insira a altura em metros: ");
    scanf("%f", &altura);

    printf("Insira o peso em Kg: ");
    scanf("%f", &peso);

    imc = peso / pow(altura, 2);

    printf("%s, seu IMC e de %.2f", nome, imc);

    return 0;
}