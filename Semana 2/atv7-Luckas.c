/*
    Escreva um programa que faça o cadastro de uma pessoa contendo nome e idade.
    O programa deverá informar se a pessoa é maior ou menor de idade.
    O programa só poderá ser encerrado quando o usuário informar como nome a palavra "FIM".
*/

#include <stdio.h>
#include <locale.h>
#include <string.h>

int main(){

setlocale(LC_ALL, "portuguese");

char nome[40] = "";
int idade = 0, opc;

do
{
    printf("1. Realizar cadastro\n2. Ver informações cadastrais\n");
    scanf("%d", &opc);

    switch (opc)
    {
    case 1:

          printf("Para realizar o cadastro escreva seu nome:\n");
          getchar();  //é usado para limpar o buffer de entrada após o usuário pressionar Enter                          
          scanf("%[^\n]", nome);               //garantindo que o programa aguarde corretamente.                          


        if( strcmp(nome, "fim") == 0){
         
         printf("Encerrando programa");

          return 0;

        }  
           else{

          printf("Para finalizar o cadastro digite sua idade:\n");
          scanf("%d", &idade);
         }
          
        break;
           case 2:
              if (strcmp(nome, "")==0 || idade <=0 || idade >200){

                printf("Usuário ainda não foi cadastrado\nOu cadastro inválido\n\n");
        
              }
              
                else if( idade > 0 && idade < 18){
                  
                  printf("Nome de Usuário:\n%s\nUsuáio com %d anos\nMenor de idade!\n\n", nome, idade);
                    
                }
                 else{
                  printf("Nome de Usuário:\n%s\nUsuário com %d anos\nMaior de idade!\n\n", nome, idade);

                 }
                 break;

                 default:
                  printf("Opção inválida");

                  break;
    }
} while (1);

}
