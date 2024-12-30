#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10

// A node in the hash table
typedef struct node {
  char* key;
  char* value;
  struct node* next;
} node;

// The hash table
node* table[TABLE_SIZE];

// A hash function that maps keys to table indices
unsigned long hash(char* key) {
  unsigned long hash = 5381;
  int c;
  while ((c = *key++)) {
    hash = ((hash << 5) + hash) + c;
  }
  return hash % TABLE_SIZE;
}

// Insert a key-value pair into the hash table
void insert(char* key, char* value) {
  // Create a new node
  node* n = (node*)malloc(sizeof(node));
  n->key = strdup(key);
  n->value = strdup(value);
  n->next = NULL;

  // Find the index for the key
  unsigned long index = hash(key);

  // Insert the node at the beginning of the linked list
  n->next = table[index];
  table[index] = n;
}

// Look up a value for a given key in the hash table
char* lookup(char* key) {
  // Find the index for the key
  unsigned long index = hash(key);

  // Search the linked list for the key
  node* n = table[index];
  while (n != NULL) {
    if (strcmp(n->key, key) == 0) {
      return n->value;
    }
    n = n->next;
  }

  // Key not found
  return NULL;
}

int main() {
  // Insert some key-value pairs into the hash table
  insert("apple", "red");
  insert("banana", "yellow");
  insert("grape", "purple");

  // Look up the values for some keys
  printf("%s\n", lookup("apple"));   // prints "red"
  printf("%s\n", lookup("banana"));  // prints "yellow"
  printf("%s\n", lookup("grape"));   // prints "purple"
  printf("%s\n", lookup("orange"));  // prints "(null)"

  return 0;
}