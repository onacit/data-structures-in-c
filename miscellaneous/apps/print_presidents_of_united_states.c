#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "miscellaneous.h"
#include "presidents_of_united_states.h"

int main() {
    struct president_of_united_state p[NUMBER_OF_PRESIDENTS_OF_UNITED_STATES];
    set_presidents_of_united_states(p);
    char o[5];
    for (int i = 0; i < NUMBER_OF_PRESIDENTS_OF_UNITED_STATES; i++) {
        int const n = sprintf_ordinal_g(o, p[i].presidency);
        assert(n < 5);
        printf("The %s President of the United States: %s\n", o, p[i].president);
    }
    return EXIT_SUCCESS;
}


