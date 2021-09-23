#ifndef DATA_STRUCTURES_IN_C_PRESIDENTS_OF_UNITED_STATES_H
#define DATA_STRUCTURES_IN_C_PRESIDENTS_OF_UNITED_STATES_H

#define NUMBER_OF_PRESIDENTS_OF_UNITED_STATES 46

#include <stdbool.h>

struct president_of_united_state {
    unsigned char presidency;
    char president[23]; // William Henry Harrison (22)
};

void presidents_of_united_states(struct president_of_united_state *);

#endif //DATA_STRUCTURES_IN_C_PRESIDENTS_OF_UNITED_STATES_H
