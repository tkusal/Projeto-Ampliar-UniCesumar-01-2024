/*
    Escreva um programa que seja uma enciclopédia de ATÉ 100 filmes.
    Cada filme possui titulo, ano e código.
    O programa deve permitir buscar um filme pelo código.

    Use subrotinas onde julgar necessário.
*/

#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    char titulo[50];
    int ano, codigo;
} criaFilme;

int menu () {
    int opc;
    printf("Escolha uma opção: \n1. Cadastrar filme\n2. Pesquisar filme\n3. Encerrar");
    scanf("%d", &opc);
    while (getchar() != '\n' && getchar() != EOF);
    system("cls");
    return opc;
}

criaFilme cadastrarFilme() {
    criaFilme filme;

    printf("Informe o título do filme: ");
    fgets(filme.titulo, sizeof(filme.titulo), stdin);
    filme.titulo[strcspn(filme.titulo, "\n")] = '\0';
    while (getchar() != '\n' && getchar() != EOF);
    system("cls");

    printf("Informe o código: ");
    scanf("%d", &filme.codigo);
    while (getchar() != '\n' && getchar() != EOF);
    system("cls");

    printf("Informe o ano: ");
    scanf("%d", &filme.ano);
    while (getchar() != '\n' && getchar() != EOF);
    system("cls");

    return filme;
}

int buscaFilme () {
    int cod;
    printf("Informe o código do filme: ");
    scanf("%d", &cod);
    while (getchar() != '\n' && getchar() != EOF);
    system("cls");
    
    return cod;
}

int engineBusca(int codBusca, criaFilme filme) {
    int v;
    if(codBusca == filme.codigo) {
        printf("Nome do filme: %s\nAno: %d\nCód.: %d", filme.titulo, filme.ano, filme.codigo);
        v = 1;
        system("pause");
        system("cls");
    } else {
        v = 0;
    }

    return v;
}

int main () {

    setlocale (LC_ALL, "Portuguese");
    int opcao, indice = 0, cod;
    criaFilme filmes[100];

    do {
        opcao = menu();

        switch(opcao) {
            case 1:
                if (indice < 100) {
                    filmes[indice] = cadastrarFilme();
                    indice++;
                } else {
                    printf("Excedeu a quantidade de cadastros.");
                    system("pause");
                    system("cls");
                }
                break;
            case 2:
                int valid;
                cod = buscaFilme();
                for (int i = 0; i <= indice; i++) {
                    valid = engineBusca(cod, filmes[i]);                    
                }

                if (valid != 1)  {
                    printf("Código não encontrado.");
                    system("pause");
                    system("cls");
                }
                break;
            case 3:
                system("pause");
                system("cls");
                return 0;
            default:
                printf("Opção inválida");
                system("pause");
                system("cls");
        }
    } while(1);
}