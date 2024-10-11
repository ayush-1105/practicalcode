#include <stdio.h>

int countCollisions(int keys[], int size, int tableSize) {
    int hashAddresses[size], collisions = 0;

    for (int i = 0; i < size; i++) {
        hashAddresses[i] = keys[i] % tableSize;
    }

    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (hashAddresses[i] == hashAddresses[j]) {
                collisions++;
            }
        }
    }

    return collisions;
}

int main() {
    int keys[] = {9893, 2341, 4312, 7893, 4531, 8731, 3184, 5421, 4955, 1496};
    int size = sizeof(keys) / sizeof(keys[0]);
    int tableSize = 64;

    int collisions = countCollisions(keys, size, tableSize);
    printf("Number of collisions: %d\n", collisions);

    return 0;
}
