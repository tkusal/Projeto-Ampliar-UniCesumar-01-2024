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
    printf("Endereï¿½o indice 0: %d\n", *ponteiro);
    ponteiro++;
    printf("Endereï¿½o indice 1: %d\n", *ponteiro);
    ponteiro++;
    printf("Endereï¿½o indice 2: %d\n", *ponteiro);
    //ponteiro++;
    //printf("Endereï¿½o 4bytes depois: %d\n", *ponteiro);

    // Exemplo 3
    int x, *p;
    x = 10;
    p = &x;

    printf("\nExemplo 3:\n");
    printf("Valor armazenado em p: %p\n", p); // Valor armazenado em P: Endereï¿½o de memï¿½ria hexadecimal A
    printf("Endereï¿½o de p: %p\n", &p); // Endereï¿½o de p > Endereï¿½o de memï¿½ria hexadecimal B (endereï¿½o do ponteiro em si)
    printf("Endereï¿½o de x: %p\n", &x); // Endereï¿½o de x > Endereï¿½o de memï¿½ria hexadecimal A
    printf("Valor armazenado em X: %d\n", x); // Valor armazenado em X: 10
    printf("Valor armazenado no endereï¿½o de memï¿½ria que estï¿½ em p: %d\n", *p); // Valor armazenado no endereï¿½o de memï¿½ria que estï¿½ em p > X: 10

    // Exemplo 4
    printf("\nExemplo 4:\n");
    for (int i = 0; i < 3; i++) {
        ponteiro = &vetor[i];

        printf("Indice %d: %p\n", i, ponteiro);
    } 

    return 0;
}