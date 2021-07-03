//
// Created by onacit on 2021-06-12.
//

#include <assert.h>
#include <stdio.h>
#include "presidents_of_united_states.h"
#include "presidents_of_united_states_misc.h"

bool first(long presidency, char *president) {
    assert(president != NULL);
    char s[5];
    presidency_to_ordinal_suffixed(s, presidency);
    printf("The %s president of the United States: %s\n", s, president);
    return true;
}

int main() {
    return presidents_of_united_states_consume_while(first);
}


