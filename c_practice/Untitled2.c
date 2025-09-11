#include <stdio.h>

int main() {
    int a, b, c;

    // Read three integers from input
    scanf("%d %d %d", &a, &b, &c);

    // Find the greatest value
    int greatest = a;

    if (b > greatest) {
        greatest = b;
    }
    if (c > greatest) {
        greatest = c;
    }

    // Output the greatest value followed by the message
    printf("%d eh o maior\n", greatest);

    return 0;
}

