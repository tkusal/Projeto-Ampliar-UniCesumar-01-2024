/*
    Desenvolva um programa que verifica se uma senha fornecida pelo usuário atende 
    aos critérios de segurança:
    
    - Comprimento mínimo de 8 caracteres
    - Presença de caracteres especiais
    - traSe possuí les maiúsculas e minúsculas
    - Se tem número

    Informe se é válida ou inválida.

    Dica: pesquise pelas bibliotecas string.h e <ctype.h>
*/

#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>
#include <stdbool.h>

int main(){

    setlocale(LC_ALL, "portuguese");


    char password[30];
    bool maiusculas = false;
    bool menusculas = false;
    bool vrfnum = false;
    bool letras = false;
    bool specialch = false;
    
    printf("Insira uma Senha:");
    scanf("%s", password);
    for(unsigned int i=0;  i < strlen(password); i++){ 

        char caracetere = password [i];
        if(isupper(caracetere)){
            maiusculas = true;

        }
        if(islower(caracetere)){
            menusculas = true;

        }
        if(!isalnum(caracetere)){
            
           specialch = true;

        }
        if(isdigit(caracetere)){

            vrfnum = true;

        }
        if(!isdigit(caracetere)){

            letras = true;

        }
    }
    if(strlen(password) < 8 ){

        printf("Senha inválida");
        return 0;

    }
    if(!(menusculas && maiusculas)){
        printf("senha inválida");

        return 0;
    }
    if(!(vrfnum || letras)){

        printf("senha inválida");

        return 0;
    }
    if(!specialch){

        printf("Não possui caracteres especiais");

        return 0;
    }

    printf("Sua senha é válida!");
}
