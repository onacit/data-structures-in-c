
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "doubly_linked_node.h"
#include "doubly_linked_list.h"


struct doubly_linked_list_env {
    struct doubly_linked_node *head;
    struct doubly_linked_node *tail;
};


struct doubly_linked_node * node_from_head(struct list *l, size_t i) {
    assert(l != NULL);
    struct doubly_linked_list_env *e = l->env;    // <1>
    struct doubly_linked_node *n = e->head;       // <2>
    for (size_t j = 0; n != NULL && j < i; j++) { // <3>
        n = n->next;                              // <4>
    }
    return n;
}

struct doubly_linked_node * node_from_tail(struct list *l, size_t i) {
    assert(l != NULL);
    struct doubly_linked_list_env *e = l->env;    // <1>
    struct doubly_linked_node *n = e->tail;       // <2>
    for (size_t j = 0; n != NULL && j < i; j++) { // <3>
        n = n->prev;                              // <4>
    }
    return n;
}

// ------------------------------------------------------------------------ size

size_t doubly_linked_list_size(struct list *l) {
    assert(l != NULL);
    size_t s = 0;
    struct doubly_linked_list_env *e = l->env;
    struct doubly_linked_node *n = e->head;
    for (; n != NULL; n = n->next) {
        s++;
    }
    return s;
}

bool doubly_linked_list_empty(struct list *l) {
    assert(l != NULL);
    struct doubly_linked_list_env *e = l->env;
    return e->head == NULL;
}

// ---------------------------------------------------------------------- insert

void doubly_linked_list_insert_first(struct list *l, void *d) {
    assert(l != NULL);
    struct doubly_linked_list_env *e = l->env;
    assert(e != NULL);
    if (e->head != NULL) {
        e->head = doubly_linked_node_insert_prev(e->head, d);
        return;
    }
    assert(e->head == NULL);
    assert(e->tail == NULL);
    struct doubly_linked_node *n = doubly_linked_node(d);
    assert(n != NULL);
    e->head = n;
    e->tail = n;
}

void doubly_linked_list_insert_last(struct list *l, void *d) {
    assert(l != NULL);
    struct doubly_linked_list_env *e = l->env;
    assert(e != NULL);
    if (e->tail != NULL) {
        e->tail = doubly_linked_node_insert_next(e->tail, d);
        return;
    }
    assert(e->tail == NULL);
    assert(e->head == NULL);
    struct doubly_linked_node *n = doubly_linked_node(d);
    assert(n != NULL);
    e->tail = n;
    e->head = n;
}

void doubly_linked_list_insert(struct list *l, size_t i, void *d) {
    assert(l != NULL);
    assert(i <= doubly_linked_list_size(l));
    struct doubly_linked_list_env *e = l->env;
    if (i == 0) {
        doubly_linked_list_insert_first(l, d);
        return;
    } else if (i == doubly_linked_list_size(l)) {
        doubly_linked_list_insert_last(l, d);
        return;
    }
    struct doubly_linked_node *p = node_from_head(l, i - 1);
    doubly_linked_node_insert_next(p, d);
}

// ---------------------------------------------------------------------- delete
void * doubly_linked_list_delete_first(struct list *l) {
    assert(l != NULL);
    assert(doubly_linked_list_size(l) > 0);
    struct doubly_linked_list_env *e = l->env;
    assert(e != NULL);
    struct doubly_linked_node *h = e->head;
    assert(h != NULL);
    e->head = h->next;
    if (e->head == NULL) {
        e->tail = NULL;
    }
    h->next = NULL;
    assert(h->prev == NULL);
    return doubly_linked_node_free(h);
}

void * doubly_linked_list_delete_last(struct list *l) {
    assert(l != NULL);
    assert(doubly_linked_list_size(l) > 0);
    struct doubly_linked_list_env *e = l->env;
    assert(e != NULL);
    struct doubly_linked_node *t = e->tail;
    assert(t != NULL);
    e->tail= t->prev;
    if (e->tail== NULL) {
        e->head = NULL;
    }
    t->prev = NULL;
    assert(t->next == NULL);
    return doubly_linked_node_free(t);
}

void * doubly_linked_list_delete(struct list *l, size_t i) {
    assert(l != NULL);
    assert(!doubly_linked_list_empty(l));
    assert(i < doubly_linked_list_size(l));
    if (i == 0) {
        return doubly_linked_list_delete_first(l);
    } else if (i == doubly_linked_list_size(l) - 1) {
        return doubly_linked_list_delete_last(l);
    }
    struct doubly_linked_node *p = node_from_head(l, i - 1);
    return doubly_linked_node_delete_next(p);
}


// ---------------------------------------------------------------------------------------------------------------------

struct list * doubly_linked_list() {
    struct doubly_linked_list_env *e = malloc(sizeof(struct doubly_linked_list_env));
    if (e == NULL) {
        return NULL;
    }
    struct list *l = malloc(sizeof(struct list));
    if (l == NULL) {
        free(e);
        return NULL;
    }
    l->env = e;
    l->size = doubly_linked_list_size;
    l->empty = doubly_linked_list_empty;
    l->insert = doubly_linked_list_insert;
    l->insert_first = doubly_linked_list_insert_first;
    l->insert_last = doubly_linked_list_insert_last;
    l->delete = doubly_linked_list_delete;
    l->delete_first = doubly_linked_list_delete_first;
    l->delete_last = doubly_linked_list_delete_last;
    return l;
}

void doubly_linked_list_free(struct list *l) {
    assert(l != NULL);
    assert(doubly_linked_list_empty(l));
    free(l);
}
