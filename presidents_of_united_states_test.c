//
// Created by onacit on 2021-06-12.
//

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "presidents_of_united_states.h"

struct president_of_united_state_iterator_environment {
    struct singly_linked_node *head;
    struct singly_linked_node *tail;
};

void next(struct president_of_united_state_iterator *i, struct president_of_united_state *p) {
    assert(i != NULL);
    assert(p != NULL);
    struct singly_linked_node *n = singly_linked_node_alloc(p);
    assert(n != NULL);
    struct president_of_united_state_iterator_environment *e
            = (struct president_of_united_state_iterator_environment *)i->e;
    if (e->head == NULL) {
        assert(e->tail == NULL);
        e->head = n;
        e->tail = e->head;
        return;
    }
    assert(e->tail != NULL);
    singly_linked_node_link_next(e->tail, n);
    e->tail = n;
}

int main(int argc, char **argv) {
    struct president_of_united_state_iterator *i = malloc(sizeof(struct president_of_united_state_iterator));
    assert(i != NULL);
    struct president_of_united_state_iterator_environment *e
            = malloc(sizeof(struct president_of_united_state_iterator_environment));
    assert(e != NULL);
    e->head = NULL;
    e->tail = NULL;
    i->e = e;
    i->n = next;
    presidents_of_united_states_iterate(i);
    for (struct singly_linked_node *n = e->head; n != NULL; n = n->next) {
        struct president_of_united_state *p = (struct president_of_united_state *) n->data;
        printf("%-2d %s\n", p->o, p->n);
    }

    return EXIT_SUCCESS;
}


