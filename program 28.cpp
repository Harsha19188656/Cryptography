#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to calculate (base^exponent) % mod
long long int mod_exp(long long int base, long long int exponent, long long int mod) {
    long long int result = 1;

    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = (result * base) % mod;
        }

        base = (base * base) % mod;
        exponent = exponent / 2;
    }

    return result;
}

// Function to perform Diffie-Hellman key exchange
long long int diffie_hellman(long long int base, long long int private_key, long long int mod) {
    return mod_exp(base, private_key, mod);
}

int main() {
    // Common parameters
    long long int base = 2;    // Common base
    long long int mod = 23;    // Common modulus
    long long int alice_private_key, bob_private_key; // Private keys for Alice and Bob

    // Generate private keys for Alice and Bob
    alice_private_key = rand() % mod;
    bob_private_key = rand() % mod;

    // Calculate public keys for Alice and Bob
    long long int alice_public_key = diffie_hellman(base, alice_private_key, mod);
    long long int bob_public_key = diffie_hellman(base, bob_private_key, mod);

    // Exchange public keys
    printf("Alice's public key: %lld\n", alice_public_key);
    printf("Bob's public key: %lld\n", bob_public_key);

    // Calculate the shared secret
    long long int alice_shared_secret = diffie_hellman(bob_public_key, alice_private_key, mod);
    long long int bob_shared_secret = diffie_hellman(alice_public_key, bob_private_key, mod);

    // Display the shared secret
    printf("Shared secret (Alice): %lld\n", alice_shared_secret);
    printf("Shared secret (Bob): %lld\n", bob_shared_secret);

    return 0;
}
