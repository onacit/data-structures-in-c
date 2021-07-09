//
// Created by onacit on 2021-06-05.
//

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include "array_list.h"

struct array_list_env {
    void **array;
    size_t size;
};

size_t array_list_size(struct list *l) {
    assert(l != NULL);
    struct array_list_env *e = (struct array_list_env *) l->environment;
    return e->size;
}

bool array_list_size_zero(struct list *l) {
    assert(l != NULL);
    struct array_list_env *e = (struct array_list_env *) l->environment;
    return e->size == 0;
}


bool array_list_insert(struct list *l, size_t i, void *d) {
    assert(l != NULL);
    struct array_list_env *e = (struct array_list_env *) l->environment;
    if (i > e->size) {
        return false;
    }
    if (e->array == NULL) {
    }
}

int array_list_insert_first_(struct list *l, void *d) {
}

int array_list_insert_last_(struct list *l, void *d) {
}


struct list * array_list() {
    struct array_list_env *e = malloc(sizeof(struct array_list_env));
    if (e == NULL) {
        return NULL;
    }
    e->array = NULL;
    e->size = 0;
    struct list *l = malloc(sizeof(struct list));
    if (l == NULL) {
        free(e);
        return NULL;
    }
    l->environment = e;
    l->size = array_list_size;
    l->size_zero_ = array_list_size_zero;
    return l;
}

