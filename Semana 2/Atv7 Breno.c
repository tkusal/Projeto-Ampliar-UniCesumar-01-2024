#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int main(){
    
    setlocale(LC_ALL, "portuguese");
    
    int opc, idade;
    char nome[50];


    do{
        printf("Informe o nome ou a palavra FIM para encerrar: ");
        scanf("%s", nome);
    
        printf("Informe a idade: ");
        scanf("%d", &idade); 
        
        if(idade < 18 && idade > 0){  
            printf("Indivíduo menor de idade");
         }
    
        else if (idade >= 18){    
            printf("Indivíduo maior de idade");
       
        }
        
        else{
            printf("Idade inválida");
        }
        
        
        
    } while (strcmp(nome, "fim") == 1);
    
    return 0;
}
