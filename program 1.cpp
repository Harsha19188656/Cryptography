#include <stdio.h>
#include <ctype.h>

void caesarCipher(char message[], int key) {
    char ch;
    int i;

    for(i = 0; message[i] != '\0'; ++i) {
        ch = message[i];

        if(isalpha(ch)) {
            char base = islower(ch) ? 'a' : 'A';
            ch = base + (ch - base + key) % 26;
        }

        message[i] = ch;
    }

    printf("Encrypted message: %s\n", message);
}

int main() {
    char message[100];
    int key;

    printf("Enter message to encrypt: ");
    fgets(message, sizeof(message), stdin);

    for (;;) {
        printf("Enter key (1-25): ");
        scanf("%d", &key);

        if (key >= 1 && key <= 25) {
            break;
        } else {
            printf("Invalid key! Please enter a key between 1 and 25.\n");
        }
    }

    caesarCipher(message, key);

    return 0;
}

