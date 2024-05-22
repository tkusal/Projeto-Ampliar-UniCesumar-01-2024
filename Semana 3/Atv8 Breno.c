#include <stdio.h>
#include <locale.h>

int main(){
    
    setlocale(LC_ALL, "Portuguese");
    
    int numeros[3][3], soma = 0;
    
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            printf("Informe um numero, matriz [%d][%d]: ", j, i);
            scanf("%d", &numeros[j][i]);
            
            if (i == j) {
                soma += numeros[j][i];
                
                
                
                
            }
        }
    }
    
    printf("A soma é : %d", soma);
    
    return 0;
}
