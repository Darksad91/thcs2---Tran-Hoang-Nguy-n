#include <stdio.h>
#include <string.h>

int is_upper(char c) {
    return c >= 'A' && c <= 'Z';
}

int is_lower(char c) {
    return c >= 'a' && c <= 'z';
}

int is_digit(char c) {
    return c >= '0' && c <= '9';
}

int main() {
    char password[101];
    fgets(password, sizeof(password), stdin);
    password[strcspn(password, "\n")] = '\0';

    int hasUpper = 0, hasLower = 0, hasDigit = 0, hasSpecial = 0;
    int specialCount = 0;
    int length = strlen(password);

    for (int i = 0; i < length; i++) {
        char c = password[i];

        if (is_upper(c)) hasUpper = 1;
        else if (is_lower(c)) hasLower = 1;
        else if (is_digit(c)) hasDigit = 1;
        else {
            hasSpecial = 1;
            specialCount++;
        }
    }

    int isValid = 1;

    if (length < 8) isValid = 0;
    if (!hasUpper || !hasLower || !hasDigit || !hasSpecial) isValid = 0;

    if (isValid) {
        printf("Valid\n");
    } else {
        printf("Invalid\n");
        printf("Error:");
        if (length < 8) printf(" Length < 8;");
        if (!hasUpper) printf(" Missing uppercase;");
        if (!hasLower) printf(" Missing lowercase;");
        if (!hasDigit) printf(" Missing digit;");
        if (!hasSpecial) printf(" Missing special character;");
        printf("\n");
    }

    printf("%d\n", specialCount);

    return 0;
}

