// Crie um programa que calcule a área de um quadrado
// lado²

#include <stdio.h>
#include <math.h>

int main() {

    // Declaração de variáveis do tipo float (real)
    float lado, area;

    //Entrada de dados utilizando scanf
    printf("Insira a medida do lado do quadrado: ");
    scanf("%f", &lado);

    // Processamento dos dados - Cálculo da área
    area = pow(lado, 2);

    // Saída do resultado
    printf("A area e: %.2f", area);

    return 0;
}