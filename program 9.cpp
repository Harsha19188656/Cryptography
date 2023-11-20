#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 5 // Size of the Playfair matrix (5x5)

// Function to find the row and column of a character in the Playfair matrix
void findPosition(char matrix[SIZE][SIZE], char ch, int *row, int *col) {
    if (ch == 'J') // 'I' and 'J' are often treated as the same in Playfair, here we'll replace 'J' with 'I'
        ch = 'I';

    for (*row = 0; *row < SIZE; (*row)++) {
        for (*col = 0; *col < SIZE; (*col)++) {
            if (matrix[*row][*col] == ch) {
                return;
            }
        }
    }
}

// Function to decrypt the Playfair cipher text
void decryptPlayfair(char ciphertext[], char key[]) {
    char matrix[SIZE][SIZE];
    int keyIndex = 0;
    int row1, row2, col1, col2;
    int i, j;

    // Creating the Playfair matrix using the provided key
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            matrix[i][j] = key[keyIndex++];
            if (keyIndex == strlen(key))
                keyIndex = 0;
        }
    }

    // Decrypting the ciphertext
    for (i = 0; i < strlen(ciphertext); i += 2) {
        char ch1 = ciphertext[i];
        char ch2 = ciphertext[i + 1];

        findPosition(matrix, ch1, &row1, &col1);
        findPosition(matrix, ch2, &row2, &col2);

        if (row1 == row2) {
            col1 = (col1 - 1 + SIZE) % SIZE;
            col2 = (col2 - 1 + SIZE) % SIZE;
        } else if (col1 == col2) {
            row1 = (row1 - 1 + SIZE) % SIZE;
            row2 = (row2 - 1 + SIZE) % SIZE;
        } else {
            int temp = col1;
            col1 = col2;
            col2 = temp;
        }

        printf("%c%c", matrix[row1][col1], matrix[row2][col2]);
    }
}

int main() {
    char ciphertext[] = "KXJEYUREBEZWEHEWRYTUHEYFSKREHEGOYFIWTTTUOLKSYCAJPOBOTEIZONTXBYBNTGONEYCUZWRGDSONSXBOUYWRHEBAAHYUSEDQ";
    char key[] = "PT109"; // Key used for Playfair cipher

    decryptPlayfair(ciphertext, key);

    return 0;
}

