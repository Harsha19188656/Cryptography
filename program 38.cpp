#include <stdio.h>

#define MOD 26

// Function to calculate the modular inverse of a number
int modInverse(int a, int m) {
    a = a % m;
    for (int x = 1; x < m; x++)
        if ((a * x) % m == 1)
            return x;
    return 1;
}

// Function to calculate the determinant of a 2x2 matrix
int determinant(int key[2][2]) {
    return key[0][0] * key[1][1] - key[0][1] * key[1][0];
}

// Function to find the modular inverse of a 2x2 matrix
void inverse(int key[2][2], int invKey[2][2]) {
    int det = determinant(key);
    int detInv = modInverse(det, MOD);

    invKey[0][0] = key[1][1];
    invKey[0][1] = -key[0][1];
    invKey[1][0] = -key[1][0];
    invKey[1][1] = key[0][0];

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            invKey[i][j] = (invKey[i][j] * detInv) % MOD;
            if (invKey[i][j] < 0)
                invKey[i][j] += MOD;
        }
    }
}

// Function to decrypt ciphertext using the inverse of the key matrix
void decrypt(int cipherText[], int plainText[], int key[2][2], int invKey[2][2], int length) {
    for (int i = 0; i < length; i += 2) {
        int a = cipherText[i] - 'A';
        int b = cipherText[i + 1] - 'A';

        plainText[i] = (invKey[0][0] * a + invKey[0][1] * b) % MOD;
        plainText[i + 1] = (invKey[1][0] * a + invKey[1][1] * b) % MOD;

        if (plainText[i] < 0)
            plainText[i] += MOD;
        if (plainText[i + 1] < 0)
            plainText[i + 1] += MOD;

        plainText[i] += 'A';
        plainText[i + 1] += 'A';
    }
}

int main() {
    int key[2][2] = {{3, 2}, {5, 7}}; // Example key matrix
    int invKey[2][2];

    // Obtain the inverse of the key matrix
    inverse(key, invKey);

    int cipherText[] = {20, 1, 8, 11, 23, 14, 9, 11}; // Example ciphertext
    int length = sizeof(cipherText) / sizeof(cipherText[0]);
    int plainText[length];

    // Decrypt the ciphertext using the inverse key
    decrypt(cipherText, plainText, key, invKey, length);

    // Display the decrypted plaintext
    printf("Decrypted Plaintext: ");
    for (int i = 0; i < length; i++)
        printf("%c", plainText[i]);
    printf("\n");

    return 0;
}

