/*
    Escreva um algoritmo que leia duas notas de matemática de um aluno. 
    Então, escreva na tela a média como saída.
*/
#include <stdio.h>

int main(){
 
 float nota1, nota2, media;

 printf("Escreva a primeira nota:\n");
 scanf("%f", &nota1);

 printf("Escreva a segunda nota:\n");
 scanf("%f", &nota2);

 media = (nota1 + nota2) / 2;

 printf("A media do aluno eh: \n%.2f", media);


    return 0;
}
