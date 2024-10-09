#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

// Create a new node with the given data
list_node* create_node(int data) {
    list_node* new_node = (list_node*)malloc(sizeof(list_node));
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}

// Add a node to the end of the list
void add_last(linked_list* list, int data) {
    list_node* new_node = create_node(data);
    if (list->tail == NULL) {
        list->head = list->tail = new_node;
    } else {
        list->tail->next = new_node;
        new_node->prev = list->tail;
        list->tail = new_node;
    }
    list->length++;
}

// Add a node to the beginning of the list
void add_first(linked_list* list, int data) {
    list_node* new_node = create_node(data);
    if (list->head == NULL) {
        list->head = list->tail = new_node;
    } else {
        new_node->next = list->head;
        list->head->prev = new_node;
        list->head = new_node;
    }
    list->length++;
}

// Get the data at a specific index
int get(linked_list* list, int index) {
    list_node* node = node_at(list, index);
    return node ? node->data : -1;
}

// Get the index of the node with the given data
int index_of(linked_list* list, int data) {
    list_node* current = list->head;
    int index = 0;
    while (current != NULL) {
        if (current->data == data) {
            return index;
        }
        current = current->next;
        index++;
    }
    return -1;
}

// Insert a node after a given index
void insert_after(linked_list* list, int index, int data) {
    list_node* current_node = node_at(list, index);
    if (current_node == NULL) return;

    list_node* new_node = create_node(data);
    new_node->next = current_node->next;
    new_node->prev = current_node;

    if (current_node->next) {
        current_node->next->prev = new_node;
    } else {
        list->tail = new_node;
    }

    current_node->next = new_node;
    list->length++;
}

// Insert a node before a given index
void insert_before(linked_list* list, int index, int data) {
    list_node* current_node = node_at(list, index);
    if (current_node == NULL) return;

    list_node* new_node = create_node(data);
    new_node->next = current_node;
    new_node->prev = current_node->prev;

    if (current_node->prev) {
        current_node->prev->next = new_node;
    } else {
        list->head = new_node;
    }

    current_node->prev = new_node;
    list->length++;
}

// Get the first element's data
int first(linked_list* list) {
    return list->head ? list->head->data : -1;
}

// Get the last element's data
int last(linked_list* list) {
    return list->tail ? list->tail->data : -1;
}

// Remove a node by its data
void remove_data(linked_list* list, int data) {
    int index = index_of(list, data);
    if (index != -1) {
        remove_index(list, index);
    }
}

// Remove a node by its index
void remove_index(linked_list* list, int index) {
    list_node* node_to_remove = node_at(list, index);
    if (node_to_remove != NULL) {
        remove_node(list, node_to_remove);
    }
}

// Remove the first node
int remove_first(linked_list* list) {
    if (list->head == NULL) return -1;

    int removed_data = list->head->data;
    remove_node(list, list->head);
    return removed_data;
}

// Remove the last node
int remove_last(linked_list* list) {
    if (list->tail == NULL) return -1;

    int removed_data = list->tail->data;
    remove_node(list, list->tail);
    return removed_data;
}

// Add a new node to the end of the list
void add_node_last(linked_list* list, list_node* new_node) {
    if (list->tail == NULL) {
        list->head = list->tail = new_node;
    } else {
        list->tail->next = new_node;
        new_node->prev = list->tail;
        list->tail = new_node;
    }
    list->length++;
}

// Add a new node to the beginning of the list
void add_node_first(linked_list* list, list_node* new_node) {
    if (list->head == NULL) {
        list->head = list->tail = new_node;
    } else {
        new_node->next = list->head;
        list->head->prev = new_node;
        list->head = new_node;
    }
    list->length++;
}

// Insert a node after an existing node
void insert_after_node(linked_list* list, list_node* new_node, list_node* existing_node) {
    new_node->next = existing_node->next;
    new_node->prev = existing_node;

    if (existing_node->next) {
        existing_node->next->prev = new_node;
    } else {
        list->tail = new_node;
    }

    existing_node->next = new_node;
    list->length++;
}

// Insert a node before an existing node
void insert_before_node(linked_list* list, list_node* new_node, list_node* existing_node) {
    new_node->next = existing_node;
    new_node->prev = existing_node->prev;

    if (existing_node->prev) {
        existing_node->prev->next = new_node;
    } else {
        list->head = new_node;
    }

    existing_node->prev = new_node;
    list->length++;
}

// Remove a specific node from the list
void remove_node(linked_list* list, list_node* node) {
    if (node->prev != NULL) {
        node->prev->next = node->next;
    } else {
        list->head = node->next;
    }

    if (node->next != NULL) {
        node->next->prev = node->prev;
    } else {
        list->tail = node->prev;
    }

    free(node);
    list->length--;
}

// Clear the list of all nodes
void clear(linked_list* list) {
    list_node* current = list->head;
    while (current != NULL) {
        list_node* next = current->next;
        free(current);
        current = next;
    }
    list->head = list->tail = NULL;
    list->length = 0;
}

// Get the size of the list
int size(linked_list* list) {
    return list->length;
}

// Dump the list to the console
void dump_list(linked_list* list) {
    list_node* current = list->head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Get the node at a specific index
list_node* node_at(linked_list* list, int index) {
    if (index < 0 || index >= list->length) return NULL;

    list_node* current;
    if (index < list->length / 2) {
        current = list->head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
    } else {
        current = list->tail;
        for (int i = list->length - 1; i > index; i--) {
            current = current->prev;
        }
    }
    return current;
}

// Swap the positions of two nodes
void swap_nodes(list_node* node_a, list_node* node_b) {
    int temp = node_a->data;
    node_a->data = node_b->data;
    node_b->data = temp;
}
