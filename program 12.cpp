#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MOD 26 // Modulus for the alphabet

// Function to convert a character to its numerical equivalent (A=0, B=1, ..., Z=25)
int charToNum(char ch) {
    return (ch >= 'a' && ch <= 'z') ? (ch - 'a') : (ch - 'A');
}

// Function to convert a number to its corresponding letter
char numToChar(int num) {
    return (char)(num + 'A');
}

// Function to perform matrix multiplication for encryption/decryption
void matrixMultiply(int key[2][2], int message[2], int result[2], int size) {
    for (int i = 0; i < size; i++) {
        result[i] = 0;
        for (int j = 0; j < size; j++) {
            result[i] += key[i][j] * message[j];
        }
        result[i] %= MOD;
    }
}

// Function to calculate the modular multiplicative inverse of a number
int modInverse(int a, int m) {
    a %= m;
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1) {
            return x;
        }
    }
    return -1; // If the inverse doesn't exist
}

int main() {
    int key[2][2] = {{9, 4}, {5, 7}}; // Key matrix
    char plaintext[] = "meet me at the usual place at ten rather than eight oclock"; // Plaintext to encrypt
    int size = 2; // Size of the matrix
    
    // Encrypting the message
    int length = strlen(plaintext);
    int blocks = length / size + (length % size != 0); // Calculate the number of blocks
    int encrypted[length];
    
    printf("Encryption:\n");
    for (int i = 0; i < blocks; i++) {
        int block[size];
        for (int j = 0; j < size; j++) {
            block[j] = (i * size + j < length) ? charToNum(plaintext[i * size + j]) : 0;
        }

        int result[size];
        matrixMultiply(key, block, result, size);

        for (int j = 0; j < size; j++) {
            encrypted[i * size + j] = result[j];
            printf("%c", numToChar(result[j]));
        }
        printf(" ");
    }
    printf("\n");
    
    // Decrypting the ciphertext
    printf("\nDecryption:\n");
    int inverse[2][2] = {{7, -4}, {-5, 9}}; // Inverse of the key matrix
    int det = (key[0][0] * key[1][1] - key[0][1] * key[1][0]) % MOD;
    int invDet = modInverse(det, MOD);

    for (int i = 0; i < blocks; i++) {
        int block[size];
        for (int j = 0; j < size; j++) {
            block[j] = encrypted[i * size + j];
        }

        int result[size];
        matrixMultiply(inverse, block, result, size);

        for (int j = 0; j < size; j++) {
            result[j] = (result[j] * invDet) % MOD;
            printf("%c", numToChar(result[j]));
        }
        printf(" ");
    }
    printf("\n");
    
    return 0;
}

