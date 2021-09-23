#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "miscellaneous.h"
#include "presidents_of_united_states.h"

int main() {
    struct president_of_united_state presidents[NUMBER_OF_PRESIDENTS_OF_UNITED_STATES];
    presidents_of_united_states(presidents);
    char ordinal[5];
    for (int i = 0; i < NUMBER_OF_PRESIDENTS_OF_UNITED_STATES; i++) {
//        int const n = sprintf_ordinal_u(ordinal, presidents[i].presidency);
        int const n = snprintf_ordinal_u(ordinal, 5, presidents[i].presidency);
        assert(n < 5);
        printf("The %s President of United States of America: %s\n", ordinal, presidents[i].president);
    }
    return EXIT_SUCCESS;
}


