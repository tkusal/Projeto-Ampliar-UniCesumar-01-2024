/*
    Você foi contratado por uma imobiliária para desenvolver um programa que receba 5 imóveis.
    Cada imóvel possui:
        - Endereço
        - Cidade
        - Área
        - Valor
        - 1 proprietário
    Cada proprietário possui:
        - Nome
        - CPF
        - Telefone

    O programa consiste em um menu que só deve ser encerrado quando o usuário escolher a opção de sair.
    As operações paresentadas pelo programa devem ser:
        1. Cadastrar Imóveis
        2. Listar todos os imóveis em ordem decrescente de área
        3. Listar todos os imóveis em ordem crescente de valor
        4. Listar todos os proprietários
        5. Sair

        Obs.: O bubble sort pode lhe auxiliar na ordenação por área e por valor.
        Use subrotinas para segmentar seu código.
        Utilize VARIÁVEIS GLOBAIS para lhe facilitar em não utilizar ponteiros.
*/
#include <stdio.h>
#include <locale.h>
#include <string.h>

typedef struct{
    char nome[50];
    char cpf[20];
    char tel[15];

}cadastroProp;

typedef struct{
    char endereco[50];
    char cidade[50];
    float area, valor;
    cadastroProp proprietario;
    
}cadastroImovel;

cadastroImovel imovel[5];

void cadastroImoveis(){
    for(int i = 0; i < 5; i++){
        printf("Informe o endereço:\n");
        fgets(imovel[i].endereco, sizeof(imovel[i].endereco), stdin);
        imovel[i].endereco[strcspn(imovel[i].endereco, "\n")] = '\0';
        while (getchar() != '\n' && getchar() != EOF);
        
        printf("Informe a cidade:\n");
        fgets(imovel[i].cidade, sizeof(imovel[i].cidade), stdin);
        imovel[i].cidade[strcspn(imovel[i].cidade, "\n")] = '\0';
        while (getchar() != '\n' && getchar() != EOF);

        printf("Informe a area:\n");
        scanf("%f", &imovel[i].area);
        while (getchar() != '\n' && getchar() != EOF);
        
        printf("Informe o valor:\n");
        scanf("%f", &imovel[i].valor);
        while (getchar() != '\n' && getchar() != EOF);

        printf("Informe o nome:\n");
        fgets(imovel[i].proprietario.nome, sizeof(imovel[i].proprietario.nome), stdin);
        imovel[i].proprietario.nome[strcspn(imovel[i].proprietario.nome, "\n")] = '\0';
        while (getchar() != '\n' && getchar() != EOF);
        
        printf("Informe o cpf:\n");
        fgets(imovel[i].proprietario.cpf, sizeof(imovel[i].proprietario.cpf), stdin);
        imovel[i].proprietario.cpf[strcspn(imovel[i].proprietario.cpf, "\n")] = '\0';
        while (getchar() != '\n' && getchar() != EOF);

        printf("Informe o telefone:\n");
        fgets(imovel[i].proprietario.tel, sizeof(imovel[i].proprietario.tel), stdin);
        imovel[i].proprietario.tel[strcspn(imovel[i].proprietario.tel, "\n")] = '\0';
        while (getchar() != '\n' && getchar() != EOF);
    }
}

void listarPorValor() {
    //ordenar em ordem crescente
    int aux;
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5-i-1; j++){
            if(imovel[j].valor > imovel[j+1].valor){
                aux = imovel[j].valor;
                imovel[j].valor = imovel[j+1].valor;
                imovel[j+1].valor = aux;
                
            }
        }
    }
    for(int i = 0; i < 5; i++){
        printf(" %f ", imovel[i].valor);
    }
}

void listarPorArea() {
    int aux;
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5-i-1; j++){
            if(imovel[j].area < imovel[j+1].area) {
                aux = imovel[j].area;
                imovel[j].area = imovel[j+1].area;
                imovel[j+1].area = aux;
            }
        }
    }
    for(int i = 0; i < 5; i++){
        printf(" %f ", imovel[i].area);
    }
}   

void listarProprietarios() {
    for(int i = 0; i < 5; i++){
        printf(" %s ", imovel[i].proprietario.nome);
    }

}

int main(){
    setlocale(LC_ALL, "Portuguese");
    int opc;
    do{
        printf("Escolha uma opção:\n");
        printf("1 Cadastrar Imóveis.\n2 Listar imóveis por área.\n3 Listar imóveis por valor.\n4 Listar proprietários.\n5 Sair.\n");
        scanf("%d", &opc);

        switch(opc){
            case 1: 
                cadastroImoveis();
                break; 

            case 2: 
                listarPorArea();
                break;  
              
            case 3: 
                listarPorValor();
                break; 
               
            case 4: 
                listarProprietarios();
                break;    
            
            case 5:
                printf("Programa encerrado!");
                return 0;

            default:
                printf("Comando invalido.");
                break;
        }
    } while(1);
}