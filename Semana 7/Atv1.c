#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *arquivo;
    //arquivo = fopen("./teste.txt", "w+");
    arquivo = fopen("./teste.txt", "a+");

    if (!arquivo) {
    printf("Erro ao abrir o arquivo.\n");
    return 1;
    }

    fprintf(arquivo, "Incluindo novos dados.\n");

    /* fprintf(arquivo, "Primeiros testes da aula de 17/04/2024.\n");
    fprintf(arquivo, "Novo conteúdo.\n");
    fseek(arquivo, 0, SEEK_SET);
    

    char str[1000];

    fgets(str, sizeof(str), arquivo);
    printf("Conteúdo do arquivo: \n%s", str);

    */

    fclose(arquivo);

    return 0;
}