#ifndef DATA_STRUCTURES_IN_C_SINGLY_LINKED_NODE_H
#define DATA_STRUCTURES_IN_C_SINGLY_LINKED_NODE_H

struct singly_linked_node {
    struct singly_linked_node *next;
    void *data;
};

struct singly_linked_node * singly_linked_node(void *d);

void * singly_linked_node_free(struct singly_linked_node *n);

struct singly_linked_node * singly_linked_node_insert_next(struct singly_linked_node *p, void *d);

void * singly_linked_node_delete_next(struct singly_linked_node *p);

#endif //DATA_STRUCTURES_IN_C_SINGLY_LINKED_NODE_H
