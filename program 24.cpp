#include <stdio.h>

// Function to calculate modular exponentiation
long long int modularExponentiation(long long int base, unsigned int exponent, long long int modulus) {
    long long int result = 1;
    base = base % modulus;

    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = (result * base) % modulus;
        }
        exponent = exponent >> 1;
        base = (base * base) % modulus;
    }

    return result;
}

// Function to calculate GCD using Euclidean algorithm
long long int gcd(long long int a, long long int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

// Function to calculate modular multiplicative inverse using Extended Euclidean algorithm
long long int modInverse(long long int e, long long int phi) {
    long long int x, y;
    for (x = 1; x < phi; x++) {
        if (((e % phi) * (x % phi)) % phi == 1) {
            return x;
        }
    }
    return -1; // Error: Multiplicative inverse does not exist
}

int main() {
    long long int e = 31;
    long long int n = 3599;
    long long int p = 61; // Assume p and q are known (for example)
    long long int q = 59; // In real scenarios, p and q are usually large primes, obtained through factorization of n

    long long int phi = (p - 1) * (q - 1);

    // Calculate private key d
    long long int d = modInverse(e, phi);

    printf("Private key d: %lld\n", d);

    return 0;
}

