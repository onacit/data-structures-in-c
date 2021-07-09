//
// Created by onacit on 7/9/2021.
//

#include <stdio.h>
#include <stdlib.h>

struct t {
    void **array;
    size_t capacity;
    size_t size;
};

int main() {
    struct t *t = malloc(sizeof(struct t));
    t->array = malloc(sizeof(void *) * 2);
    printf("%d\n", sizeof(t->array));
    printf("%d\n", sizeof(void *));
    printf("%d\n", sizeof(t->array) / sizeof(void *));
}