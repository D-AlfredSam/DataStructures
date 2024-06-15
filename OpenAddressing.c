#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10

int hashFunction(int key) {
    return key % TABLE_SIZE;
}

void insert(int hashTable[], int key) {
    int hashIndex = hashFunction(key);

    while (hashTable[hashIndex] != -1) {
        hashIndex = (hashIndex + 1) % TABLE_SIZE;
    }

    hashTable[hashIndex] = key;
}

void display(int hashTable[]) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hashTable[i] != -1)
            printf("Index %d: %d\n", i, hashTable[i]);
        else
            printf("Index %d: \n", i);
    }
}

int main() {
    int hashTable[TABLE_SIZE];

    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = -1;
    }

    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int* arr = (int*)malloc(n * sizeof(int));
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        insert(hashTable, arr[i]);
    }

    printf("Hash Table:\n");
    display(hashTable);

    free(arr);
    return 0;
}
