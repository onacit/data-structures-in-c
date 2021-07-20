//
// Created by onacit on 2021-06-05.
//

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "singly_linked_list.h"

/**
 * Returns the node at specified index of specified list.
 * @param l the list
 * @param i the index of the node.
 * @return the node at specified index; @c NULL if the list's size is greater than or equal to specified index.
 */
struct singly_linked_node* node(struct singly_linked_list *l, size_t i) {
    assert(l != NULL);
    struct singly_linked_node *n = l->head;
    for (size_t j = 0; n != NULL && j < i; j++) {
        n = n->next;
    }
    return n;
}

/**
 * @details Returns the first node of specified list.
 * @param l the list whose first node is returned.
 * @return the first of the list; @c NULL if the list is empty.
 */
struct singly_linked_node* head(struct singly_linked_list *l) {
    assert(l != NULL);
    return l->head;
}

/**
 * @details Returns the last node of specified list.
 * @param l the list whose last node is returned.
 * @return the last of the list; @c NULL if the list is empty.
 */
struct singly_linked_node* tail(struct singly_linked_list *l) {
    assert(l != NULL);
    struct singly_linked_node *n = l->head;
    if (n == NULL) {
        return NULL;
    }
    for (; n->next != NULL; n = n->next) {
    }
    return n;
}

// ---------------------------------------------------------------------------------------------------------------------

/**
 * @brief Creates a new singly linked list.
 * @return a new singly linked list; @c NULL if failed to allocate memory.
 */
struct singly_linked_list * singly_linked_list() {
    struct singly_linked_list *l = malloc(sizeof(struct singly_linked_list));
    if (l == NULL) {
        return NULL;
    }
    l->head = NULL;
    return l;
}

void singly_linked_list_free(struct singly_linked_list *l, void (*f)(void *)) {
    assert(l != NULL);
    assert(f != NULL);
    for (struct singly_linked_node *n; l->head != NULL; ) {
        n = l->head;
        l->head = l->head->next;
        n->next = NULL;
        void *data = singly_linked_node_free(n);
        (*f)(data);
    }
    free(l);
}

// ---------------------------------------------------------------------------------------------------------------------

/**
 * Checks whether specified list is empty.
 * @param l the list to check.
 * @return @c true when the list is empty; @c false otherwise.
 */
bool singly_linked_list_empty(struct singly_linked_list *l) {
    assert(l != NULL);
    return l->head == NULL;
}

/**
 * Returns the size of specified list.
 * @param l the list whose size is returned.
 * @return the size of the list.
 */
size_t singly_linked_list_size(struct singly_linked_list *l) {
    assert(l != NULL);
    size_t s = 0;
    for (struct singly_linked_node *n = l->head; n != NULL; n = n->next) {
        s++;
    }
    return s;
}

/**
 * @details Inserts specified data at specified index of specified list.
 * @param l the list to which the data is inserted.
 * @param i the index at which the data is inserted.
 * @param d the data to insert.
 * @return @c EXIT_SUCCESS when succeeded; @c EXIT_FAILURE when failed.
 */
int singly_linked_list_insert(struct singly_linked_list *l, size_t i, void *d) {
    assert(l != NULL);
    struct singly_linked_node *n = singly_linked_node(d);
    if (n == NULL) {
        return EXIT_FAILURE;
    }
    if (i == 0) {
        n->next = l->head;
        l->head = n;
        return EXIT_SUCCESS;
    }
    struct singly_linked_node *p = node(l, i - 1);
    if (p == NULL) {
        singly_linked_node_free(n);
        return EXIT_FAILURE;
    }
    singly_linked_node_link_next(p, n);
    return EXIT_SUCCESS;
}

void * singly_linked_list_delete(struct singly_linked_list *l, size_t i) {
    assert(l != NULL);
    assert(l->head != NULL);
    if (i == 0) {
        struct singly_linked_node *h = l->head;
        l->head = h->next;
        h->next = NULL;
        return singly_linked_node_free(h);
    }
    struct singly_linked_node *p = node(l, i - 1);
    return singly_linked_node_unlink_next(p);
}

void singly_linked_list_consume_while(struct singly_linked_list *l, bool (*a)(void *)) {
    assert (l != NULL);
    assert (a != NULL);
    for (struct singly_linked_node *n = l->head; n != NULL; n = n->next) {
        if (!(*a)(n->data)) {
            return;
        }
    }
}


void singly_linked_list_traverse(struct singly_linked_list *l, void (*a)(void *)) {
    assert(l != NULL);
    assert(a != NULL);
    for (struct singly_linked_node *n = l->head; n != NULL; n = n->next) {
        (*a)(n->data);
    }
}

void * singly_linked_list_get_data(struct singly_linked_list *l, size_t i) {
    struct singly_linked_node* n = node(l, i);
    assert(n != NULL);
    return n->data;
}

void * singly_linked_list_set_data(struct singly_linked_list *l, size_t i, void *d) {
    struct singly_linked_node* n = node(l, i);
    assert(n != NULL);
    void *p = n->data;
    n->data = d;
    return p;
}
