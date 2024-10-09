#include <stdio.h>
#include "linked_list.h"

void run_tests() {
    linked_list list;
    list.head = list.tail = NULL;
    list.length = 0;

    printf("Testing linked list operations:\n\n");

    // Test adding to the end
    printf("Testing add_last:\n");
    add_last(&list, 10);
    add_last(&list, 20);
    add_last(&list, 30);
    printf("Expected: 10 20 30\n");
    dump_list(&list);  // Expected: 10 20 30

    // Test adding to the beginning
    printf("\nTesting add_first:\n");
    add_first(&list, 5);
    add_first(&list, 1);
    printf("Expected: 1 5 10 20 30\n");
    dump_list(&list);  // Expected: 1 5 10 20 30

    // Test getting data by index
    printf("\nTesting get:\n");
    int value = get(&list, 2);
    printf("Expected: 10, Got: %d\n", value);

    // Test inserting after a specific index
    printf("\nTesting insert_after:\n");
    insert_after(&list, 2, 15);
    printf("Expected: 1 5 10 15 20 30\n");
    dump_list(&list);  // Expected: 1 5 10 15 20 30

    // Test inserting before a specific index
    printf("\nTesting insert_before:\n");
    insert_before(&list, 4, 17);
    printf("Expected: 1 5 10 15 17 20 30\n");
    dump_list(&list);  // Expected: 1 5 10 15 17 20 30

    // Test removing by index
    printf("\nTesting remove_index (removing index 4):\n");
    remove_index(&list, 4);
    printf("Expected: 1 5 10 15 20 30\n");
    dump_list(&list);  // Expected: 1 5 10 15 20 30

    // Test removing by data
    printf("\nTesting remove_data (removing 5):\n");
    remove_data(&list, 5);
    dump_list(&list);  // Expected: 1 10 15 20 30

    // Test removing the first node
    printf("\nTesting remove_first:\n");
    int removed_first = remove_first(&list);
    printf("Removed first: %d\n", removed_first);  // Expected: 1
    printf("Expected: 10 15 20 30\n");
    dump_list(&list);  // Expected: 10 15 20 30

    // Test removing the last node
    printf("\nTesting remove_last:\n");
    int removed_last = remove_last(&list);
    printf("Removed last: %d\n", removed_last);  // Expected: 30
    printf("Expected: 10 15 20\n");
    dump_list(&list);  // Expected: 10 15 20

    // Test clearing the list
    printf("\nTesting clear:\n");
    clear(&list);
    printf("Expected: (empty line)\n");
    dump_list(&list);  // Expected: (empty line)
    printf("List size after clearing: %d\n", size(&list));  // Expected: 0
}

int main() {
    printf("Running linked list tests...\n");
    run_tests();
    return 0;
}
