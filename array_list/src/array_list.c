//
// Created by onacit on 2021-06-05.
//

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include "array_list.h"

struct array_list_env {
    void **array;
    size_t capacity;
    size_t size;
};

// -----------------------------------------------------------------------------

size_t array_list_size(struct list *l) {
    assert(l != NULL);
    struct array_list_env *e = (struct array_list_env *) l->env;
    return e->size;
}

bool array_list_size_zero_(struct list *l) {
    assert(l != NULL);
    struct array_list_env *e = (struct array_list_env *) l->env;
    return e->size == 0;
}


void array_list_insert(struct list *l, size_t i, void *d) {
    assert(l != NULL);
    assert(i <= array_list_size(l));
    struct array_list_env *e = (struct array_list_env *) l->env;
    if (e->size == e->capacity) {
        e->capacity = e->capacity == 0 ? 1 : e->capacity << 2;
        void *r = realloc(e->array, sizeof(void *) * (e->capacity));
        assert(r != NULL);
    }
    for (size_t j = e->size; j > i; j--) {
        e->array[j] = e->array[j - 1];
    }
    e->array[i] = d;
    e->size++;
}

void array_list_insert_first_(struct list *l, void *d) {
    array_list_insert(l, 0, d);
}

void array_list_insert_last_(struct list *l, void *d) {
    assert(l != NULL);
    struct array_list_env *e = (struct array_list_env *) l->env;
    array_list_insert(l, e->size, d);
}


void * array_list_delete(struct list *l, size_t i) {
    assert(l != NULL);
    assert(i < array_list_size(l));
    struct array_list_env *e = (struct array_list_env *) l->env;
    void *data = e->array[i];
    for (size_t j = i; j < e->size; j++) {
        e->array[j] = e->array[j + 1];
    }
    e->array[e->size - 1] = NULL;
    e->size = e->size - 1;
    return data;
}

void * array_list_delete_first_(struct list *l) {
    assert(l != NULL);
    return array_list_delete(l, 0);
}

void * array_list_delete_last_(struct list *l) {
    assert(l != NULL);
    array_list_delete(l, array_list_size(l) - 1);
}


void * array_list_get(struct list *l, size_t i) {
    assert(l != NULL);
    struct array_list_env *e = (struct array_list_env *) l->env;
    return e->array[i];
}

void * array_list_get_first_(struct list *l) {
    assert(l != NULL);
    if (l->get_first_ != NULL) {
        return l->get_first_(l);
    }
    return array_list_get(l, 0);
}

void * array_list_get_last_(struct list *l) {
    assert(l != NULL);
    if (l->get_last_ != NULL) {
        return l->get_last_(l);
    }
    return array_list_get(l, array_list_size(l) - 1);
}


struct list * array_list() {
    struct array_list_env *e = malloc(sizeof(struct array_list_env));
    if (e == NULL) {
        return NULL;
    }
    e->array = NULL;
    e->capacity = 0;
    e->size = 0;
    struct list *l = malloc(sizeof(struct list));
    if (l == NULL) {
        free(e);
        return NULL;
    }
    l->env = e;
    l->size = array_list_size;
    l->size_zero_ = array_list_size_zero_;
    l->insert = array_list_insert;
    l->insert_first_ = array_list_insert_first_;
    l->insert_last_ = array_list_insert_last_;
    l->delete = array_list_delete;
    l->delete_first_ = array_list_delete_first_;
    l->delete_last_ = array_list_delete_last_;
    return l;
}

void array_list_free(struct list *l, void (*f)(void *)) {
    assert(l != NULL);
    assert(f != NULL);
    while (!list_size_zero_(l)) {
        void *data = list_delete_last_(l);
        (*f)(data);
    }
    struct array_list_env *e = (struct array_list_env *) l->env;
    free(e->array);
    free(l);
}


