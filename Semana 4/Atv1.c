/*
    Escreva um programa em C que receba duas notas de um aluno, o nome dele e sua idade.
    O programa deve retornar o nome, e a média do aluno.

    Os dados devem ser armazenados em uma struct
*/

#include <stdio.h>
#include <string.h>
#include <locale.h>

typedef struct
{
    char nome[100];
    float nota[2], media;
    int idade;
} cadastroAluno;

int main () {
    setlocale (LC_ALL, "Portuguese");

    cadastroAluno aluno;

    printf("Digita o nome do aluno: ");
    fgets(aluno.nome, sizeof(aluno.nome), stdin);
    aluno.nome[strcspn(aluno.nome, "\n")] = '\0';

    printf("Informe a idade: ");
    scanf("%d", &aluno.idade);

    for(int i = 0; i <= 1; i++) {
        printf("Informe a nota %d: ", i+1);
        scanf("%f", &aluno.nota[i]);
    }
    
    aluno.media = (aluno.nota[0] + aluno.nota[1]) / 2;

    printf("Nome: %s\nMédia: %.2f", aluno.nome, aluno.media);

    return 0;
}

