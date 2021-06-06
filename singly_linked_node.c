//
// Created by onacit on 2021-06-06.
//

#include <assert.h>
#include <stdlib.h>
#include "singly_linked_node.h"

struct singly_linked_node* singly_linked_node_malloc(void *data) {
    struct singly_linked_node *node = malloc(sizeof(struct singly_linked_node));
    if (node == NULL) {
        return NULL;
    }
    node->next = NULL;
    node->data = data;
    return node;
}

void * singly_linked_node_free(struct singly_linked_node *node) {
    assert(node != NULL);
    assert(node->next == NULL);
    void *data = node->data;
    free(node);
    return data;
}

void singly_linked_node_link(struct singly_linked_node *NODE, struct singly_linked_node *NEXT) {
    assert(NODE != NULL);
    assert(NEXT != NULL);
    assert(NEXT != NODE);
    NEXT->next = NODE->next;
    NODE->next = NEXT;
}

struct singly_linked_node * singly_linked_node_unlink(struct singly_linked_node *NODE) {
    assert(NODE != NULL);
    struct singly_linked_node *NEXT = NODE->next;
    if (NEXT == NULL) {
        return NULL;
    }
    NODE->next = NEXT->next;
    NEXT->next = NULL;
    return NEXT;
}

