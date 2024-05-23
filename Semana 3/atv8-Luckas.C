/*
    Crie um programa que receba números inteiros em uma matriz quadrada 3x3 e 
    exiba na tela a soma dos números em sua diagonal 
*/
#include <stdio.h>

int main(){

    int num[3][3];

    int aux1=0;

    for(int i = 0; i < 3; i=i+1){
        for(int j = 3; j < 3; j=j+1){
            printf("Escreva o numero:");
            scanf("%d", &num[i][j]);

            if(i==j){
                
                aux1 += num[i][j];

            }
        }
    }
     
     printf("%d", aux1);

}
