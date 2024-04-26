/*
    Escreva um c�digo que cadastre at� 100 clientes e at� 100 produtos. No sistema o usu�rio deve poder:

    - Cadastrar o cliente (C�digo, Nome, idade, saldo)
    - Cadastrar produto (c�digo do produto, descri��o do produto, valor do produto, qtd)
    - Cadastrar uma venda de um produto pra um cliente (pelo c�digo do cliente e c�digo do produto).
        - A venda deve reduzir o saldo do cliente de acordo com pre�o e qtd do produto vendido)
    - Listar todas as vendas
    - Listar todos os clientes

    - Use subrotinas e ponteiros onde julgar necess�rio

    Cadastro de venda:
    - Recebe o código do cliente e valida se o cliente existe
    - Recebe o código do produto e valida se o produto existe
    - Recebe a quantidade de produto da venda e valida se existe em estoque
    - Calcula o total da Venda
    - Valida se o cliente tem saldo pra finalizar a compra
    - Abate o valor da venda no saldo do cliente e a quantidade vendida no estoque do produto


    Exercício desenvolvido utilizando o Live Share do VSCode.
    Código escrito, em grande parte, pelos alunos.
*/

#include <stdio.h>
#include <string.h>   
#include <locale.h>
#include <stdlib.h>

#define MAX_CLIENTES 100
#define MAX_PRODUTOS 100
#define MAX_VENDAS 1000

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
    int codCliente, codProduto, qtdProduto;
    float valorVenda;
} cadVenda;

int menu();
void cadastroCliente(cadCliente *ptr);
void cadastroProduto(cadProduto *ptl);
void cadastroVenda(cadVenda *venda, cadProduto *produtos, cadCliente *clientes, int *qtdVendas);
void cadastroVenda(cadVenda *venda, cadProduto *produtos, cadCliente *clientes, int *qtdVendas);
void listarVendas(cadVenda *vendas, int qtdVenda);
void listarClientes(cadCliente *clientes, int qtdCliente);


int main () {
    setlocale(LC_ALL, "Portuguese");  //ASCII
    
    cadCliente cliente[MAX_CLIENTES];
    cadProduto produto[MAX_PRODUTOS];
    cadVenda vendas[MAX_VENDAS];

    int qtdCliente = 0, qtdProduto = 0, qtdVendas = 0;
    int opc;

    do {
        opc = menu();
        system("cls");
        switch (opc) {
            case 1:
                if (qtdCliente < MAX_CLIENTES) {
                    cadastroCliente(&cliente[qtdCliente]);
                    qtdCliente++;
                } else {
                    printf("Limite de cadastros excedido!\n");
                }
                break;
            case 2:
                if(qtdProduto < MAX_PRODUTOS) {
                    cadastroProduto(&produto[qtdProduto]);
                    qtdProduto++;
                } else {
                    printf("Limite de cadastros excedido!\n");
                }
                break;
            case 3:
                if(qtdVendas < MAX_VENDAS){
                    cadastroVenda(&vendas[qtdVendas], produto, cliente, &qtdVendas);
                } else {
                    printf("Limite de cadastros excedido!\n");
                }
                break;
            case 4:
                listarVendas(vendas, qtdVendas);
                break;
            case 5:
                listarClientes(cliente, qtdCliente);
                break;
            case 6:
                printf("\nEncerrando...\n");
                system("pause");
                return 0;
            default:
                printf("\nOp��o inv�lida!\n"); // Bug: quando a op��o � uma letra
                system("pause");
                break;
        }
    } while(1);
}

int validaProduto(int cod,cadProduto *produtos) {
    for (int i = 0; i < MAX_PRODUTOS; i++) {
        if (produtos[i].codigo == cod) {
            return i;
        }
    }
    return -1;
}

int validaCliente(int cod, cadCliente *clientes) {
    for (int i = 0; i < MAX_CLIENTES; i++) {
        if (clientes[i].cod == cod) {
            return i;
        }
    }
    return -1;
}


