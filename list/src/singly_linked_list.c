
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "singly_linked_node.h"
#include "singly_linked_list.h"


struct singly_linked_list_env {
    struct singly_linked_node *head;
};


struct singly_linked_node * node_from_head(struct list *l, size_t i) {
    assert(l != NULL);
    struct singly_linked_list_env *e = l->env;    // <1>
    assert(e != NULL);
    struct singly_linked_node *n = e->head;       // <2>
    for (size_t j = 0; n != NULL && j < i; j++) { // <3>
        n = n->next;                              // <4>
    }
    return n;
}

// ------------------------------------------------------------------------ size

size_t singly_linked_list_size(struct list *l) {
    assert(l != NULL);
    size_t s = 0;
    struct singly_linked_list_env *e = l->env;
    assert(e != NULL);
    struct singly_linked_node *n = e->head;
    for (; n != NULL; n = n->next) {
        s++;
    }
    return s;
}

bool singly_linked_list_empty(struct list *l) {
    assert(l != NULL);
    struct singly_linked_list_env *e = l->env;
    assert(e != NULL);
    return e->head == NULL;
}

// ---------------------------------------------------------------------- insert

void singly_linked_list_insert(struct list *l, size_t i, void *d) {
    assert(l != NULL);
    struct singly_linked_list_env *e = l->env;
    assert(e != NULL);
    if (i == 0) {
        struct singly_linked_node *n = singly_linked_node(d);
        assert(n != NULL);
        n->next = e->head;
        e->head = n;
        return;
    }
    struct singly_linked_node *p = node_from_head(l, i - 1);
    singly_linked_node_insert_next(p, d);
}

void singly_linked_list_insert_first(struct list *l, void *d) {
    singly_linked_list_insert(l, 0, d);
}

void singly_linked_list_insert_last(struct list *l, void *d) {
    singly_linked_list_insert(l, singly_linked_list_size(l), d);
}

// ---------------------------------------------------------------------- delete

void * singly_linked_list_delete(struct list *l, size_t i) {
    assert(l != NULL);
    assert(!singly_linked_list_empty(l));
    if (i == 0) {
        struct singly_linked_list_env *e = l->env;
        struct singly_linked_node *h = e->head;
        assert(h != NULL);
        e->head = h->next;
        h->next = NULL;
        return singly_linked_node_free(h);
    }
    struct singly_linked_node *p = node_from_head(l, i - 1);
    return singly_linked_node_delete_next(p);
}

void * singly_linked_list_delete_first(struct list *l) {
    return singly_linked_list_delete(l, 0);
}

void * singly_linked_list_delete_last(struct list *l) {
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
