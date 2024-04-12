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

typedef struct {
    int codClient, codProduto, qtdProduto;
    float valorVenda;
} cadVenda;

int menu();
void cadastroCliente();
void cadastroProduto();
void cadastroVenda();
void cadastroVenda();


int main () {
    setlocale(LC_ALL, "Portuguese");  //ASCII
    
    cadCliente cliente[100];
    cadProduto produto[100];
    cadVenda vendas[1000];

    int qtdCliente = 0, qtdProduto = 0, qtdVendas = 0;
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
                if(qtdVendas < 1000){
                    cadastroVenda(&vendas[qtdVendas], produto, cliente);
                    qtdVendas++;
                }
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

/*
    Cadastro de venda:
    - Recebe o código do cliente e valida se o cliente existe
    - Recebe o código do produto e valida se o produto existe
    - Recebe a quantidade de produto da venda e valida se existe em estoque
    - Calcula o total da Venda
    - Valida se o cliente tem saldo pra finalizar a compra
    - Abate o valor da venda no saldo do cliente e a quantidade vendida no estoque do produto
*/



cadProduto validaProduto(int cod,cadProduto *produtos) {
    int j = 0;
    for(int i = produtos; i < produtos+100; i++) {
        if ((produtos+j)->codigo == cod) {
            return (produtos+j);
        }
        j++;             
    }
    return ; 
}

cadCliente validaCliente(int cod, cadCliente *clientes) {
    int j = 0;
    for(int i = clientes; i < clientes+100; i++) {
        if ((clientes+j)->cod == cod) {
            return (clientes+j);
            printf("Encontrado: %d", clientes->cod);
        }
        j++;
    }
    return;
}

void cadastroVenda(cadVenda *venda, cadProduto *produtos, cadCliente *clientes) {
    int codCliente, codProduto, qntd;
    cadCliente *cliente;
    cadProduto *produto;

    printf("Informe o código do cliente: \n");
    scanf("%d", &codCliente);
    cliente = validaCliente(codCliente, clientes);

    printf("Validado: %d", cliente->cod);

    
    /*
    if (cliente != -1) {
        printf("Informe o código do produto: \n");
        scanf("%d", &codProduto);
        produto = validaProduto(codProduto, produtos);
        
        if (produto != -1) {
            printf("Informe a quantidade desejada: \n");
            scanf("%d", &qntd);
            if (produto->qtd >= qntd) {
                int totalVenda = qntd * produto->valor;
                if (cliente->saldo >= totalVenda) {
                    cliente->saldo -= totalVenda;
                    produto->qtd -= qntd
                }
            } else {
                printf("Não há essa quantidade de produtos em estoque!");
            }
            for(int i = 0; i < 100; i++) {

            }
        } else {
            printf("Código de produto não existe!");
        }

    } else {
        printf("Código de cliente não existe!");
    }  
    */
   
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