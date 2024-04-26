/*
Elabore um algoritmo que receba o salário de um funcionário e o código do 
cargo e apresente o cargo, o valor do aumento e o novo salário. A tabela a seguir 
apresenta os cargos.

Código      Cargo             Percentual do aumento
1        Dev Front-end                 10%
2        Dev Back-end                  30%
3        DevOps                        50%
4        Polí­tico                      150%
*/

#include <stdio.h>
#include <locale.h>

int main() {

    setlocale(LC_ALL, "Portuguese");

    int cod;
    float salario, aumento;

    printf("Informe o código do cargo: \n");
    printf("1 - Dev Front-end\n2 - Dev Back-end\n3 - DevOPs\n4 - Político\n");
    scanf("%d", &cod);

    printf("Informe seu salário: ");
    scanf("%f", &salario);

    switch(cod) {
        case 1 :
            printf("O aumento foi de: %.2f\n", salario * 0.10);
            printf("Seu salário atual é: %.2f", salario+(salario*0.10));
            break;
        
        case 2 :
            aumento = salario * 0.30;
            salario = salario + aumento;
            printf("O aumento foi de: %.2f\nSeu salário atual é: %.2f", aumento, salario);
            break;
        
        case 3 :
            aumento = salario * 0.50;
            salario = salario + aumento;
            printf("O aumento foi de: %.2f\nSeu salário atual é: %.2f", aumento, salario);
            break;

        case 4 :
            aumento = salario * 1.50;
            salario = salario + aumento;
            printf("O aumento foi de: %.2f\nSeu salário atual é: %.2f", aumento, salario);
            break;

        default :
            printf("Opção inválida");
            break;
    }

    return 0;
}