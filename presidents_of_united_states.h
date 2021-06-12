//
// Created by onacit on 2021-06-12.
//

#ifndef DATA_STRUCTURES_IN_C_PRESIDENTS_OF_UNITED_STATES_H
#define DATA_STRUCTURES_IN_C_PRESIDENTS_OF_UNITED_STATES_H

#include "singly_linked_node.h"

#define MAX_LINE_LEN = 27;

struct president_of_united_state {
    unsigned char ordinal;
    char *name;
};

void presidents_of_united_states_for_each(void (*a)(struct president_of_united_state *));

//struct singly_linked_node * presidents_of_united_states_singly_linked_nodes();

#endif //DATA_STRUCTURES_IN_C_PRESIDENTS_OF_UNITED_STATES_H
