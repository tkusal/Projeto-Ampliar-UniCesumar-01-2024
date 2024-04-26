/*
    Agora no código abaixo, crie a estrutura condicional que identifique a classificação do IMC.
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

    printf("%s, seu IMC e de %.2f.\nSua classificacao e: ", nome, imc);

    if (imc <= 18.5)
    {
        printf("Abaixo do peso\n");
    } 
    else if (imc > 18.5 && imc <= 24.9)
    {
        printf("Peso ideal\n");
    }
    else if (imc > 24.9 && imc < 30.0)
    {
        printf("Levemente acima do peso\n");
    }
    else if (imc > 29.9 && imc <= 34.9) {
        printf("Obesidade 1\n");
    }
    else if (imc > 34.9 && imc <= 39.9)
    {
        printf("Obesidade II\n");
    }
    else
    {
        printf("Obesidade III\n");
    }

    return 0;
}