# Data Structure: Generic Doubly Linked List

This is a generic doubly linked list implementation in C that can store any data type using `void*`. Each node contains pointers to both the next and previous elements, allowing for efficient insertions and deletions at both ends of the list.

## API Overview

### Public Functions

**Constructor and Destructor for the Linked List**

`LinkedList* llst_create();`  
Creates a new, empty linked list.

`void llst_free(LinkedList* list);`  
Frees all nodes and the linked list itself. Make sure to call this function to avoid memory leaks.

**Constructor and Destructor for a Node**

`Node* llst_create_node(void* value, size_t size);`  
Creates a new node with the given value and size.

`void llst_free_node(Node* node);`  
Frees the memory of a node. Make sure to call this function to avoid memory leaks.

**Functions to Manipulate Data**

`void llst_add_last(LinkedList* list, void* value, size_t size);`  
Adds an element to the end of the list. The element can be of any type, and `size` should specify the size of the data being added.

`void llst_add_first(LinkedList* list, void* value, size_t size);`  
Adds an element to the beginning of the list. The element can be of any type, and `size` should specify the size of the data being added.

`void* llst_get(LinkedList* list, size_t index);`  
Returns a pointer to the element at the specified index. The user is responsible for casting the pointer to the correct type.

`int llst_index_of(LinkedList* list, void* value, size_t size);`  
Returns the index of the first occurrence of the given data, or -1 if not found. The `size` argument specifies the size of the data for comparison.

`void llst_insert_after(LinkedList* list, size_t index, void* value, size_t size);`  
Inserts an element after the specified index.

`void llst_insert_before(LinkedList* list, size_t index, void* value, size_t size);`  
Inserts an element before the specified index.

`void* llst_first(LinkedList* list);`  
Returns a pointer to the first element in the list.

`void* llst_last(LinkedList* list);`  
Returns a pointer to the last element in the list.

`void llst_remove_data(LinkedList* list, void* value, size_t size);`  
Removes the first occurrence of the specified data.

`void llst_remove_index(LinkedList* list, size_t index);`  
Removes the element at the specified index.

`void* llst_remove_first(LinkedList* list);`  
Removes and returns the first element.

`void* llst_remove_last(LinkedList* list);`  
Removes and returns the last element.

**Functions to Manipulate Nodes**

`void llst_add_node_last(LinkedList* list, Node* new_node);`  
Adds a node to the end of the list.

`void llst_add_node_first(LinkedList* list, Node* new_node);`  
Adds a node to the beginning of the list.

`void llst_insert_after_node(LinkedList* list, Node* existing_node, Node* new_node);`  
Inserts a new node after the given node.

`void llst_insert_before_node(LinkedList* list, Node* existing_node, Node* new_node);`  
Inserts a new node before the given node.

`void llst_remove_node(LinkedList* list, Node* node);`  
Removes a specific node from the list.

`Node* llst_node_at(LinkedList* list, size_t index);`  
Gets the node at the specified index.

`void llst_swap_nodes(Node* node_a, Node* node_b);`  
Swaps the data between two nodes.

**Utility Functions**

`void llst_clear(LinkedList* list);`  
Clears the list and frees all nodes.

`size_t llst_size(LinkedList* list);`  
Returns the number of elements in the list.

`void llst_dump_list(LinkedList* list, void (*print_fn)(void*));`  
Prints the list contents using a custom print function provided by the user. The print function must handle the specific type of data stored in the list.

## Example Usage

### Example with Integers
```c
#include <stdio.h>
#include "linked_list.h"

void print_int(void* data) {
    printf("%d ", *(int*)data);
}

int main() {
    LinkedList* list = llst_create();
    int value;

    value = 10;
    llst_add_last(list, &value, sizeof(int));
    value = 20;
    llst_add_last(list, &value, sizeof(int));
    value = 30;
    llst_add_last(list, &value, sizeof(int));

    printf("List size: %zu\n", llst_size(list));  // Output: 3
    int* val = (int*)llst_get(list, 1);
    printf("Element at index 1: %d\n", *val);  // Output: 20

    printf("List contents: ");
    llst_dump_list(list, print_int);  // Output: 10 20 30

    llst_clear(list);
    llst_free(list);
    return 0;
}
```
### Example with Strings
```c
#include <stdio.h>
#include <string.h>
#include "linked_list.h"

void print_string(void* data) {
    printf("%s ", (char*)data);
}

int main() {
    LinkedList* list = llst_create();

    char* str1 = "Hello";
    char* str2 = "World";
    char* str3 = "LinkedList";

    llst_add_last(list, str1, strlen(str1) + 1);
    llst_add_last(list, str2, strlen(str2) + 1);
    llst_add_last(list, str3, strlen(str3) + 1);

    printf("List size: %zu\n", llst_size(list));  // Output: 3
    printf("List contents: ");
    llst_dump_list(list, print_string);  // Output: Hello World LinkedList

    llst_clear(list);
    llst_free(list);
    return 0;
}
```

## Notes
- The linked list is fully generic, using void* to store data of any type. This makes it flexible for storing integers, strings, or any other data structures.
- Memory Management: For complex data types (like dynamically allocated strings or structs), you need to ensure proper memory management to avoid memory leaks.
- Ensure that llst_clear() and llst_free() are called to clean up allocated memory when using dynamically allocated data.
- The linked list is not thread-safe. In multi-threaded environments, you should ensure synchronization when accessing the list.

