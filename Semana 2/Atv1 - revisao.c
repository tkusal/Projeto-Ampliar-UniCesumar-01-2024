/*
    Escreva um algorimo que receba 4 notas de um aluno e calcule a média.
    O programa deve informar se o aluno está reprovado (media menor que 5),
    em recuperação (entre 5 e 6) ou aprovado (maior que 6.0).
*/

#include <stdio.h>
#include <locale.h>

int main() {

    setlocale(LC_ALL, "Portuguese");

    float nota1, nota2, nota3, nota4, media;

    printf("Informe a nota 1: \n");
    scanf("%f", &nota1);

    printf("Informe a nota 2: \n");
    scanf("%f", &nota2);

    printf("Informe a nota 3: \n");
    scanf("%f", &nota3);

    printf("Informe a nota 4: \n");
    scanf("%f", &nota4);

    media = (nota1 + nota2 + nota3 + nota4) / 4;

    if (media < 5) {
        printf("Aluno reprovado.");
    }
    else if (media >= 5 && media <= 6) {
        printf("Aluno em recuperação.");
    }
    else {
        printf("Aluno aprovado.");
    }
    
    return 0;
}