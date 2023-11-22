#include <stdio.h>
#include <ctype.h>

#define ALPHABET_SIZE 26

// Function to calculate the modular inverse of a number
int modInverse(int a, int m) {
    a = a % m;
    for (int x = 1; x < m; x++)
        if ((a * x) % m == 1)
            return x;
    return 1;
}

// Function to encrypt text using the affine Caesar cipher
void affineCipherEncrypt(char text[], int a, int b) {
    for (int i = 0; text[i] != '\0'; i++) {
        if (isalpha(text[i])) {
            char c = toupper(text[i]);
            int p = c - 'A';
            int encrypted = ((a * p) + b) % ALPHABET_SIZE;
            text[i] = 'A' + encrypted;
        }
    }
}

// Function to decrypt text using the affine Caesar cipher
void affineCipherDecrypt(char text[], int a, int b) {
    int aInverse = modInverse(a, ALPHABET_SIZE);
    for (int i = 0; text[i] != '\0'; i++) {
        if (isalpha(text[i])) {
            char c = toupper(text[i]);
            int encrypted = c - 'A';
        

