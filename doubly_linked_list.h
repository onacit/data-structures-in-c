//
// Created by onacit on 2021-06-06.
//

#ifndef DATA_STRUCTURES_IN_C_DOUBLY_LINKED_LIST_H
#define DATA_STRUCTURES_IN_C_DOUBLY_LINKED_LIST_H

#include "doubly_linked_node.h"

struct doubly_linked_list {
    struct doubly_linked_node* head;
    struct doubly_linked_node* tail;
};

struct doubly_linked_list * doubly_linked_list_malloc();

void doubly_linked_list_free(struct doubly_linked_list *);

int doubly_linked_list_insert(struct doubly_linked_list *, size_t, void *);


#endif //DATA_STRUCTURES_IN_C_DOUBLY_LINKED_LIST_H
