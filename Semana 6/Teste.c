#include <stdio.h>

void retorno (int *b) {
    int a =1;
    if (a == 1) {
        return;
    } else {
        *b = 1;
    }

}

int main() {
    int b = 0;

    retorno(&b);

    printf("%d", b);

    return 0;
}