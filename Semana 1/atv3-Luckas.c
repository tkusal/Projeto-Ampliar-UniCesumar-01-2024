/*
    Escreva um programa que receba a idade de uma pessoa e informe se ela é maior de idade.
*/
#include <stdio.h>

int main(){

 int idadealta;

 printf("Digite a sua idade:\n");
 scanf("%d", &idadealta);
 
  /*
  < menor que
  > maior que
  <= menor ou igual que
  >= maior ou igual que 
  == igual a
  != diferente de 

  */
    if(idadealta <= 18 && idadealta >=1){
        printf("voce eh menor de idade");
    }
 
    else if(idadealta <=0 || idadealta > 120){

     printf("Idade invalida");
    
    }
    
    else{
      printf("voce e maior de idade");
    }
  
    return 0;
}
