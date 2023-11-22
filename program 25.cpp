#include <stdio.h>

// Function to calculate GCD using Euclidean algorithm
long long int gcd(long long int a, long long int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    long long int n = 179; // Example value of n (product of two primes)
    long long int e = 7;   // Example public key

    // Assuming we have some plaintext blocks
    long long int plaintext_blocks[] = {12, 25, 35, 48}; // Example plaintext blocks

    // Check each plaintext block for a common factor with n
    for (int i = 0; i < sizeof(plaintext_blocks) / sizeof(plaintext_blocks[0]); i++) {
        long long int gcd_result = gcd(plaintext_blocks[i], n);

        if (gcd_result > 1) {
            printf("Plaintext block %lld shares a common factor with n: %lld\n", plaintext_blocks[i], gcd_result);
            // Here, one could use the gcd_result to factorize n and find p and q
            // However, for simplicity, the factorization process is omitted in this example
        }
    }

    return 0;
}

