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
typedef struct
{
    int qtd, cod;
    float preco;
    char descrição[20], marca[20];
}produto;

int main () {

    setlocale (LC_ALL, "Portuguese");

    int opc;
    produto produtos[3][5];

    do {
        printf("1. Cadastrar produto\n2. Alterar Preço de um Produto\n3. Venda\n4. Saldo Total de vendas\n5. Encerrar\n");
        scanf("%d", &opc);
        while (getchar() != '\n' && getchar() != EOF);

        switch (opc) {
            case 1:
              for (int i = 0; i < 3; i++) {
                for(int j = 0; j < 5; j++) {
                    printf("Informe o código do produto: ");
                    scanf("%d", &produtos[i][j].cod);
                    while (getchar() != '\n' && getchar() != EOF);

                    printf("Informe a marca: ");
                    fgets(produtos[i][j].marca, sizeof(produtos[i][j].marca), stdin);
                    produtos[i][j].marca[strcspn(produtos[i][j].marca, "\n")] = '\0';
                    while (getchar() != '\n' && getchar() != EOF); 
              }  
        }

    } while (opc != 5);

    return 0;
}