#include <stdio.h>
#include <ctype.h>

void monoalphabeticSubstitution(char message[], char key[]) {
    int i;

    for (i = 0; message[i] != '\0'; ++i) {
        char ch = message[i];

        if (isalpha(ch)) {
            if (islower(ch)) {
                message[i] = key[ch - 'a'];
            } else {
                message[i] = toupper(key[ch - 'A']);
            }
        }
    }

    printf("Encrypted message: %s\n", message);
}

int main() {
    char message[100];
    char key[26];

    printf("Enter message to encrypt: ");
    fgets(message, sizeof(message), stdin);

    printf("Enter the substitution key (26 unique letters, no repetitions): ");
    fgets(key, sizeof(key), stdin);

    // Ensure the key has 26 unique letters
    int i, j, valid = 1;
    for (i = 0; i < 26; ++i) {
        if (!isalpha(key[i])) {
            valid = 0;
            break;
        }
        for (j = i + 1; j < 26; ++j) {
            if (tolower(key[i]) == tolower(key[j])) {
                valid = 0;
                break;
            }
        }
    }

    if (!valid) {
        printf("Invalid key! Please enter 26 unique letters.\n");
        return 1;
    }

    monoalphabeticSubstitution(message, key);

    return 0;
}

