#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include <stdbool.h>

typedef struct {
    int *data;
    int capacity;
    int size;
} arraylist;

// Constructor to create a new array list
arraylist* alst_create();

// Public functions
void alst_add(arraylist *list, int value);
int alst_get(arraylist *list, int index);
int alst_size(arraylist *list);
void alst_remove(arraylist *list);
void alst_remove_index(arraylist *list, int index);
void alst_insert_index(arraylist *list, int index, int value);
void alst_set(arraylist *list, int index, int value);
void alst_clear(arraylist *list);

// Utility functions
void alst_free(arraylist *list);

#endif // ARRAYLIST_H
