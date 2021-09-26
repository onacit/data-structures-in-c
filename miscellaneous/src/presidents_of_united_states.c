//
// Created by onacit on 2021-06-12.
//

#include <assert.h>
#include <stdio.h>
#include "presidents_of_united_states.h"

static const char FILENAME_PRESIDENTS_OF_UNITED_STATES[] = "presidents_of_united_states.txt";

void set_presidents_of_united_states(struct president_of_united_state *const p) {
    assert(p != NULL);
    FILE *stream = fopen(FILENAME_PRESIDENTS_OF_UNITED_STATES, "r");
    if (stream == NULL) {
        fprintf(stderr, "failed to open %s\n", FILENAME_PRESIDENTS_OF_UNITED_STATES);
        return;
    }
    for (int i = 0; i < NUMBER_OF_PRESIDENTS_OF_UNITED_STATES; i++) {
        int const n = fscanf(stream, "%hhu %[^\n]", &p[i].presidency, p[i].president);
        if (n == EOF) {
            fprintf(stderr, "unexpected EOF at %d\n", i);
            break;
        }
        assert(n == 2);
        if (p[i].president[22] == '\r') {
            fprintf(stderr, "replacing CR to NULL at %d\n", i);
            p[i].president[22] = '\0';
        }
    }
    if (fclose(stream) == EOF) {
        fprintf(stderr, "failed to close the stream");
    }
}