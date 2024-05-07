/* 
    Desenvolver um algoritmo em C que  peça ao usuário para inserir um número inteiro.
    Seu programa deverá somar seus dígitos desse número.
    Por exemplo, se o número for 19, deverá somar 1+9. Se o número for 5, deverá somar 0+5. Se o número for 2023, deverá somar 2+0+2+3.
*/

#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "portuguese");

    char numeros[100];
    int soma = 0;

    printf("Insira um número inteiro:\n");
    scanf("%s", &numeros);

    for (int i = 0; i < strlen(numeros); i++) {
        soma += (numeros[i] - '0');
    }

    printf("\nResultado: %d da soma dos dígitos: %s\n", soma, numeros);


    return 0;
}