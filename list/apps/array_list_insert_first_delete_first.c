#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "array_list.h"

#define NDEBUG

int main() {
    struct list *l = array_list();
    if (l == NULL) {
        return EXIT_FAILURE;
    }
    srand(time(NULL));
    int size = 4;
    for (int i = 0; i < size; i++) {
        int *d = malloc(sizeof(int));
        *d = rand();
        list_insert_first(l, d);
        printf("inserted: %d\n", *d);
    }
    printf("size: %zu\n", list_size(l));
    for (int i = 0; i < size; i++) {
        int *d = list_delete_first(l);
        printf("deleted: %d\n", *d);
        free(d);
    }
    printf("size: %zu\n", list_size(l));
    array_list_free(l);
    return EXIT_SUCCESS;
}