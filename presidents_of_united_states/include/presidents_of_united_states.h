//
// Created by onacit on 2021-06-12.
//

#ifndef DATA_STRUCTURES_IN_C_PRESIDENTS_OF_UNITED_STATES_H
#define DATA_STRUCTURES_IN_C_PRESIDENTS_OF_UNITED_STATES_H

#include <stdbool.h>

struct president_of_united_state {
    long ordinal;
    char *name;
};

struct president_of_united_state_iterator {
    void * environment;
    bool (*consume)(struct president_of_united_state_iterator *iterator, long *ordinal, char *name);
};

int presidents_of_united_states_iterate(struct president_of_united_state_iterator *iterator);

#endif //DATA_STRUCTURES_IN_C_PRESIDENTS_OF_UNITED_STATES_H
