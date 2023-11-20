#include <stdio.h>

int main() {
    int keySize = 25; // Size of the Playfair matrix
    unsigned long long int totalKeys = 1; // Initialize total keys to 1

    // Calculate the approximate number of keys by multiplying available choices
    for (int i = 0; i < keySize; i++) {
        totalKeys *= (keySize - i);
    }

    // Print the total number of keys as an approximate power of 2
    int powerOfTwo = 0;
    while (totalKeys > 1) {
        totalKeys /= 2;
        powerOfTwo++;
    }

    printf("Approximate number of keys in the Playfair cipher: 2^%d\n", powerOfTwo);

    return 0;
}

