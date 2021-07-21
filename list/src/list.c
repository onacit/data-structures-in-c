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

bool list_empty(struct list *l) {
    assert(l != NULL);
    if (l->empty != NULL) {
        return l->empty(l);
    }
    return l->size(l) == 0;
}


void list_insert(struct list *l, size_t i, void *d) {
    assert(l != NULL);
    return l->insert(l, i, d);
}

void list_insert_first(struct list *l, void *d) {
    assert(l != NULL);
    if (l->insert_first != NULL) {
        return l->insert_first(l, d);
    }
    return list_insert(l, 0, d);
}

void list_insert_last(struct list *l, void *d) {
    assert(l != NULL);
    if (l->insert_last != NULL) {
        return l->insert_last(l, d);
    }
    return l->insert(l, list_size(l), d);
}


void * list_delete(struct list *l, size_t i) {
    assert(l != NULL);
    assert(!list_empty(l));
    return l->delete(l, i);
}

void * list_delete_first(struct list *l) {
    assert(l != NULL);
    if (l->delete_first != NULL) {
        return l->delete_first(l);
    }
    return list_delete(l, 0);
}

void * list_delete_last(struct list *l) {
    assert(l != NULL);
    if (l->delete_first != NULL) {
        return l->delete_last(l);
    }
    return list_delete(l, list_size(l) - 1);
}


void * list_get(struct list *l, size_t i) {
    assert(l != NULL);
    assert(!list_empty(l));
    return l->get(l, i);
}

void * list_get_first(struct list *l) {
    assert(l != NULL);
    if (l->get_first != NULL) {
        return l->get_first(l);
    }
    return list_get(l, 0);
}

void * list_get_last(struct list *l) {
    assert(l != NULL);
    if (l->get_last != NULL) {
        return l->get_last(l);
    }
    return list_get(l, list_size(l) - 1);
}


void * list_set(struct list *l, size_t i, void *d) {
    assert(l != NULL);
    assert(!list_empty(l));
    return l->set(l, i, d);
}

void * list_set_first(struct list *l, void *d) {
    assert(l != NULL);
    if (l->set_first != NULL) {
        return l->set_first(l, d);
    }
    return list_set(l, 0, d);
}

void * list_set_last(struct list *l, void *d) {
    assert(l != NULL);
    if (l->set_last != NULL) {
        return l->set_last(l, d);
    }
    return list_set(l, list_size(l) - 1, d);
}