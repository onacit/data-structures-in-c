//
// Created by onacit on 2021-06-06.
//

#include <assert.h>
#include <stdlib.h>
#include "singly_linked_node.h"

struct singly_linked_node * singly_linked_node(void *d) {
    struct singly_linked_node *node = malloc(sizeof(struct singly_linked_node));
    if (node == NULL) {
        return NULL;
    }
    node->next = NULL;
    node->data = d;
    return node;
}

void * singly_linked_node_free(struct singly_linked_node *n) {
    assert(n != NULL);
    assert(n->next == NULL);
    void *d = n->data;
    n->data = NULL;
    free(n);
    return d;
}

struct singly_linked_node * singly_linked_node_link_next(struct singly_linked_node *p, void *d) {
    assert (p != NULL);
    struct singly_linked_node *n = singly_linked_node(d);
    if (n == NULL) {
        return NULL;
    }
    n->next = p->next;
    p->next = n;
    return n;
}

void * singly_linked_node_unlink_next(struct singly_linked_node *p) {
    assert (p != NULL);
    assert (p->next != NULL);
    struct singly_linked_node *n = p->next;
    p->next = n->next;
    n->next = NULL;
    return singly_linked_node_free(n);
}

struct singly_linked_node * singly_linked_node_find(struct singly_linked_node *node, bool (*test)(void *)) {
    assert(node != NULL);
    assert(test != NULL);
    for (struct singly_linked_node *n = node; n != NULL; n = n->next) {
        if ((*test)(n->data)) {
            return n;
        }
    }
    return NULL;
}


