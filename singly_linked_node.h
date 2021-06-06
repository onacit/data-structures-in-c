//
// Created by onacit on 2021-06-06.
//

#ifndef DATA_STRUCTURES_IN_C_SINGLY_LINKED_LIST_R
#define DATA_STRUCTURES_IN_C_SINGLY_LINKED_LIST_R

struct singly_linked_node {
    void *data;
    struct singly_linked_node *next;
};

struct singly_linked_node* singly_linked_node_malloc(void *);

void * singly_linked_node_free(struct singly_linked_node *);

void singly_linked_node_link_next(struct singly_linked_node *, struct singly_linked_node *);

struct singly_linked_node * singly_linked_node_unlink_next(struct singly_linked_node *);

#endif //DATA_STRUCTURES_IN_C_SINGLY_LINKED_LIST_R
