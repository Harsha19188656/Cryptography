#include <stdio.h>

int main() {
    // Known mappings
    int cipher_B = 1; // 'B' in the cipher
    int plain_E = 4;  // 'E' in plaintext
    int cipher_U = 20; // 'U' in the cipher
    int plain_T = 19;  // 'T' in plaintext
    
    // Calculate 'a' and 'b'
    int a, b;
    
    // Solving for 'a'
    for (a = 1; a < 26; a++) {
        if ((a * cipher_B + b) % 26 == plain_E) {
            break;
        }
    }
    
    // Solving for 'b' using 'a'
    for (b = 0; b < 26; b++) {
        if ((a * cipher_U + b) % 26 == plain_T) {
            break;
        }
    }
    
    printf("Found 'a' value: %d\n", a);
    printf("Found 'b' value: %d\n", b);
    
    return 0;
}

