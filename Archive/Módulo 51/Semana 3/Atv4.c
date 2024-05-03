/*
    Escreva um programa que receba a idade de 6 alunos e como saída retorne-os em ordem crescente.
*/

#include <stdio.h>
#include <locale.h>

int main () {

    setlocale(LC_ALL, "Portuguese");

    int i, idade[6], aux;

    for (i = 0; i < 6; i++) {
        do {
            printf("Digite uma idade: ");
            scanf("%d", &idade[i]);
        } while(idade[i] < 0);
    }  

    for (i = 0; i < 6; i++) {
        for (int j = 0; j < 6-i-1; j++) {
            if(idade[j] > idade[j+1]) {
                aux = idade[j];
                idade[j] = idade[j+1];
                idade[j+1] = aux;
            }
        }
    }

    for (i = 0; i < 6; i++) {
        printf("Vetor Indice %d: %d\n", i, idade[i]);
    }  

    return 0;
}