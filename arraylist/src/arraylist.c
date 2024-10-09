#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arraylist.h"

// Initial capacity for the array list
#define INITIAL_CAPACITY 10

// Function to create a new array list
arraylist* alst_create() {
    arraylist *list = (arraylist *)malloc(sizeof(arraylist));
    list->data = (int *)malloc(INITIAL_CAPACITY * sizeof(int));
    list->capacity = INITIAL_CAPACITY;
    list->size = 0;
    return list;
}

// Helper function to resize the array when it reaches capacity
static void alst_resize(arraylist *list, int new_capacity) {
    int *new_data = (int *)malloc(new_capacity * sizeof(int));
    memcpy(new_data, list->data, list->size * sizeof(int));
    free(list->data);
    list->data = new_data;
    list->capacity = new_capacity;
}

// Add a value to the array list
void alst_add(arraylist *list, int value) {
    if (list->size == list->capacity) {
        // Double the capacity
        alst_resize(list, list->capacity * 2);
    }
    list->data[list->size++] = value;
}

// Get a value at a specific index
int alst_get(arraylist *list, int index) {
    if (index < 0 || index >= list->size) {
        fprintf(stderr, "Index out of bounds\n");
        exit(EXIT_FAILURE);
    }
    return list->data[index];
}

// Get the size of the list
int alst_size(arraylist *list) {
    return list->size;
}

// Remove the last element from the list
void alst_remove(arraylist *list) {
    if (list->size > 0) {
        list->size--;
        if (list->size < list->capacity / 2 && list->capacity > INITIAL_CAPACITY) {
            // Shrink the capacity by half
            alst_resize(list, list->capacity / 2);
        }
    }
}

// Remove an element at a specific index
void alst_remove_index(arraylist *list, int index) {
    if (index < 0 || index >= list->size) {
        fprintf(stderr, "Index out of bounds\n");
        exit(EXIT_FAILURE);
    }
    for (int i = index; i < list->size - 1; i++) {
        list->data[i] = list->data[i + 1];
    }
    list->size--;
    if (list->size < list->capacity / 2 && list->capacity > INITIAL_CAPACITY) {
        alst_resize(list, list->capacity / 2);
    }
}

// Insert a value at a specific index
void alst_insert_index(arraylist *list, int index, int value) {
    if (index < 0 || index > list->size) {
        fprintf(stderr, "Index out of bounds\n");
        exit(EXIT_FAILURE);
    }
    if (list->size == list->capacity) {
        alst_resize(list, list->capacity * 2);
    }
    for (int i = list->size; i > index; i--) {
        list->data[i] = list->data[i - 1];
    }
    list->data[index] = value;
    list->size++;
}

// Set a value at a specific index
void alst_set(arraylist *list, int index, int value) {
    if (index < 0 || index >= list->size) {
        fprintf(stderr, "Index out of bounds\n");
        exit(EXIT_FAILURE);
    }
    list->data[index] = value;
}

// Clear the array list
void alst_clear(arraylist *list) {
    list->size = 0;
    alst_resize(list, INITIAL_CAPACITY);
}

// Free the memory used by the array list
void alst_free(arraylist *list) {
    free(list->data);
    free(list);
}
