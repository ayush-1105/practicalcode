#include <stdio.h>

int boundaryFolding(int key, int tableSize) {
    int sum = 0;
    while (key > 0) {
        sum += key % 100;
        key /= 100;
    }
    return sum % tableSize;
}

int main() {
    int tableSize = 1000;
    int keys[] = {321982432, 213432183, 343541652, 542313753};
    int numKeys = sizeof(keys) / sizeof(keys[0]);

    for (int i = 0; i < numKeys; i++) {
        int hashAddress = boundaryFolding(keys[i], tableSize);
        printf("Hash address for key %d: %d\n", keys[i], hashAddress);
    }

    return 0;
}
