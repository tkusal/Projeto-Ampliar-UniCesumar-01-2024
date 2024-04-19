#include <stdio.h>

void ihuu (int y) {
    printf("%d", y);
    y = 5;
}

int main() {
    int x = 0;

    ihuu(x++);
    printf("%d", --x);
    printf("%d", x++);


    printf("\n%d", x);

    return 0;
}