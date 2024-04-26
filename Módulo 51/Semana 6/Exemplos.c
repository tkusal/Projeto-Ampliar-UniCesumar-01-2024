#include <stdio.h>
#include <locale.h>

void minhaFuncao (int *a, int *b) {
    int resultado;

    resultado = *a + *b;

    printf ("%d\n", resultado);
}

int main (void) {
    setlocale(LC_ALL, "portuguese");

    // Exemplo 1
    printf("Exemplo 1:\n");
    int A, B;
    A = 10;
    B = 20;
    
    minhaFuncao(&A, &B);

    // Exemplo 2
    int vetor[3] = {1, 2, 3};
    int *ponteiro;

    printf("\nExemplo 2:\n");
    ponteiro = vetor;
    printf("Endereço indice 0: %d\n", *ponteiro);
    ponteiro++;
    printf("Endereço indice 1: %d\n", *ponteiro);
    ponteiro++;
    printf("Endereço indice 2: %d\n", *ponteiro);
    //ponteiro++;
    //printf("Endereço 4bytes depois: %d\n", *ponteiro);

    // Exemplo 3
    int x, *p;
    x = 10;
    p = &x;

    printf("\nExemplo 3:\n");
    printf("Valor armazenado em p: %p\n", p); // Valor armazenado em P: Endereço de memória hexadecimal A
    printf("Endereço de p: %p\n", &p); // Endereço de p > Endereço de memória hexadecimal B (endereço do ponteiro em si)
    printf("Endereço de x: %p\n", &x); // Endereço de x > Endereço de memória hexadecimal A
    printf("Valor armazenado em X: %d\n", x); // Valor armazenado em X: 10
    printf("Valor armazenado no endereço de memória que está em p: %d\n", *p); // Valor armazenado no endereço de memória que está em p > X: 10

    // Exemplo 4
    printf("\nExemplo 4:\n");
    for (int i = 0; i < 3; i++) {
        ponteiro = &vetor[i];

        printf("Indice %d: %p\n", i, ponteiro);
    } 

    return 0;
}