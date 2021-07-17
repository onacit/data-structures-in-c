//
// Created by onacit on 7/9/2021.
//

#include <stdio.h>
#include <stdlib.h>
#include "array_list.h"

int main() {
    struct list *l = array_list();
    if (l == NULL) {
        return EXIT_FAILURE;
    }
    unsigned int half = 4;
    for (int i = 0; i < half; i++) {
        int *d = malloc(sizeof(int));
        *d = rand();
        list_insert_last_(l, d);
        printf("inserted: %d\n", *d);
    }
    for (int i = 0; i < half; i++) {
        int *d = malloc(sizeof(int));
        *d = rand();
        list_insert_first_(l, d);
        printf("inserted: %d\n", *d);
    }
    printf("size: %zu\n", list_size(l));
    for (int i = 0; i < half; i++) {
        int *d = list_delete_last_(l);
        printf("deleted: %d\n", *d);
        free(d);
    }
    for (int i = 0; i < half; i++) {
        int *d = list_delete_first_(l);
        printf("deleted: %d\n", *d);
        free(d);
    }
    printf("size: %zu\n", list_size(l));
    array_list_free(l);
    return EXIT_SUCCESS;
}