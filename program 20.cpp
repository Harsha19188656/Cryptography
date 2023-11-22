#include <stdio.h>

// Function to generate subkeys
void generateSubkeys(unsigned char initialKey[8]) {
    // Initial permutation, PC-1
    // Perform operations to select 28-bit subsets for the first and second 24 bits
    unsigned char subset1[4];
    unsigned char subset2[4];

    // Extracting subsets from the initial key
    for (int i = 0; i < 4; ++i) {
        subset1[i] = initialKey[i];
        subset2[i] = initialKey[i + 4];
    }

    // Displaying the subsets
    printf("Subset 1 (First 24 bits of subkeys):\n");
    for (int i = 0; i < 4; ++i) {
        printf("%02X ", subset1[i]);
    }
    printf("\n");

    printf("Subset 2 (Second 24 bits of subkeys):\n");
    for (int i = 0; i < 4; ++i) {
        printf("%02X ", subset2[i]);
    }
    printf("\n");
}

int main() {
    // Initial 56-bit key
    unsigned char initialKey[8] = {0x12, 0x34, 0x56, 0x78, 0x9A, 0xBC, 0xDE, 0xF0};

    // Generating subkeys
    generateSubkeys(initialKey);

    return 0;
}

