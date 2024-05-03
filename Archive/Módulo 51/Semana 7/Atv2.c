/*
    Escreva um código que receba o cadastro de 10 funcionários, armazenando essas informações em um TXT.

    O funcionário possui Nome completo, matricula, telefone
*/

#include <stdio.h>
#include <locale.h>

typedef struct {
    char nome[50];
    int matric, tel;
} cadFuncionario;

int main () {

    cadFuncionario funcionario[10];
    FILE *arq;

    arq = fopen("./funcionarios.txt", "a+");

    for (int i = 0; i <= 10; i++) {
        printf("Informe o nome:\n");
        fgets(funcionario[i].nome, sizeof(funcionario[i].nome), stdin);

        printf("Matricula: \n");
        scanf("");
    }

}