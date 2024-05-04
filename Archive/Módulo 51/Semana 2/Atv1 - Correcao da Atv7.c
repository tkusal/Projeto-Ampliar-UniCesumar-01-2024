/*
    Escreva um programa em C que receba o valor inicial aplicado em um investimento, quantos meses esse investimento
    ficará aplicado e o juros anual de rendimento.
    O programa deverá retornar como saída o valor total ao final dos meses e o lucro bruto obtido.

    Dica: use a biblioteca math.h com a função pow(), para calcular os juros compostos.
*/

// STANDARD INPUT OUTPUT . HEADER
#include <stdio.h>
#include <math.h>

#define IR 27.5

int main() {

    //Declaração de variáveis
    float valorInicial;
    int qntMeses;
    float juros;
    float lucroBruto, totalBruto;

    //Entrada de dados
    printf("Insira o valor inicial do investimento: ");
    scanf("%f", &valorInicial);

    printf("Quantidade de meses de investimento: ");
    scanf("%d", &qntMeses);

    printf("Insira o juros anual do investimento: ");
    scanf("%f", &juros);

    // Processamento
    // M = C (1+i)^t 
    juros = juros/100;
    totalBruto = valorInicial * pow((1+ juros), qntMeses);
    lucroBruto = totalBruto - valorInicial;

    printf("O total e: %f\n", totalBruto);
    printf("O lucro bruto foi de: %.2f\n", lucroBruto);

    // Etapa 2 - Processamento
    // Calcule o lucro líquido e total liquido após o importo retido na fonte / IR = 27.5
    
    float imposto = lucroBruto * (IR/100);
    float lucroLiquido = lucroBruto - imposto;
    float totalLiquido = valorInicial + lucroLiquido;

    printf("Total liquido: %.2f\n", totalLiquido);
    printf("Lucro Liquido: %.2f", lucroLiquido);

    return 0;
}