#include <stdio.h>
#include <locale.h>

int main () {

    setlocale(LC_ALL, "Portuguese");

    int numero[10], aux;

    for(int i = 0; i < 10; i++){
        printf("Informe um número: ");
        scanf("%d", &numero[i]);
    }

    for(int i = 0; i < 10; i++){
        for (int j = 0; j < 10-i-1; j++) {
            if(numero[j] > numero[j+1]) {
            aux = numero[j];
            numero[j] = numero[j+1];
            numero[j+1] = aux;
            }
        }        
    }
    
    
    for (int i = 0; i < 10; i++){
        printf(" %d ", numero[i]);
    }
    
    return 0;
}
    
