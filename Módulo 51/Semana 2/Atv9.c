/*
    Escreva um programa que fça o cadastro de um usuário contendo nome, telefone e endereço.
    O cadastro só poderá ser encerrado quando o usuário informar como nome a palavra "FIM".
*/

#include <stdio.h>
#include <string.h>

int main () {

    char nome[10], endereco[50];
    char telefone[16];

    do {
        printf("Insira o nome ou FIM para encerrar: ");
        scanf("%s", nome);

        printf("Insira o telefone: ");
        scanf("%s", telefone);

        printf("Insira o endereço: ");
        scanf("%s", endereco);

    } while (strcmp(nome, "fim") == 1);

    return 0;
}