//
// Created by onacit on 2021-06-12.
//

#include <assert.h>
#include <stdio.h>
#include "presidents_of_united_states.h"

bool print(long *const presidency, char *const president) {
    assert(presidency != NULL);
    assert(president != NULL);
    printf("%s was the first president of the United States.\n", president);
    return false;
}

int main() {
    return presidents_of_united_states_consume_while(print);
}


