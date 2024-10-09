# Data Structure: Generic Dynamic Array List
This is a generic dynamic array list implementation in C. The ArrayList stores elements in an internal array and automatically resizes when capacity is exceeded. The array list supports basic operations such as adding, retrieving, setting, and removing elements, while managing memory efficiently.

## API Overview

### Public Functions
**Constructor and Destructor**

`ArrayList* alst_create(size_t element_size);`
Creates a new ArrayList with the specified element size. This allows the list to store any data type.

`void alst_free(ArrayList* list);`
Frees all memory used by the ArrayList, including the internal array. Make sure to call this function to avoid memory leaks.

**Functions to Manipulate Data**

`void alst_add(ArrayList *list, void *value);`
Adds an element to the end of the list. The element can be of any type, and memory is copied based on the element size specified during list creation.

`void alst_add_all(ArrayList *list, void *values, int length);`
Adds multiple elements to the list. The elements are provided as a pointer, and the function adds them sequentially to the list, increasing the size accordingly.

`void* alst_get(ArrayList* list, int index);`
Returns a pointer to the element at the specified index. The user is responsible for casting the pointer to the correct type.

`int alst_size(ArrayList* list);`
Returns the current number of elements in the list.

`void alst_remove(ArrayList* list);`
Removes the last element from the list.

`void alst_remove_index(ArrayList* list, int index);`
Removes the element at the specified index and shifts subsequent elements to the left.

`void alst_insert_index(ArrayList* list, int index, void* value);`
Inserts an element at the specified index and shifts subsequent elements to the right.

`void alst_set(ArrayList* list, int index, void* value);`
Replaces the element at the specified index with the given value.

`int alst_index_of(ArrayList* list, void* value);`
Returns the index of the first occurrence of the specified value in the list, or -1 if the value is not found. The comparison is done based on the size and content of the value provided.

`void alst_clear(ArrayList* list);`
Clears the list by resetting the size to zero. The internal array capacity is reduced to the initial size.

## Example Usage

### Example with Integers

```c
#include <stdio.h>
#include "arraylist.h"

void print_int(void *data) {
    printf("%d ", *(int*)data);
}

int main() {
    arraylist *list = alst_create(sizeof(int));
    int value;

    value = 10;
    alst_add(list, &value);
    value = 20;
    alst_add(list, &value);
    value = 30;
    alst_add(list, &value);

    printf("List size: %d\n", alst_size(list));  // Output: 3

    printf("List contents: ");
    for (int i = 0; i < alst_size(list); i++) {
        print_int(alst_get(list, i));  // Output: 10 20 30
    }
    printf("\n");

    alst_free(list);
    return 0;
}

```

### Example with Strings

```c
#include <stdio.h>
#include <string.h>
#include "arraylist.h"

void print_string(void *data) {
    printf("%s ", *(char**)data);
}

int main() {
    arraylist *list = alst_create(sizeof(char*));
    char *str1 = "Hello";
    char *str2 = "World";
    char *str3 = "ArrayList";

    alst_add(list, &str1);
    alst_add(list, &str2);
    alst_add(list, &str3);

    printf("List size: %d\n", alst_size(list));  // Output: 3

    printf("List contents: ");
    for (int i = 0; i < alst_size(list); i++) {
        print_string(alst_get(list, i));  // Output: Hello World ArrayList
    }
    printf("\n");

    alst_free(list);
    return 0;
}
```

## Notes
- The `ArrayList` is fully generic, using `void*` to store data of any type. This makes it flexible for storing integers, strings, or any other data structures.
- **Memory Management:** For complex data types (like dynamically allocated strings or structs), ensure that you manage memory properly (e.g., freeing any dynamically allocated memory before removing or clearing the list).
- Ensure that `alst_clear()` and `alst_free()` are called to clean up allocated memory when using dynamically allocated data.
- **Capacity Management:** The `ArrayList` automatically resizes when the internal array is full. The array's capacity doubles when full, and shrinks when the list is less than half full.
- The `ArrayList` is not **thread-safe**. If using this in a multi-threaded environment, you should manage synchronization accordingly.
- **Error Handling:** The implementation assumes that the user provides valid indexes. Attempting to access an invalid index will result in a runtime error (e.g., via `exit(EXIT_FAILURE)`).