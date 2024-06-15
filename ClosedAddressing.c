#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10

typedef struct Node {
    int data;
    struct Node* next;
} Node;

int hashFunction(int key) {
    return key % TABLE_SIZE;
}

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insert(Node* hashTable[], int key) {
    int hashIndex = hashFunction(key);
    Node* newNode = createNode(key);

    if (hashTable[hashIndex] == NULL) {
        hashTable[hashIndex] = newNode;
    } else {
        Node* temp = hashTable[hashIndex];
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void display(Node* hashTable[]) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("Index %d: ", i);
        Node* temp = hashTable[i];
        while (temp != NULL) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

void freeHashTable(Node* hashTable[]) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        Node* temp = hashTable[i];
        while (temp != NULL) {
            Node* toFree = temp;
            temp = temp->next;
            free(toFree);
        }
    }
}

int main() {
    Node* hashTable[TABLE_SIZE] = {NULL};

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
    freeHashTable(hashTable);

    return 0;
}
