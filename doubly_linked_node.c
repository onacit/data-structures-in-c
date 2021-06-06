//
// Created by onacit on 2021-06-06.
//

#include <assert.h>
#include <stdlib.h>
#include "doubly_linked_node.h"

struct doubly_linked_node * doubly_linked_node_malloc(void *data) {
    struct doubly_linked_node *node = malloc(sizeof(struct doubly_linked_node));
    if (node == NULL) {
        return NULL;
    }
    node->data = data;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

void * doubly_linked_node_free(struct doubly_linked_node *NODE) {
    assert(NODE != NULL);
    assert(NODE->prev == NULL);
    assert(NODE->next == NULL);
    void *data = NODE->data;
    free(NODE);
    return data;
}

void doubly_linked_node_link_next(struct doubly_linked_node *NODE, struct doubly_linked_node *NEXT) {
    assert(NODE != NULL);
    assert(NEXT != NULL);
    assert(NEXT != NODE);
    NEXT->next = NODE->next;
    NODE->next = NEXT;
    if (NEXT->next != NULL) {
        NEXT->next->prev = NEXT;
    }
    NEXT->prev = NODE;
}

struct doubly_linked_node * doubly_linked_node_unlink_next(struct doubly_linked_node *NODE) {
    assert(NODE != NULL);
    struct doubly_linked_node *NEXT = NODE->next;
    if (NEXT == NULL) {
        return NULL;
    }
    NODE->next = NEXT->next;
    NEXT->next = NULL;
    if (NODE->next != NULL) {
        NODE->next->prev = NODE;
    }
    NEXT->prev = NULL;
    return NEXT;
}

void doubly_linked_node_link_prev(struct doubly_linked_node *NODE, struct doubly_linked_node *PREV) {
    assert(NODE != NULL);
    assert(PREV != NULL);
    assert(PREV != NODE);
    if (NODE->prev != NULL) {
        NODE->prev->next = PREV;
        PREV->next = NODE;
    }
    PREV->prev = NODE->prev;
    NODE->prev = PREV;
}

struct doubly_linked_node * doubly_linked_node_unlink_prev(struct doubly_linked_node *NODE) {
    assert(NODE != NULL);
    struct doubly_linked_node *PREV = NODE->prev;
    if (PREV == NULL) {
        return NULL;
    }
    if (PREV->prev != NULL) {
        PREV->prev->next = NODE;
    }
    PREV->next = NULL;
    NODE->prev = PREV->prev;
    PREV->prev = NULL;
    return PREV;
}

struct doubly_linked_node * doubly_linked_node_unlink_self(struct doubly_linked_node *NODE) {
    assert(NODE != NULL);
    if (NODE->prev != NULL) {
        return doubly_linked_node_unlink_next(NODE->prev);
    }
    if (NODE->next != NULL) {
        return doubly_linked_node_unlink_prev(NODE->next);
    }
    return NODE;
}






