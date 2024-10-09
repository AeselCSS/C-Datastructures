#include <stdio.h>
#include <string.h>
#include "arraylist.h"

void print_int(void *data) {
    printf("%d ", *(int*)data);
}

void print_string(void *data) {
    printf("%s ", (char*)data);
}

void run_int_tests() {
    printf("Testing ArrayList with integers:\n");
    ArrayList *list = alst_create(sizeof(int));
    int value;

    // Test adding to the list
    value = 10;
    alst_add(list, &value);
    value = 20;
    alst_add(list, &value);
    value = 30;
    alst_add(list, &value);

    printf("Expected: 10 20 30\n");
    for (int i = 0; i < alst_size(list); i++) {
        print_int(alst_get(list, i));
    }
    printf("\n");

    // Test clearing the list
    alst_clear(list);
    printf("List size after clearing: %d\n", alst_size(list));  // Expected: 0

    alst_free(list);
}

void run_string_tests() {
    printf("Testing ArrayList with strings:\n");
    ArrayList *list = alst_create(sizeof(char*));
    char *str1 = "Hello";
    char *str2 = "World";
    char *str3 = "ArrayList";

    // Test adding strings to the list
    alst_add(list, &str1);
    alst_add(list, &str2);
    alst_add(list, &str3);

    printf("Expected: Hello World ArrayList\n");
    for (int i = 0; i < alst_size(list); i++) {
        print_string(*(char**)alst_get(list, i));
    }
    printf("\n");

    alst_free(list);
}

int main() {
    run_int_tests();
    run_string_tests();
    return 0;
}
