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

// Function to perform the letter frequency attack
void letterFrequencyAttack(const char *cipherText, int topCount) {
    int frequency[ALPHABET_SIZE] = {0};
    countFrequency(cipherText, frequency);

    int i, j, maxIdx, maxFreq;
    char plaintext[ALPHABET_SIZE];
    char possiblePlaintexts[topCount][ALPHABET_SIZE];

    for (i = 0; i < topCount; i++) {
        maxFreq = 0;
        for (j = 0; j < ALPHABET_SIZE; j++) {
            if (frequency[j] > maxFreq) {
                maxFreq = frequency[j];
                maxIdx = j;
            }
        }

        plaintext[maxIdx] = 'a' + maxIdx;
        frequency[maxIdx] = 0;

        strcpy(possiblePlaintexts[i], plaintext);
    }

    printf("Top %d possible plaintexts:\n", topCount);
    for (i = 0; i < topCount; i++) {
        printf("%d. %s\n", i + 1, possiblePlaintexts[i]);
    }
}

int main() {
    char cipherText[] = "PLOOLQJ WKH EHOLHI";
    int topCount = 10;

    letterFrequencyAttack(cipherText, topCount);

    return 0;
}

