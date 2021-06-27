//
// Created by onacit on 2021-06-12.
//

#ifndef DATA_STRUCTURES_IN_C_PRESIDENTS_OF_UNITED_STATES_H
#define DATA_STRUCTURES_IN_C_PRESIDENTS_OF_UNITED_STATES_H

#include <stdbool.h>

int presidents_of_united_states_consume_while(bool (*accept)(long *presidency, char *president));

struct president_of_united_state {
    long presidency;
    char *president;
};

struct president_of_united_state_iterator {
    void *environment;
    bool (*accept)(struct president_of_united_state_iterator *iterator, long *presidency, char *president);
};

int presidents_of_united_states_iterate_while(struct president_of_united_state_iterator *iterator);

#endif //DATA_STRUCTURES_IN_C_PRESIDENTS_OF_UNITED_STATES_H
