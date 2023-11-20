#include <stdio.h>
#include <string.h>
#include <ctype.h>

void polyalphabeticSubstitution(char message[], char key[]) {
    int i, j, keyLen, messageLen;
    char encrypted[100];

    keyLen = strlen(key);
    messageLen = strlen(message);

    for (i = 0, j = 0; i < messageLen; ++i, ++j) {
        if (j == keyLen)
            j = 0;

        // Shifting the letter in the message using the key
        int shift = toupper(key[j]) - 'A';

        if (isalpha(message[i])) {
            if (islower(message[i])) {
                encrypted[i] = 'a' + (message[i] - 'a' + shift) % 26;
            } else if (isupper(message[i])) {
                encrypted[i] = 'A' + (message[i] - 'A' + shift) % 26;
            }
        } else {
            encrypted[i] = message[i]; // Non-alphabetic characters remain unchanged
            j--; // Non-alphabetic characters don't count towards the key shift
        }
    }

    encrypted[i] = '\0';
    printf("Encrypted message: %s\n", encrypted);
}

int main() {
    char message[100], key[100];

    printf("Enter message to encrypt: ");
    fgets(message, sizeof(message), stdin);

    printf("Enter the key (word or phrase): ");
    fgets(key, sizeof(key), stdin);

    // Remove newline characters if present in inputs
    message[strcspn(message, "\n")] = '\0';
    key[strcspn(key, "\n")] = '\0';

    polyalphabeticSubstitution(message, key);

    return 0;
}

