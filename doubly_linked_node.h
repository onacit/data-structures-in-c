//
// Created by onacit on 2021-06-06.
//

#ifndef DATA_STRUCTURES_IN_C_DOUBLY_LINKED_LIST_R
#define DATA_STRUCTURES_IN_C_DOUBLY_LINKED_LIST_R

#include "singly_linked_node.h"

struct doubly_linked_node {
    void *data;
    struct doubly_linked_node* prev;
    struct doubly_linked_node* next;
};

struct doubly_linked_node * doubly_linked_node_malloc(void *);

void * doubly_linked_node_free(struct doubly_linked_node *);

void doubly_linked_node_link_next(struct doubly_linked_node *, struct doubly_linked_node *);

struct doubly_linked_node * doubly_linked_node_unlink_next(struct doubly_linked_node *);

void doubly_linked_node_link_prev(struct doubly_linked_node *, struct doubly_linked_node *);

struct doubly_linked_node * doubly_linked_node_unlink_prev(struct doubly_linked_node *);

struct doubly_linked_node * doubly_linked_node_unlink_self(struct doubly_linked_node *);

#endif //DATA_STRUCTURES_IN_C_DOUBLY_LINKED_LIST_R
