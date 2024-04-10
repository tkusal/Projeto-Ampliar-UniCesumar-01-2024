#include <stdio.h>

int main (void) {

    int vetor[3] = {1, 2, 3};
    int *ponteiro;

    ponteiro = vetor;
    printf("Endereco vetor e indice 0: %d\n", *ponteiro);
    ponteiro++;
    printf("Endereco indice 1: %d\n", *ponteiro);
    ponteiro++;
    printf("Endereco indice 2: %d\n", *ponteiro);
    ponteiro++;
    printf("Endereco 4bytes depois: %d\n", *ponteiro);

    /*
        for (int i = 0; i < 3; i++) {
            ponteiro = &vetor[i];

            printf("Indice %d: %p\n", i, ponteiro);
        } 
    */   

    return 0;
}


/*

#include <stdio.h>

int main (void) {

    int x, *p;
    x = 10;
    p = &x;

    printf ("Valor armazenado em P: %d\n", p);
    printf ("Endereco de X: %d\n", &x);
    printf ("Endereco de P: %d\n", &p);
    printf ("Valor armazenado em X: %d\n", x);
    printf ("Valor armazenado no endereco de memoria em *P: %d\n", *p);

    return 0;
}

=============================================================================
#include <stdio.h>

void minhaFuncao (int *a, int *b) {
    int resultado;

    resultado = *a+*b;

    printf ("%d", resultado);
}

int main (void) {

    int x, y;

    x = 10;
    y = 20;
    
    minhaFuncao(&x, &y);

    return 0;
}
*/