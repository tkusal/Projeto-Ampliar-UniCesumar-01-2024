/*
    Escreva um programa que receba a idade de uma pessoa e informe se ela � maior de idade.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, "portuguese");

    int idade;

    printf("insira sua idade: \n");
    scanf("%d", &idade);

    if (idade >= 18){
        printf("maior de idade!!!\n");
    }else {
        printf("menor de idade!!!\n");
    }





return 0;



}