#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

// Constructor for the linked list
LinkedList* llst_create() {
    LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));
    if (list == NULL) {
        fprintf(stderr, "ERROR: Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}

// Destructor for the linked list
void llst_free(LinkedList* list) {
    Node* current = list->head;
    while (current != NULL) {
        Node* next = current->next;
        llst_free_node(current);
        current = next;
    }
    free(list);
}

// Constructor for a node
Node* llst_create_node(void* value, size_t size) {
    Node* node = (Node*)malloc(sizeof(Node));
    if (node == NULL) {
        fprintf(stderr, "ERROR: Memory allocation failed while creating node\n");
        exit(EXIT_FAILURE);
    }
    node->data.data = malloc(size);
    if (node->data.data == NULL) {
        fprintf(stderr, "ERROR: Memory allocation failed while creating node data\n");
        exit(EXIT_FAILURE);
    }
    node->data.size = size;
    node->next = NULL;
    node->prev = NULL;
    memcpy(node->data.data, value, size);
    return node;
}

// Destructor for a node
void llst_free_node(Node* node) {
    free(node->data.data);
    free(node);
}

// === Functions to manipulate data ===
// Add data to the end of the list
void llst_add_last(LinkedList* list, void* value, size_t size) {
    Node* new_node = llst_create_node(value, size);
    llst_add_node_last(list, new_node);
}

// Add data to the beginning of the list
void llst_add_first(LinkedList* list, void* value, size_t size) {
    Node* new_node = llst_create_node(value, size);
    llst_add_node_first(list, new_node);
}

// Get the value at the specified index
void* llst_get(LinkedList* list, size_t index) {
    if (index >= list->size) {
        fprintf(stderr, "ERROR: Index out of bounds\n");
        exit(EXIT_FAILURE);
    }
    Node* current = list->head;
    for (size_t i = 0; i < index; i++) {
        current = current->next;
    }
    return current->data.data;
}

// Get the index of the specified value
int llst_index_of(LinkedList* list, void* value, size_t size) {
    Node* current = list->head;
    int index = 0;
    while (current != NULL) {
        if (current->data.size == size && memcmp(current->data.data, value, size) == 0) {
            return index;
        }
        current = current->next;
        index++;
    }
    return -1;
}

// Insert a value after the given index
void llst_insert_after(LinkedList* list, size_t index, void* value, size_t size) {
    if (index >= list->size) {
        fprintf(stderr, "ERROR: Index out of bounds\n");
        exit(EXIT_FAILURE);
    }
    Node* current = list->head;
    for (size_t i = 0; i < index; i++) {
        current = current->next;
    }
    Node* new_node = llst_create_node(value, size);
    llst_insert_after_node(list, current, new_node);
}

// Insert a value before the given index
void llst_insert_before(LinkedList* list, size_t index, void* value, size_t size) {
    if (index >= list->size) {
        fprintf(stderr, "ERROR: Index out of bounds\n");
        exit(EXIT_FAILURE);
    }
    Node* current = list->head;
    for (size_t i = 0; i < index; i++) {
        current = current->next;
    }
    Node* new_node = llst_create_node(value, size);
    llst_insert_before_node(list, current, new_node);
}

// Get the value of the first element in the list
void* llst_first(LinkedList* list) {
    if (list->head == NULL) {
        fprintf(stderr, "ERROR: List is empty\n");
        exit(EXIT_FAILURE);
    }
    return list->head->data.data;
}

// Get the value of the last element in the list
void* llst_last(LinkedList* list) {
    if (list->tail == NULL) {
        fprintf(stderr, "ERROR: List is empty\n");
        exit(EXIT_FAILURE);
    }
    return list->tail->data.data;
}

// Remove an element by value
void llst_remove_data(LinkedList* list, void* value, size_t size) {
    int index = llst_index_of(list, value, size);
    if (index != -1) {
        llst_remove_index(list, index);
    }
}

// Remove an element by index
void llst_remove_index(LinkedList* list, size_t index) {
    if (index >= list->size) {
        fprintf(stderr, "ERROR: Index out of bounds\n");
        exit(EXIT_FAILURE);
    }
    Node* current = list->head;
    for (size_t i = 0; i < index; i++) {
        current = current->next;
    }
    llst_remove_node(list, current);
}

// Remove and return the first element
void* llst_remove_first(LinkedList* list) {
    if (list->head == NULL) {
        fprintf(stderr, "ERROR: List is empty\n");
        exit(EXIT_FAILURE);
    }
    Node* first = list->head;
    void* value = first->data.data;
    llst_remove_node(list, first);
    return value;
}

// Remove and return the last element
void* llst_remove_last(LinkedList* list) {
    if (list->tail == NULL) {
        fprintf(stderr, "ERROR: List is empty\n");
        exit(EXIT_FAILURE);
    }
    Node* last = list->tail;
    void* value = last->data.data;
    llst_remove_node(list, last);
    return value;
}

// === Functions to manipulate nodes ===
// Add a node to the end of the list
void llst_add_node_last(LinkedList* list, Node* new_node) {
    if (list->tail == NULL) {
        list->head = new_node;
        list->tail = new_node;
    } else {
        list->tail->next = new_node;
        new_node->prev = list->tail;
        list->tail = new_node;
    }
    list->size++;
}

// Add a node to the beginning of the list
void llst_add_node_first(LinkedList* list, Node* new_node) {
    if (list->head == NULL) {
        list->head = new_node;
        list->tail = new_node;
    } else {
        list->head->prev = new_node;
        new_node->next = list->head;
        list->head = new_node;
    }
    list->size++;
}

// Insert a new node after the given node
void llst_insert_after_node(LinkedList* list, Node* existing_node, Node* new_node) {
    if (existing_node == list->tail) {
        llst_add_node_last(list, new_node);
    } else {
        new_node->next = existing_node->next;
        new_node->prev = existing_node;
        existing_node->next->prev = new_node;
        existing_node->next = new_node;
        list->size++;
    }
}

// Insert a new node before the given node
void llst_insert_before_node(LinkedList* list, Node* existing_node, Node* new_node) {
    if (existing_node == list->head) {
        llst_add_node_first(list, new_node);
    } else {
        new_node->next = existing_node;
        new_node->prev = existing_node->prev;
        existing_node->prev->next = new_node;
        existing_node->prev = new_node;
        list->size++;
    }
}

// Remove a specific node from the list
void llst_remove_node(LinkedList* list, Node* node) {
    if (node == list->head) {
        list->head = node->next;
    }
    if (node == list->tail) {
        list->tail = node->prev;
    }
    if (node->prev != NULL) {
        node->prev->next = node->next;
    }
    if (node->next != NULL) {
        node->next->prev = node->prev;
    }
    llst_free_node(node);
    list->size--;
}

// Get the node at the specified index
Node* llst_node_at(LinkedList* list, size_t index) {
    if (index >= list->size) {
        fprintf(stderr, "ERROR: Index out of bounds\n");
        exit(EXIT_FAILURE);
    }
    Node* current = list->head;
    for (size_t i = 0; i < index; i++) {
        current = current->next;
    }
    return current;
}

// Swap the data between two nodes
void llst_swap_nodes(Node* node_a, Node* node_b) {
    Data temp = node_a->data;
    node_a->data = node_b->data;
    node_b->data = temp;
}

// Clear all the elements from the list
void llst_clear(LinkedList* list) {
    Node* current = list->head;
    while (current != NULL) {
        Node* next = current->next;
        llst_free_node(current);
        current = next;
    }
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}

// Get the size (number of elements) of the list
size_t llst_size(LinkedList* list) {
    return list->size;
}

// Dump the contents of the list using a custom print function
void llst_dump_list(LinkedList* list, void (*print_fn)(void*)) {
    Node* current = list->head;
    while (current != NULL) {
        print_fn(current->data.data);
        current = current->next;
    }
}