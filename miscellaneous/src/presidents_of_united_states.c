//
// Created by onacit on 2021-06-12.
//

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "presidents_of_united_states.h"

static const char FILENAME_PRESIDENTS_OF_UNITED_STATES[] = "presidents_of_united_states.txt";

void presidents_of_united_states(struct president_of_united_state * const presidents) {
    assert(presidents != NULL);
    FILE *stream = fopen(FILENAME_PRESIDENTS_OF_UNITED_STATES, "r");
    if (stream == NULL) {
        fprintf(stderr, "failed to open %s\n", FILENAME_PRESIDENTS_OF_UNITED_STATES);
        return;
    }
    for (int i = 0; i < NUMBER_OF_PRESIDENTS_OF_UNITED_STATES; i++) {
        int const n = fscanf(stream, "%hhu %23[^\n]s", &presidents[i].presidency, presidents[i].president);
        assert(n == 2);
    }
    if (fclose(stream) == EOF) {
        fprintf(stderr, "failed to close the stream");
    }
}