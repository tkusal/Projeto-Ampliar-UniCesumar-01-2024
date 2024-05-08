/*
    Escreva um programa que receba a idade de uma pessoa e informe se ela é maior de idade.
*/

#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

int main () {
    
    setlocale(LC_ALL, "Portuguese");

    int idade;

    printf("Informe uma idade: ");
    scanf("%d", &idade);
    system("cls");
    
    if(idade < 18){
        printf("Indivíduo menor de idade");  
        
    }
    else if(idade >= 18){
        printf("Indivíduo maior de idade");
        
    }
    
    return 0;
}