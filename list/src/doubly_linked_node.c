#include <assert.h>
#include <stdlib.h>
#include "doubly_linked_node.h"

// ------------------------------------------------------ constructor/destructor

struct doubly_linked_node * doubly_linked_node(void *d) {
    struct doubly_linked_node *n = malloc(sizeof(struct doubly_linked_node));
    if (n == NULL) {
        return NULL;
    }
    n->next = NULL;
    n->prev = NULL;
    n->data = d;
    return n;
}

void * doubly_linked_node_free(struct doubly_linked_node *n) {
    assert(n != NULL);
    assert(n->next == NULL);
    assert(n->prev == NULL);
    void *d = n->data;
    n->data = NULL;
    free(n);
    return d;
}

// ---------------------------------------------------------------------- insert

struct doubly_linked_node * doubly_linked_node_insert_next(
        struct doubly_linked_node *p, void *d) {
    assert (p != NULL);
    struct doubly_linked_node *n = doubly_linked_node(d);
    if (n == NULL) {
        return NULL;
    }
    n->next = p->next;
    p->next = n;
    if (n->next != NULL) {
        n->next->prev = n;
    }
    n->prev = p;
    return n;
}

struct doubly_linked_node * doubly_linked_node_insert_prev(
        struct doubly_linked_node *n, void *d) {
    assert (n != NULL);
    struct doubly_linked_node *p = n->prev;
    if (p != NULL) {
        return doubly_linked_node_insert_next(p, d);
    }
    p = doubly_linked_node(d);
    if (p == NULL) {
        return NULL;
    }
    p->next = n;
    n->prev = p;
    return p;
}

// ---------------------------------------------------------------------- delete

void * doubly_linked_node_delete_next(struct doubly_linked_node *p) {
    assert (p != NULL);
    assert (p->next != NULL);
    struct doubly_linked_node *n = p->next;
    p->next = n->next;
    if (p->next != NULL) {
        p->next->prev = p;
    }
    n->next = NULL;
    n->prev = NULL;
    return doubly_linked_node_free(n);
}

void * doubly_linked_node_delete_prev(struct doubly_linked_node *n) {
    assert (n != NULL);
    assert (n->prev != NULL);
    struct doubly_linked_node *p = n->prev;
    if (p->prev != NULL) {
        return doubly_linked_node_delete_next(p->prev);
    }
    n->prev = NULL;
    p->next = NULL;
    return doubly_linked_node_free(p);
}
