/*
    Escreva um código que cadastre até 100 clientes e até 100 produtos. No sistema o usuário deve poder:

    - Cadastrar o cliente (Código, Nome, idade, saldo)
    - Cadastrar produto (código do produto, descrição do produto, valor do produto, qtd)
    - Cadastrar uma venda de um produto pra um cliente (pelo código do cliente e código do produto).
        - A venda deve reduzir o saldo do cliente de acordo com preço e qtd do produto vendido)
    - Listar todas as vendas
    - Listar todas os clientes

    - Use subrotinas e ponteiros onde julgar necessário
*/

#include <stdio.h>
#include <string.h>   
#include <locale.h>
#include <stdlib.h>

typedef struct {
    char nome[120];
    int cod;
    int idade;
    float saldo;
} cadCliente;

typedef struct {
    int codigo;
    char desc[30];
    float valor;
    int qtd;
} cadProduto;

int menu();
void cadastroCliente();
void cadastroProduto();
void cadastroVenda();

int main () {
    setlocale(LC_ALL, "Portuguese");  //ASCII
    
    cadCliente cliente[100];
    cadProduto produto[100];

    int qtdCliente = 0, qtdProduto = 0;
    int opc;

    do {
        opc = menu();
        system("cls");
        switch (opc) {
            case 1:
                if (qtdCliente < 100) {
                    cadastroCliente(&cliente[qtdCliente]);
                    qtdCliente++;
                } else {
                    printf("Limite de cadastros excedido!");
                }
                break;
            case 2:
                if(qtdProduto < 100) {
                    cadastroProduto(&produto[qtdProduto]);
                    qtdProduto++;
                } else {
                    printf("Limite de cadastros excedido!");
                }
                break;
            case 3:
                cadastroVenda();
                break;
            case 4:
                listarVendas();
                break;
            case 5:
                listarClientes();
                break;
            case 6:
                printf("Encerrando...");
                return 0;
            default:
                print("Opção inválida!");
                break;
        }
    } while(1);
}

void cadastroCliente (cadCliente *ptr) { 
    
    printf("Informe o código: \n");      
    scanf("%d", &ptr->cod);

    printf("Informe o nome: \n"); 
    fgets(ptr->nome, sizeof(ptr->nome), stdin);
    ptr->nome[strcspn(ptr->nome, "\n")] = '\0';

    printf("Informe a idade: \n");
    scanf("%d", &ptr->idade);

    printf("Informe o Saldo: \n");
    scanf("%f", &ptr->saldo);

    while (getchar() != '\n' && getchar() != EOF);
    system("cls");
}

void cadastroProduto(cadProduto *ptl ){
   
    printf("Informe o codigo: \n");
    scanf("%d", &ptl->codigo);
    
    printf("Descrição do produto: \n");
    fgets(ptl->desc, sizeof(ptl->desc), stdin);
    ptl->desc[strcspn(ptl->desc, "\n")] = '\0';

    printf("Valor do produto: \n");
    scanf("%f", &ptl->valor);    

    while (getchar() != '\n' && getchar() != EOF);
    system("cls");
    printf("Quantidade de produtos: \n");
    scanf("%d", &ptl->qtd);
}

int menu(){
    int opc;

    printf("Escolha uma opção:\n");
    printf("1. Cadastrar cliente \n2. Cadastrar produto \n3. Cadastrar uma venda\n");
    printf("4. Listar venda \n5. Listar todos clientes \n");
    scanf("%d", &opc);
    
    return opc;
}