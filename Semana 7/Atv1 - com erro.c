/*
    Escreva um programa que cadastre até 100 clientes e até 100 produtos.
    No sistema o usuário deve poder:

    - Cadastrar o cliente (Código, Nome, idade, saldo)
    - Cadastrar produto (código do produto, descrição do produto, valor do produto, qtd)
    - Cadastrar uma venda de um produto pra um cliente (pelo código do cliente e código do produto).
    - Listar todas as vendas
    - Listar todas os cliente

    - Use subrotinas e ponteiros onde julgar necessário

    Cadastro de venda:
    - Recebe o código do cliente e valida se o cliente existe
    - Recebe o código do produto e valida se o produto existe
    - Recebe a quantidade de produto da venda e valida se existe em estoque
    - Calcula o total da Venda
    - Valida se o cliente tem saldo pra finalizar a compra
    - Abate o valor da venda no saldo do cliente e a quantidade vendida no estoque do produto    
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct{
    int cod, idade;
    char nome[50];
    float saldo;
}cadastroCliente;

typedef struct{
    int cod,qntd;
    char desc[50];
    float valor;
} cadastroProduto;

typedef struct{
    float valorVenda;
    int codcliente, codproduto, qntdproduto;
}cadastroVenda;

cadastroCliente cadastrarCliente() {
    cadastroCliente retorno;
    printf("Informe o código:\n");
    scanf("%d", &retorno.cod);
    while (getchar() != '\n' && getchar() != EOF);

    printf("Informe a idade:\n");
    scanf("%d", &retorno.idade);
    while (getchar() != '\n' && getchar() != EOF);

    printf("Informe o nome:\n");
    fgets(retorno.nome, sizeof(retorno.nome), stdin);
    retorno.nome[strcspn(retorno.nome, "\n")] = '\0';
    while (getchar() != '\n' && getchar() != EOF);

    printf("Informe o saldo:\n");
    scanf("%f", &retorno.saldo);
    while (getchar() != '\n' && getchar() != EOF);

    return retorno;
}

void cadastrarProduto(cadastroProduto *produto) {
    printf("Informe o código:\n");
    scanf("%d", &produto->cod );
    while (getchar() != '\n' && getchar() != EOF);

    printf("Informe a quantidade:\n");
    scanf("%d", &produto->qntd);
    while (getchar() != '\n' && getchar() != EOF);

    printf("Informe a descrição:\n");
    fgets(produto->desc, sizeof(produto->desc), stdin);
    produto->desc[strcspn(produto->desc, "\n")] = '\0';
    while (getchar() != '\n' && getchar() != EOF);

    printf("Informe o valor:\n");
    scanf("%f", &produto->valor);
    while (getchar() != '\n' && getchar() != EOF);

}

void cadastrarVenda(cadastroVenda *venda, cadastroCliente *cliente, cadastroProduto *produto, int *iVenda){
    int indiceP = -1, indiceC = -1;

    printf("Informe o código do cliente:");
    scanf("%d", &venda->codcliente);    
    while (getchar() != '\n' && getchar() != EOF);
    for(int i = 0; i < 100; i++) {
        if(cliente->cod == venda->codcliente) {
            indiceC = i;            
        }
        cliente++;
    }
    if(indiceC < 0) {
        printf("Cod não encontrado\n");
        return;
    }
    
    printf("Informe o código do produto:");
    scanf("%d", &venda->codproduto);
    while (getchar() != '\n' && getchar() != EOF);
    for(int i = 0; i < 100; i++) {
        if(produto->cod == venda->codproduto) {
            indiceP = i;  
        }
        produto++;
    }
    if(indiceP < 0) {
        printf("Cod não encontrado\n");
        return;
    }
    
    printf("Informe a quantidade do produto:\n");
    scanf("%d", &venda->qntdproduto);
    while (getchar() != '\n' && getchar() != EOF);

    if(produto[indiceP].qntd < venda->qntdproduto) {
        printf("Quantidade insuficiente em estoque.\n");
        return;
    }
    venda->valorVenda = venda->qntdproduto * produto[indiceP].valor;

    if(cliente[indiceC].saldo < venda->valorVenda) {
        printf("Saldo do cliente é insuficiente");
        return;
    }
    cliente[indiceC].saldo -= venda->valorVenda;
    produto[indiceP].qntd -= venda->qntdproduto;
    printf("Venda cadastrada.\n");
    (*iVenda)++;    
}

void listarVendas(cadastroVenda *venda, int indiceVendas) {
    printf("Lista de vendas:\n");
    for(int i = 0; i < indiceVendas; i++){
        printf("Código do cliente: %d\n", venda->codcliente);
        printf("Código do produto: %d\n", venda->codproduto);
        printf("Quantidade de produtos: %d\n", venda->qntdproduto);
        printf("Valor total da venda: %.2f\n", venda->valorVenda);
        printf("======================================\n\n");
        venda++;
    }
}

void listarclientes(cadastroCliente *cliente, int indiceCliente) {
    printf("Lista de clientes:\n");
    for(int i = 0; i < indiceCliente; i++){
        printf("Código do cliente: %d\n", cliente->cod);
        printf("Idade do cliente: %d\n", cliente->idade);
        printf("Nome do cliente: %s\n", cliente->nome);
        printf("Saldo do cliente: %.2f\n", cliente->saldo);
        cliente ++;
    }    
}

int main() {

    setlocale(LC_ALL, "Portuguese");
    int opc;
    int indiceCliente = 0;
    int indiceProduto = 0;
    int indiceVenda = 0;
    cadastroCliente cliente[100];
    cadastroProduto produto[100];
    cadastroVenda venda[300];
    do{
        printf("Escolha uma opc:\n");
        printf("1 Cadastrar cliente\n2 Cadastrar produto\n3 Cadastrar venda\n4 Listar vendas\n5 Listar clientes\n6 Sair\n");
        scanf("%d", &opc);
        while (getchar() != '\n' && getchar() != EOF);

        switch(opc){
            case 1:
                if(indiceCliente < 100){
                    cliente[indiceCliente] = cadastrarCliente();
                    indiceCliente ++;
                } else {
                    printf("Ultrapassou o número de cadastros\n");
                }
                break;
            case 2: 
                if(indiceProduto < 100){
                    cadastrarProduto(&produto[indiceProduto]);                 
                    indiceProduto ++;
                } else {
                    printf("Ultrapassou o número de cadastros\n");
                }
                break;
            case 3: 
                if(indiceVenda < 300){
                    cadastrarVenda(&venda[indiceVenda], cliente, produto, &indiceVenda);                    
                }else {
                    printf("Ultrapassou o número de vendas\n");
                }
                break;                                            
            case 4: 
                listarVendas(venda, indiceVenda);
                break;                
            case 5:
                listarclientes(cliente, indiceCliente);
                break;
            case 6:
                printf("Encerrando programa...");
                return 0; 
                break;   

            default:
                printf("Inválido\n");
                break;
        }
    }while(1); 
}