//
// Created by onacit on 2021-06-12.
//

#ifndef DATA_STRUCTURES_IN_C_PRESIDENTS_OF_UNITED_STATES_H
#define DATA_STRUCTURES_IN_C_PRESIDENTS_OF_UNITED_STATES_H

#include "singly_linked_node.h"

struct president_of_united_state {
    unsigned char o;
    char *n;
};

struct president_of_united_state_iterator {
    void * e;
    void (*n)(struct president_of_united_state_iterator *i, struct president_of_united_state *p);
};

void presidents_of_united_states_iterate(struct president_of_united_state_iterator * i);

#endif //DATA_STRUCTURES_IN_C_PRESIDENTS_OF_UNITED_STATES_H
