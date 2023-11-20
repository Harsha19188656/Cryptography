#include <stdio.h>
#include <stdlib.h>

// Function for circular left shift on a 28-bit half key
unsigned long circularLeftShift(unsigned long keyHalf, int shiftAmount) {
    return ((keyHalf << shiftAmount) | (keyHalf >> (28 - shiftAmount))) & 0xFFFFFFF;
}

int main() {
    unsigned long initialKey = 0x123456789ABCDE; // 56-bit initial key (in hexadecimal)

    unsigned long keyLeftHalf = (initialKey >> 28) & 0xFFFFFFF; // First 28 bits
    unsigned long keyRightHalf = initialKey & 0xFFFFFFF; // Second 28 bits

    int shiftSchedule[] = {1, 2, 4, 6, 8, 10, 12, 14, 15, 17, 19, 21, 23, 25, 27, 28};

    unsigned long subkeyLeft, subkeyRight;

    for (int round = 0; round < 16; round++) {
        subkeyLeft = circularLeftShift(keyLeftHalf, shiftSchedule[round]);
        subkeyRight = circularLeftShift(keyRightHalf, shiftSchedule[round]);

        // Combine subkeys into a single 48-bit subkey
        unsigned long subkey = (subkeyLeft << 28) | subkeyRight;

        printf("Subkey %d: 0x%lX\n", round + 1, subkey);
    }

    return 0;
}

