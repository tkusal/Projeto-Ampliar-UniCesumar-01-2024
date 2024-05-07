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
        printf("Individuo menor de idade");  
        
    }
    else if(idade >= 18){
        printf("Individuo maior de idade");
        
    }
    
    return 0;
}
