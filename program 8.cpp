#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define ALPHABET_SIZE 26

// Function to generate the cipher sequence from a keyword
void generateCipherSequence(const char *keyword, char *cipherSequence) {
    int used[ALPHABET_SIZE] = {0}; // Array to track used letters
    int keywordLen = strlen(keyword);
    int i, j;

    // Copy the keyword to the cipher sequence
    strcpy(cipherSequence, keyword);

    // Mark letters in the keyword as used
    for (i = 0; i < keywordLen; i++) {
        if (isalpha(keyword[i])) {
            used[toupper(keyword[i]) - 'A'] = 1;
        }
    }

    // Fill the rest of the cipher sequence with unused letters in normal order
    for (i = 0, j = 0; i < ALPHABET_SIZE; i++) {
        if (!used[i]) {
            cipherSequence[keywordLen + j] = 'A' + i;
            j++;
        }
    }
    cipherSequence[keywordLen + j] = '\0'; // Null-terminate the cipher sequence
}

// Function to encrypt plaintext using the generated cipher sequence
void encrypt(const char *plaintext, const char *cipherSequence, char *ciphertext) {
    int length = strlen(plaintext);
    for (int i = 0; i < length; i++) {
        if (isalpha(plaintext[i])) {
            char originalChar = toupper(plaintext[i]);
            if (originalChar >= 'A' && originalChar <= 'Z') {
                int index = originalChar - 'A';
                char encryptedChar = islower(plaintext[i]) ? tolower(cipherSequence[index]) : cipherSequence[index];
                ciphertext[i] = encryptedChar;
            }
        } else {
            ciphertext[i] = plaintext[i];
        }
    }
    ciphertext[length] = '\0'; // Null-terminate the ciphertext
}

int main() {
    const char *keyword = "CIPHER";
    char cipherSequence[ALPHABET_SIZE + 1];
    char plaintext[] = "HELLO WORLD"; // Replace with your plaintext

    generateCipherSequence(keyword, cipherSequence);
    printf("Cipher Sequence: %s\n", cipherSequence);

    char ciphertext[strlen(plaintext) + 1];
    encrypt(plaintext, cipherSequence, ciphertext);

    printf("Plaintext: %s\n", plaintext);
    printf("Ciphertext: %s\n", ciphertext);

    return 0;
}

