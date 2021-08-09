
#ifndef DATA_STRUCTURES_IN_C_DOUBLY_LINKED_NODE_H
#define DATA_STRUCTURES_IN_C_DOUBLY_LINKED_NODE_H

#include "singly_linked_node.h"

struct doubly_linked_node {
    struct doubly_linked_node *next;
    struct doubly_linked_node *prev;
    void *data;
};

struct doubly_linked_node * doubly_linked_node(void *d);

void * doubly_linked_node_free(struct doubly_linked_node *n);

struct doubly_linked_node * doubly_linked_node_insert_next(struct doubly_linked_node *p, void *d);

struct doubly_linked_node * doubly_linked_node_insert_prev(struct doubly_linked_node *n, void *d);

void * doubly_linked_node_delete_next(struct doubly_linked_node *p);

void * doubly_linked_node_delete_prev(struct doubly_linked_node *n);

#endif //DATA_STRUCTURES_IN_C_DOUBLY_LINKED_NODE_H
