#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define ALPHABET_SIZE 26

// Function to encrypt the plaintext using the one-time pad Vigenère cipher
void encrypt(char plaintext[], int key[], int keyLength) {
    int len = strlen(plaintext);
    int keyIndex = 0;

    for (int i = 0; i < len; i++) {
        if (isalpha(plaintext[i])) {
            int shift = key[keyIndex % keyLength];
            char base = isupper(plaintext[i]) ? 'A' : 'a';
            plaintext[i] = (char)(((plaintext[i] - base + shift) % ALPHABET_SIZE) + base);
            keyIndex++;
        }
    }
}

int main() {
    char plaintext[1000];
    int key[1000];
    int keyLength;

    printf("Enter the plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);

    printf("Enter the key length: ");
    scanf("%d", &keyLength);

    printf("Enter the key numbers (between 0 and 26): ");
    for (int i = 0; i < keyLength; i++) {
        scanf("%d", &key[i]);
    }

    // Encrypt the plaintext
    encrypt(plaintext, key, keyLength);

    printf("Encrypted text: %s\n", plaintext);

    return 0;
}

