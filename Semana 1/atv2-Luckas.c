/*
    Escreva um programa em C que receba o salário de uma pessoa e 
    informe quanto ele pagará de imposto de renda (alíquota: 15%)
*/
#include <stdio.h>

int main(){
 
 float sal;

 printf("digite o seu salario\n");
 scanf("%f", &sal);


 sal = 0.15 * sal;
 

 printf("Voce vai pagar R$ %0.2f de imposto \nFAZ O L!", sal);

 
  return 0;
}
