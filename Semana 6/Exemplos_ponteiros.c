#include <stdio.h>
#include <string.h>

typedef struct {
    char nome [20];
    int idade;
} tipoAluno;

void escreva (tipoAluno *prt) {
    printf("Nome = %s\n", prt->nome);
    printf("Idade = %d", prt->idade);
}

int main () {
    tipoAluno Aluno;
    strcpy(Aluno.nome, "João");
    Aluno.idade = 17;
    escreva(&Aluno);
}