//
// Created by onacit on 2021-06-06.
//

#include <assert.h>
#include <stdlib.h>
#include "singly_linked_node.h"

singly_linked_node * singly_linked_node_alloc(void *data) {
    size_t s = sizeof(singly_linked_node);
    singly_linked_node *n = malloc(s);
    if (n == NULL) {
        return NULL;
    }
    n->data = data;
    n->next = NULL;
    return n;
}

void * singly_linked_node_free(singly_linked_node *node) {
    assert(node != NULL);
    assert(node->next == NULL);
    void *d = node->data;
    node->data = NULL;
    free(node);
    return d;
}

void singly_linked_node_link_next(singly_linked_node *node, singly_linked_node *next) {
    assert(node != NULL);
    assert(next != NULL);
    next->next = node->next;
    node->next = next;
}

singly_linked_node * singly_linked_node_unlink_next(singly_linked_node *node) {
    assert(node != NULL);
    singly_linked_node *next = node->next;
    if (next == NULL) {
        return NULL;
    }
    node->next = next->next;
    next->next = NULL;
    return next;
}

singly_linked_node * singly_linked_node_find(singly_linked_node *node, bool (*test)(void *)) {
    assert(node != NULL);
    assert(test != NULL);
    for (singly_linked_node *n = n; n != NULL; n = n->next) {
        if ((*test)(n->data)) {
            return n;
        }
    }
    return NULL;
}

//bool singly_linked_node_is_last(struct singly_linked_node_alloc *node) {
//    assert(node != NULL);
//    return node->next == NULL;
//}


