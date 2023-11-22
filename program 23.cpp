#include <stdio.h>

// S-DES encryption and decryption functions
void sdesEncryption(unsigned char *plaintext, unsigned char *key) {
    // Implement S-DES encryption
}

void sdesDecryption(unsigned char *ciphertext, unsigned char *key) {
    // Implement S-DES decryption
}

// Counter (CTR) mode encryption
void ctrEncryption(unsigned char *plaintext, unsigned char *key, unsigned char *counter) {
    int block_size = 2; // Block size for S-DES
    int num_blocks = 3; // Number of blocks in the plaintext

    // Encrypt each block in Counter mode
    for (int i = 0; i < num_blocks; ++i) {
        // XOR the counter with the plaintext block to create the encrypted block
        unsigned char encrypted_block[block_size];
        encrypted_block[0] = plaintext[i * block_size] ^ counter[0];
        encrypted_block[1] = plaintext[i * block_size + 1] ^ counter[1];

        // Perform S-DES encryption on the encrypted block
        sdesEncryption(encrypted_block, key);

        // Display the encrypted block
        printf("Encrypted block %d: %02X %02X\n", i + 1, encrypted_block[0], encrypted_block[1]);

        // Increment the counter for the next block
        counter[1]++; // Simulating a 2-byte counter
    }
}

// Counter (CTR) mode decryption
void ctrDecryption(unsigned char *ciphertext, unsigned char *key, unsigned char *counter) {
    int block_size = 2; // Block size for S-DES
    int num_blocks = 3; // Number of blocks in the ciphertext

    // Decrypt each block in Counter mode
    for (int i = 0; i < num_blocks; ++i) {
        // Perform S-DES decryption on the ciphertext block
        sdesDecryption(ciphertext + (i * block_size), key);

        // XOR the counter with the decrypted block to retrieve the original plaintext block
        ciphertext[i * block_size] ^= counter[0];
        ciphertext[i * block_size + 1] ^= counter[1];

        // Display the decrypted block
        printf("Decrypted block %d: %02X %02X\n", i + 1, ciphertext[i * block_size], ciphertext[i * block_size + 1]);

        // Increment the counter for the next block
        counter[1]++; // Simulating a 2-byte counter
    }
}

int main() {
    unsigned char plaintext[] = {0x01, 0x02, 0x04}; // Binary plaintext blocks
    unsigned char key[] = {0x7D}; // Binary key 01111 1101
    unsigned char counter[] = {0x00, 0x00}; // Binary counter starting at 0000 0000

    // Encryption
    printf("Encryption:\n");
    ctrEncryption(plaintext, key, counter);

    // Decryption
    printf("\nDecryption:\n");
    unsigned char ciphertext[] = {0x38, 0x4F, 0x32}; // Expected ciphertext
    ctrDecryption(ciphertext, key, counter);

    return 0;
}

