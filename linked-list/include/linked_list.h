#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdbool.h>

typedef struct list_node {
    int data;
    struct list_node* next;
    struct list_node* prev;
} list_node;

typedef struct linked_list {
    list_node* head;
    list_node* tail;
    int length;
} linked_list;

// Functions to manipulate data
void add_last(linked_list* list, int data);
void add_first(linked_list* list, int data);
int get(linked_list* list, int index);
int index_of(linked_list* list, int data);
void insert_after(linked_list* list, int index, int data);
void insert_before(linked_list* list, int index, int data);
int first(linked_list* list);
int last(linked_list* list);
void remove_data(linked_list* list, int data);
void remove_index(linked_list* list, int index);
int remove_first(linked_list* list);
int remove_last(linked_list* list);

// Functions to manipulate nodes
void add_node_last(linked_list* list, list_node* new_node);
void add_node_first(linked_list* list, list_node* new_node);
void insert_after_node(linked_list* list, list_node* new_node, list_node* existing_node);
void insert_before_node(linked_list* list, list_node* new_node, list_node* existing_node);
void remove_node(linked_list* list, list_node* node);

// Utility functions
void clear(linked_list* list);
int size(linked_list* list);
void dump_list(linked_list* list);
list_node* node_at(linked_list* list, int index);
void swap_nodes(list_node* node_a, list_node* node_b);

#endif // LINKED_LIST_H