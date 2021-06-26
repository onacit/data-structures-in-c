//
// Created by onacit on 2021-06-26.
//

#include <assert.h>
#include <string.h>
#include "presidents_of_united_states_misc.h"

int presidency_to_ordinal_suffixed(char * s, long presidency) {
    assert (s != NULL);
    assert (strlen(s) >= 4);
    const int n = 5;
    return long_to_ordinal_suffixed(s, n, presidency);
}
