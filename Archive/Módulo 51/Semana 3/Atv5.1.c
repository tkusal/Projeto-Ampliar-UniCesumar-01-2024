/*
    Escreva um programa que receba 10 números e ordene em ordem decrescente
*/

#include <stdio.h>
#include <locale.h>
 
int main () {
 
    setlocale(LC_ALL, "Portuguese");
    
    int numero[5], aux;
    
    for (int i = 0; i < 5; i++) {
        printf("Coloca o numero ai, querido: ");
        scanf("%d", &numero[i]);
    }

    for (int i = 0; i <= 4; i++) {
        for (int j = 0; j < 5-i-1; j++) {
            if (numero[j] < numero[j+1]) {
                aux = numero[j];
                numero[j] = numero[j+1];
                numero[j+1] = aux;
            }
        }
    }

    for (int i = 0; i < 5; i++) {
        printf("%d ", numero[i]);
    }

    return 0;
}