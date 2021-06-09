//
// Created by onacit on 2021-06-06.
//

#ifndef DATA_STRUCTURES_IN_C_SINGLY_LINKED_NODE_H
#define DATA_STRUCTURES_IN_C_SINGLY_LINKED_NODE_H

#include <stdbool.h>

typedef struct singly_linked_node_ {
    struct singly_linked_node_ *next;
    void *data;
} singly_linked_node;

singly_linked_node * singly_linked_node_alloc(void const *data);

void * singly_linked_node_free(singly_linked_node *node);

void singly_linked_node_link_next(singly_linked_node *node, singly_linked_node *next);

singly_linked_node * singly_linked_node_unlink_next(singly_linked_node *node);

singly_linked_node * singly_linked_node_find(singly_linked_node *node, bool const (*test)(void *));

#endif //DATA_STRUCTURES_IN_C_SINGLY_LINKED_NODE_H
