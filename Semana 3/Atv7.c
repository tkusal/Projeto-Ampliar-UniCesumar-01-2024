/*
    Escreva um programa que receba 10 números inteiros e os ordene em ordem crescente
*/

#include <stdio.h>
#include <locale.h>

int main () {

    setlocale(LC_ALL, "Portuguese");

    int numero[10], aux;

    for(int i = 0; i < 10; i++){
        printf("Informe um número: ");
        scanf("%d", &numero[i]);
    }

    for(int i = 0; i < 10; i++){
        if(numero[i] > numero[i + 1] ){
            aux = numero[i + 1];
            numero[i + 1] = numero[i];
            numero[i] = aux;
        }        
    }
    
    for (int i = 0; i < 10; i++){
        printf(" %d ", numero[i]);
    }
    
    return 0;
}