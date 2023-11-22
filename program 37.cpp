#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define ALPHABET_SIZE 26

// Function to count the frequency of each letter in the given text
void countFrequency(const char *text, int freq[]) {
    for (int i = 0; text[i] != '\0'; i++) {
        if (isalpha(text[i])) {
            char c = tolower(text[i]);
            freq[c - 'a']++;
        }
    }
}

// Function to perform the letter frequency attack
void letterFrequencyAttack(const char *cipherText, int topCount) {
    int frequency[ALPHABET_SIZE] = {0};
    countFrequency(cipherText, frequency);

    int mapping[ALPHABET_SIZE];
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        int maxIdx = 0;
        for (int j = 0; j < ALPHABET_SIZE; j++) {
            if (frequency[j] > frequency[maxIdx]) {
                maxIdx = j;
            }
        }
        frequency[maxIdx] = -1; // Mark the processed letter
        mapping[maxIdx] = i; // Store the mapping order
    }

    char plaintextMapping[ALPHABET_SIZE + 1];
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        plaintextMapping[mapping[i]] = 'a' + i; // Create the mapping for substitution
    }
    plaintextMapping[ALPHABET_SIZE] = '\0';

    printf("Mapping: %s\n", plaintextMapping);

    char possiblePlaintexts[topCount][strlen(cipherText) + 1];
    for (int i = 0; i < topCount; i++) {
        for (int j = 0; cipherText[j] != '\0'; j++) {
            char c = cipherText[j];
            if (isalpha(c)) {
                char substitute = plaintextMapping[c - 'a'];
                possiblePlaintexts[i][j] = isupper(c) ? toupper(substitute) : substitute;
            } else {
                possiblePlaintexts[i][j] = c;
            }
        }
        possiblePlaintexts[i][strlen(cipherText)] = '\0';
    }

    printf("Top %d possible plaintexts:\n", topCount);
    for (int i = 0; i < topCount; i++) {
        printf("%d. %s\n", i + 1, possiblePlaintexts[i]);
    }
}

int main() {
    char cipherText[] = "GWC UCEW GWC IKGTU ETGCM ETGCM";
    int topCount = 10;

    letterFrequencyAttack(cipherText, topCount);

    return 0;
}

