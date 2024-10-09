#include <stdio.h>
#include "arraylist.h"

void run_tests() {
    arraylist *list = alst_create();

    printf("Testing ArrayList operations:\n\n");

    // Test adding to the list
    printf("Testing alst_add:\n");
    alst_add(list, 10);
    alst_add(list, 20);
    alst_add(list, 30);
    printf("Expected: 10 20 30\n");
    for (int i = 0; i < alst_size(list); i++) {
        printf("%d ", alst_get(list, i));
    }
    printf("\n");

    // Test getting data by index
    printf("\nTesting alst_get:\n");
    int value = alst_get(list, 2);
    printf("Expected: 30, Got: %d\n", value);

    // Test inserting at a specific index
    printf("\nTesting alst_insert_index (inserting 15 at index 2):\n");
    alst_insert_index(list, 2, 15);
    printf("Expected: 10 20 15 30\n");
    for (int i = 0; i < alst_size(list); i++) {
        printf("%d ", alst_get(list, i));
    }
    printf("\n");

    // Test setting a value at a specific index
    printf("\nTesting alst_set (setting index 1 to 25):\n");
    alst_set(list, 1, 25);
    printf("Expected: 10 25 15 30\n");
    for (int i = 0; i < alst_size(list); i++) {
        printf("%d ", alst_get(list, i));
    }
    printf("\n");

    // Test removing by index
    printf("\nTesting alst_remove_index (removing index 1):\n");
    alst_remove_index(list, 1);
    printf("Expected: 10 15 30\n");
    for (int i = 0; i < alst_size(list); i++) {
        printf("%d ", alst_get(list, i));
    }
    printf("\n");

    // Test removing the last element
    printf("\nTesting alst_remove (removing last element):\n");
    alst_remove(list);
    printf("Expected: 10 15\n");
    for (int i = 0; i < alst_size(list); i++) {
        printf("%d ", alst_get(list, i));
    }
    printf("\n");

    // Test clearing the list
    printf("\nTesting alst_clear:\n");
    alst_clear(list);
    printf("Expected: (empty line)\n");
    for (int i = 0; i < alst_size(list); i++) {
        printf("%d ", alst_get(list, i));
    }
    printf("\n");
    printf("List size after clearing: %d\n", alst_size(list));  // Expected: 0

    // Free the array list
    alst_free(list);
}

int main() {
    printf("Running ArrayList tests...\n");
    run_tests();
    return 0;
}
