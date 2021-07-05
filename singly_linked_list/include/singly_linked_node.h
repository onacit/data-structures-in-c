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

/**
 * Creates a singly linked node which holds specified data.
 * @param [in] d the data to hold.
 * @return a newly created singly linked node holds @p d.
 */
struct singly_linked_node * singly_linked_node(void *d);

/**
 * Frees specified singly linked node and returns the data it holds.
 * @param [in] n the singly linked not to free.
 * @return the data the @p n holds.
 */
void * singly_linked_node_free(struct singly_linked_node *n);

/**
 * @brief Links a new singly linked node, which holds specified data, and links it as specified node's @c next value.
 * @details
 * This function, first, creates a new node using singly_linked_node(void *) with specified @p d and links it to specified @p p.
 * @code{.txt}
 * p             result
 * ---------     ---------
 * | *next | --> | *next |
 * | *data |     | *data | --> d
 * @endcode
 *
 * @param [in] p the (previous) node to which the new node is linked.
 * @param [in] d the data for the new node.
 * @return a new node holds the @p d, linked from @p p. @c NULL when failed to create a new node.
 */
struct singly_linked_node * singly_linked_node_link_next(struct singly_linked_node *p, void *d);

/**
 * @brief Unlinks the next node linked to specified node, frees the node, and returns the data it holds.
 * @param p the node whose @c next node is unlinked and freed.
 * @return the value the unlinked next node holds.
 */
void * singly_linked_node_unlink_next(struct singly_linked_node *p);

//struct singly_linked_node * singly_linked_node_find(struct singly_linked_node *node, bool (*test)(void *));

#endif //DATA_STRUCTURES_IN_C_SINGLY_LINKED_NODE_H
