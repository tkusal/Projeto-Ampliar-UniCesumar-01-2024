/*
    Escreva um programa que faça o cadastro de uma pessoa contendo nome e idade.
    O programa deverá informar se a pessoa é maior ou menor de idade.
    O programa só poderá ser encerrado quando o usuário informar como nome a palavra "FIM".
*/

#include <stdio.h>
#include <string.h>

int main () {

    char nome[40];
    int idade;

    do {

        printf("Informe o nome: ");
        scanf("%s", nome);

        //Retorna 1 = quando não consegue comparar (erro na comparação)
        //Retorna 0 = quando consegue comparar (comparou com sucesso)

        //valor 1 em condição = true/verdadeiro
        //valor 0 em condição = false/falso
                
        if (!strcmp(nome, "fim")) {
            return 0;
        }

        printf("Informe a idade: ");
        scanf("%d", &idade);

        if (idade >= 18) {
            printf("%s e maior de idade", nome);
        } else {
            printf("%s e menor de idade", nome);
        }

    } while(1);    

}