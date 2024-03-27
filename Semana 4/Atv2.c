/*
    Crie um programa que receba 3 carros (Código, Fabricante, Modelo, Ano e Valor) de uma locadora.
    Todos os carros tem uma depreciação de 10% ao ano.
    O programa deve calcular a depreciação de cada carro e informar qual perdeu mais valor.
*/

#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <time.h>

typedef struct
{
    char fabricante[50], model[50];
    int cod, ano;
    float valor;
}cadCar;

int main () {

    setlocale(LC_ALL, "Portuguese");

    cadCar carros[3];
    time_t tempoAtual;
    struct tm *infoTempo;

    time(&tempoAtual);
    infoTempo = localtime(&tempoAtual);

    int anoAtual = infoTempo->tm_year + 1900;

    printf("%d", anoAtual);

/*
    for (int i=0; i <= 2; i++ ) {
        printf("Informe o código do carro: ");
        scanf("%d", &carros[i].cod);

        printf("Informe o fabricante: ");
        fgets(carros[i].fabricante, sizeof(carros[i].fabricante), stdin);
        carros[i].fabricante[strcspn(carros[i].fabricante, "\n")] = '\0';

        printf("Informe o modelo: ");
        fgets(carros[i].model, sizeof(carros[i].model), stdin);
        carros[i].model[strcspn(carros[i].model, "\n")] = '\0';

        printf("Informe o ano do carro: ");
        scanf("%d", &carros[i].ano);

        printf("Informe o valor do carro: ");
        scanf("%f", &carros[i].valor);
    }
*/
    return 0;
}
