#include <stdio.h>
#include <stdlib.h>

#define INITIAL_TABLE_SIZE 10
#define LOAD_FACTOR_THRESHOLD 0.7

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct HashTable {
    Node** table;
    int size;
    int count;
} HashTable;

int hashFunction(int key, int size) {
    return key % size;
}

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

HashTable* createHashTable(int size) {
    HashTable* hashTable = (HashTable*)malloc(sizeof(HashTable));
    if (hashTable == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    hashTable->table = (Node**)malloc(size * sizeof(Node*));
    if (hashTable->table == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    hashTable->size = size;
    hashTable->count = 0;
    for (int i = 0; i < size; i++) {
        hashTable->table[i] = NULL;
    }
    return hashTable;
}

void freeHashTable(HashTable* hashTable) {
    if (hashTable == NULL) return;
    for (int i = 0; i < hashTable->size; i++) {
        Node* current = hashTable->table[i];
        while (current != NULL) {
            Node* temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(hashTable->table);
    free(hashTable);
}

void rehash(HashTable* hashTable) {
    int newSize = hashTable->size * 2;
    Node** newTable = (Node**)malloc(newSize * sizeof(Node*));
    if (newTable == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < newSize; i++) {
        newTable[i] = NULL;
    }

    for (int i = 0; i < hashTable->size; i++) {
        Node* current = hashTable->table[i];
        while (current != NULL) {
            Node* temp = current;
            current = current->next;
            int newIndex = hashFunction(temp->data, newSize);
            temp->next = newTable[newIndex];
            newTable[newIndex] = temp;
        }
    }

    free(hashTable->table);
    hashTable->table = newTable;
    hashTable->size = newSize;
}

void insert(HashTable* hashTable, int key) {
    int index = hashFunction(key, hashTable->size);
    Node* newNode = createNode(key);

    newNode->next = hashTable->table[index];
    hashTable->table[index] = newNode;
    hashTable->count++;

    // Check if rehashing is needed
    if ((double)hashTable->count / hashTable->size > LOAD_FACTOR_THRESHOLD) {
        rehash(hashTable);
    }
}

void display(HashTable* hashTable) {
    for (int i = 0; i < hashTable->size; i++) {
        printf("Index %d: ", i);
        Node* current = hashTable->table[i];
        while (current != NULL) {
            printf("%d -> ", current->data);
            current = current->next;
        }
        printf("NULL\n");
    }
}

int main() {
    HashTable* hashTable = createHashTable(INITIAL_TABLE_SIZE);

    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        int key;
        scanf("%d", &key);
        insert(hashTable, key);
    }

    printf("Hash Table:\n");
    display(hashTable);

    freeHashTable(hashTable);

    return 0;
}
