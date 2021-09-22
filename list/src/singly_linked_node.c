#include <assert.h>
#include <stdlib.h>
#include "singly_linked_node.h"

// -------------------------------------------------------- construct / destruct
struct singly_linked_node *singly_linked_node(void *d) {
    struct singly_linked_node *n = malloc(sizeof(struct singly_linked_node));
    if (n == NULL) {
        return NULL;
    }
    n->next = NULL;
    n->data = d;
    return n;
}

void *singly_linked_node_free(struct singly_linked_node *n) {
    assert(n != NULL);
    assert(n->next == NULL);
    void *d = n->data;
    n->data = NULL;
    free(n);
    return d;
}

// ------------------------------------------------------------- insert / delete
struct singly_linked_node *singly_linked_node_insert_next(
        struct singly_linked_node *p, void *d) {
    assert(p != NULL);
    struct singly_linked_node *n = singly_linked_node(d);
    if (n == NULL) {
        return NULL;
    }
    n->next = p->next;
    p->next = n;
    return n;
}

void *singly_linked_node_delete_next(struct singly_linked_node *p) {
    assert(p != NULL);
    assert(p->next != NULL);
    struct singly_linked_node *n = p->next;
    p->next = n->next;
    n->next = NULL;
    return singly_linked_node_free(n);
}
