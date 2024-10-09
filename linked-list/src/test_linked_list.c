#include <stdio.h>
#include <string.h>
#include "linked_list.h"

// Helper function to print integers stored in the list
void print_int(void* data) {
    printf("%d", *(int*)data);
}

// Helper function to print strings stored in the list
void print_string(void* data) {
    printf("%s", (char*)data);
}

void run_tests() {
    // Test with integers
    printf("=== Running LinkedList tests with integers ===\n\n");
    LinkedList* int_list = llst_create();
    int int_value;
    int int_result;

    // Test 1: Adding integers to the list
    printf("Test 1: Adding integers to the list\n");
    int_value = 10;
    llst_add_last(int_list, &int_value, sizeof(int));
    int_value = 20;
    llst_add_last(int_list, &int_value, sizeof(int));
    int_value = 30;
    llst_add_last(int_list, &int_value, sizeof(int));
    printf("Expected list: 10 -> 20 -> 30\n");
    printf("Current list: ");
    llst_dump_list(int_list, print_int);
    printf("\n\n");

    // Test 2: Retrieving integers by index
    printf("Test 2: Retrieving integers by index\n");
    int_result = *(int*)llst_get(int_list, 1);
    printf("Expected: 20, Got: %d\n", int_result);
    printf("\n");

    // Test 3: Removing integers by index
    printf("Test 3: Removing integer at index 1 (value 20)\n");
    llst_remove_index(int_list, 1);
    printf("Expected list: 10 -> 30\n");
    printf("Current list: ");
    llst_dump_list(int_list, print_int);
    printf("\n\n");

    // Clean up the integer list
    llst_clear(int_list);
    llst_free(int_list);

    // Test with strings
    printf("=== Running LinkedList tests with strings ===\n\n");
    LinkedList* string_list = llst_create();
    char* str_value;
    char* str_result;

    // Test 4: Adding strings to the list
    printf("Test 4: Adding strings to the list\n");
    str_value = "Hello";
    llst_add_last(string_list, str_value, strlen(str_value) + 1);
    str_value = "World";
    llst_add_last(string_list, str_value, strlen(str_value) + 1);
    str_value = "LinkedList";
    llst_add_last(string_list, str_value, strlen(str_value) + 1);
    printf("Expected list: Hello -> World -> LinkedList\n");
    printf("Current list: ");
    llst_dump_list(string_list, print_string);
    printf("\n\n");

    // Test 5: Retrieving strings by index
    printf("Test 5: Retrieving string by index\n");
    str_result = (char*)llst_get(string_list, 2);
    printf("Expected: LinkedList, Got: %s\n", str_result);
    printf("\n");

    // Test 6: Removing strings by index
    printf("Test 6: Removing string at index 1 (value World)\n");
    llst_remove_index(string_list, 1);
    printf("Expected list: Hello -> LinkedList\n");
    printf("Current list: ");
    llst_dump_list(string_list, print_string);
    printf("\n\n");

    // Test 7: Inserting a string at a specific index
    printf("Test 7: Inserting string 'Test' at index 1\n");
    str_value = "Test";
    llst_insert_after(string_list, 0, str_value, strlen(str_value) + 1);
    printf("Expected list: Hello -> Test -> LinkedList\n");
    printf("Current list: ");
    llst_dump_list(string_list, print_string);
    printf("\n\n");

    // Clean up the string list
    llst_clear(string_list);
    llst_free(string_list);
}

int main() {
    run_tests();
    return 0;
}
