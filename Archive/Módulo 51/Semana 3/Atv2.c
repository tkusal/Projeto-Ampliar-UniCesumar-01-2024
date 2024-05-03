/*
    Desenvolva um programa que verifica se uma senha fornecida pelo usuário atende 
    aos critérios de segurança:
    
    - Comprimento mínimo de 8 caracteres
    - Presença de caracteres especiais
    - Se possuí letras maiúsculas e minúsculas
    - Se tem número

    Informe se é válida ou inválida.

    Dica: pesquise pelas bibliotecas string.h e ctype.h
*/

#include <stdio.h>
#include <ctype.h>
#include <locale.h>
#include <string.h>

int main() {
    setlocale(LC_ALL, "Portuguese");

    char senha[100];
    int tem_maiuscula = 0, tem_minuscula = 0, tem_numero = 0, tem_especial = 0;
    int comprimento = 0;
    int i;

    printf("Digite a senha: ");
    fgets(senha, sizeof(senha), stdin);
    senha[strcspn(senha, "\n")] = '\0';

    // Verificando o comprimento mínimo
    comprimento = strlen(senha);
    if (comprimento < 8) {
        printf("Senha inválida: deve ter pelo menos 8 caracteres.\n");
        return 0;
    }

    // Verificando a presença de letras maiúsculas, minúsculas, números e caracteres especiais
    for (i = 0; senha[i] != '\0'; i++) {
        if (isupper(senha[i])) {
            tem_maiuscula = 1;
        }
        if (islower(senha[i])) {
            tem_minuscula = 1;
        }
        if (isdigit(senha[i])) {
            tem_numero = 1;
        }
        if (!isalnum(senha[i])) {
            tem_especial = 1;
        }
    }

    // Verificando todas as condições
    if (tem_maiuscula && tem_minuscula && tem_numero && tem_especial) {
        printf("Senha válida.\n");
    } else {
        printf("Senha inválida: deve conter pelo menos uma letra maiúscula, uma letra minúscula, um número e um caractere especial.\n");
    }

    return 0;
}