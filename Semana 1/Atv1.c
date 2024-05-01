/*
    Escreva um algoritmo que leia duas notas de matemática de um aluno. 
    Então, escreva na tela a média como saída.
*/

//standard IO (input/output) . header
#include <stdio.h>

int main() {

    //Declaração de variáveis
    float nota1, nota2;
    float media;

    //Entrada de dados
    printf("Escreva a primeira nota: \n");
    scanf("%f", &nota1);

    printf("Escreva a segunda nota: \n");
    scanf("%f", &nota2);

    //Processamento
    media = (nota1 + nota2) / 2;

    //Saída de dados
    printf("A media eh %.2f", media);

    return 0;
}