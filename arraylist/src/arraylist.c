#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"

// Initial capacity for the array list
#define INITIAL_CAPACITY 10

// Function to create a new array list
ArrayList* alst_create(size_t element_size) {
    ArrayList *list = (ArrayList *)malloc(sizeof(ArrayList));
    list->data = malloc(INITIAL_CAPACITY * element_size);
    list->element_size = element_size;
    list->capacity = INITIAL_CAPACITY;
    list->size = 0;
    return list;
}

// Helper function to resize the array when it reaches capacity
static void alst_resize(ArrayList *list, int new_capacity) {
    void* new_data = malloc(new_capacity * list->element_size);
    memcpy(new_data, list->data, list->size * list->element_size);
    free(list->data);
    list->data = new_data;
    list->capacity = new_capacity;
}

// Add a value to the array list
void alst_add(ArrayList* list, void* value) {
    if (list->size == list->capacity) {
        // Double the capacity
        alst_resize(list, list->capacity * 2);
    }
    memcpy((char*)list->data + list->size * list->element_size, value, list->element_size);
    list->size++;
}

// Add multiple values to the array list
void alst_add_all(ArrayList* list, void* values, int length) {
    if (list->size + length > list->capacity) {
        // Resize the array if necessary
        alst_resize(list, list->size + length);
    }
    memcpy((char*)list->data + list->size * list->element_size, values, length * list->element_size);
    list->size += length;
}

// Get a value at a specific index
void* alst_get(ArrayList* list, int index) {
    if (index < 0 || index >= list->size) {
        fprintf(stderr, "Index out of bounds\n");
        exit(EXIT_FAILURE);
    }
    return (char*)list->data + index * list->element_size;
}

// Get the size of the list
int alst_size(ArrayList* list) {
    return list->size;
}

// Remove the last element from the list
void alst_remove(ArrayList* list) {
    if (list->size > 0) {
        list->size--;
        if (list->size < list->capacity / 2 && list->capacity > INITIAL_CAPACITY) {
            // Shrink the capacity by half
            alst_resize(list, list->capacity / 2);
        }
    }
}

// Remove an element at a specific index
void alst_remove_index(ArrayList* list, int index) {
    if (index < 0 || index >= list->size) {
        fprintf(stderr, "Index out of bounds\n");
        exit(EXIT_FAILURE);
    }
    for (int i = index; i < list->size - 1; i++) {
        memcpy((char*)list->data + i * list->element_size, (char*)list->data + (i + 1) * list->element_size, list->element_size);
    }
    list->size--;
    if (list->size < list->capacity / 2 && list->capacity > INITIAL_CAPACITY) {
        alst_resize(list, list->capacity / 2);
    }
}

// Insert a value at a specific index
void alst_insert_index(ArrayList* list, int index, void* value) {
    if (index < 0 || index > list->size) {
        fprintf(stderr, "Index out of bounds\n");
        exit(EXIT_FAILURE);
    }
    if (list->size == list->capacity) {
        alst_resize(list, list->capacity * 2);
    }
    for (int i = list->size; i > index; i--) {
        memcpy((char*)list->data + i * list->element_size, (char*)list->data + (i - 1) * list->element_size, list->element_size);
    }
    memcpy((char*)list->data + index * list->element_size, value, list->element_size);
    list->size++;
}

// Set a value at a specific index
void alst_set(ArrayList* list, int index, void* value) {
    if (index < 0 || index >= list->size) {
        fprintf(stderr, "Index out of bounds\n");
        exit(EXIT_FAILURE);
    }
    memcpy((char*)list->data + index * list->element_size, value, list->element_size);
}

// Get the index of a value in the list
int alst_index_of(ArrayList* list, void* value) {
    for (int i = 0; i < list->size; i++) {
        if (memcmp((char*)list->data + i * list->element_size, value, list->element_size) == 0) {
            return i;
        }
    }
    return -1;
}

// Clear the array list
void alst_clear(ArrayList *list) {
    list->size = 0;
    alst_resize(list, INITIAL_CAPACITY);
}

// Free the memory used by the array list
void alst_free(ArrayList *list) {
    free(list->data);
    free(list);
}
