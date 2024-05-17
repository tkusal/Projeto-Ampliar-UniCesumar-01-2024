/*
    Escreva um programa que receba o modelo e o preço de 4 carros.
    O programa deverá informar qual é o carro mais barato e qual o mais caro.
*/

#include <stdio.h>
#include <locale.h>
#include <string.h>

int main () {

    setlocale(LC_ALL, "Portuguese_Brazil");

    float valor[4];
    char modelo[4][30];
    int indiceMenorValor = 0, indiceMaiorValor = 0;

    for(int i = 0; i < 4; i++) {
        printf("Informe o modelo do carro: ");
        fgets(modelo[i], sizeof(modelo[i]), stdin);
        modelo[i][strcspn(modelo[i], "\n")] = '\0';
        //Limpeza de buffer de entrada - como fflush(stdin) ou apenas getchar()
        while (getchar() != '\n' && getchar() != EOF);
        
        printf("Informe o valor do carro: ");
        scanf("%f", &valor[i]);
        //Limpeza de buffer de entrada - como fflush(stdin) ou apenas getchar()
        while (getchar() != '\n' && getchar() != EOF);

        if(valor[i] > valor[indiceMaiorValor]) {
            indiceMaiorValor = i;
        }

        if(valor[i] < valor[indiceMenorValor]) {
            indiceMenorValor = i;
        }     

    }

    printf("Modelo do carro mais caro: %s\n", modelo[indiceMaiorValor]);       

    printf("Modelo do carro mais barato: %s", modelo[indiceMenorValor]);

    return 0;
}    