/*
    Escreva um programa para controlar o estoque de uma loja de eletrônicos.
    O programa deve consistir em um menu que permita:

    1. Cadastrar novo produto: O sistema deve suportar até 15 produtos, em uma matriz 3x5. Cada produto deve possuir:
        a. Código
        b. Marca
        c. Descrição
        d. Preço
        e. Quantidade

    2. Alterar o preço de um produto: Deve permitir buscar um produto pelo código e alterar seu preço.

    3. Vender um Produto: Nesta opção, informa o código do produto. Com isso, ele reduz a quantidade do produto
    e armazena o valor da venda em "saldo total". Necessário validar se existe o produto em estoque. Caso não exista,
    ou seja, estoque = 0, informar que já esgotou.

    4. Visualiza saldo total de vendas

    5. Encerrar o sistema
*/

#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>
typedef struct
{
    int qtd, cod;
    float preco;
    char descricao[20], marca[20];
}produto;

int main () {

    setlocale (LC_ALL, "Portuguese");

    int opc, cod, x = 0;
    float vendaTotal = 0.0;
    produto produtos[2][2];

    do {
        printf("1. Cadastrar produto\n2. Alterar Preço de um Produto\n3. Venda\n4. Saldo Total de vendas\n5. Encerrar\n");
        scanf("%d", &opc);
        while (getchar() != '\n' && getchar() != EOF);
        system("cls");

        switch (opc) {
            case 1:
                for (int i = 0; i < 2; i++) {
                    for(int j = 0; j < 2; j++) {
                        printf("Informe o código do produto: ");
                        scanf("%d", &produtos[i][j].cod);
                        while (getchar() != '\n' && getchar() != EOF);

                        printf("Informe a marca: ");
                        fgets(produtos[i][j].marca, sizeof(produtos[i][j].marca), stdin);
                        produtos[i][j].marca[strcspn(produtos[i][j].marca, "\n")] = '\0';
                        while (getchar() != '\n' && getchar() != EOF);

                        printf("Informe a descrição do produto: ");
                        fgets(produtos[i][j].descricao, sizeof(produtos[i][j].descricao), stdin);
                        produtos[i][j].descricao[strcspn(produtos[i][j].descricao, "\n")] = '\0';
                        while (getchar() != '\n' && getchar() != EOF);

                        printf("Informe o preço do produto: ");
                        scanf("%f", &produtos[i][j].preco);
                        while (getchar() != '\n' && getchar() != EOF);

                        printf("Informe a quantidade: ");
                        scanf("%d", &produtos[i][j].qtd);
                        while (getchar() != '\n' && getchar() != EOF);

                        system("cls");
                    }  
                }
                break;
            case 2:            
                printf("Digite o código do produto: ");
                scanf("%d", &cod);
                system("cls");

                for(int i = 0; i < 2; i++){
                    for(int j = 0; j < 2; j++) {
                        if (cod == produtos[i][j].cod) {
                            printf("Informe o novo valor: ");
                            scanf("%f", &produtos[i][j].preco);
                            x = 1;
                            system("cls");                        
                        }
                    }
                }

                if (x != 1) {
                    printf("Produto não encontrado.\n");                    
                }
                x = 0;

                break;
            case 3:
                printf("Digite o código do produto: ");
                scanf("%d", &cod);
                system("cls");

                for(int i = 0; i < 2; i++){
                    for(int j = 0; j < 2; j++) {
                        if (cod == produtos[i][j].cod) {
                            if (produtos[i][j].qtd > 0) {
                                produtos[i][j].qtd--;
                                vendaTotal += produtos[i][j].preco;
                                printf("Venda efetuada.\n");
                            } else {
                                printf("Não há produto em estoque para ser vendido\n");
                            }
                            x = 1;
                        }
                    }
                }

                if (x != 1) {
                    printf("Produto não encontrado.\n");                    
                }
                x = 0;

                break;

            case 4:
                printf("Venda total: %f\n", vendaTotal);
                break;

            case 5:
                printf("Encerrando sistema...");
                return 0;
                break;

            default:
                printf("Opção inválida.\n");
                break;
        }
    } while (1);
}