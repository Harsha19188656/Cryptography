#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 5 // Size of the Playfair matrix (5x5)

// Function to create the Playfair matrix
void createPlayfairMatrix(char matrix[SIZE][SIZE], const char *key) {
    int used[26] = {0}; // Array to track used letters
    int keyLen = strlen(key);
    int keyIndex = 0;
    int i, j;

    // Fill the matrix with the key
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (keyIndex < keyLen) {
                char letter = toupper(key[keyIndex]);
                if (letter == 'J')
                    letter = 'I'; // Treating 'I' and 'J' as the same
                if (!used[letter - 'A']) {
                    matrix[i][j] = letter;
                    used[letter - 'A'] = 1;
                } else {
                    j--; // Skip used letters
                }
                keyIndex++;
            } else {
                for (char ch = 'A'; ch <= 'Z'; ch++) {
                    if (ch != 'J' && !used[ch - 'A']) {
                        matrix[i][j] = ch;
                        used[ch - 'A'] = 1;
                        break;
                    }
                }
            }
        }
    }
}

// Function to find the row and column of a character in the Playfair matrix
void findPosition(char matrix[SIZE][SIZE], char ch, int *row, int *col) {
    if (ch == 'J')
        ch = 'I'; // 'I' and 'J' are often treated as the same in Playfair

    for (*row = 0; *row < SIZE; (*row)++) {
        for (*col = 0; *col < SIZE; (*col)++) {
            if (matrix[*row][*col] == ch) {
                return;
            }
        }
    }
}

// Function to encrypt plaintext using the Playfair cipher
void encryptPlayfair(char matrix[SIZE][SIZE], const char *plaintext) {
    int length = strlen(plaintext);
    int i = 0;

    // Remove spaces and non-alphabetic characters from the plaintext
    char formatted[length * 2];
    int index = 0;
    while (plaintext[i] != '\0') {
        char ch = toupper(plaintext[i]);
        if (isalpha(ch)) {
            formatted[index++] = ch;
        }
        i++;
    }
    formatted[index] = '\0';

    // Encrypt the formatted plaintext
    i = 0;
    while (i < strlen(formatted)) {
        char ch1 = formatted[i++];
        char ch2 = formatted[i++];
        int row1, col1, row2, col2;
        findPosition(matrix, ch1, &row1, &col1);
        findPosition(matrix, ch2, &row2, &col2);

        if (row1 == row2) {
            col1 = (col1 + 1) % SIZE;
            col2 = (col2 + 1) % SIZE;
        } else if (col1 == col2) {
            row1 = (row1 + 1) % SIZE;
            row2 = (row2 + 1) % SIZE;
        } else {
            int temp = col1;
            col1 = col2;
            col2 = temp;
        }

        printf("%c%c", matrix[row1][col1], matrix[row2][col2]);
    }
}

int main() {
    char matrix[SIZE][SIZE]; // Playfair matrix
    const char *key = "MFHIJKUNOPQZVWXYELARGDSTBC"; // Playfair key
    const char *plaintext = "Must see you over Cadogan West. Coming at once"; // Plaintext to encrypt

    createPlayfairMatrix(matrix, key);
    encryptPlayfair(matrix, plaintext);

    return 0;
}

