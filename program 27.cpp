#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to calculate (base^exponent) % modulus
long long int power(long long int base, long long int exponent, long long int modulus) {
    long long int result = 1;
    base = base % modulus;
    
    while (exponent > 0) {
        if (exponent % 2 == 1)
            result = (result * base) % modulus;
        exponent = exponent >> 1; // equivalent to exponent /= 2
        base = (base * base) % modulus;
    }
    
    return result;
}

// Function to calculate the greatest common divisor (GCD) of two numbers
long long int gcd(long long int a, long long int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// Function to generate the public and private keys for RSA
void generateKeys(long long int *e, long long int *d, long long int *n) {
    // Choose two large prime numbers, p and q
    long long int p = 61;
    long long int q = 53;

    // Calculate n
    *n = p * q;

    // Calculate the totient (phi) of n
    long long int phi = (p - 1) * (q - 1);

    // Choose e such that 1 < e < phi and gcd(e, phi) = 1
    *e = 17;

    // Calculate d, the modular multiplicative inverse of e (d * e = 1 (mod phi))
    *d = 413;

    // Check if d is negative and add phi to make it positive
    while (*d < 0)
        *d += phi;
}

// Function to encrypt a message using RSA
long long int encrypt(long long int plaintext, long long int e, long long int n) {
    return power(plaintext, e, n);
}

// Function to decrypt a message using RSA
long long int decrypt(long long int ciphertext, long long int d, long long int n) {
    return power(ciphertext, d, n);
}

int main() {
    long long int e, d, n;

    // Generate public and private keys
    generateKeys(&e, &d, &n);

    // Message to be encrypted
    char message[] = "HELLO";

    // Encrypt and decrypt each character in the message
    for (int i = 0; message[i] != '\0'; i++) {
        long long int plaintext = message[i] - 'A'; // Map 'A' to 0, 'B' to 1, ..., 'Z' to 25
        long long int ciphertext = encrypt(plaintext, e, n);
        long long int decryptedText = decrypt(ciphertext, d, n);

        // Print results
        printf("Original: %c, Encrypted: %lld, Decrypted: %c\n", message[i], ciphertext, decryptedText + 'A');
    }

    return 0;
}
