#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define ALPHABET_SIZE 26

// Function to count the frequency of each letter in the given text
void countFrequency(const char *text, int freq[]) {
    int i;
    for (i = 0; text[i] != '\0'; i++) {
        if (isalpha(text[i])) {
            char c = tolower(text[i]);
            freq[c - 'a']++;
        }
    }
}

// Function to perform the letter frequency attack on additive cipher
void additiveCipherAttack(const char *cipherText, int topCount) {
    int frequency[ALPHABET_SIZE] = {0};
    countFrequency(cipherText, frequency);

    // Find the most frequent letter in the cipher text
    int maxFreq = 0, maxIdx = 0;
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (frequency[i] > maxFreq) {
            maxFreq = frequency[i];
            maxIdx = i;
        }
    }

    int shift = (maxIdx + ALPHABET_SIZE - ('e' - 'a')) % ALPHABET_SIZE; // Shifting to 'e' (most common English letter)
    char possiblePlaintexts[topCount][strlen(cipherText) + 1];

    for (int i = 0; i < topCount; i++) {
        for (int j = 0; cipherText[j] != '\0'; j++) {
            char c = cipherText[j];
            if (isalpha(c)) {
                char shifted = (char)(((tolower(c) - 'a' - shift + ALPHABET_SIZE) % ALPHABET_SIZE) + 'a');
                possiblePlaintexts[i][j] = isupper(c) ? toupper(shifted) : shifted;
            } else {
                possiblePlaintexts[i][j] = c;
            }
        }
        possiblePlaintexts[i][strlen(cipherText)] = '\0';
        shift++; // Try the next possible shift
    }

    printf("Top %d possible plaintexts:\n", topCount);
    for (int i = 0; i < topCount; i++) {
        printf("%d. %s\n", i + 1, possiblePlaintexts[i]);
    }
}

int main() {
    char cipherText[] = "IFMMP XPSME";
    int topCount = 10;

    additiveCipherAttack(cipherText, topCount);

    return 0;
}

