//
// Created by onacit on 2021-06-05.
//

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include "array_list.h"


struct array_list_env_ {
    void **array;
    size_t capacity;
    size_t size;
};

// -----------------------------------------------------------------------------

size_t array_list_size(struct list *l) {
    assert(l != NULL);
    struct array_list_env_ *e = (struct array_list_env_ *) l->env_;
    return e->size;
}

bool array_list_size_zero_(struct list *l) {
    return array_list_size(l) == 0;
}

// -----------------------------------------------------------------------------

void array_list_insert(struct list *l, size_t i, void *d) {
    assert(l != NULL);
    assert(i <= array_list_size(l));
    struct array_list_env_ *e = (struct array_list_env_ *) l->env_;
    if (e->size == e->capacity) {
        e->capacity = e->capacity == 0 ? 1 : e->capacity << 1;
        e->array = realloc(e->array, sizeof(void *) * (e->capacity));
        assert(e->array != NULL);
    }
    for (size_t j = e->size; j > i; j--) {
        e->array[j] = e->array[j - 1];
    }
    e->array[i] = d;
    e->size = e->size + 1;
}

void array_list_insert_first_(struct list *l, void *d) {
    size_t i = 0;
    array_list_insert(l, i, d);
}

void array_list_insert_last_(struct list *l, void *d) {
    size_t i = array_list_size(l);
    array_list_insert(l, i, d);
}


void * array_list_delete(struct list *l, size_t i) {
    assert(l != NULL);
    assert(i < array_list_size(l));
    struct array_list_env_ *e = (struct array_list_env_ *) l->env_;
    void *d = e->array[i];
    for (size_t j = i; j < e->size - 1; j++) {
        e->array[j] = e->array[j + 1];
    }
    e->array[e->size - 1] = NULL;
    e->size = e->size - 1;
    return d;
}

void * array_list_delete_first_(struct list *l) {
    size_t i = 0;
    return array_list_delete(l, i);
}

void * array_list_delete_last_(struct list *l) {
    size_t i = array_list_size(l) - 1;
    array_list_delete(l, i);
}

// -----------------------------------------------------------------------------

void * array_list_get(struct list *l, size_t i) {
    assert(l != NULL);
    assert(i < array_list_size(l));
    struct array_list_env_ *e = (struct array_list_env_ *) l->env_;
    return e->array[i];
}

void * array_list_get_first_(struct list *l) {
    size_t i = 0;
    return array_list_get(l, i);
}

void * array_list_get_last_(struct list *l) {
    size_t i = array_list_size(l) - 1;
    return array_list_get(l, i);
}

// -----------------------------------------------------------------------------

void * array_list_set(struct list *l, size_t i, void *d) {
    assert(l != NULL);
    struct array_list_env_ *e = (struct array_list_env_ *) l->env_;
    void *p = e->array[i];
    e->array[i] = d;
    return p;
}

void * array_list_set_first_(struct list *l, void *d) {
    size_t i = 0;
    return array_list_set(l, i, d);
}

void * array_list_set_last_(struct list *l, void *d) {
    size_t i = array_list_size(l) - 1;
    return array_list_set(l, i, d);
}

// -----------------------------------------------------------------------------

struct list * array_list() {
    struct array_list_env_ *e = malloc(sizeof(struct array_list_env_));
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
    l->env_ = e;
    l->size = array_list_size;
    l->empty = array_list_size_zero_;
    l->insert = array_list_insert;
    l->insert_first = array_list_insert_first_;
    l->insert_last = array_list_insert_last_;
    l->delete = array_list_delete;
    l->delete_first = array_list_delete_first_;
    l->delete_last = array_list_delete_last_;
    l->get = array_list_get;
    l->get_first = array_list_get_first_;
    l->get_last = array_list_get_last_;
    l->set = array_list_set;
    l->set_first = array_list_set_first_;
    l->set_last = array_list_set_last_;
    return l;
}

void array_list_free(struct list *l) {
    assert(l != NULL);
    assert(array_list_size_zero_(l));
    struct array_list_env_ *e = (struct array_list_env_ *) l->env_;
    free(e->array);
    free(l);
}


