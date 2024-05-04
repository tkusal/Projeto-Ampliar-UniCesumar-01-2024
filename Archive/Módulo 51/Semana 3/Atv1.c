/*
    Escreva um programa que receba 6 idades e informe quem È o mais novo e o mais velho.
    Necess·rio, ainda, informar se essas duas idades (menor e maior) s„o maior ou menor que 18 anos.
*/

#include <stdio.h>
#include <locale.h>

int main () {

    setlocale (LC_ALL, "Portuguese");

    int i, idade, menorIdade, maiorIdade;

    for (i = 1; i <= 6; i++) {

         do {
            printf("Informe a idade %d: ", i);
            scanf("%d", &idade);

            if (idade < 0) {
                printf("Idade n„o pode ser menor que zero.\n");
            }

        }while (idade < 0);         

        if (i == 1) {
            maiorIdade = idade;
            menorIdade = idade;
        }

        if (idade > maiorIdade)
        {
            maiorIdade = idade;
        }
        else
        {        
            if (idade < menorIdade){
                menorIdade = idade;
            }
        }
    }

    if (maiorIdade >= 18) {
        printf("A pessoa mais velha tem %d anos.\n… maior de idade.\n", maiorIdade);
    } else {
        printf ("A pessoa mais velha tem %d anos.\n… menor de idade.\n", maiorIdade);
    }

    if (menorIdade >= 18) {
        printf("A pessoa mais nova tem %d anos.\n… maior de idade.", menorIdade);
    } else {
        printf ("A pessoa mais nova tem %d anos.\n… menor de idade.", menorIdade);
    }

    return 0;
}