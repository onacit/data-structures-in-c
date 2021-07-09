//
// Created by onacit on 2021-06-05.
//

#include <assert.h>
#include <stdbool.h>
#include "list.h"


size_t list_size(struct list *l) {
    assert(l != NULL);
    return l->size(l);
}

bool list_empty(struct list *l) {
    assert(l != NULL);
    if (l->size_zero_ != NULL) {
        return l->size_zero_(l);
    }
    return l->size(l) == 0;
}


bool list_insert(struct list *l, size_t i, void *d) {
    assert(l != NULL);
    return l->insert(l, i, d);
}

bool list_push_front(struct list *l, void *d) {
    assert(l != NULL);
    if (l->insert_first_ != NULL) {
        return l->insert_first_(l, d);
    }
    return list_insert(l, 0, d);
}

bool list_push_back(struct list *l, void *d) {
    assert(l != NULL);
    if (l->insert_last_ != NULL) {
        return l->insert_last_(l, d);
    }
    size_t i = list_size(l);
    return l->insert(l, i, d);
}


bool list_delete(struct list *l, size_t i, void (*f)(void *)) {
    assert(l != NULL);
    assert(f != NULL);
    return l->delete(l, i, f);
}

bool list_pop_front(struct list *l, void (*f)(void *)) {
    assert(l != NULL);
    assert(f != NULL);
    if (l->delete_first_ != NULL) {
        return l->delete_first_(l, f);
    }
    return list_delete(l, 0, f);
}

bool list_pop_back(struct list *l, void (*f)(void *)) {
    if (l->delete_first_ != NULL) {
        return l->delete_last_(l, f);
    }
    size_t i = list_size(l);
    return list_delete(l, i, f);
}


bool list_access(struct list *l, size_t i, void (*f)(void **)) {
    assert(l != NULL);
    assert(f != NULL);
    return l->access(l, i, f);
}

bool list_front(struct list *l, void (*f)(void **)) {
    assert(l != NULL);
    assert(f != NULL);
    if (l->access_first != NULL) {
        return l->access_first(l, f);
    }
    return list_access(l, 0, f);
}

bool list_back(struct list *l, void (*f)(void **)) {
    assert(l != NULL);
    assert(f != NULL);
    if (l->access_last != NULL) {
        return l->access_last(l, f);
    }
    size_t i = list_size(l);
    return list_access(l, i, f);
}
