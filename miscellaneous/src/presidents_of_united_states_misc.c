#include <assert.h>
#include <string.h>
#include "miscellaneous.h"
#include "presidents_of_united_states_misc.h"

static size_t n = 5;

int presidency_to_ordinal_suffixed(char * s, long presidency) {
    assert (s != NULL);
    assert (strlen(s) >= 4);
    return long_to_ordinal_suffixed(s, n, presidency);
}
