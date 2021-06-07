//
// Created by onacit on 2021-06-06.
//

#include <assert.h>
#include <stdlib.h>
#include "singly_linked_node.h"

struct singly_linked_node * singly_linked_node_malloc(void *data) {
    struct singly_linked_node *node = malloc(sizeof(struct singly_linked_node));
    if (node == NULL) {
        return NULL;
    }
    node->data = data;
    node->next = NULL;
    return node;
}

void * singly_linked_node_free(struct singly_linked_node *node) {
    assert(node != NULL);
    assert(node->next == NULL);
    void *data = node->data;
    node->data = NULL;
    free(node);
    return data;
}

void singly_linked_node_link_next(struct singly_linked_node *NODE, struct singly_linked_node *NEXT) {
    assert(NODE != NULL);
    assert(NEXT != NULL);
    NEXT->next = NODE->next;
    NODE->next = NEXT;
}

struct singly_linked_node * singly_linked_node_unlink_next(struct singly_linked_node *NODE) {
    assert(NODE != NULL);
    struct singly_linked_node *NEXT = NODE->next;
    if (NEXT == NULL) {
        return NULL;
    }
    NODE->next = NEXT->next;
    NEXT->next = NULL;
    return NEXT;
}

struct singly_linked_node * singly_linked_node_find(struct singly_linked_node *node, bool const (*test)(void *)) {
    assert(node != NULL);
    assert(test != NULL);
    for (struct singly_linked_node *n = node; n != NULL; n = n->next) {
        if ((*test)(n->data)) {
            return n;
        }
    }
    return NULL;
}


