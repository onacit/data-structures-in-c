//
// Created by onacit on 2021-06-06.
//

#include <assert.h>
#include <stdlib.h>
#include "singly_linked_node.h"

struct singly_linked_node * singly_linked_node_alloc(void *data) {
    size_t s = sizeof(struct singly_linked_node);
    struct singly_linked_node *n = malloc(s);
    if (n == NULL) {
        return NULL;
    }
    n->data = data;
    n->next = NULL;
    return n;
}

void * singly_linked_node_free(struct singly_linked_node *node) {
    assert(node != NULL);
    assert(node->next == NULL);
    void *d = node->data;
    node->data = NULL;
    free(node);
    return d;
}

void singly_linked_node_link_next(struct singly_linked_node *node, struct singly_linked_node *next) {
    assert(node != NULL);
    assert(next != NULL);
    next->next = node->next;
    node->next = next;
}

struct singly_linked_node * singly_linked_node_unlink_next(struct singly_linked_node *node) {
    assert(node != NULL);
    struct singly_linked_node *next = node->next;
    if (next == NULL) {
        return NULL;
    }
    node->next = next->next;
    next->next = NULL;
    return next;
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


