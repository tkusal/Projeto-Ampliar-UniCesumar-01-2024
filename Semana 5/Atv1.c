/*
    Faça uma calculadora com as 4 operações básicas.
    Cada operações deve ser uma subrotina.
    Você deve informar ao usuário as operações para cada operação.
    Se ele escolher a opção 0, o programa deverá ser encerrado.
*/

#include <stdio.h>
#include <locale.h>

int num1, num2;

void entradaDados () {
    printf("Informe um número: ");
    scanf("%d", &num1);
    printf("Informe um número: ");
    scanf("%d", &num2);
}

int soma () {
    entradaDados();
    return num1 + num2;
}

int subtracao () {
    entradaDados();
    return num1 - num2;
}

int multiplicacao () {
    entradaDados();
    return num1 * num2;
}

int divisao () {
    entradaDados();
    return num1 / num2;
}

int main () {
    setlocale (LC_ALL, "Portuguese");

    int opc, resultado;

    do {
        printf("Escolha uma operação: \n");
        printf("1. Soma\n");
        printf("2. Substração\n");
        printf("3. Multiplicação\n");
        printf("4. Divisão\n");
        printf("0. Sair\n");
        scanf("%d", &opc);        

        switch(opc) {
            case 1:
                resultado = soma();
                break;
            case 2:
                resultado = subtracao();
                break;    
            case 3:
                resultado = multiplicacao();
                break;
            case 4:
                resultado = divisao();
                break;
            case 0:
                printf("Encerrando...");
                break;
            default: 
                printf("Opção inválida");
                break;
        }

        printf("Resultado: %d\n", resultado);

    }while(opc != 0);

    return 0;    
}