#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define ALPHABET_SIZE 26

// Function to count the frequency of characters in the ciphertext
void countFrequency(const char *text, int frequency[]) {
    int i;
    for (i = 0; i < strlen(text); i++) {
        char c = toupper(text[i]);
        if (isalpha(c)) {
            frequency[c - 'A']++;
        }
    }
}

int main() {
    char ciphertext[] = "53‡‡†305))6*;4826)4‡.)4‡);806*;48†8¶60))85;;]8*;:‡*8†83 (88)5*†;46(;88*96*?;8)*‡(;485);5*†2:*‡(;4956*2(5*—4)8¶8* ;4069285);)6†8)4‡‡;1(‡9;48081;8:8‡1;48†85;4)485†528806*81 (‡9;48;(88;4(‡?34;48)4‡;161;:188;‡?";
    
    // Initialize frequency array for 26 letters
    int frequency[ALPHABET_SIZE] = {0};
    
    // Count frequency of characters in the ciphertext
    countFrequency(ciphertext, frequency);
    
    // Print the frequency of each letter
    printf("Frequency analysis of the ciphertext:\n");
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        printf("%c: %d\n", 'A' + i, frequency[i]);
    }
    
    return 0;
}

