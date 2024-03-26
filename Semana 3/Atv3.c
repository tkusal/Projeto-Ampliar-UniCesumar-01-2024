/*
    Crie um programa que gere uma senha aleatória para o usuário. O usuário deve escolher se:
    
    - a senha deverá ter letras maiúsculas e minúsculas ou não
    - se deverá conter números ou não
    - se deverá contar simbolos ou não
    - quantidade de caracteres.

    Dica: pesquise as bibliotecas time.h e stdlib.h
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

int main() {
    int tem_maiusculas, tem_minusculas, tem_numeros, tem_simbolos;
    int tamanho, i;
    char caracteres[95]; // 95 é o total de caracteres imprimíveis na tabela ASCII

    setlocale(LC_ALL, "Portuguese");

    // Inicializando o array de caracteres imprimíveis
    for (i = 0; i < 95; i++) {
        caracteres[i] = i + 32;
    }

    printf("Informe quantos caracteres quer na senha: ");
    scanf("%d", &tamanho);

    printf("Digite 1 se deseja incluir letras maiúsculas, 0 caso contrário: ");
    scanf("%d", &tem_maiusculas);

    printf("Digite 1 se deseja incluir letras minúsculas, 0 caso contrário: ");
    scanf("%d", &tem_minusculas);

    printf("Digite 1 se deseja incluir números, 0 caso contrário: ");
    scanf("%d", &tem_numeros);

    printf("Digite 1 se deseja incluir símbolos, 0 caso contrário: ");
    scanf("%d", &tem_simbolos);

    // Verificando se pelo menos um tipo de caractere foi escolhido
    if (!(tem_maiusculas || tem_minusculas || tem_numeros || tem_simbolos)) {
        printf("Pelo menos um tipo de caractere deve ser incluído na senha.\n");
        return 1;
    }

    srand(time(NULL));

    printf("Sua senha aleatória é: ");
    for (i = 0; i < tamanho; i++) {
        char c;
        do {
            c = caracteres[rand() % 95];
        } while ((!tem_maiusculas && c >= 'A' && c <= 'Z') ||
                 (!tem_minusculas && c >= 'a' && c <= 'z') ||
                 (!tem_numeros && c >= '0' && c <= '9') ||
                 (!tem_simbolos && !(c >= 'A' && c <= 'Z') && !(c >= 'a' && c <= 'z') && !(c >= '0' && c <= '9')));
        printf("%c", c);
    }
    printf("\n");

    return 0;
}