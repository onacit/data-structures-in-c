//
// Created by onacit on 2021-06-05.
//

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include "list.h"


size_t list_size(struct list *l) {
    assert(l != NULL);
    return l->size(l);
}

bool list_size_zero_(struct list *l) {
    assert(l != NULL);
    if (l->size_zero_ != NULL) {
        return l->size_zero_(l);
    }
    return l->size(l) == 0;
}


void list_insert(struct list *l, size_t i, void *d) {
    assert(l != NULL);
    return l->insert(l, i, d);
}

void list_insert_first_(struct list *l, void *d) {
    assert(l != NULL);
    if (l->insert_first_ != NULL) {
        return l->insert_first_(l, d);
    }
    return list_insert(l, 0, d);
}

void list_insert_last_(struct list *l, void *d) {
    assert(l != NULL);
    if (l->insert_last_ != NULL) {
        return l->insert_last_(l, d);
    }
    return l->insert(l, list_size(l), d);
}


void list_delete(struct list *l, size_t i, void (*f)(void *)) {
    assert(l != NULL);
    assert(f != NULL);
    return l->delete(l, i, f);
}

void list_delete_first_(struct list *l, void (*f)(void *)) {
    assert(l != NULL);
    assert(f != NULL);
    if (l->delete_first_ != NULL) {
        return l->delete_first_(l, f);
    }
    return list_delete(l, 0, f);
}

void list_delete_last_(struct list *l, void (*f)(void *)) {
    if (l->delete_first_ != NULL) {
        return l->delete_last_(l, f);
    }
    return list_delete(l, list_size(l), f);
}


void * list_get(struct list *l, size_t i) {
    assert(l != NULL);
    return l->get(l, i);
}

void * list_get_first(struct list *l) {
    assert(l != NULL);
    if (l->get_first_ != NULL) {
        return l->get_first_(l);
    }
    return list_get(l, 0);
}

void * list_get_last(struct list *l) {
    assert(l != NULL);
    if (l->get_last_ != NULL) {
        return l->get_last_(l);
    }
    return list_get(l, list_size(l) - 1);
}


void * list_set(struct list *l, size_t i, void *d) {
    assert(l != NULL);
    return l->set(l, i, d);
}

void * list_set_first(struct list *l, void *d) {
    assert(l != NULL);
    if (l->set_first_ != NULL) {
        return l->set_first_(l, d);
    }
    return list_set(l, 0, d);
}

void * list_set_last(struct list *l, void *d) {
    assert(l != NULL);
    if (l->set_last_ != NULL) {
        return l->set_last_(l, d);
    }
    return list_set(l, list_size(l) - 1, d);
}


void list_access(struct list *l, size_t i, void (*f)(void *)) {
    assert(l != NULL);
    assert(f != NULL);
    return l->access(l, i, f);
}

void list_access_first_(struct list *l, void (*f)(void *)) {
    assert(l != NULL);
    assert(f != NULL);
    if (l->access_first != NULL) {
        return l->access_first(l, f);
    }
    return list_access(l, 0, f);
}

void list_access_last_(struct list *l, void (*f)(void *)) {
    assert(l != NULL);
    assert(f != NULL);
    if (l->access_last != NULL) {
        return l->access_last(l, f);
    }
    return list_access(l, list_size(l) - 1, f);
}
