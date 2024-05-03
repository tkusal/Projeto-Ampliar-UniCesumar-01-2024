/*
    Crie um programa em C que receba 3 carros (Código, Fabricante, Modelo, Ano e Valor) de uma locadora.
    Todos os carros tem uma depreciação de 10% ao ano.
    O programa deve calcular a depreciação de cada carro e informar qual perdeu mais valor.
*/

#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <time.h>

#define depre 0.1

typedef struct
{
    char fabricante[50], model[50];
    int cod, ano;
    float valor, depreciacao, valorAtual;
}cadCar;

int main () {

    setlocale(LC_ALL, "Portuguese");

    cadCar carros[3];
    time_t tempoAtual;
    struct tm *infoTempo;
    float maiorDepreciacao = 0;
    int aux;

    time(&tempoAtual);
    infoTempo = localtime(&tempoAtual);

    int anoAtual = infoTempo->tm_year + 1900;

    for (int i=0; i <= 2; i++ ) {
        printf("Informe o código do carro: ");
        scanf("%d", &carros[i].cod);
        while (getchar() != '\n' && getchar() != EOF);

        printf("Informe o fabricante: ");
        fgets(carros[i].fabricante, sizeof(carros[i].fabricante), stdin);
        carros[i].fabricante[strcspn(carros[i].fabricante, "\n")] = '\0';
        while (getchar() != '\n' && getchar() != EOF);

        printf("Informe o modelo: ");
        fgets(carros[i].model, sizeof(carros[i].model), stdin);
        carros[i].model[strcspn(carros[i].model, "\n")] = '\0';
        while (getchar() != '\n' && getchar() != EOF);

        printf("Informe o ano do carro: ");
        scanf("%d", &carros[i].ano);
        while (getchar() != '\n' && getchar() != EOF);

        printf("Informe o valor do carro: ");
        scanf("%f", &carros[i].valor);
        while (getchar() != '\n' && getchar() != EOF);

        carros[i].valorAtual = carros[i].valor;
        carros[i].depreciacao = 0;

        for (int j = anoAtual; j > carros[i].ano; j--) {
            carros[i].depreciacao += carros[i].valorAtual * depre;
            carros[i].valorAtual -= carros[i].valorAtual * depre;
        }

        if (carros[i].depreciacao > maiorDepreciacao) {
            maiorDepreciacao = carros[i].depreciacao;
            aux = i;
        }
    }

    printf("O carro com maior depreciação foi o código: %d\nDepreciação:%.2f\nValor atual: %.2f", carros[aux].cod, carros[aux].depreciacao, carros[aux].valorAtual);
    
    return 0;
}
