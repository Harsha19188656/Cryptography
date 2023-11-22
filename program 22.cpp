#include <stdio.h>

// S-DES encryption functions
void initialPermutation(unsigned char block[8]) {
    // Initial permutation logic
    // Implement initial permutation here
}

void sdesEncryption(unsigned char block[8], unsigned char key[10], unsigned char iv[8]) {
    // S-DES encryption logic
    // Implement S-DES encryption using the given block, key, and IV
}

// S-DES decryption functions
void sdesDecryption(unsigned char block[8], unsigned char key[10], unsigned char iv[8]) {
    // S-DES decryption logic
    // Implement S-DES decryption using the given block, key, and IV
}

void finalPermutation(unsigned char block[8]) {
    // Final permutation logic
    // Implement final permutation here
}

int main() {
    unsigned char plaintext[] = {0x01, 0x23}; // Binary plaintext 0000 0001 0010 0011
    unsigned char key[] = {0x7D}; // Binary key 01111 1101
    unsigned char iv[] = {0xAA}; // Binary IV 1010 1010

    // Encryption
    printf("Encryption:\n");
    initialPermutation(iv);
    printf("IV after initial permutation: %02X\n", iv[0]);
    sdesEncryption(plaintext, key, iv);
    printf("Encrypted ciphertext: %02X\n", plaintext[0]);

    // Decryption
    printf("\nDecryption:\n");
    unsigned char decrypted_plaintext[8] = {0x00};
    sdesDecryption(plaintext, key, iv);
    printf("Decrypted plaintext: %02X\n", plaintext[0]);

    return 0;
}


