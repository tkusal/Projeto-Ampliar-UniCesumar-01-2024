/*
Escreva um algoritmo que leia o nome de um aluno e suas duas notas de matemática.
Então, escreva na tela o nome e a média do aluno.
*/ 

#include <stdio.h>

int main() {

    float n1;
    float n2, result;
    char aluno[10];

    printf("Insira o nome do aluno: ");
    scanf("%s", aluno);

    printf("Insira a primeira nota: ");
    scanf("%f", &n1);

    printf("Insira a segunda nota: ");
    scanf("%f", &n2);

    result = (n1+n2)/2;

    printf("A media do aluno %s eh de: %.2f", aluno, result);
    
    return 0;
}