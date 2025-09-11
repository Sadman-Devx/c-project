#include <stdio.h>

int main() {
    int num1, num2;


    printf("Enter the first integer: ");
    scanf("%d", &num1);

    printf("Enter the second integer: ");
    scanf("%d", &num2);

    int sum = num1 + num2;
    int difference = num1 - num2;
    int product = num1 * num2;
    float quotient = (float)num1 / num2;


    printf("Sum: %d\n", sum);
    printf("Difference: %d\n", difference);
    printf("Product: %d\n", product);


    if (num2 != 0) {
        printf("Quotient: %.2f\n", quotient);
    } else {
        printf("Division by zero is not possible.\n");
    }

    return 0;
}
