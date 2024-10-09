#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include <stdbool.h>
#include <stddef.h>

typedef struct {
    void* data;           // Generic data pointer
    size_t element_size;  // Size of each element
    int capacity;         // Current capacity of the array
    int size;             // Number of elements in the array
} ArrayList;

// Constructor to create a new array list
ArrayList* alst_create(size_t element_size);

// Public functions
void alst_add(ArrayList* list, void* value); // Add a value to the array list
void alst_add_all(ArrayList* list, void* values, int length); // Add multiple values to the array list
void* alst_get(ArrayList* list, int index); // Get a value at a specific index
int alst_size(ArrayList* list); // Get the size of the list
void alst_remove(ArrayList* list); // Remove the last element from the list
void alst_remove_index(ArrayList* list, int index); // Remove an element at a specific index
void alst_insert_index(ArrayList* list, int index, void* value); // Insert a value at a specific index
void alst_set(ArrayList* list, int index, void* value); // Set a value at a specific index
int alst_index_of(ArrayList* list, void* value); // Get the index of a value in the list
void alst_clear(ArrayList* list); // Clear all elements from the list
void alst_free(ArrayList* list); // Free the memory allocated for the list

#endif // ARRAYLIST_H
