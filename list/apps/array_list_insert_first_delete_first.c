#include <assert.h>
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
    int count = 4;
    for (int i = 0; i < count; i++) {
        int *d = malloc(sizeof(int));
        *d = rand();
        list_insert_first(l, d);
        printf("inserted to the first: %d\n", *d);
    }
    size_t size = list_size(l);
    assert(size == count);
    printf("size: %zu\n", size);
    for (int i = 0; i < count; i++) {
        int *d = list_delete_first(l);
        printf("deleted from the first: %d\n", *d);
        free(d);
    }
    size = list_size(l);
    assert(size == 0);
    printf("size: %zu\n", size);
    array_list_free(l);
    return EXIT_SUCCESS;
}