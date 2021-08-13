
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "singly_linked_node.h"
#include "singly_linked_list.h"


struct singly_linked_list_env {
    struct singly_linked_node *head;
};


struct singly_linked_node * node(struct singly_linked_list_env *const e,
                                 const size_t i) {
    assert(e != NULL);
    struct singly_linked_node *n = e->head;          // <1>
    for (size_t j = 0; n != NULL && j < i; j++) {    // <2>
        n = n->next;                                 // <3>
    }
    return n;
}

struct singly_linked_node * tail(struct singly_linked_list_env *const e,
                                 const size_t i) {
    assert(e != NULL);
    struct singly_linked_node *n = e->head;          // <1>
    for (size_t j = 0; n != NULL && j < i; j++) {    // <2>
        n = n->next;                                 // <3>
    }
    return n;
}

// ------------------------------------------------------------------------ size

size_t singly_linked_list_size(struct list *const l) {
    assert(l != NULL);
    struct singly_linked_list_env *const e = l->env;
    size_t s = 0;
    for (struct singly_linked_node *n = e->head; n != NULL; n = n->next) {
        s++;
    }
    return s;
}

bool singly_linked_list_empty(struct list *const l) {
    assert(l != NULL);
    struct singly_linked_list_env *e = l->env;
    return e->head == NULL;
}

// ---------------------------------------------------------------------- insert

int singly_linked_list_insert(struct list *const l, const size_t i,
                              void *const d) {
    assert(l != NULL);
    struct singly_linked_list_env *const e = l->env;
    if (i == 0) {
        struct singly_linked_node *const n = singly_linked_node(d);
        if (n == NULL) {
            return -1;
        }
        n->next = e->head;
        e->head = n;
        return 0;
    }
    struct singly_linked_node *const p = node(e, i - 1);
    singly_linked_node_insert_next(p, d);
    return 0;
}

int singly_linked_list_insert_first(struct list *const l, void *const d) {
    return singly_linked_list_insert(l, 0, d);
}

int singly_linked_list_insert_last(struct list *const l, void *const d) {
    return singly_linked_list_insert(l, singly_linked_list_size(l), d);
}

// ---------------------------------------------------------------------- delete

void * singly_linked_list_delete(struct list *const l, const size_t i) {
    assert(l != NULL);
    assert(!singly_linked_list_empty(l));
    struct singly_linked_list_env *const e = l->env;
    if (i == 0) {
        struct singly_linked_node *const h = e->head;
        e->head = h->next;
        h->next = NULL;
        return singly_linked_node_free(h);
    }
    struct singly_linked_node *p = node(e, i - 1);
    return singly_linked_node_delete_next(p);
}

void * singly_linked_list_delete_first(struct list *const l) {
    return singly_linked_list_delete(l, 0);
}

void * singly_linked_list_delete_last(struct list *const l) {
    return singly_linked_list_delete(l, singly_linked_list_size(l) - 1);
}

// ------------------------------------------------------ constructor/destructor

struct list * singly_linked_list() {
    struct singly_linked_list_env *e
            = malloc(sizeof(struct singly_linked_list_env));
    if (e == NULL) {
        return NULL;
    }
    struct list *l = malloc(sizeof(struct list));
    if (l == NULL) {
        free(e);
        return NULL;
    }
    l->env = e;
    l->size = singly_linked_list_size;
    l->empty = singly_linked_list_empty;
    l->insert = singly_linked_list_insert;
    l->insert_first = singly_linked_list_insert_first;
    l->insert_last = singly_linked_list_insert_last;
    l->delete = singly_linked_list_delete;
    l->delete_first = singly_linked_list_delete_first;
    l->delete_last = singly_linked_list_delete_last;
    return l;
}

void singly_linked_list_free(struct list *l) {
    assert(l != NULL);
    assert(singly_linked_list_empty(l));
    free(l);
}
