#include <stdio.h>
#include <string.h>

int isValid(char cardNumber[17]) {
    int sum = 0;
    int length = strlen(cardNumber);
    int parity = length % 2;

    for (int i = 0; i < length; i++) {
        int digit = cardNumber[i] - '0';

        if (i % 2 == parity) {
            digit *= 2;
            if (digit > 9) {
                digit -= 9;
            }
        }

        sum += digit;
    }

    return (sum % 10 == 0);
}

int main() {
    char cardNumber[17];

    printf("Input card number (16 digit): ");
    scanf("%16s", cardNumber);

    if (isValid(cardNumber)) {
        printf("Valid number card.\n");
    } else {
        printf("Invalid number card.\n");
    }

    return 0;
}