void cadastroVenda(cadVenda *venda, cadProduto *produtos, cadCliente *clientes, int *qtdVendas) {
    int codCliente, codProduto, qntd, clienteIdx, produtoIdx;

    printf("Informe o c�digo do cliente: \n");
    scanf("%d", &codCliente);
    while (getchar() != '\n' && getchar() != EOF);
    clienteIdx = validaCliente(codCliente, clientes);
    
    if (clienteIdx != -1) {
        printf("Informe o c�digo do produto: \n");
        scanf("%d", &codProduto);
        while (getchar() != '\n' && getchar() != EOF);
        produtoIdx = validaProduto(codProduto, produtos);
        
        if (produtoIdx != -1) {
            printf("Informe a quantidade desejada: \n");
            scanf("%d", &qntd);
            while (getchar() != '\n' && getchar() != EOF);

            if (produtos[produtoIdx].qtd >= qntd) {
                int totalVenda = qntd * produtos[produtoIdx].valor;
                if (clientes[clienteIdx].saldo >= totalVenda) {
                    clientes[clienteIdx].saldo -= totalVenda;
                    produtos[produtoIdx].qtd -= qntd;

                    venda->codCliente = codCliente;
                    venda->codProduto = codProduto;
                    venda->qtdProduto = qntd;
                    venda->valorVenda = totalVenda;
                    (*qtdVendas)++; // Aumentar qtd de vendas somente ap�s valida��o
                    printf("Venda cadastrada!\n");
                } else {
                    printf("Cliente n�o tem saldo suficiente!\n");
                }
            } else {
                printf("N�o h� essa quantidade de produtos em estoque!\n");
            }
        } else {
            printf("C�digo de produto n�o existe!\n");
        }
    } else {
        printf("C�digo de cliente n�o existe!\n");
    }
    system("pause");
}

void listarVendas(cadVenda *vendas, int qtdVenda) {
    system("cls");
    if (qtdVenda == 0) {
        printf("N�o h� vendas cadastradas!\n");
        return;
    }
    for (int i = 0; i < qtdVenda; i++) {
        printf("Venda #%d de código: %d. No valor de %.2f, com %d quantidade(s), para cliente de código %d\n", i+1, vendas->codProduto, vendas->valorVenda, vendas->qtdProduto, vendas->codCliente);
    }
    system("pause");
}

void listarClientes(cadCliente *clientes, int qtdCliente) {
    system("cls");
    if (qtdCliente == 0) {
        printf("N�o h� clientes cadastrados!\n");
        return;
    }
    for (int i = 0; i < qtdCliente; i++) {
        printf("Cliente #%d de código %d. Nome: %s, Idade: %d, Saldo: %.2f\n", i+1, clientes[i].cod, clientes[i].nome, clientes[i].idade, clientes[i].saldo);
    }
    system("pause");
}

void cadastroCliente (cadCliente *ptr) {
    
    printf("\nInforme o c�digo: \n");
    scanf("%d", &ptr->cod);
    while (getchar() != '\n' && getchar() != EOF); // Flush stdin

    printf("Informe o nome: \n");
    fgets(ptr->nome, sizeof(ptr->nome), stdin);
    ptr->nome[strcspn(ptr->nome, "\n")] = '\0';
    while (getchar() != '\n' && getchar() != EOF);

    printf("Informe a idade: \n");
    scanf("%d", &ptr->idade);

    printf("Informe o Saldo: \n");
    scanf("%f", &ptr->saldo);

    system("cls");
}

void cadastroProduto(cadProduto *ptl ){
   
    printf("Informe o codigo: \n");
    scanf("%d", &ptl->codigo);
    while (getchar() != '\n' && getchar() != EOF);

    printf("Descri��o do produto: \n");
    fgets(ptl->desc, sizeof(ptl->desc), stdin);
    ptl->desc[strcspn(ptl->desc, "\n")] = '\0';
    while (getchar() != '\n' && getchar() != EOF);

    printf("Valor do produto: \n");
    scanf("%f", &ptl->valor);
    while (getchar() != '\n' && getchar() != EOF);    

    printf("Quantidade de produtos: \n");
    scanf("%d", &ptl->qtd);
    while (getchar() != '\n' && getchar() != EOF);
}

int menu(){
    int opc;

    system("cls");
    printf("Escolha uma op��o:\n");
    printf("1. Cadastrar cliente \n2. Cadastrar produto \n3. Cadastrar uma venda\n");
    printf("4. Listar venda \n5. Listar todos clientes \n6. Sair\n");
    scanf("%d", &opc);
    while (getchar() != '\n' && getchar() != EOF);
    
    return opc;
}