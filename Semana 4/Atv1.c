/*
    Escreva um programa que receba o cadastro de um aluno e retorne sua média.

    O aluno deve ter: Nome, idade e 2 notas.
    Utilize struct.
*/

#include <stdio.h>
#include <locale.h>
#include <string.h>

typedef struct{
    char nome[50];
    int idade;
    float nota[2], media;
    
}Cadastroaluno;

//entrada de dados//

int main(){
    setlocale(LC_ALL, "portuguese");

    Cadastroaluno aluno;

    printf("Informe o nome: ");
    fgets(aluno.nome, sizeof(aluno.nome), stdin);
    aluno.nome[strcspn(aluno.nome, "\n")] = '\0';
    while (getchar() != '\n' && getchar() != EOF);

    printf("Informe a idade: \n");
    scanf("%d", &aluno.idade);
    while (getchar() != '\n' && getchar() != EOF);


    for(int i = 0; i < 2; i++) {
        printf("informe uma nota");
        scanf("%f", &aluno.nota[i]);
        while (getchar() != '\n' && getchar() != EOF);
    }

    //processamento de dados//

    aluno.media = (aluno.nota[0] + aluno.nota[1])/2;

    //saída de dados//

    printf("sua média é: %f", aluno.media);


    return 0;
}
