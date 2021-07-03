//
// Created by onacit on 2021-06-12.
//

#include <assert.h>
#include <stdio.h>
#include <presidents_of_united_states_misc.h>
#include "presidents_of_united_states.h"

bool first(long presidency, char * const president) {
    assert(president != NULL);
    char s[4];
    presidency_to_ordinal_suffixed(s, presidency);
    printf("%s was the %s president of the United States.\n", president, s);
    return false;
}

int main() {
    return presidents_of_united_states_consume_while(first);
}


