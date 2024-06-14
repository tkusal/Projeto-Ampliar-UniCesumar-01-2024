/*
    Escreva o famoso programa que recebe 3 alunos (nome, idade e 2 notas) e retorne 
    a média de cada aluno e informe qual o aluno mais velho.

    Utilize ponteiro e subrotina.
*/

#include <stdio.h>
#include <locale.h>
#include <string.h>

typedef struct {
    char nome[50];
    int idade;
    float nota1, nota2;
    float media;

}registroAluno;

float calculo(float *a, float *b){
    float result;
    result = (*a + *b)/2;
    return result;
}

void maiorIdade(registroAluno *aluno){
    int aux = 0;
    char pessoaMaisVelha[50];
    for(int i = 0; i < 3; i++){
        if(aluno->idade > aux ) {
            aux = aluno->idade;
            strcpy(pessoaMaisVelha, aluno->nome);
        }
        aluno ++;
    }       
    printf("A pessoa mais velha é:%s", pessoaMaisVelha);
}

void entrada(registroAluno *aluno){
    for(int i = 0; i < 3; i++){
        printf("Informe um nome:\n");
        fgets(aluno->nome, sizeof(aluno->nome), stdin);
        aluno->nome[strcspn(aluno->nome, "\n")] = '\0';
        while (getchar() != '\n' && getchar() != EOF);
        
        printf("Insira a idade:\n");
        scanf("%d", &aluno->idade);
        while (getchar() != '\n' && getchar() != EOF);

        printf("Informe uma nota:\n");
        scanf("%f", &aluno->nota1);
        while (getchar() != '\n' && getchar() != EOF);

        printf("Informe uma nota:\n");
        scanf("%f", &aluno->nota2);
        while (getchar() != '\n' && getchar() != EOF);
        
        aluno++;
    }
   
}

int main(){
    setlocale(LC_ALL, "portuguese");
    registroAluno aluno[3];

    entrada(aluno);    
    
    for(int i = 0; i < 3; i++){
        aluno[i].media = calculo(&aluno[i].nota1, &aluno[i].nota2);
        printf("Média:%.2f Aluno:%s\n", aluno[i].media, aluno[i].nome);
    }
    
    maiorIdade(aluno);
    return 0;
    
}