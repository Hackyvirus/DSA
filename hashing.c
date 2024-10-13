#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10  // Size of the hash table

// Node structure for linked list
typedef struct Node {
    int key;
    struct Node* next;
} Node;

// Hash table array of pointers to nodes
Node* hashTable[TABLE_SIZE];

// Function to create a new node
Node* createNode(int key) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->next = NULL;
    return newNode;
}

// Hash function to map a key to a table index
int hashFunction(int key) {
    return key % TABLE_SIZE;
}

// Function to insert a key into the hash table
void insert(int key) {
    int index = hashFunction(key);
    Node* newNode = createNode(key);

    // If there's no node at the index, insert the new node
    if (hashTable[index] == NULL) {
        hashTable[index] = newNode;
    } else {
        // Insert the new node at the beginning of the linked list
        newNode->next = hashTable[index];
        hashTable[index] = newNode;
    }

    printf("Inserted %d into the hash table.\n", key);
}

// Function to search for a key in the hash table
Node* search(int key) {
    int index = hashFunction(key);
    Node* temp = hashTable[index];

    // Traverse the linked list at that index
    while (temp != NULL) {
        if (temp->key == key) {
            printf("Key %d found in the hash table.\n", key);
            return temp;
        }
        temp = temp->next;
    }

    printf("Key %d not found in the hash table.\n", key);
    return NULL;
}

// Function to delete a key from the hash table
void delete(int key) {
    int index = hashFunction(key);
    Node* temp = hashTable[index];
    Node* prev = NULL;

    // Traverse the linked list at that index
    while (temp != NULL) {
        if (temp->key == key) {
            if (prev == NULL) {
                // Key is at the head of the linked list
                hashTable[index] = temp->next;
            } else {
                // Key is in the middle or end of the linked list
                prev->next = temp->next;
            }
            free(temp);
            printf("Key %d deleted from the hash table.\n", key);
            return;
        }
        prev = temp;
        temp = temp->next;
    }

    printf("Key %d not found in the hash table.\n", key);
}

// Function to display the hash table
void display() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("Index %d: ", i);
        Node* temp = hashTable[i];
        while (temp != NULL) {
            printf("%d -> ", temp->key);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    // Initialize hash table
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = NULL;
    }

    // Insert keys into the hash table
    insert(10);
    insert(20);
    insert(30);
    insert(5);
    insert(25);

    // Display the hash table
    printf("\nHash Table:\n");
    display();

    // Search for keys in the hash table
    search(10);
    search(15);

    // Delete a key from the hash table
    delete(20);
    delete(35);

    // Display the hash table after deletion
    printf("\nHash Table after deletion:\n");
    display();

    return 0;
}
