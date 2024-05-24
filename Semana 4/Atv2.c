/*
    Crie um programa em C que receba 3 carros (Código, Fabricante, Modelo, Ano e Valor) de uma locadora.
    Todos os carros tem uma depreciação de 10% ao ano.
    O programa deve calcular a depreciação de cada carro e informar qual perdeu mais valor.
*/

#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <math.h>

typedef struct{
    char fabricante[30], modelo[30];
    int codigo, ano;
    float valor;
    float depre;
}Cadastrocarro;

int main(){
    setlocale(LC_ALL, "portuguese");

    Cadastrocarro carro[3];
    float maiorDepre = 0;
    int aux;

    for(int i = 0; i < 3; i=i+1){
        printf("Digite o código do carro:\n");
        scanf("%d", &carro[i].codigo);
        while (getchar() != '\n' && getchar() != EOF);
        
        printf("Digite o fabricante do carro:\n");
        fgets(carro[i].fabricante, sizeof(carro[i].fabricante), stdin);
        carro[i].fabricante[strcspn(carro[i].fabricante, "\n")] = '\0';
        while (getchar() != '\n' && getchar() != EOF);

        printf("Digite o modelo do carro:\n");
        fgets(carro[i].modelo, sizeof(carro[i].modelo), stdin);
        carro[i].modelo[strcspn(carro[i].modelo, "\n")] = '\0';
        while (getchar() != '\n' && getchar() != EOF);

        printf("Digite o ano do carro:\n");
        scanf("%d", &carro[i].ano);
        while (getchar() != '\n' && getchar() != EOF);

        printf("Digite o valor do carro:\n");
        scanf("%f", &carro[i].valor);
        while (getchar() != '\n' && getchar() != EOF);

        for (int j = carro[i].ano; j < 2025; j++){
            carro[i].depre += carro[i].valor * 0.1;
            carro[i].valor -= carro[i].valor * 0.1;         
        }
        
        if (carro[i].depre > maiorDepre){
            maiorDepre = carro[i].depre;
            aux = i;
        }
    }

    printf("O Carro: %d, modelo: %s, teve a maior depreciaçao: %f", carro[aux].codigo, carro[aux].modelo, carro[aux].depre);
    
    return 0;
}