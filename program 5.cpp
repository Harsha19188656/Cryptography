#include <stdio.h>
#include <ctype.h>

// Function to encrypt a single character using the affine Caesar cipher
char encrypt(char ch, int key1, int key2) {
    if (isalpha(ch)) {
        char base = isupper(ch) ? 'A' : 'a';
        return (char)((key1 * (ch - base) + key2) % 26 + base);
    }
    return ch;
}

// Function to encrypt a string using the affine Caesar cipher
void affineCaesarCipher(char *text, int key1, int key2) {
    for (int i = 0; text[i] != '\0'; ++i) {
        text[i] = encrypt(text[i], key1, key2);
    }
}

int main() {
    char text[100];
    int key1, key2;

    // Input message
    printf("Enter the message: ");
    fgets(text, sizeof(text), stdin);

    // Input keys
    printf("Enter key 1 (multiplicative key): ");
    scanf("%d", &key1);

    printf("Enter key 2 (additive key): ");
    scanf("%d", &key2);

    // Encrypt the message using the affine Caesar cipher
    affineCaesarCipher(text, key1, key2);

    // Display the encrypted message
    printf("Encrypted message: %s\n", text);

    return 0;
}
