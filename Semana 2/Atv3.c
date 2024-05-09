/*
    Escreva um algoritmo que escreva na tela todos os números pares entre 1 e 100
*/

// cont++
// cont += 1
// cont = cont+1

#include <stdio.h>

int main () { 

    for (int cont = 1; cont <= 100; cont = cont*2) {
        if (cont % 2 == 0) 
        {
            printf("%d\n", cont);
        }
    }

    return 0;
}