//
// Created by onacit on 2021-06-06.
//

#ifndef DATA_STRUCTURES_IN_C_SINGLY_LINKED_NODE_H
#define DATA_STRUCTURES_IN_C_SINGLY_LINKED_NODE_H

#include <stdbool.h>

struct singly_linked_node {
    struct singly_linked_node *next;
    void *data;
};

struct singly_linked_node * singly_linked_node_alloc(void *data);

void * singly_linked_node_free(struct singly_linked_node *node);

void singly_linked_node_link_next(struct singly_linked_node *node, struct singly_linked_node *next);

struct singly_linked_node * singly_linked_node_unlink_next(struct singly_linked_node *node);

struct singly_linked_node * singly_linked_node_find(struct singly_linked_node *node, bool (*test)(void *));

#endif //DATA_STRUCTURES_IN_C_SINGLY_LINKED_NODE_H
