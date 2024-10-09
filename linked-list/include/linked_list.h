#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdbool.h>
#include <stddef.h>  // for size_t

typedef struct Data
{
    void* data;  // Void pointer to store any type of data
    size_t size; // Size of the data (used for copying and managing memory)
} Data;

typedef struct Node
{
    Data data;         // Data contained in the node
    struct Node* next; // Pointer to the next node in the list
    struct Node* prev; // Pointer to the previous node in the list
} Node;

typedef struct LinkedList
{
    Node* head;   // Pointer to the first node
    Node* tail;   // Pointer to the last node
    size_t size;  // Number of elements in the list
} LinkedList;

// Constructor and destructor for the linked list
LinkedList* llst_create();            // Create a new linked list
void llst_free(LinkedList* list);     // Free the memory of the linked list and its nodes

// Constructor and destructor for a node
Node* llst_create_node(void* value, size_t size);  // Create a new node with the given value and size
void llst_free_node(Node* node);                   // Free the memory of a node

// Functions to manipulate data
void llst_add_last(LinkedList* list, void* value, size_t size);   // Add an element to the end of the list
void llst_add_first(LinkedList* list, void* value, size_t size);  // Add an element to the beginning of the list
void* llst_get(LinkedList* list, size_t index);                   // Get the value at the specified index (returns void pointer)
int llst_index_of(LinkedList* list, void* value, size_t size);    // Get the index of the specified value
void llst_insert_after(LinkedList* list, size_t index, void* value, size_t size);  // Insert a value after the given index
void llst_insert_before(LinkedList* list, size_t index, void* value, size_t size); // Insert a value before the given index
void* llst_first(LinkedList* list);  // Get the value of the first element in the list (returns void pointer)
void* llst_last(LinkedList* list);   // Get the value of the last element in the list (returns void pointer)
void llst_remove_data(LinkedList* list, void* value, size_t size);  // Remove an element by value
void llst_remove_index(LinkedList* list, size_t index);              // Remove an element by index
void* llst_remove_first(LinkedList* list);  // Remove and return the first element (returns void pointer)
void* llst_remove_last(LinkedList* list);   // Remove and return the last element (returns void pointer)

// Functions to manipulate nodes
void llst_add_node_last(LinkedList* list, Node* new_node);  // Add a node to the end of the list
void llst_add_node_first(LinkedList* list, Node* new_node); // Add a node to the beginning of the list
void llst_insert_after_node(LinkedList* list, Node* existing_node, Node* new_node);  // Insert a new node after the given node
void llst_insert_before_node(LinkedList* list, Node* existing_node, Node* new_node); // Insert a new node before the given node
void llst_remove_node(LinkedList* list, Node* node);  // Remove a specific node from the list
Node* llst_node_at(LinkedList* list, size_t index);   // Get the node at the specified index
void llst_swap_nodes(Node* node_a, Node* node_b);     // Swap the data between two nodes

// Utility functions
void llst_clear(LinkedList* list);        // Clear all the elements from the list
size_t llst_size(LinkedList* list);       // Get the size (number of elements) of the list
void llst_dump_list(LinkedList* list, void (*print_fn)(void*));  // Dump the contents of the list using a custom print function

#endif // LINKED_LIST_H
