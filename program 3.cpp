#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 5

void prepareKey(char key[], char keyMatrix[SIZE][SIZE]) {
    int i, j, k;
    char alphabet[26] = "ABCDEFGHIKLMNOPQRSTUVWXYZ"; // excluding 'J'

    int len = strlen(key);
    int visited[26] = {0};

    // Place the key in the matrix
    for (i = 0; i < len; ++i) {
        if (key[i] != ' ' && !visited[toupper(key[i]) - 'A']) {
            keyMatrix[i / SIZE][i % SIZE] = toupper(key[i]);
            visited[toupper(key[i]) - 'A'] = 1;
        }
    }

    // Fill the remaining matrix cells with the alphabet
    for (k = len, i = 0; i < SIZE; ++i) {
        for (j = 0; j < SIZE; ++j) {
            if (!keyMatrix[i][j]) {
                while (visited[alphabet[k] - 'A'])
                    ++k;

                keyMatrix[i][j] = alphabet[k++];
            }
        }
    }
}

void getPosition(char keyMatrix[SIZE][SIZE], char letter, int *row, int *col) {
    int i, j;

    for (i = 0; i < SIZE; ++i) {
        for (j = 0; j < SIZE; ++j) {
            if (keyMatrix[i][j] == letter) {
                *row = i;
                *col = j;
                return;
            }
        }
    }
}

void encryptPlayfair(char message[], char keyMatrix[SIZE][SIZE]) {
    int i, len = strlen(message);

    // Remove any spaces from the message
    for (i = 0; i < len; ++i) {
        if (message[i] == ' ') {
            for (int j = i; j < len; ++j) {
                message[j] = message[j + 1];
            }
            len--;
        }
    }

    // Convert 'J' to 'I' in the message
    for (i = 0; i < len; ++i) {
        if (message[i] == 'J')
            message[i] = 'I';
    }

    // Adjust the message length for odd number of characters
    if (len % 2 != 0) {
        message[len] = 'X';
        message[len + 1] = '\0';
        len++;
    }

    // Encrypt pairs of letters
    for (i = 0; i < len; i += 2) {
        int row1, col1, row2, col2;
        getPosition(keyMatrix, toupper(message[i]), &row1, &col1);
        getPosition(keyMatrix, toupper(message[i + 1]), &row2, &col2);

        if (row1 == row2) { // Same row
            printf("%c%c", keyMatrix[row1][(col1 + 1) % SIZE], keyMatrix[row2][(col2 + 1) % SIZE]);
        } else if (col1 == col2) { // Same column
            printf("%c%c", keyMatrix[(row1 + 1) % SIZE][col1], keyMatrix[(row2 + 1) % SIZE][col2]);
        } else { // Different row and column
            printf("%c%c", keyMatrix[row1][col2], keyMatrix[row2][col1]);
        }
    }
    printf("\n");
}

int main() {
    char key[50];
    char keyMatrix[SIZE][SIZE] = {{0}};

    printf("Enter the key: ");
    fgets(key, sizeof(key), stdin);

    prepareKey(key, keyMatrix);

    char message[100];
    printf("Enter the message to encrypt (without spaces): ");
    fgets(message, sizeof(message), stdin);

    encryptPlayfair(message, keyMatrix);

    return 0;
}
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

