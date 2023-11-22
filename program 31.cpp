#include <stdio.h>
#include <stdint.h>

#define BLOCK_SIZE_64 8 // 64 bits, in bytes
#define CONSTANT_64 0x1B // Constant for 64-bit block size

// Function to perform left shift operation on a block
void leftShift(uint8_t block[], int size) {
    uint8_t carry = 0;
    for (int i = size - 1; i >= 0; i--) {
        uint8_t temp = block[i] >> 7; // Extract the carry bit
        block[i] = (block[i] << 1) | carry; // Left shift by 1 and OR with previous carry
        carry = temp; // Update carry with the extracted bit
    }
}

// Function to generate CMAC subkeys for a 64-bit block size
void generateSubKeys64(uint8_t key[]) {
    uint8_t subKey1[BLOCK_SIZE_64];
    uint8_t subKey2[BLOCK_SIZE_64];

    // Initial block consisting of 0 bits
    uint8_t zeroBlock[BLOCK_SIZE_64] = {0};

    // Apply block cipher to the zero block using the key (omitted for simplicity)
    // Here, let's assume the block cipher operation happened and modified zeroBlock

    // Generate first subkey
    for (int i = 0; i < BLOCK_SIZE_64; i++) {
        subKey1[i] = zeroBlock[i];
    }

    // Conditionally left shift and XOR with constant for subkey 1
    if (zeroBlock[0] >> 7 == 1) {
        leftShift(subKey1, BLOCK_SIZE_64);
        subKey1[BLOCK_SIZE_64 - 1] ^= CONSTANT_64;
    } else {
        leftShift(subKey1, BLOCK_SIZE_64);
    }

    // Generate second subkey from first subkey
    for (int i = 0; i < BLOCK_SIZE_64; i++) {
        subKey2[i] = subKey1[i];
    }

    // Conditionally left shift and XOR with constant for subkey 2
    if (subKey1[0] >> 7 == 1) {
        leftShift(subKey2, BLOCK_SIZE_64);
        subKey2[BLOCK_SIZE_64 - 1] ^= CONSTANT_64;
    } else {
        leftShift(subKey2, BLOCK_SIZE_64);
    }

    // Print the generated subkeys
    printf("SubKey 1: ");
    for (int i = 0; i < BLOCK_SIZE_64; i++) {
        printf("%02X ", subKey1[i]);
    }
    printf("\n");

    printf("SubKey 2: ");
    for (int i = 0; i < BLOCK_SIZE_64; i++) {
        printf("%02X ", subKey2[i]);
    }
    printf("\n");
}

int main() {
    // Example key for demonstration (64-bit key)
    uint8_t key[BLOCK_SIZE_64] = {0x12, 0x34, 0x56, 0x78, 0x9A, 0xBC, 0xDE, 0xFF};

    // Generate CMAC subkeys for 64-bit block size
    generateSubKeys64(key);

    return 0;
}

