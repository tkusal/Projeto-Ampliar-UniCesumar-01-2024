/*
    Crie um programa em C que receba 3 alunos (Código, nome, ano de nascimento, nota1 e nota2).
    O programa deve  ter o seguinte menu:
        - Cadastrar aluno
        - Informar a média de cada aluno exibindo se está aprovado ou não (média 6)
        - qual o aluno mais velho
        - sair
*/

#include <stdio.h>
#include <locale.h>
#include <string.h>

typedef struct{
    int cod, ano;
    char nome[50];
    float notas[2];
    float media;
}cadastroAluno;

int main(){
    setlocale(LC_ALL, "portuguese");

    cadastroAluno aluno[3];
    int opc;
    int i = 0;
    int aux = 0;
    int maiorIdade = 0;
    do{
        printf("Escolha uma opção: ");
        printf("1. Cadastrar.\n 2.Consultar média.\n 3. Idade mais velho.\n 4. sair\n");
        scanf("%d", &opc);

        switch(opc) {
            case 1: 
                if(i < 3){
                    printf("Informe um código: ");
                    scanf("%d", &aluno[i].cod);
                    while (getchar() != '\n' && getchar() != EOF);

                    printf("Informe o nome: \n");
                    fgets(aluno[i].nome, sizeof(aluno[i].nome), stdin);
                    aluno[i].nome[strcspn(aluno[i].nome, "\n")] = '\0';
                    while (getchar() != '\n' && getchar() != EOF);

                    printf("Informe o ano de nascimento: \n");
                    scanf("%d", &aluno[i].ano);
                    while (getchar() != '\n' && getchar() != EOF);

                    for(int j = 0; j < 2; j++){
                        printf("Informe a nota: ");
                        scanf("%f", &aluno[i].notas[j]);
                        while (getchar() != '\n' && getchar() != EOF);
                    }  
                    
                    i++;
                    
                } else{
                    printf("Não há mais espaço para cadastros.");
                }
                break;
            case 2:
                for(int j = 0; j <3; j++){
                    aluno[j].media = 0;
                    for(int u = 0; u < 2; u++){
                        aluno[j].media += aluno[j].notas[u];
                    }

                    aluno[j].media = aluno[j].media/2;
                    if(aluno[j].media < 6){
                        printf("Média: %f, Aluno reprovado.", aluno[j].media);
                    }else {
                        printf("Média: %f, Aluno aprovado.", aluno[j].media);
                    }
                }
                break;
            case 3: 
                int indice;
                for(int j = 0; j < 3; j++){
                    aux = 2024 - aluno[j].ano;
                    if(maiorIdade < aux){
                        maiorIdade = aux;
                        indice = j;
                    }

                }
                printf("Aluno mais velho: %s", aluno[indice].nome);
                break;
            case 4:
                printf("saindo do programa...");
                return 0;

            default:
                printf("Opção inválida.");
                break;
        }
    } while(1);

}